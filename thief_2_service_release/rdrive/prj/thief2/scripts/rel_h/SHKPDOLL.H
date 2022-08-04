/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkpdoll.h 1.3 1998/12/08 00:07:44 XEMU Exp $

#ifndef __SHKPDOLL_H
#define __SHKPDOLL_H

#include <objtype.h>
extern "C"
{
#include <event.h>
}

EXTERN void ShockPaperDollInit(int which);
EXTERN void ShockPaperDollTerm(void);
EXTERN void ShockPaperDollDraw(void);
EXTERN bool ShockPaperDollHandleMouse(Point pt);
EXTERN bool ShockPaperDollDoubleClick(Point pos);
EXTERN bool ShockPaperDollDragDrop(Point pos, BOOL start);
EXTERN void ShockPaperDollStateChange(int which);
EXTERN bool ShockPaperDollCheckTransp(Point pt);

#endif