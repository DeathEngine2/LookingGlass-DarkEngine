/*
 * $Source: x:/prj/tech/libsrc/scrnman/RCS/scrnman.h $
 * $Revision: 1.3 $
 * $Author: JAEMZ $
 * $Date: 1998/06/22 17:53:41 $
 *
 * Screen Manager
 *
*/

#ifndef __SCRNMAN_H
#define __SCRNMAN_H
#pragma once

#include <dev2d.h>

// The big purpose of this module is to hide whether you
// are page flipping or offscreen buffered, and to hide
// much 8 vs 16 bit stuff like blackening screens

// Call before using
EXTERN void ScrnInit();

// Free up any alloced memory
EXTERN void ScrnClose();

// Do you want fullscreen or debug?  Default is TRUE.
EXTERN void ScrnSetFullscreen(bool b);
EXTERN bool ScrnGetFullscreen(void);

// Do you want to flip or not?  Default is FALSE.
EXTERN void ScrnSetFlippable(bool b);
EXTERN bool ScrnGetFlippable(void);

// Do you want to zbuffer or not?  Default is FALSE.
EXTERN void ScrnSetZbuffer(bool b);

// Use this value to get the fast value, but don't 
// change it directly
EXTERN bool gScrnZbuffer;
EXTERN bool ScrnGetZbuffer(void);

// Actually perform the mode change with current
// fullscreen and flippable defaults
// -1 resets current mode
EXTERN void ScrnSetDevice(int id);

// Which is the currently set device
EXTERN int ScrnCurDevice(void);

// How many devices are there?
EXTERN int ScrnNumDevices(void);

// Get a text description of the device
EXTERN int ScrnGetDeviceDescription(int i,char **desc);

// Set res based on the width and height
// Also tries to get bitDepth, but overrides to 16
// in d3d mode
// Preserves palette
// This is preferred over ScrnSetRes
EXTERN int ScrnSetWidthHeight(int w,int h,int bitDepth);

// returns -1 if not yet set
EXTERN int ScrnGetRes();

// Gets the current bitdepth
EXTERN int ScrnGetBitDepth();

// clear the screen to black and blacken the palette
// note that this works great, 8 or 16 bit as a prelude
// to loading a new screen
EXTERN void ScrnBlacken();

// Keep this frame visible, no flipping or
// back buffer
EXTERN void ScrnStartNoFlipFrame();
EXTERN void ScrnEndNoFlipFrame();

// call the background callback if present
EXTERN void ScrnStartFrame();

// blit or page flip, transparently, woo woo.
EXTERN void ScrnEndFrame();

// When in lgd3d mode, break and restore any locks on the display 
// surface and switch r3d drivers.
// These calls need to bracket sections of the renderer that
// are hardware accelerated.
EXTERN void ScrnUseLgd3d(void);
EXTERN void ScrnUseG2(void);


// set the current canvas to be the visible screen
// the idea is you're not page flipping or blitting
// in fact, if you do an end_frame in this mode, you get
// an error
EXTERN void ScrnSetVisible();

// set the current canvas to be the offscreen canvas(default)
EXTERN void ScrnSetOffscreen();

// load and use this palette
EXTERN void ScrnNewPalette(uchar *,int start,int size);

// make the current palette black and use it
EXTERN void ScrnNewBlackPalette();

// load but do not set this palette
EXTERN void ScrnLoadPalette(uchar *pal,int start,int size);

// set the currently loaded palette
EXTERN void ScrnUsePalette();

// return pointer to loaded palette.  Beware, don't mess with it.
EXTERN uchar *ScrnGetPalette();

// Dirty rectangle saveunder system, works both with
// page flipping and non

// Destination determined by x,y,w,h
// and just x,y for the source
// If null is passed as bitmap it uses the current background
// flag for permanency, which are shared across all pages
// flag for copying or not

EXTERN void ScrnAddSaveUnder(int dx,int dy,int w,int h,int sx,int sy,grs_bitmap *bm,bool perm,bool copy,int type);

// Render the saveunders.  Someday this could be 
// handle based
EXTERN void ScrnRenderSaveUnders(BOOL render, int type);

// Kills all saveunders
EXTERN void ScrnResetSaveUnders();

// Tells how many pages there are
// We do it this way because each user 
// might want different timings
EXTERN int ScrnGetPages();

// Tells you which page you are on
EXTERN int ScrnGetPageNum();

enum {
   kSUTypeAll,
   kSUTypeMouse,
   kSUTypeCockpit,
};


// Are we in d3d mode?
EXTERN bool gScrnD3d;

// Routines in disfavor... Don't use these unless you have to...

// Switch display providers on the fly...
// In general, use the higher level one though...
// This is for more fine control
EXTERN void ScrnSetDisplay(int kind, int flags);

// set a new screen mode.  Preserve the previous
// palette or not
EXTERN int ScrnSetRes(int mode,bool pres_pal);

#endif // __SCRNMAN_H





