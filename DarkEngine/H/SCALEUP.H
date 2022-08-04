// $Header: x:/prj/tech/libsrc/scaleup/RCS/scaleup.h 1.2 1998/07/07 16:19:51 JAEMZ Exp $

#ifndef __SCALEUP_H
#define __SCALEUP_H
#pragma once

// Rescales src onto dst.
// Scale is scale of dst/src
// Takes matrix floats
EXTERN void ScaleUp(float *dmat,int dw,int dh,float *smat,int sw,int sh,int srow,float scale);

#endif  // Scaleup
