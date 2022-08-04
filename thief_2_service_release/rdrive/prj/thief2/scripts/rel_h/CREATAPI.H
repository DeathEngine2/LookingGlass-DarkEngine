/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/creatapi.h 1.1 1997/10/29 18:45:41 kate Exp $
// This used for getting class pointers for creatures
// Should only be included by cpp files that want to think of creature
// as mesh or motor

#ifndef __CREATAPI_H
#define __CREATAPI_H

#include <meshtype.h>
#include <motrtype.h>
#include <objtype.h>
// why include these?
#include <meshapi.h>
#include <motorapi.h>

IMesh *CreatureGetMeshInterface(const ObjID objID);
IMotor *CreatureGetMotorInterface(const ObjID objID);


#endif
