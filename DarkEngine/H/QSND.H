#ifndef __QSND_H
#define __QSND_H

// sit these flags on top of normal flags
#define QSND_CANT_PAN   0x0100  // cant be played as a mono panned sample!
#define QSND_FIXED_LOC  0x0200  // will not move (or change volume)

#define QSND_NOLINK    -1

snd_handle qsnd_sample_init(uchar *smp,uchar *img,int len,uchar pri,void *data,int flags);

#endif // __QSND_H

