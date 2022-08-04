/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aibiped.h 1.12 1998/02/03 20:42:28 TOML Exp $
//
//

#ifndef __AIBIPED_H
#define __AIBIPED_H

#pragma once

///////////////////////////////////////////////////////////////////////////////

#include <aimisc.h>
#include <aitask.h>
#include <aievent.h>
#include <limits.h>

///////////////////////////////////////////////////////////////////////////////
//
// Forward declarations
//

class cAIBipedCoord;
class cAIBipedEval;

/////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIBipedEval
//
// cAIBipedEval provides the API for all evaluators.  It is a virtual
// class, subclasses must define the DoesAcceptEvent, RespondToEvent,
// and Cycle methods to create a valid class.
//
// The job of the biped evaluator is to respond to events and cycle through
// time creating suggestions when appropriate to its nature for the
// biped coordinator to use in making the AI's biped goal.
//

class cAIBipedEval : public cAITask
{
public:
   cAIBipedEval(eAITaskType type, tAIID ai, cAIBipedCoord *coordinator, cAI * aiPtr);
   ~cAIBipedEval() {}

   cAIBipedCoord * MyCoord() {return m_pCoord;}

   // Based on this event, generate biped suggestion
   // to the biped coordinator
   virtual void RespondToEvent(const sAIEvent &event) = 0;

private:
   cAIBipedCoord * m_pCoord;
};

/////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIFireMissleBipEv
//

class cAIFireMissleBipEv : public cAIBipedEval
{
public:
   cAIFireMissleBipEv(tAIID ai, cAIBipedCoord *coordinator, cAI * aiPtr);

   void RespondToEvent(const sAIEvent &event);
   void Cycle();

private:
   ulong m_lastFire;
};

/////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIIdleGesturesBipEv
//

class cAIIdleGesturesBipEv : public cAIBipedEval
{
public:
   cAIIdleGesturesBipEv(tAIID ai, cAIBipedCoord *coordinator, cAI * aiPtr);
   ~cAIIdleGesturesBipEv();

   void RespondToEvent(const sAIEvent &event);
   void Cycle();

private:
   ulong m_next;
};

/////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAICombatBipEv
//

class cAICombatBipEv : public cAIBipedEval
{
public:
   cAICombatBipEv(tAIID ai, cAIBipedCoord *coordinator, cAI * aiPtr);
   ~cAICombatBipEv();

   void RespondToEvent(const sAIEvent &event);
   void Cycle();
};

/////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIBipedCoord
//
// @TBD (toml 09-27-97): the above evaluators should be either contained
// or simply not in this header
//

class cAIBipedCoord : public cAITask
{
public:
   cAIBipedCoord(tAIID ai, cAI * aiPtr);
   ~cAIBipedCoord();

   void Cycle(); // Set or Update the Biped Goal

   void RequestMotion(eAIMotionType motion);

   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

private:
   // Biped Evaluators
   cAIIdleGesturesBipEv * m_pIdleGesturesBipEv;
   cAIFireMissleBipEv *   m_pFireMissleBipEv;
   cAICombatBipEv *       m_pCombatBipEv;

   ulong                  m_aNextTimeMotionPlayable[kNumAIMotions];

   // Main Phases of the Biped Coordinator.
   void SuspendAndResumeEvaluators();
   void DestributeEventsToEvaluators();
   void IdleEvaluators();
   void UpdateBipedGoal();
   void UpdatePhysicsControls();
   void ExecuteBipedGoal();

};

/////////////////////////////////////////////////////////////////////////////

#endif /* !__AIBIPED_H */
