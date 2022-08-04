/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/labtab/RCS/labtab.h 1.1 1999/04/27 18:14:48 JAEMZ Exp $

// Label table
// Allows you to give it a label (16 characters with 0 ending max)
// and get back a pointer.
// This way you don't waste tons of RAM duplicating this stuff.
// Labels are case sensitive, so don't mess up
//

#ifndef __LABTAB_H
#define __LABTAB_H
#pragma once

#include <dynarray.h>
#include <label.h>

class cLabelTable {
public:
   // Adds label if doesn't exist yet, and passes back
   // pointer to it.
   Label* Add(const Label &rLabel);

   // Just does a lookup, returning NULL if can't find it
   Label *Lookup(const Label &rLabel);
private:
   cDynArray<Label> m_labelList;
};

#endif
