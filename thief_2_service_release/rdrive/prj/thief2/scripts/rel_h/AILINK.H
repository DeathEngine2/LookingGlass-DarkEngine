/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/ailink.h 1.7 1998/01/28 13:43:55 TOML Exp $

#ifndef __AILINK_H
#define __AILINK_H
#include <linktype.h>
#include <link.h>

//
// AI LINK RELATIONS & STUFF
//

EXTERN RelationID gAIRelationIDs[];
EXTERN int gNumAIRelations;

#define gAIAttackLinkID (gAIRelationIDs[0])
#if 0
#define gAIDefendLinkID (gAIRelationIDs[1])
#define gAIFollowLinkID (gAIRelationIDs[2])
#define gAIFleeLinkID (gAIRelationIDs[3])
#endif
#define gAISenseLinkID (gAIRelationIDs[1])
#define gAIFastMovingObjectLinkID (gAIRelationIDs[2])
#define gAIPatrolLinkID (gAIRelationIDs[3])
#define gAICurrentPatrolLinkID (gAIRelationIDs[4])

struct sAISenseLinkData
{
   BOOL    sense;                // can I currently sense this object through any method?
   ulong   lastSense;            // when was the last time I sensed object?
   BOOL    lastKnownLocValid;    // do we have a last known location?
   sAIPoint lastKnownLoc;         // where was the last known location?

   int     senseLevel;           // the "heat level" of sensing someone.  0..10000, 10000 = can fully sense
   int     peakSenseLevel;       // the highest "heat level" yet reached.
   ulong   lastSenseLevelUpdate; // when was the last time we updated the senseLevel?

   BOOL    fCanRaycast;           // Could I have LOS if I had 360 vision?
   BOOL    los;                  // do I have LOS now?
   ulong   lastLos;              // when did I last have LOS?
   ulong   lastLosCalculation;   // why was the last time I tried an LOS calculation?

   int     senseChangePerSec;    // how fast is the sense level changing?
   int     distanceRating;       // 0..100, how much is target distance helping to raise sense level
   int     movementRating;       // 0..100, how much is target movement helping to raise sense level
   int     lightRating;          // 0..100, how much is target distance helping to raise sense level
};

struct sAIFollowLinkData
{
   eAIPriority priority;      // what's the priority to follow this obj?
   float           accuracy;      // what accuracy?
   int             frobCommand;   // do something when I get close to the obj?
};

#endif // !__AILINK_H
