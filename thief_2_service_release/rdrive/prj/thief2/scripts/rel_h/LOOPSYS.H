/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/fltloop/RCS/loopsys.h 1.3 1999/09/28 11:22:51 darrenl Exp $

#pragma once
#ifndef __LOOPSYS_H
#define __LOOPSYS_H

#include <error.h>


// The loopmanager is the system responsible for maintaining loopmodes.
// Loopmodes are a class.  The idea is that when you write a loopmode, you 
// inherit it from the base loopmode, only make it with the appropriate
// brackets.

// I recommend that all bracket h and cpp files are suffixed with _br,
// and all loopmode h and cpp files are suffixed with _lp
// This allows ready recognition, and an easy way to find all the defined
// brackets in a game

// To change to another loopmode, you instantiate that loopmode object, then
// perform some operation on it, like a switch, or a push.
// You can also pop at any time, and unwind, which exits the system at the 
// next loop.  It doesn't fully pop down the stack completely though, although
// it may still.  


// Forward declare
class cLoopMode;

// --------------------------------------------------------
// loopsys_init()
// 
//  Initializes the loopmode system

extern void loopsys_init();

// --------------------------------------------------------
// loopsys_shutdown()
// 
// Does a loopmode unwind and any other memory freeing it needs to do
// This is good if the game has to suddenly exit from inside loopsys_go
// Note that this doesn't continue looping, it immediately cleans up 
// the current loopmode and anything on the stack

extern void loopsys_shutdown();


// --------------------------------------------------------
// loopsys_go()
// 
//  begins an event loop, which iterates until loopsys_exit()
//  is called.  
//  The current loopmode's enter function will be called
//  before the first iteration, the exit function will be called
//  after the last iteration, and the loop function will be called
//  once each iteration. 
//
//  If there is no current loopmode, loopsys_go() will 
//  immediately return ERR_NULL.  If any of the 
//  current loopmode's functions ever returns a non-OK error
//  code, loopsys_go will exit, returning that error code. 

extern errtype loopsys_go(int* retval);


// --------------------------------------------------------
// loopsys_switch(mode)
// 
// Changes the current loop mode, if called from inside
// the execution of loopsys_go(), the change will happen
// at the end of the current iteration of the current 
// loopmode.  The current loopmode's exit function will be 
// called as well as the new loopmode's.  

extern void loopsys_switch(cLoopMode* mode,ulong how=0);


// --------------------------------------------------------
// loopsys_push(mode)
//
// Behaves exactly like loopman switch, but also saves the
// old loopmode on a stack to be restored when the current 
// loopmode exits. 

extern void loopsys_push(cLoopMode* mode,ulong how=0);


// ----------------------------------------------------------
// loopsys_pop()
//
// Causes the current iteration of the current loopmode
// to be the last.  If the loopmode stack is not empty, 
// loopsys_pop() will pop the top loopmode and 
// loopsys_switch() to it.  Otherwise, loopsys_pop()
// will cause the current execution of loopsys_go()
// to exit, returning the specified return value.

extern void loopsys_pop();


// --------------------------------------------------------
// loopsys_bury(mode)
// 
// Push a loopmode onto the stack to be executed upon exiting
// the current loop mode

extern void loopsys_bury(cLoopMode* mode,ulong how=0);



// ---------------------------------------------------------
// loopsys_unwind()
//
// This unwinds the whole stack,
// returning from loopsys_go();

extern void loopsys_unwind(int retval);



// ----------------------------------------------------------
// loopsys_getcur()
//
// Returns pointer to current cLoopMode

extern cLoopMode *loopsys_getcur ();


// Returns the stack depth, good for debugging...
extern int loopsys_stackdepth();

#endif  // __LOOPSYS_H








