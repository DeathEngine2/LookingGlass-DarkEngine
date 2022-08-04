/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  9/20/99 9:40:31 AM

  File:  rgLgd3d.h

  Description:  Emulation of Lgd3d interface


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rglgd3d.h 1.1 1999/10/07 10:02:49 Zarko Exp $

#pragma once 

#ifndef _RGLGD3D_H
#define _RGLGD3D_H




#pragma warning ( disable :4201 )
#include <g2.h>

#include <r3ds.h>



#ifdef __cplusplus
extern "C" {
#endif
   
   // additional sets of texture coordinates are added
   typedef struct {
      float   u, v;
   } LGD3D_tex_coord;

   
#define LGRT_SINGLE_TEXTURE_SINGLE_PASS     0L
#define LGRT_MULTI_TEXTURE_SINGLE_PASS      1L
   
   //NOTE: multipass multitexturing is not supported!!!
   
   // Capabilities that can be requested:
   
#define LGD3DF_SPEW                    0x00000002L
   
   //depth buffer:
#define LGD3DF_ZBUFFER                 0x00000001L // Z-buffer 
#define LGD3DF_WBUFFER                 0x00000004L // W-buffer 
#define LGD3DF_DEPTH_BUFFER_REQUIRED   0x00000008L // the 
   // selected (Z_ or W-) depth buffer REQUIRED!
   //fog:
#define LGD3DF_TABLE_FOG               0x00000010L // table based pixel fog
#define LGD3DF_VERTEX_FOG              0x00000020L 
   
   //dithering
#define LGD3DF_DITHER                  0x00000040L // use dithering 
   
   //antialiasing
#define LGD3DF_ANTIALIAS				   0x00000080L // use (sort independent) antialiasing 
   
#define LGD3DF_MULTI_TEXTURING         0x00000100L // we support ONLY two sets of textures and
   // and texture coordinates
   
#define LGD3DF_MODULATEALPHA			   0x00000200L // we want to use modulate alpha for single texture mode
#define LGD3DF_BLENDDIFFUSE				0x00000400L // we want to use blend diffuse for single texture mode
   
#define LGD3DF_MULTITEXTURE_COLOR		0x00000800L // we want to use color light maps for single or multi texture mode
#define LGD3DF_MULTITEXTURE_ALPHA		0x00001000L // we want to use alpha light maps for single or multi texture mode
   
#define LGD3DF_DO_WINDOWED             0x00002000L
   
#define LGD3DF_MT_BLENDDIFFUSE         0x00004000L // we want to use alpha light maps for single or multi texture mode
   
   // Supported capabilities: (returned by the enumeration)
   
   //depth buffer
#define LGD3DF_CAN_DO_ZBUFFER				0x00010000L
#define LGD3DF_CAN_DO_WBUFFER				0x00040000L // W-buffer 
   //fog:
#define LGD3DF_CAN_DO_TABLE_FOG			0x00080000L // table based pixel fog
#define LGD3DF_CAN_DO_VERTEX_FOG			0x00100000L // vertex fog
   //dithering
#define LGD3DF_CAN_DO_DITHER				0x00200000L // can dither
#define LGD3DF_CAN_DO_ANTIALIAS			0x00400000L // can use (sort independent) antialiasing 
   
#define LGD3DF_CAN_DO_SINGLE_PASS_MT	0x02000000L // we can do single pass double texturing
#define LGD3DF_CAN_DO_WINDOWED         0x04000000L // we can play the game in lil' window
   
  // typedef struct ILGSurface ILGSurface;
   
   typedef struct _D3DDeviceDesc DevDesc;
   
   typedef struct lgd3ds_device_info {
      GUID         device_guid;
      GUID*        p_ddraw_guid;
      DevDesc*     device_desc;
      short*       supported_modes; // -1 terminated list 
      char*        p_ddraw_desc;
      ulong        flags;
   } lgd3ds_device_info;
   
   
   /// lgd3ds_device_info flags passed to the libray
   /// or returned by the enumeration.  
   
   extern int lgd3d_enumerate_devices_capable_of( ulong flags );
    //ToDo
   extern int lgd3d_enumerate_devices(void);
   //ToDo
   extern lgd3ds_device_info *lgd3d_get_device_info(int device);
   
   
   // pre-initiazation calls
 //  extern void lgd3d_texture_set_RGB(bool is_RGB);
#define lgd3d_texture_set_RGB( b ) COMCall1( g_pIRenderG, UseRGBTextures, b )
   
  // extern BOOL lgd3d_init( lgd3ds_device_info *device_info );
  // use rgCreateD6RenderGFromDispdev(...) instead

   //typedef struct ILGSurface ILGSurface;
   

   //not used :
   //extern BOOL lgd3d_attach_to_lgsurface( ILGSurface* pILGSurface ); 
   
   extern void lgd3d_clean_render_surface( BOOL bDepthBuffToo );
   
   //extern void lgd3d_shutdown(void);
#define lgd3d_shutdown rgDestroyRenderG
   
   
   //extern void lgd3d_start_frame(int frame);  // frame count passed to texture manager
#define lgd3d_start_frame( frame ) COMCall1( g_pIRenderG, StartFrame, frame )
   
   
   //extern void lgd3d_end_frame(void);
#define lgd3d_end_frame() COMCall0( g_pIRenderG, EndFrame )
   
   
   //extern BOOL lgd3d_overlays_master_switch( BOOL bOverlaysOn );
#define lgd3d_overlays_master_switch( b ) COMCall1( g_pIRenderG, OverlaysMasterSwitch, b )
   
   //not used
   //extern void lgd3d_blit();
   
   //extern void lgd3d_clear(int color_index);
#define lgd3d_clear( n )  COMCall1( g_pIRGView, ClearWithColor, n )
   
   //extern void lgd3d_set_zwrite(BOOL zwrite);
#define lgd3d_set_zwrite( b ) COMCall1( g_pIRenderG, SetZWrite, b )

   extern void lgd3d_set_zcompare(BOOL bCompare);

   //not used
   //extern void lgd3d_zclear(void);

   //extern void lgd3d_set_znearfar(double znear, double zfar);
#define lgd3d_set_znearfar( d1, d2 ) COMCall2( g_pIRGView, SetNearFarValues, d1, d2 )
   
   //extern void lgd3d_get_znearfar(double znear, double zfar);
#define lgd3d_get_znearfar( pd1, pd2 ) COMCall2( g_pIRGView, GetNearFarValues, pd1, pd2 )
   
   // no ...... way
   //extern BOOL lgd3d_z_normal;
   
   
   //extern void lgd3d_clear_z_rect(int x0, int y0, int x1, int y1);
#define lgd3d_clear_z_rect( f1, f2, f3, f4 ) COMCall4( g_pIRGView, ClearDepthBuffer,f1, f2, f3, f4 )

   //extern void lgd3d_set_z(float z);    // z coord for flat (2d) polys
#define lgd3d_set_z( f ) COMCall1( g_pIRGView, Set2dZvalue, f )
   
   extern int lgd3d_get_depth_buffer_state( void );

   //extern int lgd3d_is_zwrite_on( void );
#define lgd3d_is_zwrite_on( ) COMCall0( g_pIRenderG, GetZWrite )

   extern int lgd3d_is_zcompare_on( void );
   
   //extern double lgd3d_set_zbias(double zbias);
#define lgd3d_set_zbias( d ) COMCall1( g_pIRGView, SetZBiasDR, d )

  
   // 0 <= nZbias <= 16
  // extern void lgd3d_push_zbias_i( int nZBias );
#define lgd3d_push_zbias_i( n ) COMCall1( g_pIRGView, SetZBias, n )

   //extern void lgd3d_pop_zbias( void );
#define lgd3d_pop_zbias() COMCall0( g_pIRGView, PopZBias )
   

   // "smooth"(i.e., linera or bilinear) or "nearest point"
   //extern BOOL lgd3d_set_shading( BOOL bSmoothShading ); 
#define lgd3d_set_shading( b ) COMCall1( g_pIRenderG, EnableSmoothShading, b )

   //extern BOOL lgd3d_is_smooth_shading_on( void );
#define lgd3d_is_smooth_shading_on() COMCall0( g_pIRenderG, IsSmoothShading )
   
   //extern int lgd3d_is_alpha_blending_on( void );
 #define lgd3d_is_alpha_blending_on( b ) COMCall0( g_pIRenderG, GetAlphaBlendingOn )
   
   //extern void lgd3d_set_alpha(float alpha);             // 0.0 <= alpha <= 1.0
#define lgd3d_set_alpha( f ) COMCall1( g_pIRenderG, SetConstAlpha_F, f )
   
   //extern void lgd3d_set_blend(BOOL do_blend);
#define lgd3d_set_blend( b ) COMCall1( g_pIRenderG, SetAlphaBlendingOn, b )

   // belongs to shaders
   //extern void lgd3d_blend_normal(void);
   
  // extern void lgd3d_blend_multiply(int blend_mode); //from below
   /*
   enum {
      BLEND_DEST_ZERO=0,
         BLEND_SRC_ZERO=0,
         BLEND_SRC_ONE=1,
         BLEND_SRC_SRC=2,
         BLEND_SRC_DEST=3,
         BLEND_DEST_ONE=4,
         BLEND_DEST_SRC=8,
         BLEND_DEST_DEST=12
   };
   */
   
   //efects:
   // color range is 0..255
   // not used (?)
   //extern void lgd3d_set_chromakey(int red, int green, int blue);
   
   //extern void lgd3d_set_dithering( int bOn );
#define lgd3d_set_dithering( b ) COMCall1( g_pIRenderG, EnableDithering, b )
   
   //extern int lgd3d_is_dithering_on( void );
#define lgd3d_is_dithering_on( ) COMCall0( g_pIRenderG, IsDithering )
   
   
   // not implemented
   //extern void lgd3d_set_antialiasing( int bOn );
   //extern int lgd3d_is_antialiasing_on( void );
   
   //extern BOOL lgd3d_enable_specular( BOOL bUseIt );
#define lgd3d_enable_specular( b ) COMCall1( g_pIRenderG, EnableSpecular, b )
   
   //extern void lgd3d_set_fog_level(float fog_level);     // 0.0 <= fog_level <= 1.0
#define lgd3d_set_fog_level( f ) COMCall1( g_pIRenderG, SetFogLevel, f )
   
   //extern void lgd3d_set_fog_color(int r, int g, int b); // 0..255
#define lgd3d_set_fog_color( n1, n2, n3 ) COMCall3( g_pIRenderG, SetFogColor, n1, n2, n3 )

   //extern void lgd3d_set_fog_enable(BOOL enable);
#define lgd3d_set_fog_enable( b ) COMCall1( g_pIRenderG, EnableFog, b )

   //extern void lgd3d_set_fog_density(float density);
#define lgd3d_set_fog_density( f ) COMCall1( g_pIRenderG, SetFogDensity, f )

   //extern int lgd3d_is_fog_on( void );
#define lgd3d_is_fog_on( ) COMCall0( g_pIRenderG, IsFogOn )
   
   //extern void lgd3d_set_texture_level( int n );
#define lgd3d_set_texture_level( n ) COMCall1( g_pIRGTexMng, SetCurrentTextureLevel, n )
   
   // shader stuff
   //extern void lgd3d_get_texblending_modes( ulong* pulLevel0Mode, ulong* pulLevel1Mode );
   
   //texture manager
#define lgd3d_set_texture(bm) \
   do if (g_tmgr) g_tmgr->set_texture(bm); while (0)
   
#define lgd3d_load_texture(bm) \
   do if (g_tmgr) g_tmgr->load_texture(bm); while (0)
   
#define lgd3d_unload_texture(bm) \
   do if (g_tmgr) g_tmgr->unload_texture(bm); while (0)
   

   // procedural textures
   extern void lgd3d_hack_light(r3s_point *p, float r);
   extern void lgd3d_hack_light_extra(r3s_point *p, float r, grs_bitmap *bm);
   
   // texture wrapping
   //  TRUE == wrap the texture (texture is a torus), 
   //  FALSE == clamp the texture (texture is a closed rectangle)

   //extern BOOL lgd3d_get_texture_wrapping( DWORD dwLevel );
#define lgd3d_get_texture_wrapping( dw ) COMCall1( g_pIRenderG, GetWrapping, dw )

   //NOTE: return is void, not BOOL
   //extern BOOL lgd3d_set_texture_wrapping( DWORD dwLevel, BOOL bSetSmooth );
#define  lgd3d_set_texture_wrapping( dw, b ) COMCall2( g_pIRenderG, SetWrapping, dw, b )
   
   // palettes
   extern void lgd3d_set_pal(uint start, uint n, uchar *pal);
   extern void lgd3d_set_pal_slot(uint start, uint n, uchar *pal, int slot);
   extern void lgd3d_set_pal_slot_flags(uint start, uint n, uchar *pal, int slot, int flags);
   
   extern void lgd3d_set_alpha_pal(ushort *pal);

   // not used
   //extern void lgd3d_get_trans_texture_bitmask(grs_rgb_bitmask *bitmask);
   //extern void lgd3d_get_opaque_texture_bitmask(grs_rgb_bitmask *bitmask);
   //extern void lgd3d_get_alpha_texture_bitmask(grs_rgb_bitmask *bitmask);
   
   // not used 
   //extern void lgd3d_set_texture_clut(uchar *clut);
   //extern uchar *lgd3d_set_clut(uchar *clut);
   
   //extern void lgd3d_disable_palette(void);
#define lgd3d_disable_palette()  do{ if( g_pIRenderG )COMCall1( g_pIRenderG, UsePrimaryPalette, FALSE );}while(0)

   //extern void lgd3d_enable_palette(void);
#define lgd3d_enable_palette()  COMCall1( g_pIRenderG, UsePrimaryPalette, TRUE )
   
   
   
   //extern void lgd3d_set_offsets(int x, int y);
#define lgd3d_set_offsets( n1, n2 ) COMCall2( g_pIRGView, SetOffsets, n1, n2 )

   //extern void lgd3d_get_offsets(int *x, int *y);
#define lgd3d_get_offsets( pn1, pn2 ) COMCall2( g_pIRGView, GetOffsets, pn1, pn2 )
   
   
   // drawing:
   
   extern int lgd3d_draw_point(r3s_point *p);
   extern void lgd3d_draw_line(r3s_point *p0, r3s_point *p1);
   
   
   //Poligon Drowing states
   //NOTE: for now it does *NOT* affect indexed and multytextured polies
   /*
   typedef enum ePolyMode{
      kLgd3dPolyModeFillWTexture  = 0x00000001L,
         kLgd3dPolyModeFillWColor    = 0x00000002L,   
         kLgd3dPolyModeDrawEdges     = 0x00000004L,  // use color
         
         kLgd3dPolyModeDefault       = 0x00000001L, // normal, == kLgd3dPolyModeFillTexture
         kLgd3dPolyModeWireframe     = 0x00000004L, // == kLgd3dPolyModeDrawEdges
         kLgd3dPolyModeOutlineTex    = 0x00000005L, // == kLgd3dPolyModeFillWTexture + kLgd3dPolyModeDrawEdges
         kLgd3dPolyModeOutlineColor  = 0x00000006L, // == kLgd3dPolyModeFillWColor + kLgd3dPolyModeDrawEdges
         
         kLgd3dILLEGALPolyMode       = 0x00000000L
   } ePolyMode;
   
   extern BOOL lgd3d_set_poly_mode( ePolyMode eNewMode );
   extern ePolyMode lgd3d_get_poly_mode();
   */
   
   extern int lgd3d_trifan(int n, r3s_point **vpl);
   extern int lgd3d_lit_trifan(int n, r3s_point **vpl);
   extern int lgd3d_poly(int n, r3s_point **vpl);
   extern int lgd3d_spoly(int n, r3s_point **vpl);
   extern int lgd3d_g2upoly(int n, g2s_point **vpl);
   extern int lgd3d_g2poly(int n, g2s_point **vpl);
   extern int lgd3d_g2utrifan(int n, g2s_point **vpl);
   extern int lgd3d_g2trifan(int n, g2s_point **vpl);
   
   
   // r3d interface
   typedef int (*tLgd3dDrawPolyFunc)(int n, r3s_phandle *pl);
   
   extern tLgd3dDrawPolyFunc           lgd3d_draw_poly_func;
   
   extern void lgd3d_tmap_setup(grs_bitmap *bm);
   extern void lgd3d_lit_tmap_setup(grs_bitmap *bm);
   extern void lgd3d_rgblit_tmap_setup(grs_bitmap *bm);
   extern void lgd3d_rgbalit_tmap_setup(grs_bitmap *bm);
   extern void lgd3d_rgbafoglit_tmap_setup(grs_bitmap *bm); // rgba + fog 
   extern void lgd3d_diffspecular_tmap_setup(grs_bitmap *bm); // rgba + fog 
   extern void lgd3d_poly_setup(grs_bitmap *bm);
   extern void lgd3d_spoly_setup(grs_bitmap *bm);
   extern void lgd3d_rgb_poly_setup(grs_bitmap *bm);
   extern void lgd3d_rgba_poly_setup(grs_bitmap *bm);
   
   
   // indexed primitives:
   
   typedef int (*tLgd3dDrawPolyIndexedFunc)( int n, r3s_phandle *pl, r3ixs_info *info );
   
   extern tLgd3dDrawPolyIndexedFunc    lgd3d_draw_poly_indexed_func;
   
   typedef void (*fp_release_IP)( void );
   
   extern fp_release_IP                lgd3d_release_ip_func;
   
   extern int lgd3d_indexed_poly(int n, r3s_point **vpl, r3ixs_info *info);
   extern int lgd3d_indexed_spoly(int n, r3s_point **vpl, r3ixs_info *info);
   extern void lgd3d_rgblit_tmap_setup(grs_bitmap *bm);
   extern int lgd3d_lit_indexed_trifan(int n, r3s_point **vpl, r3ixs_info *info);
   
   extern void lgd3d_release_indexed_primitives( void );
   
   
   
   extern int lgd3d_TrifanMTD( int n, r3s_point **ppl, LGD3D_tex_coord **pptc );
   extern int lgd3d_LitTrifanMTD( int n, r3s_point **ppl, LGD3D_tex_coord **pptc );
   extern int lgd3d_RGBlitTrifanMTD( int n, r3s_point **ppl, LGD3D_tex_coord **pptc );
   
   extern int lgd3d_RGBAlitTrifanMTD( int n, r3s_point **ppl, LGD3D_tex_coord **pptc );
   extern int lgd3d_RGBAFoglitTrifanMTD( int n, r3s_point **ppl, LGD3D_tex_coord **pptc );
   extern int lgd3d_DiffuseSpecularMTD( int n, r3s_point **ppl, LGD3D_tex_coord **pptc );
   
   extern int lgd3d_g2UTrifanMTD( int n, g2s_point **vpl, LGD3D_tex_coord **vptc );
   extern int lgd3d_g2TrifanMTD( int n, g2s_point **vpl, LGD3D_tex_coord **vptc );
   
   
#ifdef __cplusplus
}
#endif

#endif //_RGLGD3D_H

