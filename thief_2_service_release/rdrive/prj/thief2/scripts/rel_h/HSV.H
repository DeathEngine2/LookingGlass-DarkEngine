/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: r:/flt3repos/flt3/src/wrend/hsv.h,v $
 * $Revision: 1.1 $
 * $Author: bfarquha $
 * $Date: 1998/08/25 11:34:29 $
 *
 * Hue/Saturation/Value(Brightness) and RGB conversion routines. Assumes 16 bit RGB encoding.
 *
*/

#ifndef __HSV_H
#pragma once
#define __HSV_H

struct sHSI
   {
   float h; // hue (value 0 -> 360)
   float s; // saturation (value 0 -> 1)
   float v; // intensity (value 0 -> 1)
   };

#define RGB2HSV(nRGB, pHSV) \
   { \
   int r,g,b; \
   float fr,fg,fb; \
   float fMax,fMin; \
   gr_split_rgb(nRGB, r, g, b); \
   fr = r/255.0; \
   fg = r/255.0; \
   fb = r/255.0; \
   fMax = __max(__max(fr,fg),fb); \
   fMin = __min(__min(fr,fg),fb); \
   pHSV->v = fMax; \
   if (!r && !g && !b) \
      { \
      pHSV->s = 0; \
      pHDV->h = -1; \
      } \
   else \
      { \
      pHSV->s = (fMax-fMin)/fMax; \
      if (fr == fMax) \
         pHSV->h = (fg-fb)/(fMax-fMin); \
      else if (fg == fMax) \
         pHSV->h = 2 + (fb-fr)/(fMax-fMin); \
      else \
         pHSV->h = 4 + (fr-fg)/(fMax-fMin); \
      pHSV->h *= 60; \
      if (pHSV->h < 0) \
         pHSV->h = pHSV->h + 360; \
      } \
   }


#define HSV2RGB(pHSV, pRGB) \
   { \
   if (pHSV->s == 0) \
      { \
      if (pHSV->v < 0) \
         *pRGB = gr_bind_rgb((pHSV->v*255),(pHSV->v*255),(pHSV->v*255)); \
      else \
         CriticalMsg("Unable to convert HSV to RGB"); \
      } \
   else \
      { \
      float h,f,p,q,t; \
      int i; \
      h = fmod(pHSV->h,360); \
      h /= 60; \
      i = floor(h); \
      f = h-i; \
      p = pHSV->v*(1-pHSV->s); \
      q = pHSV->v*(1-(pHSV->s*f)); \
      t = pHSV->v*(1-(pHSV->s*(1-f))); \
      switch (i) \
         { \
         case 0: \
            *pRGB = gr_bind_rgb((pHSV->v*255),(t*255),(p*255)); \
         break; \
         case 1: \
            *pRGB = gr_bind_rgb((q*255),(pHSV->v*255),(p*255)); \
         break; \
         case 2: \
            *pRGB = gr_bind_rgb((p*255),(pHSV->v*255),(t*255)); \
         break; \
         case 3: \
            *pRGB = gr_bind_rgb((p*255),(q*255),(pHSV->v*255)); \
         break; \
         case 4: \
            *pRGB = gr_bind_rgb((t*255),(p*255),(pHSV->v*255)); \
         break; \
         case 5: \
            *pRGB = gr_bind_rgb((pHSV->v*255),(p*255),(q*255)); \
         break; \
         default: \
            CriticalMsg("Unable to convert HSV to RGB"); \
         } \
      } \
   }

#endif
