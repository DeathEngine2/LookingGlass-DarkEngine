/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/mskltree.h 1.1 1997/12/16 13:05:59 kate Exp $

#ifndef __MSKLTREE_H
#define __MSKLTREE_H

typedef class cMSkillTree cMSkillTree;
typedef class cMSkillTreeNode cMSkillTreeNode;

// XXX can add different node type if want bigger key

typedef ulong tMSkillKey;
typedef struct sMSkillKeyDesc sMSkillKeyDesc;

struct sMSkillKeyDesc
{
   int nValues;
   uchar *pValues;
};

class cMSkillTree
{
public:

   cMSkillTree(const int bitsPerLevel, const int maxDepth); // XXX Assert if > sizeof(long)
   cMSkillTree(const cMSkillTree& atree); // copy constructor
   ~cMSkillTree();

   tMSkillKey BuildKey(const sMSkillKeyDesc& keyDesc);
   void InsertData(const void *dataPtr, const tMSkillKey key);
   void *GetData(const tMSkillKey key);

   int GetWildValue() const { return m_MaxEntriesPerLevel; } // the value to pass in to
                                                    // keydesc when
                                                    // any value is fine.

private:

   const int m_BitShift;
   const int m_MaxEntriesPerLevel;
   const int m_MaxDepth;
   cMSkillTreeNode *m_pHead;

};

#endif
