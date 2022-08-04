//		PICT.H		Header file for PICT resources
/*
* $Header: r:/prj/lib/src/anim/rcs/pict.h 1.2 1993/10/12 12:57:53 dc Exp $
* $Log: pict.h $
 * Revision 1.2  1993/10/12  12:57:53  dc
 * hey look, angle
 * 
 * Revision 1.1  1993/06/17  09:57:34  rex
 * Initial revision
 * 
*/

#include <2dres.h>

//	PICT header (followed by opcodes)

typedef struct {
	Point size;
} PictHdr;

//	PICT opcodes

#define PICT_CLOSE	0		// no args
#define PICT_CLEAR	1		// uchar color
#define PICT_FCOLOR	2		// uchar color
#define PICT_BCOLOR	3		// uchar color
#define PICT_POINT	4		// short x, short y
#define PICT_HLINE	5		// short x0, short y, short x1
#define PICT_VLINE	6		// short x, short y0, short y1
#define PICT_LINE		7		// short x0, short y0, short x1, short y1
#define PICT_BOX		8		// short x0, short y0, short x1, short y1
#define PICT_RECT		9		// short x0, short y0, short x1, short y1
#define PICT_CIRCLE	10		// short x, short y, short r
#define PICT_DISK		11		// short x, short y, short r
#define PICT_POLYLINE 12	// uchar numverts, short verts[numverts][2]
#define PICT_POLYGON	13		// uchar numverts, short verts[numverts][2]
#define PICT_BITMAP	14		// Ref ref, short x, short y
#define PICT_TEXT		15		// Id font, short x, short y, char string[]
#define PICT_PICT		16		// Ref ref, short x0, short y0, short x1, short y1

//	Function prototypes

void PictDraw(PictHdr *ppict, short x, short y);
void PictDrawScaled(PictHdr *ppict, Rect *parea);

//	Macros to draw PICT's from refs

#define PictDrawRef(ref,x,y) do {	\
	PictDraw(RefLock(ref),x,y);		\
	RefUnlock(ref);						\
	} while(0)

#define PictDrawScaledRef(ref,parea) do {	\
	PictDrawScaled(RefLock(ref),parea);		\
	RefUnlock(ref);								\
	} while(0)

