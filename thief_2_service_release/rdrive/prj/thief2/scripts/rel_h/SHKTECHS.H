/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shktechs.h 1.1 1999/01/02 13:57:03 XEMU Exp $

#ifndef __SHKTECHS_H
#define __SHKTECHS_H

#include <rect.h>

EXTERN void ShockTechSkillInit(int which);
EXTERN void ShockTechSkillTerm(void);
EXTERN void ShockTechSkillDraw(void);
EXTERN bool ShockTechSkillHandleMouse(Point pt);
EXTERN void ShockTechSkillStateChange(int which);
EXTERN bool ShockTechSkillCheckTransp(Point pt);

#endif