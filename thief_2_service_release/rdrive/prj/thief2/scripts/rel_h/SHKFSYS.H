/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkfsys.h 1.5 1999/04/02 12:08:12 Justin Exp $

#ifndef __SHKFSYS_H
#define __SHKFSYS_H

#include <shknet.h>

void ShockFrobsysInit(void);
void ShockFrobsysTerm(void);
void ShockDoFrob(bool in_inv);

// Returns TRUE iff we're waiting for the host to reply to some frob
// requests:
BOOL ShockFrobPending();

#endif
