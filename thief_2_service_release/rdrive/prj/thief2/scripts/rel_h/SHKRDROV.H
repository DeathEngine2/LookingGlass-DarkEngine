/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkrdrov.h 1.4 1999/05/22 17:50:56 XEMU Exp $

#ifndef __SHKRDROV_H
#define __SHKRDROV_H

extern "C"
{
#include <event.h>
}

const int kRadarOverlayWidth = 128;
const int kRadarOverlayHeight = 128;
const int kRadarHalfWidth = (kRadarOverlayWidth-1)/2;
const int kRadarHalfHeight = (kRadarOverlayHeight-1)/2;

EXTERN void ShockRadarInit(int which);
EXTERN void ShockRadarTerm(void);
EXTERN void ShockRadarDraw(void);
EXTERN bool ShockRadarHandleMouse(Point pt);

#endif