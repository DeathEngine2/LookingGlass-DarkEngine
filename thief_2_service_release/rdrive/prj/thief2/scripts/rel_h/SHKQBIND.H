/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkqbind.h 1.1 1999/04/07 22:45:58 XEMU Exp $

#ifndef __SHKQBIND_H
#define __SHKQBIND_H

#define MAX_BIND  12

typedef enum ePsiPowers;

EXTERN int ShockBindVal(ePsiPowers power);
EXTERN void ShockQuickbindInit(void);

#endif