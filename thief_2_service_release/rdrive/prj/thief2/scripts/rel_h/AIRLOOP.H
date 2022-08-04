/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/airloop.h 1.2 1997/01/21 21:27:32 CNORDEN Exp $
#ifndef __AIRLOOP_H
#define __AIRLOOP_H

////////////////////////////////////////////////////////////
// AIR-SPECIFIC LOOP CLIENTS
//

//
// AIR SIM CLIENT
// 
DEFINE_LG_GUID(LOOPID_AirSim, 0x40);
EXTERN struct sLoopFactoryDesc AirSimLoopFactory;

//
// AIR RENDER CLIENT
// 
DEFINE_LG_GUID(LOOPID_AirRender, 0x41);
EXTERN struct sLoopFactoryDesc AirRenderLoopFactory;

////////////////////////////////////////////////////////////
// AIR LOOPMODES 
//
// These loopmodes are really just client sets.  They 
// are intended to be included by other loopmodes
// 

//
// AIR GAME MODE CLIENTS
// 
DEFINE_LG_GUID(LOOPID_AirGameClients, 0x42);
EXTERN struct sLoopModeDesc AirGameClients; 

DEFINE_LG_GUID(LOOPID_AirBaseClients, 0x46);
EXTERN struct sLoopModeDesc AirBaseClients;
//
// KEEP THIS FILE RELATIVELY CLEAR OF JUNK!  DO NOT PUT YOUR SYSTEM'S API HERE! 
// DO NOT INCLUDE OTHER HEADER FILES FROM THIS FILE!
//

 
#endif // __AIRLOOP_H
