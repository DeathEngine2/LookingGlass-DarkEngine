/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pnpvslid.h 1.2 1996/09/25 03:58:35 dc Exp $

#ifndef __PNPVSLID_H
#define __PNPVSLID_H

#include <vslider.h>

typedef struct _pnp_vslider_data
{
   anonSlider* slider;
   void* update_gadg; 
   void (*update_func)(void* g, void* data);
   void* update_data;
} pnp_vslider_data;

EXTERN void _pnp_vslider(Rect* area, char* title, pnp_vslider_data* _data);
EXTERN void _pnp_vslider_destroy(void* g);



#endif // __PNPVSLID_H
