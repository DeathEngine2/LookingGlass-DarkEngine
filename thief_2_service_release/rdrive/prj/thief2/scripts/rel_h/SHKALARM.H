/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkalarm.h 1.3 1999/06/17 23:54:48 XEMU Exp $

#ifndef __SHKALARM_H
#define __SHKALARM_H

extern "C" 
{
#include <event.h>
}

EXTERN void ShockAlarmDraw(void);
EXTERN void ShockAlarmInit(int which);
EXTERN void ShockAlarmTerm(void);
EXTERN void ShockHackIconDraw(void);
EXTERN void ShockHackIconInit(int which);
EXTERN void ShockHackIconTerm(void);

EXTERN void ShockAlarmAdd(int time);
EXTERN void ShockAlarmRemove(void);
EXTERN void ShockAlarmDisableAll(void);
#endif