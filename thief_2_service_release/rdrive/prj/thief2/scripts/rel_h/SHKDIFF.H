/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkdiff.h 1.1 1999/06/08 16:09:27 mahk Exp $

#ifndef __SHKDIFF_H
#define __SHKDIFF_H

enum eShockDifficulty
{
   kShockDiffPlaytest,
   kShockFirstDiff,
   kShockDiffEasy = kShockFirstDiff, 
   kShockDiffNormal,
   kShockDiffHard,
   kShockDiffImpossible,
   kShockLimDiff, 
   kNumShockDiffs = kShockLimDiff - kShockFirstDiff,
   kShockDiffMultiplay = kShockLimDiff,
}; 

#endif // __SHKDIFF_H
