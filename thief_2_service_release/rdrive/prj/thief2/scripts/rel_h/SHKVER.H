/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkver.h 1.1 1999/02/03 17:27:16 XEMU Exp $

#ifndef __SHKVER_H
#define __SHKVER_H

#include <resapi.h>

EXTERN void ShockVersionInit(int which);
EXTERN void ShockVersionTerm(void);
EXTERN IRes *ShockVersionBitmap(void);

#endif