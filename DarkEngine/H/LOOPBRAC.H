// $Header: x:/prj/tech/libsrc/loopsys/RCS/loopbrac.h 1.2 1998/06/01 15:54:55 JAEMZ Exp $

#pragma once
#ifndef __LOOPBRAC_H
#define __LOOPBRAC_H

#include <stdio.h>
#include <stdlib.h>
#include <error.h>

// This is the bracket base type.
// It contains these
// Maximum loop brackets

class cLoopBracket {
public:
   cLoopBracket(char *n,ulong m=0);

   // This is what the loopmanager should call
   // Takes care of suspend/resume logic
   inline errtype Start(ulong flag=0) {if (flag&mask) return Resume(); else return Setup();}
   inline errtype Stop(ulong flag=0) {if (flag&mask) return Suspend(); else return Cleanup();}

   // If flag&mask, resume then cleanup, else, nothing
   inline errtype Pop(ulong flag=0) {if (flag&mask) return QuitSuspend(); else return OK;}

   virtual errtype Loop();

public:
   const char *const name;

protected:
   // These are the ones you inherit
   virtual errtype Setup();
   virtual errtype Resume();
   virtual errtype Cleanup();
   virtual errtype Suspend();
   // The default of this should be okay, 
   // it's for quitting a suspended bracket
   // Right here it just resumes then cleans up
   virtual errtype QuitSuspend();

private:
   const ulong mask;
};

#endif // LOOP_BRAC






