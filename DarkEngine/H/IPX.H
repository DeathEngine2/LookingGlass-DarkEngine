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
