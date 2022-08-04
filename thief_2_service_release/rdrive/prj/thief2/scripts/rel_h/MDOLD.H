/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: x:/prj/tech/libsrc/md/RCS/md.h $
 * $Revision: 1.12 $
 * $Author: KEVIN $
 * $Date: 1996/12/03 14:48:48 $
 *
 * Model Library prototypes
 *
 */


#ifndef __MD_H
#define __MD_H

#include <mds.h>
#include <r3ds.h>

typedef unsigned short ID; // to avoid including RES.h


// Normal way to render a model.  Pass in pointer to the model and parms
// list
void md_render_model(mds_model *m,float parms[]);

// Given a model, returns the needed size of the buffer for it
int md_buffsize(mds_model *m);

// Use this buffer for the next model rendered
void md_set_buff(mds_model *m,void *buff);

// Only transforms points, polygon normals, and lighting values
// into the buffer.  Does not render.
void md_transform_only(mds_model *m,float parms[]);

// Only render the model, assumes it has been transformed, and in fact,
// only works then.
void md_render_only(mds_model *m,float parms[]);

// Renders only a subobject, nothing else. 
void md_render_subobj(mds_model *m,float parms[],int sub);

// Return a pointer to the material list.
#define md_mat_list(m) ((mds_mat *)((uchar *)(m)+((m)->mat_off)))

// Return a point to the subobject list
#define md_subobj_list(m) ((mds_subobj *)((uchar *)(m)+((m)->subobj_off)))

// Return a pointer to the vhot list
#define md_vhot_list(m) ((mds_vhot*)((uchar *)(m)+((m)->vhot_off)))

// Return a pointer to the light list
#define md_light_list(m) ((mds_light*)((uchar *)(m)+((m)->light_off)))

// Return a pointer to the point list
#define md_point_list(m) ((mxs_vector*)((uchar *)(m)+((m)->point_off)))

// Return a pointer to the normal list
#define md_norm_list(m) ((mxs_vector*)((uchar *)m+m->norm_off))

// Just evaluate the vhots, stuffing them into their positions.
void md_eval_vhots(mds_model *m,float parms[]);

// These tables are for the vcolors, textures, vcalls, and for reading the result of vhots.  The vhots are in 
// world coords.  You set the vcolor to the color index (if 8 bit) or color (if 16 bit or higher).  You set the 
// vtext tab to the handle of the texture.

#define MD_TAB_SIZE 64

typedef void (* mdf_vcall)(mds_node_vcall *v);

extern int         mdd_vcolor_tab[MD_TAB_SIZE];
extern r3s_texture mdd_vtext_tab[MD_TAB_SIZE];
extern mdf_vcall   mdd_vcall_tab[MD_TAB_SIZE];
extern mxs_vector  mdd_vhot_tab[MD_TAB_SIZE];

#define md_set_table_entry(index, val, table) \
do {                                                     \
   int __mdmac_index = (index);                          \
   AssertMsg1(((__mdmac_index < MD_TAB_SIZE)&&           \
               (__mdmac_index > 0)),                     \
            "MD library table index out of range: %i\n", \
            __mdmac_index);                              \
   table[__mdmac_index] = (val);                         \
} while (0)

#define md_set_vtext(index, val)  \
         md_set_table_entry(index, val, mdd_vtext_tab)

#define md_set_vcolor(index, val) \
         md_set_table_entry(index, val, mdd_vcolor_tab)

#define md_set_vcall(index, val)  \
         md_set_table_entry(index, val, mdd_vcall_tab)

#define md_set_vhot(index, val)   \
         md_set_table_entry(index, val, mdd_vhot_tab)

// Typedef defining a function to render a polygon.  This is used as 
// the callback type.  If you return true, it then renders the polygon 
// for you.

typedef void (* mdf_pgon_cback)(mds_pgon *pgon);

// Set the polygon callback function.  Gets reset at the end of the
// next rendering.  Returns current one so you can chain if you want.
mdf_pgon_cback md_set_pgon_callback(mdf_pgon_cback func);

// Exposed so people doing pgon callbacks
// can pre or post render
void md_render_pgon(mds_pgon *p);

// By default is set true, you can set it false here, and change the 
// render order for doing craziness like span 
// clipping, and potentially Z buffer.
void md_render_back_to_front(bool f);

// By default is set false.  If set true, evaluates a bounding sphere 
// at each node to determine if the node needs
// to be rendered or not.
void md_check_bounding_sphere(bool f);

// Converts a normal to a compressed light value
void md_norm2light(ulong *l,mxs_vector *n);

// set the render mode
enum {
   MD_RMODE_NORMAL,
   MD_RMODE_SOLID,
   MD_RMODE_WIRE
};

// render normally, as solid, or wire
// let's you change the primitive
// Also has the effect of eliminating color setting
void md_set_render_prim(ubyte mode);

// to light, or not to light.
void md_set_render_light(bool l);

// Internally, the library must keep several pointers around after getting 
// a pointer to the model.  We expose these for adventurous users
// Carpe diem, er.. Cave Canem, uh.. something like that.
// Caveat Emptor!  
// These are:

extern mds_model   *mdd_model;   // a pointer to the model
extern mds_subobj  *mdd_subs;    // subobject header list
extern mds_mat     *mdd_mats;    // material list
extern mds_uv      *mdd_uvs;     // the uv list
extern mds_vhot    *mdd_vhots;   // vhot list
extern mxs_vector  *mdd_points;  // point list
extern mds_light   *mdd_lights;  // lighting normal and point list
extern mxs_vector  *mdd_norms;   // the polygon normal list
extern uchar       *mdd_pgons;   // the top of the polygon list 
extern uchar       *mdd_nodes;   // the the top of the node list

// And once the user buffer is allocated and set, it keeps:

extern void        *mdd_buff;     // a pointer to the buffer
extern r3s_point   *mdd_buff_points; // a pointer to the transformed points
extern float       *mdd_buff_lights;  // a pointer to the lighting values
extern float       *mdd_buff_norms;   // a pointer to the normal do product results

extern ubyte      mdd_type_and;  // mask for pgon type at render time
extern ubyte      mdd_type_or;   // mask for pgon type at render time

// Sets the light callback, and gets the old one back
mdf_light_setup_cback md_set_light_setup_callback(mdf_light_setup_cback);
mdf_light_cback md_set_light_callback(mdf_light_cback);
mdf_light_obj_cback md_set_light_obj_callback(mdf_light_obj_cback);

// This is the default implementaton of lighting, just
// call md_light_init() to install, and use it
// like the old 3d library lighting

#define MD_LT_NONE    0
#define MD_LT_AMB     1
#define MD_LT_DIFF    2
#define MD_LT_SPEC    4

// Set the light type
void md_light_set_type(uchar type);

// Recomputes constants based on type of lighting
// call explicitly if you change object frame and 
// need to recompute lights.
void md_light_recompute();

// Call this to install the default
// lighter
void md_light_init();

// Just set these directly
extern mxs_vector mdd_sun_vec;
extern float mdd_lt_amb;    // ambient value
extern float mdd_lt_diff;   // diffuse value
extern float mdd_lt_spec;   // specular value

// Set true to get linear, false to get perspective
// This is superceded and overwritten if you use the
// fancy util renderer

void md_set_tmap_linear(bool l);


// Scale a model according to the scaling vector s.  The scaling is 
// done in source space.  If the model *dst is NULL, it allocates memory
// for it
// light is whether or not to retransform the lighting vectors.  Depending,
// you may actually want it to be the same, plus it's the slowest thing to
// do
mds_model *md_scale_model(mds_model *dst,mds_model *src,mxs_vector *s,bool light);


// Useful Utilities Functions

// Locks down textures using a resource offset
// This assumes that the texture handles are set
// to be added to a resource offset to get their
// ResID.  So if you do sneakiness, this won't work
// Call this just before rendering the model
// Assumes textures are stored as .btm

void md_mat_textures_lock(mds_model *m,ID base);

// Sets the colors of a model, should work in both
// 8 bit mode (with grd_ipal set) and in 16 bit or
// 24 bit mode.  Call this just before rendering the
// model

void md_mat_colors_set(mds_model *m);

// Just like md_mat_textures_lock, only it unlocks
// the textures.

void md_mat_textures_unlock(mds_model *m,ID base);


// Returns the maximum pixel error in the biggest
// texture map in the model

float md_tmap_err(mds_model *m);


// Pixel error below which you use linear texture
// maps used by md_fancy_render_model. 1 means pixel
// perfect.  Defaults to 1

void md_set_linear_breakpoint(float b);


// Renders the model by first checking the bounding
// box, turning on clipping if it needs to be clipped,
// not if not, does either linear or perspective texturing
// depending on where the linear breakpoint is

void md_fancy_render_model(mds_model *m,float parms[]);


// Checks whether the segment a-b intersects the model.
// it fills in hit, hit_normal, and r appropriately.

void md_hit_detect(mds_model *m, mds_hit_detect_info *hdi);

#endif // __MD_H
