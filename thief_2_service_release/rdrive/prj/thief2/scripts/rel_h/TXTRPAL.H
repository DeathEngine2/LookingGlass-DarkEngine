/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/editor/RCS/txtrpal.h 1.4 1998/08/08 18:43:55 dc Exp $

#ifndef __TEXTRPAL_H
#define __TEXTRPAL_H
#include <brushgfh.h>

#define TPAL_XTRA_DONE   (4)
#define TPAL_XTRA_DETACH (3)
#define TPAL_XTRA_REMOVE (2)
#define TPAL_XTRA_SKY    (1)

#define TpalIsExtraButton(x) (x<0)
#define TpalGetExtraCode(x)  (-(x))

// called when a texture is clicked on.  returns whether to destroy texture pal.
typedef bool (*TexturePalCall)(int texture);

EXTERN void CreateTexturePalette(TexturePalCall update);
EXTERN void DestroyTexturePalette(void);

EXTERN void ToggleTexturePalette(TexturePalCall update);

EXTERN bool TexturePaletteVisible(void);
EXTERN void TexturePaletteUpdate(GFHUpdateOp op);

EXTERN void TexturePaletteSelect(int texture);

#endif // __TEXTRPAL_H
