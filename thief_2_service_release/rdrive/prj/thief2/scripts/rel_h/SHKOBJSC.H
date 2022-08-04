/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkobjsc.h 1.1 1998/08/30 18:42:40 JON Exp $
//
// Object script stuff
//

#ifndef __SHKOBJSC_H
#define __SHKOBJSC_H

#include <scrptmsg.h>

#include <engscrpt.h>

///////////////////////////////////////////////////////////////////////////////
//
// SERVICES
//

///////////////////////////////////////
//
// Game system and interface support functions
//

DECLARE_SCRIPT_SERVICE(ShockObj, 0x1d9)
{
   STDMETHOD_(ObjID, FindScriptDonor)(ObjID objID, string name) PURE;
};

#endif /* !__SHKOBJSC_H */
