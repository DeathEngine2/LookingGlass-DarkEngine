/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aibiptyp.h 1.6 1998/02/11 20:17:13 dc Exp $
//
//
//

#ifndef __AIBIPTYP_H
#define __AIBIPTYP_H

///////////////////////////////////////////////////////////////////////////////
//
// Constants
//

enum eAIMotionType
{
   kAIMT_Calibration,
   kAIMT_Rest,
   kAIMT_IdleGesture,
   kAIMT_AlertLevelOne,
   kAIMT_AlertLevelTwo,
   kAIMT_AlertLevelThreeFront,
   kAIMT_AlertLevelThreeRear,
   kAIMT_CallingForHelp,
   kAIMT_EnteringAttackMode,
   kAIMT_SwordAttack,
   kAIMT_SwordAttShort,
   kAIMT_SwordAttMedium,
   kAIMT_SwordAttLong,
   kAIMT_SwordParry,
   kAIMT_SwordDodge,
   kAIMT_SideStepRight,
   kAIMT_SideStepLeft,
   kAIMT_Retreat,
   kAIMT_RetreatFast,   
   kAIMT_Advance,
   kAIMT_Death,
   kAIMT_Walk,
   kAIMT_Awaken,
   kAIMT_Hurt,
   kAIMT_HurtLight,
   kAIMT_HurtLots,
   kAIMT_CombatIdle,
   kAIMT_Stun,
   
   kNumAIMotions,
   kAIMT_None,
   kAIMType_TypeMax=0xffffffff // force it use an int
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__AIBIPTYP_H */
