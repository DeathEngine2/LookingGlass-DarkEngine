/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

//		FNAME.H		Filename manipulation
//		Rex E. Bradford (REX)
/*
* $Header: x:/prj/tech/libsrc/dstruct/RCS/fname.h 1.3 1999/09/14 11:24:11 JAEMZ Exp $
* $Log: fname.h $
 * Revision 1.3  1999/09/14  11:24:11  JAEMZ
 * Constified this puppy!
 * 
 * Revision 1.2  1996/01/22  15:38:38  DAVET
 * 
 * Added cplusplus stuff.
 * 
 * Revision 1.1  1993/05/03  10:53:34  rex
 * Initial revision
 * 
*/

#ifndef FNAME_H
#define FNAME_H

#include "types.h"

#ifdef __cplusplus
extern "C"  {
#endif

#define MAXLEN_FNAME_PATH 113
#define MAXLEN_FNAME_NAME 8
#define MAXLEN_FNAME_EXT 3

typedef struct {		// this struct holds 4 pieces of a filename
	char drive;
	char path[MAXLEN_FNAME_PATH + 1];
	char name[MAXLEN_FNAME_NAME + 1];
	char ext[MAXLEN_FNAME_EXT + 1];
} Fname;					// 128 bytes total, why not

//	This function extracts a filename struct from a string

int FnameExtract(Fname *fname, const char *str);

//	This function builds a string from a filename struct

char *FnameBuild(char *buff, Fname *fname);

//	These macros replace a component

#define FnameReplaceDrive(fn,d) ((fn)->drive=(d))
#define FnameReplacePath(fn,p) (FnameReplacePart(&(fn)->path, p, MAXLEN_FNAME_PATH))
#define FnameReplaceName(fn,n) (FnameReplacePart(&(fn)->name, n, MAXLEN_FNAME_NAME))
#define FnameReplaceExt(fn,e) (FnameReplacePart(&(fn)->ext, e, MAXLEN_FNAME_EXT))

void FnameReplacePart(char *part, char *str, int maxlen);

//	These macros add a component only if it is currently empty

#define FnameAddDrive(fn,d) {if ((fn)->drive==0) FnameReplaceDrive(fn,d);}
#define FnameAddPath(fn,p) {if ((fn)->path[0]==0) FnameReplacePath(fn,p);}
#define FnameAddName(fn,n) {if ((fn)->name[0]==0) FnameReplaceName(fn,n);}
#define FnameAddExt(fn,e) {if ((fn)->ext[0]==0) FnameReplaceExt(fn,e);}

//	These macros delete a component

#define FnameDelDrive(fn) ((fn)->drive=0)
#define FnameDelPath(fn) ((fn)->path[0]=0)
#define FnameDelName(fn) ((fn)->name[0]=0)
#define FnameDelExt(fn) ((fn)->ext[0]=0)


#ifdef __cplusplus
}
#endif



#endif


