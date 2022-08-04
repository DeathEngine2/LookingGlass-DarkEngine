///////////////////////////////////////////////////////////////////////////////
// $Source: x:/prj/tech/libsrc/loco/RCS/locotype.h $
// $Author: JON $
// $Date: 1996/11/06 10:19:53 $
// $Revision: 1.1 $
//
// Locomotion basic types

#ifndef __LOCOTYPE_H
#define __LOCOTYPE_H

// Locomotors use IDs so that the app can save them off 
// if it wants
typedef ushort LocomotorID;
#define LOCOMOTOR_INVALID USHRT_MAX

// These are defined for real in track.h and loco.h
typedef struct Locomotor;
typedef struct LocoSegment;
typedef struct LocoTPt;
typedef struct LocoTPtInfo;

#endif // __LOCOTYPE_H
