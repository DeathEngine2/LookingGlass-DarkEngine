/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  7/27/99 9:25:45 AM

  File:  rgCaps.h

  Description:  IRGGraphicCaps, interface for enumeration
               of the graphic devices


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgcaps.h 1.2 1970/01/01 00:00:00 Zarko Exp $

#pragma once

#ifndef _RGCAPS_H
#define _RGCAPS_H


//_____INCLUDES_AND_DEFINITIONS___________________________

#ifndef _RGTYPES_H
#include <rgTypes.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif
   
   
#define NO_DEV2D_MODES  128
   
   
   
   //Enumeration filter flags
   
#define RG_EF_USE_CONFIG_FILE    0x00000001L
#define RG_EF_ENUM_SOFTWARE      0x00000002L
#define RG_EF_USE_32BIT          0x00000004L
   
   
   F_DECLARE_INTERFACE(IRGGraphicCaps);
   F_DECLARE_INTERFACE(IRG_CPUID);
   
   //_______TYPEDEFS_________________________________________
   
   // "C"-structure containing some wierd stuff
   // it will change in the future
   typedef struct sRGDeviceData {
      union {
         GUID  DeviceGUID;
         char  caData2[16];
      };
      union {
         GUID* pDDrawGuid;
         void* pvData1;
      };
      DWORD    dwCaps;  // capabilities OR-ed "RG_CAPS_.."
      DWORD    dwTotalVideoMem;
      DWORD    dwTotalTexMem;
      DWORD    dwLocalTexMem;
      DWORD    dwNoTextureLevels; // max no of "current" textures
      int      nNoSupportedModes;
      short    naSupportedModes[NO_DEV2D_MODES];
   } sRGDeviceData;
   
   
   
   
   
#undef INTERFACE
#define INTERFACE IRGGraphicCaps
   
   DECLARE_INTERFACE_(IRGGraphicCaps, IUnknown)
   {
      DECLARE_UNKNOWN_PURE();
      
      // graphic API interface
      
      // SelectGraphicAPI returns TRUE if API enumeration component
      // was created.  FALSE indicate that the component was not created
      // OR that we do not support the API
      STDMETHOD_(BOOL,SelectGraphicAPI) (THIS_ eRGGraphicAPI eAPI) PURE;
      
      // currently selected API. All subsequent data\enumeration request
      // will be carried only for this API
      STDMETHOD_(eRGGraphicAPI,GetGraphicAPIType) (THIS) PURE;
      
      // sets the enumeration filter and returns the previos  value.  The set
      // filter will be used in subsequent calls to Enumerate, even if
      // the selected API was changed
      STDMETHOD_(DWORD,SetEnumerationFilter) (THIS_ DWORD dwFilter) PURE;
      
      
      // all the calls below are relative to the specified API.  If no API was 
      // selected the calls will return E_RG_UNINITIALIZED
      
      
      // enumerate the capabilities for the selected API, using the set enumeration
      // filter. Data for the specified API is saved until the next call.  Switching
      // API does NOT delete data for the previously enumerated API.
      STDMETHOD (Enumerate) (THIS) PURE;
      
      
      // "capabilities caps" interface (for the selected API)
      
      // Number of enumerated devices.  -1 means that the devices have not been
      // enumerated.
      // If RG_EF_ENUM_SOFTWARE has been passed in a
      // call to "SetEnumerationFilter" software devices were also enumerated.
      STDMETHOD_(int, GetNoDevices) (THIS) PURE;
      
      // gets the caps for the device, unless pdwCaps is NULL or no API was selected.
      // The caps are defined in "rgTypes.h"
      STDMETHOD (GetCapabilityFlags) (
         THIS_ 
         /*[in]*/ int nDeviceNo,
         /*[out]*/DWORD* pdwCaps
         ) 
         PURE;
      
      // returns pointers to device's name and the name of the driver. 
      // It is API specific as of the source of the returned strings.
      STDMETHOD (GetDeviceDescription) (
         THIS_
         /*[in]*/ int nDeviceNo,
         /*[out]*/char** pszDeviceName,
         /*[out]*/char** pszDeviceDriver
         )
         PURE;
      
      
      STDMETHOD (GetDeviceData) (
         THIS_
         /*[in]*/ int nDeviceNo, 
         /*[out]*/sRGDeviceData** ppsDevData
         )
         PURE;
      
      // Returns API-specific structure if applicable. 
      STDMETHOD (GetAPIspecificStruct) (
         THIS_
         /*[in]*/ int nDeviceNo, 
         /*[out]*/void** ppvStructure
         )
         PURE;
      
      // Get
      STDMETHOD (GetAPIspecificID) (
         THIS_
         /*[in]*/ int nDeviceNo,
         /*[out]*/void** ppvID
         )
         PURE;
   };
   
   
   //________________________________
   
   
#undef INTERFACE
#define INTERFACE IRG_CPUID
   
   DECLARE_INTERFACE_(IRG_CPUID, IUnknown)
   {
      DECLARE_UNKNOWN_PURE();
      
      STDMETHOD_(BOOL,CanDoMMX) (THIS) PURE;
      STDMETHOD_(BOOL,CanDoSIMD) (THIS) PURE;
      STDMETHOD_(BOOL,CanDo3DNow) (THIS) PURE;
      STDMETHOD_(BOOL,CanUseTSC) (THIS) PURE;
   };
   
   



   //______EXPORTED_DATA_____________________________________
   
   extern IRGGraphicCaps* g_pRGGraphicCaps;
   
   
   extern BOOL rgInitTheGraphicCaps( void );
   extern void rgEmptyTheGraphicCaps( void );
   
   
#ifdef __cplusplus
}
#endif


#endif //_RGCAPS_H