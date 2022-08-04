/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkwepsc.h 1.3 1999/04/07 13:43:43 JON Exp $
//
// psi script stuff
//

#ifndef __SHKWEPSC_H
#define __SHKWEPSC_H

#include <scrptmsg.h>
#include <engscrpt.h>

#include <fix.h>

///////////////////////////////////////////////////////////////////////////////
//
// SERVICES
//

DECLARE_SCRIPT_SERVICE(ShockWeapon, 0x213)
{
   STDMETHOD_(void, SetWeaponModel)(const object ref obj) PURE;
   STDMETHOD_(object, GetWeaponModel)(void) PURE;

   STDMETHOD_(object, TargetScan)(object projectile) PURE;
   STDMETHOD_(void, Home)(object projectile, object target) PURE;

   STDMETHOD_(void, DestroyMelee)(const object ref obj) PURE;
};

#endif /* !__SHKWEPSC_H */
