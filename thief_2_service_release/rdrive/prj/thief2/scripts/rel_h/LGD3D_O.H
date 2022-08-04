/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  1/18/99 6:33:27 PM
  
    File:  lgd3d_o.h
    
      Description:  
      
        
=========================================================*/

#ifndef _LGD3D_O_H
#define _LGD3D_O_H


//_____INCLUDES_AND_DEFINITIONS___________________________

#include <dev2d.h>


#ifdef __cplusplus
extern "C" {
#endif

//_______OVERLAYS_________________________________________


// TRANSLUCENT OVERLAYS ("alpha overlays" or aol)
// Overlays are displayed at the end of the frame.
//
// Overlays can be set and changed any time during the executions, and once set they are displayed every frame until
// explicitly unset or switched off, or untill lgd3d goes bah-by (for example, 2d option screen pops up).
// Overlays are kept and displayed from an ordered list. The app only needs to keep a handle to an overlay.
//
// creating overlays:
// "lgd3d_aol_add" appends the end of the list and "lgd3d_aol_insert" inserts after the specified overlay.
// sLGD3DOverlayInfo structure passed (as reference) to these functions doesn't need to exist after the call.  
//
// To restore overlay:
// After lgd3d was closed and reinitalized or the overlay was removed: use "lgd3d_aol_add" or "lgd3d_aol_insert"
// (Note that the previously used handles have expired and you need to renew your driving licence.)
// After the overlay was switched off (with "lgd3d_aol_switch( handle, FALSE)") use "lgd3d_aol_switch( handle, TRUE)"
//
// NOTE: if you do something funky with lgd3d frames you can turn ovelays on and off using
//      "BOOL lgd3d_overlays_master_switch( BOOL bOverlaysOn );" from lgd3d.h. However this function has no 
//      "magic rug feature", so you will get an access exception if you call this function 
//      and the lgd3d library does not exist. On other hand existance of overlays is not required.

typedef struct {
    union {
        float fX0;
        float fU0;
    };
    union {
        float fY0;
        float fV0;
    };
    union {
        float fX1;
        float fU1;
    };
    union {
        float fY1;
        float fV1;
    };
} sOverRectangle;

/*
    0 ---1
    | \  |
    |  \ |
    |   \|
    3----2

  */
typedef unsigned long HLGD3DOVERLAY; //"handle" to an overlay



// sLGD3DOverlayInfo.dwFlags specify which fields of the structure are usable
//
// DEFAULT: use only  fX0, fY0 and pBitmap
#define LGD3DOI_UPPER_LEFT_CORNER       0x00000001L
#define LGD3DOI_BITMAP                  0x00000002L
#define LGD3DOI_ALPHA                   0x00000004L
#define LGD3DOI_RGB                     0x00000008L
#define LGD3DOI_LOWER_RIGHT_CORNER      0x00000010L
#define LGD3DOI_TEXTURE_COORDINATES     0x00000020L

//NOTE: LGD3DOI_UPPER_LEFT_CORNER and LGD3DOI_BITMAP are assumed 
//      in the calls to "lgd3d_aol_add" and  "lgd3d_aol_insert".

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
} sLGD3DOverlayInfo;



// creation

// return codes:  S_OK, S_LGD3DOEC_INVISIBLE, E_LGD3DOEC_ALLOCATION 
HRESULT lgd3d_aol_add(  sLGD3DOverlayInfo* psOverInfo,  // in
                        HLGD3DOVERLAY* phOver);         // out

// return codes:  S_OK, S_LGD3DOEC_INVISIBLE, E_LGD3DOEC_ALLOCATION, E_LGD3DOEC_BAD_HANDLE
HRESULT lgd3d_aol_insert(   sLGD3DOverlayInfo* psOverInfo, HLGD3DOVERLAY hAfterMe,  // in
                            HLGD3DOVERLAY* phOver);                                 // out




// death

// return codes:  S_OK, E_LGD3DOEC_BAD_HANDLE

HRESULT lgd3d_aol_remove( HLGD3DOVERLAY hOver ); 

void lgd3d_aol_remove_all( void );


// switching on/off

//returns the previous (ON/OFF) state of overlays
//(DECLARED IN LGD3D.H: )     BOOL lgd3d_overlays_master_switch( BOOL bOverlaysOn );


// return codes:  S_OK, E_LGD3DOEC_BAD_HANDLE
HRESULT lgd3d_aol_switch( HLGD3DOVERLAY hOver, BOOL bOn ); 


// updating data

// return codes:  S_OK, S_LGD3DOEC_INVISIBLE, E_LGD3DOEC_BAD_HANDLE

// use the flags in psOverInfo to specify what to change. 
// NOTE: Bitmap can NOT be changed with this method.
HRESULT lgd3d_aol_update( HLGD3DOVERLAY hOver, sLGD3DOverlayInfo* psOverInfo ); 

// to update bitmap data. Do NOT change anything else in the bitmap structure!
// NOTE: while bitmap locked overlay will not be displayed. 
HRESULT lgd3d_aol_lock_bitmap_data( HLGD3DOVERLAY hOver, //in
                                    grs_bitmap** ppsBitmap // out 
                                    );

// it will reload the bitmap of the overlay
HRESULT lgd3d_aol_unlock_bitmap_data( HLGD3DOVERLAY hOver );
  
HRESULT lgd3d_aol_set_position( HLGD3DOVERLAY hOver, float fScreenX, float fScreenY );
HRESULT lgd3d_aol_move( HLGD3DOVERLAY hOver, float fDeltaX, float fDeltaY );
HRESULT lgd3d_aol_set_color( HLGD3DOVERLAY hOver, int nRed, int nGreen, int nBlue, int nAlpha );
HRESULT lgd3d_aol_set_alpha( HLGD3DOVERLAY hOver, int nAlpha );


// clipping viewport

// if psInRect == NULL the whole screen is the clipping rectangle
void lgd3d_aol_set_clip_rect( sOverRectangle* psInRect ); 

void lgd3d_aol_get_clip_rect( sOverRectangle* psOutRect ); 





//_______ERROR_CODES________________________


#define LGD3D_SUBSYS                      3

//
// S_OK
//


//
//      E_LGD3DOEC_ALLOCATION
//
// memory allocation failure -- we should never see that, right?
//
#define E_LGD3DOEC_ALLOCATION               MakeResult( kError,  LGD3D_SUBSYS, 1 )



//
//      E_LGD3DOEC_BAD_HANDLE
//
// handle used to identify an overlay does not point to a valid object
//
#define E_LGD3DOEC_BAD_HANDLE               MakeResult( kError,  LGD3D_SUBSYS, 2 )


//
//      S_LGD3DOEC_INVISIBLE
//
//  overlay is OK, but it is completely clipped out (CLIP_ALL == 16)
//
#define S_LGD3DOEC_INVISIBLE                MakeResult( kSuccess,  LGD3D_SUBSYS, 16 )   



//
//      E_LGD3DOEC_BITMAP_LOCKED
//
//  the overlays bitmap is locked
//
#define E_LGD3DOEC_BITMAP_LOCKED            MakeResult( kError,  LGD3D_SUBSYS, 3 )


//
//      E_LGD3DOEC_BITMAP_UNLOCKED
//
//  the overlays bitmap was not locked
#define E_LGD3DOEC_BITMAP_UNLOCKED            MakeResult( kError,  LGD3D_SUBSYS, 4 )



//
//      E_LGD3DOEC_BITMAP_MIA
//
//  the bitmap has not been loaded or was abducted by aliens
//
#define E_LGD3DOEC_BITMAP_MIA               MakeResult( kError,  LGD3D_SUBSYS, 5 )




#ifdef __cplusplus
}
#endif


#endif //_LGD3D_O_H