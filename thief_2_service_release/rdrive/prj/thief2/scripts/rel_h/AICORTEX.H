/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aicortex.h 1.16 1998/01/21 14:34:18 TOML Exp $
//
//

#ifndef __AICORTEX_H
#define __AICORTEX_H

#pragma once

///////////////////////////////////////////////////////////////////////////////

#include <aitask.h>
#include <aievent.h>

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAICtx
//

class cAICtx : public cAITask
{
public:
   cAICtx(eAITaskType type, tAIID ai, cAI * aiPtr);
   ~cAICtx() {}

   // Does he accept this event type?
   virtual BOOL DoesAcceptEvent(const sAIEvent& event) = 0;

   // Based on this event, generate movement suggestion to
   // the movement coordinate.
   virtual void RespondToEvent(const sAIEvent &event) = 0;

   // Based on Time, do your thing
   virtual void Cycle() = 0;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIPatrolHldCtx
//

#define NUM_PATROL_PTS 4

class cAIPatrolHldCtx : public cAICtx
{
public:
   cAIPatrolHldCtx(tAIID ai, cAI * aiPtr);
   ~cAIPatrolHldCtx() {}

   BOOL GetPatrolling();
   void StartPatrolling();
   void StopPatrolling();

   BOOL DoesAcceptEvent(const sAIEvent& event);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

   BOOL m_fLastPatrolling; 
   
private:
   void GoToNextPatrolPt();
   void SetPatrolling(BOOL patrolling);
   BOOL GetCurrentPatrolObj(ObjID &id);

};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIDefendHldCtx
//

#if 0
class cAIDefendHldCtx : public cAICtx
{
public:
   cAIDefendHldCtx(tAIID ai, cAI * aiPtr);
   ~cAIDefendHldCtx() {}

   BOOL DoesAcceptEvent(const sAIEvent& event);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();
};
#endif

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIFollowHldCtx
//

#if 0
class cAIFollowHldCtx : public cAICtx
{
public:
   cAIFollowHldCtx(tAIID ai, cAI * aiPtr);
   ~cAIFollowHldCtx() {}

   BOOL DoesAcceptEvent(const sAIEvent& event);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();
};
#endif

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIFleeHldCtx
//

#if 0
class cAIFleeHldCtx : public cAICtx
{
public:
   cAIFleeHldCtx(tAIID ai, cAI * aiPtr);
   ~cAIFleeHldCtx() {}

   void StartFleeing(BOOL forever) {m_fFleeing = TRUE; m_fFleeingForever = forever;}
   void StopFleeing()          {m_fFleeing = FALSE; m_fFleeingForever = FALSE;}

   BOOL DoesAcceptEvent(const sAIEvent& event);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

private:
   // @TBD (toml 09-25-97): ever hear of bit flags?
   BOOL m_fFleeing;        // am I fleeing right now?
   BOOL m_fFleeingForever; // am I fleeing forever, or just until safe?
};
#endif

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIHighCombatCtx
//

class cAIHighCombatCtx : public cAICtx
{
public:
   cAIHighCombatCtx(tAIID ai, cAI * aiPtr);
   ~cAIHighCombatCtx() {}

   BOOL DoesAcceptEvent(const sAIEvent& event);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAISoundCtx
//

class cAISoundCtx : public cAICtx
{
public:
   cAISoundCtx(tAIID ai, cAI * aiPtr);
   ~cAISoundCtx() {}

   BOOL DoesAcceptEvent(const sAIEvent& event);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__AICORTEX_H */
