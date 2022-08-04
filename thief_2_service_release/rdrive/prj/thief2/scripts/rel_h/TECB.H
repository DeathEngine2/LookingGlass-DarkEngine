/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

////////////////////////////////////////////////
// TECB.H			// Eric McCall -- 1993 //
//
// Handles all low memory management of ECB's and
// their associated data (IPXHeaders and user data)
//
/* $Header: r:/prj/lib/src/network/rcs/tecb.h 1.4 1993/08/18 11:33:21 eric Exp $
* $Log: tecb.h $
 * Revision 1.4  1993/08/18  11:33:21  eric
 * Upped TECB allocation to temporarily fix network flood
 * problem.
 * 
 * Revision 1.3  1993/08/11  15:24:25  eric
 * Made TECB_prep accept local and inet address
 * 
 * Revision 1.2  1993/08/10  16:14:37  eric
 * Moved TECB_prep here, changed debug slots, more.
 * 
 * Revision 1.1  1993/07/20  16:26:33  eric
 * Initial revision
 * 
*/

#ifndef TECB_H
#define TECB_H

#include <lg.h>
#include "ipx.h"

// If we're running out of ECBs, either increase these numbers, 
// or call net_update more frequently
#define NET_NUM_SEND_ECBS	5
#define NET_NUM_REC_ECBS	8

#define DATA_BUFF_SIZE	500

typedef struct _total_ECB_ {
	ECB ecb;
	IPXHeader head;
	char data[DATA_BUFF_SIZE];
} TECB;

// Offsets for pointer math:
// offsets of each item in TECB struct
#define	OFF_ECB	(0)
#define	OFF_Head	(OFF_ECB + (sizeof(ECB)))
#define	OFF_Data	(OFF_Head + (sizeof(IPXHeader)))

// Offsets from base low memory into start of TECB pools
#define	OFF_SendECB		(0)
#define	OFF_RecECB		(OFF_SendECB + (sizeof(TECB) * NET_NUM_SEND_ECBS))


// put anything that needs real mode memory into here!
struct real_mode_data {
	TECB SendPool[NET_NUM_SEND_ECBS];
	TECB RecPool[NET_NUM_REC_ECBS];
};

// global pointer to low memory total ECB struct : ECB + IPXHeader + data
extern TECB *LM_RecTECBp;
extern TECB *LM_SendTECBp;
extern ConvMemBlock LowMemBlock;	// global storage pointers to struct real_mnode_data

// Code-like defines    (the x in all these is an index to a TECB struct)

#define FORALLSENDECBS(x) for(x = 0; x < NET_NUM_SEND_ECBS; x++)
#define FORALLRECECBS(x) for(x = 0; x < NET_NUM_REC_ECBS; x++)
#define TECB_SEND_COMPL_CODE(x) (LM_SendTECBp[x].ecb.compl_code)
#define TECB_REC_COMPL_CODE(x) (LM_RecTECBp[x].ecb.compl_code)
#define TECB_REC_SOCKET(x) (LM_RecTECBp[x].ecb.socket)

// global functions

extern void ECBInit( void );
extern TECB *ECB_send_get();
extern TECB *TECB_prep(char inet[], char local[], ushort data_len);

#endif
