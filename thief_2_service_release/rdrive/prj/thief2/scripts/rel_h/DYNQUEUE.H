/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/cpptools/RCS/dynqueue.h 1.2 1998/09/11 13:54:02 jaemz Exp $

#ifndef __DYNQUEUE_H
#define __DYNQUEUE_H
#pragma once

#include <string.h>

// A dynamic queue,
// Let's you add and remove.
// You  set the starting size
// and the block size (which is how much to add or
// subtract at at time)
// Items must be copyable

// Intended for small values only since it reallocs and copies the elements
// themselves every time it expands.
// Example:
// 
// cSmallDynamicQueue<int> q;
//
// q.Add(2);
// q.Add(3);
// // q.Size() would now be 2
// printf("%d\n",*q.Next());
// printf("%d\n",*q.Next());
// // q.Next() would now return NULL

template <class MEMBER>
class cSmallDynamicQueue
{
public:
   cSmallDynamicQueue(int startsize=16,int blocksize=16) : 
      m_size(startsize),
      m_block(blocksize),
      m_head(0),
      m_tail(0)
   {
      m_pBase = new MEMBER[m_size];
   }

   ~cSmallDynamicQueue()
   {
      delete m_pBase;
   }

  
   // Add a member 
   void Add(MEMBER &rAddition)
   {
      m_pBase[m_head] = rAddition;
      m_head = (m_head+1)%m_size;

      // if full, expand
      if (m_head == m_tail) {
         int new_size = m_size + m_block;
         MEMBER *new_base = new MEMBER[new_size];

         // copy head segment
         memcpy(new_base,m_pBase,sizeof(MEMBER)*m_head);

         // copy tail segment
         memcpy(new_base+m_tail+m_block,m_pBase+m_tail
                ,sizeof(MEMBER)*(m_size-m_tail));

         delete m_pBase;
         m_size = new_size;
         m_pBase = new_base;
         m_tail += m_block;
      }
   }

   // Returns the next one
   MEMBER *Next()
   {
      MEMBER *ret;
      // empty
      if (m_tail==m_head) return NULL;

      ret = m_pBase + m_tail;
      m_tail = (m_tail+1)%m_size;

      return ret;
   }

   // Returns number of elements in queue
   int Size()
   {
      if (m_head>=m_tail) return m_head - m_tail;
      return m_head+m_size - m_tail;
   }
   
private:
   MEMBER *m_pBase;     // base pointer
   int m_size;          // current size
   int m_block;         // block size
   int m_head;          // head index
   int m_tail;          // tail index
};

#endif
