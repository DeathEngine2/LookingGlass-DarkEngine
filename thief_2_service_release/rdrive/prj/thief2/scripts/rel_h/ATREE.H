/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/atree.h 1.1 1997/12/02 17:08:27 kate Exp $

#ifndef __ATREE_H
#define __ATREE_H

typedef class cATree cATree;
typedef class cATreeNode cATreeNode;

// XXX can add different node type if want bigger key

typedef ulong tAKey;
typedef struct sAKeyDesc sAKeyDesc;

struct sAKeyDesc
{
   int nValues;
   uchar *pValues;
};

class cATree
{
public:

   cATree(const int bitsPerLevel, const int maxDepth); // XXX Assert if > sizeof(long)
   cATree(const cATree& atree); // copy constructor
   ~cATree();

   tAKey BuildKey(const sAKeyDesc& keyDesc);
   void InsertData(const void *dataPtr, const tAKey key);
   void *GetData(const tAKey key);

   int GetWildValue() const { return m_MaxEntriesPerLevel; } // the value to pass in to
                                                    // keydesc when
                                                    // any value is fine.

private:

   const int m_BitShift;
   const int m_MaxEntriesPerLevel;
   const int m_MaxDepth;
   cATreeNode *m_pHead;

};

#endif
