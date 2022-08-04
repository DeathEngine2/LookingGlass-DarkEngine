/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/drum/RCS/drumi.h 1.1 1996/05/21 16:26:40 TOML Exp $
// internal drum system prototypes and data for internal library routines

#ifndef __drumi_h
#define __drumi_h

#include "drumx.h"
#include <lg.h>

// pointers to the actual drumSpriteTables.  These are malloced and set 
// at init time and don't change.
extern DrumSpriteData *currentSpriteTable;
extern DrumSpriteData *oldSpriteTable;
extern DrumSpriteData **sortedSprites;

extern int maxSprites;
extern int maxUsedSprites;

extern grs_bitmap *source_image, *source_depth, *dest_image, *dest_depth;

extern void initSprite(DrumSpriteData *s);
extern void drumSpritesInit();
extern void drumSpritesCleanup();
extern void drumSpritesForget();
#endif
