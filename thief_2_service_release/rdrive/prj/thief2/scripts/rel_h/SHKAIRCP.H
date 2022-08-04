/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkaircp.h 1.1 1999/03/25 17:39:37 JON Exp $
//
// Ranged-combat-related properties and relations
//

#ifndef __SHKAIRCP_H
#define __SHKAIRCP_H

#include <property.h>
#include <relation.h>

////////////////////////////////////////////////////////////////////////////////

F_DECLARE_INTERFACE(IShockRangedProperty);

#define SHKAI_RANGED_PROP_NAME "ShkAIRange"

struct sShockRanged
{
   int   m_minimumDist;
   int   m_maximumDist;
   float m_firingDelay;   
   int   m_fireWhileMoving;
};

class cShockRanged: public sShockRanged
{
public:
   cShockRanged();
};

#undef  INTERFACE
#define INTERFACE IShockRangedProperty
DECLARE_PROPERTY_INTERFACE(IShockRangedProperty)
{
   DECLARE_UNKNOWN_PURE();
   DECLARE_PROPERTY_PURE();
   DECLARE_PROPERTY_ACCESSORS(cShockRanged *);
};

////////////////////////////////////////////////////////////////////////////////

EXTERN IShockRangedProperty *g_pShockRangedProp;

////////////////////////////////////////////////////////////////////////////////

EXTERN void ShockAIInitRangedProp();
EXTERN void ShockAITermRangedProp();

EXTERN sShockRanged* ShockAIGetRangedProp(ObjID objID);

////////////////////////////////////////////////////////////////////////////////

#endif






