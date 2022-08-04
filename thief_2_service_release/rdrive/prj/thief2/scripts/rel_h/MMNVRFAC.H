/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/mmnvrfac.h 1.1 1997/11/18 10:42:13 kate Exp $

#ifndef __MMNVRFAC_H
#define __MMNVRFAC_H

// This module contains an array of all the factory methods for creating
// maneuvers

#include <mmanuver.h>

EXTERN cManeuverFactory *g_aManeuverFactoryTable;
EXTERN int g_iNumManeuverFactories;

#endif
