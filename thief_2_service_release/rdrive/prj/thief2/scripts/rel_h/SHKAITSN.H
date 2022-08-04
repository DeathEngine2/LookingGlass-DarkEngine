/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: $
//
// Turret senses
//

#ifndef __SHKAITSN_H
#define __SHKAITSN_H

#include <aibassns.h>

#pragma once
#pragma pack(4)

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAITurretSenses
//

class cAITurretSenses : public cAISenses
{
private:
   virtual floatang GetVisionFacing() const;
};

///////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__SHKAITSN_H */
