/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  10/20/99 12:25:32 PM
  
    File:  rgTexTyp.h
    
      Description: TRGTexture 
      
        
=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgtextyp.h 1.1 1970/01/01 00:00:00 Zarko Exp $

#pragma once 

#ifndef _RGTEXTYP_H
#define _RGTEXTYP_H

// C++ ***ONLY***
#ifdef __cplusplus


//_____INCLUDES_AND_DEFINITIONS___________________________

#ifndef _RGTYPES_H
#include <rgTypes.h>
#endif





#define RG_MAX_NO_TEXTURES    4096


#define RG_INVALID_HTEX 0xFFFFFFFFL

// texture properties
#define RG_TP_MIPMAP          0x00000001L
#define RG_TP_DYNAMIC         0x00000002L // will be locked often
#define RG_TP_STATIC          0x00000004L // will not be locked often
#define RG_TP_NOLOCK          0x00000008L // it will NEVER be locked 
#define RG_TP_ANIMATED        0x00000010L 
#define RG_TP_ALL_FLAGS       0x0000FFFFL // all flags


//_______TYPEDEFS_________________________________________



struct TRGTexture
{
   virtual ~TRGTexture(){} //overloaded d-tor needs to unload the texture
   
   // OPERATIONS
   
   // texture manger calls this method to put 
   // the texture into "loaded" state
   // and to pass texture handle
   virtual void MarkLoaded(
      /*[in]*/ DWORD dwTexHandle //texture "handle" 
      ) = 0;
   
   // "unload" the texture
   virtual void MarkUnloaded() = 0;
   

   // "memento" interface: safekeeping of the internal state
   // it is texture's responsability to delete memento

   // returns class specific data
   virtual void* MakeMemento() = 0;

   // uses memento to construct a texture with the same data
   // NOTE: the created texture is possibly a different object!
   virtual BOOL UseMemento( 
      /*[in]*/ void* pvMemento,        // created by "MakeMemento()"
      /*[out]*/TRGTexture** ppTexture  // (re)constructed texture
      ) = 0;

   // mip levels iteration (default is the top level)
   virtual void _SetFirstMipLevel() = 0; 
   virtual BOOL _SetNextMipLevel() = 0; 
   
   
   //ACCCESSORS
   virtual DWORD GetRTI() = 0;   // run time info
   virtual DWORD GetProperties() = 0; // RG_TP_... flags
   virtual BOOL IsLoaded() = 0;
   virtual int GetTextureHandle() = 0;
   virtual DWORD GetNumMipLevels() = 0;
   virtual DWORD GetNumImageBytes() = 0;
   
   // relative to the selected mip level:
   
   
   virtual BOOL GetImageInfo(
      /*[in]*/ sRGImageInfo* pInfoAddress // copies internal data to the 
      // specified address
      ) = 0;
   
   
   virtual DWORD GetPaletteIndex() = 0; //in bytes
   
   
   // Get the data in the requested format. 
   virtual BOOL GetImageData(
      /*[in]*/ sRGImageInfo* psTargetInfo,
      /*[in]*/ void* pvTargetData //address of the target memory
      ) = 0;
   
   // get the pointer to the (level) data
   virtual BYTE* GetDataPtr() = 0;
};


#endif // __cplusplus



#endif //_RGTEXTYP_H