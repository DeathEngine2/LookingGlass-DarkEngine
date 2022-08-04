/////////////////////////////////////////////////////////
// IPX.H
//
// This header file defines the data structures and 
// return values for using IPX.
//

#ifndef IPX_H
#define IPX_H

#include "rminth.h"

#define DWORD ulong
#define WORD ushort
#define BYTE uchar

typedef struct IPXPackHead_ {
	ushort checksum;
	ushort length;
	uchar tc;
	uchar type;
	uchar dst_net[4];
	uchar dst_node[6];
	ushort dst_socket;
	uchar src_net[4];
	uchar src_node[6];
	ushort src_socket;
} IPXHeader;

// IPX Packet type defines:
#define IPX_PACK_UNK	0	// unknown	<- this can be used too...
#define IPX_PACK_RIP	1	// routing
#define IPX_PACK_ECHO	2	// echo
#define IPX_PACK_ERR	3	// error
#define IPX_PACK_PEP	4	// packet exchange  <- use this for IPX
#define IPX_PACK_SPP	5	// seq. packet exchange  <- use this for SPX
#define IPX_PACK_NCP	17

typedef struct ECB_ {
	ulong link_addr;		// used by IPX only with ECB is in use
	ulong ESR_addr;		// set to NULL (0) if no ESR used
	uchar in_use;
	uchar compl_code;
	ushort socket;
	ulong IPX_workspace;		// shouldn't be changed while ECB in use
	uchar driver_workspace[12];	// shouldn't be changed while ECB in use
	uchar imm_addr[6];
	ushort frag_cnt;		// this should be init'ed to 2 (low-high)
	ulong frag1_addr;		// address to an IPXPacketHeader: real mode offset-segment
	ushort frag1_size;	// this will be the size of the header, 30 bytes : hi-lo format
	ulong frag2_addr;		// this holds user data : rm offset-segment
	ushort frag2_size;	// size of user data : hi-lo
} ECB;

// in_use field codes (what's happening to the ECB)
#define ECB_INUSE_DONE		0x0;		// IPX is done with the ECB
#define ECB_INUSE_QUEUED	0xfb;		// ECB is in a holding queue after a send or receive
#define ECB_INUSE_SCHEDULED	0xfd;		// ECB is scheduled; IPX is waiting for its time interval
#define ECB_INUSE_LISTENING	0xfe;		// IPX is in use for receiving a packet
#define ECB_INUSE_INUSE	0xff;		// ECB is in use for sending a packet
#define ECB_INUSE_SNDTRIED	0xf8;		// IPX was busy, so this send packet has been requeued for later
#define ECB_INUSE_PROCESSING	0xfa;		// ECB is being processed now

// completion codes after IPX is done with packet
#define ECB_COMPL_SUCCESS	0x0;
#define ECB_COMPL_CANCELFAIL	0xf9; // the event should not be cancelled
#define ECB_COMPL_CANCELED	0xfc;	// the send was cancelled
#define ECB_COMPL_MALF_OVER	0xfd;	// the send packet was malformed, or the receive overflowed
#define ECB_COMPL_UNDELIV	0xfe;	// the packet couldn't be delivered
#define ECB_COMPL_FAIL_CLOS	0xff; // send: network/hardware error | receive: the socket is closed

// Data :

extern unsigned int max_packet_size;		// max packet size in bytes
extern char my_ipx_addr[12];		// This node's internet address (with socket)

// Function prototypes

WORD SwapByte(WORD stinky);
bool IPXInit( void );
void IPXGetInternetworkAddr( BYTE *my_addr );
bool IPXPackFromMe (IPXHeader *ipxhp);
BYTE IPXOpenSocket( WORD socket_num );
BYTE IPXCloseSocket( WORD socket_num );
void IPXRelinquishControl( void );
BYTE IPXSend(ECB *ecb);
BYTE IPXListen(ECB *ecb);

#endif


////////////////////////////////////////////////
// TECB.H			// Eric McCall -- 1993 //
//
// Handles all low memory management of ECB's and
// their associated data (IPXHeaders and user data)
//
/* $Header: o:/netapi/src/RCS/tecb.h 1.4 1993/08/18 11:33:21 eric Exp $
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

#endif	// TECB_H

// Nettypes.h			// Eric McCall - 1993 //
//
// Include file for LG network API
//

#ifndef NETTYPES_H
#define NETTYPES_H

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

#endif // NETTYPES_H

// Network.h			// Eric McCall - 1993 //
//
// Include file for base LG network API
//

#ifndef NETWORK_H
#define NETWORK_H

#include "ipx.h"
#include "tecb.h"
#include "nettypes.h"

#define Spew_init(x)	Spew(DSRC_NETWORK_InitShut,x)
#define Spew_PD(x)	Spew(DSRC_NETWORK_PackDump,x)
#define Spew_up(x)	Spew(DSRC_NETWORK_Update,x)
#define Spew_admin(x)	Spew(DSRC_NETWORK_Admin,x)
#define Spew_game(x)	Spew(DSRC_NETWORK_Game,x)
#define Spew_node(x)	Spew(DSRC_NETWORK_Node,x)
#define Spew_WD(x)	Spew(DSRC_NETWORK_Watchdog,x)
#define Spew_time(x)	Spew(DSRC_NETWORK_Time,x)

typedef enum PacketType_ {
	GAME_QUERY,

	NODE_QUERY,
	NODE_REPLY,
	NODE_DELETE,

	OBJ_UPDATE,
	OBJ_DESTROY,
	OBJ_SLEEP,		// Implement this later...
	OBJ_WAKE,		// Implement this later...

	TIME_SYNC_REQ,
	TIME_SYNC_REP,
	NET_NUM_PACKET_TYPES
} PacketType;

// Public data structures

typedef struct {
	uint malformed;
	uint oversized;
	uint update_loops;
	uint packets_received[NET_NUM_PACKET_TYPES];
	uint packets_sent[NET_NUM_PACKET_TYPES];
} NetStats;

typedef struct NetNode_ {
	bool active;
	bool WD_packet_sent;
	BYTE net_addr[10];		// internetwork address of node holding objid
	BYTE local_target[6];		// routing info
	long last_time;			// last update time (this is local, not net time)
	long response_time;		// how long we guess it'll take for this node to reply
} NetNode;

// Public global datumz

extern NetStats net_stats;
extern NetNode netNodes[NET_NUM_MAX_NODES];		// list of nodes in the gameID
extern int net_err;						// last error from Novell API

// Functions that'll be available

extern void MHexDump(char *addr, int len);

extern bool net_init(WORD socket);             // socket identifies the application
extern GameID net_join_group(GameID game);	// join group *game (NULL_ID to find an empty group
extern bool net_leave_group(void);			// leave the current group
extern bool net_send_all(PacketType type, ObjID obj, char *data, ushort length);
extern bool net_send(NodeID target, PacketType type, ObjID obj, char *data, ushort length);
extern void net_update();
extern void net_exit();

#endif /* NETWORK_H */


// Netobj.h			// Eric McCall - 1993 //
//
// Include file for network object handler
//

#ifndef NETOBJ_H
#define NETOBJ_H

#ifndef NETWORK_H
#include "network.h"
#endif

#define Spew_obj(x)	Spew(DSRC_NETWORK_Object,x)
#define Spew_oa(x)	Spew(DSRC_NETWORK_ObjAdmin,x)

typedef struct NetObj_ {
	bool active;			// is this object ID in use ?
	NodeID nodeID;			// index into array of NetNode
	ObjID index;			// index into array of NetObjs (either here or in remote array)
	ulong local_obj_id;		// local object system ID (maybe a pointer to a name string...)
	ulong time;				// time of last update (sent or received, depending on where the object is stored)
	// instead of this, should have callback to update function?
	char data[NOBJ_DATA_BUFF_SIZE];	// most recent network data received about the object ??
} NetObj;

extern NobjID net_create_obj(ulong ext_objID);
extern NetObj netObjs[NET_NUM_MAX_NOBJS];		// index into this is ObjID
extern void nobj_update( void );

#endif // NETOBJ_H
