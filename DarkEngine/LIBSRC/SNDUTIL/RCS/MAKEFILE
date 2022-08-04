head	 1.7;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.7
date	 1996.12.19.15.59.41;  author PATMAC;  state Exp;
branches ;
next	 1.6;

1.6
date	 1996.10.03.18.37.32;  author PATMAC;  state Exp;
branches ;
next	 1.5;

1.5
date	 1996.09.05.14.00.55;  author PATMAC;  state Exp;
branches ;
next	 1.4;

1.4
date	 1996.09.04.13.28.24;  author PATMAC;  state Exp;
branches ;
next	 1.3;

1.3
date	 1996.09.03.11.45.02;  author PATMAC;  state Exp;
branches ;
next	 1.2;

1.2
date	 1996.08.26.17.08.14;  author PATMAC;  state Exp;
branches ;
next	 1.1;

1.1
date	 1996.08.22.17.31.36;  author PATMAC;  state Exp;
branches ;
next	 ;


desc
@makefile for sound utilities
@


1.7
log
@remove wail32 dependancy from oneshot, stream and splice
@
text
@MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = sndutil
EXETARGS = splice stream oneshot

sndutil_OBJS = streamer rstremer fstremer mstremer splicer rsplicer fsplicer \
					imaadpcm oneshot roneshot foneshot

sndutil_HDRS = sndutil.h
#sndutil_DEFINES = SND_TEST

splice_OBJS = splcmain utilmain
splice_LIBS = lg mprintf range res \
                cpptools comtools compapis appcore templgen sound dsound \
                sndutil
splice_COMPILER_LIBS = uuid winmm

stream_OBJS = strmmain utilmain
stream_LIBS = lg mprintf range res \
                cpptools comtools compapis appcore templgen sound dsound \
                sndutil
stream_COMPILER_LIBS = uuid winmm

oneshot_OBJS = onemain utilmain
oneshot_LIBS = lg mprintf range res \
                cpptools comtools compapis appcore templgen sound dsound \
                sndutil
oneshot_COMPILER_LIBS = uuid winmm



%include $(MRC)\make.rc

@


1.6
log
@Add mstremer / streams from a memory image
,
@
text
@d21 1
a21 1
                wail32 sndutil
d27 1
a27 1
                wail32 sndutil
d33 1
a33 1
                wail32 sndutil
@


1.5
log
@Add one/shot stuff
@
text
@d12 2
a13 2
sndutil_OBJS = streamer rstremer fstremer splicer rsplicer fsplicer imaadpcm \
					oneshot roneshot foneshot
@


1.4
log
@Add sndutil lib to stream.exe
@
text
@d10 1
a10 1
EXETARGS = splice stream
d12 2
a13 1
sndutil_OBJS = streamer rstremer fstremer splicer rsplicer fsplicer imaadpcm
d29 6
@


1.3
log
@Add ADPCM support
@
text
@d19 2
a20 1
                cpptools comtools compapis appcore templgen sound dsound wail32 sndutil
d25 2
a26 1
                cpptools comtools compapis appcore templgen sound dsound wail32
@


1.2
log
@Added stream & splice stand/alone programs
@
text
@d12 1
a12 2
#sndutil_OBJS = streamer splicer timelog
sndutil_OBJS = streamer rstremer splicer rsplicer
d17 1
a17 1
splice_OBJS = splcmain splicer fsplicer utilmain
d19 1
a19 1
                cpptools comtools compapis appcore templgen sound dsound wail32
d22 1
a22 1
stream_OBJS = strmmain streamer fstremer utilmain
@


1.1
log
@Initial revision
@
text
@d10 1
a10 1
EXETARGS = 
d13 1
a13 1
sndutil_OBJS = streamer splicer
d17 12
@
