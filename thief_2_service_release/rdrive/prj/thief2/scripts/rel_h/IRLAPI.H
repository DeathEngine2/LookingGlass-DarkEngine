/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Id: irlapi.h,v 1.25 1995/12/04 11:37:21 sjl Exp $
 *
 * Copyright (c) RenderMorphics Ltd. 1993, 1994
 * Version 1.1
 *
 * All rights reserved.
 *
 * This file contains private, unpublished information and may not be
 * copied in part or in whole without express permission of
 * RenderMorphics Ltd.
 *
 */

#ifndef __IRLAPI_H__
#define __IRLAPI_H__

#include "irlobj.h"

#ifdef __cplusplus
extern "C" {
struct IRealityLab;
#endif

typedef void (*RLDevicePaletteCallback)
    (IRLDevice *dev, void *arg, int index, int red, int green, int blue);

typedef void (*RLDeviceRenderCallback)
(   IRLDevice *dev, void *arg, void *buffer1, void *buffer2,
    int x1, int x2, int y1, int y2
);

DEFINE_GUID(IID_IRealityLab,    0x4471be20, 0xd273, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
WIN_TYPES(IRealityLab, REALITYLAB);

/* Set the Reality Lab memory allocators */
STDAPI IRealityLabSetAllocator(RLMallocFunction, RLReallocFunction, RLFreeFunction);
STDAPI IRealityLabGetAllocator(RLMallocFunction *, RLReallocFunction *, RLFreeFunction *);


/* Create a Reality Lab API */
STDAPI IRealityLabCreate(LPREALITYLAB FAR *lplpRL);


#define IREALITYLAB_METHODS \
    STDMETHOD(CreateFrame)      (THIS_ IRLFrame *, IRLFrame **) PURE; \
    STDMETHOD(CreateMesh)       (THIS_ IRLMesh **) PURE; \
    STDMETHOD(CreateMeshBuilder)(THIS_ IRLMeshBuilder **) PURE; \
    STDMETHOD(CreateFace)       (THIS_ IRLFace **) PURE; \
    STDMETHOD(CreateAnimation)  (THIS_ RLAnimationType, IRLAnimation **) PURE; \
    STDMETHOD(CreateAnimationSet)(THIS_ IRLAnimationSet **) PURE; \
    STDMETHOD(CreateTexture)    (THIS_ RLImage *, IRLTexture **) PURE; \
    STDMETHOD(CreateLight)      (THIS_ RLLightType, RLColour, IRLLight **) PURE; \
    STDMETHOD(CreateMaterial)   (THIS_ RLValue ks, RLValue power, IRLMaterial **) PURE; \
    STDMETHOD(CreateDevice)     (THIS_ ULONG width, ULONG height, IRLDevice **) PURE; \
    STDMETHOD(CreateLightRGB) \
        (THIS_ RLLightType, RLValue reg, RLValue green, RLValue blue, IRLLight **) PURE; \
    \
    STDMETHOD(CreateShadow) \
    (   THIS_ IRLVisual *visual, IRLLight *light, \
        RLValue px, RLValue py, RLValue pz, \
        RLValue nx, RLValue ny, RLValue nz, \
        IRLVisual ** \
    ) PURE; \
    STDMETHOD(CreateViewport) \
    (   THIS_ IRLDevice *, IRLFrame *camera, ULONG xpos, ULONG ypos, \
        ULONG width, ULONG height, IRLViewport ** \
    ) PURE; \
    STDMETHOD(CreateWrap) \
    (   THIS_ RLWrapType, IRLFrame *ref, \
        RLValue ox, RLValue oy, RLValue oz, \
        RLValue dx, RLValue dy, RLValue dz, \
        RLValue ux, RLValue uy, RLValue uz, \
        RLValue ou, RLValue ov, \
        RLValue su, RLValue sv, \
        IRLWrap ** \
    ) PURE; \
    STDMETHOD(LoadTexture)      (THIS_ const char *filename, IRLTexture **) PURE; \
    \
    STDMETHOD(LoadTextureFromResource)  (THIS_ const char *filename, HRSRC rs, IRLTexture **) PURE; \
    \
    STDMETHOD(SetSearchPath)    (THIS_ const char *path) PURE; \
    STDMETHOD(AddSearchPath)    (THIS_ const char *path) PURE; \
    STDMETHOD(GetSearchPath)    (THIS_ int *return_count, char ***return_path) PURE; \
    STDMETHOD(SetDefaultTextureColours)(THIS_ ULONG) PURE; \
    STDMETHOD(SetDefaultTextureShades)(THIS_ ULONG) PURE; \
    \
    STDMETHOD(GetDevices)       (THIS_ IRLDeviceArray **return_devices) PURE; \
    STDMETHOD(GetNamedObject)   (THIS_ const char *name, IRLObject **) PURE; \
    STDMETHOD(GetLastError)     (THIS) PURE; \
    STDMETHOD(RaiseError)       (THIS_ RLError) PURE; \
    STDMETHOD(AddErrorHandler)  (THIS_ RLErrorHandler fn, void* arg) PURE; \
    STDMETHOD(RemoveErrorHandler)(THIS_ RLErrorHandler fn, void* arg) PURE; \
    STDMETHOD_(const char*, ErrorString)(THIS_ HRESULT error) PURE; \
    \
    STDMETHOD(Malloc)           (THIS_ void** p_return, size_t size) PURE; \
    STDMETHOD(Realloc)          (THIS_ void** p_inout, size_t size) PURE; \
    STDMETHOD(Free)             (THIS_ void* p) PURE; \
    STDMETHOD_(ULONG, GetTotalAllocated)(THIS) PURE; \
    \
    STDMETHOD(EnumerateObjects) (THIS_ RLObjectCallback, void *arg) PURE; \
    STDMETHOD(Tick)             (THIS)

#undef INTERFACE
#define INTERFACE IRealityLab

DECLARE_INTERFACE_(IRealityLab, IUnknown)
{
    IUNKNOWN_METHODS(PURE);
    IREALITYLAB_METHODS;
};

#ifdef __cplusplus
};
#endif

#endif /* _IRLAPI_H_ */
