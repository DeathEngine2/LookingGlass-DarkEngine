/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: x:/prj/tech/libsrc/inp6d/RCS/inp6d.h $
 * $Revision: 1.22 $
 * $Author: TOML $
 * $Date: 1996/10/23 09:36:22 $
 *
 * Declarations for 6d input library.
 */

#ifndef _WIN32
#ifndef __INP6D_H
#define __INP6D_H

#include <fix.h>

/* constants for different 6d input devices. */
enum {
   I6D_NONE,
   I6D_SBALL,
   I6D_CYBERMAN,
   I6D_VFX1,
   I6D_SWIFT,
   I6D_CTM,
   I6D_ALLPRO,
   I6D_VIO,
   I6D_OCTM,
   I6D_WARRIOR,
   I6D_DEVICES
};

enum {
   I6D_X,            // out the right
   I6D_Y,            // in, into the world
   I6D_Z,            // up up up...
   I6D_RX,           // pitch, really
   I6D_RY,           // bank, really
   I6D_RZ,           // heading, really
};


// for i6_set_detect
#define I6F_SBALL      1
#define I6F_CYBERMAN   2
#define I6F_VFX1       4
#define I6F_SWIFT      8
#define I6F_CTM       16
#define I6F_ALLPRO    32
#define I6F_VIO       64
#define I6F_OCTM     128
#define I6F_HEADSETS   (4|16|32|64|128)


typedef struct {
   short but;        /* button state bitfield */
#ifdef __cplusplus
   short x, y, z, rx, ry, rz ;
#else
   union {
      struct {
         short x,y,z;      /* location data */
         ushort rx,ry,rz;   /* rotation data */
      };
      short els[6];        /* for easy access */
   };
#endif
   short newbutt;    /* buttons whose state changed... */
   short descriptor; /* who, what, when, why, where */
} i6s_event;

typedef struct {
   char     name[12];   // name of device
   int      num_buts;   // number of buttons
   short    x,y,z;      // range of these +-
   ushort   rx,ry,rz;   // range of these +- (0 to 180)
   bool     video;      // does it do video?
   fixang   fov;        // field of view
   fix      asp;        // aspect ratio
   bool     stereo;     // does it do stereo video?
   fix      st_asp;     // stereo aspect
   fix      st_off;     // percentage amount to move 2d screens to correct for stereo
   bool     phys;       // whether you have physical screen mem for mouse
   short    max_vw,max_vh;  // max video w and h
   short    max_stw,max_sth;  // max stereo w and h
   char     ver[20];  // version number, set by installer
} i6s_info;


extern char          i6d_probe_flag;
extern char         *i6d_message;
extern int           i6d_device;
extern i6s_event    _inp6d_event;

// probe for devices, eh?
extern int           i6_probe_small(void);
extern int           i6_probe(void);
extern int           i6_force(int w);

// function pointer list from hell
extern int         (*i6_startup)(void);
extern int         (*i6_shutdown)(void);
extern i6s_event  *(*i6_poll)(void);
extern i6s_info      *i6d_info;

// functions to enable and disable filtering and hysteresis
// on input devices
void i6_filter(bool f);
void i6_hysteresis(bool f);
// whether to autoscale pitch/bank, default yes
void i6_autoscale(bool f);
void i6_recenter(void);

// Pass this the or of the flags before you call
// the detector to set which things you want to
// detect for
void i6_set_detect(uint f);

#endif
#endif