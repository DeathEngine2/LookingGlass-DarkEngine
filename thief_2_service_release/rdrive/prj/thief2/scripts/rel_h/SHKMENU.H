/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkmenu.h 1.1 1999/01/11 11:40:37 mahk Exp $
#pragma once  
#ifndef __SHKMENU_H
#define __SHKMENU_H

////////////////////////////////////////////////////////////
// SHOCK METAGAME MENUS
//

EXTERN void ShockMenusInit(void); 
EXTERN void ShockMenusTerm(void); 

//
// ShockMain menu 
//

EXTERN const struct sLoopInstantiator* DescribeShockMainMenuMode(void); 
EXTERN void SwitchToShockMainMenuMode(BOOL push); 

//
// Sim menu 
//

EXTERN const struct sLoopInstantiator* DescribeShockSimMenuMode(void); 
EXTERN void SwitchToShockSimMenuMode(BOOL push); 


#endif // __SHKMENU_H

