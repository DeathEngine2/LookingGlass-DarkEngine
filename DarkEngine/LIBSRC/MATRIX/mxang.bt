// $Header: x:/prj/tech/libsrc/matrix/RCS/mxang.h 1.1 1997/08/11 18:41:13 dc Exp $
// angle/angvec stuff for mx
// since it is single/double precision invariant

#ifndef __MXANG_H
#define __MXANG_H

typedef ushort mxs_ang;

typedef struct _mxs_angvec {
   union {
      struct {mxs_ang tx,ty,tz;};
      mxs_ang el[3];
   };
} mxs_angvec;

#define MX_ANG_PI 0x8000
#define MX_REAL_PI 3.141592653589
#define MX_REAL_2PI (2.0*3.141592653589)

#endif  // __MXANG_H
