/*
 
Copyright (c) 1995, Microsoft Corporation.  All Rights Reserved.

Module Name:

    irlwin.h

*/

#ifndef __IRLWIN_H__
#define __IRLWIN_H__

#ifndef WIN32
#define WIN32
#endif

#include "irlapi.h"
#include "ddraw.h"
#include "d3d.h"

/*
 * GUIDS used by Reality Lab Windows interface
 */
DEFINE_GUID(IID_IRLWinDevice,   0xc5016cc0, 0xd273, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IWinRealityLab, 0xc5016cc1, 0xd273, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);

WIN_TYPES(IRLWinDevice, RLWINDEVICE);
WIN_TYPES(IWinRealityLab, WINREALITYLAB);

#undef INTERFACE
#define INTERFACE IRLWinDevice

DECLARE_INTERFACE_(IRLWinDevice, IRLDevice)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLDevice methods (unchanged from IRLObj.h)
     */
    STDMETHOD(Update)(THIS) PURE;
    STDMETHOD(Sync)(THIS) PURE;
    STDMETHOD(AddUpdateCallback)(THIS_ RLUpdateCallback, void* arg) PURE;
    STDMETHOD(RemoveUpdateCallback)(THIS_ RLUpdateCallback, void* arg) PURE;

    STDMETHOD(SetDither)(THIS_ BOOL) PURE;
    STDMETHOD(SetGamma)(THIS_ RLValue) PURE;
    STDMETHOD(SetShades)(THIS_ ULONG) PURE;
    STDMETHOD(SetQuality)(THIS_ RLRenderQuality) PURE;
    STDMETHOD(SetWireframeOptions)(THIS_ ULONG options) PURE;
    STDMETHOD(SetTextureQuality)(THIS_ RLTextureQuality) PURE;
    STDMETHOD(SetColourModel)(THIS_ RLColourModel) PURE;
    STDMETHOD(SetPalette)(THIS_ ULONG start, ULONG size, RLPaletteEntry *palette) PURE;

    STDMETHOD(GetViewports)(THIS_ interface IRLViewportArray **return_views) PURE;
    STDMETHOD(GetImageFormat)(THIS_ RLImage **) PURE;
    STDMETHOD(GetPalette)(THIS_ ULONG start, ULONG size, RLPaletteEntry **return_palette) PURE;

    STDMETHOD_(BOOL, GetDither)(THIS) PURE;
    STDMETHOD_(ULONG, GetShades)(THIS) PURE;
    STDMETHOD_(ULONG, GetHeight)(THIS) PURE;
    STDMETHOD_(ULONG, GetWidth)(THIS) PURE;
    STDMETHOD_(ULONG, GetPolygonsDrawn)(THIS) PURE;
    STDMETHOD_(ULONG, GetWireframeOptions)(THIS) PURE;
    STDMETHOD_(RLValue, GetGamma)(THIS) PURE;
    STDMETHOD_(RLRenderQuality, GetQuality)(THIS) PURE;
    STDMETHOD_(RLColourModel, GetColourModel)(THIS) PURE;
    STDMETHOD_(RLTextureQuality, GetTextureQuality)(THIS) PURE;

    /*
     * IRLWinDevice methods
     */

    /* Repaint the window with the last frame which was rendered. */
    STDMETHOD(HandlePaint)(THIS_ HDC hdc) PURE;

    /* Respond to a WM_ACTIVATE message. */
    STDMETHOD(HandleActivate)(THIS_ WORD wparam) PURE;

    /* Respond to a WM_MOVE message. */
    STDMETHOD_(HRESULT, HandleMove)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IWinRealityLab

DECLARE_INTERFACE_(IWinRealityLab, IRealityLab)
{
    IUNKNOWN_METHODS(PURE);
    IREALITYLAB_METHODS; /* these are never pure */

    /*
     * IWinRealityLab methods
     */

    /* Create a Windows Device using DirectDraw surfaces */
    STDMETHOD(CreateDeviceFromSurface)
    (   THIS_ LPGUID lpGUID, LPDIRECTDRAW lpDD,
        LPDIRECTDRAWSURFACE lpDDSBack, IRLWinDevice **
    ) PURE;

    /* Create a Windows Device using D3D objects */
    STDMETHOD(CreateDeviceFromD3D)
    (   THIS_ LPDIRECT3D lpD3D, LPDIRECT3DDEVICE lpD3DDev,
        IRLWinDevice **
    ) PURE;

    /* As CreateWinDevice(), but takes a DC instead.
     * It is the caller's responsibility to destroy the DC after
     * the Device is destroyed.
     */
    STDMETHOD(CreateDeviceFromHWND)
        (THIS_ HWND hwnd, LPGUID lpGUID, int width, int height, IRLWinDevice **) PURE;

    #if 0
    /* Create a texure from a DC */
    STDMETHOD(CreateTextureFromDC)(THIS_ HDC context, int width, int height, IRLTexture **) PURE;
    #endif
    STDMETHOD(CreateTextureFromSurface)(THIS_ LPDIRECTDRAWSURFACE lpDDS, IRLTexture **) PURE;
};

#endif
