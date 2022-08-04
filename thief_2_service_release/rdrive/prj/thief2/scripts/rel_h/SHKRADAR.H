/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkradar.h 1.2 1999/02/25 16:21:02 XEMU Exp $

#ifndef __SHKRADAR_H
#define __SHKRADAR_H

#include <rect.h>

void RadarOn(void);
void RadarOff(void);
void RadarScan(void);
void RadarStatus(int *pTargetsNum, Point **ppTargetPts, int **ppTargetData);

#endif