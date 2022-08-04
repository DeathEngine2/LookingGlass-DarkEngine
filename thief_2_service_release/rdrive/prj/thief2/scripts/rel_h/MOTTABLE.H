/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/mottable.h 1.1 1998/01/07 12:23:38 kate Exp $

#ifndef __MOTTABLE_H
#define __MOTTABLE_H

#include <imottab.h>

#define DLLEXPORT __declspec (dllexport)

EXTERN DLLEXPORT IMotionTable * LGAPI GetMotionTable();


#endif // __MOTTABLE_H
