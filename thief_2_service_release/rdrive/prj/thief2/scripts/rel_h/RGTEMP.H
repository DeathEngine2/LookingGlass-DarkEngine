/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  8/16/99 4:18:07 PM

  File:  rgTemp.h

  Description:  Temporary, to be discarded after 2d libs
               got fixed


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgtemp.h 1.2 1970/01/01 00:00:00 Zarko Exp $

#pragma once

#ifndef _RGTEMP_H
#define _RGTEMP_H


//_____INCLUDES_AND_DEFINITIONS___________________________

#ifndef __TMGR_H
#include <tmgr.h> // from lgd3d
#endif

#pragma warning ( disable :4201 )

#ifndef __G2_H 
#include <g2.h>
#endif

#ifndef __R3DS_H
#include <r3ds.h>
#endif

#define RGPALF_OPAQUE 1L
#define RGPALF_TRANS  2L
#define RGPALF_32BIT  4L




//______EXPORTED_DATA_____________________________________


#ifdef __cplusplus
extern "C" {
#endif

   // additional sets of texture coordinates are added
   typedef struct {
      float   u, v;
   } RG_tex_coord;
   
   
   typedef struct IRGDisplayCanvas IRGDisplayCanvas;

   extern texture_manager *get_texture_manager_proxy( void* manager, void* driver );
   
   
   // LGD3D EMULATION WRAPPERS
   
   
   extern IRGDisplayCanvas* ExtractDX6CanvasFromDispDev();
   

   extern int rgEnumerateD6Devces();

      
   typedef struct ILGSurface ILGSurface;

   extern BOOL CreateLGD6Surface( ILGSurface** ppILGSurf );

   //_____________________________________
   
   typedef int (*tRendGDrawPolyFunc)(int n, r3s_phandle *pl);
   
   extern tRendGDrawPolyFunc           rendg_draw_poly_func;
   
   typedef int (*tRendGDrawPolyIndexedFunc)( int n, r3s_phandle *pl, r3ixs_info *info );
   

   extern tRendGDrawPolyIndexedFunc    rendg_draw_poly_indexed_func;
   
   typedef void (*fp_release_IP)( void );
   
   extern fp_release_IP                rendg_release_ip_func;


   //////////////////////
   extern void rendg_clean_render_surface( BOOL bDepthBuffToo );
   
 
   
   extern void rendg_set_zcompare(BOOL bCompare);
   
   //not used
   //extern void rendg_zclear(void);
   
  
   
   extern int rendg_get_depth_buffer_state( void );
   

   extern int rendg_is_zcompare_on( void );
   
   
   
   // procedural textures
   extern void rendg_hack_light(r3s_point *p, float r);
   extern void rendg_hack_light_extra(r3s_point *p, float r, grs_bitmap *bm);
   
  
   
   // palettes
   extern void rendg_set_pal(uint start, uint n, uchar *pal);
   extern void rendg_set_pal_slot(uint start, uint n, uchar *pal, int slot);
   extern void rendg_set_pal_slot_flags(uint start, uint n, uchar *pal, int slot, int flags);
   
   extern void rendg_set_alpha_pal(ushort *pal);
   
  
   
   extern int rendg_draw_point(r3s_point *p);
   extern void rendg_draw_line(r3s_point *p0, r3s_point *p1);
   
   
   extern int rendg_trifan(int n, r3s_point **vpl);
   extern int rendg_lit_trifan(int n, r3s_point **vpl);
   extern int rendg_poly(int n, r3s_point **vpl);
   extern int rendg_spoly(int n, r3s_point **vpl);
   extern int rendg_g2upoly(int n, g2s_point **vpl);
   extern int rendg_g2poly(int n, g2s_point **vpl);
   extern int rendg_g2utrifan(int n, g2s_point **vpl);
   extern int rendg_g2trifan(int n, g2s_point **vpl);
   
   
   extern void rendg_tmap_setup(grs_bitmap *bm);
   extern void rendg_lit_tmap_setup(grs_bitmap *bm);
   extern void rendg_rgblit_tmap_setup(grs_bitmap *bm);
   extern void rendg_rgbalit_tmap_setup(grs_bitmap *bm);
   extern void rendg_rgbafoglit_tmap_setup(grs_bitmap *bm); // rgba + fog 
   extern void rendg_diffspecular_tmap_setup(grs_bitmap *bm); // rgba + fog 
   extern void rendg_poly_setup(grs_bitmap *bm);
   extern void rendg_spoly_setup(grs_bitmap *bm);
   extern void rendg_rgb_poly_setup(grs_bitmap *bm);
   extern void rendg_rgba_poly_setup(grs_bitmap *bm);
   
   
   extern int rendg_indexed_poly(int n, r3s_point **vpl, r3ixs_info *info);
   extern int rendg_indexed_spoly(int n, r3s_point **vpl, r3ixs_info *info);
   extern void rendg_rgblit_tmap_setup(grs_bitmap *bm);
   extern int rendg_lit_indexed_trifan(int n, r3s_point **vpl, r3ixs_info *info);
   
   extern void rendg_release_indexed_primitives( void );
   
   
   
   extern int rendg_TrifanMTD( int n, r3s_point **ppl, RG_tex_coord **pptc );
   extern int rendg_LitTrifanMTD( int n, r3s_point **ppl, RG_tex_coord **pptc );
   extern int rendg_RGBlitTrifanMTD( int n, r3s_point **ppl, RG_tex_coord **pptc );
   
   extern int rendg_RGBAlitTrifanMTD( int n, r3s_point **ppl, RG_tex_coord **pptc );
   extern int rendg_RGBAFoglitTrifanMTD( int n, r3s_point **ppl, RG_tex_coord **pptc );
   extern int rendg_DiffuseSpecularMTD( int n, r3s_point **ppl, RG_tex_coord **pptc );
   
   extern int rendg_g2UTrifanMTD( int n, g2s_point **vpl, RG_tex_coord **vptc );
   extern int rendg_g2TrifanMTD( int n, g2s_point **vpl, RG_tex_coord **vptc );
   
   
#ifdef __cplusplus
}
#endif









#endif //_RGTEMP_H