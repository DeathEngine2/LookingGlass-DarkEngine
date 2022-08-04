/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  9/15/99 6:10:55 PM

  File:  rgView.h

  Description:  Drawing the primitives


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgview.h 1.2 1970/01/01 00:00:00 Zarko Exp $

#pragma once 

#ifndef _RGVIEW_H
#define _RGVIEW_H

//_____INCLUDES_AND_DEFINITIONS___________________________


#ifdef __cplusplus
extern "C" {
#endif
   
   typedef struct grs_bitmap grs_bitmap;
   
   
   F_DECLARE_INTERFACE(IRGView); 
   
   
   //_______TYPEDEFS_________________________________________
   
   struct IRenderG;
   struct TRGTexture;
   
#undef INTERFACE
#define INTERFACE IRGView
   
   DECLARE_INTERFACE_(IRGView, IUnknown)
   {
      DECLARE_UNKNOWN_PURE();
      
      // initializations
      STDMETHOD (InitializeForAPI) (THIS_ 
         IRenderG* pIRG //use flags to determine API
         ) PURE;
      
      // detach from API
      STDMETHOD_(void, DetachFromAPI) (THIS) PURE;
      
      STDMETHOD_(eRGGraphicAPI, GetGraphicAPI) (THIS) PURE;
      
      // View rectangle
      STDMETHOD_(void, SetViewRectangle) (THIS_ sViewRect* psVR) PURE;
      STDMETHOD_(void, GetViewRectangle) (THIS_ sViewRect* psVR) PURE;
      
      // Clip Rectangle
      STDMETHOD_(void, SetClipRectangle) (THIS_ sClipRect* psCR) PURE;
      STDMETHOD_(void, GetClipRectangle) (THIS_ sClipRect* psCR) PURE;
      // offsets
      STDMETHOD_(void, SetOffsets) (THIS_ int nXOffset, int nYOffset) PURE;
      STDMETHOD_(void, GetOffsets) (THIS_ int* pnXOffset, int* pnYOffset) PURE;
      
      STDMETHOD_(void, UseZNormalCalc) (THIS_ BOOL bUseIt) PURE;
      STDMETHOD_(void, UseZLinearCalc) (THIS_ BOOL bUseIt) PURE;
      
      // render buffer mng:
      //RG_BC_RENDER_BUFFER,RG_BC_DEPTH_BUFFER,RG_BC_STENCIL_BUFFER 
      STDMETHOD_(void, ClearBuffers) (THIS_ DWORD dwBufferFlags) PURE;
      
      STDMETHOD_(void, ClearDepthBuffer) (THIS_ int x1, int y1, int x2, int y2) PURE;
      STDMETHOD_(void, ClearWithColor) (THIS_ int nColor) PURE;
      
      STDMETHOD_(void, SetNearFarValues) (THIS_ double drNear, double drFar) PURE;
      STDMETHOD_(void, GetNearFarValues) (THIS_ double* pdrNear, double* pdrFar) PURE;
      STDMETHOD_(void, Set2dZvalue) (THIS_ double drZ2D) PURE;
      
      STDMETHOD_(void, SetZBias) (THIS_ int nZBias) PURE;
      STDMETHOD_(double, SetZBiasDR) (THIS_ double drZBias) PURE;
      STDMETHOD_(void, PushSetZBias) (THIS_ int nZBias) PURE;
      STDMETHOD_(void, PopZBias) (THIS) PURE;
      
      
      STDMETHOD_(void, DrawGlow1Default) (THIS_ sTLPoint* psCenter, float fRadius) PURE;
      STDMETHOD_(void, DrawGlow1) (THIS_ sTLPoint* psCenter, float fRadius, grs_bitmap* psBM) PURE;
      
      //primitives
      STDMETHOD_(void, DrawTLNoClip) (THIS_ enum ePrimType eType, DWORD dwNoVerts, sTLVertex* pVertices) PURE;
      
      STDMETHOD_(void, DrawLineTL) (THIS_ BOOL bTextured, sTLPoint* pStart, sTLPoint* pEnd, float fThicknes) PURE;
      // transformations:
   };
   
   
   
#ifdef __cplusplus
}
#endif



#endif //_RGVIEW_H