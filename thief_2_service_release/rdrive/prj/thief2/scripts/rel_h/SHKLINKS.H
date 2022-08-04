/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shklinks.h 1.2 1998/11/18 10:54:30 JON Exp $

#ifndef __SHKLINKS_H
#define __SHKLINKS_H

#include <comtools.h>

F_DECLARE_INTERFACE(IRelation);

EXTERN IRelation * g_pReplicatorLinks;
EXTERN IRelation * g_pMutateLinks;

EXTERN void ShockLinksInit(void);
EXTERN void ShockLinksTerm(void);
#endif 