/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aimoveev.h 1.3 1998/01/21 14:34:17 TOML Exp $
//
//
//

#ifndef __AIMOVEEV_H
#define __AIMOVEEV_H

#include <fltang.h>
#include <aitask.h>

#pragma once
#pragma pack(4)

struct sAIMoveSuggestion;
struct sAIEvent;

class cAIPath;

////////////////////////////////////////////////////////////////////////////
//
// MOVEMENT EVALUATOR TASKS
//
// Evaluators are owned by their coordinator (described in next section).
// There is one of each type of evaluator for each AI (and one movement
// coordinator for each AI as well).  The evaluators are responsible for
// looking at events and at the world and making movement suggestions
// to their Movement Coordinator.
//
// PROCESS FOR CREATING & ADDING NEW EVALUATORS:
//
// 1. Create the evaluator subclass of the cAIMoveEvaluator class.
// 2. Add the appropriate lines to cAITask.h because you need a new
//    task constant (which means modifying stuff in cAITask.cc)
// 3. Add the variable to the cAIMoveCoord class.
// 4. Add the appropriate lines the following methods in the
//    cAIMoveCoord class: constructor, destructor, DistributeOldSuggestions,
//                           DestributeEventsToEvaluators, IdleEvaluators,
//


///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIMoveEvaluator
//

class cAIMoveCoord;

class cAIMoveEvaluator : public cAITask
{
public:
   cAIMoveEvaluator(eAITaskType type, tAIID ai, cAIMoveCoord *owner, cAI * aiPtr);
   ~cAIMoveEvaluator() {}

   // AIMoveEvaluators make sure all of their suggestions are
   // removed when they are suspended.
   void Suspend();

   cAIMoveCoord * MyCoord() { return m_pCoord; }

   // Based on this event, generate movement suggestion to
   // the movement coordinate.
   virtual void RespondToEvent(const sAIEvent &event) = 0;

   // Suggestions stay alive for more than one cycle, so this method
   // re-evaluates the move eval's previous suggestions for
   // continued existence and to update bias values.  Returns
   // TRUE when the suggestion should be killed, FALSE if it
   // should be kept alive.
   virtual BOOL ReEvaluateSuggestion(const sAIMoveSuggestion &suggestion) = 0;

   // Based on Time, generate movement suggestions to the movement coordinate
   virtual void Cycle() = 0;

   // Misc Helpers for Subclasses.
   int ComputeSuggestionBias(int activationRating);

private:
   cAIMoveCoord * m_pCoord;

};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIHighLevelMev
//
// HighLevelMoveEvaluators are a special brand of Move Evaluators
// which only get idled by the movement coordinator
// if they are the highest priority level high level
// move evals.
//
// The PreCycle is meant to allow the high level
// move evals to do something every cycle the move
// coord gets called.  It should remove suggestions
// previously made by the evaluator and maintenance
// and code required to generate the evaluator's current
// priority level, which must be returned.  Returning
// zero means that the evaluator is in fact inactive.
//

class cAIHighLevelMev : public cAIMoveEvaluator
{
   public:
   cAIHighLevelMev(eAITaskType type, tAIID ai, cAIMoveCoord *owner, cAI * aiPtr);
   ~cAIHighLevelMev() {}

   virtual int PreCycle() = 0;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIHldMev
//
// Reponsible for making the AI moves towards the external
//

class cAIHldMev : public cAIHighLevelMev
{
public:
   cAIHldMev(tAIID ai, cAIMoveCoord *owner, cAI * aiPtr);
   ~cAIHldMev();

   int  PreCycle();

   const cAIPath * GetCurrentPath() { return m_pPath;}
   BOOL GetCurrentPathTargetLocation(sAIPoint * p);

   BOOL ReEvaluateSuggestion(const sAIMoveSuggestion &suggestion);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

private:
   sAIHld    m_curGoal;
   BOOL      m_fHeadingStraightToDest; // following path OR moving directly to m_curGoal.destination
   cAIPath * m_pPath;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAILoiterMev
//

class cAILoiterMev : public cAIHighLevelMev
{
public:
   cAILoiterMev(tAIID ai, cAIMoveCoord *owner, cAI * aiPtr);
   ~cAILoiterMev();

   int PreCycle();

   BOOL ReEvaluateSuggestion(const sAIMoveSuggestion &suggestion);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

private:
   floatang m_dir;
   ulong    m_nextSwitch;
   int      m_speed;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIAvoidFriendsMev
//
// Make sure we don't get too close to our friends, we might hurt them
// or look silly or something.
//

class cAIAvoidFriendsMev : public cAIMoveEvaluator
{
public:
   cAIAvoidFriendsMev(tAIID ai, cAIMoveCoord *owner, cAI * aiPtr);
   ~cAIAvoidFriendsMev();

   BOOL ReEvaluateSuggestion(const sAIMoveSuggestion &suggestion);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIWallsCliffsMev
//
// Responsible for making sure the AI doesn't run into walls
//

const int AVOID_WALL_CLIFF_LIST_SIZE = 20;

class cAIWallsCliffsMev : public cAIMoveEvaluator
{
public:
   cAIWallsCliffsMev(tAIID ai, cAIMoveCoord *owner, cAI * aiPtr);
   ~cAIWallsCliffsMev() {}

   BOOL ReEvaluateSuggestion(const sAIMoveSuggestion &suggestion);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

private:
   // the terrain sample results...
   sAIPoint m_lastSamplePt;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAICliffPredictMev
//

class cAICliffPredictMev : public cAIMoveEvaluator
{
public:
   cAICliffPredictMev(tAIID ai, cAIMoveCoord *owner, cAI * aiPtr);
   ~cAICliffPredictMev() {}

   BOOL ReEvaluateSuggestion(const sAIMoveSuggestion &suggestion);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

private:
   sAIPoint m_lastSamplePt;
   BOOL     m_fDanger;
   sAIPoint m_dangerPt;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIDodgeFastObjsMev
//

class cAIDodgeFastObjsMev : public cAIMoveEvaluator
{
public:
   cAIDodgeFastObjsMev(tAIID ai, cAIMoveCoord *owner, cAI * aiPtr) : cAIMoveEvaluator(kDodgeFastMovingObjectsMoveEval, ai, owner, aiPtr) {}
   ~cAIDodgeFastObjsMev() {}

   BOOL ReEvaluateSuggestion(const sAIMoveSuggestion &suggestion);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

private:
//   void CheckLocationAndSuggest(sAIPoint p);

};

////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__AIMOVEEV_H */
