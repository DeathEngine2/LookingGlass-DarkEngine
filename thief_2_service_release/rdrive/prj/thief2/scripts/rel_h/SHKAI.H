/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkai.h 1.4 1998/08/20 16:04:00 JON Exp $

#ifndef __SHKAI_H
#define __SHKAI_H

#include <relation.h>

typedef int eAIVisionType;
// note: must keep this in synch with struct desc in shkai.cpp
enum eAIVisionType_ 
{
   kAIVisionGeneric = 0, 
   kAIVisionCamera = 1, 
   kAIVisionRobot = 2, 
   kAIVisionHuman = 3, 
   kAIVisionHybrid = 4, 
   kAIVisionAnnelid = 5, 
   kAIVisionTypeNum};

EXTERN IRelation *g_pAIGunFlashLinks;

EXTERN void ShockAIInit();
EXTERN void ShockAITerm();

#endif // __SHKAI_H