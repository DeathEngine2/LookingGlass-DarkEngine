/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/motion/RCS/motdb.h 1.5 1999/06/06 17:02:58 dc Exp $

#ifndef __MOTDB_H
#define __MOTDB_H

#include <tagfile.h>
#include <motschem.h>
#include <namemap.h>
#include <dynarray.h>
#include <fcytagdb.h>
#include <tagdbout.h>
#include <motdbtyp.h>
#include <tagremap.h>

#ifdef __cplusplus

typedef enum eMotDBMatchType
{
   kMMT_AbsoluteBest,
   kMMT_WeightedDither,
} eMotDBMatchType;

class cMotionDatabase
{
public:
   cMotionDatabase();
   virtual ~cMotionDatabase();

   // database query
   virtual BOOL GetBestMatch(int actor, cTagDBInput *pInput, cMotionSchema **ppSchema,eMotDBMatchType matchType=kMMT_AbsoluteBest);
   virtual BOOL GetTagKeyID(const Label *pName, int *pID);

   // get schema by index
   virtual BOOL GetSchema(int index, cMotionSchema **ppSchema);

   void Clear();

   // save/load
   virtual BOOL Load(ITagFile *pFile);
#ifdef EDITOR
   virtual BOOL BuildFromAscii();
   virtual BOOL Save(ITagFile *pFile);
#endif

   // build utilities
   virtual void CreateTagDatabase(int nActors);
   virtual void RegisterTag(const Label *pName, const sTagInfo *pInfo);
   virtual void AddSchema(const sMotSchemaDesc *pSchema);

   // retokenization--these are passed into cTagDBDatabases
   void TokenGlobalToLocal(cTagDBKey *pKey);
   void TokenLocalToGlobal(cTagDBKey *pKey);

private:
   cNameMap m_NameMap;
   cNameMap m_TagNameMap;
   cTagRemapper m_Remap;
   cMotionSchemaSet m_SchemaSet;
   int m_nActors;
   IFancyTagDatabase *m_pDatabase;
   cTagDBOutput m_RawResult;
};

inline BOOL cMotionDatabase::GetTagKeyID(const Label *pName, int *pID)
{
   int index=m_TagNameMap.IDFromName(pName);

   if(index==kNameMapIndexNotFound)
      return FALSE;
   *pID=index;
   return TRUE;
}

#endif // cplusplus

#endif // motdb.h
