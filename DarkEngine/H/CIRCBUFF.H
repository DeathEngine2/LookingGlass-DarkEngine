//		CIRCBUFF.H		Circular buffer
//		Rex E. Bradford

/*
 * $Source: x:/prj/tech/libsrc/afile/RCS/circbuff.h $
 * $Revision: 1.1 $
 * $Author: rex $
 * $Date: 1994/07/22 13:21:07 $
 * $Log: circbuff.h $
 * Revision 1.1  1994/07/22  13:21:07  rex
 * Initial revision
 * 
*/

#ifndef __CIRCBUFF_H
#define __CIRCBUFF_H

#ifndef __TYPES_H
#include <types.h>
#endif

typedef struct {
	uchar *buff;				// ptr to circular buffer
	uchar *buffEnd;			// end of buffer
	uchar *pput;				// ptr to put data to
	uchar *pget;				// ptr to get data from
} CircBuff;

void CircBuffInit(CircBuff *pcb, uchar *buff, long length);
void CircBuffReset(CircBuff *pcb);
ulong CircBuffRoom(CircBuff *pcb);
ulong CircBuffUsed(CircBuff *pcb);
void CircBuffAdvancePut(CircBuff *pcb, long amt);
void CircBuffAdvanceGet(CircBuff *pcb, long amt);
bool CircBuffBetween(uchar *ptest, uchar *pbeg, uchar *pend);

#define CircBuffEmpty(pcb) ((pcb)->pput==(pcb)->pget)
#define CircBuffHitEnd(pcb,p) ((p)>=(pcb)->buffEnd)

#endif


