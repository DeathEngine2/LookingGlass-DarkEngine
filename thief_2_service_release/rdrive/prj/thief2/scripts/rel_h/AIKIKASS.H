/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aikikass.h 1.6 1998/02/20 13:57:08 dc Exp $
//
// Kick Ass!
//

#ifndef __AIKIKASS_H
#define __AIKIKASS_H

#include <ai.h>
#include <aievtgen.h>
#include <aicortex.h>
#include <aimoveev.h>

#pragma once
#pragma pack(4)

///////////////////////////////////////////////////////////////////////////////

class cAI;
class cAICbatEvGen;
class cAICbatCtx;
class cAICbatMev;
class cAIProtoCombat;
class cAIProtoCombatComponent;

enum eAIProtoCombatEvent {
   kAIPC_EventNull,
   kAIPC_ImDamaged,
   kAIPC_TargetDamaged,
   kAIPC_ImContacted,
   kAIPC_TargetContacted,
   kAIPC_Block,
   kAIPC_OppAttackStart,
   kAIPC_OppAttackEnd,
   kAIPC_OppBlockStart,
   kAIPC_OppBlockEnd,
   kAIPC_Hit,
   kAIPC_Hitting,
   kAIPC_Stunned,
   kAIPC_TooClose,
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIProtoCombat
//
// The composite combat object, shared by the combat event generator, cortex
// and movement evaluator. Referred to within those classes as "m_pOuter"
//

class cAIProtoCombat
{
public:   
   cAIProtoCombat(cAI * pAI);
   ~cAIProtoCombat();
   
   BOOL HaveCombatTarget();
   BOOL GetCombatTarget(ObjID * pTarget, eAIPriority * pTargetPriority);
   eAIPriority GetTargetTacticalPriorty();
   
   void UpdateLinks();
   void SetDestination();
   // return whether to cycle the HLDMev
   BOOL SuggestMoves();
   
   cAICbatEvGen * GetEvGen();
   cAICbatCtx *   GetCtx();
   cAICbatMev *   GetMev();
   void SetHldMev(cAIHldMev * pHldMev);
   
   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

   // tell protocombat about events in the world (from weapon/damage listeners in aiext)
   void InformOfEvent(eAIProtoCombatEvent happened);

   // this is idiotically here so i can get to it from CbatMev - dc
   cAIHldMev    *m_pHldMev;

private:
   // so we can talk to the rest of ourselves and such
   cAICbatEvGen *m_pEvGen;
   cAICbatCtx   *m_pCtx;
   cAICbatMev   *m_pMev;
   cAI          *m_pAI;

   // target control/system
   BOOL        m_fCombatTargetValid;
   ObjID       m_CombatTarget;
   eAIPriority m_CombatTargetPriority;

   float       m_goalDist;
   float       m_lastDist;

   ////////////////////////////////////////
   // the horror of the attack mode system
   enum eAIActionPriority { kRnd, kLow, kNorm, kHigh, kMust };
   
   enum eAISimpleAttackModes
   {
      ATTACK_UNDECIDED,
      ATTACK_MODE_CIRCLE_CW,
      ATTACK_MODE_CIRCLE_CCW,
      ATTACK_MODE_CHARGE,
      ATTACK_MODE_BACKOFF,
      ATTACK_MODE_JUMPBACK,
      ATTACK_MODE_ADVANCE,
      ATTACK_MODE_AVOID,
      ATTACK_MODE_BLOCK,
      ATTACK_MODE_DODGE,
      ATTACK_MODE_IDLE,
      ATTACK_MODE_NO_MOVE, // @HACK ai gun
      ATTACK_MODE_SWING_QUICK,
      ATTACK_MODE_SWING_NORMAL,
      ATTACK_MODE_SWING_MASSIVE,
      NUM_ATTACK_MODES
   };

   // for use in the horror of choosing attacks
   struct atkEntry {
      eAISimpleAttackModes mode;
      eAIActionPriority    pri;
      int                  wgt;
   };

   eAISimpleAttackModes m_mode;
   int                  m_MsThisMode;
   int                  m_LastSndTime;
   BOOL                 m_specificAction;  // are we requesting specific behavior
   
   // so we have fewer ifs in the damn code
   inline BOOL isModeAttacking(const eAISimpleAttackModes mode)
    { return (mode==ATTACK_MODE_SWING_QUICK)||(mode==ATTACK_MODE_SWING_NORMAL)||(mode==ATTACK_MODE_SWING_MASSIVE); }
   inline BOOL isModeBlocking(const eAISimpleAttackModes mode)
    { return (mode==ATTACK_MODE_BLOCK); }
   inline BOOL isModeAvoiding(const eAISimpleAttackModes mode)
    { return (mode==ATTACK_MODE_BLOCK)||(mode==ATTACK_MODE_BACKOFF)||(mode==ATTACK_MODE_DODGE); }
   inline BOOL isModeCanRespond(const eAISimpleAttackModes mode)
    { return (mode==ATTACK_MODE_IDLE)||(mode==ATTACK_MODE_AVOID)||(mode==ATTACK_MODE_BACKOFF)||(mode==ATTACK_MODE_CIRCLE_CW)||(mode==ATTACK_MODE_CIRCLE_CCW); }

   // event queue, for ProtoCombat events we are InformOfEventted of
   #define             AIPROTO_EventQueueLen         32
   eAIProtoCombatEvent m_EventQueue[AIPROTO_EventQueueLen];    // lets track what has happened to us mid frame
   int                 m_EventQueuePtr;

   // current state on the Opponent we are engaged with
   BOOL                m_OppAttacking;
   BOOL                m_OppBlocking;

   // various helper functions for parsing combat
   void ProcessModeSet(eAISimpleAttackModes new_mode, ObjID target, sAIPoint targetPt);
   BOOL ChooseNewAttackMode(eAISimpleAttackModes *new_mode, ObjID target, sAIPoint targetPt);
   BOOL InterruptForEvent(eAISimpleAttackModes *new_mode, float dist_2);
   void UpdateOppState(eAIProtoCombatEvent ev);
   BOOL SolveResponse(atkEntry *Choices, int choice_count, eAISimpleAttackModes *new_mode, eAIActionPriority *pri);
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIProtoCombatComponent
//

class cAIProtoCombatComponent
{
protected:
   cAIProtoCombatComponent(cAIProtoCombat * pOuter)
    : m_pOuter(pOuter)
   {
   }
   
   cAIProtoCombat * const m_pOuter;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAICbatEvGen
//

class cAICbatEvGen : public cAITask, public cAIProtoCombatComponent
{
public:
   cAICbatEvGen(tAIID ai, cAI * aiPtr, cAIProtoCombat * pOuter);
   virtual ~cAICbatEvGen();

   void Cycle();

private:
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAICbatCtx
// 

class cAICbatCtx : public cAICtx, public cAIProtoCombatComponent
{
public:
   cAICbatCtx(tAIID ai, cAI * aiPtr, cAIProtoCombat * pOuter);
   virtual ~cAICbatCtx();

   BOOL DoesAcceptEvent(const sAIEvent& event);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

private:
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAICbatMev
//

class cAICbatMev  : public cAIHighLevelMev, public cAIProtoCombatComponent
{
public:
   cAICbatMev(tAIID ai, cAIMoveCoord *pCoord, cAI * aiPtr, cAIProtoCombat * pOuter);
   virtual ~cAICbatMev();

   int PreCycle();

   BOOL ReEvaluateSuggestion(const sAIMoveSuggestion &suggestion);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

};

///////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__AIKIKASS_H */
