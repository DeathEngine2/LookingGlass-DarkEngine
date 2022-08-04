//		EFILE.H		.e file interface
//

/*
* $Header: x:/prj/tech/libsrc/3dsconv/RCS/efile.h 1.22 1997/11/09 12:03:09 JAEMZ Exp $
* $Log: efile.h $
 * Revision 1.22  1997/11/09  12:03:09  JAEMZ
 * Added way to force width and height to fix data bug
 * 
 * Revision 1.21  1997/06/10  16:31:06  JAEMZ
 * Added comment
 * 
 * Revision 1.20  1996/12/06  14:39:08  JAEMZ
 * Added lot's of new functions for Allocing and not setting Erecs
 * 
 * Revision 1.19  1996/12/04  17:09:51  JAEMZ
 * Added fields to mesh, made erec 2 mesh
 * 
 * Revision 1.18  1996/12/04  01:18:30  JAEMZ
 * Changed shorts to ints, so we can have BBBIIIIGGG files
 * 
 * Revision 1.17  1996/12/03  21:08:23  JAEMZ
 * Added Read3ds as a routine
 * 
 * Revision 1.16  1996/12/03  20:13:24  JAEMZ
 * Added wire and dbl to the structures
 * 
 * Revision 1.15  1996/11/13  16:53:16  JAEMZ
 * Added double sided
 * 
 * Revision 1.14  1996/05/31  18:55:41  JAEMZ
 * Added transparency field to material.
 * 
 * Revision 1.13  1996/05/21  19:20:53  JAEMZ
 * Added color field
 * 
 * Revision 1.12  1996/01/16  19:45:12  JAEMZ
 * Added shading parm
 * 
 * Revision 1.11  1993/11/30  18:17:21  rex
 * Added tolerance param to EsetRemoveRedundantPoints
 * 
 * Revision 1.10  1993/11/19  13:07:46  rex
 * Changed EsetFindCentroid() arg from zfloor to yfloor
 * 
 * Revision 1.9  1993/11/15  16:41:31  rex
 * Modified EsetScalePoints() to take object index, added EsetRotatePoints(),
 * added EvecNeg()
 * 
 * Revision 1.8  1993/11/04  10:16:48  rex
 * Added more prototypes
 * 
 * Revision 1.7  1993/10/29  09:42:29  rex
 * Added a few more prototypes
 * 
 * Revision 1.6  1993/10/28  15:13:15  rex
 * Added include of <string.h> and <types.h>
 * 
 * Revision 1.5  1993/10/28  15:09:53  rex
 * Put #ifndef wrapper around contents
 * 
 * Revision 1.4  1993/10/28  15:07:16  rex
 * Added new evec functions
 * 
 * Revision 1.3  1993/10/28  13:59:17  rex
 * Added prototypes for zillions of erec functions
 * 
 * Revision 1.2  1993/09/28  17:18:20  rex
 * Extended structures to allow up to 8 vertices per face
 * 
 * Revision 1.1  1993/09/16  15:04:33  rex
 * Initial revision
 * 
 * Revision 1.1  1993/09/16  15:01:46  rex
 * Initial revision
 * 
*/

#ifndef EFILE_H
#define EFILE_H

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
	Ertype type;					// record type
	union {
		char *s;						// ptr to string
		EmaterialSet *pmatset;	// ptr to material set
		EpointSet *ptset;			// ptr to point set
		EfaceSet *pfaceset;		// ptr to face set
		EmappingSet *pmapset;	// ptr to face mappings set
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


