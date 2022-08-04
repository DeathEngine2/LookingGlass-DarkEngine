::::::::::::::
prim.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/prim.c 1.7 1996/05/29 00:08:57 buzzard Exp $
//
//  Context setting for 3D primitives

#include <primfunc.h>
#include <primcon_.h>

  // start up a new context
void r3_set_prim(void)
{
   r3_compute_prim_funcs(R3FUNC_ALL, "r3_set_prim");
}

  // use 2d clipping for all primitives?
void r3_set_2d_clip(bool context)
{
   if (context != r3d_clip_2d) {
      r3d_clip_2d = context;
      r3_compute_prim_funcs(R3FUNC_ALL_2D, "r3_set_2d_clip");
   }
}

void r3_set_color(int color)
{
   r3d_color = color;
}

void r3_set_point_context(int context)
{
   if (context != r3d_point_flags) {
      r3d_point_flags = context;
      r3_compute_prim_funcs(R3FUNC_ALL_POINT, "r3_set_point_context");
   }
}

void r3_set_line_context(int context)
{
   if (context != r3d_line_flags) {
      r3d_line_flags = context;
      r3_compute_prim_funcs(R3FUNC_ALL_LINE, "r3_set_line_context");
   }
}

void r3_set_polygon_context(int context)
{
   if (context != r3d_poly_flags) {
      r3d_poly_flags = context;
      r3_compute_prim_funcs(R3FUNC_ALL_POLY, "r3_set_polygon_context");
   }
}

void r3_set_texture(r3s_texture id)
{
   // store off the bitmap
   r3d_bm = id;

   // recompute 2D function ptr
   r3_compute_prim_funcs(R3FUNC_2D_POLY, "r3_set_texture");
}
::::::::::::::
primconv.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/primconv.c 1.6 1996/05/26 16:57:06 buzzard Exp $

#include <r3ds.h>
#include <primconv.h>

////////  convert between 3d points and 2d points  ////////

  // convert an array of phandles into an array vertices
  // this automatically reverses the winding in a left-handed space UNIMPLEMENTED
void r3_phandle_to_vertex_list(int n, r3s_phandle *src, grs_point **vp)
{
   int i;
   for (i=0; i < n; ++i)
      vp[i] = r3_phandle_to_vertex(src[i]);
}

#pragma off(unreferenced)

  // reverse 2d vertex list by hand
void r3_reverse_vertex_list(int n, grs_point **src)
{
}

  // reverse 2d vertex list if we're in a left-handed space
void r3_maybe_reverse_vertex_list(int n, grs_point **src)
{
}
#pragma on(unreferenced)

  // back-compatibility: convert from grs_point to grs_vertex
grs_vertex hacks[32];
grs_vertex *loc[32];
void r3_new2d_to_old2d(int n, grs_point **src, grs_vertex ***dest, grs_bitmap *cur_bm_hack)
{
   int i;
   *dest = loc;
   for (i=0; i < n; ++i) {
      loc[i] = &hacks[i];
      loc[i]->x = src[i]->sx;
      loc[i]->y = src[i]->sy;
      loc[i]->w = src[i]->w * 65536;
      loc[i]->i = src[i]->i * 65536 * 16;
      loc[i]->u = src[i]->u * 65536 * cur_bm_hack->w;
      loc[i]->v = src[i]->v * 65536 * cur_bm_hack->h;
   }
}

grs_vertex **r3_new2d_to_old2d_hack(int n, grs_point **src, grs_bitmap *bm)
{
   grs_vertex **p;
   r3_new2d_to_old2d(n, src, &p, bm);
   return p;
}
::::::::::::::
primface.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/primface.c 1.5 1996/05/28 19:44:38 buzzard Exp $

//  3D Rendering primitives and context

#include <lg.h>

#include <r3ds.h>
#include <ctxts.h>

#include <primface.h>

  // check if a polygon is forward facing, takes array of 3 phandles
  // automatically deals with left/right-handed space
bool r3_check_facing_3(r3s_phandle *vp)
{
   mxs_vector a,b,c;

   mx_sub_vec(&a, &vp[1]->p, &vp[0]->p);
   mx_sub_vec(&b, &vp[2]->p, &vp[1]->p);

   // compute normal with cross product
   mx_cross_vec(&c, &b, &a);
   
   // compare dot product of one pt with normal

   return mx_dot_vec(&vp[0]->p, &c) < 0;
}

  // check the facing of a polygon that may have
  // colinear points
bool r3_check_facing_n(int n, r3s_phandle *vp)
{
   real best, this;
   mxs_vector a,b,c,z;
   int i, which;

   mx_sub_vec(&a, &vp[0]->p, &vp[n-1]->p);

   best = -1;
   which = -1;

   for (i=0; i < n-1; ++i) {
      mx_sub_vec(&b, &vp[i+1]->p, &vp[i]->p);

        // find potential normal vector
      mx_cross_vec(&c, &b, &a);

        // if it's long enough, just use it
      this = mx_dot_vec(&c, &c);
      if (this > 0.1)
         goto ready_to_go;

        // if it's short, it might be colinear, it
        // might just be a tiny polygon, so save the
        // the longest one
      if (this > best) {
         best = this;
         z = c;
         which = i;
      }
      a = b;
   }

   if (which == -1) {
      Warning(("r3d: r3_check_facing_n: no non-colinear points found.\n"));
      return FALSE;
   }

     // reload normal
   c = z;

ready_to_go:

     // compare dot product of one pt with normal
   return mx_dot_vec(&vp[0]->p, &c) < 0;
}

  // check if a polygon is forward facing, takes a camera space normal
bool r3_check_v_normal(r3s_phandle vp, mxs_vector *n)
{
   // polygon is facing if    dot(point-camera, normal) < 0
   //   in this space, camera is at 0
   return mx_dot_vec(&vp->p, n) < 0;
}

   // check camera space pt & normal to see if forward facing
bool r3_check_v_normal_vec(mxs_vector *p, mxs_vector *n)
{
   return mx_dot_vec(p, n) < 0;
}

   // check worldspace pt & normal to see if forward facing
extern bool r3_check_w_normal_vec(mxs_vector *p, mxs_vector *n)
{
   mxs_vector temp;
   mx_sub_vec(&temp, p, &r3d_state.cur_con->trans.vino);   // HACK HACK HACK
         // this is wrong--should be  trans.vinw   but it don't exist
   return mx_dot_vec(&temp, n) < 0;
}

   // check object space pt & normal to see if forward facing
extern bool r3_check_o_normal_vec(mxs_vector *p, mxs_vector *n)
{
   mxs_vector temp;
   mx_sub_vec(&temp, p, &r3d_state.cur_con->trans.vino);
   return mx_dot_vec(&temp, n) < 0;
}
::::::::::::::
primfunc.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/primfunc.c 1.10 1996/05/29 00:08:46 buzzard Exp $

#include <lg.h>
#include <2d.h>

#include <ctxts.h>
#include <prim.h>
#include <primcon_.h>
#include <primtab_.h>
#include <primfunc.h>
#include <clipcon_.h>

#include <grnull.h>
#include <primpoly.h>

// remove debugging macro
#undef r3_compute_prim_funcs

int (*tmap_3d_funcs[])(int, r3s_phandle *, r3s_texture) =
{
   r3_any,
   r3_clip_any,
   r3_check_any,
   r3_check_clip_any
};

int (*poly_3d_funcs[])(int, r3s_phandle *) =
{
   r3_implicit_any,
   r3_clip_implicit_any,
   r3_check_implicit_any,
   r3_check_clip_implicit_any
};

int tmap_2d_funcs[] =
{
   // 0
   FIX_POLY, FIX_UPOLY,                     //      solid unlit
   FIX_SPOLY, FIX_USPOLY,                   //      solid gouraud
   FIX_CPOLY, FIX_UCPOLY,                   //      solid rgb gouraud
   -1, -1,                                  //      solid pal gouraud

   // 8
   FIX_TLUC8_POLY, FIX_TLUC8_UPOLY,         //      transluc unlit
   -1, -1,                                  //      transluc gouraud
   -1, -1,                                  //      transluc rgb gouraud
   -1, -1,                                  //      transluc pal gouraud

   // 16
   DEVICE_PER_MAP, DEVICE_PER_UMAP,         //      texture unlit
   DEVICE_LIT_PER_MAP, DEVICE_LIT_PER_UMAP, //      texture gouraud
   -1, -1,                                  //      texture rgb gouraud
   -1, -1,                                  //      texture pal gouraud

   // 24
   FLAT8_LMAP, FLAT8_ULMAP,                 //      linear unlit
   FLAT8_LIT_LIN_MAP, FLAT8_LIT_LIN_UMAP,   //      linear gouraud
   -1, -1,                                  //      linear rgb gouraud
   -1, -1                                   //      linear pal gouraud
};
//   FLAT8_PER_MAP, FLAT8_PER_UMAP,         //      texture unlit
//   FLAT8_LIT_PER_MAP, FLAT8_LIT_PER_UMAP, //      texture gouraud

// determine which parameters to clip
static int clip_flags[] =
{
   0,0,
   R3_CLIP_I, R3_CLIP_I,
   R3_CLIP_RGB, R3_CLIP_RGB,
   R3_CLIP_I, R3_CLIP_I,
   0,0,
   R3_CLIP_I, R3_CLIP_I,
   R3_CLIP_RGB, R3_CLIP_RGB,
   R3_CLIP_I, R3_CLIP_I,
   R3_CLIP_UV, R3_CLIP_UV,
   R3_CLIP_ALL, R3_CLIP_ALL,
   R3_CLIP_RGB | R3_CLIP_UV, R3_CLIP_RGB | R3_CLIP_UV,  // clipping UV and RGB not really supported
   R3_CLIP_ALL, R3_CLIP_ALL,
   R3_CLIP_UV, R3_CLIP_UV,
   R3_CLIP_ALL, R3_CLIP_ALL,
   R3_CLIP_RGB | R3_CLIP_UV, R3_CLIP_RGB | R3_CLIP_UV,  // clipping UV and RGB not really supported
   R3_CLIP_ALL, R3_CLIP_ALL
};

  // internal function to set up function pointers
#ifdef DBG_ON
 void r3_compute_prim_funcs(int funcs, char *name)
#else
 void r3_compute_prim_funcs(int funcs)
#endif
{
   int poly_mode;

     // compute poly index if we do any 3d poly functions
   if (funcs & (R3FUNC_3D_POLY | R3FUNC_3D_TMAP))
      if (r3d_poly_flags & R3_PL_CHECK_FACING)
         poly_mode = r3d_clip_mode != R3_NO_CLIP ? 3 : 2;
      else
         poly_mode = r3d_clip_mode != R3_NO_CLIP ? 1 : 0;

   if (funcs & R3FUNC_3D_POLY) {
      switch (r3d_poly_flags & R3_PL_MODE_MASK) {
         case R3_PL_POLYGON:
            r3_3d_poly_func  = poly_3d_funcs[poly_mode];
            break;

#ifdef DBG_ON
         case R3_PL_TRISTRIP:
            Warning(("r3d: r3_compute_prim_funcs:\n  TRISTRIP mode not supported in %s\n", name));
            break;
            
         case R3_PL_TRIFAN:
            Warning(("r3d: r3_compute_prim_funcs:\n  TRIFAN mode not supported in %s\n", name));
            break;

         case R3_PL_QUADSTRIP:
            Warning(("r3d: r3_compute_prim_funcs:\n  QUADSTRIP mode not supported in %s\n", name));
            break;
#endif
         default:
            Warning(("r3d: r3_compute_prim_funcs:\n  Unhandled polygon drawing mode in %s\n", name));
      }
   }
   if (funcs & R3FUNC_3D_TMAP) {
      switch (r3d_poly_flags & R3_PL_MODE_MASK) {
         case R3_PL_POLYGON:
            r3_3d_tmap_func  = tmap_3d_funcs[poly_mode];
            break;

#ifdef DBG_ON
         case R3_PL_TRISTRIP:
            Warning(("r3d: r3_compute_prim_funcs:\n  TRISTRIP mode not supported in %s\n", name));
            break;
            
         case R3_PL_TRIFAN:
            Warning(("r3d: r3_compute_prim_funcs:\n  TRIFAN mode not supported in %s\n", name));
            break;

         case R3_PL_QUADSTRIP:
            Warning(("r3d: r3_compute_prim_funcs:\n  QUADSTRIP mode not supported in %s\n", name));
            break;
#endif
         default:
            Warning(("r3d: r3_compute_prim_funcs:\n  Unhandled tmap drawing mode in %s\n", name));
      }
   }
   if (funcs & R3FUNC_2D_POLY) {
      int index = ((r3d_poly_flags & (48+12)) >> 1) | !r3d_clip_2d;
      int x = tmap_2d_funcs[index];
#ifdef DBG_ON
      if (x == -1) {
         Warning(("r3d: r3_compute_prim_funcs:\n  set an invalid polygon type in %s\n", name));
         goto set_bad_func;
      }
#endif
      if (index >= 16 && index < 24 && r3d_bm)
         x += 2 * (r3d_bm->type);   // this is the wacky 2D formula, don't blame me man
      r3_2d_tmap_func  = (void (*)(grs_bitmap *_bm,int _n,grs_vertex **_vpl)) grd_canvas_table[x];
#ifdef DBG_ON
      if (r3_2d_tmap_func == gr_null && r3d_bm) {
         Warning(("r3d: r3_compute_prim_funcs:\n  current polygon function is gr_null in %s\n", name));
        set_bad_func:
         r3_2d_tmap_func = (void (*) (grs_bitmap *, int, grs_vertex **)) gr_silent_null; // don't print any error messages
      }
#endif
      r3d_clip_flags = clip_flags[index];
   }
   if (funcs & R3FUNC_2D_LINE) {
      r3_2d_line_func  = NULL;
   }
   if (funcs & R3FUNC_2D_POINT) {
      r3_2d_point_func = NULL;
   }
}
::::::::::::::
primmisc.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/primmisc.c 1.4 1996/05/26 15:42:43 buzzard Exp $

//  3D misc rendering primitives

#include <r3ds.h>
#include <primtab_.h>
#include <clipcon_.h>
#include <primcon_.h>
#include <clipprim.h>
#include <_test.h>

int r3_draw_point(r3s_phandle p)
{
   TEST_IN_BLOCK_RETVAL("r3_draw_point",0);
   if (r3d_clip_mode)
      if (p->ccodes)
         return CLIP_ALL;

   return r3_2d_point_func(r3d_color, (grs_vertex *) &p->grp);
}

int r3_draw_line(r3s_phandle p0, r3s_phandle p1)
{
   TEST_IN_BLOCK_RETVAL("r3_draw_line",0);
   gr_set_fcolor(r3d_color);
   if (r3d_clip_mode != R3_NO_CLIP) {
      r3s_phandle *res, pt[2];
      pt[0] = p0; pt[1] = p1;
      if (!r3_clip_line(pt, &res))
         return CLIP_ALL;
      return gr_fix_line(res[0]->grp.sx, res[0]->grp.sy, res[1]->grp.sx, res[1]->grp.sy);
   } else
      return gr_fix_line(p0->grp.sx, p0->grp.sy, p1->grp.sx, p1->grp.sy);
}

#pragma off(unreferenced)
int r3_bitmap (r3s_texture bm, r3s_phandle p)
{
   return 0;
}

int r3_make_bitmap_poly(r3s_texture bm, r3s_phandle p, r3s_phandle *dest)
{
   return 0;
}
#pragma on(unreferenced)
::::::::::::::
primpoly.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/primpoly.c 1.12 1996/05/26 23:03:08 buzzard Exp $
//
//  polygon drawing functions

#include <lg.h>

#include <r3ds.h>
#include <primtab_.h>
#include <primface.h>
#include <primcon_.h>
#include <clipprim.h>
#include <clip.h>
#include <primconv.h>



extern grs_vertex **r3_new2d_to_old2d_hack(int n, grs_point **src, grs_bitmap *hack); // HACK HACK HACK

//  key to naming conventions:
//     check    = check backfacing
//     clip     = apply 3d clipping
//     implicit = r3_draw_poly call--texture not passed in

int r3_check_clip_any(int n, r3s_phandle *vp, r3s_texture bm)
{
   if (r3_check_facing_n(n, vp)) {
      n = r3_raw_clip_polygon(n, vp, &vp);
      if (n) {
         grs_point *p2[32];
         r3_phandle_to_vertex_list(n, vp, p2);
         return r3_2d_tmap_func(bm, n, r3_new2d_to_old2d_hack(n, p2, bm));
      }
   }
   return CLIP_ALL;
}

int r3_check_any(int n, r3s_phandle *vp, r3s_texture bm)
{
   if (r3_check_facing_n(n, vp)) {
      grs_point *p2[32];
      r3_phandle_to_vertex_list(n, vp, p2);
      return r3_2d_tmap_func(bm, n, r3_new2d_to_old2d_hack(n, p2, bm));
   }
   return CLIP_ALL;
}   

int r3_clip_any(int n, r3s_phandle *vp, r3s_texture bm)
{
   n = r3_raw_clip_polygon(n, vp, &vp);
   if (n) {
      grs_point *p2[32];
      r3_phandle_to_vertex_list(n, vp, p2);
      return r3_2d_tmap_func(bm, n, r3_new2d_to_old2d_hack(n, p2, bm));
   }
   return CLIP_ALL;
}

int r3_any(int n, r3s_phandle *vp, r3s_texture bm)
{
   grs_point *p2[32];
   r3_phandle_to_vertex_list(n, vp, p2);
   return r3_2d_tmap_func(bm, n, r3_new2d_to_old2d_hack(n, p2, bm));
}

// just convert the points and call the implicit texture
int r3_convert_implicit(int n, r3s_phandle *vp)
{
   grs_point *p2[32];
   r3_phandle_to_vertex_list(n, vp, p2);
   return r3_2d_tmap_func(r3d_bm, n, r3_new2d_to_old2d_hack(n, p2, r3d_bm));
}

int r3_check_clip_implicit_any(int n, r3s_phandle *vp)
{
   if (r3_check_facing_n(n, vp)) {
      n = r3_raw_clip_polygon(n, vp, &vp);
      if (n)
         return r3_convert_implicit(n, vp);
   }
   return CLIP_ALL;
}

int r3_check_implicit_any(int n, r3s_phandle *vp)
{
   if (r3_check_facing_n(n, vp))
      return r3_convert_implicit(n, vp);
   return CLIP_ALL;
}

int r3_clip_implicit_any(int n, r3s_phandle *vp)
{
   n = r3_raw_clip_polygon(n, vp, &vp);
   if (n)
      return r3_convert_implicit(n, vp);
   return CLIP_ALL;
}
::::::::::::::
clip.c
::::::::::::::
#include <clipcon_.h>
#include <primfunc.h>

  // specify whether clipping is on or off
void r3_set_clipmode(r3e_clipmode x)
{
   r3d_clip_mode = x;
   r3_compute_prim_funcs(R3FUNC_ALL_3D, "r3_set_clipmode");
}

  // do initialization when a new view matrix is specified
void r3_set_clip(void)
{
   r3_compute_prim_funcs(R3FUNC_ALL, "r3_set_clip during context initialization");
}

void r3_set_clip_flags(int flags)
{
   r3d_clip_flags = flags;
}
::::::::::::::
clipclip.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/clipclip.c 1.7 1996/05/25 22:50:25 buzzard Exp $

// clipping is:
//    off the right is  y < -x
//    off the left is   y > x
//    off the top is    z > x
//    off the bottom is z < -x

//  clipspace clipping

#include <r3ds.h>
#include <clip_.h>
#include <clipcon_.h>
#include <clipoff.h>
#include <_test.h>

void r3_clipspace_code_points(int n, r3s_point *src)
{
   int i;
   r3s_point *p = src;
   real nearxxx = r3d_near_plane;

   TEST_IN_BLOCK("r3_clipspace_code_points");

   for (i=0; i < n; ++i) {
      int code = 0;
      real z = p->p.z;

      if (p->p.x > z) code = R3C_OFF_RIGHT; else code = R3C_NONE;
      if (p->p.x < -z) code |= R3C_OFF_LEFT;

      if (p->p.y < -z) code |= R3C_OFF_TOP;
      if (p->p.y > z) code |= R3C_OFF_BOTTOM;

      if (z < nearxxx) code |= R3C_BEHIND;

      p->ccodes = code;
      ++p;
   }   

   if (r3d_num_planes)
      r3_std_code_points(n, src);
}
::::::::::::::
clipglob.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/clipglob.c 1.12 1996/05/27 19:52:32 buzzard Exp $
#include <math.h>

#include <mprintf.h>
#include <lg.h>
#include <ctxts.h>
#include <r3ds.h>
#include <clipcon_.h>
#include <clip_.h>
#include <clipoff.h>
#include <xform.h>
#include <clipu.h>
#include <_test.h>

real r3_pt_dist(r3s_point *src, mxs_plane *clip)
{
   return mx_dot_vec(&src->p, &clip->v) + clip->d;
}

#define r3_pt_side_test(a,b)   (r3_pt_dist(a,b) < 0)

// recode all user clip planes in any intermediate space
void r3_std_code_points(int n, r3s_point *src)
{
   int i,k = r3d_num_planes;
   r3s_clip_plane *clip_plane = (r3s_clip_plane *) r3d_clip_data;

   TEST_IN_BLOCK("r3_std_code_points");
   
   if (k == 1) {
      // if only one clip plane, don't do waste time on innermost loop
      for (i=0; i < n; ++i) {
         if (r3_pt_side_test(src, &clip_plane[0].view_plane))
            src->ccodes |= 1 << NUM_STD_CCODES;
         ++src;
      }
   } else {
      for (i=0; i < n; ++i) {
         int code=0,j;

         for (j=0; j < k; ++j)
            if (r3_pt_side_test(src, &clip_plane[j].view_plane))
               code |=  1 << j;

         src->ccodes |= code << NUM_STD_CCODES;
         ++src;
      }
   }
}

int r3_ccodes_or;
int r3_ccodes_and;

int r3_code_polygon(int n, r3s_phandle *src)
{
   int i, c_or, c_and,k;
   c_or = c_and = src[0]->ccodes;
   for (i=1; i < n; ++i) {
      k = src[i]->ccodes;
      c_or |= k;
      c_and &= k;
   }
   r3_ccodes_or = c_or;
   r3_ccodes_and = c_and;
   return c_or;
}

#define NUM_CLIP_PTS 32

static r3s_phandle clip1[128];
static r3s_phandle clip2[128];
static r3s_point clippt[NUM_CLIP_PTS];
r3s_point *r3_next_point;

r3s_point *r3_clip_left  (r3s_point *p, r3s_point *q);
r3s_point *r3_clip_top   (r3s_point *p, r3s_point *q);
r3s_point *r3_clip_bottom(r3s_point *p, r3s_point *q);
r3s_point *r3_clip_right (r3s_point *p, r3s_point *q);
r3s_point *r3_clip_behind(r3s_point *p, r3s_point *q);
r3s_point *r3_clip_user_plane(r3s_point *p, r3s_point *q, int n);

#define FP(x)   ((int) ((x) * 65536))

   // externally callable interface
int r3_clip_polygon(int n, r3s_phandle *src, r3s_phandle **dest)
{
   TEST_IN_BLOCK_RETVAL("r3_clip_polygon", 0);
   if (r3d_clip_mode == R3_NO_CLIP) { *dest = src; return n; }
   return r3_raw_clip_polygon(n, src, dest);
}

   // internally direct-called interface
int r3_raw_clip_polygon(int n, r3s_phandle *src, r3s_phandle **dest)
{
   int i, code, c_or, j, k, last_code, p;
   r3s_phandle *out;

   TEST_IN_BLOCK_RETVAL("r3_raw_clip_polygon",0);

   if (!r3_code_polygon(n, src)) {
      *dest = src;
      return n;    // trivial accept
   }

   if (r3_ccodes_and)
      return 0;    // trivial reject

   c_or = r3_ccodes_or;
   r3_next_point = clippt;

      // check if we do main cone clipping
   if (r3d_clip_mode == R3_CLIP) {
      // clip by main clip planes

      // clipping logic is as follows:
      //   iterate through all points.  add to the
      //   new polygon all points that are inside and
      //   all points that are intersections of edge
      //   with a given plane.  recompute new c_or code
      //   as we go.
      //
      // If a polygon gets clipped away entirely but isn't
      // trivially rejected, then eventually its vertex count
      // goes to 0.  We don't explicitly check for this;
      // instead its c_or is 0 and it early outs that way.

      if (c_or & R3C_OFF_LEFT) {
         c_or = 0; j = n-1; k=0; last_code = src[j]->ccodes;
         out = clip1;
         for (i=0; i < n; ++i) {
            code = src[i]->ccodes;

            // if code changes value at this point, generate clipped pt
            if ((code ^ last_code) & R3C_OFF_LEFT) {
               out[k] = r3_clip_left(src[i], src[j]);
               c_or |= out[k++]->ccodes;
            }

            // if leading pt is inside, include it
            if (!(code & R3C_OFF_LEFT))
               out[k++] = src[i], c_or |= code;

            j = i;
            last_code = code;
         }
         src = out;
         n = k;
      }

      if (c_or & R3C_OFF_RIGHT) {
         c_or = 0; j = n-1; k=0; last_code = src[j]->ccodes;
         out = ((src == clip1) ? clip2 : clip1);
         for (i=0; i < n; ++i) {
            code = src[i]->ccodes;

            // if code changes value at this point, generate clipped pt
            if ((code ^ last_code) & R3C_OFF_RIGHT) {
               out[k] = r3_clip_right(src[i], src[j]);
               c_or |= out[k++]->ccodes;
            }

            // if leading pt is inside, include it
            if (!(code & R3C_OFF_RIGHT))
               out[k++] = src[i], c_or |= code;

            j = i;
            last_code = code;
         }
         src = out;
         n = k;
      }

      if (c_or & R3C_OFF_TOP) {
         c_or = 0; j = n-1; k=0; last_code = src[j]->ccodes;
         out = ((src == clip1) ? clip2 : clip1);
         for (i=0; i < n; ++i) {
            code = src[i]->ccodes;

            // if code changes value at this point, generate clipped pt
            if ((code ^ last_code) & R3C_OFF_TOP) {
               out[k] = r3_clip_top(src[i], src[j]);
               c_or |= out[k++]->ccodes;
            }

            // if pt is inside, include it
            if (!(code & R3C_OFF_TOP))
               out[k++] = src[i], c_or |= code;

            j = i;
            last_code = code;
         }
         src = out;
         n = k;
      }

      if (c_or & R3C_OFF_BOTTOM) {
         c_or = 0; j = n-1; k=0; last_code = src[j]->ccodes;
         out = ((src == clip1) ? clip2 : clip1);
         for (i=0; i < n; ++i) {
            code = src[i]->ccodes;

            // if code changes value at this point, generate clipped pt
            if ((code ^ last_code) & R3C_OFF_BOTTOM) {
               out[k] = r3_clip_bottom(src[i], src[j]);
               c_or |= out[k++]->ccodes;
            }

            // if pt is inside, include it
            if (!(code & R3C_OFF_BOTTOM))
               out[k++] = src[i], c_or |= code;

            j = i;
            last_code = code;
         }
         src = out;
         n = k;
      }

      if (c_or & R3C_BEHIND) {
         c_or = 0; j = n-1; k=0; last_code = src[j]->ccodes;
         out = ((src == clip1) ? clip2 : clip1);
         for (i=0; i < n; ++i) {
            code = src[i]->ccodes;

            // if code changes value at this point, generate clipped pt
            if ((code ^ last_code) & R3C_BEHIND) {
               out[k] = r3_clip_behind(src[i], src[j]);
               c_or |= out[k++]->ccodes;
            }

            // if pt is inside, include it
            if (!(code & R3C_BEHIND))
               out[k++] = src[i], c_or |= code;

            j = i;
            last_code = code;
         }
         src = out;
         n = k;
      }

      // now code all the points by the user planes at once
      // this avoids testing r3d_num_planes at every point
      if (r3d_num_planes && r3_next_point != clippt) {
         r3_std_code_points(r3_next_point - clippt, clippt);
         c_or = 0;
         for (i=0; i < n; ++i)
            c_or |= src[i]->ccodes;
      }
   }

   if (c_or) {
      int this_code=1 << NUM_STD_CCODES;
      for (p=0; p < r3d_num_planes; ++p, this_code <<= 1) {
         if (c_or & this_code) {
            c_or = 0; j = n-1; k=0; last_code = src[j]->ccodes;
            out = ((src == clip1) ? clip2 : clip1);
            for (i=0; i < n; ++i) {
               code = src[i]->ccodes;

               // if code changes value at this point, generate clipped pt
               if ((code ^ last_code) & this_code) {
                  out[k] = r3_clip_user_plane(src[i], src[j], p);
                  c_or |= out[k++]->ccodes;
               }

               // if pt is inside, include it
               if (!(code & this_code))
                  out[k++] = src[i], c_or |= code;

               j = i;
               last_code = code;
            }
            src = out;
            n = k;
         }
      }
   }

#ifdef DBG_ON
   if (c_or) {
      Warning(("r3d: r3d_clip_polygon: invalid clipping\n"));
      return 0;
   }
#endif

   *dest = src;
   return n;
}

bool r3_clip_line(r3s_phandle *src,r3s_phandle **dest)
{
   r3s_phandle *out;
   int c_or, c_and;

   *dest = src;

   c_or = (src[0]->ccodes | src[1]->ccodes);
   if (!c_or) return TRUE;  // trivial accept
   c_and = (src[0]->ccodes & src[1]->ccodes);
   if (c_and) return FALSE; // trivial reject

   r3_next_point = clippt;

     // check each of the planes one by one
     //   (only the first is commented; they're all cut&pasted)

   if (r3d_clip_mode == R3_CLIP) {
      if (c_or & R3C_OFF_LEFT) {
           // select which buffer to output to
         out = clip1;
           // put the intersection of the line with the plane into output
         out[0] = r3_clip_left(src[0], src[1]);
           // copy whichever point is inside into the output
         out[1] = src[0]->ccodes & R3C_OFF_LEFT ? src[1] : src[0];
           // move the output to be the new input
         src = out;
           // check for it being totally clipped away
           // (required since rest of code assumes it's not)
         if (src[0]->ccodes & src[1]->ccodes) return FALSE;
           // compute the new clip code
         c_or = src[0]->ccodes | src[1]->ccodes;
      }
      if (c_or & R3C_OFF_RIGHT) {
         out = ((src == clip1) ? clip2 : clip1);
         out[0] = r3_clip_right(src[0], src[1]);
         out[1] = src[0]->ccodes & R3C_OFF_RIGHT ? src[1] : src[0];
         src = out;
         if (src[0]->ccodes & src[1]->ccodes) return FALSE;
         c_or = src[0]->ccodes | src[1]->ccodes;
      }
      if (c_or & R3C_OFF_TOP) {
         out = ((src == clip1) ? clip2 : clip1);
         out[0] = r3_clip_top(src[0], src[1]);
         out[1] = src[0]->ccodes & R3C_OFF_TOP ? src[1] : src[0];
         src = out;
         if (src[0]->ccodes & src[1]->ccodes) return FALSE;
         c_or = src[0]->ccodes | src[1]->ccodes;
      }
      if (c_or & R3C_OFF_BOTTOM) {
         out = ((src == clip1) ? clip2 : clip1);
         out[0] = r3_clip_bottom(src[0], src[1]);
         out[1] = src[0]->ccodes & R3C_OFF_BOTTOM ? src[1] : src[0];
         src = out;
         if (src[0]->ccodes & src[1]->ccodes) return FALSE;
         c_or = src[0]->ccodes | src[1]->ccodes;
      }
      if (c_or & R3C_BEHIND) {
         out = ((src == clip1) ? clip2 : clip1);
         out[0] = r3_clip_behind(src[0], src[1]);
         out[1] = src[0]->ccodes & R3C_BEHIND ? src[1] : src[0];
         src = out;
         if (src[0]->ccodes & src[1]->ccodes) return FALSE;
         c_or = src[0]->ccodes | src[1]->ccodes;
      }
      // recode points by user clip planes
      if (r3d_num_planes && r3_next_point != clippt) {
         r3_std_code_points(r3_next_point - clippt, clippt);
         if (src[0]->ccodes & src[1]->ccodes) return FALSE;
         c_or = src[0]->ccodes | src[1]->ccodes;
      }
   }

     // clip against user planes
   if (c_or) {
      int p,this_code=1 << NUM_STD_CCODES;
      for (p=0; p < r3d_num_planes; ++p, this_code <<= 1) {
         if (c_or & this_code) {
            out = ((src == clip1) ? clip2 : clip1);
            out[0] = r3_clip_user_plane(src[0], src[1], p);
            out[1] = (src[0]->ccodes & this_code) ? src[1] : src[0];
            src = out;
            if (src[0]->ccodes & src[1]->ccodes) return FALSE;
            c_or = src[0]->ccodes | src[1]->ccodes;
         }
      }
   }

#ifdef DBG_ON
   if (c_or) {
      Warning(("r3d: r3d_clip_line: invalid clipping\n"));
      return FALSE;
   }
#endif

   *dest = src;
   return TRUE;
}

#define swap(p,q)    do { r3s_point *temp = p; p = q; q = temp; } while(0)

// General comments about all clip functions:
   // we swap points so result is the same regardless of point order
   // note that unlike old 3d, we don't compare something like z,
   // which can (trivially!) be constant.

#define weight(p,q,parm,frac)    (p->parm + frac * (q->parm - p->parm))

real r3_clip_frac;

void r3_intersect(r3s_point *p, r3s_point *q)
{
   r3s_point *pt = r3_next_point-1;
   int flags = r3d_clip_flags;

   if (r3_next_point == clippt + NUM_CLIP_PTS) {
      Warning(("r3d fatal error: Overflowed static NUM_CLIP_PTS limit.\n"));
      return;
   }

   if (flags & R3_CLIP_I)
      pt->grp.i = weight(p,q,grp.i,r3_clip_frac);
   if (flags & R3_CLIP_U)
      pt->grp.u = weight(p,q,grp.u,r3_clip_frac);
   if (flags & R3_CLIP_V)
      pt->grp.v = weight(p,q,grp.v,r3_clip_frac);

   r3_project_point(pt);
}

#define CODE_RIGHT(pt)  (pt->p.x > jz ? R3C_OFF_RIGHT : 0)
#define CODE_TOP(pt)    (pt->p.y < -jz ? R3C_OFF_TOP : 0)
#define CODE_BOTTOM(pt) (pt->p.y > jz ? R3C_OFF_BOTTOM : 0)
#define CODE_BEHIND(pt) (pt->p.z < r3d_near_plane ? R3C_BEHIND : 0)

#define PX  (p->p.x)
#define PY  (p->p.y)
#define PZ  (p->p.z)
#define QX  (q->p.x)
#define QY  (q->p.y)
#define QZ  (q->p.z)

//    boundary is x + z = 0
//  dist from boundary is   PX + PZ

static real iz, jz;

r3s_point *r3_clip_left(r3s_point *p, r3s_point *q)
{
   r3s_point *pt = r3_next_point++;   
   if (p->ccodes & R3C_OFF_LEFT) swap(p,q);

   r3_clip_frac = (PX + PZ*r3d_glob.x_clip) / (PX - QX + (PZ - QZ) * r3d_glob.x_clip);

   pt->p.y = PY + r3_clip_frac * (QY - PY);
   pt->p.z = PZ + r3_clip_frac * (QZ - PZ);
   pt->p.x = -pt->p.z * r3d_glob.x_clip;

   r3_intersect(p, q);
   iz = pt->p.z * r3d_glob.x_clip;
   jz = pt->p.z * r3d_glob.y_clip;
   pt->ccodes = CODE_RIGHT(pt) | CODE_TOP(pt) | CODE_BOTTOM(pt) | CODE_BEHIND(pt);
   return pt;
}

r3s_point *r3_clip_right(r3s_point *p, r3s_point *q)
{
   r3s_point *pt = r3_next_point++;   
   if (p->ccodes & R3C_OFF_RIGHT) swap(p,q);

   r3_clip_frac = (r3d_glob.x_clip * PZ - PX) / (r3d_glob.x_clip * (PZ - QZ) + QX - PX);
   pt->p.y = PY + r3_clip_frac * (QY - PY);
   pt->p.z = PZ + r3_clip_frac * (QZ - PZ);
   pt->p.x = pt->p.z * r3d_glob.x_clip;

   r3_intersect(p, q);
   jz = pt->p.z * r3d_glob.y_clip;
   pt->ccodes = CODE_TOP(pt) | CODE_BOTTOM(pt) | CODE_BEHIND(pt);
   return pt;
}

r3s_point *r3_clip_top(r3s_point *p, r3s_point *q)
{
   r3s_point *pt = r3_next_point++;   
   if (p->ccodes & R3C_OFF_TOP) swap(p,q);

   r3_clip_frac = (PY + PZ*r3d_glob.y_clip) / (r3d_glob.y_clip * (PZ - QZ) + PY - QY);
   pt->p.x = PX + r3_clip_frac * (QX - PX);
   pt->p.z = PZ + r3_clip_frac * (QZ - PZ);
   pt->p.y = -pt->p.z * r3d_glob.y_clip;

   r3_intersect(p, q);
   jz = pt->p.z * r3d_glob.y_clip;
   pt->ccodes = CODE_BOTTOM(pt) | CODE_BEHIND(pt);
   return pt;
}

r3s_point *r3_clip_bottom(r3s_point *p, r3s_point *q)
{
   r3s_point *pt = r3_next_point++;   
   if (p->ccodes & R3C_OFF_BOTTOM) swap(p,q);

   r3_clip_frac = (PZ*r3d_glob.y_clip - PY) / (r3d_glob.y_clip*(PZ - QZ) + QY - PY);
   pt->p.x = PX + r3_clip_frac * (QX - PX);
   pt->p.z = PZ + r3_clip_frac * (QZ - PZ);
   pt->p.y = pt->p.z * r3d_glob.y_clip;

   r3_intersect(p, q);
   pt->ccodes = CODE_BEHIND(pt); // & ~R3C_OFF_BOTTOM;
   return pt;
}

//  z = r3d_near_plane
// dist is   PZ - r3d_near_plane
r3s_point *r3_clip_behind(r3s_point *p, r3s_point *q)
{
   r3s_point *pt = r3_next_point++;   
   if (p->ccodes & R3C_BEHIND) swap(p,q);

   r3_clip_frac = (PZ - r3d_near_plane) / (PZ - QZ);
   pt->p.x = PX + r3_clip_frac * (QX - PX);
   pt->p.y = PY + r3_clip_frac * (QY - PY);
   pt->p.z = r3d_near_plane;

   r3_intersect(p, q);
   pt->ccodes = 0;
   return pt;
}

r3s_point *r3_clip_user_plane(r3s_point *p, r3s_point *q, int n)
{
   r3s_clip_plane *clip = r3d_clip_data;
   mxs_plane *m = &clip[n].view_plane;
   r3s_point *pt = r3_next_point++;
   real dp,dq;
   int i, code = 1 << (n + NUM_STD_CCODES);

   if (p->ccodes & code) swap(p,q);

   dp = r3_pt_dist(p, m);
   dq = r3_pt_dist(q, m);

   r3_clip_frac = dp / (dp - dq);
   pt->p.x = PX + r3_clip_frac * (QX - PX);
   pt->p.y = PY + r3_clip_frac * (QY - PY);
   pt->p.z = PZ + r3_clip_frac * (QZ - PZ);

   r3_intersect(p, q);

   // now clip code it to all of the planes after this one
   code = 0;
   for (i=n+1; i < r3d_num_planes; ++i) {
      if (r3_pt_side_test(pt, &clip[i].view_plane))
         code |= 1 << i;
   }
   pt->ccodes = code << NUM_STD_CCODES;

   return pt;
}
::::::::::::::
clipplan.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/clipplan.c 1.6 1996/05/27 19:52:24 buzzard Exp $

// User-defined clipping plane management

#include <lg.h>
#include <r3ds.h>
#include <clipu.h>
#include <space.h>
#include <clip_.h>

#define cclip   (r3d_state.cur_con->clip)

void r3_compute_camera_planes(void)
{
   r3s_clip_plane *clip = (r3s_clip_plane *) cclip.clip_data;
   int i,n = cclip.num_user_planes;
   for (i=0; i < n; ++i) {
      r3_w2c_plane(&clip[i].view_plane, &clip[i].world_plane);
   }
}

void r3_clear_clip_planes(void)
{
   cclip.num_user_planes = 0;
}

void r3_pop_clip_plane(void)
{
   if (cclip.num_user_planes <= 0) {
      Warning(("r3_pop_clip_plane: tried to pop too many planes\n"));
      return;
   }

   --cclip.num_user_planes;
}

  // worldspace plane
void r3_push_clip_plane(mxs_plane *p)
{
   int n;
   r3s_clip_plane *clip;

   if (cclip.num_user_planes >= NUM_USER_PLANES) {
      // there's only room for NUM_USER_PLANES clip codes,
      // so planes beyond that don't work correctly.

      Warning(("r3_push_clip_plane: tried to have more than %d planes\n", NUM_USER_PLANES));

      // but we'll still allow it to get allocated so that
      // pushes match pops
   }

   if (cclip.num_user_planes == cclip.max_user_planes) {
      int n;
      void *q;
      n = cclip.max_user_planes * 2;
      if (n == 0) n = 1;
      
      q = Realloc(cclip.clip_data, sizeof(r3s_clip_plane) * n);
#ifdef DBG_ON
      if (!q) {
         Warning(("r3d: r3_push_clip_plane: out of memory at depth %d\n", n));
         return;
      }
#endif

      cclip.clip_data = q;
      cclip.max_user_planes = n;

      Warning(("r3d: r3_push_clip_plane: needs to realloc, increase default clipping planes\n"));
   }

   clip = (r3s_clip_plane *) cclip.clip_data;   

   n = cclip.num_user_planes++;

     // copy the passed in user plane
   clip[n].world_plane = *p;

     // compute the version in camera space
   r3_w2c_plane(&clip[n].view_plane, &clip[n].world_plane);
}
::::::::::::::
clipproj.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/clipproj.c 1.3 1996/05/15 23:36:11 buzzard Exp $

#include <lg.h>
#include <r3ds.h>
#include <clip_.h>
#include <clipoff.h>
#include <clipcon_.h>

#define cur_canv   (r3d_state.cur_con->cnv)

//  for project space, i = -y/x + i_center
//  now, to check the "left" clipping plane,
//  we test i < 0:
//    -y/x + i_center < 0
//    -y/x < -i_center
//    if x > 0
//      -y < -i_center * x
//      y > i_center*x

void r3_projectspace_code_points(int n, r3s_point *src)
{
   int i;
   r3s_point *p = src;
   real nearxxx = r3d_near_plane;
   fix w = fix_make(cur_canv->bm.w,0);
   fix h = fix_make(cur_canv->bm.h,0);

   for (i=0; i < n; ++i) {
      int code = 0;
      real z = p->p.z;
      
      if (z > nearxxx) {
         // fast clipping
         if (p->grp.sx < 0) code = R3C_OFF_LEFT;
         else if (p->grp.sx > w) code = R3C_OFF_RIGHT;
         else code = 0;

         if (p->grp.sy < 0) code |= R3C_OFF_TOP;
         else if (p->grp.sy > h) code |= R3C_OFF_BOTTOM;
      } else {
         // slow clipping (need two multiplies)
         real iz = z * r3d_glob.x_clip;
         real jz = z * r3d_glob.y_clip;
         if (p->p.x < -iz) code = R3C_OFF_LEFT | R3C_BEHIND; else code = R3C_BEHIND;
         if (p->p.x >  iz) code |= R3C_OFF_RIGHT;
         if (p->p.y < -jz) code |= R3C_OFF_TOP;
         if (p->p.y >  jz) code |= R3C_OFF_BOTTOM;
      }
      p->ccodes = code;
      ++p;
   }

   if (r3d_num_planes)
      r3_std_code_points(n, src);
}
::::::::::::::
clipunsc.c
::::::::::::::
// $Header: x:/prj/tech/libsrc/r3d/RCS/clipunsc.c 1.4 1996/05/25 22:50:26 buzzard Exp $

#include <lg.h>
#include <r3ds.h>
#include <clip_.h>
#include <clipoff.h>
#include <clipcon_.h>

#pragma off(unreferenced)
void r3_unscaledspace_code_points(int n, r3s_point *src)
{
   int i;
   r3s_point *p = src;
   real nearxxx = r3d_near_plane;
   real w = 1.0, h = 1.0;
   real w2 = w/2, h2 = h/2;

   for (i=0; i < n; ++i) {
      int code;
      real z = p->p.z;
      real iz = r3d_glob.x_clip * z;
      real jz = r3d_glob.y_clip * z;
      if (p->p.z < nearxxx) code = R3C_BEHIND; else code = 0;
      if (p->p.x < -iz) code |= R3C_OFF_LEFT;
      if (p->p.x >  iz) code |= R3C_OFF_RIGHT;
      if (p->p.y < -jz) code |= R3C_OFF_TOP;
      if (p->p.y >  jz) code |= R3C_OFF_BOTTOM;
      p->ccodes = code;
      ++p;
   }

   if (r3d_num_planes)
      r3_std_code_points(n, src);
}
#pragma on(unreferenced)
