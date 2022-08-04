/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/palmnch/RCS/palmnch.h 1.5 1998/11/24 10:11:18 jaemz Exp $

#ifndef __FIT_H
#define __FIT_H

#include <stdio.h>

#include <2d.h>
#include <ipw.h>
#include <error.h>

// First call this with how many colors you want to max out
// at, default is 12000 if you pass 0 or negative number
EXTERN void PlmInit( int max_colors);

// Before processing any files, you can call these
// to set options
EXTERN void PlmSetFillColor( int r, int g, int b );
EXTERN void PlmSetAlpha( float a );
EXTERN void PlmSetBeta( float b );
EXTERN void PlmSetGamma( float g );
EXTERN void PlmUnsetAlpha( void );
EXTERN void PlmUnsetBeta( void );
EXTERN void PlmUnsetGamma( void );
EXTERN void PlmSetSegaQuantization( void );
EXTERN void PlmSetQuantization( int rbits, int gbits, int bbits );
EXTERN void PlmSetSuperblackRemapping( bool onoff );
EXTERN void PlmSetIpalDepth( int depth );
EXTERN void PlmSetNColors( int n );

// Call these to put fix and post colors in the palette,
// before processing images

// Post colors have no influence on the palette
EXTERN errtype PlmAddPostColor( int r, int g, int b, int slot );

// Fix colors are fixed in the palette.  This is really
// the only cool part of this algorithm, using fixed
// colors you already have.
EXTERN errtype PlmAddFixColor( int r, int g, int b, int slot );

// Add a color with a weight
EXTERN void PlmAddColor(int r,int g,int b,ulong weight);


// Process image by calling these two, often as you like
EXTERN errtype PlmProcessIpwImage( Image *I );
EXTERN errtype PlmProcess2dImage( grs_bitmap *bm );
EXTERN void PlmSetDefaultWeight( ulong wt );

// When you have processed all the files you want,
EXTERN errtype PlmCrunch( void );

// Calling this resets the cruncher data structures.
EXTERN void PlmResetCruncher( void );

// After crunching the palette, reap the spoils of wor.
EXTERN uchar *PlmGetPal( void );
EXTERN ulong *PlmGetPalWeights();


EXTERN void PlmWriteSimplePal( int fd );
EXTERN errtype PlmWriteIpal( int fd );
EXTERN errtype PlmRepalIpwImage( Image *old, Image **new_one, char *fname );
EXTERN errtype PlmRepal2dImage( grs_bitmap *old, grs_bitmap *new_one, char *fname );

// Informational things, call at any time
EXTERN ulong PlmNumColorsRead( void );

// Error codes
#define PLM_OK                       (0)
#define PLMERR_TOO_MANY_FIXCOLORS   (-1)
#define PLMERR_TOO_MANY_POSTCOLORS  (-2)
#define PLMERR_NO_PAL_BUILT         (-3)
#define PLMERR_CANT_ALLOCATE_COLOR  (-4)
#define PLMERR_FRIENDLESS_COLOR     (-5)
#define PLMERR_BAD_FRIEND           (-6)
#define PLMERR_BAD_IMAGE            (-7)
#define PLMERR_IMAGE_SIZES_DIFFER   (-8)
#define PLMERR_NO_OFFBLACK          (-9)
#define PLMERR_BAD_NEW_IMAGE       (-10)
#define PLMERR_CANT_ALLOCATE_IMAGE (-11)
#define PLMERR_CANT_REPAL_IMAGE    (-12)
#define PLMERR_CANT_CVT_IPW_TO_2D  (-13)
#define PLMERR_CANT_CVT_2D_TO_IPW  (-13)
#define PLMERR_IPW_CANT_DELETE     (-15)

// This stuff should be in ipw, but instead its in palmnch
extern char *IP_ERRORS[];
#define ip_error(a) ((a<=-1 && a>=-4) ? IP_ERRORS[(-a)-1] : "Unknown IPW error")

#endif /* !__FIT_H */





