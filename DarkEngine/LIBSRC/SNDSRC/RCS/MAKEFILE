head	 1.2;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.2
date	 1997.09.24.14.22.53;  author PATMAC;  state Exp;
branches ;
next	 1.1;

1.1
date	 1997.06.11.17.52.37;  author PATMAC;  state Exp;
branches ;
next	 ;


desc
@Makefile for sound sources
@


1.2
log
@Add IMA ADPCM convertor
@
text
@MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = sndsrc
EXETARGS = playsrc

sndsrc_OBJS = sndsrc
sndsrc_win32_OBJS = playlist refill sndsrcid sndseg rezseg fileseg memseg imaadpcm


sndsrc_HDRS = sndsrc.h playlist.h sndsrcid.h
#   sndsrci.h sndsrcid.h sndseg.h sndsegi.h
#sndsrc_DEFINES = SND_TEST

playsrc_OBJS = playsrc utilmain
playsrc_LIBS = lg mprintf range res \
                cpptools comtools compapis appcore templgen sound \
                sndutil sndsrc
playsrc_COMPILER_LIBS = uuid winmm

%include $(MRC)\make.rc

@


1.1
log
@Initial revision
@
text
@d13 1
a13 1
sndsrc_win32_OBJS = playlist refill sndsrcid sndseg rezseg fileseg memseg
d16 1
a16 1
sndsrc_HDRS = sndsrc.h playlist.h
@
