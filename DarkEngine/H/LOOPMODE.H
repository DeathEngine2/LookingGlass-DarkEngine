// $Header: x:/prj/tech/libsrc/loopsys/RCS/loopmode.h 1.2 1998/06/01 15:58:17 JAEMZ Exp $

#pragma once
#ifndef __LOOPMODE_H
#define __LOOPMODE_H

#include <error.h>

// Forward declare...
class cLoopBracket;

// By all rights this should be private to the class, but you
// can't actually do that, which is dumb.  You can do it in java!

const kLMMaxBrackets=32;

class cLoopMode {
public:
   cLoopMode();
   // This deletes all the registered brackets too, so beware
   virtual ~cLoopMode();

   // Adds a bracket to the loopmode in the right order
   void Add(cLoopBracket *pLB);

// Semiprivate stuff, only for the loop manager to see
   // You can easily redefine these to do your profiling or
   // mono printing or whatever.
   // I thought that was better than having to install callbacks
   // everwhere, which seems silly in an object oriented archetecture.

   // Setup the loop
   virtual errtype Setup();

   // Loop the loop
   virtual errtype Loop();

   // Shutdown the loop, saying how
   virtual errtype Cleanup();
   errtype Cleanup(ulong h) {how = h; return Cleanup();}

   // Pop this loopmode, ie, resume what needs to be resumed, 
   // then cleanup
   virtual errtype Pop();

   // How this mode was exited (if on stack)
   ulong how;

protected:

   // This is all for the list of brackets
   cLoopBracket *mBrackets[kLMMaxBrackets];
   int mNumBrackets;
};

#endif  // __LOOPMODE_H





