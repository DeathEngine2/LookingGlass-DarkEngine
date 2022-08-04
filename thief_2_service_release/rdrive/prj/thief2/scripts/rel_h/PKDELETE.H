/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pkdelete.h 1.6 1997/09/18 00:08:47 mahk Exp $

#ifndef __PKDELETE_H
#define __PKDELETE_H

#ifdef NETWORK_ENABLED

#include <packets.h>
#include <physics.h>
#include <globalid.h>


#ifdef __cplusplus
typedef struct packetDelete : public packetHeader {
#else 
typedef struct packetDelete {
   packetHeader;
#endif 
   GlobalID killGID;
} packetDelete;

EXTERN void sendDeletePacket(ObjID usID);
EXTERN void RecvDeletePacket(packetDelete *pk);

#define SendDeletePacket(oid) \
   do { \
      if (netWork) \
         sendDeletePacket(oid); \
   } while (0)

#else  // !NETWORK_ENABLED

// just null this out
#define SendDeletePacket(oid) 
   
#endif 
#endif 
