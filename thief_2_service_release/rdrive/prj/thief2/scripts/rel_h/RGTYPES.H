/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  7/26/99 11:47:21 AM

  File:  rgTypes.h

  Description:  C-structures and constants used by RenderG


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgtypes.h 1.5 1970/01/01 00:00:00 Zarko Exp $

#pragma once

#ifndef _RGTYPES_H
#define _RGTYPES_H


//_____INCLUDES_AND_DEFINITIONS___________________________


//__Capabilities flags______

// This flags are API independent. 
// They are used both by the enumeration to signal
// availability and are passed to the initialization
// by the client

#define RG_CAPS_HARDWARE            0x00000001L //hardware accealration
#define RG_CAPS_PRIMARY             0x00000002L // "primary" device (as opposed to seconadary monitor or 3d-only)
                                    
#define RG_CAPS_WINDOWED            0x00000004L // not "full-screen"
#define RG_CAPS_32BIT_DISPLAY       0x00000008L // 32bit depth of the display
                                    
#define RG_CAPS_DEPTH_BUFFER        0x00000010L // using a depth buffer
#define RG_CAPS_W_BUFFER            0x00000020L // using W-buffer
#define RG_CAPS_STENCIL_BUFFER      0x00000040L // using stancil buffer
                                    
#define RG_CAPS_FOG_TABLE           0x00000080L // table(pixel) fog
#define RG_CAPS_FOG_LINEAR          0x00000100L // linear fog calculations used
#define RG_CAPS_FOG_VERTEX          0x00000200L // vertex fog used
                                    
#define RG_CAPS_DITHER              0x00000400L // use dithering (16bit-depth only)
#define RG_CAPS_NOSORT_ANTIALIAS    0x00000800L // NOT IMPLEMENTED
                                    
#define RG_CAPS_MULTITEXTURE        0x00001000L //  single pass multitexturing
                                    
#define RG_CAPS_STATE_SORTED        0x00002000L // sort all polygons by state, "full state sort"
#define RG_CAPS_ALPHA_SORTED        0x00004000L // sort all poligons that use alpha blending

#define RG_CAPS_BUMP_ENV            0x00008000L // NOT IMPLEMENTED YET

#define RG_CAPS_SH_MODULATE         0x00010000L // DX5 "MODULATE" shader
#define RG_CAPS_SH_MODULATEALPHA    0x00020000L // DX5 "MODULATEALPHA", to set as default needs to be in required flags 
#define RG_CAPS_SH_MULTITEX_COLOR   0x00040000L

#define RG_CAPS_W_FOG               0x00080000L // using W for distance calculations in fog
#define RG_CAPS_Z_FOG               0x00100000L // using Z for distance calculations in fog

#define RG_CAPS_NO_WARNINGS         0x00200000L // no warnings issued

// Configuration hints
// REQUIRED for interaction with the "legacy" code

#define RG_CH_DISPDEV_APP           0x01000000L // use Dispdev.lib as the source of the Display Canvas
#define RG_CH_R3D_APP               0x02000000L // use r3d.lib for primitives rendering
#define RG_CH_GRSBITMAP_APP         0x04000000L // support "legacy" grs-bitmap textures
#define RG_CH_USE_PAL_TEX           0x08000000L // use color LUTs
#define RG_CH_USE_MIPMAP_TEX        0x10000000L // DEPRICIATED
#define RG_CH_USE_MAX_TEX_PAGE      0x20000000L // use texture pages (for fonts and overlays)  of the maximal size, otherwise: 256 by 256
                                             



//_______TYPEDEFS_________________________________________


// recognised API types
// these are API types that RenderG recognizes


typedef enum eRGGraphicAPI {
   kRGDirectX_61        = 0, 
   kRGDirectX_70        = 1,
   kRGGlide_30          = 2,
   kRGOpenGL_11         = 3,
   kRGNoGrAPI           = 4,
   kRGGrAPINotSelected  = 0x7FFFFFFF
} eRGGraphicAPI;


// rendering configuration
// can be changed runtime
typedef enum eRGConfig {
   kRGConfSimple           = 0, 
   kRGConfBuffered         = 1,
   kRGConfBufferedShifted  = 2,
   kRGConfBufferedSorted   = 3,
   kRGConfCacheAll         = 4,
   kRGConfNoConfigs        = 5,
   kRGConfReinitialize     = 6,
   kRGConfigError          = 0x7FFFFFFFL
}eRGConfig;

// phase...but not PMS
typedef enum eRGPhase {
   kRGAPISelected    = 0,  // API object factory accessible
   kRGIsConfigured   = 1,  // all components are created and configured
   kRGSuspended      = 2,  // active data in system memory, but video memory resources are abandoned
   kRGIsActive       = 3,  // ready for rendering
   kRGStateError     = 0x7FFFFFFFL 
} eRGPhase;




typedef enum eRGBlendFact { // alias D3DBLEND
   kRGBF_Zero              = 1,
   kRGBF_One               = 2,
   kRGBF_SrcColor          = 3,
   kRGBF_InvSrcColor       = 4,
   kRGBF_SrcAlpha          = 5,
   kRGBF_InvSrcAlpha       = 6,
   kRGBF_DestAlpha         = 7,
   kRGBF_InvDestAlpha      = 8,
   kRGBF_DestColor         = 9,
   kRGBF_InvDestColor      = 10,
   kRGBF_SrcAlphaSat       = 11,
   kRGBF_BothSrcAlpha      = 12,
   kRGBF_BothInvSrcAlpha   = 13,
   kRGBF_force_dword       = 0x7fffffff, /* force 32-bit size enum */
} eRGBlendFact;


typedef enum eRGFogType 
{
   kRGFTNoFog                 = 0,
   kRGFTLinearTableFog        = 1, 
   kRGFTExponentialTableFog   = 2,
   kRGFTVertexFog             = 3,
   kRGFTNumberOfFogTypes      = 4,   
   kRGFTFogError              = 0x7FFFFFFFL
} eFogType;


typedef enum eRGCompareFunc { // coresponds 1 - 1 with "D3DCMPFUNC"
    kRGCompareNever          = 1,
    kRGCompareLess           = 2,
    kRGCompareEqual          = 3,
    kRGCompareLessEqual      = 4,
    kRGCompareGreater        = 5,
    kRGCompareNotEqual       = 6,
    kRGCompareGreaterEqual   = 7,
    kRGCompareAlways         = 8,
    kRGCompareError          = 0x7fffffff, /* force 32-bit size enum */
} eRGCompareFunc;


typedef enum eRGCullType { // 1-1 with "D3DCULL"
   kRGCullNone               = 1,
   kRGCullClockwise          = 2,
   kRGCullCounterclockwise   = 3, 
   kRGCullError              = 0x7FFFFFFFL
} eRGCullType;


typedef enum eRGTextureOp { // 1-1 with "D3DTEXTUREOP"
   
      // Control
      kRGTexOp_Disable    = 1,      // disables stage
      kRGTexOp_SelectArg1 = 2,      // the default
      kRGTexOp_SelectArg2 = 3,
      
      // Modulate
      kRGTexOp_Modulate   = 4,      // multiply args together
      kRGTexOp_Modulate2X = 5,      // multiply and  1 bit
      kRGTexOp_Modulate4X = 6,      // multiply and  2 bits
      
      // Add
      kRGTexOp_Add          =  7,   // add arguments together
      kRGTexOp_AddSigned    =  8,   // add with -0.5 bias
      kRGTexOp_AddSigned2X  =  9,   // as above but left  1 bit
      kRGTexOp_Subtract     = 10,   // Arg1 - Arg2, with no saturation
      kRGTexOp_AddSmooth    = 11,   // add 2 args, subtract product
      // Arg1 + Arg2 - Arg1*Arg2
      // = Arg1 + (1-Arg1)*Arg2
      
      // Linear alpha blend: Arg1*(Alpha) + Arg2*(1-Alpha)
      kRGTexOp_BlendDiffuseAlpha    = 12, // iterated alpha
      kRGTexOp_BlendTextureAlpha    = 13, // texture alpha
      kRGTexOp_BlendFactorAlpha     = 14, // alpha from D3DRENDERSTATE_TEXTUREFACTOR
      // Linear alpha blend with pre-multiplied arg1 input: Arg1 + Arg2*(1-Alpha)
      kRGTexOp_BlendTextureAlphaPM  = 15, // texture alpha
      kRGTexOp_BlendCurrentAlpha    = 16, // by alpha of current color
      
      // Specular mapping
      kRGTexOp_PreModulate            = 17,     // modulate with next texture before use
      kRGTexOp_ModulateAlpha_AddColor = 18,     // Arg1.RGB + Arg1.A*Arg2.RGB
      // ColorOP only
      kRGTexOp_ModulateColor_AddAlpha = 19,     // Arg1.RGB*Arg2.RGB + Arg1.A
      // ColorOP only
      kRGTexOp_ModulateInvAlpha_AddColor = 20,  // (1-Arg1.A)*Arg2.RGB + Arg1.RGB
      // ColorOP only
      kRGTexOp_ModulateInvColor_AddAlpha = 21,  // (1-Arg1.RGB)*Arg2.RGB + Arg1.A
      // ColorOP only
      
      // Bump mapping
      kRGTexOp_BumpEnvMap           = 22, // per pixel env map perturbation
      kRGTexOp_BumpEnvMapLuminance  = 23, // with luminance channel
      // This can do either diffuse or specular bump mapping with correct input.
      // Performs the function (Arg1.R*Arg2.R + Arg1.G*Arg2.G + Arg1.B*Arg2.B)
      // where each component has been scaled and offset to make it signed.
      // The result is replicated into all four (including alpha) channels.
      // This is a valid ColorOP only.
      kRGTexOp_DotProduct3          = 24,
      
      kRGTexOp_force_dword = 0x7fffffff,
} eRGTextureOp;

/*
 * Values for COLORARG1,2 and ALPHAARG1,2 texture blending operations
 * set in texture processing stage controls in D3DRENDERSTATE.
 */
#define RG_D3DTA_SELECTMASK        0x0000000f  // mask for arg selector
#define RG_D3DTA_DIFFUSE           0x00000000  // select diffuse color
#define RG_D3DTA_CURRENT           0x00000001  // select result of previous stage
#define RG_D3DTA_TEXTURE           0x00000002  // select texture color
#define RG_D3DTA_TFACTOR           0x00000003  // select RENDERSTATE_TEXTUREFACTOR
#define RG_D3DTA_SPECULAR          0x00000004  // select specular color
#define RG_D3DTA_COMPLEMENT        0x00000010  // take 1.0 - x
#define RG_D3DTA_ALPHAREPLICATE    0x00000020  // replicate alpha to color components


typedef struct sRGTexBlendArgs {
   eRGTextureOp        eColorOperation;
   DWORD               dwColorArg1;
   DWORD               dwColorArg2;
   eRGTextureOp        eAlphaOperation;
   DWORD               dwAlphaArg1;
   DWORD               dwAlphaArg2;
} sRGTexBlendArgs;




typedef enum eRGTexMagFilter { // coresponds 1 - 1 with "D3DTEXTUREMAGFILTER"
   kRGTMag_Point           = 1,    // nearest
   kRGTMag_Linear          = 2,    // linear interpolation
   kRGTMag_FlatCubic       = 3,    // cubic
   kRGTMag_GaussianCubic   = 4,   // different cubic kernel
   kRGTMag_Anisotropic     = 5,    //
   kRGTMag_force_dword     = 0x7fffffff,
} eRGTexMagFilter;

typedef enum eRGTexMinFilter { // coresponds 1 - 1 with "D3DTEXTUREMINFILTER"
   kRGTMin_Point           = 1,    // nearest
    kRGTMin_Linear         = 2,    // linear interpolation
    kRGTMin_Anisotropic    = 3,    //
    kRGTMin_force_dword    = 0x7fffffff,
} eRGTexMinFilter;

typedef enum eRGTexMipMapFilter { // coresponds 1 - 1 with "D3DTEXTUREMIPFILTER"
   kRGTMip_None            = 1,    // mipmapping disabled (use MAG filter)
   kRGTMip_Point           = 2,    // nearest
   kRGTMip_Linear          = 3,    // linear interpolation
   kRGTMip_force_dword     = 0x7fffffff,
} eRGTexMipMapFilter;


//_________________________


// supported texture formats
typedef enum eRGPixFormats 
{
   kRGpfPalettized         = 0, //losers only, please
   kRGpf0565               = 1,
   kRGpf0555               = 2,
   kRGpf0888               = 3,
   kRGpf1555               = 4,
   kRGpf4444               = 5,
   kRGpf8888               = 6,
   kRGpf88BumpDuDv         = 7,
   kRGpf565BumpLuminance   = 8,
   kRGpfDD1                = 9,
   kRGpfDD2                = 10,
   kRGNoPixFormats         = 11,
   kRGpfScreenRGB          = kRGNoPixFormats,
   kRGInvalidPF            = 0x7FFFFFFF
} eRGPixFormats;


typedef struct sARGBbitmask {  
   DWORD   dwRed;
   DWORD   dwGreen;
   DWORD   dwBlue;
   DWORD   dwAlpha;
} sARGBbitmask;



typedef struct sRGImageInfo {
   DWORD          dwWidth;    //in pixels
   DWORD          dwHeight;   //in pixels
   DWORD          dwPitch;    //in bytes 
   eRGPixFormats  eFormat;
}sRGImageInfo;


typedef struct sRGTextureCore {
   sRGImageInfo   sImageInfo;
   void*          pvOuter;
   DWORD          dwTypeFlags; //type + RTI 
   DWORD          dwNumMipMapLevels;
   DWORD          dwLUTIndex;
} sRGTextureCore;




/////////////////////////////////////////

// clip codes (same as in dev2d.h)
#define CLIP_NONE    0
#define CLIP_LEFT    1
#define CLIP_TOP     2
#define CLIP_RIGHT   4
#define CLIP_BOT     8
#define CLIP_ALL     16

typedef struct sViewRect { // equal to D3DRECT
   union {
      long x1;
      long lX1;
   };
   union {
      long y1;
      long lY1;
   };
   union {
      long x2;
      long lX2;
   };
   union {
      long y2;
      long lY2;
   };
} sViewRect;

////////////////////

typedef struct sClipRect {
   float fX1;
   float fX2;
   float fY1;
   float fY2;
} sClipRect;



typedef struct {
    union {
        float fX0;
        float fU0;
    };
    union {
        float fX1;
        float fU1;
    };
    union {
        float fY0;
        float fV0;
    };
    union {
        float fY1;
        float fV1;
    };
} sFloatRect;


typedef struct {
   union {
      DWORD    dwX0;
      DWORD    dwU0;
   };
   union {
      DWORD    dwX1;
      DWORD    dwU1;
   };
   union {
      DWORD    dwY0;
      DWORD    dwV0;
   };
   union {
      DWORD    dwY1;
      DWORD    dwV1;
   };
   
} sDWORDRect;



//__Vertera___________________________

////////////////////

typedef struct _sTPosition {
   float    sx;
   float    sy;
   float    sz;
   float    rhw;
}sTPosition;

////////////////////

typedef struct _sLVertColor {
   DWORD    color;
   DWORD    specular;
}sLVertColor;

////////////////////

typedef struct _sTLPoint {
   sTPosition     pos;
   sLVertColor    vcol;
}sTLPoint;

typedef struct sTLVertex {
    float       sx;
    float       sy;
    float       sz;
    float       rhw;
    DWORD       color;
    DWORD       specular;
    float       tu;
    float       tv;
} sTLVertex;

///////////////////////

typedef struct sTLVertex2T {
    float       sx;
    float       sy;
    float       sz;
    float       rhw;
    DWORD       color;
    DWORD       specular;
    float       tu;
    float       tv;
    float       tu2;
    float       tv2;   
} sTLVertex2T;

////////////////////


typedef enum eRGPrimTypes { // 1 - 1 wth "D3DPRIMITIVETYPE"
    kRGPT_PointList     = 1,
    kRGPT_LineList      = 2,
    kRGPT_LineStrip     = 3,
    kRGPT_TriangleList  = 4,
    kRGPT_TriangleStrip = 5,
    kRGPT_TriangleFan   = 6,
    kRGPT_force_dword   = 0x7fffffff, /* force 32-bit size enum */
} eRGPrimTypes;



enum ePrimType {
   kPoint            = 0,
   kLineNOTex        = 1,
   kLine             = 2,
   kPolyNOTex        = 3,
   kPolyOneTexLev    = 4,
   kNoSimplePrimTyes = 5,
   kPolyTwoTexLev    = 5,
   kPolyIndOneLev    = 6,
   kPolyIndOLNOTex   = 7,
   kNoPrimTypes      = 8,
   kPrimError        = 0x7FFFFFFFL
};

enum eRGVertexType {
   kRGVertType_TL          = 0,
   kRGVertType_TLind       = 1,
   kRGVertType_TL2T        = 2,
   kRGVertType_TL2Tind     = 3,
   kRGVertType_NoTypes     = 4,
   kRGVertType_force_dword = 0x7fffffff, /* force 32-bit size enum */
};


enum eVertBuffType {
   kVBpoints      = 0,
   kVBoneTex      = 1,
   kVBTwoTex      = 2,
   kVBAppIndexed  = 4,
   kNoVBTypes     = 5
};


// buffer clears
#define RG_BC_RENDER_BUFFER   0x00000001L // == D3DCLEAR_TARGET
#define RG_BC_DEPTH_BUFFER    0x00000002L // == D3DCLEAR_ZBUFFER
#define RG_BC_STENCIL_BUFFER  0x00000004L // == D3DCLEAR_STENCIL


//________Error_handling_______________________________

typedef enum eLanguage {
      kUSEnglish,
      kUK,
      kGerman,
      kFrench,
      kHrvatski,
      kNewEngland,
      kSwahili, 
      kKlingon
} eLanguage;  //Help!!!

extern void rgSetLanguage( eLanguage duh );

extern char* rgGetLastErrorString( void );


//__ERROR_CODES_______________________



#define RGEC_SUBSYS       3

// Errors

#define E_RG_UNINITIALIZED       MakeResult(kError, RGEC_SUBSYS, 1)

#define E_RG_APIUNSUPPORTED      MakeResult(kError, RGEC_SUBSYS, 2)

#define E_RG_INVALIDPARAMS       MakeResult(kError, RGEC_SUBSYS, 3)

#define E_RG_FEATURE_UNSUPPORTED MakeResult(kError, RGEC_SUBSYS, 4)

#define E_RG_INITFAILED          MakeResult(kError, RGEC_SUBSYS, 5)

#define E_RG_BITDEPTH            MakeResult(kError, RGEC_SUBSYS, 6)

// something was in a wrong state, phase or out for lunch
#define E_RG_UNSYNCH             MakeResult(kError, RGEC_SUBSYS, 7)

#define E_RG_MEMALLOC            MakeResult(kError, RGEC_SUBSYS, 8)

#define E_RG_INUSE               MakeResult(kError, RGEC_SUBSYS, 9)

// Warnings

#define S_RG_UNINITIALIZED       MakeResult(kSuccess, RGEC_SUBSYS, 1001)

#define S_RG_INVISIBLE           MakeResult(kSuccess, RGEC_SUBSYS, 1002)

#define S_RG_NONEED              MakeResult(kSuccess, RGEC_SUBSYS, 1003)





#endif //_RGTYPES_H