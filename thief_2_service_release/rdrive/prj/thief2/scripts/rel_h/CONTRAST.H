/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: x:/prj/tech/libsrc/contrast/RCS/contrast.h $
 * $Revision: 1.1 $
 * $Author: JAEMZ $
 * $Date: 1998/01/23 12:16:27 $
 *
 */

#ifndef __CONTRAST_H
#define __CONTRAST_H


// The contrast library supplies routines
// for adjusting the contrast of values and 
// 8 bit palettes around a given value.
// Contrast is always provided AROUND some
// given value, usually some scene average.
// Basically values around that average are
// scaled.  The simplest method is to get the
// delta from the average, scale it, then add
// it back to the average.  Of course this saturates
// quickly.  A more "advanced" algorithm provided,
// transforms the delta into a space such that
// it goes to infinity at 255 and 0.  This means
// that scaling the delta never completely saturates
// but just gets closer and closer to 0 and 255 in
// a gradual fashion.  You can choose which you prefer.
// 

#define CONTRAST_LINEAR 0
#define CONTRAST_ASYMPTOTIC 1

// Set the contrast type for this app.
// 0 is default, which is purely linear, easily saturates
// 1 is linear around the average and decreases towards 0 and 255
// Default is 0
void ContrastSetType(int ctype);


// Returns the currently set contrast type
int ContrastGetType();


// Given a source value, the average to contrast around, and 
// the contrast amount, return a new one.
// Contrast goes from (0..1..)
int ContrastValue(float val,float av,float contrast);


// Make a contrasted palette around the average screen intensity (av),
// and a src palette,and the contrast amount.
// Contrast goes from (0..1..)
void ContrastMakePalAround(uchar *dst,uchar *src,float av,float contrast);
 

// Given a palette, and the average lighting level, returns
// the average intensity of that palette.
float ContrastGetPalIntensity(uchar *src,float av_int);


// Given a palette, and an average lighting value, and a contrast
// parameter (0..1..), stuff a return palette.  Src can be dst.
// The lighting value is the average light intensity of the scene.
void ContrastMakePalIntensity(uchar *dst,uchar *src,float av_int,float contrast);





#endif // CONTRAST_H





