/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/3dsconv/RCS/efile.h 1.24 1998/09/25 17:19:07 jaemz Exp $

#ifndef EFILE_H
#define EFILE_H
#pragma once

#include <string.h>

#include <types.h>
#include <matrixs.h>

//	-----------
//	Erec format
//	-----------

#define MAX_EFACE_VERTICES 8		// maximum # vertices per eface

typedef enum {
   E_END,			// end record (must be 0)
   E_COMMENT,		// comment record
   E_MATERIAL,		// material record
   E_BEGIN,			// begin record
   E_POINTS,		// points record
   E_PARTS,			// parts record (faces)
   E_PARTMAPPINGS, // part mappings record (face, uv pairs)
   E_PARTVNORMS,  // part vertex normals record (face, normals)
   E_PARTVCOLORS, // part vertex colors record (face, rgba ulong)
   E_ORIENTATION  // Orientation transform of object
} Ertype;

typedef struct {
   short num;			// material number
   char *name;			// material name
   char *tmapName;	// tmap name or NULL
   uchar intensity;	// intensity
   uchar shading;    // shading type 1=flat,gouraud,phong,metal
   long color;   // 0bgr rep of color, or -1 if not present
   long transp;   // transparency
   bool  dbl;   // double sided or not
   bool  wire;  // wire or not
   long illum;  // self illumination 
} Ematerial;

typedef struct {
   int numMats;		// number of materials
   Ematerial *pmats;	// ptr to array of materials
} EmaterialSet;

typedef struct {
   float x;
   float y;
   float z;
} Evector;

typedef Evector Epoint;

typedef struct {
   int numPts;		// number of points
   Epoint *ppts;		// ptr to array of points
} EpointSet;

typedef struct {
   uchar type;			// type (usually 0)
   uchar vis;			// visibility (usually 'N')
   int   ref;			// reference (index)
   ushort color;		// color, hiword usually 0xff
   int  numPts;		// number of points (3 or 4)
   int  pts[MAX_EFACE_VERTICES];	// point indices
} Eface;

typedef struct {
   int  numFaces;	// number of faces
   Eface *pfaces;		// ptr to array of faces
} EfaceSet;

typedef struct {
   float u;
   float v;
} Euv;

typedef struct {
   int   face;			// face number
   short numuv;		// # uv mappings
   Euv uv[MAX_EFACE_VERTICES];	// uv mappings, one per point in face
} Emapping;

typedef struct {
   int numMappings;	// number of mappings
   Emapping *pmaps;		// ptr to array of mappings
} EmappingSet;

typedef struct {
   int face;         // face number
   int numn;         // # vertex normals
   Evector n[MAX_EFACE_VERTICES];
} EpartVNorms;

typedef struct {
   int numPartVNorms;   // number of part vertex normals
   EpartVNorms *ppvns; // ptr to array of part vertex normals
} EpartVNormsSet;      

typedef struct {
   int face;         // face number
   int numc;         // # vertex colors
   ulong c[MAX_EFACE_VERTICES]; // vertex colors, rgba
} EpartVColors;

typedef struct {
   int numPartVColors;   // number of part vertex colors
   EpartVColors *ppvcs; // ptr to array of part vertex colors
} EpartVColorsSet;      

typedef struct {
   Ertype type;					// record type
   union {
      char *s;						// ptr to string
      EmaterialSet *pmatset;	// ptr to material set
      EpointSet *ptset;			// ptr to point set
      EfaceSet *pfaceset;		// ptr to face set
      EmappingSet *pmapset;	// ptr to face mappings set
      EpartVNormsSet *ppvnset;  // ptr to face vertex normals set
      EpartVColorsSet *ppvcset; // ptr to face vertex colors set
      mxs_trans *ptrans;      // ptr to orientation transform
   };
} Erec;

//	Macro used to copy string into erec

#define ErecCopyString(s) strdup(s)

//	----------
//	Prototypes
//	----------

//	Read and write e-files (efile.c)

int EfileRead(Erec *perec, FILE *fp);	// read file into empty erec array
int EfileWrite(Erec *perec, FILE *fp);	// write file from erec array


// Turn a height field into an erec

// Mesh initializer
typedef struct {
   char *name;       // name of mesh
   int w,h,row;      // width, height, and row of height field
   float *field;     // the height field
   float xs,ys,zs;   // xscale, yscale, zscale
   float xb,yb,zb;   // offsets for x,y, and z
   char *matname;    // material name
   char *matfile;    // material file name 
   int winding;      // 0 is clockwise, 1 counterclockwise
   uchar *dirmap;    // direction map if present (w-1)x(h-1) big, leave NULL otherwise
   int   drow;       // direction map row size
   int xdir,ydir;    // direction of mappings, 0 is with, 1 against axis
} MeshInfo;

// Makes a height field into an erec, suitable
// for output
void Mesh2Erec(Erec *perec,MeshInfo *mi);

// Turns an erec into a mesh, fills in everything but winding
// and dirmap, and drow, and xdir, and ydir, cause I'm lazy
// Mallocs name, matname, matfile and dirmap
// Mallocs mi if you pass in Null
// Err gets set to FALSE if holes were left
// Set use_wh true to use the w and h and row as you set them
MeshInfo *Erec2Mesh(Erec *perec,MeshInfo *mi,bool use_wh,int *err);
                                                      
// Frees a mesh info, assumes it was malloced,
// and everything in it too.
// This will work on one stuffed by Erec2Mesh
void FreeMesh(MeshInfo *mi);


// Write 3ds files (write 3ds)
// Needs to be well behaved erec,
// all triangles, and one mapping per
// vertex
void Write3DS(Erec *perec,FILE *fp);

// returns 0 on error
// pass in title for efile
// and the erec and
// and verbose or not
// If non zero, returns number of records read
int Read3ds(Erec *perec,FILE *fp,char *titlename,bool verbose);

//	Allocate and free e-records (erec.c)

Erec *ErecAllocSet(int numRecords);		// allocate array of e records
void ErecFreeSet(Erec *perec);			// free all records and then array
void ErecFree(Erec *perec);				// free particular records

//	Make particular e-records (erec.c)

void ErecMakeEnd(Erec *perec);
void ErecMakeComment(Erec *perec, char *s);
void ErecMakeMaterials(Erec *perec, int numMats, Ematerial *pmat);
void ErecMakeBegin(Erec *perec, char *s);
void ErecAllocPoints(Erec *perec, int numPts);
void ErecMakePoints(Erec *perec, int numPts, Epoint *ppts);
void ErecAllocParts(Erec *perec, int numFaces);
void ErecMakeParts(Erec *perec, int numFaces, Eface *pfaces);
void ErecAllocPartMappings(Erec *perec,int numMappings);
void ErecMakePartMappings(Erec *perec, int numMappings, Emapping *pmaps);
void ErecAllocPartVNorms(Erec *perec, int numPVNs);
void ErecMakePartVNorms(Erec *perec, int numPVNs, EpartVNorms *ppvns);
void ErecAllocPartVColors(Erec *perec, int numPVCs);
void ErecMakePartVColors(Erec *perec, int numPVCs, EpartVColors *ppvcs);
void ErecAllocOrientation(Erec *perec);
void ErecMakeOrientation(Erec *perec,mxs_trans *t);

// Find a particular e-record
void *ErecFindType(Ertype e,Erec *erec);

//	Manipulate erec array points (epoint.c)

void EsetRemoveRedundantPoints(Erec *perec, double tol);
void EsetScalePoints(Erec *perec, int index, Evector vscale);
void EsetRotatePoints(Erec *perec, int index, double rotate);
void EsetFindCentroid(Erec *perec, int index, bool yfloor, Evector *pcentroid);
void EsetMove(Erec *perec, int index, Evector *pvec);

//	Manipulate erec array parts (epart.c)

int EsetCollapseTriangles(Erec *prec);
bool EfaceIsConvex(Eface *pface, EpointSet *pptset);
void EsetRenumberParts();

//	Manipulate erec array u,v coords (euv.c)

void EsetUvFlip(Erec *perec, bool fu, bool fv);
void EsetUvSnap(Erec *perec, double tol, int gran);

//	Manipulate erec array materials (emat.c)

int EsetMapMaterials(Erec *perec, char *fname);
void EsetRemoveNonTmapMappings(Erec *perec);

//	Miscellaneous erec array manipulations (emisc.c)

int EsetNumObjects(Erec *perec);
Erec *EsetFindObject(Erec *perec, int index);
char *EsetGetObjectName(Erec *perec, int index);
void EsetRenameObject(Erec *perec, int index, char *name);

//	3d primitives for Evectors

double EvecMag(Evector *v);
void EvecScale(Evector *v, double s);
void EvecAdd(Evector *dest, Evector *src1, Evector *src2);
void EvecSub(Evector *dest, Evector *src1, Evector *src2);
void EvecNeg(Evector *v);
void EvecNormalize(Evector *v);
int EvecDir(Evector *v);
void EvecDotProduct(Evector *dest, Evector *v0, Evector *v1);
void EvecCrossProduct(Evector *dest, Evector *v0, Evector *v1);
void EvecNormal(Evector *norm, Evector *v0, Evector *v1, Evector *v2);

#endif


