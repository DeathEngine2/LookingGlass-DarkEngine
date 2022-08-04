/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

////////////////////////////////////////////////////////////////////////////////
// $Header: x:/prj/tech/hsrc/RCS/srgba.h 1.3 1999/04/20 17:01:50 JAEMZ Exp $
//
// Color structure with alpha.  Has some standard operators
// as well as interpolation and a way to get the R3 color out of it
// and a 4444 color out of it
//

#pragma once

#ifndef __SRGBA_H
#define __SRGBA_H

#include <types.h>

////////////////////////////////////////

typedef struct sRGBA
{
   uchar a;
   uchar r;
   uchar g;
   uchar b;

   // For C, C++ interoperability
#ifdef __cplusplus

   sRGBA() {};

   sRGBA(uchar _r, uchar _g, uchar _b, uchar _a = 255)
   {
      Set(_r, _g, _b, _a);
   };

   inline sRGBA &operator=(const sRGBA &c)
   {
      r = c.r;
      g = c.g;
      b = c.b;
      a = c.a;
      return *this;
   };

   inline void Set(uchar _r, uchar _g, uchar _b, uchar _a = 255)
   {
      r = _r;
      g = _g;
      b = _b;
      a = _a;
   };

   inline void Interpolate(sRGBA one, sRGBA two, float val)
   {
      r = one.r + ((two.r - one.r) * val);
      g = one.g + ((two.g - one.g) * val);
      b = one.b + ((two.b - one.b) * val);
      a = one.a + ((two.a - one.a) * val);
   };

   // Gets the standard R3 value from it.
   // We probably also want one with alpha someday
   inline int ValueR3() const
   {
      return (((int)r << 16) | ((int)g << 8) | (int)b);
   };

   // Gets the 4444 version of this
   inline ushort Value4444() const
   {
      return (((ushort)(a) >> 4) << 12) |
             (((ushort)(r) >> 4) << 8) |
             (((ushort)(g) >> 4) << 4) |
              ((ushort)(b) >> 4);
   };
#endif

} sRGBA;
// 4

////////////////////////////////////////

#endif
