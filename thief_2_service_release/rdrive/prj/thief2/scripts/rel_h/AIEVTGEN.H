/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aievtgen.h 1.11 1998/01/21 14:34:23 TOML Exp $
//
//

#ifndef __AIEVTGEN_H
#define __AIEVTGEN_H

#pragma once

///////////////////////////////////////////////////////////////////////////////

#include <aitask.h>

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAITrackAIsEvGen
//

class cAITrackAIsEvGen : public cAITask
{
public:
   cAITrackAIsEvGen(tAIID ai, cAI * aiPtr);
   ~cAITrackAIsEvGen();

   void Cycle();
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAITrackPlayerEvGen
//

class cAITrackPlayerEvGen : public cAITask
{
public:
   cAITrackPlayerEvGen(tAIID ai, cAI * aiPtr);
   ~cAITrackPlayerEvGen();

   void Cycle();
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIFastObjWatchEvGen
//

#if 0
class cAIFastObjWatchEvGen : public cAITask
{
public:
   cAIFastObjWatchEvGen(tAIID ai, cAI * aiPtr);
   ~cAIFastObjWatchEvGen();

   void Cycle();
};
#endif


///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIEffModeEvGen
//
// The cAIEffModeEvGen chooses when to go from kNonCombatMode
// to kAIHLM_Efficiency, and back again.
//

class cAIEffModeEvGen : public cAITask
{
public:
   cAIEffModeEvGen(tAIID ai, cAI * aiPtr);
   ~cAIEffModeEvGen() {}

   void Cycle();

private:
   ulong m_lastTeleportTime;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIMoveProgWatchEvGen
//
// The progress watcher makes sure that the AI is actually
// moving successfully towards its goal, and isn't
// stuck bouncing against a wall or something.
//

class cAIMoveProgWatchEvGen : public cAITask
{
public:
   cAIMoveProgWatchEvGen(tAIID ai, cAI * aiPtr);
   ~cAIMoveProgWatchEvGen() {}

   ulong GetTimeSinceLastProgress();

   // Make sure the progress watcher that we have a new destination goal
   void NotifyOfNewMoveDestinationGoal();

   void Cycle();

private:
   // last location the AI was thought to be making progress.
   sAIPoint m_lastProgPt;

   // last time wh changed lastProgressPoint
   ulong    m_lastProgTime;

};

///////////////////////////////////////////////////////////////////////////////
#if 0
class cAIEnemySwordWatchEvGen : public cAITask
{
public:
   cAIEnemySwordWatchEvGen(tAIID ai, cAI * aiPtr);
   ~cAIEnemySwordWatchEvGen();

   void Cycle();
};

class cAIEnemyShieldWatchEvGen : public cAITask
{
public:
   cAIEnemyShieldWatchEvGen(tAIID ai, cAI * aiPtr);
   ~cAIEnemyShieldWatchEvGen();

   void Cycle();
};

class cAIEnemyBipedWatchEvGen : public cAITask
{
public:
   AIEnemyBipedWatcherEvtGen(tAIID ai, cAI * aiPtr);
   ~AIEnemyBipedWatcherEvtGen();

   void Cycle();
};

#endif

#endif /* !__AIEVTGEN_H */
