/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  7/23/99 4:36:19 PM
  
    File:  RenderG.h
    
      Description: RenderGlass interface.  This component
      configures the other components
      
        
=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/renderg.h 1.4 1970/01/01 00:00:00 Zarko Exp $


#pragma once

#ifndef _RENDERG_H
#define _RENDERG_H


//_____INCLUDES_AND_DEFINITIONS___________________________

#ifndef __COMTOOLS_H
#include <comtools.h>
#endif

#ifndef _RGTYPES_H
#include <rgTypes.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif
   
   
   F_DECLARE_INTERFACE(IRenderG);
   
   
   typedef struct IRGCore IRGCore;
   typedef struct IRGDisplayCanvas IRGDisplayCanvas;
   
   typedef struct IRGShader IRGShader;
   typedef struct sRGShaderData sRGShaderData;
   
   typedef struct IRGObjFactory IRGObjFactory;
   
   typedef struct IRGTexMng IRGTexMng;
   typedef struct IRGView IRGView;
   
   //_______TYPEDEFS_________________________________________
   
#undef INTERFACE
#define INTERFACE IRenderG
   
   DECLARE_INTERFACE_(IRenderG, IUnknown)
   {
      DECLARE_UNKNOWN_PURE();
      
      
      //API specific
      STDMETHOD_(eRGGraphicAPI,GetGraphicAPIType) (THIS) PURE;
      STDMETHOD_(IRGCore*,GetCore) (THIS) PURE;
      
      
      // state of the library
      STDMETHOD_(eRGPhase,GetPhase) (THIS) PURE;
      
      STDMETHOD_(void,Destroy) (THIS) PURE;
      
      STDMETHOD (Activate) (THIS) PURE;
      
      STDMETHOD (Suspend) (THIS) PURE;
      
      STDMETHOD_(void, SetRenderingConfig) (THIS_ eRGConfig eNew) PURE;
      STDMETHOD_(eRGConfig, GetRenderingConfig) (THIS) PURE;
      
      STDMETHOD_(BOOL, CacheAlphaPolies) (THIS_ BOOL bCache) PURE;
      
      // 2d rendering target
      STDMETHOD (SetRenderingTarget) (
         THIS_
         /*[in]*/ IRGDisplayCanvas*  pTarget
         ) 
         PURE;
      
      STDMETHOD (GetRenderingTarget) (
         THIS_
         /*[out]*/IRGDisplayCanvas** ppTarget
         ) 
         PURE;
      
      STDMETHOD (InitializeFromCanvas) (
         THIS_
         /*[in]*/ IRGDisplayCanvas*  pTarget,
         /*[in]*/ int nDeviceNo,
         /*[in]*/ DWORD dwRequested,
         /*[in]*/ DWORD dwRequired
         ) 
         PURE;
      
      // return the caps set during an initialization call
      // like "InitializeFromCanvas"
      STDMETHOD_(DWORD,GetSetFlags) (THIS) PURE;
      
      STDMETHOD_(void,DeInitialize)(THIS) PURE;
      
      STDMETHOD_(void, StartFrame) (THIS_ int nFrameNo) PURE;
      
      STDMETHOD_(void, EndFrame) (THIS) PURE;
      
      STDMETHOD_(BOOL, GetInFrame) (THIS) PURE;

      STDMETHOD_(void, ForceDrawing) (THIS) PURE;
      
      STDMETHOD_(IRGObjFactory*,GetObjectFactory) (THIS) PURE;
      
      
      // SHADER HANDLER AND CONTROLLER
      
      // shaders are IRGShader implementations.  
      
      // the shader interface has two simultanteously selected shaders:
      // "default shader" and "multi stage" or "MS" shader, where stages
      // refers to texture stages.  The "default" shaders are "single stage" 
      // shaders, used for primitives with one set of texture coordinates. 
      // A default shader has to be chosen during the initialization from the pool
      // of the build in shaders.
      
      
      // NOTE: A shader can be attached, but not "detached".
      //       So the shader's handle returned is valid as 
      //       long as IRenderG object is not destroyed
      
      
      // handle shaders
      
      
      // aggreagate this shader
      // all the arguments must point to initialized memory
      // if shader'sconfiguration succeedes, pData will be filled 
      // with relevant data, otherwise: pData->dwHandle == RG_VOID_SHADER
      STDMETHOD (AttachShader) (
         THIS_
         /*[in]*/ IRGShader* pShader,  // your masterpeace, the shader
         /*[out]*/sRGShaderData* pData // address of structure that will be filled        
         )
         PURE;
      
      
      // copies data for the shader with this handle
      STDMETHOD (GetShaderData) (
         THIS_
         /*[in]*/ DWORD dwShaderHandle,   //should be a valid shader handle
         /*[out]*/sRGShaderData* pData    // address of client created object
         // that will contain copy of the 
         // shader's data after the call
         )
         PURE;
      
      
      //Selection:
      
      STDMETHOD_(void,SelectMSShader) (      
         THIS_
         /*[in]*/ DWORD dwShaderHandle // can be any valid shader handle
         )
         PURE;
      
      STDMETHOD_(void,SelectDefaultShader) (      
         THIS_
         /*[in]*/ DWORD dwShaderHandle // can be any valid shader handle
         )
         PURE;
      
      
      
      // choose between selected default and MS shaders
      STDMETHOD_(void,UseDefaultShader) (
         THIS_
         /*[in]*/ BOOL bDefault, // default or MS?
         /*[in]*/ DWORD dwPassNo // select the pass number
         )
         PURE;
      
      // fills all the structures pointed to by non-null arguments
      STDMETHOD (GetSelectedShaders) (
         THIS_
         /*[out]*/DWORD* pdwDefaultShaderSelection,
         /*[out]*/sRGShaderData* psDefaulShaderData,  // address of the structure to be filled
         // ignored if NULL
         /*[out]*/DWORD* pdwMSShaderSelection,
         /*[out]*/sRGShaderData* psMSShaderData       // address of the structure to be filled
         // ignored if NULL
         )
         PURE;
      
      
      // get the access too any shader
      STDMETHOD_(IRGShader*,GetShaderPtr) (
         THIS_
         /*[in]*/ DWORD dwShaderHandle // can be any valid shader handle
         )
         PURE;
      
      
      // push on stack the previously selected MS shader
      // and either use the default or MS shader.
      // if dwShaderHandle is not RG_VOID_SHADER, it is 
      // the new selected MS shader, even if bDefault is TRUE.
      // Marginal behavior: if dwShaderHandle is RG_VOID_SHADER
      // MS shader data are unchanged and the behavior is 
      // identical to  "UseDefaultShader" method
      STDMETHOD_(void,PushAndSelectShader) (      
         THIS_
         /*[in]*/ BOOL bDefault, // default or MS?
         /*[in]*/ DWORD dwShaderHandle, // selected MS (if not RG_VOID_SHADER)
         /*[in]*/ DWORD dwPassNo // select the pass number
         )
         PURE;
      
      // pops MS shader (does *not* force MS shader use)
      STDMETHOD_(void,PopShader) (THIS) PURE;
      
    
      

      // Alpha Blending States

      //   States:
      //       (flag) (Default: off) Global alpha on        // client controlls it
      //       (flag) Texture alpha on       // set when a texture needs alpha-blending
      //       (flag) Shader alpha on        // set/unset by the current shader
      //       (DWORD) (Default: 255)Constant alpha color   // in { 0 ... 255 } // applied to the primitives
     
      // NOTE: alpha blending is on iff any of these flags is set
      
      // Global-alpha-on control
      STDMETHOD_(void, SetAlphaBlendingOn) (
         THIS_ 
         /*[in]*/ BOOL bBlendingOn  //set global alpha flag
         ) 
         PURE;

      STDMETHOD_(BOOL, GetAlphaBlendingOn) (THIS) PURE;
         
      // set constant alpha color 
      STDMETHOD_(void, SetConstAlpha) (
         THIS_ 
         /*[in]*/ DWORD dwAlphaColor   // in { 0 ... 255 }
         ) 
         PURE; 

      STDMETHOD_(void, SetConstAlpha_F) (
         THIS_ 
         /*[in]*/ float fAlpha   // in the [ 0.0 , 1.0 ]
         ) 
         PURE; 

      // sets both global alpha flag and constant alpha color 
      STDMETHOD_(void, SetAlphaStates) (
         THIS_ 
         /*[in]*/ BOOL bBlendingOn,    // set global alpha flag
         /*[in]*/ DWORD dwAlphaColor   // in { 0 ... 255 }
         ) 
         PURE;
      
      // push and set the new alpha states
      STDMETHOD_(void, PushAndSetAlphaStates) (
         THIS_ 
         /*[in]*/ BOOL bBlendingOn,    // set global alpha flag
         /*[in]*/ DWORD dwAlphaColor   // in { 0 ... 255 }
         ) 
         PURE;
      
      // ... the float version
      STDMETHOD_(void, PushAndSetAlphaStates_F) (
         THIS_ 
         /*[in]*/ BOOL bBlendingOn, // set global alpha flag
         /*[in]*/ float fAlpha      // in the [ 0.0 , 1.0 ]
         ) 
         PURE;
      
      // the alpha states stack
      STDMETHOD_(void, PushAlphaStates) (THIS) PURE;
      STDMETHOD_(void, PopAlphaStates) (THIS) PURE;
     
      
      
      // Fog
      
      // Fog controll states are divided into two groups.  Each group 
      // has its own stack
      
      //  "Fog States" states:
      //       (BOOL)         (Default: off) fog on // master switch
      //       (eRGFogType)   (Default: kRGFTNoFog) fog mode;            // mode selection
      //       (DWORD)        (Default: 0) constant fog level   // set as a float and applied to primitives 
      //       (DWORD)        (Default: 0) fog color            // color of the fog
      
      // NOTE constant fog level is used with vertex fog

      // the fog switch
      STDMETHOD_(void, SetFogOn) (
         THIS_ 
         /*[in]*/ BOOL bFogOn
         ) 
         PURE;

      // fog switch accessor
      STDMETHOD_(BOOL, GetFogOn) (THIS) PURE;
      
      // sets the fog mode.  It fails if mode is
      // not supported
      STDMETHOD_(BOOL, SetFogMode) (
         THIS_ 
         /*[in]*/ eFogType eMode 
         ) 
         PURE;

      // fog mode accessor
      STDMETHOD_(eFogType, GetFogMode) (THIS) PURE;
      
      // set the constant fog level
      STDMETHOD_(void, SetFogLevel) (
         THIS_ 
         /*[in]*/ float fFogLevel // in [ 0.0 , 1.0 ] 0 --> no fog color; 1 -->fully fogged
         ) 
         PURE; 
      
      // set fog color 
      STDMETHOD_(void, SetFogColor) (
         THIS_ 
         /*[in]*/ int nRed,   // in {0,256}
         /*[in]*/ int nGreen, // in {0,256}
         /*[in]*/ int nBlue   // in {0,256}
         ) 
         PURE; 

      // fog states stack
      STDMETHOD_(void, PushFogStates) (THIS) PURE;
      STDMETHOD_(void, PopFogStates) (THIS) PURE;
      
      
      
      // "Fog Data"
      //    (float)  fog start (linar fog) xor fog density (exponential fog)
      //    (float)  fog end (linar fog)

      // exponential fog: 
      //                   set density
      STDMETHOD_(void, SetFogDensity) (
         THIS_ 
         /*[in]*/ float fFogDensity //  in [ 0.0 , 1.0 ]
         ) 
         PURE;
      
      // linear fog:
      //             set fog start
      STDMETHOD_(void, SetFogStart) (
         THIS_ 
         /*[in]*/ float fFogStart   //  in [ 0.0 , 1.0 ]
         ) 
         PURE;

      //             set fog end
      STDMETHOD_(void, SetFogEnd) (
         THIS_ 
         /*[in]*/ float fFogEnd  //  in [ 0.0 , 1.0 ]
         ) 
         PURE;
      
      // fog data stock
      STDMETHOD_(void, PushFogData) (THIS) PURE;
      STDMETHOD_(void, PopFogData) (THIS) PURE;
      

      //    Depth (or Z-)Buffer

      // Z-buffer controll states are divided into two groups.  Each group 
      // has its own stack
      
      //    "Z-buffer On"
      //       (BOOL)   the on/off switch

      // set the switch
      STDMETHOD_(void, SetZBufferOn) (
         THIS_ 
         /*[in]*/ BOOL bOn
         ) 
         PURE;

      // the switch accessor
      STDMETHOD_(BOOL, GetZBufferOn) (THIS) PURE;

      // push the curren and set the new value
      STDMETHOD_(void, PushAndSetZBufferOn) (
         THIS_ 
         /*[in]*/ BOOL bOn
         ) 
         PURE;

      // ZBuffer on statck
      STDMETHOD_(void, PushZBufferOn) (THIS) PURE;
      STDMETHOD_(void, PopZBufferOn) (THIS) PURE;
         

      //  ZBuffer Data:
      //    (BOOL)            (Default: FALSE) Z-buffer writes enabled
      //    (eRGCompareFunc)  (Default: kRGCompareAlways) Z-comparison function (condition)
      
      // set z-buffer writes switch
      STDMETHOD_(void, SetZWriteOn) (
         THIS_ 
         /*[in]*/ BOOL bZWriteOn
         ) 
         PURE;

      // the write switch accessor
      STDMETHOD_(BOOL, GetZWriteOn) (THIS) PURE;

      // set the comparison condition
      STDMETHOD_(void, SetZCompareFunc) (
         THIS_ 
         /*[in]*/ eRGCompareFunc eCFunc
         ) 
         PURE;
      
      // get the comparison function
      STDMETHOD_(eRGCompareFunc, GetZCompareFunc) (THIS) PURE;

      // push current z-buffer data and set the new 
      STDMETHOD_(void, PushAndSetZBufferData) (
         THIS_ 
         /*[in]*/ BOOL bZWriteOn, 
         /*[in]*/ eRGCompareFunc eCFunc
         ) 
         PURE;

      // Z-buffer data stack
      STDMETHOD_(void, PushZBufferData) (THIS) PURE;
      STDMETHOD_(void, PopZBufferData) (THIS) PURE;
      
      
      // Global Boolean States
      
      //    (flag)         (Default: on)   Smooth, "Gouraud" shading (on) or flat shading (off)
      //    (flag)         (Default: off)  dithering on/off ( for 16bit rendering depth )
      //    (flag)         (Default: off)  specular on/off 
      //    (eRGCullType)  (Default: kRGCullNone)  type of polygon culling
      


      // Smooth or flat shading
      STDMETHOD_(BOOL, SetSmoothShadingOn) (
         THIS_ 
        /*[in]*/ BOOL bSmoothOn
        ) 
        PURE;

      STDMETHOD_(BOOL, GetSmoothShadingOn) (THIS) PURE;

      // Dithering
      STDMETHOD_(BOOL, SetDitheringOn) (
         THIS_ 
         /*[in]*/ BOOL bDitheringOn
         ) 
         PURE;

      STDMETHOD_(BOOL, GetDitheringOn) (THIS) PURE;
      
      // Polygon Culling
      STDMETHOD_(void, SetCulling) (THIS_
         /*[in]*/ eRGCullType eCull
         ) 
         PURE;
      
      STDMETHOD_(eRGCullType, GetCulling) (THIS) PURE;
      
      // Specular Lighting
      STDMETHOD_(BOOL, SetSpecularOn) (
         THIS_ 
          /*[in]*/ BOOL bSpecularOn
          ) 
          PURE;

      STDMETHOD_(BOOL, GetSpecularOn) (THIS) PURE;
      
      
      // global Boolean states stack
      STDMETHOD_(void, PushBoolStates) (THIS) PURE;
      STDMETHOD_(void, PopBoolStates) (THIS) PURE;



      // Texture States

      // exposed data:
      //    (BOOL)      (Default: TRUE)  perspectively corect textures on
      
      // the following data is kept for each texture level (8 levels max)
      //    (BOOL)               (Default: TRUE)            wrapping (TRUE) or clamping (FALSE) the textures
      //    (eRGTexMagFilter)    (Default: kRGTMag_Linear)  tex magnification filter
      //    (eRGTexMinFilter)    (Default: kRGTMin_Linear)  tex minification filter
      //    (eRGTexMipMapFilter) (Default: kRGTMip_None)    tex mip-mapping filter
      
      //perspectively corect textures
      STDMETHOD_(void, SetPCTexturesOn) (
         THIS_ 
         /*[in]*/ BOOL bOn
         ) 
         PURE;

      STDMETHOD_(BOOL, GetPCTexturesOn) (THIS) PURE;
      
      // wrapping or clamp
      STDMETHOD_(void, SetLevelWrappingOn) (
         THIS_ 
         /*[in]*/ DWORD dwLevel, //to which level
         /*[in]*/ BOOL bWrapOn   // or clamp, if FALSE
         ) 
         PURE;

      STDMETHOD_(BOOL, GetLevelWrappingOn) (
         THIS_ 
         /*[in]*/ DWORD dwLevel
         ) 
         PURE;
      
      // texture magnification filter
      STDMETHOD_(void, SetLevelMagnificationTexFilter) (
         THIS_ 
         /*[in]*/ DWORD dwLevel, //to which level
         /*[in]*/ eRGTexMagFilter eFilter
         ) 
         PURE;

      STDMETHOD_(eRGTexMagFilter, GetLevelMagnificationTexFilter) ( 
         THIS_ 
         /*[in]*/ DWORD dwLevel
         ) 
         PURE;
      
       // texture minification filter
      STDMETHOD_(void, SetLevelMinificationTexFilter) (
         THIS_ 
         /*[in]*/ DWORD dwLevel, //to which level
         /*[in]*/ eRGTexMinFilter eFilter
         ) 
         PURE;

      STDMETHOD_(eRGTexMinFilter, GetLevelMinificationTexFilter) ( 
         THIS_ 
         /*[in]*/ DWORD dwLevel
         ) 
         PURE;
      
      // Mip mapping filter
      STDMETHOD_(void, SetLevelMipMappingTexFilter) (
         THIS_ 
         /*[in]*/ DWORD dwLevel, //to which level
         /*[in]*/ eRGTexMipMapFilter eFilter
         ) 
         PURE;

      STDMETHOD_(eRGTexMipMapFilter, GetLevelMipMappingTexFilter) ( 
         THIS_ 
         /*[in]*/ DWORD dwLevel
         ) 
         PURE;
      
      // texture states stack
      STDMETHOD_(void, PushTextureStates) (THIS) PURE;
      STDMETHOD_(void, PopTextureStates ) (THIS) PURE;



      STDMETHOD_(BOOL, OverlaysMasterSwitch) (THIS_ BOOL bOverlaysOn) PURE;
      
      STDMETHOD_(void, UseRGBTextures) (THIS_ BOOL bUseRGB) PURE;
      STDMETHOD_(BOOL, AreTexturesRGB) (THIS) PURE;
      
      STDMETHOD_(void, UsePrimaryPalette) (THIS_ BOOL bPalOn) PURE;
   };
   
   
   //______EXPORTED_DATA_____________________________________
   
   typedef struct IRGFontSys IRGFontSys;
   
   // the main library interface
   extern IRenderG*     g_pIRenderG;
   extern IRGTexMng*    g_pIRGTexMng;
   extern IRGView*      g_pIRGView;
   extern IRGFontSys*   g_pIRGFontSys;
   
   
   // Genesis:
   
   // 1) Create an interface object for the selected API,
   //    get IRGObjFactory object to create API specific
   //    rendering target and call "InitializeFromCanvas"
   //    to fully configure the rendering
   
   // Implements "IRenderG" object.  The crated object is
   // accessible via global pointer "g_pIRenderG" or
   // *ppIRenderG. Use NULL for ppIRenderG if *ppIRenderG
   // is not required. Creates IRGObjFactory subcomponent that
   // can be obtained with QueryInterface.
   
   
   
   
   
   extern IRGView* CreateD3DView();
   
   extern void rgDestroyRenderG();
   
   extern HRESULT rgCreateRenderG( 
      /*[in]*/ eRGGraphicAPI eType, //sets the API for all subcomponents
      /*[out]*/ IRenderG** ppIRenderG //set to NULL if not needed
      );
   
   
   // 2) Use API-specific canvas and configure RenderG to render 3d to it.
   
   // implement all the rg interfaces.  The interfaces are
   // accessible through QueryInterface
   extern HRESULT rgCreateRenderGFromCanvas( 
      IRGDisplayCanvas* pIRenderTarget, 
      eRGGraphicAPI eType,
      int nSelectedDevice,
      DWORD dwRequestedFlags,
      DWORD dwRequiredFlags
      );
   
   
   extern HRESULT rgCreateD6RenderGFromDispdev(  
      int nSelectedDevice,
      DWORD dwRequestedFlags,
      DWORD dwRequiredFlags
      );
   
   //built in shaders
   
   extern sRGShaderData  g_sShadModulate;
   extern sRGShaderData  g_sShadModulateAlpha;
   extern sRGShaderData  g_sShadMultitexColor;
   
#ifdef __cplusplus
   }
#endif
   
#endif //_RENDERG_H