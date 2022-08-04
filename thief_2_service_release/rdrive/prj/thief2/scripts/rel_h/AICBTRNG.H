/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/ai/RCS/aicbtrng.h 1.4 1998/05/26 04:14:14 CCAROLLO Exp $
//
//
//

#ifndef __AICBTRNG_H
#define __AICBTRNG_H

#include <aibasabl.h>
#include <aiutils.h>

#include <relation.h>

#pragma once
#pragma pack(4)

extern IRelation * g_pAIRetreatPtDibsLinks;
extern IRelation * g_pAIVantagePtDibsLinks;

///////////////////////////////////////////////////////////////////////////////
//
// Publish ability and all associated link and property types
//

BOOL AIInitCombatRangedAbility();
BOOL AITermCombatRangedAbility();


///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAICombatRanged
//

class cAICombatRanged : public cAIAbility
{
public:
   STDMETHOD_(const char *, GetName)();

   // Initialize/Terminate the component
   STDMETHOD_(void, Init)();
   STDMETHOD_(void, Term)();

   // Notifications
   STDMETHOD_(void, OnUpdateProperties)(eAIPropUpdateKind kind);
   STDMETHOD_(void, OnGoalProgress)(const cAIGoal *);
   STDMETHOD_(void, OnActionProgress)(IAIAction *);

   // Ability flow
   STDMETHOD (SuggestGoal)(cAIGoal *, cAIGoal **);
   STDMETHOD (SuggestActions)(cAIGoal * pGoal, const cAIActions & previous, cAIActions * pNew);

protected:
   void SetShouldCombatRangedFromProperty();
   BOOL ShouldCombatRanged();

   ObjID    GetProjectile();
   mxs_real GetProjectileRange(ObjID projectile);

   void ResetFiringInterval(eAITimerPeriod ms = kAIT_Max);
   BOOL ReadyToFire();
   BOOL WantsToFire();

   void SetAdvanceDesire(short value);
   void SetRetreatDesire(short value);
   void SetVantageDesire(short value);

   short GetAdvanceDesire() const;
   short GetRetreatDesire() const;
   short GetVantageDesire() const;

   BOOL Advance(cAIActions *pNew);
   BOOL Retreat(cAIActions *pNew);
   BOOL Vantage(cAIActions *pNew);

   enum
   {
      kShouldCombatRanged = kBaseFirstAvailFlag,

      kCombatRangedFirstAvailFlag =  (kShouldCombatRanged << 1)
   };

private:

   cAITimer m_FiringInterval;        // Timer for minimum firing delay
   cAITimer m_FiringUpdateInterval;  // Timer for checking if we want to fire
   cAITimer m_MoveUpdateInterval;    // Timer for checking were we want to go

   short m_AdvanceDesire;  // How much we want to advance on target
   short m_RetreatDesire;  // How much we want to retreat and take cover
   short m_VantageDesire;  // How much we want to go to a vantage point

   BOOL  m_Moving;  // Are we currently en route to a marker?
   BOOL  m_Firing;  // Are we currently in the act of firing?
};

///////////////////////////////////////////////////////////////////////////////

inline BOOL cAICombatRanged::ShouldCombatRanged()
{
   return (m_flags & kShouldCombatRanged);
}

///////////////////////////////////////////////////////////////////////////////

inline void cAICombatRanged::SetAdvanceDesire(short value)
{
   Assert_((value >= 0) && (value <= 10));

   m_AdvanceDesire = value;
   m_RetreatDesire = 0;
   m_VantageDesire = 0;
}

////////////////////////////////////////

inline void cAICombatRanged::SetRetreatDesire(short value)
{
   Assert_((value >= 0) && (value <= 10));

   m_AdvanceDesire = 0;
   m_RetreatDesire = value;
   m_VantageDesire = 0;
}

////////////////////////////////////////

inline void cAICombatRanged::SetVantageDesire(short value)
{
   Assert_((value >= 0) && (value <= 10));

   m_AdvanceDesire = 0;
   m_RetreatDesire = 0;
   m_VantageDesire = value;
}

////////////////////////////////////////

inline short cAICombatRanged::GetAdvanceDesire() const
{
   return m_AdvanceDesire;
}

////////////////////////////////////////

inline short cAICombatRanged::GetRetreatDesire() const
{
   return m_RetreatDesire;
}

////////////////////////////////////////

inline short cAICombatRanged::GetVantageDesire() const
{
   return m_VantageDesire;
}

///////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__AICBTRNG_H */




