/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/motdmnge.h 1.2 1997/10/29 18:37:14 kate Exp $

#ifndef __MOTDMNGE_H
#define __MOTDMNGE_H

EXTERN void MotDmngeInit(int num_motions);
EXTERN void MotDmngeClose();
EXTERN void MotDmngeLock(int mot_num);
EXTERN void MotDmngeUnlock(int mot_num);


#endif
