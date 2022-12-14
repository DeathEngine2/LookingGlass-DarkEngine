/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkrsprp.h 1.2 1998/09/28 21:58:16 XEMU Exp $

#ifndef _SHKRSPRP_H
#define _SHKRSPRP_H

// Setting text properties
#define PROP_RESEARCHTIME_NAME "RsrchTime"
EXTERN IIntProperty* gPropResearchTime;

#define PROP_RESEARCHTEXT_NAME "RsrchTxt"
EXTERN IStringProperty* gPropResearchText;

#define MAX_CHEM_ITEMS  7
typedef struct sChemInfo
{
   char m_chem[MAX_CHEM_ITEMS][64];
   int m_time[MAX_CHEM_ITEMS];
} sChemInfo;

// ChemInfo description property
F_DECLARE_INTERFACE(IChemInfoProperty);

#undef INTERFACE
#define INTERFACE IChemInfoProperty

DECLARE_PROPERTY_INTERFACE(IChemInfoProperty)
{
   DECLARE_UNKNOWN_PURE();                // IUnknown methods 
   DECLARE_PROPERTY_PURE();               // IProperty methods
   DECLARE_PROPERTY_ACCESSORS(sChemInfo*);  // Type-specific accessors, by reference
};
#define PROP_CHEMNEED_NAME  "ChemNeeded"
EXTERN IChemInfoProperty *gPropChemNeeded;

#endif