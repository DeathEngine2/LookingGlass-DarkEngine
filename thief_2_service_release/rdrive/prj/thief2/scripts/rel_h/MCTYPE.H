/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/mctype.h 1.3 1998/01/29 17:33:35 kate Exp $

#ifndef __MCTYPE_H
#define __MCTYPE_H

typedef class IMotionCoordinator IMotionCoordinator;
typedef class IManeuver IManeuver;
typedef class IMotionPlan IMotionPlan;

typedef struct sMcMoveState sMcMoveState;
typedef struct sMcMoveParams sMcMoveParams;

typedef void (*fMcMotorStateChangeCallback)(void *context);

typedef void (*fMcManeuverCompletionCallback)(void *context, IManeuver *pCompleted, IManeuver *pNext);

#endif
