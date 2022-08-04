/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/userpnp.h 1.1 1996/08/02 06:01:03 mahk Exp $
#ifndef __USERPNP_H
#define __USERPNP_H

#include <swappnp.h>

EXTERN void CreateUserPNP(LGadRoot* root, Rect* bounds, editBrush* brush);
EXTERN void UpdateUserPNP(GFHUpdateOp op, editBrush* brush);
EXTERN void DestroyUserPNP(void);

#endif // __USERPNP_H
