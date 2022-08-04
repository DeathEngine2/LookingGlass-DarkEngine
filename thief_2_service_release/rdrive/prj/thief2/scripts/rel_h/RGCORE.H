/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  7/26/99 12:31:22 PM

  File:  rgCore.h

  Description:  Low lewel graphic interface, IRGCore

  READ CAREFULLY:  
         IRGCore should be used only inside shaders!
     Any other use of this interface by an application (the app)
     constitutes an explicit request by the app creator(s) for 
     Dr.Zarko Bizaca to be excluded from all of the steps of
     the quality assurance and debbuging of the app.
     To apply for an exception from the rule above, an adminstrative
     processing fee in the amount of 10,000 US dollars is required.
     
=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgcore.h 1.3 1970/01/01 00:00:00 Zarko Exp $

#pragma once

#ifndef _RGCORE_H
#define _RGCORE_H

#ifdef __cplusplus


//_____INCLUDES_AND_DEFINITIONS___________________________


#ifndef _RGTYPES_H
#include <rgTypes.h>
#endif


struct IRGDisplayCanvas;

F_DECLARE_INTERFACE(IRGCore);

//_______TYPEDEFS_________________________________________

#undef INTERFACE
#define INTERFACE IRGCore


DECLARE_INTERFACE_(IRGCore, IUnknown)
{
   DECLARE_UNKNOWN_PURE();
   
   STDMETHOD_(eRGGraphicAPI,GetGraphicAPIType) (THIS) PURE;
   
   // 2d rendering target
   STDMETHOD (SetRenderingTarget) (
      THIS_
      /*[in]*/ IRGDisplayCanvas*  pTarget
      ) PURE;

   STDMETHOD (GetRenderingTarget) (
      THIS_
      /*[out]*/IRGDisplayCanvas** ppTarget
      ) PURE;

   STDMETHOD (InitializeFromCanvas) (
      THIS_
      /*[in]*/ IRGDisplayCanvas* pTarget,
      /*[in]*/ int nDeviceNo,
      /*[in]*/ DWORD dwRequested,
      /*[in]*/ DWORD dwRequired
      ) 
      PURE;
      


   STDMETHOD (CreateAPIVieport)(
      THIS_
      /*[in]*/ sViewRect* psRect, 
      /*[in]*/ DWORD dwFlags 
      )
      PURE;

   STDMETHOD_(void,DeleteAPIViewport) (THIS) PURE;

   STDMETHOD_(void,StartScene)(THIS) PURE;
   STDMETHOD_(void,EndScene)(THIS) PURE;

   // API specific setup (ex.: for W-buffer, fog)
   STDMETHOD_(void,SetNearFarRange)(THIS_ float fNear, float fFar ) PURE;
   
   STDMETHOD_(void,AlphaBlendingSwitch) (THIS_ BOOL bOn) PURE;
   
   STDMETHOD_(void,SetBlendingFactors) ( THIS_
      eRGBlendFact    eSrcAlpha,
      eRGBlendFact    eDstAlpha) PURE;
   
   STDMETHOD_(void,ToggleFog)( THIS_ BOOL bOn ) PURE;
   STDMETHOD_(void,SetFogMode)( THIS_ eRGFogType eFogType ) PURE;
   STDMETHOD_(void,SetFogColor)( THIS_ DWORD dwColor ) PURE;
   STDMETHOD_(void,SetFogData)( 
      THIS_
      /*[in]*/ eRGFogType eFogType,
      /*[in]*/ float fStartOrDensity,
      /*[in]*/ float fEnd 
      ) 
      PURE;
   
   STDMETHOD_(void,ClearBuffers)( 
      THIS_ 
      /*[in]*/ sViewRect* pRect,    // rectangle to clean
      /*[in]*/ DWORD dwBufferFlags, // RG_BC_RENDER_BUFFER/RG_BC_DEPTH_BUFFER/RG_BC_STENCIL_BUFFER
      /*[in]*/ DWORD dwARGBcolor,   // 32-bit color to clean the render buffer
      /*[in]*/ float rZ,            // walue for the Z-buffer
      /*[in]*/ DWORD dwStencil      // value to put in the stencil buffer
      ) 
      PURE;
   
   
   STDMETHOD_(BOOL,GetUsingDepthBuffer) (THIS) PURE;

   STDMETHOD_(void,EnableDepthBuffer) (THIS_ BOOL bUseIt) PURE;
   STDMETHOD_(void,EnableDepthBufferWrites) (THIS_ BOOL bOn) PURE;
   STDMETHOD_(void,SetZCompareFunct) (THIS_ eRGCompareFunc eZFunc) PURE;

   STDMETHOD_(void,ToggleGouraudShading) (THIS_ BOOL bOn) PURE;
   STDMETHOD_(void,ToggleDithering) (THIS_ BOOL bOn) PURE;
   STDMETHOD_(void,ToggleSpecular)  (THIS_ BOOL bOn) PURE;
   STDMETHOD_(void,SetCullMode) (THIS_ eRGCullType eType) PURE;
   

   STDMETHOD_(void,SetTextureData)( 
      THIS_
      /*[in]*/ DWORD dwLevel,                // texture level
      /*[in]*/ sRGTexBlendArgs* psBlendArgs  // data to be set
      )
      PURE;
      
   STDMETHOD_(void,SetTexCoordinateIndex) (
      THIS_
      /*[in]*/ DWORD dwLevel,       //associate with this level
      /*[in]*/ DWORD dwCoordIndex   //index to associate
      )
      PURE;
   STDMETHOD_(DWORD,GetNoTexLevels) (THIS) PURE;
   STDMETHOD_(void,SetPerspectiveCorr)( THIS_ BOOL bPC) PURE;
   STDMETHOD_(void,SetTexWrap) (THIS_ DWORD dwLevel, BOOL bWrap) PURE;
   STDMETHOD_(void,SetMagTexFilter) (THIS_ DWORD dwLevel, eRGTexMagFilter eFilter) PURE;
   STDMETHOD_(void,SetMinTexFilter) (THIS_ DWORD dwLevel, eRGTexMinFilter eFilter) PURE;
   STDMETHOD_(void,SetMipTexFilter) (THIS_ DWORD dwLevel, eRGTexMipMapFilter eFilter) PURE;

   
  STDMETHOD_(BOOL,ValidateCurrent) (THIS) PURE;
   

   
   STDMETHOD_(void,RenderPrimitive) (
      THIS_ 
      /*[in]*/ eRGVertexType eVertType,
      /*[in]*/ eRGPrimTypes ePrimType,
      /*[in]*/ void* pvVertices,
      /*[in]*/ DWORD dwNoVertices,
      /*[in]*/ void* pvIndices,
      /*[in]*/ DWORD dwNoIndices
      )
      PURE;


};



#endif //__cplusplus

#endif //_RGCORE_H