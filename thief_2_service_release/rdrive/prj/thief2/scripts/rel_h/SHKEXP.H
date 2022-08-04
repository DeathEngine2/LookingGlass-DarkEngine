/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkexp.h 1.2 1999/04/02 12:06:57 Justin Exp $
//
// Deal with adding experience points when needed
//

#ifndef __SHKEXP_H
#define __SHKEXP_H

#include <iobjsys.h>

// Give the player the specified number of experience points; display
// a message if specified. Note that this will send the experience points
// to all players, and may divide them up, depending on tunable params.
EXTERN void ShockAddExp(ObjID player, int amt, BOOL verbose);

// Startup and shutdown the system
EXTERN void ShockExpInit();
EXTERN void ShockExpTerm();

#endif // !__SHKEXP_H
