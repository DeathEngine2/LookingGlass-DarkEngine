/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: x:/prj/tech/libsrc/loco/RCS/idlist.h $
// $Author: JON $
// $Date: 1996/10/30 11:55:37 $
// $Revision: 1.2 $
//

#ifndef __IDLIST_H
#define __IDLIST_H

#include "types.h"
#include "limits.h"

typedef ushort ListID;

#define LIST_ID_INVALID USHRT_MAX

typedef struct _IDList 
{
   ListID id;
   ListID next_id;	// ID of next node or INVALID if at tail
} IDList;

// List header

#define ID_LIST_RESIZE 0x01 // resize the list when we run out of mem 
typedef struct _IDListHead
{
   uchar flags;
   ListID free_id; // free list
   void *nodes;
   ushort nodes_num;
   ushort node_size;
} IDListHead;

// Get a pointer to a node from a list header and node index
#define ID_LIST_NODE(list_head, i) ((IDList*)(&(((BYTE*)((list_head)->nodes))[(i)*((list_head)->node_size)])))
// Next functions
#define ID_LIST_NEXT_FROM_ID(list_head, node_id) (ID_LIST_NODE(list_head, ID_LIST_NODE(list_head, node_id)->next))
#define ID_LIST_NEXT(list_head, node) (ID_LIST_NODE(list_head, ((IDList*)node)->next_id))
#define ID_LIST_NEXT_ID(list_head, node) (((IDList*)node)->next_id)

extern void IDListFreeAll(IDListHead *list_head);
extern void IDListDestroy(IDListHead *list_head);
extern bool IDListInit(IDListHead *list_head, ushort nodes_num, ushort node_size, uchar flags);
extern ListID IDListGet(IDListHead *list_head);
extern bool IDListFree(ListID list, IDListHead *list_head);

extern ListID IDListAdd(ListID *list, IDListHead *list_head);
extern ListID IDListFindPrev(ListID node_id, ListID list, IDListHead *list_head);
extern bool IDListRemove(ListID node_id, ListID *list, IDListHead *list_head);

#endif // __IDLIST_H


