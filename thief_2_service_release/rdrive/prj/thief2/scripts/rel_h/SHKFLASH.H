/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkflash.h 1.3 1999/11/19 14:52:39 adurant Exp $
//
// gun flashes
//

This file has been moved to gunflash.h AMSD


#ifndef __SHKFLASH_H
#define __SHKFLASH_H

#include <matrixs.h>
#include <objtype.h>

// Create flash objects as specified by archetype flash links at the various VHots of the gun
// Each link identifies the flash object (destination) and the vhot number as data
EXTERN void CreateGunFlashes(ObjID archetypeID, ObjID gunID, 
                             mxs_ang facingOffset = 0,
                             BOOL isGhost = FALSE);

EXTERN void GunFlashInit(void);
EXTERN void GunFlashTerm(void);

#endif // __SHKFLASH_H
