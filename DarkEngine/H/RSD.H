//		RSD.H		RSD functions for animfile stuff
//		Rex E. Bradford

/*
 * $Source: x:/prj/tech/libsrc/afile/RCS/rsd.h $
 * $Revision: 1.1 $
 * $Author: rex $
 * $Date: 1994/07/22 13:21:28 $
 * $Log: rsd.h $
 * Revision 1.1  1994/07/22  13:21:28  rex
 * Initial revision
 * 
*/

#ifndef __RSD_H
#define __RSD_H

#ifndef __TYPES_H
#include <types.h>
#endif

//	Rsd expansion (rsdexp.c)

void RsdExpand(uchar *pd, uchar *pRsd, int skipPix, long numpixels);

//	Rsd compression (rsdcomp.c)

long RsdCompress(uchar *pd, long pdLen, uchar *ps, int skipPix,
	long numpixels);
long RsdCompressDiff(uchar *pd, long pdLen, uchar *psold, uchar *psnew,
	long numpixels);

//	Rsd compression details: writing rsd codes

uchar *RsdWriteSkip(uchar *pd, ushort len);
uchar *RsdWriteRun(uchar *pd, ushort len, uchar pixel);
uchar *RsdWriteDump(uchar *pd, ushort len, uchar *ps);
uchar *RsdWriteEnd(uchar *pd);

long RsdLengthSkip(ushort len);
long RsdLengthRun(ushort len);
long RsdLengthDump(ushort len);
#define RsdLengthEnd() (3)

bool RsdCheckPd(long lenCurr, long lenTot, long want);

#endif


