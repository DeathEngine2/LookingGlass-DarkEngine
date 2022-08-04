/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: x:/prj/windex/libsrc/3d/RCS/3dshad.h $
 * $Revision: 1.2 $
 * $Author: DAVET $
 * $Date: 1996/01/16 15:55:26 $
 *
 * Header file for LookingGlass 3D shading
 *
 */

#ifndef __3DSHAD_H
#define __3DSHAD_H

#include <fix.h>
#include <2d.h>


#ifdef __cplusplus
extern "C" {
#endif 


#define SHAD_FLAT 0
#define SHAD_Z    1

typedef struct g3s_shad {
   uchar shad_type;
   grs_bitmap *bm; // bitmap
   uchar *vbuf;    // vertical buffer
   g3s_vector corner[4];   // world coords
   sfix u[4];  // u's
   sfix v[4];  // v's
} g3s_shad;


// Render a model onto a g3s_shad
void g3_render_shadow(void *modptr,fix *parmptr,g3s_shad *shad);

// do all the allocating for shadow of size w,h
g3s_shad *g3_alloc_shad(void *modptr,short w,short h,uchar stype);

// free a shad that's been allocated
void g3_free_shad(g3s_shad *shad);

// Interprets a model with a shadow map
void g3_interpret_shadowed(void *modptr,fix *parm,g3s_shad *shad);

#ifdef __cplusplus
}
#endif 




#endif /* __3DSHAD_H */
