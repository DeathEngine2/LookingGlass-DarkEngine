/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  10/19/99 9:54:29 AM

  File:  rgMipTex.h

  Description:  


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgmiptex.h 1.1 1970/01/01 00:00:00 Zarko Exp $

#pragma once 

#ifndef _RGMIPTEX_H
#define _RGMIPTEX_H


//_____INCLUDES_AND_DEFINITIONS___________________________


//C++, C-+ or C+- only!
#ifdef __cplusplus

#ifndef _RGTYPES_H
#include <rgTypes.h>
#endif

#ifndef _RGTEXTYP_H
#include <rgTexTyp.h>
#endif

#define RG_TEX_RTI_PLAIN   1
#define RG_TEX_RTI_MIPMAP   2

//_______TYPEDEFS_________________________________________

struct grs_bitmap;
struct TRGTexture;
struct IRGTexMng;



////////////////////////////////
//
// cRGPlainTexture
//

class cRGPlainTexture : public TRGTexture {
   //data
   sRGImageInfo   m_sImageInfo;
   int            m_nTexHandle;
   DWORD          m_dwFlags;
   BYTE*          m_pucData;

public:
   // TRGTexture interface
   DWORD GetRTI() { return RG_TEX_RTI_PLAIN; }
   void MarkLoaded( DWORD dwTexHandle);
   void MarkUnloaded();
   void* MakeMemento();
   BOOL UseMemento( void* pvMemento, TRGTexture** ppTexture );
   void _SetFirstMipLevel(); 
   BOOL _SetNextMipLevel(); 
   DWORD GetProperties(); // RG_TP_... flags
   BOOL IsLoaded();
   int GetTextureHandle();
   DWORD GetNumMipLevels(); 
   DWORD GetNumImageBytes();
   BOOL GetImageInfo(sRGImageInfo* pInfoAddress);   
   DWORD GetPaletteIndex(){ return (DWORD)(-1);}
   BOOL GetImageData(sRGImageInfo* psTargetInfo,void* pvTargetData);

   cRGPlainTexture( sRGImageInfo* psImInfo );
   virtual ~cRGPlainTexture();
   
   BYTE* GetDataPtr() { return m_pucData; }
   
private:
   cRGPlainTexture();
   cRGPlainTexture( const cRGPlainTexture& );
   cRGPlainTexture& operator =( const cRGPlainTexture& );
};






///////////////////////////////////////
//
// cRGMipMapTexture
//


typedef void* (__stdcall *fpMemAllocator) ( DWORD dwSize );


class cRGMipMapTexture : public TRGTexture {
   
   enum {kUnloaded = -1, kMaxNoLevels = -1};
   
   // structure provided by the resource system
   BYTE*             m_pucAllocated;   // allocated data
   sRGTextureCore*   m_psTexCore;
   int               m_nTexHandle;     // a handle manipulated by the texture manager or kUnloaded(==-1) if not loaded
   DWORD             m_dwHighestLevel; // the highest level to be loaded and reported to IRGTexture interface
   DWORD             m_dwCurrentLevel; // a cursor for MipMap levels iteration 
   DWORD             m_dwCurrentOffset; //offset into m_pucData to the beggining of the current level
   BYTE*             m_pucData;        // current level's data
   
public :
   
   //c-tors

   // uses the data to allocate the image memory.  It sets psImageInfo->dwPitch.
   // To fill the memory  set the desired level and call GetDataPtr()
   cRGMipMapTexture( DWORD dwNumLevels, sRGImageInfo* psImageInfo );

   // pucData contains  only one mipmap level and all the members of 
   // psImageInfo are valid.  Downsample the image into until one of the dimensions is 1.  
   cRGMipMapTexture( sRGImageInfo* psImageInfo, BYTE* pucData, fpMemAllocator allocator = NULL );


   // fully created core
   cRGMipMapTexture( sRGTextureCore* psTCore );

   // copy c-tor
   cRGMipMapTexture( const cRGMipMapTexture& );

   //d-tor
   virtual ~cRGMipMapTexture();
   
   //setup
   
   // before the texture is loaded:
   BOOL SetHighestTexLevel( DWORD dwHighestLevel ); // fails iff tex is loaded

   // if the texture is loaded
   void RelodeIfHigherLOD( DWORD dwNewHighestLevel, IRGTexMng* pITexMex );
   
   DWORD GetHighestTexLevel() { return m_dwHighestLevel; }

   DWORD ComputeNumBytes( DWORD dwWidth, DWORD dwHeight, DWORD dwNoLevels ) const;

   BYTE* GetDataPtr() { return m_pucData + m_dwCurrentOffset; }


   // TRGTexture interface, see "rgTexTyp.h" 
   
   DWORD GetRTI() { return RG_TEX_RTI_MIPMAP; }

   void MarkLoaded(DWORD dwTexHandle );
   
   void MarkUnloaded()
   {
      m_nTexHandle = kUnloaded;
   }

   void* MakeMemento();
   BOOL UseMemento( void* pvMemento, TRGTexture** ppTexture );


   void _SetFirstMipLevel();
   BOOL _SetNextMipLevel(); 
   
   DWORD GetProperties()
   {
      return m_psTexCore->dwTypeFlags;
   }

   BOOL IsLoaded()
   {
      return ( kUnloaded != m_nTexHandle );
   }

   int GetTextureHandle()
   {
      return m_nTexHandle;
   }

   DWORD GetNumMipLevels() //"the number of levels" as exposed to the texture manager
   {
      return (m_psTexCore->dwNumMipMapLevels - m_dwHighestLevel);
   }

   DWORD GetNumImageBytes();
   
   BOOL GetImageInfo(sRGImageInfo* pInfoAddress );   

   DWORD GetPaletteIndex()
   {
      return 0xFFFFFFFF;
   }
   
   BOOL GetImageData(sRGImageInfo* psTargetInfo,void* pvTargetData);

   
   sRGTextureCore* GetTexCore() const { return m_psTexCore; } 

   DWORD GetSizeOfTexCore() const;

   cRGPlainTexture* CreatePlainTexture();


   //do-nots
private:
   cRGMipMapTexture();
   cRGMipMapTexture& operator =( const cRGMipMapTexture& );
};  








#endif // __cplusplus

#endif // _RGMIPTEX_H