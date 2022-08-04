/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  8/16/99 10:08:25 AM

  File:  rgTexMng.h

  Description:  TRGTexture and IRGTexMng interfaces


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgtexmng.h 1.2 1970/01/01 00:00:00 Zarko Exp $

#pragma once

#ifndef _RGTEXMNG_H
#define _RGTEXMNG_H


//_____INCLUDES_AND_DEFINITIONS___________________________


#ifdef __cplusplus
extern "C" {
#endif
   
   
   F_DECLARE_INTERFACE(IRGTexMng); 
   F_DECLARE_INTERFACE(IRGTexDriver); 
   
   
   //_______TYPEDEFS_________________________________________
   
   typedef struct TRGTexture TRGTexture;
   
   //________________________________
   
   
#undef INTERFACE
#define INTERFACE IRGTexMng
   
   DECLARE_INTERFACE_(IRGTexMng, IUnknown)
   {
      DECLARE_UNKNOWN_PURE();
      
      STDMETHOD (Initialize) (
         THIS_
         /*[in]*/ IRGTexDriver* pTexDriver,  //API-specific texture driver
         /*[in]*/ TRGTexture* pDummyTex, // if not NULL, "the missing texture"
         /*[in]*/ void* pvTexFormatTree,     // Driver-specific handle tree
         /*[in]*/ void* pvTexController,     // Implementation specific tex controller
         /*[in]*/ DWORD dwNoTextureLevels,   // no of simultaneous texture levels
         /*[in]*/ DWORD dwInitalNoTextures,  // crate this many initialized texture containers  
         /*[in]*/ DWORD dwMaxNoTextures,     // absoulute maximum of texture containers
         /*[in]*/ DWORD dwFlags              // implementation specific
         )
         PURE;
      
      STDMETHOD_(void,Shutdown) (THIS) PURE;
      
      STDMETHOD_(void,SuspendAllTextures) (THIS) PURE;
      STDMETHOD_(void,ReloadAllTextures) (THIS) PURE;
      
      
      STDMETHOD_(void,StartFrame) (THIS_ int nFrameNo) PURE; 
      STDMETHOD_(void,EndFrame) (THIS) PURE;
      
      STDMETHOD_(void,SetCurrentTextureLevel) (THIS_ DWORD dwLevel) PURE;
      
      STDMETHOD_(void,LoadTexture) (THIS_ TRGTexture* pITex) PURE;
      STDMETHOD_(void,ReloadTexture) (THIS_ TRGTexture* pITex) PURE;
      
      STDMETHOD_(void,LoadTextureToLevel) (THIS_ DWORD dwLevel, TRGTexture* pITex) PURE;
      STDMETHOD_(void,ReloadTextureToLevel) (THIS_ DWORD dwLevel, TRGTexture* pITex) PURE;
      
      STDMETHOD_(void,UnloadTexture) (THIS_ TRGTexture* pITex) PURE;
      
      STDMETHOD_(void,SetTexture) (THIS_ TRGTexture* pITex) PURE;
      STDMETHOD_(void,SetTextureToLevel) (THIS_ DWORD dwLevel, TRGTexture* pITex) PURE;
      
      STDMETHOD_(void,CacheTexture) (THIS_ TRGTexture* pITex) PURE;
      STDMETHOD_(void,CacheCurrentTextures) (THIS) PURE;
      
      
      //stats
      STDMETHOD_(DWORD,GetTotalBytes) (THIS) PURE;    //  total lodaed textures
      STDMETHOD_(DWORD,GetBytesLoaded) (THIS) PURE;   //...this frame
      
      //constrains
      STDMETHOD_(BOOL,IsAGPSupported) (THIS) PURE;
      STDMETHOD_(DWORD,GetMaxTexSize) (THIS) PURE;
   };
   
#ifdef __cplusplus
}
#endif


#endif //_RGTEXMNG_H