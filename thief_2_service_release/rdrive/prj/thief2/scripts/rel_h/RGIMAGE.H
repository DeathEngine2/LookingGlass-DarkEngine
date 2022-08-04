/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  10/29/99 11:27:07 AM

  File:  rgImage.h

  Description:  Images and textures format specific utilities


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgimage.h 1.1 1970/01/01 00:00:00 Zarko Exp $

#pragma once 

#ifndef _RGIMAGE_H
#define _RGIMAGE_H


#ifndef _RGTYPES_H
#include <rgTypes.h>
#endif

//_______TYPEDEFS_________________________________________

class cRGImaginer;

class cRGImageTranslator 
{
   //data
   cRGImaginer* m_pcImaginer;


      //singleton interface
public:
   static cRGImageTranslator* GetInstance();
private:
   static cRGImageTranslator*  s_pInstance;

   cRGImageTranslator();
   
public:  
   ~cRGImageTranslator(){}

   // interface
public:  

   BOOL Translate( 
      //destination
      BYTE* pucDst,
      sRGImageInfo* psDst,
      //source
      BYTE* pucSrc,
      sRGImageInfo* psSrc,
      BYTE* pucPalette = NULL
      );

   BOOL Downsample( 
      //destination
      BYTE* pucDst,
      DWORD dwDstPitch,
      //sRGImageInfo* psDst, is not needed
      //source
      BYTE* pucSrc,
      sRGImageInfo* psSrc
      );
   
   
   eRGPixFormats GetNextChoice(eRGPixFormats eFormat);
   
   DWORD GetNumBytes( eRGPixFormats eFormat);
   
   BOOL Extend24to32bits( BYTE* pucDst,
      DWORD dwDstPitch,
      BYTE* pucSrc,
      sRGImageInfo* psSrc
      );
   
   // takes a block from the source image and sets it into the 
   // destination.  
   // Format type field ("eFormat") from "psDst" is ignored
   BOOL ExtractBlock( 
      //destination
      BYTE* pucDst,
      sRGImageInfo* psDst,
      //source
      BYTE* pucSrc,
      sRGImageInfo* psSrc,
      sDWORDRect* pSrcRect
      );



 //do-nots
private:
   cRGImageTranslator& operator =( const cRGImageTranslator& );
   cRGImageTranslator( const cRGImageTranslator& );
};



#endif //_RGIMAGE_H