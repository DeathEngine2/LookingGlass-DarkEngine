//		B2INTERP.H		BABL2 Interpreter Header
//		Rex E. Bradford (REX)
/*
* $Header: r:/prj/lib/src/babl2/rcs/b2interp.h 1.15 1993/10/29 15:51:12 rex Exp $
* $log$
*/

#ifndef B2INTERP_H
#define B2INTERP_H

#include <lg.h>
#include <res.h>
#include <llist.h>
#include <babl2.h>

extern Thread *gThread;			// ptr to currently running thread, useful

extern Babint *((*B2Cvars)[]);		// ptr to table of cvar ptrs
extern Babint (*(*B2Cfuncs)[])();	// ptr to table of cfunction ptrs

#define P_CVAR(i) ((*B2Cvars)[i])
#define P_CFUNC(i) ((*B2Cfuncs)[i])

typedef struct {					// opcode,routine pair
	uchar code;
	uchar* (*routine)(uchar *p);
} OpcodeSpec;

//	Interp Routines

void Babl2InterpInit();
void Babl2InstallOpcodes(OpcodeSpec *ptable);
void Babl2Interpret(Thread *pthread);

char *DoStrFormat(Ref stringRef, char *pd, char *pend);

//	Thread-blocking var & macro

extern bool threadBlocked;				// used to break out of interpreter
#define BLOCKTHREAD() (threadBlocked=TRUE)

//	Macros/functions for stack manipulation

#define INIT_STACKSIZE (16*sizeof(Babint))	// initial stack size
#define GROW_STACKSIZE (16*sizeof(Babint))	// amount to grow stack by

extern Babint expStack[];		// expression stack
extern uchar expTypeStack[];	// expression type stack
extern short expStackOff;		// offset into expression stack

#ifdef WARN_ON

#define POPEXP() PopExp()
#define PUSHEXP(val,type) PushExp(val,type)
#define DISCARDEXP() DiscardExp()

Babint PopExp();
void PushExp(Babint val, uchar type);
void DiscardExp();

#else

#define POPEXP() (expStack[--expStackOff])
#define PUSHEXP(val,type) do {			\
	expStack[expStackOff] = val;			\
	expTypeStack[expStackOff++] = type;	\
} while (0)
#define DISCARDEXP() (--expStackOff)

#endif

#define TOPEXP() (expStack[expStackOff-1])
#define TOPEXPTYPE() (expTypeStack[expStackOff-1])

#define LOCALOFF(off) ((off) + REFTABLESIZE(((RefTable *) gThread->pcBase)->numRefs))
#define LOCALPTR(off) (gThread->pcBase + LOCALOFF(off))

#endif

