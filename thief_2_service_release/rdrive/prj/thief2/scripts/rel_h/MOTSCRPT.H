/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/motscrpt.h 1.1 1997/12/31 13:29:26 kate Exp $
#pragma once  
#ifndef __MOTSCRPT_H
#define __MOTSCRPT_H

#include <objscrt.h>

///////////////////////////////////////
//
// Motion services
//

DECLARE_SCRIPT_SERVICE(Motion, 0xf7)
{
   // Play motion with name "name"
   STDMETHOD_(boolean,Play)(const object obj, const char *name) PURE;
};


#endif // __MOTSCRPT_H
