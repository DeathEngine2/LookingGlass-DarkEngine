// $Header: x:/prj/tech/libsrc/palmnch/RCS/palmnch.h 1.4 1997/04/22 11:33:33 JAEMZ Exp $

#ifndef __FIT_H
#define __FIT_H

#include <stdio.h>

#include <2d.h>
#include <ipw.h>
#include <error.h>

// First call this with how many colors you want to max out
// at, default is 12000 if you pass 0 or negative number
void PlmInit( int max_colors);

// Before processing any files, you can call these
// to set options
void PlmSetFillColor( int r, int g, int b );
void PlmSetAlpha( float a );
void PlmSetBeta( float b );
void PlmSetGamma( float g );
void PlmUnsetAlpha( void );
void PlmUnsetBeta( void );
void PlmUnsetGamma( void );
void PlmSetSegaQuantization( void );
void PlmSetQuantization( int rbits, int gbits, int bbits );
void PlmSetSuperblackRemapping( bool onoff );
void PlmSetIpalDepth( int depth );
void PlmSetNColors( int n );

// Call these to put fix and post colors in the palette,
// before processing images

// Post colors have no influence on the palette
errtype PlmAddPostColor( int r, int g, int b, int slot );

// Fix colors are fixed in the palette.  This is really
// the only cool part of this algorithm, using fixed
// colors you already have.
errtype PlmAddFixColor( int r, int g, int b, int slot );

// Add a color with a weight
void PlmAddColor(int r,int g,int b,ulong weight);


// Process image by calling these two, often as you like
errtype PlmProcessIpwImage( Image *I );
errtype PlmProcess2dImage( grs_bitmap *bm );
void PlmSetDefaultWeight( ulong wt );

// When you have processed all the files you want,
errtype PlmCrunch( void );

// Calling this resets the cruncher data structures.
void PlmResetCruncher( void );

// After crunching the palette, reap the spoils of wor.
uchar *PlmGetPal( void );
ulong *PlmGetPalWeights();


void PlmWriteSimplePal( int fd );
errtype PlmWriteIpal( int fd );
errtype PlmRepalIpwImage( Image *old, Image **new, char *fname );
errtype PlmRepal2dImage( grs_bitmap *old, grs_bitmap *new, char *fname );

// Informational things, call at any time
ulong PlmNumColorsRead( void );

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
