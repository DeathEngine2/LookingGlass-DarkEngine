/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkmap.h 1.3 1999/01/25 18:23:02 XEMU Exp $

#ifndef __SHKMAP_H
#define __SHKMAP_H

#include <objtype.h>
extern "C"
{
#include <event.h>
}

EXTERN void ShockMapInit(int which);
EXTERN void ShockMapTerm(void);
EXTERN void ShockMapDraw(void);
EXTERN void ShockMapStateChange(int which);

EXTERN void ShockMiniMapInit(int which);
EXTERN void ShockMiniMapTerm(void);
EXTERN void ShockMiniMapDraw(void);
EXTERN void ShockMiniMapStateChange(int which);
EXTERN bool ShockMiniMapCheckTransp(Point pt);

EXTERN void ShockMapSetExplored(int loc, char val);
EXTERN void ShockMapDrawContents(Point dp);

#endif