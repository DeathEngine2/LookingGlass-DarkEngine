/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aitask.h 1.14 1997/10/08 12:48:20 TOML Exp $
//
//

#ifndef __AITASK_H
#define __AITASK_H

#pragma once

#include <aitype.h>
#include <aitsktyp.h>

#pragma pack(4)

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAITask
//
// The Task class is the root of all tasks.
// It is a pure virtual class; you must override the Cycle method.
//

class cAI;

class cAITask
{
public:
   cAITask(eAITaskType type, tAIID ai, cAI * aiPtr);
   virtual ~cAITask() {}

   void Suspend();
   void UnSuspend();
   BOOL IsSuspended()              {return m_fSuspended;}

   void SetIdlePeriod(long idlePeriod) {m_idlePeriod = idlePeriod;}
   long GetIdlePeriod()            {return m_idlePeriod;}
   eAITaskType GetTaskType()              {return m_type;}
   static void GetTaskName(eAITaskType type, char* name);

   void Idle();
   void ForceCycle();
   void MakeReadyToCycle()         {m_nextTimeToIdle = 0;}

   virtual void Cycle() = 0; // Override this method in subclasses

   eAITaskType GetTaskID()                {return m_type;}
//   cAI * MyAI()                     {return m_pAI;}

protected:
   const tAIID m_AIID;                        // who is my (owner) ai?
   cAI * const m_pAI;                         // who is my (owner) ai?

private:
   long        m_nextTimeToIdle, m_idlePeriod;// idle stuff
   eAITaskType m_type;                        // what is this task?
   BOOL        m_fSuspended;                  // have I been suspended?

};

///////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__AITASK_H */
