/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pkupdate.h 1.1 1996/10/11 22:29:18 dc Exp $

#ifndef __PKUPDATE_H
#define __PKUPDATE_H

#include <packets.h>
#include <physics.h>
#include <appobj.h>

typedef struct {
   packetHeader;
   GlobalID ourGID;
   PhysicsState phys;
} packetUpdate;

void sendUpdatePacket(ObjID usID);
void RecvUpdatePacket(packetUpdate *pk);

#define SendUpdatePacket(oid) \
   do { \
      if (netWork) \
         sendUpdatePacket(oid); \
   } while (0)

#endif // __PKUPDATE_H

