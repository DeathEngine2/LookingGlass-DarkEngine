/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkuitul.h 1.1 1999/08/05 18:03:19 Justin Exp $

#ifndef __SHKUITUL_H
#define __SHKUITUL_H
#include <rect.h>
#include <guistyle.h>

// Flags for DrawString
enum eDrawStringFlags
{
   kLeftAlign  = 1 << 0, 
};

   // Draw an arbitrary string in a rect, centered and top aligned.
   // Return the height drawn, that is to say the y coord of the bottom of text  
extern int ShockDrawString(const char* str, const Rect& r, ulong flags = 0, guiStyle* style = NULL, StyleFontKind font = StyleFontNormal); 



#endif // __SHKUITUL_H
