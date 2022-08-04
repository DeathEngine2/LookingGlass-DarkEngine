/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

//		CSTREAM.H		Streams for C
//		Rex E. Bradford (REX)
/*
* $Header: x:/prj/tech/libsrc/handpars/RCS/cstream.h 1.6 1970/01/01 00:00:00 REX Exp $
* $Log: cstream.h $
 * Revision 1.6  1970/01/01  00:00:00  REX
 * Added ifdef cplusplus
 * 
 * Revision 1.5  1996/12/18  16:11:06  DAVET
 * Added prevChar and CsGetPrev for ability to get the previous character
 * 
 * Revision 1.4  1996/07/03  13:43:45  DAVET
 * Upped default line buffer size to 1024.
 * 
 * Revision 1.3  1993/07/26  11:44:51  rex
 * Added CSF_FREEBUFF flag
 * 
 * Revision 1.2  1993/07/16  14:48:40  rex
 * Changed prototype of CsInitLineBuff() to take size arg
 * 
 * Revision 1.1  1993/06/29  10:05:35  rex
 * Initial revision
 * 
 * Revision 1.3  1993/05/11  15:43:01  rex
 * Made CSF_ENDFILE a user flag
 * 
 * Revision 1.2  1993/05/11  14:30:52  rex
 * Added CSF_ENDFILE flag to generate CHAR_ENDFILE before EOF
 * 
 * Revision 1.1  1993/05/06  11:02:12  rex
 * Initial revision
 * 
*/

#ifndef __CSTREAM_H
#define __CSTREAM_H

#include <stdio.h>
#include <types.h>
#include <datapath.h>

#ifdef __cplusplus
extern "C" {
#endif

//	A Cstream implements these functions:

struct Cstream_;

typedef struct {
	void (*f_close)(struct Cstream_ *cs);				// close stream
	int (*f_get)(struct Cstream_ *cs);					// get next char
	int (*f_put)(struct Cstream_ *cs, int c);			// put a char
	long (*f_read)(struct Cstream_ *cs, void *p, long n);		// read chars
	long (*f_write)(struct Cstream_ *cs, void *p, long n);	// write chars
	int (*f_gets)(struct Cstream_ *cs, char *s, long bufsiz);	// read string
	int (*f_puts)(struct Cstream_ *cs, char *s);	// write string
	long (*f_tell)(struct Cstream_ *cs);				// return current pos
	int (*f_seek)(struct Cstream_ *cs, long pos, int org);	// seek to pos
	bool (*f_eos)(struct Cstream_ *cs);					// report if end-of-stream
} CstreamFuncs;

//	Cstreams may be line-based, using this struct:

typedef struct {
	char *lineBuff;
	char *lineCurr;
	int lineno;
	bool lineEnded;
} CstreamLineInfo;

//	Here is a Cstream:

typedef struct Cstream_ {
	char *name;						// filename or descriptive name
	ushort flags;					// CSF_XXX
	union {
		FILE *fp;					// handle to stream's data
		int fd;
		uchar *buff;
		void *data;
		};
	long length;					// length
	int ungetChar;					// unget char or 0 if none
   int prevChar;                                        // The previous char 
	union {
		uchar *curr;				// current ptr
		long pos;					// current pos
		};
	CstreamLineInfo cli;			// embedded line info
	struct Cstream_ *prevCs;	// previous cstream or NULL
	CstreamFuncs *pfuncs;		// ptr to functions
} Cstream;

//	Cstream flags:

#define CSF_READ		0x0001	// open for reading
#define CSF_WRITE		0x0002	// open for writing
#define CSF_BINARY	0x0004	// open in binary mode
#define CSF_LINEMODE	0x0008	// open in "line buffer" mode
#define CSF_FREEBUFF	0x0010	// Cstrbuff: free buffer at eof
#define CSF_ENDFILE		0x4000	// put out CHAR_ENDFILE before 0?

//	Do not supply these when open (used internally)

#define CSF_SELFALLOC	0x8000	// self-allocated

//	ENDFILE char, returned instead of EOF if CSF_ENDFILE set

#define CHAR_ENDFILE	26

//	Open a cstream with one of these:

Cstream *CsOpenFile(Cstream *cs, Cstream *csPrev, char *fname,
	Datapath *datapath, ushort flags);
Cstream *CsOpenFp(Cstream *cs, Cstream *csPrev, FILE *fp, ushort flags);
Cstream *CsOpenFd(Cstream *cs, Cstream *csPrev, int fd, ushort flags);
Cstream *CsOpenBuff(Cstream *cs, Cstream *csPrev, void *buff,
	long buffsize, ushort flags);
Cstream *CsOpenMono(Cstream *cs, Cstream *csPrev);

//	Close a cstream with:

Cstream *CsClose(Cstream *cs);

//	Functions & macros for i/o

int CsGet(Cstream *cs);
int CsGetPrev(Cstream *cs);
#define CsPut(cs,c)		((cs)->pfuncs->f_put(cs,c))
int CsUnget(Cstream *cs, int c);
#define CsRead(cs,p,n)	((cs)->pfuncs->f_read(cs,p,n))
#define CsWrite(cs,p,n)	((cs)->pfuncs->f_write(cs,p,n))
#define CsGets(cs,p,n)	((cs)->pfuncs->f_gets(cs,p,n))
#define CsPuts(cs,p)		((cs)->pfuncs->f_puts(cs,p))
void CsPrintf(Cstream *cs, char *fmt, ...);
#define CsTell(cs)		((cs)->pfuncs->f_tell(cs))
#define CsSeek(cs,p,o)	((cs)->pfuncs->f_seek(cs,p,o))
#define CsEos(cs)			((cs)->pfuncs->f_eos(cs))

//	Misc macros

#define CsGetName(cs) ((cs)->name)
#define CsGetLine(cs) ((cs)->cli.lineBuff)
#define CsGetLineno(cs) ((cs)->cli.lineno)

//	Helper routines for cstream implementations

// Upped this from 256 to 1024 for loooong kanji strings. dt 07/03/96


#define CS_DEFAULT_LINEBUFF_SIZE 1024
void CsInitLineBuff(Cstream *cs, int size);	// if 0, uses default size

#ifdef __cplusplus
};
#endif

#endif

