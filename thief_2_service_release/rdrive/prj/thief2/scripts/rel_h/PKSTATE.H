/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pkstate.h 1.4 1997/09/18 00:08:51 mahk Exp $

#ifndef __PKSTATE_H
#define __PKSTATE_H

#ifdef NETWORK_ENABLED

#include <packets.h>
#include <physics.h>
//
// MAHK 9/17/97.   I HAVE REMOVED APPOBJSTATE FROM THE CODE BASE.  THIS IS JUST A TOMBSTONE
//


#ifdef __cplusplus
typedef struct packetState : public packetHeader {
#else 
typedef struct packetState {
   packetHeader;
#endif 
   GlobalID ourGID;
} packetState;

void sendStatePacket(ObjID usID);
void RecvStatePacket(packetState *pk);

#define SendStatePacket(oid) \
   do { \
      if (netWork) \
         sendStatePacket(oid); \
   } while (0)

#else  // NETWORK_ENABLED

// just null it out
#define SendStatePacket(oid)

#endif // NETWORK_ENABLED

#endif // __PKSTATE_H

