/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/shkyorn.h 1.1 1998/03/18 16:05:56 XEMU Exp $

#ifndef __SHKYORN_H
#define __SHKYORN_H

extern "C"
{
#include <event.h>
}
#include <objtype.h>

EXTERN void ShockYorNInit(int which);
EXTERN void ShockYorNTerm(void);
EXTERN void ShockYorNDraw(void);
EXTERN bool ShockYorNHandleMouse(uiMouseEvent *mev);
EXTERN void ShockYorNStateChange(int which);
EXTERN bool ShockYorNCheckTransp(Point pt);
EXTERN void ShockYorNPopup(ObjID o, const char *text);

#endif