/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: x:/prj/tech/libsrc/3d/RCS/3dinterp.h $
 * $Revision: 1.12 $
 * $Author: KEVIN $
 * $Date: 1996/08/22 15:39:58 $
 *
 * includes for the 3d interpreter
 *
 * $Log: 3dinterp.h $
 * Revision 1.12  1996/08/22  15:39:58  KEVIN
 * fixed typo.
 * 
 * Revision 1.11  1996/08/22  15:30:22  KEVIN
 * Fixes for 16 bit + vcolors.
 * 
 * Revision 1.10  1996/07/08  10:06:03  KEVIN
 * Changed g3d_fill_parm back to ulong.
 * 
 * Revision 1.9  1996/07/08  10:01:15  KEVIN
 * Fixed c++ bug with g3_set_callback().
 * 
 * Revision 1.8  1996/07/07  21:39:22  JAEMZ
 * Added structures for callback information and fill type
 * 
 * Revision 1.7  1996/06/14  15:21:17  KEVIN
 * Merged in functionality from oldtech.
 * 
 * 
 * Revision 1.5  1995/12/17  15:06:54  JAEMZ
 * Moved 3d fill modes over to 3dinterp
 * 
 * Revision 1.4  1995/07/23  20:02:05  JAEMZ
 * Moved object stuff from 3d to 3dinterp
 * 
 * Revision 1.3  1995/01/27  17:33:02  jaemz
 * New 3d regime
 * 
 * Revision 1.2  1993/10/02  09:19:46  kaboom
 * New include for g3_set_vtext().
 * 
 * Revision 1.1  1993/08/04  00:48:56  dc
 * Initial revision
 */

#ifndef __3DINTERP_H
#define __3DINTERP_H

#include <fix.h>


#ifdef __cplusplus
extern "C" {
#endif 




typedef struct {
   char        name[8];   // name of model
   g3s_vector  bmax; // bbox maximum
   g3s_vector  bmin; // bbox minimum     
   g3s_vector  cen;  // centroid position
   g3s_vector  pcen;  // centroid pos relative to parent
   fix   rad;     // bounding radius from centroid
   fix   prad;    // biggest pgon rad
   short pgons;   // number of pgons
   short verts;   // number of verts
   short parms;   // number of parms
   ubyte vcalls;  // number of vcalls
   ubyte vhots;   // number of hot spots
   bool  lit;     // built lit
   ubyte mats;    // number of mats in the header
   ulong vh_off;  // offset of vhot area
   ulong hsize;   // header size, mix and stir
   g3s_vector res2; // reserved 1
} g3s_modinfo; // 94 long

typedef struct {
   uchar type; // type 0 = texture, 1 = virtual color
   uchar num;  // slot to put it in
   ulong handle;  // texture handle or 0bgr
   union {
      fix   uv;   // uv coords per 3d unit for mipmapping or ipal index
      ulong ipal; // inverse pal lookup
   };
} g3s_matinfo; // material info

typedef struct {
   char name[16];
} g3s_matname;  // name of materials

typedef struct {
   ulong     id;      // id of vhot and maybe name later
   g3s_vector v;  // location rel to obj
} g3s_vhotinfo; // vhot info

// given a model address, return a pointer to the structure
#define g3_info(modadd) ((g3s_modinfo *)(modadd))

// given a model address, return a pointer to the first vhot
#define g3_vhot_list(modadd) ((g3s_vhotinfo *)(((g3s_modinfo *)(modadd))+1))

// given a model address, return a point to g3s_matinfo *
#define g3_mat_list(modadd) ((g3s_matinfo *)((uchar*)(modadd)+94+(((g3s_modinfo *)(modadd))->vhots * 16)))

g3s_matname *g3_matname(g3s_modinfo *modadd);

void g3_interpret_object(ubyte *object_ptr,fix *parm_ptr);
void g3_interpret_vhot(ubyte *object_ptr,fix *parm_ptr);
void g3_object_bbox(ubyte *object_ptr);
void g3_compute_bbox(ubyte *object_ptr,g3s_vector *v);
extern void g3_set_tmaps_linear();
extern void g3_reset_tmaps();

#pragma aux g3_interpret_object "*" parm [eax] [ebx] modify [eax ebx ecx edx esi edi];
#pragma aux g3_interpret_vhot "*" parm [eax] [ebx] modify [eax ebx ecx edx esi edi];

// actual inline code
extern ulong vcolor_tab[];
#define g3_set_vcolor(vcolor_id, color_val) \
   vcolor_tab[vcolor_id] = color_val;

extern ulong vpoint_tab;
void g3_set_vpoint(int vpoint_id, void *point_ptr);
#pragma aux g3_set_vpoint = \
   "mov vpoint_tab[eax*4], ebx" \
   parm [eax] [ebx] modify exact [eax]

extern ulong vtext_tab;
void g3_set_vtext(int vtext_id, void *text_ptr);
#pragma aux g3_set_vtext = \
   "mov vtext_tab[eax*4], ebx" \
   parm [eax] [ebx] modify exact [eax]

extern ulong vcall_tab;
void g3_set_vcall(int vcall_id, void *v_ptr);
#pragma aux g3_set_vcall = \
   "mov vcall_tab[eax*4], ebx" \
   parm [eax] [ebx] modify exact [eax]

extern g3s_vector vhot_tab[];

// flags for polygon draw type
extern uchar itrp_gour_flg, itrp_wire_flag, itrp_check_flg;

#define g3_set_gour_flag(x)   itrp_gour_flag  = x
#define g3_set_wire_flag(x)   itrp_wire_flag  = x
#define g3_set_check_flag(x)  itrp_check_flag = x

#define FT_LIGHT     0
#define FT_FLAT_LIGHT 1
#define FT_NO_LIGHT   2
#define FT_SHADOW    3
#define FT_SHADOWED  4
#define FT_WIRE      5
#define FT_SOLID     6
#define FT_CALLBACK  7

// Fill type functions
void g3_push_fill(int ftype);
#pragma aux g3_push_fill "*" parm [eax] modify [eax ebx ecx edx esi edi];
void g3_pop_fill();
#pragma aux g3_pop_fill "*" modify [eax ebx ecx edx esi edi];

// Sets the interpreter callback fillmode on polys, pass it pointer to
// function, you need to do a g3_pop_fill afterwards

// this describes the polygon information structure
typedef struct {
   short token;      // gen_norm token =
   short offset;     // offset to end of pgon
   g3s_vector norm;  // normal of pgon (in object space)
   g3s_vector cen;   // center of pgon (in object space)
   ushort   type;    // pgon type 0=solid, 1=wire, 2=tmap
   ushort   num;     // number of verts
   ushort   verts[]; // vertex indices, the low byte of last one is
                     // is color if solid, tmap index if not
} g3s_pgon_info;

extern g3s_phandle g3d_resbuf[];

// Define a g3f_cback as a thing that takes a pgon * and returns nothing
typedef void (* g3f_cback)(g3s_pgon_info *pgon);

// Set the callback routine for filltype Callback
extern ulong g3d_fill_parm;
#define g3_set_callback(f) g3d_fill_parm = (ulong )(f);

#ifdef __cplusplus
}
#endif 


#endif /* __3DINTERP_H */
