/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkpsisc.h 1.3 1999/02/21 20:18:36 XEMU Exp $
//
// psi script stuff
//

#ifndef __SHKPSSCR_H
#define __SHKPSSCR_H

#include <scrptmsg.h>
#include <simtime.h>
#include <engscrpt.h>

// argh
enum ePsiPowers;

///////////////////////////////////////////////////////////////////////////////
//
// SERVICES
//

///////////////////////////////////////
//
// Game system and interface support functions
//

DECLARE_SCRIPT_SERVICE(ShockPsi, 0x1d7)
{
   STDMETHOD(OnDeactivate)(ePsiPowers power) PURE;
   STDMETHOD_(tSimTime, GetActiveTime)(ePsiPowers power) PURE;
   STDMETHOD_(BOOL, IsOverloaded)(ePsiPowers power) PURE;
};

#endif /* !__SHKPSSCR_H */
