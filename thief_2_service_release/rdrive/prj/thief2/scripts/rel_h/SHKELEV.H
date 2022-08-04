/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkelev.h 1.2 1999/08/07 21:07:53 Justin Exp $

#ifndef __SHKELEV_H
#define __SHKELEV_H

#include <rect.h>

EXTERN void ShockElevInit(int which);
EXTERN void ShockElevTerm(void);
EXTERN void ShockElevNetInit();
EXTERN void ShockElevNetTerm();
EXTERN void ShockElevDraw(void);
EXTERN bool ShockElevHandleMouse(Point pt);
EXTERN void ShockElevStateChange(int which);
EXTERN bool ShockElevCheckTransp(Point pt);


#endif
