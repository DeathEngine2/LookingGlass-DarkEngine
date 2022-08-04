head	 2.5;
branch   ;
access   ;
symbols  SHIPPED_F95:2.2 oldnmk:1.2.1 FLT_SHIP:1.2.1.1;
locks    lmfeeney:1.2.1.1; strict;
comment  @# @;


2.5
date	 1996.10.21.16.53.11;  author TOML;  state Exp;
branches ;
next	 2.4;

2.4
date	 1996.10.16.16.08.03;  author TOML;  state Exp;
branches ;
next	 2.3;

2.3
date	 1996.04.08.16.55.22;  author TOML;  state Exp;
branches ;
next	 2.2;

2.2
date	 1996.01.30.11.45.22;  author JACOBSON;  state Exp;
branches ;
next	 2.1;

2.1
date	 1995.10.02.19.57.21;  author MBAER;  state Exp;
branches ;
next	 1.2;

1.2
date	 1994.10.17.17.47.52;  author lmfeeney;  state Exp;
branches 1.2.1.1;
next	 1.1;

1.1
date	 1993.05.20.16.17.41;  author kaboom;  state Exp;
branches ;
next	 ;

1.2.1.1
date	 1994.12.10.10.43.37;  author lmfeeney;  state Exp;
branches ;
next	 ;


desc
@Makefile for timer library.
@


2.5
log
@*** empty log message ***
@
text
@#
# $Source: x:/prj/tech/libsrc/timer/rcs/makefile $
# $Revision: 2.4 $
# $Author: TOML $
# $Date: 1996/10/16 16:08:03 $
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = timer

irrupt_OBJS = tmrt

tmact.asm       tmd.asm         tminit.asm      tmrem.asm       tmsfreq.asm
tmadd.asm       tmdeact.asm     tmphnd.asm      tmsden.asm      tmsper.asm
tmclose.asm     tmfast.asm      tmrate.asm

timer_OBJS = tmrt \
             tmftab tmlibt tmail \
             tmwin32

timer_dos4g_OBJS = \
    tmact tmd tmadd tmclose tmdeact tmfast tminit tmphnd \
    tmrate tmrem tmsden tmsfreq tmsper

timer_HDRS = timer.h tminit.h

timer.h: tmdecl.h tmftab.h tmmac.h tmd.inc tmflag.inc tmlow.inc tmreg.inc
	%do comp_h h_pre="\#include \<fix.h\>" h_in="$(^,M\.h)" inc_in="$(^,M\.inc)" h_out="$@@"

%include $(MRC)\make.rc
@


2.4
log
@msvc port, part 2
@
text
@d3 1
a3 1
# $Revision: 2.3 $
d5 1
a5 1
# $Date: 1996/04/08 16:55:22 $
d24 1
a24 3
timer_OBJS = \
             \
             tmrt \
d28 3
a30 5
#
# Removed, will need to reintegrate for DOS (toml 10-14-96)
#
# tmact tmd tmadd tmclose tmdeact tmfast tminit tmphnd
# tmrate tmrem tmsden tmsfreq tmsper
@


2.3
log
@*** empty log message ***
@
text
@d2 4
a5 4
# $Source: x:/prj/tech/libsrc/timer/RCS/makefile $
# $Revision: 2.2 $
# $Author: JACOBSON $
# $Date: 1996/01/30 11:45:22 $
d20 8
a27 4
timer_OBJS = tmact tmadd tmclose tmd \
             tmdeact tmfast tminit tmphnd \
             tmrate tmrem tmsden tmrt \
             tmsfreq tmsper tmftab tmlibt tmail \
d29 6
@


2.2
log
@dded windoze stuff.
@
text
@d2 4
a5 4
# $Source: t:/prj/tech/libsrc/timer/rcs/makefile $
# $Revision: 2.1 $
# $Author: MBAER $
# $Date: 1995/10/02 19:57:21 $
d10 1
a10 1
PROJECT = windex
@


2.1
log
@Getting rid of old nmk

@
text
@d2 4
a5 4
# $Source: r:/prj/lib/src/timer/rcs/makefile $
# $Revision: 1.2.1.1 $
# $Author: lmfeeney $
# $Date: 1994/12/10 10:43:37 $
d23 2
a24 1
             tmsfreq tmsper tmftab tmlibt tmail
@


1.2
log
@totally revised
@
text
@d3 3
a5 3
# $Revision: 1.1 $
# $Author: kaboom $
# $Date: 1993/05/20 16:17:41 $
d8 1
a8 1
DEBUG_ON = 1
d10 1
a10 11
COMPILER = watcom
SRCDIR = r:\prj\lib\src\timer
RELDIR = r:\prj\lib\rel
OBJDIR = obj
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
INCPATH = . $(SRCDIR) $(INCDIR)
LIBPATH = $(RELDIR)
LIB_TARGETS = timer 
PROG_TARGETS =
INST_TARGETS = TIMER 
d12 1
a12 1
TMRT.C_CFLAGS = -zu -s 
d14 1
a14 4
timer_OBJS = tmact.obj tmadd.obj tmclose.obj tmd.obj \
             tmdeact.obj tmfast.obj tminit.obj tmphnd.obj \
             tmrate.obj tmrem.obj tmsden.obj tmrt.obj \
             tmsfreq.obj tmsper.obj tmftab.obj tmlibt.obj tmail.obj
d16 1
a16 1
TIMER_HDRS = timer.h tminit.h
d18 1
a18 1
!include $(INIT)\make.rc
d20 4
a23 13
timer.h:  tmdecl.h tmftab.h tmmac.h tmd.inc tmflag.inc tmlow.inc tmreg.inc
        rm -f junk
        @@echo cat $^ \>junk
        !foreach FILE $(^,M\.h)
          @@cat $(FILE) >>junk
        !end
        !foreach FILE $(^,M\.inc)
          @@inc2h $(FILE) junk
        !end
        @@echo \#ifndef __TIMER_H >$(@@,F)
        @@echo \#define __TIMER_H >>$(@@,F)
        sed '/\/\/.*$$/d' junk >>$(@@,F)
        @@echo \#endif /* !__TIMER_H */>>$(@@,F)
d25 1
a25 1
### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.
d27 2
a28 1
tmact.obj objo\tmact.obj objd\tmact.obj: tmd.inc tmflag.inc tmlow.inc tmrec.inc
d30 1
a30 30
tmadd.obj objo\tmadd.obj objd\tmadd.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc

tmail.obj objo\tmail.obj objd\tmail.obj: ail32.h tmftab.h

tmclose.obj objo\tmclose.obj objd\tmclose.obj: dpmi.inc tmd.inc tmhnd.inc tmreg.inc type.inc

tmd.obj objo\tmd.obj objd\tmd.obj: tmd.inc tmlow.inc

tmdeact.obj objo\tmdeact.obj objd\tmdeact.obj: tmd.inc tmflag.inc tmlow.inc tmrec.inc

tmfast.obj objo\tmfast.obj objd\tmfast.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc

tmftab.obj objo\tmftab.obj objd\tmftab.obj: tmdecl.h tmftab.h

tminit.obj objo\tminit.obj objd\tminit.obj: dpmi.inc tmd.inc tmdecl.inc tmflag.inc tmftab.inc tmhnd.inc \
	 tmlow.inc tmrec.inc tmreg.inc type.inc

tmphnd.obj objo\tmphnd.obj objd\tmphnd.obj: pic.inc tmd.inc tmflag.inc tmlow.inc tmrec.inc type.inc

tmrate.obj objo\tmrate.obj objd\tmrate.obj: tmd.inc tmlow.inc tmreg.inc

tmrem.obj objo\tmrem.obj objd\tmrem.obj: tmd.inc tmflag.inc tmlow.inc

tmsden.obj objo\tmsden.obj objd\tmsden.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc

tmsfreq.obj objo\tmsfreq.obj objd\tmsfreq.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc tmreg.inc

tmsper.obj objo\tmsper.obj objd\tmsper.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc tmreg.inc

tmtick.obj objo\tmtick.obj objd\tmtick.obj: tmlow.inc
@


1.2.1.1
log
@new make regime
@
text
@d2 1
a2 1
# $Source: n:/project/lib/src/timer/RCS/makefile $
d8 1
a8 1
MAKETOP = $(CWD)
d10 11
a20 1
PROJECT = windex
d22 1
a22 1
%include $(MRC)\env.rc
d24 4
a27 1
%include $(MRC)\init.rc
d29 1
a29 1
LIBTARGS = timer
d31 1
a31 1
irrupt_OBJS = tmrt
d33 13
a45 4
timer_OBJS = tmact tmadd tmclose tmd \
             tmdeact tmfast tminit tmphnd \
             tmrate tmrem tmsden tmrt \
             tmsfreq tmsper tmftab tmlibt tmail
d47 1
a47 1
timer_HDRS = timer.h tminit.h
d49 1
a49 2
timer.h: tmdecl.h tmftab.h tmmac.h tmd.inc tmflag.inc tmlow.inc tmreg.inc
	%do comp_h h_pre="\#include \<fix.h\>" h_in="$(^,M\.h)" inc_in="$(^,M\.inc)" h_out="$@@"
d51 30
a80 1
%include $(MRC)\make.rc
@


1.1
log
@Initial revision
@
text
@d2 1
a2 1
# $Source: n:/project/lib/src/timer/rcs/makefile $
d5 1
a5 1
# $Date: 1993/05/20 15:52:50 $
d11 2
a12 2
SRCDIR = n:\project\lib\src\timer
RELDIR = n:\project\lib\release
d18 1
a18 1
LIB_TARGETS = timer
d20 1
a20 1
INST_TARGETS = timer
d22 3
a24 1
TIMER_OBJS = tmact.obj tmadd.obj tmclose.obj tmd.obj \
d26 2
a27 3
             tmrate.obj tmrem.obj tmsden.obj \
             tmsfreq.obj tmsper.obj tmtick.obj
TIMER_HDRS = timer.h
d29 2
d33 1
a33 1
timer.h: tmdecl.h tmd.inc tmflag.inc tmlow.inc tmreg.inc
d49 1
a49 1
tmact.obj: tmd.inc tmflag.inc tmlow.inc tmrec.inc
d51 1
a51 1
tmadd.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc
d53 1
a53 1
tmclose.obj: dpmi.inc tmd.inc tmreg.inc type.inc
d55 1
a55 1
tmd.obj: tmd.inc tmlow.inc
d57 1
a57 1
tmdeact.obj: tmd.inc tmflag.inc tmlow.inc tmrec.inc
d59 1
a59 1
tmfast.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc
d61 1
a61 2
tminit.obj: dpmi.inc tmd.inc tmdecl.inc tmflag.inc tmhnd.inc tmlow.inc \
	 tmrec.inc tmreg.inc type.inc
d63 1
a63 1
tmphnd.obj: pic.inc tmd.inc tmflag.inc tmlow.inc tmrec.inc type.inc
d65 2
a66 1
tmrate.obj: tmd.inc tmlow.inc tmreg.inc
d68 1
a68 1
tmrem.obj: tmd.inc tmflag.inc tmlow.inc
d70 1
a70 1
tmsden.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc
d72 1
a72 1
tmsfreq.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc tmreg.inc
d74 1
a74 1
tmsper.obj: tmd.inc tmdecl.inc tmflag.inc tmlow.inc tmrec.inc tmreg.inc
d76 5
a80 1
tmtick.obj: tmlow.inc
@
