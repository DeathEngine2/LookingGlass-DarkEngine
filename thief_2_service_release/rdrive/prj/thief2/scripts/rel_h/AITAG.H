/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/aitag.h 1.4 1997/10/04 17:11:52 TOML Exp $

#ifndef __AITAG_H
#define __AITAG_H

#include <tagtype.h>

EXTERN sTag* gAITags[];

#define gAIDistanceRatingTag (gAITags[0])
#define gAIMovementRatingTag (gAITags[1])
#define gAILightingRatingTag (gAITags[2])
#define gAIRelativeZPosTag (gAITags[3])
#define gAINearbyFriendsTag (gAITags[4])
#define gAILocationTag (gAITags[5])
#define gAIObjectTag (gAITags[6])

#endif // !__AITAG_H
