/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: r:/prj/lib/src/inp6d/rcs/i6dvideo.h $
 * $Revision: 1.6 $
 * $Author: jaemz $
 * $Date: 1995/01/04 20:29:08 $
 *
 * 2d hacking needed by the 6d library
 */

#ifndef __I6DVIDEO_H
#define __I6DVIDEO_H

#include <fix.h>
#include <2d.h>

/* public symbols other people may care about someday
 * as well as types, prototypes, and defines
 */

// stereo stuff
typedef struct {
   grs_canvas whole_shmear;
   grs_canvas left_eye, right_eye;
} i6s_stereo_canvii;

typedef struct {
   i6s_stereo_canvii on_screen_p1;
   i6s_stereo_canvii on_screen_p2;
   i6s_stereo_canvii off_screen;
   int               flags, scr_mode;
   short             scr_w, scr_h, eye_w, eye_h;
   fixang            fov_w, fov_h;
   fix               infin_asp, eye_asp;
   grs_canvas       *stereo_screen;
   grs_canvas       *cf_infin, *cf_left, *cf_right;
} i6s_stereo_setup;

// publics
extern int         (*i6_video)(int to_do, void *data);
extern i6s_stereo_setup *i6d_ss;

#define i6_get_canvas(can)

// and relevant defines 
#define I6VID_STARTUP     0x0001    // lets see whats up
#define I6VID_STR_START   0x0002    // create the stereo data memory area
#define I6VID_STR_SETUP   0x0004    // setup the stereo data fields and such
#define I6VID_GO_STEREO   0x0008    // into stereo mode
#define I6VID_GO_MONO     0x0010    // back out
#define I6VID_DO_PFLIP    0x0020    // flip to the other page
#define I6VID_FRM_START   0x0040    // setup the cf canvii
#define I6VID_FRM_INFIN   0x0080    // start the infinite frame
#define I6VID_FRM_STEREO  0x0100    // infinite area done, on to stereo region
#define I6VID_FRM_DONE    0x0200    // done with all frames, munge if needed
#define I6VID_FRM_COPY    0x0400    // munged, overlayed, go to screen
#define I6VID_SET_MODE    0x0800    // did a set mode
#define I6VID_CLEAR_MODE  0x1000    // did a set mode
#define I6VID_TOGGLE_MODE 0x2000    // toggle the mode

#define I6VID_CLOSEDOWN   0x8000    // hit the road

// flags for the stereo_setup structure
#define I6VID_FLG_FRMBUF  0x001     // frame buffering or not
#define I6VID_FLG_PFLIP   0x002     // page flip potential or not

#define I6VID_FLG_INSTER  0x100     // are we in stereo mode
#define I6VID_FLG_PAGEID  0x200     // are we on page 0 or 1

#define I6VID_FLG_CREATED 0x800     // is this i6d_ss using memory we alloced

// values returned by the video calls
#define I6VID_WHOLE       0x1000
#define I6VID_EYES        0x2000

/* now secret internal to the library gnosis
 */

int i6_no_video(int to_do, void *data);
bool i6_device_revector(int (*new_pal)(int,int,uchar *), int (*new_close)(void));

i6s_stereo_setup *i6_get_ster_setup(void);
void i6_free_ster_setup(i6s_stereo_setup *l_ss);
bool svga_pflip_stereo_setup(i6s_stereo_setup *l_ss);
bool mcga_stereo_setup(i6s_stereo_setup *l_ss);

// if you need to chain to it....
extern int (*old_set_pal)(int start,int n,uchar *pal_data);

i6s_stereo_setup *i6_setup_stereo(bool frame_buffer);
#endif
