//		HandScan.H		Lexical "hand-scanner" for the "hand-parser"
//		Rex E. Bradford (REX)
/*
* $Header: x:/prj/tech/libsrc/handpars/RCS/handscan.h 1.3 1996/09/29 12:41:09 JAEMZ Exp $
* $Log: handscan.h $
 * Revision 1.3  1996/09/29  12:41:09  JAEMZ
 * Added doubleval to Token and parse it on the sly
 * 
 * Revision 1.2  1993/07/15  11:05:15  rex
 * Added field for f_PopCs function ptr to Scanner struct, and macro to set it
 * 
 * Revision 1.1  1993/06/29  10:05:53  rex
 * Initial revision
 * 
 * Revision 1.3  1993/05/11  14:31:14  rex
 * Took out CHAR_ENDFILE stuff (moved to cstream)
 * 
 * Revision 1.2  1993/05/10  16:29:57  rex
 * Added CHAR_ENDFILE and flag and macro to have scanner return it optionally.
 * 
 * Revision 1.1  1993/05/06  11:02:18  rex
 * Initial revision
 * 
*/

#ifndef HANDSCAN_H
#define HANDSCAN_H

#include "types.h"
#include "fix.h"
#include "cstream.h"
#include "symtab.h"

//	Extend base symbol table types

#define TSYM_NAME		TSYM_USER
#define TSYM_CHAR		(TSYM_USER+1)
#define TSYM_VARREF	(TSYM_USER+2)

#define TSYM_SCANUSER	(TSYM_USER+3)	// user can go from here ...

//	And map TOK_XXX to TSYM_XXX

#define TOK_NULL		TSYM_NULL
#define TOK_INTEGER	TSYM_INTEGER
#define TOK_FIX		TSYM_FIX
#define TOK_STRING	TSYM_STRING
#define TOK_NAME		TSYM_NAME
#define TOK_CHAR		TSYM_CHAR
#define TOK_VARREF	TSYM_VARREF

//	Token definition

typedef uchar TokType;

typedef struct
	{
	TokType type;			// token type
	union {
		long integer;		// composite value
		fix fixval;
		char *string;
		ushort chval;
		TokType varRefType;
		};
   double doubleval;
} Token;

//	The scanner keeps an array of token type names, for convenience

extern char *tokTypeName[];

//	A scanner structure is small enough to be embedded if desirable.
//	The hand parser does just that.

#define MAX_DBLCHARS 31
#define MAX_WSCHARS 15

typedef struct Scanner_ {
	Cstream *ps;									// current cstream
	Cstream *(*f_PopCs)(struct Scanner_ *pscan);	// func to call when pop cs
	void (*f_ExpandMacro)(void *arg, char *name, char *buff);	// macro expand func
	void *femArg;									// arg to pass to macro ex
	bool semiComments : 1;						// if TRUE, semi-colon comments on
	ushort dblChars[MAX_DBLCHARS+1];			// valid double-chars
	uchar wsChars[MAX_WSCHARS+1];				// whitespace chars
} Scanner;

//	Convert two chars to a double-char

#define DBLCHAR(cl,cr) ((((ushort)(cl)) << 8) | (cr))

//	Set f_PopCs() routine

#define ScanSetPopCs(pscan,f) ((pscan)->f_PopCs = (f))

//	PROTOTYPES:

//	Start up a scanner with the supplied script

void ScanStart(Scanner *pscan, Cstream *pcstream);

//	Set function to call when expanding $macros

void ScanSetMacroExpandFunc(void *arg, Scanner *pscan,
	void (*f_em)(void *arg, char *name, char *buff));

//	Turn semi-colon comments on and off

#define ScanSetSemiComments(pscan,onoff) ((pscan)->semiComments=(onoff))

//	Add double-char pairs to the scanner

bool ScanAddDblChars(Scanner *pscan, ushort *pdbl);

//	Set whitespace chars (' ' and '\t' always assumed)

bool ScanSetWsChars(Scanner *pscan, uchar *pws);

//	Get next token, return FALSE if none left

bool ScanNextTok(Scanner *pscan, Token *pt);

#endif


