/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/motdesc.h 1.13 1998/05/20 20:15:52 kate Exp $

#ifndef __MOTDESC_H
#define __MOTDESC_H

#include <motion.h>
#include <motdbase.h>

EXTERN int MotDescNumMotions();
EXTERN BOOL MotDescNeckFixed(int index);
EXTERN char *MotDescGetName(int index);
EXTERN int MotDescNameGetNum(char *name);
EXTERN int MotDescBlendLength(int index);

#endif
