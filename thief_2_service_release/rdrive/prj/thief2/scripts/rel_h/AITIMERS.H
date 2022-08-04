/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aitimers.h 1.4 1997/10/04 17:11:56 TOML Exp $
//
//
//

#ifndef __AITIMERS_H
#define __AITIMERS_H

#ifdef __cplusplus
#include <timings.h>
#endif

///////////////////////////////////////////////////////////////////////////////

#ifndef SHIP

enum eAICycleTimers
{
   kAICycleTimer_FrameInit,
   kAICycleTimer_EventGeneration,
   kAICycleTimer_CortexProcess,
   kAICycleTimer_MovementProcess,
   kAICycleTimer_BipedProcess,
   kAICycleTimer_FrameShutdown,
   kAICycleTimer_PreCycle,

   kAICycleTimer_Count
};

#ifdef __cplusplus
extern cTimerSet<cAverageTimer, kAICycleTimer_Count> g_AICycleTimers;
#endif

EXTERN void AIInitCycleTimers();
EXTERN void AITermCycleTimers();

#define AICycleTimerStart(phase)    g_AICycleTimers[ kAICycleTimer_ ## phase ].Start()
#define AICycleTimerMark(phase)     g_AICycleTimers[ kAICycleTimer_ ## phase ].Mark()
#define AICycleTimerStop(phase)     g_AICycleTimers[ kAICycleTimer_ ## phase ].MarkStop()

#endif

///////////////////////////////////////////////////////////////////////////////

#endif /* !__AITIMERS_H */
