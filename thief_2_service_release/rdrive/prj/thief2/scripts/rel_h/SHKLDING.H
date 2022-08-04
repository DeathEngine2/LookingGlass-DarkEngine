/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shklding.h 1.3 1999/05/31 15:43:29 Justin Exp $

#ifndef __SHKLDING_H
#define __SHKLDING_H

////////////////////////////////////////////////////////////
// SHOCK LOADING SCREEN API
//

EXTERN void ShockLoadingInit(); 
EXTERN void ShockLoadingTerm(); 

// Nasty little hack we have to expose, to prevent recursive level trans
// in multiplayer:
EXTERN BOOL gbShockTransporting;

EXTERN void SwitchToShockInitGame(BOOL push); 
typedef struct sLoopInstantiator sLoopInstantiator; 
EXTERN sLoopInstantiator* DescribeShockInitGameMode(void); 

#endif // __SHKLDING_H
