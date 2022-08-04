/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  8/17/99 2:14:45 PM

  File:  rgFactry.h

  Description:  A factory of API specific objects


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgfactry.h 1.2 1970/01/01 00:00:00 Zarko Exp $

#pragma once

#ifndef _RGFACTRY_H
#define _RGFACTRY_H



//_____INCLUDES_AND_DEFINITIONS___________________________


#ifdef __cplusplus
extern "C" {
#endif
   
   
   typedef struct IRGDisplayCanvas IRGDisplayCanvas;
   
   
   F_DECLARE_INTERFACE(IRGObjFactory);
   
   //_______TYPEDEFS_________________________________________
   
#undef INTERFACE
#define INTERFACE IRGObjFactory
   
   
   DECLARE_INTERFACE_(IRGObjFactory, IUnknown)
   {
      DECLARE_UNKNOWN_PURE();
      
      STDMETHOD (CreateDisplayCanvas) (
         THIS_
         /*[out]*/IRGDisplayCanvas** ppDC,
         /*[in]*/ int nDeviceIndex,
         /*[in]*/ DWORD dwWidth,
         /*[in]*/ DWORD dwHeight,
         /*[in]*/ int nFlags,
         /*[in]*/ HWND hWnd
         )
         PURE;
   };
   
   
   
#ifdef __cplusplus
}
#endif
   

#endif //_RGFACTRY_H