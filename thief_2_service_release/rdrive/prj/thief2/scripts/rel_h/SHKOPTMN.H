/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkoptmn.h 1.1 1999/02/22 13:05:23 mahk Exp $

#ifndef __SHKOPTMN_H
#define __SHKOPTMN_H

//////////////////////////////////////////////////////////////
// OPTIONS PANEL MODE FOR SHOCK 2
//

EXTERN void SwitchToShockOptionsMode(BOOL push); 
EXTERN const struct sLoopInstantiator* DescribeShockOptionsMode(void); 


EXTERN void ShockOptionsMenuInit();
EXTERN void ShockOptionsMenuTerm();


#endif // __SHKOPTMN_H
