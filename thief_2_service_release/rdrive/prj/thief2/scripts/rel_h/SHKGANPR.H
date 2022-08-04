/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkganpr.h 1.3 1999/11/19 14:51:22 adurant Exp $
// Shock gun animation properties

#ifndef __SHKGANPR_H
#define __SHKGANPR_H

#include <propface.h>
#include <gunanim.h>

// Gun Anim 
#undef INTERFACE
#define INTERFACE IGunAnimProperty
DECLARE_PROPERTY_INTERFACE(IGunAnimProperty)
{
   DECLARE_UNKNOWN_PURE(); 
   DECLARE_PROPERTY_PURE(); 
   DECLARE_PROPERTY_ACCESSORS(sGunAnim*); 
}; 

#define PROP_GUN_ANIM_POST_NAME "AnimPost"
#define PROP_GUN_ANIM_PRE_NAME "AnimPre"

extern IGunAnimProperty *g_gunAnimPreProperty;
extern IGunAnimProperty *g_gunAnimPostProperty;

void GunAnimPropertyInit(void);
void GunAnimPropertyTerm(void);

#endif
