/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/dragbox.h 1.1 1996/07/31 03:29:56 mahk Exp $

#ifndef __DRAGBOX_H
#define __DRAGBOX_H
#include <editbr.h>
#include <vslider.h>

EXTERN void* brushVSsetupSz(floatSlider *s, editBrush* br, int axis, float scale);
EXTERN void* brushVSsetupPos(floatSlider *s, editBrush* br, int axis, float scale);
EXTERN void* brushVSsetupAng(fixangSlider *s, editBrush* br, int axis);

#endif // __DRAGBOX_H
