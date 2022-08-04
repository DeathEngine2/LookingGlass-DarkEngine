/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  7/25/99 9:31:11 AM

  File:  rgCanvas.h

  Description: Canvas interfaces  


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgcanvas.h 1.2 1970/01/01 00:00:00 Zarko Exp $

#pragma once

#ifndef _RGCANVAS_H
#define _RGCANVAS_H


//_____INCLUDES_AND_DEFINITIONS___________________________

#ifndef _RGTYPES_H
#include <rgTypes.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif
   
   F_DECLARE_INTERFACE(IRGCanvas);
   F_DECLARE_INTERFACE(IRGDisplayCanvas);
   
   //_______TYPEDEFS_________________________________________
   
   typedef enum eRGCLock {
      kCLockRead,
         kCLockWrite,
         kCLockReadWrite
   }eRGCLock;
   
   
   typedef enum eRGCState{
      kCStateUnlocked = 0,
         kCState3DRendering,
         kCState2DDrawing,
         kCStateBlitting
   }eRGCState;
   
   typedef enum eRGCType {
      kCTypeScreen,
         kCTypeSystemMem,
         kCTypeVideoMem
   } eRGCType;
   
   
   
#undef INTERFACE
#define INTERFACE IRGCanvas
   
   
   DECLARE_INTERFACE_(IRGCanvas, IUnknown)
   {
      // IUnknown with self-destruct
      DECLARE_UNKNOWN_PURE();
      
      // get the (exclusive) access to the data
      STDMETHOD (Lock) (
         THIS_
         /*[in]*/ eRGCLock eLockType,     // the kind of the requested access
         /*[out]*/void** ppvImageData,    // pointer to the image memory
         /*[out]*/sRGImageInfo* pLockInfo // the freshly updated info
         )
         PURE;
      
      // give up the exclusive access to the memory
      STDMETHOD (Unlock) (THIS) PURE;
      
      // data access
      STDMETHOD_(BOOL,GetImageInfo) (
         THIS_
         /*[in]*/ sRGImageInfo* pInfoAddress // copies internal data to the specified address
         ) 
         PURE;
      
      
      //get the states
      STDMETHOD_( eRGCState, GetCanvasState ) (THIS) PURE;
      STDMETHOD_( eRGCType, GetCanvasType ) (THIS) PURE;
      STDMETHOD_( eRGGraphicAPI, GetAPIType ) (THIS) PURE;
   };
   
   //_____________________________________________________
   
   
#undef INTERFACE
#define INTERFACE IRGDisplayCanvas
   
   DECLARE_INTERFACE_(IRGDisplayCanvas, IRGCanvas)
   {
      //happy flags
      enum{ kPrimary       = 0x00000001, // the main display, only one per RenderG instance
         kFullScreen       = 0x00000002,  //full screen + kPrimary
         kDoubleBuffer     = 0x00000004,
         kTripleBuffer     = 0x00000008,
         k32bits           = 0x00000010,
         kZBuffer          = 0x00000020
      };
      
      STDMETHOD_(DWORD, GetFlags) (THIS) PURE; // from above
      
      // data type is fixed for a given API
      STDMETHOD (GetAPIspecificData) (
         THIS_
         /*[out]*/void** ppvAPIdata 
         )
         PURE;
      
      // Adds a buffer to attach (example: a depth buffer )
      // API specific
      STDMETHOD (AttachBuffer) (
         THIS_
         /*[in]*/ int nFlags,    // saying what kind of buffer this is
         /*[in]*/ void* pvBuffer // buffer to attach
         )
         PURE;
      
      
      // Resize and/or move the canvas
      STDMETHOD (Reposition) (
         THIS_
         /*[in]*/ HWND hWnd,        //if relevant
         /*[in]*/ sDWORDRect* pRect // if relevant
         )
         PURE;
      
      // flip or appropriate operation (example: blit to screen)
      STDMETHOD (Flip) (THIS) PURE;
      
      // Clean the specified buffers.  Flags are:
      // RG_BC_RENDER_BUFFER,  RG_BC_DEPTH_BUFFER and RG_BC_STENCIL_BUFFER 
      STDMETHOD (CleanBuffers) (
         THIS_
         /*[in]*/    DWORD dwFlags
         ) 
         PURE;
   };
   
   
   
#ifdef __cplusplus
}
#endif


#endif //_RGCANVAS_H