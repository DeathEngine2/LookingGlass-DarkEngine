// Nettypes.h			// Eric McCall - 1993 //
//
// Include file for LG network API
//
/* $Header: r:/prj/lib/src/network/rcs/nettypes.h 1.7 1994/01/13 15:30:21 eric Exp $
* $Log: nettypes.h $
 * Revision 1.7  1994/01/13  15:30:21  eric
 * Added macros to get at ObjID and NodeID parts of the 
 * global NobjID
 * 
 * Revision 1.6  1993/08/18  11:40:24  eric
 * changed gameid size / definition.
 * Oh, to reuse the constant, these guys must be unsigned, hmm...
 * Should fix this somehow...
 * 
 * Revision 1.5  1993/08/13  15:07:46  eric
 * Made gameID into a uchar (16 distinct games are plenty)
 * 
 * Revision 1.4  1993/08/12  15:44:43  eric
 * Got recent stuff working.
 * 
 * Revision 1.3  1993/08/12  15:38:03  eric
 * Added compile-time buffer check
 * 
 * Revision 1.2  1993/08/12  15:21:07  eric
 * Changed NOBJ_DATA_BUFF_SIZE
 * 
 * Revision 1.1  1993/08/10  16:11:44  eric
 * Initial revision
 * 
*/

#ifndef NETTYPES_H
#define NETTYPES_H

#ifndef TECB_H
#include "tecb.h"
#endif

// constants and types available to all

#define NET_NULL_ID	-1		// null game / node ID, otherwise known as 0xFF...

#define NET_NUM_MAX_NODES	8		// max number of nodes in a gameID

typedef char GameID;		// a node group identifier
typedef short NodeID;		// a node identifier
//typedef unsigned char GameID;		// a node group identifier
//typedef unsigned short NodeID;		// a node identifier

#define NET_NUM_MAX_NOBJS	16		// max network objects on a node

typedef unsigned short ObjID;		// an identifier for local use
typedef unsigned long NobjID;		// a nobj identifier; (nodeID << 16) + ObjID on that node

#define NOBJID(x,y)	( (NobjID) ((x<<16)+y) )
#define NOBJINDEX(x)	( (ObjID) (0x0000ffff & x) )
#define NOBJNODE(x)	( (NodeID) ((0xffff0000 & x) >> 16) )

#define NOBJ_DATA_BUFF_SIZE	80

#if (NOBJ_DATA_BUFF_SIZE > DATA_BUFF_SIZE)
	#error Object data size exceeds real mode memory allocated!  Change and recompile.
#endif


#endif
