/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkaisc.h 1.5 1999/05/03 13:03:09 JON Exp $
//
// AI script stuff
//

#ifndef __SHKAISC_H
#define __SHKAISC_H

#include <scrptmsg.h>
#include <engscrpt.h>

///////////////////////////////////////////////////////////////////////////////
//
// SERVICES
//

DECLARE_SCRIPT_SERVICE(ShockAI, 0x21b)
{
   STDMETHOD_(BOOL, Stun)(object who, string startTags, string loopTags, float sec) PURE;
   STDMETHOD_(BOOL, IsStunned)(object who) PURE;
   STDMETHOD_(BOOL, UnStun)(object who) PURE;

   STDMETHOD_(BOOL, Freeze)(object who, float sec) PURE;
   STDMETHOD_(BOOL, IsFrozen)(object who) PURE;
   STDMETHOD_(BOOL, UnFreeze)(object who) PURE;

   STDMETHOD_(void, NotifyEnterTripwire)(object who, object what) PURE;
   STDMETHOD_(void, NotifyExitTripwire)(object who, object what) PURE;
   STDMETHOD_(BOOL, ObjectLocked)(object obj) PURE;   // doesn't really belong here, but used by AI

   STDMETHOD_(void, ValidateSpawn)(object creature, object spawnMarker) PURE;  // again, not really belonging here, but whatever
};

#endif /* !__SHKAISC_H */
