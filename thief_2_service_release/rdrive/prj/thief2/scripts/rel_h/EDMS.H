/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Header: x:/prj/tech/libsrc/tn_edms/RCS/edms.h 1.22 1996/01/07 16:40:25 DFAN Exp $
 */

#ifndef __EDMS_H
#define __EDMS_H

#include "fix.h"
#include "physhand.h"

#define MAX_OBJ 96

typedef int object_number;

extern int min_physics_handle;
extern object_number  ph2on[MAX_OBJ];
extern physics_handle on2ph[MAX_OBJ];

#define physics_handle_to_object_number(ph) (ph2on[ph])
#define object_number_to_physics_handle(on) (on2ph[on])

#ifdef __cplusplus
extern "C" {
#endif

void           EDMS_init_handles( void );
physics_handle EDMS_bind_object_number( object_number on );
void           EDMS_remap_object_number( object_number old, object_number nu );
physics_handle EDMS_get_free_ph( void );
void           EDMS_release_object( physics_handle ph );

#ifdef __cplusplus
}
#endif

// The integrator

void EDMS_soliton_vector( fix timestep );

// Tools...
// ========
// Here is a routine that will attempt to settle an object to the local b/c.  It is NOT intended for
// online use.  A negative return value indicates a badly placed or unphysical model...
// ====================================================================================
int   EDMS_settle_object( physics_handle ph );

void  EDMS_mprint_state( physics_handle ph );

// Prints out state and sleep information on ALL objects.  Show sleepers is 1 to display sleeping objects...
// ---------------------------------------------------------------------------------------------------------
void  EDMS_inventory_and_statistics( int show_sleepers );

// Returns TRUE if an object is awake, FLASE otherwise...
// ------------------------------------------------------
bool  EDMS_frere_jaques( physics_handle ph );

// Checks integrity of EDMS.  Returns EDMS error codes, as seen below.
// -------------------------------------------------------------------
int   EDMS_sanity_check( void );

// Here we exclude objects from hitting specific others...
// -------------------------------------------------------
void  EDMS_ignore_collisions( physics_handle ph1, physics_handle ph2 );

// Here we reallow collisions...
// -----------------------------
void  EDMS_obey_collisions( physics_handle ph1 );

// Autodestruct objects kill themselves after the first or second collision callback.  This is model specific.
// -----------------------------------------------------------------------------------------------------------
void  EDMS_set_autodestruct( physics_handle ph );
void  EDMS_defuse_autodestruct( physics_handle ph );

// Wake me up no matter what (i.e. terrain is changing, new level, etc.)...
// ------------------------------------------------------------------------
void  EDMS_crystal_meth( physics_handle ph );

// Structs...
// ==========
typedef struct {
   fix   playfield_size;
   int   min_physics_handle;

   void	(*collision_callback) (physics_handle caller, physics_handle victim, int badness,
                                  long DATA1, long DATA2, fix location[3]),
		   (*autodestruct_callback) (physics_handle caller),
	   	(*awol_callback) (physics_handle caller),
		   (*snooz_callback) (physics_handle caller),
		   (*terrain_obj_callback) (physics_handle caller, long DATA1, long DATA2);

   void  *argblock_pointer;
} EDMS_data;

typedef struct {
   fix   X, Y, Z,
         X_dot, Y_dot, Z_dot;
} State;

typedef struct {
   fix   X, Y, Z,
         X_dot, Y_dot, Z_dot,
         X_acc, Y_acc, Z_acc;
} ExtendedState;

// Master control...
// =================
void  EDMS_get_state( physics_handle ph, State *s ),
      EDMS_get_extended_state( physics_handle ph, ExtendedState *s ),
      EDMS_startup( EDMS_data* D ),
      EDMS_kill_object( physics_handle ph ),
      EDMS_holistic_teleport( physics_handle ph, State *s );
      
// Tell EDMS what space to use for spare calculations
void  EDMS_set_workspace (void *space);

// Marble:
// -------
typedef struct
{
   fix   mass,
         radius,
         gravity,
         elasticity,
         friction,
         power,
         drag,
         control_drag,
         fake_r,
         fake_z;
} Marble;

physics_handle EDMS_make_marble( Marble *m, State *s );
void EDMS_get_marble_parameters( physics_handle ph, Marble *m );
void EDMS_set_marble_parameters( physics_handle ph, Marble *m );
void EDMS_control_marble( physics_handle ph, fix X, fix Y, fix Z );
void EDMS_override_marble( physics_handle ph, fix X, fix Y, fix Z );
void EDMS_kick_marble (physics_handle ph, fix X, fix Y, fix Z);

// Death...
// --------
typedef struct {

   fix   mass,
         size,
         gravity,
         drag;     // drag multiplier, 1 for normal drag, 0 for none

} Death;

physics_handle EDMS_make_death( Death *d, State *s );
void EDMS_get_death_parameters( physics_handle ph, Death *d );
void EDMS_set_death_parameters( physics_handle ph, Death *d );

// Raycaster

physics_handle EDMS_FF_beam_weapon_new( fix X[3],  //Location of gun, *returns hit location*...
                        fix D[3],                  //Unit vector in direction of barrel...
                        fix speed,                 //Speed of bullet in m/s...
                        fix mass,                  //Mass of projectile in kilos...
                        fix size,                  //Radius of bullet in meters...
                        fix range,                 //Range of weapon in meters...
                        physics_handle exclude,    //A physics object that is immune to hits...
                        physics_handle shooter,    //The physics object who fired...
                        long *w_info,              //FF wall information, returned if a wall is hit...
                        long *g_info,              //FF ground information, "" "" "" "" ...
                        bool *hit );               //TRUE for a hit, FALSE if range is exceeded without a hit...


// Obsolete
typedef struct
{
   fix	mass,
      	max_speed,
   	   skill,
      	gravity;

   fix   hip_radius,
         thigh,
         shin,
         torso;

   fix   shoulders,
         arms;
} Biped;

// Freefall terrain data structures...
// ===================================
typedef struct {
   fix   g_height,                  //The ground...
         g_dx,
         g_dy,
         g_dz,

         w_x,                       //Any walls...
         w_y,
         w_z;

   fix   power_mult,                //Information about terrain
         friction;

   long  DATA1,                     //For terrain return information...
         DATA2;

   fix   my_size;                   //Only needed for "fast" terrain calls

   physics_handle caller;           //Who's responsible...
} terrain_ff;

// Error codes

#define     EDMS_TOO_MANY_OBJECTS 1
#define     EDMS_PHYSICS_HANDLES_CORRUPT 2
#define     EDMS_OBJECT_HANDLES_CORRUPT 3
#define     EDMS_IDOF_POINTERS_CORRUPT 4

void EDMS_set_z_offset (physics_handle ph, fix dz);
void EDMS_set_x_dot (physics_handle ph, fix x);
void EDMS_set_y_dot (physics_handle ph, fix y);
void EDMS_set_z_dot (physics_handle ph, fix z);

#endif /* __EDMS_H */

