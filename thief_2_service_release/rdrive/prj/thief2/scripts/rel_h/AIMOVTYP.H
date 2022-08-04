/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aimovtyp.h 1.1 1997/10/04 17:10:50 TOML Exp $
//
//
//

#ifndef __AIMOVTYP_H
#define __AIMOVTYP_H

#include <fltang.h>
#include <aitype.h>
#include <aitsktyp.h>

#pragma once
#pragma pack(4)

///////////////////////////////////////////////////////////////////////////////
//
// Constants
//

enum eAIFacing
{
   kAIF_Any,
   kAIF_MoveDir,
   kAIF_CombatTarget,
   kAIF_SpecificDir,
   kAIF_TypeMax=0xffffffff // force it use an int
};

///////////////////////////////////////////////////////////////////////////////
//
// STRUCT: sAIMoveSuggestion
//
// The sAIMoveSuggestion structure provides the uniform information
// structure through which evalutors make movement suggestions
// to their coordinators.

struct sAIMoveSuggestion
{
   int         bias;                    // suggestion bias (-100%..+100%)
   floatarc    moveDir;                 // which direction is the suggestion, 0 = east
   sAIPoint    finalDest;               // what's the final goal of the movement process?
   eAIFacing   facingRestriction;       // which way does the AI have to face?
   floatang    specificFacing;          // for facingRestriction==kAIF_SpecificDir
   int         speed;                   // what speed 0%..100%
   int         speedLatitude;           // latitude of speed suggestion
   char        fMutualExlusions;        // what suggestions do I not mix with?

   eAITaskType suggestor;               // who suggested this crazy idea?
   BOOL        active;                  // is this the active move suggestion? (from the last cycle)
   ulong       timeCreated;             // when was the suggestion created?

   union
   {
      // data for use by suggestor
      short    shortdata[8];
      long     longdata[4];
      float    floatdata[2];
   };
};

///////////////////////////////////////////////////////////////////////////////
//
// STRUCT: sAIMoveGoal
//

struct sAIMoveGoal
{
   sAIPoint    finalDest;               // the final destination of the current move goal
   floatang    moveDir;                 // the direction we hope we're moving, 0 = east
   eAIFacing   facing;                  // how the movement goal wants the AI facing
   floatang    specificFacing;          // for facing==kAIF_SpecificDir
   int         speed;                   // the speed we hope we're moving

   eAITaskType activeEval;              // the movement evaluator in control
   ulong       timeOfEvalActivation;    // when did the active evaluator become the active?
   eAIPriority priority;                // lead suggestion priority level
};

///////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__AIMOVTYP_H */
