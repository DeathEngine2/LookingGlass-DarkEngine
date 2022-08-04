//	Anim.H		Animation system header file.
//	Rex E. Bradford (REX)

/*
* $Header: r:/prj/lib/src/anim/rcs/anim.h 1.7 1995/02/28 19:14:01 dfan Exp $
* $Log: anim.h $
 * Revision 1.7  1995/02/28  19:14:01  dfan
 * AnimInstallTimeVar
 * 
 * Revision 1.6  1994/09/01  15:13:20  rex
 * Added length to data buffer, with safe macro which sets it
 * 
 * Revision 1.5  1994/09/01  04:46:27  minman
 * allows for buffer to be used for cutscene to be passed in
 * 
 * Revision 1.4  1993/10/26  17:13:11  rex
 * Added prototype for AnimKillAll()
 * 
 * Revision 1.3  1993/10/12  12:57:44  dc
 * hey look, angle
 * 
 * Revision 1.2  1993/09/30  09:55:47  rex
 * Added noPatch flag to anim header, replaced frameSetId in anim struct with
 * currFrameRef, and add AnimPlayNoCanvas() and AnimGetCurrFrameRef() macros.
 * 
 * Revision 1.1  1993/05/14  11:29:39  rex
 * Initial revision
 * 
 * Revision 1.6  1993/05/12  18:10:20  rex
 * Revamped by Art Min for viewport-independency
 * 
 * Revision 1.4  1993/04/15  16:26:05  rex
 * Changed pnext & pprev into _llist
 * 
 * Revision 1.3  1992/11/17  13:35:56  rex
 * Modified ActAnim struct to support animation scaling
 * 
 * Revision 1.2  1992/09/03  10:57:17  unknown
 * Changed ActAnim struct to support anims which play into owner canvas instead
 * of creating their own viewport.  Added ANCODE_XXX codes for anim events;
 * added prototype for AnimPlayCanvas(). (rex)
 * 
 * Revision 1.1  1992/08/31  16:57:17  unknown
 * Initial revision
 * 
*/

#ifndef ANIM_H
#define ANIM_H

#include <rect.h>
#include <llist.h>
#include <res.h>
#include <2d.h>
#include <2dres.h>
#include <fix.h>

//	Animation event codes

typedef uchar AnimCode;

#define ANCODE_NEWFRAME	0x01		// new frame, update screen (arg = ptr to update area)
#define ANCODE_MOVE		0x02		// move anim (arg = ptr to x,y,z delta)
#define ANCODE_END		0x04		// end anim w/o kill (no arg)
#define ANCODE_KILL		0x08		// kill anim (no arg)
#define ANCODE_MARK		0x10		// user marking (arg = user param)
#define ANCODE_RESCALE  0x20     // animation rescaled
#define ANCODE_REANCHOR 0x40     // anchor has moved
#define ANCODE_RESIZE   0x80     // the animation has a new size

// Define the ancodes that the composer is interested in

#define ANCODE_COMPOSER (ANCODE_NEWFRAME | ANCODE_MOVE | ANCODE_KILL | ANCODE_RESCALE | \
                        ANCODE_REANCHOR | ANCODE_RESIZE)

//	Animation events are accompanied by one of these:

typedef struct {
	short				dx;				// delta motion of anim, in x
	short				dy;				// delta motion of anim, in y
	short				dz;				// delta motion of anim, in z
   Point          anchorOff;		// amt by which anchor moved, or 0,0
   Point          newsize;			// new changed size, or 0,0
   Rect           updateArea;		// new frame update area, or 0,0,0,0
   short          marker;			// marker code, or 0
} AnimCodeData;

//	AnimHead: describes the header of an individual animscript resource

typedef struct {
	Point size;				// size of anim
	Id frameSetId;			// resource id of binary frame set
	Point anchor;			// anchor point of anim
	short znominal;		// nominal zpos, scale if non-zero
	ushort transp:1;		// does animation include transparencies?
	ushort realtime:1;	// should animation try to keep up with realtime?
	ushort noPatch:1;		// frames are not RSD patches of prev frame
} AnimHead;

//	ActAnim: describes an active animation record

typedef struct ActAnim_ {
	struct			_llist;			// list ptrs
	grs_canvas		*pcv;		      // ptr to canvas playing into
	void				(*composerFunc) (struct ActAnim_ *paa, AnimCode ancode, AnimCodeData *animData); // composer evt handler
	void				*pContainer;   // ptr to container object
	void				(*notifyFunc) (struct ActAnim_ *paa, AnimCode ancode, AnimCodeData *animData); // owner evt handler
	void				*powner;       // ptr to owner of object
	AnimCode			ownerMask;     // mask of what events the owner wants
	Ref				refScript;		// ref of animation script
	AnimHead			*pah;	   		// ptr to animation header
	uchar				*pCurr;			// ptr to current step
	uchar				*pLoopBegin;	// ptr to loop begin point
	short				loopCount;		// loop counter
	Ref				currFrameRef;	// current frame ref
	short				frameRunNum;	// current frame number, -1 if not in run
	short				frameRunEnd;	// last frame in run + 1
	short				frameDelay;		// frame delay in frame set
	fix				animRate;		// animation rate
	ulong				timeContinue;	// time at which to advance to next step
	fix				xadv;				// whole/fract position for moving anims
	fix				yadv;
	fix				zadv;
	fix				xspeed;			// whole/fract speed for moving anims
	fix				yspeed;
	fix				zspeed;
	long				lastTimer;		// last timer value for this guy
	AnimCode			animMask;
	AnimCodeData	ancodeData;
	ushort         realtime : 1;	// anim runs in real time?
	ushort         killed : 1;	   // anim killed this recur?
	ushort         stopped : 1;	// anim stopped?
	ushort         moving : 1;	   // anim moving?
	ushort         active : 1;	   // anim active?
   ushort         bufferFilled : 1;
   void           *dataBuffer;	// data buffer to use for frames, or NULL
	long				dataBufferLen;	// length of data buffer
} ActAnim;

//	General prototypes: anim.c

void AnimInit();									// init animation system
void AnimTerm();									// shut down animation system
void AnimRecur();									// update animations in progress
void AnimInstallTimeVar (long *where);    // tell anim system where to get time

//	Play and control anims: anim.c

#define AnimPlayNoCanvas(anr,pct,cf) AnimPlayCanvas(anr,pct,NULL,cf)

ActAnim *AnimPlayCanvas(Ref animRef, void *pcontainer, grs_canvas *pcv,	// play anim into canvas
   void (*composeFunc)(ActAnim *paa, AnimCode ancode, AnimCodeData *animData));
void AnimChange(ActAnim *paa, Ref animRef);	// change anim
void AnimKill(ActAnim *paa);						// kill one or all anims
void AnimKillAll();									// kill all anims
#define AnimSetRate(paa,rate) ((paa)->animRate = (rate))	// set new anim rate
void AnimSetSpeed(ActAnim *paa, fix xsp, fix ysp, fix zzsp); // set motion spd
void AnimSetNotify(ActAnim *paa, void *powner, AnimCode mask,
	void (*func) (ActAnim *, AnimCode ancode, AnimCodeData *animData));
void AnimMove(ActAnim *paa, short dx, short dy, short dz);	// move anim

//	Deal with animation resources: anim.c

void AnimSetAnimPall(Ref animRef);				// set pall from .ans resource
bool AnimPreloadFrames(ActAnim *paa, Ref animRef);			// preload an anim's frames
Point AnimGetSize(Ref animRef);					// get size of an anim

//	Macro to read anim header from resource

#define AnimReadHeader(ref,pAnhead) (*pAnhead = (* ((AnimHead *) RefGet(ref))));

//	Convenience macros

#define AnimContainer(paa) ((paa)->pContainer)
#define AnimOwner(paa) ((paa)->powner)
#define AnimGetCurrFrameRef(paa) ((paa)->currFrameRef)

#define AnimSetDataBuffer(paa, buffer) { \
	(paa)->dataBuffer = (buffer); (paa)->dataBufferLen = 0x7FFFFFFFL; }
#define AnimSetDataBufferSafe(paa, buffer, len) { \
	(paa)->dataBuffer = (buffer); (paa)->dataBufferLen = (len); }

//	Prototypes: rsdasm.asm

void RsdExpandSameWidth(uchar *pd, uchar *p, int width, int height);

#endif


