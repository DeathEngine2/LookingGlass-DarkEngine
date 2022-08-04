/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pupprop.h 1.2 1998/03/26 13:53:16 mahk Exp $

#ifndef __PUPPROP_H
#define __PUPPROP_H

#include <property.h>
#include <puppet.h>

////////////////////////////////////////////////////////////
// PUPPET PROPERTY
//

#undef INTERFACE
#define INTERFACE IPuppetProperty
DECLARE_PROPERTY_INTERFACE(IPuppetProperty)
{
   DECLARE_UNKNOWN_PURE(); 
   DECLARE_PROPERTY_PURE(); 
   DECLARE_PROPERTY_ACCESSORS(cPuppet*); 
}; 


#define PROP_PUPPET_NAME "Puppet"

//
// Instantiate the puppet property. 
//
EXTERN IPuppetProperty *PuppetPropertyInit(void);

#endif // __PUPPROP_H




