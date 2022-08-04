/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

#ifndef __AIROVRLY_H
#define __AIROVRLY_H

// Individual overlays
#define kOverlayCompass    0
#define kOverlayNano       1
#define kNumOverlays       4

// Change modes
#define kOverlayModeOff    0
#define kOverlayModeOn     1
#define kOverlayModeToggle 2

EXTERN void AirOverlayInit(void);
EXTERN void AirOverlayTerm(void);
EXTERN void AirOverlayDoFrame(void);
EXTERN void AirOverlayChange(int which, int mode);
EXTERN void AirOverlayComboChanged();

#endif // __AIROVRLY_H
