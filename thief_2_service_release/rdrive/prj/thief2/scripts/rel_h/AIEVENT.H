/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aievent.h 1.17 1998/02/23 10:44:42 TOML Exp $
//
// AI EVENTS
//
// AI Events represent basic state changes in the world, such as a new jab
// beginning by the opponents sword, a new arrow flying through the air,
// the ceiling is falling in, etc.
//
// AI Events are created by the Event Generators and various Cortex Tasks,
// at the beginning of each AI's frame, stored in the cAIEvents during
// the frame, and then distributed by the Movement Coordinator and
// the Cortex Coordinator during the frame to be used by the
// Movement & Biped Evaluators to make their suggestions.
//
// IMPORTANCE NOTE: When adding an event type, YOU MUST update the
// eventTypeCutOffChart in aievent.c
//

#ifndef __AIEVENT_H
#define __AIEVENT_H

#pragma once
#pragma pack(4)

///////////////////////////////////////////////////////////////////////////////

#include <limits.h>

#include <dlist.h>

#include <aitype.h>
#include <fltang.h>

///////////////////////////////////////////////////////////////////////////////
//
// Constants
//

///////////////////////////////////////
//
// AI events
//
// IMPORTANCE NOTE: When adding an event type, YOU MUST update the
// eventTypeCutOffChart in aievent.c
//

enum eAIEventType
{
#if 0
   kAIE_Null,
#endif
   // High level state related
   kAIE_HighLevMode,
#if 0
   kAIE_HighLevCombatGoal,

   // Physics & combat related
   kAIE_MySword, // never generated
   kAIE_EnemySword,
   kAIE_Biped,
   kAIE_Physics,
   kAIE_Damage,
   kAIE_HeardSound,
#endif
   
   // High Level Destination
   kAIE_HighLevDest,

   // Link related
   // These are in the same order as their relations in gAIRelationIDs
   kAIE_BaseLink,
   kAIE_AttackLink = kAIE_BaseLink,
#if 0
   kAIE_DefendLink,
   kAIE_FollowLink,
   kAIE_FleeLink,
#endif
   kAIE_SenseLink,
   kAIE_FastObjLink,
   kAIE_PatrolLink,
   kAIE_CurrentPatrolLink,

   kNumEventTypes
};

typedef ulong tAIEventType;

///////////////////////////////////////

enum eAISwordEventType
{
   kAISE_Slash,
   kAISE_Parry,
   kSwordEventTypeIntMax=0xffffffff // force it use an int
};

///////////////////////////////////////////////////////////////////////////////
//
// Miscellaneous types
//

///////////////////////////////////////
//
// Link event type
//

struct sAILinkEventType
{
   BOOL         justDestroyed;
   BOOL         justCreated;
   LinkID       linkJustCreated; // if justCreated == TRUE
};

///////////////////////////////////////

struct sAISwordEventInfo
{
   ObjID          swordOwner;
   eAISwordEventType type;
};

///////////////////////////////////////////////////////////////////////////////
//
// STRUCT: sAIEvent
//

struct sAIEvent
{
   tAIEventType         type;
   sAIPoint             location; // i would like to put this in the union but can't because it has a constructor
   union
   {
      sAILinkEventType  linkInfo;
      ObjID             damager;
      sAISwordEventInfo swordInfo;
   };
};


///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIEvent
//
// Record keeping class private to cAIEvents
//
class cAIEvents;
class cAIEvent;
typedef cDList<cAIEvent, 1>     cAIEventList;
typedef cDListNode<cAIEvent, 1> cAIEventListNode;

class cAIEvent : public sAIEvent, public cAIEventListNode
{
   cAIEvent(const sAIEvent & event)
   {
      memcpy(((sAIEvent *)this), &event, sizeof(sAIEvent)); // side cast
   }

   friend class cAIEvents;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIEvents
//
// The cAIEvents is responsible for storing events generated
// by the AI's.  Events can be created "pre-cycle" before AI
// is executing its frame, so every AI needs to be able to
// store events for itself.  However, events are not expected
// to remain in the pool between cycles, so RemoveAllEvents
// should be called at the end of each AI's frame.
//

class cAIEvents
{
public:
   cAIEvents();
   ~cAIEvents()
   {
      RemoveAll();
   }

   // Add one event to the event heap.
   void Add(const sAIEvent & event);

   const sAIEvent * GetFirst();
   const sAIEvent * GetNext(const sAIEvent * pLastEvent);

   // Clears the events from this AI from the heap.
   void RemoveAll();

   // Prints all the events currently in the pool for a give AI.
   void PrintEvents();

private:

#ifdef DEBUG
   void ValidateAdd(const sAIEvent & event);
#endif

   cAIEventList m_List;

};

///////////////////////////////////////

inline const sAIEvent * cAIEvents::GetFirst()
{
   return m_List.GetFirst();
}

///////////////////////////////////////

inline const sAIEvent * cAIEvents::GetNext(const sAIEvent * pLastEvent)
{
   cAIEvent * pEvent = (cAIEvent *) pLastEvent;
   return pEvent->GetNext();
}

///////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__AIEVENT_H */
