/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aitsktyp.h 1.2 1997/12/30 13:35:57 TOML Exp $
//
//

#ifndef __AITSKTYP_H
#define __AITSKTYP_H

#pragma once

///////////////////////////////////////////////////////////////////////////////

enum eAITaskType // @Note (toml 09-28-97): grumble grumble, hate hate hate
{
   kNullTask,

   // Event Generators
   kAIEfficiencyModeEvtGen,
   kTrackAIsEvtGen,
   kTrackPlayerEvtGen,
   kFMOWatcherEvtGen,
   kUpdateAttackLinksEvtGen,
   kAIMoveProgressWatcherEvtGen,

   // Cortex Related Tasks
   kUpdateScriptCortexComp,
   kUpdatePatrolHLDCortexComp,
   kUpdateAttackHLDCortexComp,
   kUpdateDefendHLDCortexComp,
   kUpdateFollowHLDCortexComp,
   kUpdateFleeHLDCortexComp,
   kUpdateGeneralHLDCortexComp,
   kUpdateHighLevelCombatGoalCortexComp,
   kSoundCortexComp,

   // Movement Releated Tasks
   kEvaluatorsCoord,
   kMoveCoordinator,
   kBasicAttackEnemyMoveEval,
   kBumAroundMoveEval,
   kHighLevelDestinationMoveEval,
   kAvoidWallsAndCliffsMoveEval,
   kPredictLocationToAvoidCliffMoveEval,
   kDodgeFastMovingObjectsMoveEval,
   kAvoidFriendsMoveEval,

   // Biped Related Tasks
   kBipedCoord,
   kIdleGesturesBipedEval,
   kFireMissleWeaponBipedEval,
   kCombatBipedEval,

   kNumTaskTypes,
   kAITaskTypeMax=0xffffffff // force it use an int
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__AITSKTYP_H */
