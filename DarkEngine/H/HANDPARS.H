//		HandPars.H	The non-yacc-based "hand parser"
//						"HandParse: The parser for the rest of us"
//		Rex E. Bradford (REX)
/*
* $Header: r:/prj/lib/src/handpars/rcs/handpars.h 1.6 1994/03/11 15:52:50 rex Exp $
* $Log: handpars.h $
 * Revision 1.6  1994/03/11  15:52:50  rex
 * Oops
 * 
 * Revision 1.5  1994/03/11  15:44:38  rex
 * Added ParseCalcFuncExpr()
 * 
 * Revision 1.4  1994/03/11  13:24:03  rex
 * Added registered funcs list to parser struct, & prototypes to reg & unreg,
 * added new standard item for ParseTryStd (standalone func call)
 * 
 * Revision 1.3  1994/03/10  11:50:40  rex
 * Added <> around include files, added format string caching
 * 
 * Revision 1.2  1993/07/15  11:03:48  rex
 * Added PARSTD_DO to standard parse stuff
 * 
 * Revision 1.1  1993/06/29  10:05:44  rex
 * Initial revision
 * 
 * Revision 1.2  1993/05/10  16:30:26  rex
 * Added PARSTD_ENDFILE
 * 
 * Revision 1.1  1993/05/06  11:02:23  rex
 * Initial revision
 * 
*/

#ifndef __HANDPARS_H
#define __HANDPARS_H

#include <types.h>
#include <cstream.h>
#include <symtab.h>
#include <handscan.h>
#include <llist.h>

//	A parser structure is small enough to carry around, or put
//	in static or stack storage.  Roughly 150 bytes.  A lot more
//	gets allocated and pointed to.

#define REJECT_STACK_DEPTH 8

typedef enum {CACHE_NONE,CACHE_SOME,CACHE_ALL} ParseFormatCache;

typedef struct {
	Scanner scan;				// embedded scanner
	Symtab *psymtab;			// symbol table for defines
	Token *tokenStack;		// stack of tokens
	short tokenStackHead;	// next avail token stack slot
	short tokenStackTail;	// oldest token
	short rejectStack[REJECT_STACK_DEPTH];	// index to reject to
	short rejectStackIndex;	// current pos in reject stack
	ulong condStackMask;		// condition stack bits (max depth 32)
	short condStackIndex;	// condition stack index
	short condSkipCount;		// if non-zero, we're skipping
	ParseFormatCache formatCache;	// how to cache compiled formats
	LlistHead listCachedFormats;	// lru list of compiled format statements
	LlistHead listRegisteredFuncs; // list of registered functions
} Parser;

//	Datapaths used by parser

extern Datapath datapathScripts;	// datapath to find scripts in
extern Datapath datapathHfiles;	// datapath to find C header files in

//	Overall parser control

void ParseStart(Parser *p, Cstream *pscript, Symtab *psymtab);
void ParseDelete(Parser *p);

#define ParseSetSemiComments(p,onoff) ScanSetSemiComments(&(p)->scan,onoff)

//	Trying to parse input

bool ParseMore(Parser *p);
bool ParseTry(Parser *p, char *fmt, Token *ptoks);
bool ParseTryStd(Parser *p, ulong itemMask);
void ParseMatchAny(Parser *p, Token *ptok);
bool ParseReject(Parser *p);

//	Precompiled format strings

int ParseCompileFmt(char *fmt, Token *ptoks, int ntoks);
bool ParseTryPrecompiled(Parser *p, Token *ptokMatch, Token *ptoks);

//	Caching of compiled format strings (default is CACHE_SOME)

void ParseCacheSet(Parser *p, ParseFormatCache form);

//	Register functions for use in expressions

void ParseRegisterFunc(Parser *p, char *name, long (*f_func)(),
	int numArgs, bool retvalIsFix);
void ParseUnregisterFunc(Parser *p, char *name);
long ParseCallRegisteredFunc(Parser *p, char *name, long *args, int numArgs,
	TokType *retType);

//	Errors, warnings, token printing

void ParseError(Parser *p, char *str);
void ParseWarning(Parser *p, char *str);
void ParsePrintToken(Token tok);
void ParseSprintfToken(char *buff, Token tok);

//	Standard parser items

#define PARSTD_EOL		0x00000001L		// "\n"
#define PARSTD_DEFINE	0x00000002L		// "%s = [%d %f %s]"
#define PARSTD_INCLUDE	0x00000004L		// "INCLUDE %s"
#define PARSTD_CHEADER	0x00000008L		// "CHEADER %s"
#define PARSTD_IFDEF		0x00000010L		// "[IFDEF IFNDEF] %s"
#define PARSTD_ENDIF		0x00000020L		// "ENDIF"
#define PARSTD_IFSTR		0x00000040L		// "IF %s [== !=] %s"
#define PARSTD_IFNUM		0x00000080L		// "IF %d [== != < <= > >=] %d"
#define PARSTD_PRINT		0x00000100L		// "PRINT ... \n"
#define PARSTD_RUN		0x00000200L		// "RUN ... \n"
#define PARSTD_DO			0x00000400L		// "DO macname FOR [names ...] \n"
#define PARSTD_REGFUNC	0x00000800L		// "?func(...)
#define PARSTD_ENDFILE	0x00001000L		// (END OF FILE)
#define PARSTD_EXIT		0x00002000L		// "EXIT"

#define PARSTD_ALL		0x000FFFFFL		// high 12 bits reserved for C hdrs!

#endif

