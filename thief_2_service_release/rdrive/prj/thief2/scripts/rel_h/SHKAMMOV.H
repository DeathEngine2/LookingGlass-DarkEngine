/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkammov.h 1.6 1999/02/26 13:32:15 XEMU Exp $

#ifndef __SHKAMMO_H
#define __SHKAMMO_H

extern "C" 
{
#include <event.h>
}

EXTERN void ShockAmmoDraw(void);
EXTERN void ShockAmmoInit(int which);
EXTERN void ShockAmmoTerm(void);
EXTERN bool ShockAmmoHandleMouse(Point pt);
EXTERN bool ShockAmmoCheckTransp(Point pt);
EXTERN void ShockAmmoRefreshButtons(void);
EXTERN void ShockAmmoStateChange(int which);

EXTERN void ShockAmmoReload(void);
EXTERN void ShockAmmoChangeTypes(void);
EXTERN void ShockAmmoPsiLevel(int button);

#endif