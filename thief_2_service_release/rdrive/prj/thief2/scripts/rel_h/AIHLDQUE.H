/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aihldque.h 1.2 1998/01/14 03:04:26 TOML Exp $
//
//

#ifndef __AIHLDQUE_H
#define __AIHLDQUE_H

#include <aitype.h>

#pragma once
#pragma pack(4)

//////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIHldQueue
//
// High Level Destinations are destinations which the Hld
// move evalualator pathfinds to.  It is the way the AI
// moves to a "distant" location.
//
// The queue records various Hld's as they are created from all around
// the AI code. Each location in the code should have its own
// eAIHldType.
//
// Generally, that section of code should be required to
// KillHLDs of its type periodically (probably right
// before it adds a new one).  GetHighestPriorityHLD
// returns the highest priority (with its own version
// of subprioritization for equal priority Hlds) at
// any given time; this is the current "distant"
// goal of the AI
//

const int kAIHldQueueMax = 10;

class cAIHldQueue
{
public:
   cAIHldQueue(cAI * pAI);

   BOOL GetHighestPriorityHLD(sAIHld &hld);
   BOOL AddHLD(const sAIHld &newHLD);
   BOOL GetHLD(eAIHldType ofType, sAIHld &hld);
   void KillHLDs(eAIHldType ofType);
   void KillHLDs();
   void KillHighestPriorityHLD();

   void Read(tAIReadWriteFunc pfnReadWrite);
   void Write(tAIReadWriteFunc pfnReadWrite);

private:
   int    m_HighestHld;
   BOOL   m_fHighestHldInvalid;
   cAI *  m_pAI;
   sAIHld m_Hlds[kAIHldQueueMax];

   int GetSubPriorityLevel(eAIHldType type);
};

///////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__AIHLDQUE_H */
