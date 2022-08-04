/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/physprop.h 1.5 1997/09/24 11:46:23 CCAROLLO Exp $

#ifndef PHYSPROP_H
#define PHYSPROP_H

#include <property.h>
#include <phystype.h>


F_DECLARE_INTERFACE(IPhysStateProperty);

#undef INTERFACE
#define INTERFACE IPhysStateProperty
DECLARE_COMPLEX_PROPERTY(PhysicsState,PhysState);

////////////////////////////////////////////////////////////
// THE INSTANTIATED PHYSICS PROPERTIES
//

#define PROP_PHYSSTATE_NAME   "PhysState" 
#define PROP_PHYSSTATE2_NAME  "NetPhysState" 
#define PROP_GRAVITY_NAME     "Gravity"

//
// Instantiate a physics property. 
//

EXTERN IPhysStateProperty* PhysStatePropInit(const char* physname, int* obj2physarray, struct sCompactArrayProp* prop, BOOL Virtual);
EXTERN void CreateGravProp(void);

#endif // PHYSPROP_H
