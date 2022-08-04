/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  7/25/99 9:29:17 PM

  File:  rgGuids.h

  Description:  GUIDs used by the interfaces of RenderG


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgguids.h 1.2 1970/01/01 00:00:00 Zarko Exp $

#pragma once

#ifndef _RGGUIDS_H
#define _RGGUIDS_H


//_____INCLUDES_AND_DEFINITIONS___________________________

DEFINE_LG_GUID(IID_IRGCanvas, 0x287);
DEFINE_LG_GUID(IID_IRGDisplayCanvas, 0x290);


DEFINE_LG_GUID(IID_IRenderG, 0x292);
DEFINE_LG_GUID(IID_IRGCore, 0x2a3);


DEFINE_LG_GUID(IID_IRGGraphicCaps, 0x2e7);
DEFINE_LG_GUID(IID_IRG_CPUID, 0x2f3);


DEFINE_LG_GUID(IID_IRGOverlays, 0x305);
//
DEFINE_LG_GUID(IID_IRGTexMng, 0x307);
DEFINE_LG_GUID(IID_IRGTexDriver, 0x310 );
DEFINE_LG_GUID(IID_IRGView, 0x308);

DEFINE_LG_GUID(IID_IRGObjFactory, 0x30B);

DEFINE_LG_GUID(IID_IRGShader, 0x30f );

DEFINE_LG_GUID(IID_ILGSurface, 0x25e);

DEFINE_LG_GUID(IID_IRGOverlay, 0x306);
DEFINE_LG_GUID(IID_IRGBillboard, 0x312);
DEFINE_LG_GUID(IID_IRGTexRectangle, 0x345 );
DEFINE_LG_GUID(IID_IRGOverlaySys, 0x346 );
//
DEFINE_LG_GUID(IID_IRGFontSys, 0x291);




#endif //_RGGUIDS_H