/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  8/16/99 10:16:50 AM

  File:  rgOver.h

  Description:  Overlay System


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgover.h 1.2 1970/01/01 00:00:00 Zarko Exp $

#pragma once

#ifndef _RGOVER_H
#define _RGOVER_H

#ifndef _RGMIPTEX_H
#include <rgMipTex.h>
#endif



// Overlay system

// There are two overlay interaces: IRGBillboard and IRGTexRectangle. 

// IRGBillboard contains an image that can of arbitrary dimensions. It is 3d equivalent
// of the surface blit. Displayed image can not be resized.
// IRGRectangle has a pointer to a texture and it can display it through the 
// current 3D rendering system. The displayed image can be resized
// Same methods are shared and so IRGOverlay provides a common base interface for both.



/*
    0 ---1
    | \  |
    |  \ |
    |   \|
    3----2

  */

typedef struct {
   int   nAlpha; //  in the interval [0,255]
   int   nRed;   //  in the interval [0,255]
   int   nGreen; //  in the interval [0,255]
   int   nBlue;  //  in the interval [0,255]
} sOverColor;


F_DECLARE_INTERFACE(IRGOverlay);
F_DECLARE_INTERFACE(IRGTexRectangle);
F_DECLARE_INTERFACE(IRGBillboard);
F_DECLARE_INTERFACE(IRGOverlaySys);



#undef INTERFACE
#define INTERFACE IRGOverlay;

DECLARE_INTERFACE_(IRGOverlay, IUnknown)
{
   DECLARE_UNKNOWN_PURE();
   
   // sets pointer to the OverlaySystem that contains
   // the overlay.   The old value is released and 
   // on the new value (if not NULL) AddRef is called
   STDMETHOD_(void,SetOverlaySysPtr) (
      THIS_ 
      /*[in]*/ IRGOverlaySys*    pIOuter //can be NULL
      )
      PURE;

   
   // color
    STDMETHOD_(void,SetColor ) (
      THIS_
      /*[in]*/ sOverColor* pColor
      )
      PURE;
   
   STDMETHOD_(void,GetColor) (
      THIS_
      /*[out]*/ sOverColor* pColorAddress
      )
      PURE;

   STDMETHOD (PrepareOverlay)(THIS) PURE;

   STDMETHOD (Draw)(THIS) PURE;
   
};



typedef enum eOverUnits {
   kOverUseImageSize,
   kOverUseScreenCoord,
   kOverUseDimsPercentage
};


#undef INTERFACE
#define INTERFACE IRGTexRectangle;

DECLARE_INTERFACE_(IRGTexRectangle, IRGOverlay)
{
   // There are 3 ways "sFloatRect"'s fields are interpreted:
   // 1) "kOverUseImageSize" (default)
   //    using the image dimensions in pixels.  Only upper left corner
   //    needs to be specified.  If used with texture rectangles
   //    size of a texel is equal to the size of a pixel.
   
   // 2) "kOverUseScreenCoord"
   //    Using screen coordinate in pixels. Both upper left and 
   //    lower right coorners needs to be specified.  Both bill-
   //    boards and texture rectangles are rescaled.
   
   // 3) "kOverUseDimsPercentage"
   //    In percentage of the screen dimensions ( 0.0f -- 100.0f)
   //    Internaly, dimensions are translated into pixels.   
   
   // sets the system ( 1, 2 or 3 from the comment above)
   // returns the previous version.  It affects only subsequent
   // transactions, so it can be safely used to retrive the set
   // state by a double call
   STDMETHOD_(eOverUnits, SetUnits) (
      THIS_
      /*[in]*/ eOverUnits  eNewUnits
      )
      PURE;

   // Position of the overlay. 
   
   // sets the position ( measures are in the selected eOverUnits)
   STDMETHOD_(void,SetPosition) (
      THIS_
      /*[in]*/ sFloatRect* pRectangle
      )
      PURE;

   // get the overlays  position
   // if kOverUseImageSize is selected, (fX1,fY1) is calculated
   // from the image/texture dimensions in pixels
   // If the overlay was not updated (with PrepareOverlay() ) 
   // the method will **fail**
   STDMETHOD_(BOOL,GetPosition) (
      THIS_
      /*[out]*/ sFloatRect* pRectAddress
      )
      PURE;
   
   
   
  // texture
   STDMETHOD_(void,SetTexture) (
      THIS_
      /*[in]*/ TRGTexture* pTex
      )
      PURE;

   STDMETHOD_(TRGTexture*,GetTexture) (THIS) PURE;

   //texture coordinates
    STDMETHOD_(void,SetTexCoordinates) (
      THIS_
      /*[in]*/ sFloatRect* pRectangle
      )
      PURE;
   
   STDMETHOD_(void,GetTexCoordinates) (
      THIS_
      /*[out]*/ sFloatRect* pRectAddress
      )
      PURE;
};





///////////////////////
// IRGBillboard
//
// the Marlboro Man stuff

// contains internally an image.  
// Image format may change during its existance, including the 
// pixel format.  Billboards are displayed through IRGBillboardHandler
// object onto which the billboard is attached 




#undef INTERFACE
#define INTERFACE IRGBillboard;

DECLARE_INTERFACE_(IRGBillboard, IRGOverlay)
{
   // sets the position ( measures are in pixels)
   STDMETHOD_(void,PositionULCorner) (
      THIS_
      /*[in]*/ float fUpperLeftX,
      /*[in]*/ float fUpperLeftY
      )
      PURE;
   
   // If the overlay was not updated (with PrepareOverlay() ) 
   // the method will **fail**
   STDMETHOD_(BOOL,GetPosition) (
      THIS_
      /*[out]*/ sFloatRect* pRectAddress
      )
      PURE;

   // recreate the visual representation
   // signaling that the image data has changed
   STDMETHOD_(void, MarkImageChanged) (THIS) PURE;

   // destroy the internal image
   STDMETHOD_(BOOL, ReleaseImage) (THIS) PURE;
   
   // create an image with specified properities
   STDMETHOD (CreateImage) (
      THIS_
      /*[in]*/ sRGImageInfo* pImInfo
      )
      PURE;
   
   // get a copy of the image info
   STDMETHOD_(BOOL,GetImageInfo) (
      THIS_
      /*[out]*/ sRGImageInfo* pInfoAddress // copies internal data to the specified address
      ) 
      PURE;
   
   // get a pointer into the image memory
   STDMETHOD_(BYTE*,GetImageData ) (THIS) PURE;   
};






#undef INTERFACE
#define INTERFACE IRGOverlaySys;

DECLARE_INTERFACE_(IRGOverlaySys, IUnknown)
{
   DECLARE_UNKNOWN_PURE();
   
   //IRGOverlay
   STDMETHOD_(BOOL,AddOvelay) (
      THIS_
      /*[in]*/ IRGOverlay* pIOverlay
      )
      PURE;

   STDMETHOD_(BOOL,RemoveOverlay) (
      THIS_
      /*[in]*/ IRGOverlay* pIOverlay
      )
      PURE;


    STDMETHOD_(BOOL,DrawOverlays) (THIS) PURE;

   // clipping rectangle
   // fiels are *allways* in pixels
   STDMETHOD_(BOOL,SetClippingRectangle) (
      THIS_
      /*[in]*/ sFloatRect* pRectangle
      )
      PURE;
   
   STDMETHOD_(BOOL,GetClippingRectangle) (
      THIS_
      /*[out]*/ sFloatRect* pRectAddress
      )
      PURE;

   STDMETHOD_(void,GetScreenSizes) (
      THIS_
      /*[out]*/float* prWidth,
      /*[out]*/float* prHeight
      )
      PURE;      
};



























/////////////////OLD//SYSTEM//////////////////////////////////////





//_____INCLUDES_AND_DEFINITIONS___________________________



F_DECLARE_INTERFACE(IRGOverlays); 

struct grs_bitmap;

//_______OVERLAYS_________________________________________


// TRANSLUCENT OVERLAYS ("alpha overlays" or aol)
// Overlays are displayed at the end of the frame.
//
// Overlays can be set and changed any time during the executions, and once set they are displayed every frame until
// explicitly unset or switched off, or untill rg goes bah-by (for example, 2d option screen pops up).
// Overlays are kept and displayed from an ordered list. The app only needs to keep a handle to an overlay.
//
// creating overlays:
// "rendg_aol_add" appends the end of the list and "rendg_aol_insert" inserts after the specified overlay.
// sRGOverlayInfo structure passed (as reference) to these functions doesn't need to exist after the call.  
//
// To restore overlay:
// After rg was closed and reinitalized or the overlay was removed: use "rendg_aol_add" or "rendg_aol_insert"
// (Note that the previously used handles have expired and you need to renew your driving licence.)
// After the overlay was switched off (with "rendg_aol_switch(handle, FALSE)") use "rendg_aol_switch(handle, TRUE)"
//
// NOTE: if you do something funky with rg frames you can turn ovelays on and off using
//      "BOOL rendg_overlays_master_switch(BOOL bOverlaysOn);" from lgd3d.h. However this function has no 
//      "magic rug feature", so you will get an access exception if you call this function 
//      and the lgd3d library does not exist. On other hand existance of overlays is not required.


typedef unsigned long HRGOVERLAY; //"handle" to an overlay



// sRGOverlayInfo.dwFlags specify which fields of the structure are usable
//
// DEFAULT: use only  fX0, fY0 and pBitmap
#define RGOI_UPPER_LEFT_CORNER       0x00000001L
#define RGOI_BITMAP                  0x00000002L
#define RGOI_ALPHA                   0x00000004L
#define RGOI_RGB                     0x00000008L
#define RGOI_LOWER_RIGHT_CORNER      0x00000010L
#define RGOI_TEXTURE_COORDINATES     0x00000020L

//NOTE: RGOI_UPPER_LEFT_CORNER and RGOI_BITMAP are assumed 
//      in the calls to "rendg_aol_add" and  "rendg_aol_insert".

typedef struct {
    DWORD           dwFlags; //I am using caps! HELP!!!
    grs_bitmap*     pBitmap;
    float       fX0;    // upper left corner
    float       fY0;    // upper left corner
    float       fX1;    // lower right corner 
    float       fY1;    // lower right corner 
    float   tu0;    // upper left corner texture coordinate  
    float   tv0;    // upper left corner texture coordinate
    float   tu1;    // lower right corner texture coordinate  
    float   tv1;    // lower right corner texture coordinate
    int         nAlpha; //  in the interval [0,255]
    int         nRed;   //  in the interval [0,255]
    int         nGreen; //  in the interval [0,255]
    int         nBlue;  //  in the interval [0,255]
} sRGOverlayInfo;


//////////////////////////////////////////////


#undef INTERFACE
#define INTERFACE IRGOverlays

DECLARE_INTERFACE_(IRGOverlays, IUnknown)
{
   DECLARE_UNKNOWN_PURE();
   
   // creation
   
   // return codes:  S_OK, S_RGOEC_INVISIBLE, E_RGOEC_ALLOCATION 
   STDMETHOD(AddAlphaOverlay) (THIS_ 
      /*[in]*/    sRGOverlayInfo* psOverInfo,  
      /*[out]*/   HRGOVERLAY* phOver
     ) PURE;
   
   // return codes:  S_OK, S_RGOEC_INVISIBLE, E_RGOEC_ALLOCATION, E_RGOEC_BAD_HANDLE
   STDMETHOD(InsertAlphaOverlay) (THIS_ 
      /*[in]*/    sRGOverlayInfo* psOverInfo, HRGOVERLAY hAfterMe,  
      /*[out]*/   HRGOVERLAY* phOver
     ) PURE;
   
   
   
   // death
   
   // return codes:  S_OK, E_RGOEC_BAD_HANDLE
   
   STDMETHOD(RemoveOverlay) (THIS_ HRGOVERLAY hOver) PURE; 
   
   STDMETHOD_(void, RemoveAllOverlays) (THIS) PURE;
   
   
   // switching on/off
   
   //returns the previous (ON/OFF) state of overlays
   //(DECLARED IN LGD3D.H:)     BOOL rendg_overlays_master_switch(BOOL bOverlaysOn);
   
   
   // return codes:  S_OK, E_RGOEC_BAD_HANDLE
   STDMETHOD (SwitchOverlay) (THIS_ HRGOVERLAY hOver, BOOL bOn) PURE; 
   
   
   // updating data
   
   // return codes:  S_OK, S_RGOEC_INVISIBLE, E_RGOEC_BAD_HANDLE
   
   // use the flags in psOverInfo to specify what to change. 
   // NOTE: Bitmap can NOT be changed with this method.
   STDMETHOD(UpdateAlphaOverlay) (THIS_ HRGOVERLAY hOver, sRGOverlayInfo* psOverInfo) PURE; 
   
   // to update bitmap data. Do NOT change anything else in the bitmap structure!
   // NOTE: while bitmap locked overlay will not be displayed. 
   STDMETHOD(LockAOLBitmapData) (THIS_ 
      /*[in]*/    HRGOVERLAY hOver,
      /*[out]*/   grs_bitmap** ppsBitmap 
    ) PURE;
   
   // it will reload the bitmap of the overlay
   STDMETHOD(UnlockAOLBitmapData) (THIS_  HRGOVERLAY hOver) PURE;
   
   STDMETHOD(SetAOLPosition) (THIS_ 
      HRGOVERLAY hOver, float fScreenX, float fScreenY) PURE;
   
   STDMETHOD(MoveAOL) (THIS_ HRGOVERLAY hOver, float fDeltaX, float fDeltaY) PURE;
   STDMETHOD(SetAOLColor) (THIS_ 
      HRGOVERLAY hOver, int nRed, int nGreen, int nBlue, int nAlpha) PURE;
   
   STDMETHOD(SetAOLAlpha) (THIS_ HRGOVERLAY hOver, int nAlpha) PURE;
   
   
   // clipping viewport
   
   // if psInRect == NULL the whole screen is the clipping rectangle
   STDMETHOD_(void, SetClipRectangle) (THIS_ 
      /*[in]*/    sFloatRect* psInRect 
    ) PURE; 
   
   STDMETHOD_(void, GetClipRectangle) (THIS_ 
      /*[out]*/   sFloatRect* psInRect 
    ) PURE; 
};


//_______ERROR_CODES________________________


#define RG_SUBSYS                      3

//
// S_OK
//


//
//      E_RGOEC_ALLOCATION
//
// memory allocation failure -- we should never see that, right?
//
#define E_RGOEC_ALLOCATION               MakeResult(kError,  RG_SUBSYS, 1)



//
//      E_RGOEC_BAD_HANDLE
//
// handle used to identify an overlay does not point to a valid object
//
#define E_RGOEC_BAD_HANDLE               MakeResult(kError,  RG_SUBSYS, 2)


//
//      S_RGOEC_INVISIBLE
//
//  overlay is OK, but it is completely clipped out (CLIP_ALL == 16)
//
#define S_RGOEC_INVISIBLE                MakeResult(kSuccess,  RG_SUBSYS, 16)   



//
//      E_RGOEC_BITMAP_LOCKED
//
//  the overlays bitmap is locked
//
#define E_RGOEC_BITMAP_LOCKED            MakeResult(kError,  RG_SUBSYS, 3)


//
//      E_RGOEC_BITMAP_UNLOCKED
//
//  the overlays bitmap was not locked
#define E_RGOEC_BITMAP_UNLOCKED            MakeResult(kError,  RG_SUBSYS, 4)



//
//      E_RGOEC_BITMAP_MIA
//
//  the bitmap has not been loaded or was abducted by aliens
//
#define E_RGOEC_BITMAP_MIA               MakeResult(kError,  RG_SUBSYS, 5)



//______EXPORTED_DATA_____________________________________

#ifdef __cplusplus
extern "C" {
#endif

   extern IRGOverlays* g_pIActiveOver;
   
#ifdef __cplusplus
}
#endif


//______MACROS____________________________________________


//HRESULT rendg_aol_add(sRGOverlayInfo* psOverInfo,HRGOVERLAY* phOver);
#define rendg_aol_add(ps, ph)  \
   COMCall2(g_pIActiveOver, AddAlphaOverlay, ps, ph)

//HRESULT rendg_aol_insert(sRGOverlayInfo* psOverInfo, HRGOVERLAY hAfterMe, HRGOVERLAY* phOver);
#define rendg_aol_insert(ps, h, ph)  COMCall3(g_pIActiveOver, InsertAlphaOverlay, ps, h, ph)

//HRESULT rendg_aol_remove(HRGOVERLAY hOver); 
#define rendg_aol_remove(h)    \
   COMCall1(g_pIActiveOver, RemoveOverlay, h)

//void rendg_aol_remove_all(void);
#define rendg_aol_remove_all()   \
   COMCall0(g_pIActiveOver, RemoveAllOverlays)

//HRESULT rendg_aol_switch(HRGOVERLAY hOver, BOOL bOn); 
#define rendg_aol_switch(h, b) \
   COMCall2(g_pIActiveOver, SwitchOverlay, h, b)

//HRESULT rendg_aol_update(HRGOVERLAY hOver, sRGOverlayInfo* psOverInfo); 
#define rendg_aol_update(h, ps) \
    COMCall2(g_pIActiveOver, UpdateAlphaOverlay, h, ps)

//HRESULT rendg_aol_lock_bitmap_data(HRGOVERLAY hOver, grs_bitmap** ppsBitmap);
#define rendg_aol_lock_bitmap_data(h, pps) \
    COMCall2(g_pIActiveOver, LockAOLBitmapData, h, pps)

//HRESULT rendg_aol_unlock_bitmap_data(HRGOVERLAY hOver);
#define rendg_aol_unlock_bitmap_data(h) \
    COMCall1(g_pIActiveOver, UnlockAOLBitmapData, h)

//HRESULT rendg_aol_set_position(HRGOVERLAY hOver, float fScreenX, float fScreenY);
#define rendg_aol_set_position(h, f1, f2) \
    COMCall3(g_pIActiveOver, SetAOLPosition, h, f1, f2)

//HRESULT rendg_aol_move(HRGOVERLAY hOver, float fDeltaX, float fDeltaY);
#define rendg_aol_move(h, f1, f2) \
    COMCall3(g_pIActiveOver, MoveAOL, h, f1, f2 )

//HRESULT rendg_aol_set_color(HRGOVERLAY hOver, int nRed, int nGreen, int nBlue, int nAlpha);
#define rendg_aol_set_color(h, n1, n2, n3, n4) \
    COMCall5(g_pIActiveOver, SetAOLColor, h, n1, n2, n3, n4)

//HRESULT rendg_aol_set_alpha(HRGOVERLAY hOver, int nAlpha);
#define rendg_aol_set_alpha(h, n) \
    COMCall2(g_pIActiveOver, SetAOLAlpha, h, n)

//void rendg_aol_set_clip_rect(sFloatRect* psInRect); 
#define rendg_aol_set_clip_rect(ps) \
    COMCall1(g_pIActiveOver, SetClipRectangle, ps)

//void rendg_aol_get_clip_rect(sFloatRect* psOutRect); 
#define rendg_aol_get_clip_rect(ps) \
    COMCall1(g_pIActiveOver, GetClipRectangle, ps)




#endif //_RGOVER_H