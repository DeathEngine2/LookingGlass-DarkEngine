/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/txtpnp.h 1.3 1997/07/13 01:49:54 dc Exp $

#ifndef __TXTPNP_H
#define __TXTPNP_H

// returns TXTPNP_NO_PAL_UP if no palette up, else returns currently chosen texture
EXTERN int txtPnP_pal_query(void);
#define TXTPNP_NO_PAL_UP (-2)

// is it allowed to do attaches?  used by txtrpal and such
EXTERN BOOL txtPnP_allow_attach;

// actually query and control attach/detach state
EXTERN BOOL txtPnP_attached(void);
EXTERN void txtPnP_detach(void);
EXTERN void txtPnP_attach(void);

#endif  // __TXTPNP_H
