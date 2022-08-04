/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkmain.h 1.1 1999/04/03 05:03:36 mahk Exp $

#ifndef __SHKMAIN_H
#define __SHKMAIN_H

//
// Shock "Master Control" Loopmode.  
//
// Currently just  starts the intro cutscene and switches to main
// menu, but may do more in the future.  
//

EXTERN void ShockMasterModeInit(); 
EXTERN void ShockMasterModeTerm(); 


EXTERN struct sLoopInstantiator* DescribeShockMasterMode(void); 

enum eShockMasterModeState
{
   kMasterModeAppStart, 
   kMasterModeNewGame, 
}; 

// Set which of the above states the master mode will be in
EXTERN void ShockSetMasterMode(int state); 

#endif // __SHKMAIN_H

