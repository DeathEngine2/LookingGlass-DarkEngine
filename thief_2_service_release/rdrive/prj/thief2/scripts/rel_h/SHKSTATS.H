/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkstats.h 1.2 1998/11/23 15:57:43 XEMU Exp $

#ifndef __SHKSTATS_H
#define __SHKSTATS_H

extern "C"
{
#include <event.h>
}

EXTERN void ShockStatsInit(int which);
EXTERN void ShockStatsTerm(void);
EXTERN void ShockStatsDraw(void);
EXTERN bool ShockStatsHandleMouse(Point pt);
EXTERN void ShockStatsStateChange(int which);
EXTERN bool ShockStatsCheckTransp(Point pt);


#endif