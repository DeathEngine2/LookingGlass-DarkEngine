/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/drum/RCS/drumx.h 1.1 1996/05/21 16:26:39 TOML Exp $
// xternal drum system prototypes/headers for the app to see

#ifndef __DRUMX_H
#define __DRUMX_H

#include <2d.h>
#include <fix.h>
#include <rect.h>

typedef struct {
   grs_bitmap *pix;     
   grs_bitmap *zed;
   short       x,y;
   short       w,h;
   fix         virz;
   short       id;
   short       flags;
   ushort     *pal;   // in case have 8-bit source and 16-bit dest
   long        data;  // app specific data, for convenience.  Can also
                     // be used by span mergers
} DrumSpriteData;

// sprite flags
#define SPRITE_EMPTY       0x1
#define SPRITE_REMOVE      0x2
#define SPRITE_UPDATED     0x4
#define SPRITE_OVERLAY     0x8
#define SPRITE_BACKGROUND  0x10

// drum flags for drumSetupBuffers
#define DRUM_FORGET_NONOVERLAY 0x1
//#define DRUM_FORGET_ALL        0x2 // not implemented yet

// flags for drumEndFrame
#define DFF_NO_OVERLAYS 0x1

// merge types for drumEndFrame
#define SM_NOMERGE      0
#define SM_ZREAD        1
#define SM_ZREADWRITE   2
#define SM_FILLSOLID    3
#define NUM_MERGE_FUNCS 4

typedef struct DrumSpanData {
   int scry,leftx,width;
   uchar type, pad[3];
} DrumSpanData;

typedef struct {
        Rect r;
        uchar flags; // don't use these yet
} DirtyRect;

// dirty rectangle flags
#define DRECT_USED      1
#define DRECT_INTERNAL  2 // flag for internal drum purposes only

extern DirtyRect *dirtyRects;
extern int maxDRects;
extern int maxUsedDRects;

extern DirtyRect *blitRects;
extern int maxBlitRects;
extern int maxUsedBlitRects;

extern DrumSpriteData **sortedSprites;
extern int maxSprites;
extern int maxUsedSprites;

bool drumStartup(int num_sprites);
bool drumClosedown(void);
// This clears out span lists and assorted inter-frame junk.  Also,
// depending what flags are set, it can delete knowledge of sprites themselves. 
bool drumSetupBuffers(grs_bitmap *src_pix, grs_bitmap *src_zed,\
   grs_bitmap *dst_pix, grs_bitmap *dst_zed,uchar flags);

// Frees all non-overlay sprites.  must be called within a drum frame
void drumClearSprites(void);
DrumSpriteData *drumGetSprite(void);
bool drumUpdate(DrumSpriteData *meself);
bool drumFreeSprite(DrumSpriteData *meself);

void drumStartFrame(void);
void drumEndFrame(uchar merge_type, uchar flags);
void drumBlitChanges(grs_bitmap *foreground);

#endif
