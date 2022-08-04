/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkpjbas.h 1.2 1999/11/19 14:53:39 adurant Exp $

This file has been moved to projbase.h AMSD


#ifndef __SHKPJBAS_H
#define __SHKPJBAS_H

#include <mxang.h>

// info structure attached to a projectile archetype object
typedef struct sProjectile
{
   int m_spray;             // number of projectiles/trigger pull (instantaneous)
   mxs_ang m_spread;        // random angular error per shot
} sProjectile;

#endif
