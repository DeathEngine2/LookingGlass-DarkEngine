/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shktluct.h 1.1 1999/03/31 14:06:00 XEMU Exp $

#ifndef __SHKTLUCT_H
#define __SHKTLUCT_H

EXTERN void ShockTlucTextDraw(void);
EXTERN void ShockTlucTextInit(int which);
EXTERN void ShockTlucTextTerm(void);

EXTERN void ShockTlucTextAdd(char *name, char *table, int offset);

#endif