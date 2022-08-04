/*
 
Copyright (c) 1995, Microsoft Corporation.  All Rights Reserved.

Module Name:

    rltypes.h

*/

#ifndef __RLTYPES_H__
#define __RLTYPES_H__

#include <stddef.h>
#include "d3dtypes.h"

#ifdef WIN32
#define RLAPI  __stdcall
#else
#define RLAPI
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#ifdef __psx__
#ifndef FIXED_POINT_API
#define FIXED_POINT_API
#endif
#ifndef FIXED_POINT_INTERNAL
#define FIXED_POINT_INTERNAL
#endif
#endif

#ifndef TRUE
#define FALSE 0
#define TRUE 1
#endif

typedef unsigned long                   RLColour;
/* RLRGB and RLRGBA may be used as initialisers for RLColours
 * The int or float values must be in the range 0..1
 */
#define RLRGB(r, g, b) \
    (0xff000000L | ( ((long)((r) * 255)) << 16) | (((long)((g) * 255)) << 8) | (long)((b) * 255))
#define RLRGBA(r, g, b, a) \
    (   (((long)((a) * 255)) << 24) | (((long)((r) * 255)) << 16) \
    |   (((long)((g) * 255)) << 8) | (long)((b) * 255) \
    )

typedef char*                           RLAttribute;

#ifdef FIXED_POINT_API
typedef long int        RLValue;
#ifndef __psx__
#define RLVal(x)                ((RLValue)((x) * (double)(1<<16)))
#else
#define RLVal(x)                ((RLValue)((x) * 65536))
#endif
#define RLInt(x)                ((x) >> 16)
#define RLFloat(x)              ((x) / 65536.0)
extern RLValue RLAPI RLDivide(RLValue, RLValue);
extern RLValue RLAPI RLMultiply(RLValue, RLValue);
#define RLMultiply3(a,b,c)      RLMultiply(RLMultiply(a, b), c)
#else
typedef float           RLValue;
#define RLVal(x)        ((RLValue) (x))
#define RLInt(x)        ((int)(x))
#define RLFloat(x)      ((float) (x))
#define RLDivide(a,b)   ((RLValue) ((double) (a) / (double) (b)))
#define RLMultiply(a,b) ((RLValue) ((a) * (b)))
#define RLMultiply3(a,b,c)      ((RLValue) ((a) * (b) * (c)))
#endif

/*
 * Error codes
 */

typedef enum _RLError
{   RLNoError = 0,              /* no error */
    RLBadObject,                /* object expected in argument */
    RLBadType,                  /* bad argument type passed */
    RLBadAlloc,                 /* out of memory */
    RLFaceUsed,                 /* face already used in a mesh */
    RLNotFound,                 /* object not found in specified place */
    RLNotDoneYet,               /* unimplemented */
    RLFileNotFound,             /* file cannot be opened */
    RLBadFile,                  /* data file is corrupt */
    RLBadDevice,                /* device is not compatible with renderer */
    RLBadValue,                 /* bad argument value */
    RLBadMajorVersion,          /* bad dll major version */
    RLBadMinorVersion,          /* bad dll minor version */
    RLUnableToExecute,          /*
                                 * certain functions, such as
                                 * IRealityLabSetAllocator, cannot be executed
                                 * subsequent to other functions
                                 */
    RLMaxError
} RLError;

typedef void (*RLErrorHandler)
(   RLError error,              /* error which was generated */
    void* arg                   /* argument given to RLAddErrorHandler */
);

typedef struct _RLRectangle
{
    int x1, y1, x2, y2;
} RLRectangle;

typedef struct _RLVector
{   RLValue x, y, z;
} RLVector;

typedef struct _RLQuaternion
{   RLValue s;
    RLVector v;
} RLQuaternion;

typedef struct _RLVector4d
{   RLValue x, y, z, w;
} RLVector4d;

typedef RLValue RLMatrix4d[4][4];

typedef struct _RLBox
{   RLVector min, max;
} RLBox;

typedef void (*RLWrapCallback)
    (RLVector*, int* u, int* v, RLVector* a, RLVector* b, void*);

typedef enum _RLLightType
{   RLLightAmbient,
    RLLightPoint,
    RLLightSpot,
    RLLightDirectional,
    RLLightParallelPoint
} RLLightType;
/*
typedef unsigned long RLRenderQuality;

static const RLRenderQuality RLShadeFlat =      0x01;
static const RLRenderQuality RLShadeGouraud =   0x02;
static const RLRenderQuality RLShadePhong =     0x04;

static const RLRenderQuality RLLightOff =       0x07;
static const RLRenderQuality RLLightOn =        0x08;

static const RLRenderQuality RLFillWireframe =  0x10;
static const RLRenderQuality RLFillSolid =      0x20;
static const RLRenderQuality RLFillPoints =     0x30;

#define RLRenderWireframe   (RLShadeFlat + RLLightOff + RLFillWireframe)
#define RLRenderUnlitFlat   (RLShadeFlat + RLLightOff + RLFillSolid)
#define RLRenderFlat        (RLShadeFlat + RLLightOn + RLFillSolid)
#define RLRenderGouraud     (RLShadeGouraud + RLLightOn + RLFillSolid)
#define RLRenderPhong       (RLShadePhong + RLLightOn + RLFillSolid)
*/
typedef enum _RLShadeMode {
    RLShadeFlat         = 0,
    RLShadeGouraud      = 1,
    RLShadePhong        = 2,

    RLShadeMask         = 7,
    RLShadeMax          = 8
} RLShadeMode;

typedef enum _RLLightMode {
    RLLightOff          = 0 * RLShadeMax,
    RLLightOn           = 1 * RLShadeMax,

    RLLightMask         = 7 * RLShadeMax,
    RLLightMax          = 8 * RLShadeMax
} RLLightMode;

typedef enum _RLFillMode {
    RLFillPoints        = 0 * RLLightMax,
    RLFillWireframe     = 1 * RLLightMax,
    RLFillSolid         = 2 * RLLightMax,

    RLFillMask          = 7 * RLLightMax,
    RLFillMax           = 8 * RLLightMax
} RLFillMode;

typedef unsigned long RLRenderQuality;

#define RLRenderWireframe       (RLShadeFlat+RLLightOff+RLFillWireframe)
#define RLRenderUnlitFlat       (RLShadeFlat+RLLightOff+RLFillSolid)
#define RLRenderFlat            (RLShadeFlat+RLLightOn+RLFillSolid)
#define RLRenderGouraud         (RLShadeGouraud+RLLightOn+RLFillSolid)
#define RLRenderPhong           (RLShadePhong+RLLightOn+RLFillSolid)

typedef enum _RLLightingFrequency
{   RLLightNever,
    RLLightOnce,
    RLLightContinually
} RLLightingFrequency;

typedef enum _RLTextureQuality
{   RLTextureNearest,           /* choose nearest texel */
    RLTextureLinear,            /* interpolate 4 texels */
    RLTextureMipNearest,        /* nearest texel in nearest mipmap  */
    RLTextureMipLinear,         /* interpolate 2 texels from 2 mipmaps */
    RLTextureLinearMipNearest,  /* interpolate 4 texels in nearest mipmap */
    RLTextureLinearMilLinear    /* interpolate 8 texels from 2 mipmaps */
} RLTextureQuality;

typedef enum _RLCombineType
{   RLCombineReplace,
    RLCombineBefore,
    RLCombineAfter
} RLCombineType;

typedef enum _RLColourModel
{   RLColourRamp, RLColourRGB
} RLColourModel;

typedef enum _RLPaletteFlags
{   RLPaletteFree,              /* renderer may use this entry freely */
    RLPaletteReadOnly,          /* fixed but may be used by renderer */
    RLPaletteReserved           /* may not be used by renderer */
} RLPaletteFlags;

typedef struct _RLPaletteEntry
{   unsigned char red;          /* 0 .. 255 */
    unsigned char green;        /* 0 .. 255 */
    unsigned char blue;         /* 0 .. 255 */
    unsigned char flags;        /* one of RLPaletteFlags */
} RLPaletteEntry;

typedef struct _RLImage
{   int width, height;          /* width and height in pixels */
    int aspectx, aspecty;       /* aspect ratio for non-square pixels */
    int depth;                  /* bits per pixel */
    int rgb;                    /* if false, pixels are indices into a
                                   palette otherwise, pixels encode
                                   RGB values. */
    int bytes_per_line;         /* number of bytes of memory for a
                                   scanline. This must be a multiple
                                   of 4. */
    void* buffer1;              /* memory to render into (first buffer). */
    void* buffer2;              /* second rendering buffer for double
                                   buffering, set to NULL for single
                                   buffering. */
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    unsigned long alpha_mask;   /* if rgb is true, these are masks for
                                   the red, green and blue parts of a
                                   pixel.  Otherwise, these are masks
                                   for the significant bits of the
                                   red, green and blue elements in the
                                   palette.  For instance, most SVGA
                                   displays use 64 intensities of red,
                                   green and blue, so the masks should
                                   all be set to 0xfc. */
    int palette_size;           /* number of entries in palette */
    RLPaletteEntry* palette;    /* description of the palette (only if
                                   rgb is false).  Must be (1<<depth)
                                   elements. */
} RLImage;

typedef enum _RLWrapType
{   RLWrapFlat,
    RLWrapCylinder,
    RLWrapSphere,
    RLWrapChrome
} RLWrapType;

#define RLWireframeCull         1 /* cull backfaces */
#define RLWireframeHiddenLine   2 /* lines are obscured by closer objects */

typedef enum _RLProjectionType
{   RLProjectPerspective,
    RLProjectOrthographic
} RLProjectionType;

typedef enum _RLXOFFormat
{   RLXOFBinary,
    RLXOFCompressed,
    RLXOFText
} RLXOFFormat;

#define RLXOFSaveNormals                1
#define RLXOFSaveTextureCoordinates     2
#define RLXOFSaveMaterials              4
#define RLXOFSaveTextureNames           8
#define RLXOFSaveAll                    15

typedef enum _RLColourSource
{   RLColourFromFace,
    RLColourFromVertex
} RLColourSource;

typedef enum _RLFrameConstraint
{   RLConstrainZ,               /* use only X and Y rotations */
    RLConstrainY,               /* use only X and Z rotations */
    RLConstrainX                /* use only Y and Z rotations */
} RLFrameConstraint;

typedef enum _RLMaterialMode
{   RLMaterialFromMesh,
    RLMaterialFromParent,
    RLMaterialFromFrame
} RLMaterialMode;

typedef enum _RLFogMode
{   RLFogLinear,                /* linear between start and end */
    RLFogExponential,           /* density * exp(-distance) */
    RLFogExponentialSquared     /* density * exp(-distance*distance) */
} RLFogMode;

typedef enum _RLDecalDepth
{   RLDecalFront,               /* decal is in front of everything */
    RLDecalBack,                /* decal is behind everything */
    RLDecalMix                  /* decal is mixed in according to depth */
} RLDecalDepth;

typedef enum _RLAnimationType
{
    RLAnimationOpen,
    RLAnimationClosed
} RLAnimationType;

typedef enum _RLInterpolationType
{
    RLInterpolationLinear,
    RLInterpolationCubicSpline
} RLInterpolationType;

typedef void* (*RLMallocFunction)(size_t);
typedef void* (*RLReallocFunction)(void*, size_t);
typedef void  (*RLFreeFunction)(void*);

/* new mesh stuff */

typedef unsigned long RLMapping, RLMappingFlag;
static const RLMappingFlag RLMapWrapU = 1;
static const RLMappingFlag RLMapWrapV = 2;
static const RLMappingFlag RLMapPerspCorrect = 4;

typedef struct _RLVertex
{   RLVector        position;
    RLVector        normal;
    RLValue         tu, tv;
    RLColour        colour;
} RLVertex;

typedef int RLGroupIndex; /* group indexes begin a 0 */
static const RLGroupIndex RLAllGroups = -1;

/*
 * Create a colour from three components in the range 0-1 inclusive.
 */
extern RLColour RLAPI   RLCreateColourRGB(RLValue red,
                                          RLValue green,
                                          RLValue blue);

/*
 * Create a colour from four components in the range 0-1 inclusive.
 */
extern RLColour         RLAPI RLCreateColourRGBA(RLValue red,
                                                 RLValue green,
                                                 RLValue blue,
                                                 RLValue alpha);

/*
 * Get the red component of a colour.
 */
extern RLValue          RLAPI RLColourGetRed(RLColour);

/*
 * Get the green component of a colour.
 */
extern RLValue          RLAPI RLColourGetGreen(RLColour);

/*
 * Get the blue component of a colour.
 */
extern RLValue          RLAPI RLColourGetBlue(RLColour);

/*
 * Get the alpha component of a colour.
 */
extern RLValue          RLAPI RLColourGetAlpha(RLColour);

/*
 * Add two vectors.  Returns its first argument.
 */
extern RLVector*        RLAPI RLVectorAdd(RLVector* d,
                                          RLVector* s1,
                                          RLVector* s2);

/*
 * Subtract two vectors.  Returns its first argument.
 */
extern RLVector*        RLAPI RLVectorSubtract(RLVector* d,
                                               RLVector* s1,
                                               RLVector* s2);
/*
 * Reflect a ray about a given normal.  Returns its first argument.
 */
extern RLVector*        RLAPI RLVectorReflect(RLVector* d,
                                              RLVector* ray,
                                              RLVector* norm);

/*
 * Calculate the vector cross product.  Returns its first argument.
 */
extern RLVector*        RLAPI RLVectorCrossProduct(RLVector* d,
                                                   RLVector* s1,
                                                   RLVector* s2);
/*
 * Return the vector dot product.
 */
extern RLValue          RLAPI RLVectorDotProduct(RLVector* s1,
                                                 RLVector* s2);

/*
 * Scale a vector so that its modulus is 1.  Returns its argument or
 * NULL if there was an error (e.g. a zero vector was passed).
 */
extern RLVector*        RLAPI RLVectorNormalise(RLVector*);

/*
 * Return the length of a vector (e.g. sqrt(x*x + y*y + z*z)).
 */
extern RLValue          RLAPI RLVectorModulus(RLVector* v);

/*
 * Set the rotation part of a matrix to be a rotation of theta radians
 * around the given axis.
 */

extern RLVector*        RLAPI RLVectorRotate(RLVector* r, RLVector* v, RLVector* axis, RLValue theta);

/*
 * Scale a vector uniformly in all three axes
 */
extern RLVector*        RLAPI RLVectorScale(RLVector* d, RLVector* s, RLValue factor);

/*
 * Return a random unit vector
 */
extern RLVector*        RLAPI RLVectorRandom(RLVector* d);

/*
 * Returns a unit quaternion that represents a rotation of theta radians
 * around the given axis.
 */

extern RLQuaternion*    RLAPI RLQuaternionFromRotation(RLQuaternion* quat,
                                                       RLVector* v,
                                                       RLValue theta);

/*
 * Calculate the product of two quaternions
 */
extern RLQuaternion*    RLAPI RLQuaternionMultiply(RLQuaternion* q,
                                                   RLQuaternion* a,
                                                   RLQuaternion* b);

/*
 * Interpolate between two quaternions
 */
extern RLQuaternion*    RLAPI RLQuaternionSlerp(RLQuaternion* q,
                                                RLQuaternion* a,
                                                RLQuaternion* b,
                                                RLValue alpha);

/*
 * Calculate the matrix for the rotation that a unit quaternion represents
 */
extern void             RLAPI RLMatrixFromQuaternion(RLMatrix4d mat, RLQuaternion* quat);

#if defined(__cplusplus)
};
#endif

#endif /* rltypes.h */
