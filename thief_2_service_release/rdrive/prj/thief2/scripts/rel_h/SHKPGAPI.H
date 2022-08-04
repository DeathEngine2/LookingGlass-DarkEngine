/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkpgapi.h 1.10 1999/05/21 20:01:24 JON Exp $

#ifndef __SHKPGAPI_H
#define __SHKPGAPI_H

#include <comtools.h>
#include <objtype.h>
#include <simtime.h>

//------------------------------------
// Player Gun API
//

F_DECLARE_INTERFACE(IPlayerGun); 

#undef INTERFACE
#define INTERFACE IPlayerGun

DECLARE_INTERFACE_(IPlayerGun,IUnknown)
{
   DECLARE_UNKNOWN_PURE(); 

   STDMETHOD(Init)(THIS_) PURE;
   STDMETHOD(GameInit)(THIS_) PURE;
   STDMETHOD(GameTerm)(THIS_) PURE;
   // Set new gun and raise it
   STDMETHOD(Set)(THIS_ ObjID objID) PURE;
   // Set the gun already raised, no activation sound
   STDMETHOD(SetRaised)(THIS_ ObjID objID) PURE;
   // Get current gun
   STDMETHOD_(ObjID, Get)(THIS_) PURE;
   STDMETHOD_(ObjID, GetHand)(THIS_) PURE;
   // Update
   STDMETHOD(Frame)(THIS_ tSimTime timeDelta) PURE;
   // Fire gun
   STDMETHOD(PullTrigger)(THIS_) PURE;
   STDMETHOD(ReleaseTrigger)(THIS_) PURE;
   // Gun state changes
   STDMETHOD(Raise)(THIS_) PURE;
   STDMETHOD(Lower)(THIS_) PURE;
   STDMETHOD(Off)(THIS_) PURE;
   STDMETHOD(Load)(void) PURE; 
   // Gun state queries
   STDMETHOD_(BOOL, IsReloading)(THIS_) const PURE;
   STDMETHOD_(BOOL, IsTriggerPulled)(THIS_) const PURE;
   // Queries
   // does this ammo obj match the type last loaded into the gun?
   STDMETHOD_(BOOL, MatchesCurrentAmmo)(THIS_ ObjID ammoID) PURE;
};

#undef INTERFACE

void ShockPlayerGunCreate(void);

#endif