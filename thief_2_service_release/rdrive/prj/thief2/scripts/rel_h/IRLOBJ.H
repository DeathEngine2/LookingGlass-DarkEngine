/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Id: irlobj.h,v 1.34 1995/12/01 18:25:47 dave Exp $
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

#ifndef _IRLOBJ_H_
#define _IRLOBJ_H_

#include <objbase.h> /* Use Windows header files */
#define VIRTUAL

#include "rltypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The methods for IUnknown
 */
#define IUNKNOWN_METHODS(kind) \
    STDMETHOD(QueryInterface)           (THIS_ REFIID riid, LPVOID *ppvObj) kind; \
    STDMETHOD_(ULONG, AddRef)           (THIS) kind; \
    STDMETHOD_(ULONG, Release)          (THIS) kind

/*
 * The methods for IRLObject
 */
#define IRLOBJECT_METHODS(kind) \
    STDMETHOD(Copy)                     (THIS_ IRLObject **) kind; \
    STDMETHOD(AddDestroyCallback)       (THIS_ RLObjectCallback, void *argument) kind; \
    STDMETHOD(RemoveDestroyCallback)    (THIS_ RLObjectCallback, void *argument) kind; \
    STDMETHOD(SetAppData)               (THIS_ ULONG data) kind; \
    STDMETHOD_(ULONG, GetAppData)       (THIS) kind; \
    STDMETHOD(SetName)                  (THIS_ const char *) kind; \
    STDMETHOD_(const char *, GetName)   (THIS) kind; \
    STDMETHOD_(const char *, GetClassName)(THIS) kind


#define IRLFACILITY 0x999

#define WIN_TYPES(itype, ptype) \
    typedef interface itype FAR *LP##ptype, FAR **LPLP##ptype

WIN_TYPES(IRLObject, RLOBJECT);
WIN_TYPES(IRLDevice, RLDEVICE);
WIN_TYPES(IRLViewport, RLVIEWPORT);
WIN_TYPES(IRLFrame, RLFRAME);
WIN_TYPES(IRLVisual, RLVISUAL);
WIN_TYPES(IRLMesh, RLMESH);
WIN_TYPES(IRLMeshBuilder, RLMESHBUILDER);
WIN_TYPES(IRLFace, RLFACE);
WIN_TYPES(IRLLight, RLLIGHT);
WIN_TYPES(IRLTexture, RLTEXTURE);
WIN_TYPES(IRLWrap, RLWRAP);
WIN_TYPES(IRLMaterial, RLMATERIAL);
WIN_TYPES(IRLAnimation, RLANIMATION);
WIN_TYPES(IRLAnimationSet, RLANIMATIONSET);
WIN_TYPES(IRLArray, RLOBJECTARRAY);
WIN_TYPES(IRLDeviceArray, RLDEVICEARRAY);
WIN_TYPES(IRLViewportArray, RLVIEWPORTARRAY);
WIN_TYPES(IRLFrameArray, RLFRAMEARRAY);
WIN_TYPES(IRLVisualArray, RLVISUALARRAY);
WIN_TYPES(IRLPickedArray, RLPICKEDARRAY);
WIN_TYPES(IRLLightArray, RLLIGHTARRAY);

/*
 * GUIDs for QueryInterface method
 */
DEFINE_GUID(IID_IRLObject,        0xeb16cb00, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLDevice,        0xeb16cb01, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLViewport,      0xeb16cb02, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLFrame,         0xeb16cb03, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLVisual,        0xeb16cb04, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLMesh,          0xeb16cb05, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLMeshBuilder,   0xeb16cb06, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLFace,          0xeb16cb07, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLLight,         0xeb16cb08, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLTexture,       0xeb16cb09, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLWrap,          0xeb16cb0a, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLMaterial,      0xeb16cb0b, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLAnimation,     0xeb16cb0d, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLAnimationSet,  0xeb16cb0e, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLArray,         0xeb16cb0f, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLDeviceArray,   0xeb16cb10, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLViewportArray, 0xeb16cb11, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLFrameArray,    0xeb16cb12, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLVisualArray,   0xeb16cb13, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLLightArray,    0xeb16cb14, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLPicked,        0xeb16cb15, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLPickedArray,   0xeb16cb16, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IRLFaceArray,     0xeb16cb17, 0xd271, 0x11ce, 0xac, 0x48, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);

typedef void (*RLObjectCallback)(LPRLOBJECT obj, void *arg);
typedef void (*RLUpdateCallback)(LPRLDEVICE obj, void *arg, int, RLRectangle*);

typedef HRESULT (*RLLoadTextureCallback)
    (char *tex_name, void *arg, LPRLTEXTURE *);

#undef INTERFACE
#define INTERFACE IRLObject

/*
 * Base class
 */
DECLARE_INTERFACE_(IRLObject, IUnknown)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);
};

#undef INTERFACE
#define INTERFACE IRLVisual

DECLARE_INTERFACE_(IRLVisual, IRLObject)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);
};

#undef INTERFACE
#define INTERFACE IRLPicked

DECLARE_INTERFACE_(IRLPicked, IRLVisual)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLPicked methods
     */
    STDMETHOD(GetPosition)(THIS_ RLVector *return_position) PURE;
    STDMETHOD(GetFrames)(THIS_ interface IRLFrameArray **return_array) PURE;
    STDMETHOD(GetFace)(THIS_ LONG *group, ULONG *index) PURE;
};

#undef INTERFACE
#define INTERFACE IRLDevice

DECLARE_INTERFACE_(IRLDevice, IRLObject)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLDevice methods
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
};

#undef INTERFACE
#define INTERFACE IRLViewport

DECLARE_INTERFACE_(IRLViewport, IRLObject)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLViewport methods
     */
    STDMETHOD(Clear)(THIS) PURE;
    STDMETHOD(Render)(THIS_ interface IRLFrame *) PURE;

    STDMETHOD(SetFront)(THIS_ RLValue) PURE;
    STDMETHOD(SetBack)(THIS_ RLValue) PURE;
    STDMETHOD(SetField)(THIS_ RLValue) PURE;
    STDMETHOD(SetUniformScaling)(THIS_ BOOL) PURE;
    STDMETHOD(SetCamera)(THIS_ interface IRLFrame *) PURE;
    STDMETHOD(SetProjection)(THIS_ RLProjectionType) PURE;
    STDMETHOD(Transform)(THIS_ RLVector4d *d, RLVector *s) PURE;
    STDMETHOD(InverseTransform)(THIS_ RLVector *d, RLVector4d *s) PURE;
    STDMETHOD(Configure)(THIS_ LONG x, LONG y, ULONG width, ULONG height) PURE;
    STDMETHOD(ForceUpdate)(THIS_ ULONG x1, ULONG y1, ULONG x2, ULONG y2) PURE;
    STDMETHOD(SetPlane)(THIS_ RLValue left, RLValue right, RLValue bottom, RLValue top) PURE;

    STDMETHOD(GetCamera)(THIS_ interface IRLFrame **) PURE;
    STDMETHOD(GetDevice)(THIS_ interface IRLDevice **) PURE;
    STDMETHOD(GetPlane)(THIS_ RLValue *left, RLValue *right, RLValue *bottom, RLValue *top) PURE;
    STDMETHOD(Pick)(THIS_ LONG x, LONG y, interface IRLPickedArray **return_visuals) PURE;

    STDMETHOD_(BOOL, GetUniformScaling)(THIS) PURE;
    STDMETHOD_(LONG, GetX)(THIS) PURE;
    STDMETHOD_(LONG, GetY)(THIS) PURE;
    STDMETHOD_(ULONG, GetWidth)(THIS) PURE;
    STDMETHOD_(ULONG, GetHeight)(THIS) PURE;
    STDMETHOD_(RLValue, GetField)(THIS) PURE;
    STDMETHOD_(RLValue, GetBack)(THIS) PURE;
    STDMETHOD_(RLValue, GetFront)(THIS) PURE;
    STDMETHOD_(RLProjectionType, GetProjection)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IRLFrame

DECLARE_INTERFACE_(IRLFrame, IRLVisual)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLFrame methods
     */
    STDMETHOD(Move)(THIS) PURE;
    STDMETHOD(Transform)(THIS_ RLVector *d, RLVector *s) PURE;
    STDMETHOD(LookAt)(THIS_ IRLFrame *target, IRLFrame *reference, RLFrameConstraint) PURE;
    STDMETHOD(InverseTransform)(THIS_ RLVector *d, RLVector *s) PURE;

    STDMETHOD(AddVisual)(THIS_ IRLVisual *) PURE;
    STDMETHOD(AddChild)(THIS_ IRLFrame *child) PURE;
    STDMETHOD(AddLight)(THIS_ interface IRLLight *) PURE;
    STDMETHOD(AddRenderCallback)(THIS_ RLObjectCallback, VOID *arg) PURE;
    STDMETHOD(AddTransform)(THIS_ RLCombineType, RLMatrix4d) PURE;
    STDMETHOD(AddScale)(THIS_ RLCombineType, RLValue sx, RLValue sy, RLValue sz) PURE;
    STDMETHOD(AddTranslation)(THIS_ RLCombineType, RLValue x, RLValue y, RLValue z) PURE;
    STDMETHOD(AddRotation)(THIS_ RLCombineType, RLValue x, RLValue y, RLValue z, RLValue theta) PURE;

    STDMETHOD(SetMaterialMode)(THIS_ RLMaterialMode) PURE;
    STDMETHOD(SetTexture)(THIS_ interface IRLTexture *) PURE;
    STDMETHOD(SetTextureTopology)(THIS_ BOOL wrap_u, BOOL wrap_v) PURE;
    STDMETHOD(SetColour)(THIS_ RLColour) PURE;
    STDMETHOD(SetColourRGB)(THIS_ RLValue red, RLValue green, RLValue blue) PURE;
    STDMETHOD(SetPosition)(THIS_ IRLFrame *reference, RLValue x, RLValue y, RLValue z) PURE;
    STDMETHOD(SetVelocity)(THIS_ IRLFrame *reference, RLValue x, RLValue y, RLValue z) PURE;
    STDMETHOD(SetRotation)(THIS_ IRLFrame *reference, RLValue x, RLValue y, RLValue z, RLValue theta) PURE;
    STDMETHOD(SetOrientation)
    (   THIS_ IRLFrame *reference,
        RLValue dx, RLValue dy, RLValue dz,
        RLValue ux, RLValue uy, RLValue uz
    ) PURE;
    STDMETHOD(RemoveVisual)(THIS_ IRLVisual *) PURE;
    STDMETHOD(RemoveChild)(THIS_ IRLFrame *) PURE;
    STDMETHOD(RemoveLight)(THIS_ interface IRLLight *) PURE;
    STDMETHOD(RemoveRenderCallback)(THIS_ RLObjectCallback, VOID *arg) PURE;

    STDMETHOD(BuildMesh)(THIS_ interface IRLMesh **) PURE;
    STDMETHOD(GetScene)(THIS_ interface IRLFrame **) PURE;
    STDMETHOD(GetParent)(THIS_ interface IRLFrame **) PURE;
    STDMETHOD(GetTexture)(THIS_ interface IRLTexture **) PURE;
    STDMETHOD(GetTransform)(THIS_ RLMatrix4d return_matrix) PURE;
    STDMETHOD(GetPosition)(THIS_ IRLFrame *reference, RLVector *return_position) PURE;
    STDMETHOD(GetVelocity)(THIS_ IRLFrame *reference, RLVector *return_velocity) PURE;
    STDMETHOD(GetRotation)(THIS_ IRLFrame *reference, RLVector *axis, RLValue *return_theta) PURE;
    STDMETHOD(GetOrientation)(THIS_ IRLFrame *reference, RLVector *dir, RLVector *up) PURE;
    STDMETHOD(GetChildren)(THIS_ interface IRLFrameArray **children) PURE;
    STDMETHOD(GetVisuals)(THIS_ interface IRLVisualArray **visuals) PURE;
    STDMETHOD(GetLights)(THIS_ interface IRLLightArray **lights) PURE;
    STDMETHOD(GetTextureTopology)(THIS_ BOOL *wrap_u, BOOL *wrap_v) PURE;

    STDMETHOD_(RLColour, GetColour)(THIS) PURE;
    STDMETHOD_(RLMaterialMode, GetMaterialMode)(THIS) PURE;

    STDMETHOD(SceneSetBackground)(THIS_ RLColour) PURE;
    STDMETHOD(SceneSetBackgroundRGB)(THIS_ RLValue red, RLValue green, RLValue blue) PURE;
    STDMETHOD(SceneSetBackgroundDepth)(THIS_ RLImage *) PURE;
    STDMETHOD(SceneSetBackgroundImage)(THIS_ interface IRLTexture *) PURE;
    STDMETHOD(SceneSetFogEnable)(THIS_ BOOL) PURE;
    STDMETHOD(SceneSetFogMode)(THIS_ RLFogMode) PURE;
    STDMETHOD(SceneSetFogColour)(THIS_ RLColour) PURE;
    STDMETHOD(SceneSetFogParams)(THIS_ RLValue start, RLValue end, RLValue density) PURE;
    STDMETHOD(SceneGetFogParams)(THIS_ RLValue *return_start, RLValue *return_end, RLValue *return_density) PURE;
    STDMETHOD_(BOOL, SceneGetFogEnable)(THIS) PURE;
    STDMETHOD_(RLColour, SceneGetBackground)(THIS) PURE;
    STDMETHOD_(RLImage *, SceneGetBackgroundDepth)(THIS) PURE;
    STDMETHOD_(RLFogMode, SceneGetFogMode)(THIS) PURE;
    STDMETHOD_(RLColour, SceneGetFogColour)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IRLMesh

DECLARE_INTERFACE_(IRLMesh, IRLVisual)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLMesh methods
     */
    STDMETHOD(Scale)(THIS_ RLValue sx, RLValue sy, RLValue sz) PURE;
    STDMETHOD(Translate)(THIS_ RLValue tx, RLValue ty, RLValue tz) PURE;
    STDMETHOD(Save)(THIS_ CHAR *filename, RLXOFFormat format, ULONG save) PURE;
    STDMETHOD(GetBox)(THIS_ RLBox *) PURE;
    STDMETHOD(SetLightingFrequency)(THIS_ RLLightingFrequency) PURE;
    STDMETHOD_(RLLightingFrequency, GetLightingFrequency)(THIS) PURE;

    STDMETHOD(AddGroup)(THIS_ unsigned vCount, unsigned fCount, unsigned vPerFace, unsigned *fData, RLGroupIndex *returnId) PURE;
    STDMETHOD(SetVertices)(THIS_ RLGroupIndex id, unsigned index, unsigned count, RLVertex *values) PURE;
    STDMETHOD(SetGroupColour)(THIS_ RLGroupIndex id, RLColour value) PURE;
    STDMETHOD(SetGroupColourRGB)(THIS_ RLGroupIndex id, RLValue red, RLValue green, RLValue blue) PURE;
    STDMETHOD(SetGroupMapping)(THIS_ RLGroupIndex id, RLMapping value) PURE;
    STDMETHOD(SetGroupQuality)(THIS_ RLGroupIndex id, RLRenderQuality value) PURE;
    STDMETHOD(SetGroupMaterial)(THIS_ RLGroupIndex id, interface IRLMaterial *value) PURE;
    STDMETHOD(SetGroupTexture)(THIS_ RLGroupIndex id, interface IRLTexture *value) PURE;

    STDMETHOD_(unsigned, GetGroupCount)(THIS) PURE;
    STDMETHOD(GetGroup)(THIS_ RLGroupIndex id, unsigned *vCount, unsigned *fCount, unsigned *vPerFace, unsigned **fData) PURE;
    STDMETHOD_(RLVertex *, GetVertices)(THIS_ RLGroupIndex id, unsigned index, unsigned count, RLVertex *returnPtr) PURE;
    STDMETHOD_(RLColour, GetGroupColour)(THIS_ RLGroupIndex id) PURE;
    STDMETHOD_(RLMapping, GetGroupMapping)(THIS_ RLGroupIndex id) PURE;
    STDMETHOD_(RLRenderQuality, GetGroupQuality)(THIS_ RLGroupIndex id) PURE;
    STDMETHOD(GetGroupMaterial)(THIS_ RLGroupIndex id, interface IRLMaterial **returnPtr) PURE;
    STDMETHOD(GetGroupTexture)(THIS_ RLGroupIndex id, interface IRLTexture **returnPtr) PURE;
};

#undef INTERFACE
#define INTERFACE IRLFace

DECLARE_INTERFACE_(IRLFace, IRLObject)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLFace methods
     */
     STDMETHOD(AddVertex)(THIS_ RLValue x, RLValue y, RLValue z) PURE;
     STDMETHOD(AddVertexAndNormalIndexed)(THIS_ ULONG vertex, ULONG normal) PURE;
     STDMETHOD(SetColourRGB)(THIS_ RLValue, RLValue, RLValue) PURE;
     STDMETHOD(SetColour)(THIS_ RLColour) PURE;
     STDMETHOD(SetTexture)(THIS_ interface IRLTexture *) PURE;
     STDMETHOD(SetTextureCoordinates)(THIS_ ULONG vertex, RLValue u, RLValue v) PURE;
     STDMETHOD(SetMaterial)(THIS_ interface IRLMaterial *) PURE;
     STDMETHOD(SetTextureTopology)(THIS_ BOOL wrap_u, BOOL wrap_v) PURE;

     STDMETHOD(GetVertex)(THIS_ ULONG index, RLVector *vertex, RLVector *normal) PURE;
     STDMETHOD(GetVertices)(THIS_ ULONG *vertex_count, RLVector **coords, RLVector **normals) PURE;
     STDMETHOD(GetTextureCoordinates)(THIS_ ULONG vertex, RLValue *u, RLValue *v) PURE;
     STDMETHOD(GetTextureTopology)(THIS_ BOOL *wrap_u, BOOL *wrap_v) PURE;
     STDMETHOD(GetNormal)(THIS_ RLVector *) PURE;
     STDMETHOD(GetTexture)(THIS_ interface IRLTexture **) PURE;
     STDMETHOD(GetMaterial)(THIS_ interface IRLMaterial **) PURE;

     STDMETHOD_(int, GetVertexCount)(THIS) PURE;
     STDMETHOD_(int, GetVertexIndex)(THIS_ ULONG which) PURE;
     STDMETHOD_(int, GetTextureCoordinateIndex)(THIS_ ULONG which) PURE;
     STDMETHOD_(RLColour, GetColour)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IRLMeshBuilder

DECLARE_INTERFACE_(IRLMeshBuilder, IRLVisual)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLMeshBuilder methods
     */
    STDMETHOD(Load)(THIS_ const char *filename)PURE;
    STDMETHOD(LoadWithTextures)(THIS_ const char *filename, RLLoadTextureCallback, void* arg) PURE;
    STDMETHOD(LoadFromResource)(THIS_ const char *filename, HRSRC resource)PURE;
    STDMETHOD(LoadFromResourceWithTextures)(THIS_ const char *filename, RLLoadTextureCallback, void* arg, HRSRC resource) PURE;
    STDMETHOD(Save)(THIS_ const char *filename, RLXOFFormat, int save) PURE;
    STDMETHOD(Scale)(THIS_ RLValue sx, RLValue sy, RLValue sz) PURE;
    STDMETHOD(Translate)(THIS_ RLValue tx, RLValue ty, RLValue tz) PURE;
    STDMETHOD(SetColourSource)(THIS_ RLColourSource) PURE;
    STDMETHOD(SetLightingFrequency)(THIS_ RLLightingFrequency) PURE;
    STDMETHOD(GetBox)(THIS_ RLBox *) PURE;
    STDMETHOD(GetFrame)(THIS_ IRLFrame **) PURE;
    STDMETHOD(GenerateNormals)(THIS) PURE;
    STDMETHOD_(RLLightingFrequency, GetLightingFrequency)(THIS) PURE;
    STDMETHOD_(RLColourSource, GetColourSource)(THIS) PURE;

    STDMETHOD(AddFace)(THIS_ interface IRLFace *) PURE;
    STDMETHOD(AddFaces)
    (   THIS_ ULONG vcount, RLVector *vertices, ULONG ncount, RLVector *normals,
        ULONG *data, interface IRLFaceArray **
    ) PURE;
    STDMETHOD(ReserveSpace)(THIS_ ULONG vertex_Count, ULONG normal_count, ULONG face_count) PURE;
    STDMETHOD(SetColourRGB)(THIS_ RLValue red, RLValue green, RLValue blue) PURE;
    STDMETHOD(SetColour)(THIS_ RLColour) PURE;
    STDMETHOD(SetTexture)(THIS_ interface IRLTexture *) PURE;
    STDMETHOD(SetMaterial)(THIS_ interface IRLMaterial *) PURE;
    STDMETHOD(SetTextureTopology)(THIS_ BOOL wrap_u, BOOL wrap_v) PURE;
    STDMETHOD(SetQuality)(THIS_ RLRenderQuality) PURE;
    STDMETHOD(SetPerspective)(THIS_ BOOL) PURE;
    STDMETHOD(SetVertex)(THIS_ ULONG index, RLValue x, RLValue y, RLValue z) PURE;
    STDMETHOD(SetNormal)(THIS_ ULONG index, RLValue x, RLValue y, RLValue z) PURE;
    STDMETHOD(SetTextureCoordinates)(THIS_ ULONG index, RLValue u, RLValue v) PURE;
    STDMETHOD(SetVertexColour)(THIS_ ULONG index, RLColour) PURE;
    STDMETHOD(SetVertexColourRGB)(THIS_ ULONG index, RLValue red, RLValue green, RLValue blue) PURE;

    STDMETHOD(GetFaces)(THIS_ interface IRLFaceArray **) PURE;
    STDMETHOD(GetVertices)
    (   THIS_ ULONG *vcount, RLVector **vertices, ULONG *ncount, RLVector **normals, ULONG **face_data
    ) PURE;
    STDMETHOD(GetTextureCoordinates)(THIS_ ULONG index, RLValue *u, RLValue *v) PURE;

    STDMETHOD_(int, AddVertex)(THIS_ RLValue x, RLValue y, RLValue z) PURE;
    STDMETHOD_(int, AddNormal)(THIS_ RLValue x, RLValue y, RLValue z) PURE;
    STDMETHOD(CreateFace)(THIS_ interface IRLFace **) PURE;
    STDMETHOD_(RLRenderQuality, GetQuality)(THIS) PURE;
    STDMETHOD_(BOOL, GetPerspective)(THIS) PURE;
    STDMETHOD_(int, GetFaceCount)(THIS) PURE;
    STDMETHOD_(int, GetVertexCount)(THIS) PURE;
    STDMETHOD_(RLColour, GetVertexColour)(THIS_ ULONG index) PURE;

    STDMETHOD(CreateMesh)(THIS_ interface IRLMesh **) PURE;
};

#undef INTERFACE
#define INTERFACE IRLLight

DECLARE_INTERFACE_(IRLLight, IRLObject)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLLight methods
     */
    STDMETHOD(SetType)(THIS_ RLLightType) PURE;
    STDMETHOD(SetColour)(THIS_ RLColour) PURE;
    STDMETHOD(SetColourRGB)(THIS_ RLValue red, RLValue green, RLValue blue) PURE;
    STDMETHOD(SetRange)(THIS_ RLValue) PURE;
    STDMETHOD(SetUmbra)(THIS_ RLValue) PURE;
    STDMETHOD(SetPenumbra)(THIS_ RLValue) PURE;
    STDMETHOD(SetConstantAttenuation)(THIS_ RLValue) PURE;
    STDMETHOD(SetLinearAttenuation)(THIS_ RLValue) PURE;
    STDMETHOD(SetQuadraticAttenuation)(THIS_ RLValue) PURE;

    STDMETHOD_(RLValue, GetRange)(THIS) PURE;
    STDMETHOD_(RLValue, GetUmbra)(THIS) PURE;
    STDMETHOD_(RLValue, GetPenumbra)(THIS) PURE;
    STDMETHOD_(RLValue, GetConstantAttenuation)(THIS) PURE;
    STDMETHOD_(RLValue, GetLinearAttenuation)(THIS) PURE;
    STDMETHOD_(RLValue, GetQuadraticAttenuation)(THIS) PURE;
    STDMETHOD_(RLColour, GetColour)(THIS) PURE;
    STDMETHOD_(RLLightType, GetType)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IRLTexture

DECLARE_INTERFACE_(IRLTexture, IRLVisual)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLTexture methods
     */
    STDMETHOD(Changed)(THIS_ BOOL pixels, BOOL palette) PURE;

    STDMETHOD(SetOpacity)(THIS_ RLImage *) PURE;
    STDMETHOD(SetColours)(THIS_ ULONG) PURE;
    STDMETHOD(SetShades)(THIS_ ULONG) PURE;
    STDMETHOD(SetDecalSize)(THIS_ RLValue width, RLValue height) PURE;
    STDMETHOD(SetDecalOrigin)(THIS_ LONG x, LONG y) PURE;
    STDMETHOD(SetDecalDepth)(THIS_ RLDecalDepth) PURE;
    STDMETHOD(SetDecalScale)(THIS_ ULONG) PURE;
    STDMETHOD(SetDecalTransparency)(THIS_ BOOL) PURE;
    STDMETHOD(SetDecalTransparentColour)(THIS_ RLColour) PURE;

    STDMETHOD(GetDecalSize)(THIS_ RLValue *width_return, RLValue *height_return) PURE;
    STDMETHOD(GetDecalOrigin)(THIS_ LONG *x_return, LONG *y_return) PURE;

    STDMETHOD_(RLImage *, GetImage)(THIS) PURE;
    STDMETHOD_(RLImage *, GetOpacity)(THIS) PURE;
    STDMETHOD_(ULONG, GetShades)(THIS) PURE;
    STDMETHOD_(ULONG, GetColours)(THIS) PURE;
    STDMETHOD_(ULONG, GetDecalScale)(THIS) PURE;
    STDMETHOD_(BOOL, GetDecalTransparency)(THIS) PURE;
    STDMETHOD_(RLDecalDepth, GetDecalDepth)(THIS) PURE;
    STDMETHOD_(RLColour, GetDecalTransparentColour)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IRLWrap

DECLARE_INTERFACE_(IRLWrap, IRLObject)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLWrap methods
     */
    STDMETHOD(Apply)(THIS_ interface IRLObject *) PURE;
    STDMETHOD(ApplyRelative)(THIS_ interface IRLFrame *frame, interface IRLObject *) PURE;
};

#undef INTERFACE
#define INTERFACE IRLMaterial

DECLARE_INTERFACE_(IRLMaterial, IRLObject)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLMaterial methods
     */
    STDMETHOD(SetKs)(THIS_ RLValue ks) PURE;
    STDMETHOD(SetPower)(THIS_ RLValue power) PURE;

    STDMETHOD_(RLValue, GetKs)(THIS) PURE;
    STDMETHOD_(RLValue, GetPower)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IRLAnimation

DECLARE_INTERFACE_(IRLAnimation, IRLObject)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLAnimation methods
     */
    STDMETHOD(SetOptions)(THIS_ UINT flags) PURE;
    STDMETHOD(SetPositionInterpolation)(THIS_ RLInterpolationType type) PURE;
    STDMETHOD(AddRotateKey)(THIS_ RLValue time, RLQuaternion *q) PURE;
    STDMETHOD(AddPositionKey)(THIS_ RLValue time, RLValue x, RLValue y, RLValue z) PURE;
    STDMETHOD(AddScaleKey)(THIS_ RLValue time, RLValue x, RLValue y, RLValue z) PURE;
    STDMETHOD(SetFrame)(THIS_ interface IRLFrame *frame) PURE;
    STDMETHOD(SetTime)(THIS_ RLValue time) PURE;

    STDMETHOD_(UINT, GetOptions)(THIS) PURE;
    STDMETHOD_(RLAnimationType, GetType)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IRLAnimationSet

DECLARE_INTERFACE_(IRLAnimationSet, IRLObject)
{
    IUNKNOWN_METHODS(PURE);
    IRLOBJECT_METHODS(PURE);

    /*
     * IRLAnimationSet methods
     */
    STDMETHOD(AddAnimation)(THIS_ interface IRLAnimation *aid) PURE;
    STDMETHOD(RemoveAnimation)(THIS_ interface IRLAnimation *aid) PURE;
    STDMETHOD(SetTime)(THIS_ RLValue time) PURE;
};

#undef INTERFACE
#define INTERFACE IRLArray

DECLARE_INTERFACE_(IRLArray, IUnknown)
{
    IUNKNOWN_METHODS(PURE);

    STDMETHOD_(ULONG, GetSize)(THIS) PURE;
    /* No GetElement method as it would get overloaded
     * in derived classes, and overloading is
     * a no-no in COM
     */
};

#undef INTERFACE
#define INTERFACE IRLDeviceArray

DECLARE_INTERFACE_(IRLDeviceArray, IRLArray)
{
    IUNKNOWN_METHODS(PURE);

    STDMETHOD_(ULONG, GetSize)(THIS) PURE;
    STDMETHOD(GetElement)(THIS_ ULONG index, IRLDevice **) PURE;
};

#undef INTERFACE
#define INTERFACE IRLFrameArray

DECLARE_INTERFACE_(IRLFrameArray, IRLArray)
{
    IUNKNOWN_METHODS(PURE);

    STDMETHOD_(ULONG, GetSize)(THIS) PURE;
    STDMETHOD(GetElement)(THIS_ ULONG index, IRLFrame **) PURE;
};

#undef INTERFACE
#define INTERFACE IRLViewportArray

DECLARE_INTERFACE_(IRLViewportArray, IRLArray)
{
    IUNKNOWN_METHODS(PURE);

    STDMETHOD_(ULONG, GetSize)(THIS) PURE;
    STDMETHOD(GetElement)(THIS_ ULONG index, IRLViewport **) PURE;
};

#undef INTERFACE
#define INTERFACE IRLVisualArray

DECLARE_INTERFACE_(IRLVisualArray, IRLArray)
{
    IUNKNOWN_METHODS(PURE);

    STDMETHOD_(ULONG, GetSize)(THIS) PURE;
    STDMETHOD(GetElement)(THIS_ ULONG index, IRLVisual **) PURE;
};

#undef INTERFACE
#define INTERFACE IRLPickedArray

DECLARE_INTERFACE_(IRLPickedArray, IRLArray)
{
    IUNKNOWN_METHODS(PURE);

    STDMETHOD_(ULONG, GetSize)(THIS) PURE;
    STDMETHOD(GetElement)(THIS_ ULONG index, IRLPicked **) PURE;
};

#undef INTERFACE
#define INTERFACE IRLLightArray

DECLARE_INTERFACE_(IRLLightArray, IRLArray)
{
    IUNKNOWN_METHODS(PURE);

    STDMETHOD_(ULONG, GetSize)(THIS) PURE;
    STDMETHOD(GetElement)(THIS_ ULONG index, IRLLight **) PURE;
};

#undef INTERFACE
#define INTERFACE IRLFaceArray

DECLARE_INTERFACE_(IRLFaceArray, IRLArray)
{
    IUNKNOWN_METHODS(PURE);

    STDMETHOD_(ULONG, GetSize)(THIS) PURE;
    STDMETHOD(GetElement)(THIS_ ULONG index, IRLFace **) PURE;
};

#ifdef __cplusplus
};
#endif
#endif /* _IRLOBJ_H_ */
