/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

//		BABL2.H		BABL2 Interpreter header file
//		Rex E. Bradford (REX)
/*
* $Header: x:/prj/tech/libsrc/babl2/RCS/babl2.h 1.14 1996/04/09 19:10:16 xemu Exp $
* $Log: babl2.h $
 * Revision 1.14  1996/04/09  19:10:16  xemu
 * added NewThreadArglist
 * 
 * Revision 1.13  1993/10/22  11:22:39  rex
 * Added macros to get and put babl2 globals from C
 * 
 * Revision 1.12  1993/10/15  13:30:41  rex
 * Added 2 msg ptrs to thread struct, added SIGNAL_MSGRECEIVE
 * 
 * Revision 1.11  1993/08/31  10:12:46  rex
 * Changed Babl2KillThread() from macro to func
 * 
 * Revision 1.10  1993/07/29  15:07:57  rex
 * Added B2KEY_TIMEOUT special key value
 * 
 * Revision 1.9  1993/07/27  13:19:14  rex
 * Changed prototype of Babl2Debug() (arg from short to Babint)
 * 
 * Revision 1.8  1993/07/26  12:43:27  rex
 * Modified key handler prototypes, added special key defines for mouse
 * 
 * Revision 1.7  1993/07/21  17:40:59  rex
 * Added macros: Babl2GlobalsPtr() and Babl2GlobalsSize()
 * 
 * Revision 1.6  1993/07/20  13:52:19  rex
 * Changed Babl2UseScripts() and Babl2UnuseScripts() prototypes
 * 
 * Revision 1.5  1993/07/16  17:31:03  rex
 * Added plug-in user interface handlers for SAY and MENU
 * 
 * Revision 1.4  1993/07/13  16:13:48  rex
 * Modified Thread structure, added time globals, prototypes mods
 * ,.
 * 
 * Revision 1.3  1993/06/30  15:26:22  rex
 * Moved some stuff into b2types.h
 * 
 * Revision 1.2  1993/06/30  09:57:07  rex
 * Changed menu structure
 * 
 * Revision 1.1  1993/06/29  18:38:52  rex
 * Initial revision
 * 
 * Revision 1.5  1993/05/25  15:01:53  rex
 * Removed base.h, put in types.h instead
 * 
 * Revision 1.4  1993/05/03  12:33:20  dfan
 * #ifndef around #include lines
 * 
 * Revision 1.3  1993/04/15  16:26:25  rex
 * Changed pnext & pprev to _llist
 * 
 * Revision 1.2  1992/10/19  17:49:56  rex
 * Changed a couple of constants (BABL2_EXPR_DEPTH, SIGNAL_USER)
 * 
 * Revision 1.1  1992/08/31  17:00:00  unknown
 * Initial revision
 * 
*/


#ifndef BABL2_H
#define BABL2_H

#ifndef RES_H
#include <res.h>
#endif
#ifndef LLIST_H
#include <llist.h>
#endif
#ifndef B2TYPES_H
#include <b2types.h>
#endif
#ifndef MESSAGE_H
#include <message.h>
#endif

//	Thread structure

#define BABL2_EXPR_DEPTH 16

typedef struct {
	struct _llist;			// list ptrs
	short threadId;		// unique thread id
	Id resId;				// resource id of script
	uchar *pcBase;			// ptr to code base while running
	Baboff pc;				// current program counter offset
	Baboff sp;				// current stack offset
	Baboff bp;				// current frame ptr offset
	ushort sizeStack;		// size of stack in bytes
	uchar *stack;			// ptr to stack (and statics)
	Message *pMsgSend;	// message being constructed to send
	Message *pMsgReceive; // received message
	short blockState;		// blocking condition
	long blockArg;			// argument to blocking condition
	short timeout;			// block timeout in milliseconds
	ulong tlast;			// time last ran
	Babint expStack[BABL2_EXPR_DEPTH];		// expression stack 
	uchar expTypeStack[BABL2_EXPR_DEPTH];	// expression type stack
	short expStackOff;	// expression stack offset
} Thread;

extern LlistHead threadList;

//	Task Manager Routines (b2task.c)

void Babl2Init();
void Babl2Term();
void Babl2UseScripts(Id idHdr, Babint *((*pcvars)[]), Babint (*(*pcfuncs)[])());
void Babl2UnuseScripts();
void Babl2SetTimePtrs(ulong volatile *pSysTime, ulong volatile *pGameTime);
void Babl2Recur();
void Babl2RunThread(Thread *pthread);
Thread *Babl2NewThread(Ref func);
Thread *Babl2NewThreadArglist(Ref func, Babint *arg_list, int num_args);
void Babl2SignalThread(Thread *pthread, short signal, long arg);
void Babl2BlockThread(Thread *pthread, short blockState, long blockArg,
	short timeout);
void Babl2KillThread(Thread *pthread);
Thread *Babl2FindThread(ushort threadId);
void Babl2Debug(Babint value);

extern ulong volatile *pBabl2SysTime;
extern ulong volatile *pBabl2GameTime;

#define Babl2GetSysTime() (*pBabl2SysTime)
#define Babl2GetGameTime() (*pBabl2GameTime)

#define Babl2NumThreads() LlistNumNodes(&threadList)
#define Babl2UnblockThread(pthread) ((pthread)->blockState = 0)

int Babl2HandleKey(ushort key);
int Babl2HandleKeyThread(Thread *pthread, ushort key);

//	Special key values

#define B2KEY_MOUSE_MOVE	0x80		// mouse events
#define B2KEY_MOUSE_LDOWN	0x81
#define B2KEY_MOUSE_LUP		0x82
#define B2KEY_MOUSE_RDOWN	0x83
#define B2KEY_MOUSE_RUP		0x84
#define B2KEY_MOUSE_CDOWN	0x85
#define B2KEY_MOUSE_CUP		0x86

#define B2KEY_TIMEOUT		0x88		// timeout from waitkeyclick

#define B2KEY_USER			0x90		// 0x90 and up are user keys

//	Access to header and globals

extern uchar *babl2Globals;				// ptr to globals
extern Babl2ResHeader babl2ScriptsHdr;	// copy of res header

#define Babl2GlobalsPtr() (babl2Globals)
#define Babl2GlobalsSize() (babl2ScriptsHdr.globalSize)

#define Babl2GetGlobal(offset) (*(Babint *)(babl2Globals+(offset)))
#define Babl2PutGlobal(offset,val) *(Babint *)(babl2Globals+(offset))=(val)

//	Plug-in user-interface handlers

extern void (*f_Babl2Say)(ushort speaker, char *str);
extern void (*f_Babl2Menu)(short numItems, char **strings, ushort *accKeys);

#define Babl2SetSayFunc(f) (f_Babl2Say = (f))
#define Babl2SetMenuFunc(f) (f_Babl2Menu = (f))

//	Signal values

#define SIGNAL_EXIT		1		// thread is exiting
#define SIGNAL_KILLED	2		// wait for thread to be killed
#define SIGNAL_DELAY		3		// wait for elapsed real time delay
#define SIGNAL_KEYCLICK	4		// wait for key or mousepress
#define SIGNAL_WAITTIME	5		// wait for elapsed game time
#define SIGNAL_MENU		6		// wait for menu pick
#define SIGNAL_ANIMEND	7		// wait for anim to end
#define SIGNAL_MSGRECEIVE 8	// wait for message to be received

#define SIGNAL_USER 	256


#endif

