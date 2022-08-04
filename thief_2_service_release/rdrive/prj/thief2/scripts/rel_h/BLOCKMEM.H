/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: x:/prj/tech/libsrc/loco/RCS/blockmem.h $
// $Author: JON $
// $Date: 1996/10/30 11:52:30 $
// $Revision: 1.2 $
//

#ifndef BLOCKMEM_H
#define BLOCKMEM_H

typedef struct _BlockMem
{
  struct _BlockMem *next;	
} BlockMem;

#define ID_LIST_RESIZE 0x01 // resize the list when we run out of mem 
typedef struct _BlockHead
{
   uchar flags;
   BlockMem *free; // free list
   void *nodes;
   ushort nodes_num;
   ushort node_size;
} BlockHead;

// Get a pointer to a node from a list header and node index
#define BLOCK_MEM_NODE(block_head, i) ((BlockMem*)(&(((BYTE*)(block_head->nodes))[(i)*block_head->node_size])))

extern void BlockMemFreeAll(BlockHead *block_head);
extern void BlockMemDestroy(BlockHead *block_head);
extern bool BlockMemInit(BlockHead *block_head, ushort nodes_num, ushort node_size, uchar flags);
extern BlockMem *BlockMemGet(BlockHead *block_head);
extern bool BlockMemFree(BlockMem *block, BlockHead *block_head);

#define BlockMemSafeFree(block, block_head) if ((block) != NULL) BlockMemFree((block), (block_head))
#endif

