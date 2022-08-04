#ifndef _NEWPROTO_H
#define _NEWPROTO_H

//#include <bipstr.h>
//#include <schedstr.h>
//#include <motion.h>

// Biped Interface Functions

void biped_basic_init(bipeds_info *,biped_motion *,ushort,ushort,int,mxs_real);
//void biped_init(bipeds_info *,biped_motion *,ushort,ushort,int,mxs_real);
int biped_create_loctable(locomotion_table *);
void biped_add_locomotion(locomotion_table *,biped_locomotion *, int *);
void biped_delete_locomotion(locomotion_table *,int, int *);
void biped_set_torsocap(bipeds_info *,biped_motion *, mxs_real, int,int);
void biped_set_limbcap(bipeds_info *,biped_motion *,mxs_real,int,int);
void biped_set_effeccap(bipeds_info *,biped_motion *, mxs_real, int,int);
#ifdef BAD_FUNC
void do_limb_capture(bipeds_info *,biped_motion *,mxs_real,int,int);
#endif
bool biped_init_torsocap(Trunk_info *, void *,ushort,int,int);
bool biped_init_headcap(Head_info *,void *,ushort,int,int);
bool biped_init_handcap(Hand_info *,void *,ushort,int,int,int);
void biped_init_handweapcap(Hand_info,void *,ushort,int,int,int);
bool biped_init_footcap(Foot_info *,void *,ushort,int,int,int);
bool biped_init_armcap(Arm_info *,void *,ushort,int,int,int);
bool biped_init_legcap(Leg_info *, void *,ushort,int,int,int);
void biped_get_locomotion(biped_locomotion *,locomotion_table,int);
void biped_do_mot(bipeds_info *,void *,mxs_real,mxs_real);//,int);
void biped_do_loc(bipeds_info *,biped_locomotion *,mxs_real,mxs_real);//,int);
void biped_do_locskel(bipeds_info *,biped_locomotion *,mxs_real);
void biped_do_motskel(bipeds_info *,void *,mxs_real);

// bend direction for joint
#define BEND_BACK 0
#define BEND_FWD  1
void biped_compute_joint(mxs_vector *,mxs_vector *,mxs_vector *,mxs_vector *,Limb_sched *,int bend_dir);
mxs_real biped_bm_len(sks_skel *,int,mxs_real);
int biped_bm_ppu(sks_skel *,int);
void bp_to_biped(bps_info*,bipeds_info*);
void biped_to_bp(bps_info *, bipeds_info *);
void set_bpsched_from_bipedmot(bps_info *, bipeds_info *, biped_motion *);
void virt_SweepScanner(bipeds_info *,biped_motion *,int,int,int,int,int);
void virt_DrawWeapon(bipeds_info *,biped_motion *,int , int, int);
void virt_DrawandSweepWeapon(bipeds_info *,biped_motion *,mxs_real,int,int);
void biped_vec_interp(mxs_vector *,mxs_vector *,mxs_vector *,mxs_real);

//void biped_load_motcap();

//void biped_set_motion(biped_info *, biped_motion *, int);
//void biped_set_locomotion(biped_info *, biped_motion *, int);

//void biped_process_motions(bipeds_info*,biped_motion*,biped_locomotion*,int,int,int);

//void biped_scale_to_object(bipeds_info *,biped_motion *,biped_locomotion *,int,int);
//void biped_scale_motions(bipeds_info *, biped_motion *,biped_locomotion *,int,int);
//void biped_merge_motions(bipeds_info *,biped_motion *,biped_locomotion *,int*,int*int);
//void biped_blend_endpoints(bipeds_info *,biped_motion *,biped_locomotion *,int,int);  // Note: bipeds_info could store

//===========================================================

//void biped_query_locomotion_reqs(bipeds_info *,bps_motion, bps_motion_req *);

// Is the following Function Necessary?
//#define biped_from_obj(obj) ((bipeds_info *)&(people[((ObjPerson *)&objs[(obj)])->person].biped))
//void biped_init(bipeds_info *b,int pba_type);



// Physics interactions

// set functions to get and set world position and orientation of
// physics rep of biped.  The z-value should be height of bottom
// (so for sphere, take sphere center - radius.)

typedef bool (*biped_physetfunc)(bipeds_info *b,mxs_vector *pos,mxs_matrix *or);
typedef bool (*biped_phygetfunc)(bipeds_info *b,mxs_vector *pos,mxs_matrix *or);

void biped_set_physfuncs(biped_physetfunc pset, biped_phygetfunc pget);

// Locomotion

#ifdef LATER
bps_locomotion *biped_determine_locomotion(int level_of_detail);
void biped_determine_required_space(bipeds_info *,bps_locomotion *,space_reqs *);
void biped_process_locomotion(bps_locomotion *);

// Motion Scaling and Blending

bd_vec_interp(g3s_vector *,g3s_vector *,g3s_vector *,fix);
void_propogate_force();
                     
// Biped Functionality

bool biped_set_schedules(bps_locomotion *,bipeds_info *);
bool biped_adjust_schedules(bipeds_info *, bps_locomotion *);

void biped_dumb_phys(bipeds_info *b);
void biped_do_phys(bipeds_info *b,fix dt,fix time); // old
bool biped_trunk_motion(bipeds_info *b,fix cur_time); // ?

// Attributes

bool biped_can_bound(bipeds_info *b); // There can be a list of these, and may
                                   // not be necessary.

// New Skel and Rendering Routines

void biped_compute_skel(bipeds_info *b,int detail,fix cur_time);
void biped_compute_constants(bipeds_info *b); // ?
// Are the following necessary?
#define biped_phys_to_rend(dest,src) do {(dest)->x = (src)->x;(dest)->y=(src)->y;(dest)->z=(src)->z;} while(0); 
#define biped_rend_to_phys(dest,src) do {(dest)->x = (src)->x;(dest)->y=(src)->y;(dest)->z=(src)->z;} while(0);

// Callback

// These specific calls will be generalized, or ones will exist for various states.  These are just calls for some specific Terra-Nova holdovers.
bool biped_in_water(fix x,fix y);
void biped_splash(g3s_vector *loc,bool sound);
void biped_sound_foot_fall(int foot,int terrain, fix vel);
void biped_sound_foot_lift(int foot,fix vel);


// General Speedup

int biped_get_detail(bipeds_info *b);
void biped_get_bbox(bipeds_info *b,Rect *pbox);
void biped_get_head_bbox(bipeds_info *b,Rect *pbox);

// New Dynamnic Motions

// These are specific for crouching, and will be other virtual motions.
bool biped_is_crouched(bipeds_info *b);
void biped_crouch_hucker(bipeds_info *bps,mxs_ang lean,fix height);
void biped_crouch(bipeds_info *b,bool lean);
void biped_uncrouch(bipeds_info *b);
// These general information functions will allow to use information for planning.  The get_vel will be radically changed.
void biped_center(bipeds_info *b,fix *sx,fix *sy);
void biped_3d_center(bipeds_info *b,g3s_vector *v);
bpsLoc *biped_get_loc(bipeds_info *b);
g3s_vector *biped_get_vel(bipeds_info *b);
// These are used to make walking more general.
void biped_head_animate(bipeds_info *b, uchar frame);
void biped_head_reset(bipeds_info *b);
void biped_eye_loc(g3s_vector *loc,bipeds_info *b);

// Operations Unspec.
// What are these, and do we need these?
int biped_sound(fix mapx,fix mapy,fix mapz);
fix biped_terrain(fix x,fix y,fix z);
#define biped_is_player(bdb) TRUE
#endif
#endif //_NEWPROTO_H
