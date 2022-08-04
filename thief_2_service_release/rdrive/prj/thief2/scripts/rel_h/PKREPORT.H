/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pkreport.h 1.3 1997/09/18 00:08:50 mahk Exp $

#ifndef __PKREPORT_H
#define __PKREPORT_H

#ifdef NETWORK_ENABLED

#include <packets.h>
#include <physics.h>
#include <globalid.h>

typedef struct {
   packetHeader;
   GlobalID srcGID;
   GlobalID dstGID;
   int data;
} packetReport;

void sendReportPacket(ObjID reporter, ObjID reportee, int data);
void RecvReportPacket(packetReport *pk);

#define SendReportPacket(src,dst,dat) \
   do { \
      if (netWork) \
         sendReportPacket(src,dst,dat); \
   } while (0)

#else  // NETWORK_ENABLED

// just null this out
#define SendReportPacket(src,dst,dat)

#endif // NETWORK_ENABLED

#endif // __PKREPORT_H

