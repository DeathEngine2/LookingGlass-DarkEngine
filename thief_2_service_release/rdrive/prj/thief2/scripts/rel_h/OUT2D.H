/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: r:/prj/lib/src/out2d/RCS/out2d.h $
 * $Revision: 1.1 $
 * $Author: jaemz $
 * $Date: 1995/04/14 20:36:30 $
 *
 * Declarations for Out2d input library.
 */

#ifndef __OUT2D_H
#define __OUT2D_H

#include <fix.h>

enum {
   O2D_NONE,
   O2D_EXOS,
};

// constants for which constants change
// for environment commands
#define O2F_SPRING 1
#define O2F_DAMP   2
#define O2F_CEN    4
#define O2F_ALL    7

// This says whether a device is present or not
// don't change it, just read it.  It'll be set
// after you probe and turn it on.
extern bool o2d_open;


// Call first
extern int  o2_init();
extern int  o2_close();

// Probe for devices, note that this kills serial, heh.
extern int  o2_probe();

// get joystick coords and buttons
// the only joy we'll ever get
// pointers to x,y,button field
// x and y vary between 1 and -1, first quadrant
// stick seen from above
extern int o2_get_joy(fix *x,fix *y,uchar *but);

// these return bool
extern bool o2_dev_on();    // turns device feedback "on" to defaults
extern bool o2_dev_off();   // turns device "off"

// x and y are amplitude (0-1), duration in msec
// again, first quad, seen above
extern bool o2_pulse(fix x,fix y,int dur);

// rumble amplitude about x,y  (0-1), freq is frequency
// of rumble in hertz.  0,0 to turn off
extern bool o2_rumble(fix x,fix y,int freq);

// Pass in new spring constants, damping, and the flag
// saying which of those are to be changed.  O2F_ALL means
// change all.  
// Spring and damper are between 0-1
// Ice    s=0   d=0
// Normal s=.1  d=.02
// Water  s=.35 d=.05
// Mud    s=.55 d=.08
extern bool o2_xmodel(fix spring, fix damp, fix cen,uchar flag);
extern bool o2_ymodel(fix spring, fix damp, fix cen,uchar flag);



#endif
