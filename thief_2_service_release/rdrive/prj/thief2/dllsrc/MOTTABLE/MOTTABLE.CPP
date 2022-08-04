/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/t2repos/thief2/dllsrc/mottable/mottable.cpp,v 1.2 1998/03/04 19:12:56 kate Exp $

#include <motdata.h>
#include <mottable.h>
#include <string.h>
#include <comtools.h>

//
// Include this last
//
#include <initguid.h>
#include <imotiid.h>

class cMotionTable : public cCTUnaggregated<IMotionTable,&IID_IMotionTable,kCTU_Default>
{
public:
   cMotionTable();
   virtual ~cMotionTable() {}
   
   // get information about static motion array.  
   // this should only be used for motion loading purposes.
   // and should go away or change once the world is happily dynamic.
   STDMETHOD_(int,NumPossibleMotions)() const;
   STDMETHOD_(char*,GetNameFromHardIndex)(int index) const;
   STDMETHOD_(void,AddMotionFromHardIndex)(int index, int motionNum);

   // get information about a motion given its run-time motion number
   STDMETHOD_(int,GetType)(const int motionNum) const;
   STDMETHOD_(BOOL,NeckIsFixed)(const int motionNum) const;
   STDMETHOD_(char*,GetName)(const int motionNum);
   STDMETHOD_(int,GetBlendType)(const int motionNum) const;
   STDMETHOD_(int,GetNumMotions)() const;

   // get the motion number for a motion based on other information
   STDMETHOD_(int,NameGetNum)(const char *name) const;
   STDMETHOD_(int,TypeGetAllNums)(const int type, int *pMotNums, int *maxMots) const;
   STDMETHOD_(int,TypeGetNumFast)(const int type) const;

};

cMotionTable g_MotionTable;


static int g_NumLoadedMotions = 0;
static MotDesc **g_pMotionData=NULL;

//////////////////////////////////////////////////
//////////////////////////////////////////////////
///
/// MOTION TABLE IMPLEMENTATION
///
//////////////////////////////////////////////////
//////////////////////////////////////////////////


int motDescTypeMap[NUM_MOTDESC_TYPES];  


static void SetupMotion(int motionNum, int type)
{
   if(motDescTypeMap[type]<0)
      motDescTypeMap[type]=motionNum;
//   numMotDescs++; XXX this should incremented here, but isn't because everything
// still hacked and hard-wired
}

cMotionTable::cMotionTable()
{
//   int i;
   const int num=g_NumMotDescs;

   memset(motDescTypeMap,0xff,sizeof(long)*NUM_MOTDESC_TYPES);
#if 0
   for(i=0;i<g_NumMotDescs;i++)
   {
      SetupMotion(i,GetType(i));
   }
#endif
   g_pMotionData= new MotDesc *[num];
}

STDMETHODIMP_(int ) cMotionTable::NumPossibleMotions() const
{
   return g_NumMotDescs;
}

STDMETHODIMP_(char *) cMotionTable::GetNameFromHardIndex(int index) const
{
   return g_aMotDescs[index].name;
}

STDMETHODIMP_(void ) cMotionTable::AddMotionFromHardIndex(int index, int motionNum)
{
   int offset=motionNum;
//   AssertMsg(offset==g_NumLoadedMotions,"motion table out of synch"); // XXX need to add library
   g_NumLoadedMotions++;
   g_aMotDescs[index].motionNum=offset;
   if(g_pMotionData)
      g_pMotionData[offset]=&g_aMotDescs[index];

   int type=g_aMotDescs[index].type;
   if(motDescTypeMap[type]<0)
      motDescTypeMap[type]=motionNum;
   
   // add to name hash table
}

STDMETHODIMP_(int ) cMotionTable::GetType(const int motionNum) const
{
   if(g_pMotionData&&motionNum<g_NumLoadedMotions&&motionNum>=0)
      return g_pMotionData[motionNum]->type;
   else
      return MDT_NONE;
}

STDMETHODIMP_(BOOL ) cMotionTable::NeckIsFixed(const int motionNum) const
{
   if(g_pMotionData&&motionNum<g_NumLoadedMotions&&motionNum>=0)
      return g_pMotionData[motionNum]->neckFixed;
   else
      return FALSE;
}

STDMETHODIMP_(char *) cMotionTable::GetName(const int motionNum)
{
   if(g_pMotionData&&motionNum<g_NumLoadedMotions&&motionNum>=0)
      return g_pMotionData[motionNum]->name;
   else
      return NULL;
}

STDMETHODIMP_(int ) cMotionTable::GetBlendType(const int motionNum) const
{
   if(g_pMotionData&&motionNum<g_NumLoadedMotions&&motionNum>=0)
      return g_pMotionData[motionNum]->blendType;
   else
      return BLEND_NONE;
}

STDMETHODIMP_(int ) cMotionTable::GetNumMotions() const
{
   return g_NumLoadedMotions;
}

// XXX should use a string hash table.
// Though really, should just get rid of this whole mess..
STDMETHODIMP_(int ) cMotionTable::NameGetNum(const char *name) const
{
   int i;
   MotDesc **md=g_pMotionData;

   if(!name)
      return -1;
   for(i=0;i<g_NumLoadedMotions;i++,md++)
   {
      if(!stricmp(name,(*md)->name))
         return i;
   }
   return -1;
}
   
STDMETHODIMP_(int ) cMotionTable::TypeGetAllNums(const int type, int *pMotNums, int *maxMots) const
{
   int i,num_match=0;
   MotDesc **md=g_pMotionData;

   for(i=0;i<g_NumLoadedMotions;i++,md++)
   {
      if((*md)->type==type)
      {
         pMotNums[num_match++]=i;
         if(num_match>=*maxMots)
            break;
      }
   }
   *maxMots=num_match;
   return num_match;
}

STDMETHODIMP_(int ) cMotionTable::TypeGetNumFast(const int type) const
{ 
   return motDescTypeMap[type]; 
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
///
/// EXTERNALLY VISIBLE FUNCTIONS
//////////////////////////////////////////////////
//////////////////////////////////////////////////

DLLEXPORT IMotionTable * LGAPI GetMotionTable()
{
   return &g_MotionTable;
}
