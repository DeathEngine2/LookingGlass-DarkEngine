/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  12/14/99 1:56:31 PM

  File:  rg.h

  Description:  RenderG's main staging area.  To be included
                  by the clients that need basic functionalty
                  of setting the rendering states, textures
                  and drawing the primitives.


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rg.h 1.1 1970/01/01 00:00:00 Zarko Exp $

#pragma once 

#ifndef _RG_H
#define _RG_H


//_____INCLUDES_AND_DEFINITIONS___________________________

#ifndef _RENDERG_H
#include <RenderG.h>
#endif

#ifndef _RGVIEW_H
#include <rgView.h>
#endif

#ifndef _RGTEXMNG_H
#include <rgTexMng.h>
#endif


#ifndef _RGTEMP_H
#include <rgTemp.h>
#endif




#endif //_RG_H