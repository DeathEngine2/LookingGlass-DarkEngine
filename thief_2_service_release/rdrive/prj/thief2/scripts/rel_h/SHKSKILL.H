/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkskill.h 1.3 1999/01/02 13:54:00 XEMU Exp $

#ifndef __SHKSKILL_H
#define __SHKSKILL_H

#include <rect.h>

extern "C"
{
#include <event.h>
}

EXTERN void ShockSkillsInit(int which);
EXTERN void ShockSkillsTerm(void);
EXTERN void ShockSkillsDraw(void);
EXTERN bool ShockSkillsHandleMouse(Point pt);
EXTERN void ShockSkillsStateChange(int which);
EXTERN bool ShockSkillsCheckTransp(Point pt);

#endif