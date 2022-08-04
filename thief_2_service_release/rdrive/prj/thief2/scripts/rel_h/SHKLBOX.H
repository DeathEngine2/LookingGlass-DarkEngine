/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shklbox.h 1.2 1999/01/19 17:21:02 XEMU Exp $

#ifndef __SHKLBOX_H
#define __SHKLBOX_H

extern "C" 
{
#include <event.h>
}

EXTERN void ShockLetterboxDraw(void);
EXTERN void ShockLetterboxInit(int which);
EXTERN void ShockLetterboxTerm(void);

EXTERN void ShockLetterboxSet(BOOL camera);
#endif