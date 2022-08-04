/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/skillset.h 1.2 1997/12/15 15:54:53 kate Exp $
// interface to get information about an object's skill abilities

#ifndef __SKILLSET_H
#define __SKILLSET_H

#include <objtype.h>
#include <skilltyp.h>

BOOL SkillSetGetForObj(const ObjID objID, int *nSkills, tSkillID **ppSkills);



#endif
