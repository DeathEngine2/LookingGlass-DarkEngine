/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkmeter.h 1.3 1999/08/05 17:52:28 Justin Exp $

#ifndef __SHKMETER_H
#define __SHKMETER_H

extern "C" 
{
#include <event.h>
}

EXTERN void ShockMetersDraw(void);
EXTERN void ShockMetersInit(int which);
EXTERN void ShockMetersTerm(void);
EXTERN bool ShockMetersHandleMouse(Point pt);
EXTERN bool ShockMetersCheckTransp(Point pt);
EXTERN bool ShockMetersDragDrop(Point pt, BOOL start);

#endif
