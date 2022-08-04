/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkcont.h 1.6 1998/12/08 00:07:45 XEMU Exp $

#ifndef __SHKCONT_H
#define __SHKCONT_H

#include <objtype.h>
extern "C"
{
#include <event.h>
}

EXTERN void ShockContainerInit(int which);
EXTERN void ShockContainerTerm(void);
EXTERN void ShockContainerDraw(void);
EXTERN bool ShockContainerHandleMouse(Point pt);
EXTERN bool ShockContainerDragDrop(Point pt, BOOL start);
EXTERN void ShockContainerStateChange(int which);
EXTERN void ShockContainerOpen(ObjID o);
EXTERN bool ShockContainerCheckTransp(Point pt);
EXTERN ObjID ShockContainerFindObj(Point mpos, int *slotp = NULL);
EXTERN int ShockContainerFindObjSlot(Point mpos);
EXTERN void ShockContainerCheckRemove(ObjID o, ObjID cont);

#endif
