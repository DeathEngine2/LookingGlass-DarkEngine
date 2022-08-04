/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/shkplpup.h 1.1 1998/02/24 14:43:24 JON Exp $

#ifndef __SHKPLPUP_H
#define __SHKPLPUP_H

#include <objtype.h>

ObjID PlayerPuppetCreate(const char *pModelName);
void PlayerPuppetDestroy(void);

#endif