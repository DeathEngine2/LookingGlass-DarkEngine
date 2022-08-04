head	 2.14;
branch   ;
access   ;
symbols  SHIPPED_F95:2.5 oldnmk:1.17.1 FLT_SHIP:1.17.1.2;
locks    ; strict;
comment  @# @;


2.14
date	 1998.01.06.18.34.10;  author JAEMZ;  state Exp;
branches ;
next	 2.13;

2.13
date	 1997.10.06.20.47.12;  author JON;  state Exp;
branches ;
next	 2.12;

2.12
date	 1996.11.05.14.28.54;  author TOML;  state Exp;
branches ;
next	 2.11;

2.11
date	 1996.10.14.19.23.35;  author mahk;  state Exp;
branches ;
next	 2.10;

2.10
date	 1996.09.24.11.47.21;  author TOML;  state Exp;
branches ;
next	 2.9;

2.9
date	 1996.09.13.17.31.03;  author BODISAFA;  state Exp;
branches ;
next	 2.8;

2.8
date	 1996.08.14.21.32.25;  author dc;  state Exp;
branches ;
next	 2.7;

2.7
date	 1996.05.18.13.16.39;  author TOML;  state Exp;
branches ;
next	 2.6;

2.6
date	 1996.04.08.16.52.52;  author TOML;  state Exp;
branches ;
next	 2.5;

2.5
date	 1996.02.15.15.08.42;  author JACOBSON;  state Exp;
branches ;
next	 2.4;

2.4
date	 1996.02.07.12.21.35;  author TOML;  state Exp;
branches ;
next	 2.3;

2.3
date	 1996.02.02.10.08.59;  author TOML;  state Exp;
branches ;
next	 2.2;

2.2
date	 1996.01.19.10.10.16;  author JACOBSON;  state Exp;
branches ;
next	 2.1;

2.1
date	 1995.10.02.20.05.11;  author ept;  state Exp;
branches ;
next	 1.17;

1.17
date	 1994.11.07.20.44.24;  author dc;  state Exp;
branches 1.17.1.1;
next	 1.16;

1.16
date	 1994.10.11.13.02.35;  author jaemz;  state Exp;
branches ;
next	 1.15;

1.15
date	 1994.08.15.16.50.27;  author kaboom;  state Exp;
branches ;
next	 1.14;

1.14
date	 1994.08.14.17.57.52;  author mahk;  state Exp;
branches ;
next	 1.13;

1.13
date	 1994.06.21.05.34.20;  author mahk;  state Exp;
branches ;
next	 1.12;

1.12
date	 1994.06.21.05.29.17;  author mahk;  state Exp;
branches ;
next	 1.11;

1.11
date	 1994.02.12.18.36.20;  author kaboom;  state Exp;
branches ;
next	 1.10;

1.10
date	 1994.01.20.13.39.36;  author jak;  state Exp;
branches ;
next	 1.9;

1.9
date	 1993.12.01.07.35.09;  author kaboom;  state Exp;
branches ;
next	 1.8;

1.8
date	 1993.11.19.03.02.01;  author kaboom;  state Exp;
branches ;
next	 1.7;

1.7
date	 1993.05.17.11.40.43;  author kaboom;  state Exp;
branches ;
next	 1.6;

1.6
date	 1993.05.05.15.47.52;  author kaboom;  state Exp;
branches ;
next	 1.5;

1.5
date	 1993.05.04.14.34.29;  author mahk;  state Exp;
branches ;
next	 1.4;

1.4
date	 1993.04.28.17.01.59;  author mahk;  state Exp;
branches ;
next	 1.3;

1.3
date	 1993.04.16.22.52.58;  author mahk;  state Exp;
branches ;
next	 1.2;

1.2
date	 1993.03.29.15.58.44;  author matt;  state Exp;
branches ;
next	 1.1;

1.1
date	 1993.03.29.15.54.24;  author matt;  state Exp;
branches ;
next	 ;

1.17.1.1
date	 1994.12.10.10.23.28;  author lmfeeney;  state Exp;
branches ;
next	 1.17.1.2;

1.17.1.2
date	 1995.05.01.17.22.06;  author jak;  state Exp;
branches ;
next	 1.17.1.3;

1.17.1.3
date	 1995.06.05.14.18.16;  author JAK;  state Exp;
branches ;
next	 ;


desc
@Makefile for joystick library
@


2.14
log
@Added kbcntry.c and .h
@
text
@#
# $Source: x:/prj/tech/winsrc/input/rcs/makefile $
# $Revision: 2.13 $
# $Author: JON $
# $Date: 1997/10/06 20:47:12 $
#

MAKETOP = $(CWD)

PROJECT = tech

COMP ?= W105
SYS ?= WIN32

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = input
#EXETARGS = test

#test_OBJS = test
test_LIBS = input

#input_dos4g_OBJS = \
# 	basjoy biosjoy fanjoy joyflat joystick kbarray kbasctab kbcntry \
#       kbbflush kbcstat kbflush kbgen kbgflag kbglob kbgstat kbint \
#       kblnext kblow kbnext kbphnd kbqueue kbrhnd kbsflag kbshut leds \
#       kbssig kbsstat kbstart kbstate mousesys mousedev ngpjoy kbcook
#       hatcal

#input_win32_OBJS = \
# 	joystick kbstart kbshut kbasctab mousesys mousedev \
#        kbsys kbdev kbcook defehand joywin

input_OBJS = \
	     joystick kbstart kbshut kbasctab kbcntry mousesys \
        kbsys kbdev kbcook kbwin defehand joywin hatcal fanjoy \
        recinput inpinit inpcompo inpdynf inperr \
		joyold inpman inpguid

input_LIBS = compapis recorder mprintf

# kbcntry?

#       kbarray kbasctab kbcntry kbbflush kbcook \
#	kbcstat kbflush kbgen kbgflag kbglob kbgstat kbint kblnext kblow \
#	kbnext kbphnd kbqueue kbrhnd kbsflag kbshut kbssig kbsstat \
#	kbstart kbstate leds mouse mousedev

input_HDRS = joystick.h kb.h kbcook.h kbcntry.h keydefs.h mouse.h mousevel.h inpinit.h joystick.h \
        joyapi.h inpapi.h inpbase.h inpface.h

# fix this, want right h2i args

# h2i_files = kbflag kbarray

# OK, it's busted and I'm getting headers from R:
# kbflag.inc : kbflag.h
# 	h2inc /Ni $^ $@@

# kbarray.inc : kbarray.h
#	h2inc /Ni $^ $@@

# kb.h : kbs.h kbdecl.h kbscan.h kbcntry.h kbarray.inc kbd.inc kberr.h
#	kbflag.inc kblow.inc kbstate.inc
#	%do comp_h h_pre="" h_in="$(^,M\.h)" inc_in="$(^,M\.inc)" h_out="$@@"

# kb.h: kbs.h kbdecl.h kbscan.h kbcntry.h kbarray.inc kbd.inc kberr.inc kbflag.inc \
#         kblow.inc kbstate.inc

kb.h: kbs.h kbdecl.h kbscan.h kbmod.h kbarray.h kbstate.h
        rm -f junk
        @@echo cat $^ \>junk
        !foreach FILE $(^,M\.h)
          @@cstrip $(FILE) >>junk
        !end
        !foreach FILE $(^,M\.inc)
          @@inc2h $(FILE) junk
        !end
        @@echo \#ifndef __KB_H >$(@@,F)
        @@echo \#define __KB_H >>$(@@,F)
        sed '/\/\/.*$$/d' junk >>$(@@,F)
        @@echo \#endif /* !__KB_H */>>$(@@,F)

%include $(MRC)\make.rc












@


2.13
log
@New input manager.
@
text
@d3 3
a5 3
# $Revision: 2.12 $
# $Author: TOML $
# $Date: 1996/11/05 14:28:54 $
d37 1
a37 1
	     joystick kbstart kbshut kbasctab mousesys \
d51 1
a51 1
input_HDRS = joystick.h kb.h kbcook.h keydefs.h mouse.h mousevel.h inpinit.h joystick.h \
@


2.12
log
@interim clean-up
@
text
@d3 3
a5 3
# $Revision: 2.11 $
# $Author: mahk $
# $Date: 1996/10/14 19:23:35 $
d39 2
a40 1
        recinput inpinit inpguid inpcompo
d51 2
a52 1
input_HDRS = joystick.h kb.h kbcook.h keydefs.h mouse.h mousevel.h inpinit.h
d87 8
@


2.11
log
@added agg member stuff
@
text
@d2 4
a5 4
# $Source: x:/prj/tech/libsrc/input/rcs/makefile $
# $Revision: 2.10 $
# $Author: TOML $
# $Date: 1996/09/24 11:47:21 $
d39 1
a39 1
        recinput inpinit inpguid
@


2.10
log
@*** empty log message ***
@
text
@d2 4
a5 4
# $Source: x:/prj/tech/libsrc/input/RCS/makefile $
# $Revision: 2.9 $
# $Author: BODISAFA $
# $Date: 1996/09/13 17:31:03 $
d37 1
a37 1
 	joystick kbstart kbshut kbasctab mousesys \
d39 1
a39 1
        recinput
d50 1
a50 1
input_HDRS = joystick.h kb.h kbcook.h keydefs.h mouse.h mousevel.h
@


2.9
log
@Recording support
@
text
@d2 4
a5 4
# $Source: x:/prj/tech/libsrc/input/rcs/makefile $
# $Revision: 2.8 $
# $Author: dc $
# $Date: 1996/08/14 21:32:25 $
d20 1
a20 1
EXETARGS = test
d22 1
a22 1
test_OBJS = test
@


2.8
log
@add comp?= and sys?= for windows
@
text
@d3 3
a5 3
# $Revision: 2.7 $
# $Author: TOML $
# $Date: 1996/05/18 13:16:39 $
d38 4
a41 1
        kbsys kbdev kbcook kbwin defehand joywin hatcal fanjoy
@


2.7
log
@Converted to latest COM framework
@
text
@d3 1
a3 1
# $Revision: 2.6 $
d5 1
a5 1
# $Date: 1996/04/08 16:52:52 $
d11 3
@


2.6
log
@*** empty log message ***
@
text
@d2 4
a5 4
# $Source: x:/prj/tech/libsrc/input/RCS/makefile $
# $Revision: 2.5 $
# $Author: JACOBSON $
# $Date: 1996/02/15 15:08:42 $
d44 1
a44 1
input_HDRS = joystick.h kb.h kbcook.h keydefs.h mouse.h mousevel.h defehand.h
@


2.5
log
@Removed mousedev.
@
text
@d2 4
a5 4
# $Source: x:/prj/windex/libsrc/input/rcs/makefile $
# $Revision: 2.4 $
# $Author: TOML $
# $Date: 1996/02/07 12:21:35 $
d10 1
a10 1
PROJECT = windex
@


2.4
log
@Initial windows support
@
text
@d3 1
a3 1
# $Revision: 2.3 $
d5 1
a5 1
# $Date: 1996/02/02 10:08:59 $
d34 1
a34 1
 	joystick kbstart kbshut kbasctab mousesys mousedev \
@


2.3
log
@*** empty log message ***
@
text
@d3 3
a5 3
# $Revision: 2.2 $
# $Author: JACOBSON $
# $Date: 1996/01/19 10:10:16 $
d31 1
a31 1
#        kbsys kbdev kbcook
d35 1
a35 1
        kbsys kbdev kbcook kbwin defehand
@


2.2
log
@Argh.
@
text
@d2 4
a5 4
# $Source: r:/prj/lib/src/input/rcs/makefile $
# $Revision: 1.17.1.1 $
# $Author: lmfeeney $
# $Date: 1994/12/10 10:23:28 $
d35 1
a35 1
        kbsys kbdev kbcook kbwin
d44 1
a44 1
input_HDRS = joystick.h kb.h kbcook.h keydefs.h mouse.h mousevel.h
d57 1
a57 1
# kb.h : kbs.h kbdecl.h kbscan.h kbcntry.h kbarray.inc kbd.inc kberr.h 
d64 1
a64 1
kb.h: kbs.h kbdecl.h kbscan.h kbmod.h kbarray.h kbstate.h 
d77 1
a77 1
 
@


2.1
log
@This is a new branch so that we can get rid of the nmk branch.
@
text
@d3 3
a5 3
# $Revision: 1.17.1.3 $
# $Author: JAK $
# $Date: 1995/06/05 14:18:16 $
d17 1
d19 14
d34 2
a35 4
	basjoy biosjoy fanjoy joyflat joystick kbarray kbasctab kbcntry kbbflush \
        kbcook kbcstat kbflush kbgen kbgflag kbglob kbgstat kbint kblnext kblow \
	kbnext kbphnd kbqueue kbrhnd kbsflag kbshut kbssig kbsstat \
	kbstart kbstate leds mouse mousedev ngpjoy hatcal
d37 7
d60 17
@


1.17
log
@fancy joystick support
@
text
@d2 4
a5 4
# $Source: r:/prj/lib/src/input/RCS/makefile $
# $Revision: 1.16 $
# $Author: jaemz $
# $Date: 1994/10/11 13:02:35 $
d8 1
a8 5
%if defined(NONET)
ROOTDRIVE=$(NONET):
%else
ROOTDRIVE=r:
%endif
d10 1
a10 1
DEBUG_ON= 1
d12 1
a12 4
COMPILER= watcom
SRCDIR= $(ROOTDRIVE)\prj\lib\src\input
RELDIR= $(ROOTDRIVE)\prj\lib\rel
BUILD_DIR= $(ROOTDRIVE)\prj\lib\build\input
d14 1
a14 8
OBJDIR= objo
BINDIR=
LIBDIR= $(RELDIR)
INCDIR= $(RELDIR)
INCPATH= . ..\dpmi $(SRCDIR) $(RELDIR)
LIBPATH= . $(RELDIR)
LIB_TARGETS= input
INST_TARGETS= input
d16 1
a16 20
INPUT_OBJS= \
        kbarray.obj \
        kbbflush.obj kbcstat.obj \
        kbflush.obj \
        kblow.obj kbgen.obj \
        kbgflag.obj kbglob.obj kbgstat.obj \
        kbint.obj \
        kblnext.obj \
        kbnext.obj \
        kbqueue.obj \
        kbphnd.obj kbrhnd.obj \
        kbsflag.obj kbshut.obj \
        kbssig.obj kbsstat.obj \
        kbstart.obj \
        kbstate.obj kbcook.obj kbasctab.obj \
        kbcntry.obj \
        leds.obj \
        joyflat.obj joystick.obj ngpjoy.obj basjoy.obj fanjoy.obj \
        mouse.obj  mousedev.obj
INPUT_HDRS= mouse.h kb.h kbcook.h joystick.h mousevel.h
d18 5
a22 1
!include $(INIT)/make.rc
d24 1
a24 14
kb.h: kbs.h kbdecl.h kbscan.h kbcntry.h kbarray.inc kbd.inc kberr.inc kbflag.inc \
        kblow.inc kbstate.inc
        rm -f junk
        @@echo cat $^ \>junk
        !foreach FILE $(^,M\.h)
          @@cstrip $(FILE) >>junk
        !end
        !foreach FILE $(^,M\.inc)
          @@inc2h $(FILE) junk
        !end
        @@echo \#ifndef __KB_H >$(@@,F)
        @@echo \#define __KB_H >>$(@@,F)
        sed '/\/\/.*$$/d' junk >>$(@@,F)
        @@echo \#endif /* !__KB_H */>>$(@@,F)
d26 1
a26 1
### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.
d28 1
a28 1
basjoy.obj objo\basjoy.obj objd\basjoy.obj: _input.h basjoy.h dbg.h dbgmacro.h stdio.h types.h
d30 3
a32 1
joystick.obj objo\joystick.obj objd\joystick.obj: basjoy.h joystick.h ngpjoy.h
d34 2
a35 1
kbasctab.obj objo\kbasctab.obj objd\kbasctab.obj: ctype.h error.h kb.h kbcook.h
d37 5
a41 1
kbbflush.obj objo\kbbflush.obj objd\kbbflush.obj: type.inc
a42 2
kbcook.obj objo\kbcook.obj objd\kbcook.obj: ctype.h dbg.h dbgmacro.h error.h kb.h kbcook.h kbmod.h kbscan.h \
	 lg.h lgalt.h malloc.h memall.h memmacro.h stdio.h types.h
a43 1
kbcstat.obj objo\kbcstat.obj objd\kbcstat.obj: kbd.inc kblow.inc type.inc
a44 1
kbflush.obj objo\kbflush.obj objd\kbflush.obj: kbd.inc kblow.inc type.inc
a45 39
kbgen.obj objo\kbgen.obj objd\kbgen.obj: kbreg.inc

kbgflag.obj objo\kbgflag.obj objd\kbgflag.obj: kbd.inc kblow.inc type.inc

kbgstat.obj objo\kbgstat.obj objd\kbgstat.obj: kbd.inc kblow.inc type.inc

kblnext.obj objo\kblnext.obj objd\kblnext.obj: kbd.inc kbflag.inc kblow.inc type.inc

kblow.obj objo\kblow.obj objd\kblow.obj: dpmi.h i86.h

kbnext.obj objo\kbnext.obj objd\kbnext.obj: kbd.inc kbflag.inc kblow.inc type.inc

kbphnd.obj objo\kbphnd.obj objd\kbphnd.obj: fault.inc kbarray.inc kbd.inc kbflag.inc kblow.inc kbreg.inc \
	 kbscan.inc macros.inc type.inc types.inc

kbqueue.obj objo\kbqueue.obj objd\kbqueue.obj: kbs.h

kbrhnd.obj objo\kbrhnd.obj objd\kbrhnd.obj: kbarray.inc kbflag.inc kblow.inc kbreg.inc kbscan.inc type.inc

kbsflag.obj objo\kbsflag.obj objd\kbsflag.obj: kbd.inc kblow.inc

kbshut.obj objo\kbshut.obj objd\kbshut.obj: dpmi.h i86.h kbint.h kblow.h

kbssig.obj objo\kbssig.obj objd\kbssig.obj: kbarray.h

kbsstat.obj objo\kbsstat.obj objd\kbsstat.obj: kbd.inc kblow.inc type.inc

kbstart.obj objo\kbstart.obj objd\kbstart.obj: dpmi.h i86.h kbarray.h kbglob.h kbint.h kblow.h kbqueue.h \
	 kbs.h string.h

kbstate.obj objo\kbstate.obj objd\kbstate.obj: kbarray.inc kbd.inc kblow.inc type.inc

leds.obj objo\leds.obj objd\leds.obj: conio.h kbmod.h

mouse.obj objo\mouse.obj objd\mouse.obj: _mouse.h dbg.h dbgmacro.h dos.h dpmi.h error.h i86.h lg.h \
	 lgalt.h malloc.h memall.h memmacro.h mouse.h mousevel.h stdio.h \
	 stdlib.h types.h

ngpjoy.obj objo\ngpjoy.obj objd\ngpjoy.obj: _input.h dbg.h dbgmacro.h dos.h i86.h ngpjoy.h stdio.h types.h
@


1.17.1.1
log
@new make regime
,
@
text
@d2 1
a2 1
# $Source: r:/prj/lib/src/input/rcs/makefile $
d8 5
a12 1
MAKETOP = $(CWD)
d14 1
a14 1
PROJECT = windex
d16 4
a19 1
%include $(MRC)\env.rc
d21 8
a28 1
%include $(MRC)\init.rc
d30 20
a49 1
LIBTARGS = input
d51 1
a51 5
input_OBJS = \
	basjoy  fanjoy joyflat joystick kbarray kbasctab kbcntry kbbflush kbcook \
	kbcstat kbflush kbgen kbgflag kbglob kbgstat kbint kblnext kblow \
	kbnext kbphnd kbqueue kbrhnd kbsflag kbshut kbssig kbsstat \
	kbstart kbstate leds mouse mousedev ngpjoy  
d53 14
a66 1
input_HDRS = joystick.h kb.h kbcook.h keydefs.h mouse.h mousevel.h
d68 1
a68 1
# fix this, want right h2i args
d70 1
a70 1
# h2i_files = kbflag kbarray
d72 1
a72 3
# OK, it's busted and I'm getting headers from R:
# kbflag.inc : kbflag.h
# 	h2inc /Ni $^ $@@
d74 1
a74 2
# kbarray.inc : kbarray.h
#	h2inc /Ni $^ $@@
d76 1
a76 5
# kb.h : kbs.h kbdecl.h kbscan.h kbcntry.h kbarray.inc kbd.inc kberr.h 
#	kbflag.inc kblow.inc kbstate.inc
#	%do comp_h h_pre="" h_in="$(^,M\.h)" inc_in="$(^,M\.inc)" h_out="$@@"
 
%include $(MRC)\make.rc
d78 2
d81 1
d83 1
d85 39
@


1.17.1.2
log
@added bios reading
@
text
@d3 3
a5 3
# $Revision: 1.17.1.1 $
# $Author: lmfeeney $
# $Date: 1994/12/10 10:23:28 $
d19 2
a20 2
	basjoy biosjoy fanjoy joyflat joystick kbarray kbasctab kbcntry kbbflush \
        kbcook kbcstat kbflush kbgen kbgflag kbglob kbgstat kbint kblnext kblow \
@


1.17.1.3
log
@added hatcal
@
text
@d3 3
a5 3
# $Revision: 1.17.1.2 $
# $Author: jak $
# $Date: 1995/05/01 17:22:06 $
d22 1
a22 1
	kbstart kbstate leds mouse mousedev ngpjoy hatcal
@


1.16
log
@Added foreign keyboard support
@
text
@d2 4
a5 4
# $Source: r:/prj/lib/src/input/rcs/makefile $
# $Revision: 1.15 $
# $Author: kaboom $
# $Date: 1994/08/15 16:50:27 $
d8 6
d17 3
a19 3
SRCDIR= r:\prj\lib\src\input
RELDIR= r:\prj\lib\rel
BUILD_DIR= r:\prj\lib\build\input
d47 1
a47 1
        joyflat.obj joystick.obj ngpjoy.obj basjoy.obj \
@


1.15
log
@Added leds.obj, depend, etc.
@
text
@d3 3
a5 3
# $Revision: 1.13 $
# $Author: mahk $
# $Date: 1994/06/21 05:34:20 $
d39 1
d47 1
a47 1
kb.h: kbs.h kbdecl.h kbscan.h kbarray.inc kbd.inc kberr.inc kbflag.inc \
@


1.14
log
@network  modernization.
@
text
@d11 3
a13 3
SRCDIR= R:\prj\lib\src\input
RELDIR= R:\prj\lib\rel
BUILD_DIR= R:\prj\lib\build\input
d39 1
d46 2
a47 2
kb.h: kbs.h kbdecl.h kbarray.inc kbd.inc kberr.inc kbflag.inc \
        kblow.inc kbscan.inc kbstate.inc
d51 1
a51 1
          @@cat $(FILE) >>junk
d63 1
a63 1
basjoy.obj objo\basjoy.obj objd\basjoy.obj: basjoy.h
d67 1
a67 1
kbasctab.obj objo\kbasctab.obj objd\kbasctab.obj: ctype.h kb.h kbcook.h
d69 1
a69 1
kbclose.obj objo\kbclose.obj objd\kbclose.obj: kbd.inc kberr.inc kbhnd.inc kblow.inc
d71 2
a72 1
kbcook.obj objo\kbcook.obj objd\kbcook.obj: ctype.h kb.h kbcook.h
d74 1
a74 1
kbcstat.obj objo\kbcstat.obj objd\kbcstat.obj: kbd.inc kblow.inc
d76 1
a76 1
kbd.obj objo\kbd.obj objd\kbd.obj: kbd.inc kblow.inc
a77 2
kbflush.obj objo\kbflush.obj objd\kbflush.obj: kbd.inc kblow.inc

d80 1
a80 1
kbgflag.obj objo\kbgflag.obj objd\kbgflag.obj: kbd.inc kblow.inc
d82 1
a82 1
kbgstat.obj objo\kbgstat.obj objd\kbgstat.obj: kbd.inc kblow.inc
d84 1
a84 2
kbinit.obj objo\kbinit.obj objd\kbinit.obj: kbarray.inc kbclose.asm kbd.inc kberr.inc kbflag.inc kbhnd.inc \
	 kbint.inc kblow.inc kbphnd.asm kbreg.inc kbrhnd.asm kbscan.inc
d86 1
a86 1
kblnext.obj objo\kblnext.obj objd\kblnext.obj: kbd.inc kbflag.inc kblow.inc
d88 1
a88 1
kbnext.obj objo\kbnext.obj objd\kbnext.obj: kbd.inc kbflag.inc kblow.inc
d90 2
a91 1
kbphnd.obj objo\kbphnd.obj objd\kbphnd.obj: kbarray.inc kbd.inc kbflag.inc kblow.inc kbreg.inc kbscan.inc
d95 1
a95 1
kbrhnd.obj objo\kbrhnd.obj objd\kbrhnd.obj: kbarray.inc kbflag.inc kblow.inc kbreg.inc kbscan.inc
d99 1
a99 1
kbshut.obj objo\kbshut.obj objd\kbshut.obj: kbint.h kblow.h
d103 1
a103 1
kbsstat.obj objo\kbsstat.obj objd\kbsstat.obj: kbd.inc kblow.inc
d105 2
a106 1
kbstart.obj objo\kbstart.obj objd\kbstart.obj: kbarray.h kbglob.h kbint.h kblow.h kbqueue.h kbs.h string.h
d108 1
a108 1
kbstate.obj objo\kbstate.obj objd\kbstate.obj: kbarray.inc kbd.inc kblow.inc
d110 1
a110 1
mouse.obj objo\mouse.obj objd\mouse.obj: dos.h i86.h mouse.h mousevel.h stdlib.h
d112 3
a114 1
ngpjoy.obj objo\ngpjoy.obj objd\ngpjoy.obj: dos.h i86.h ngpjoy.h
d116 1
a116 1
testcook.obj objo\testcook.obj objd\testcook.obj: ctype.h kb.h kbcook.h
@


1.13
log
@changed N: to r: in reldir
@
text
@d2 2
a3 2
# $Source: n:/project/lib/src/input/rcs/makefile $
# $Revision: 1.12 $
d5 1
a5 1
# $Date: 1994/06/21 05:29:17 $
d11 1
a11 1
SRCDIR= n:\project\lib\src\input
d13 1
a13 1
BUILD_DIR= n:\project\lib\build\input
@


1.12
log
@Added mouse velocity support.
@
text
@d3 3
a5 3
# $Revision: 1.11 $
# $Author: kaboom $
# $Date: 1994/02/12 18:36:20 $
d12 1
a12 1
RELDIR= n:\prj\lib\rel
@


1.11
log
@New files, depend.
@
text
@d3 3
a5 3
# $Revision: 1.10 $
# $Author: jak $
# $Date: 1994/01/20 13:39:36 $
d12 1
a12 1
RELDIR= n:\project\lib\release
d41 1
a41 1
INPUT_HDRS= mouse.h kb.h kbcook.h joystick.h
d62 1
a62 1
basjoy.obj: _input.h basjoy.h dbg.h dbgmacro.h stdio.h types.h
d64 1
a64 1
joystick.obj: basjoy.h joystick.h ngpjoy.h
d66 1
a66 2
kbasctab.obj: ctype.h dbg.h dbgmacro.h error.h kb.h kbcook.h lg.h lgalt.h \
	 malloc.h memall.h memmacro.h stdio.h types.h
d68 1
a68 1
kbbflush.obj: type.inc
d70 1
a70 2
kbclose.obj: dpmi.inc kbd.inc kberr.inc kbhnd.inc kblow.inc macros.inc \
	 type.inc types.inc
d72 1
a72 2
kbcook.obj: ctype.h dbg.h dbgmacro.h error.h kb.h kbcook.h lg.h lgalt.h \
	 malloc.h memall.h memmacro.h stdio.h types.h
d74 1
a74 1
kbcstat.obj: kbd.inc kblow.inc type.inc
d76 1
a76 1
kbd.obj: kbd.inc kblow.inc
d78 1
a78 1
kbflush.obj: kbd.inc kblow.inc type.inc
d80 1
a80 1
kbgen.obj: kbreg.inc
d82 1
a82 1
kbgflag.obj: kbd.inc kblow.inc type.inc
d84 2
a85 1
kbgstat.obj: kbd.inc kblow.inc type.inc
d87 1
a87 3
kbinit.obj: dpmi.inc kbarray.inc kbclose.asm kbd.inc kberr.inc kbflag.inc \
	 kbhnd.inc kbint.inc kblow.inc kbphnd.asm kbreg.inc kbrhnd.asm \
	 kbscan.inc macros.inc type.inc types.inc
d89 1
a89 1
kblnext.obj: kbd.inc kbflag.inc kblow.inc type.inc
d91 1
a91 1
kblow.obj: dpmi.h
d93 1
a93 1
kbnext.obj: kbd.inc kbflag.inc kblow.inc type.inc
d95 1
a95 2
kbphnd.obj: kbarray.inc kbd.inc kbflag.inc kblow.inc kbreg.inc kbscan.inc \
	 macros.inc type.inc types.inc
d97 1
a97 1
kbqueue.obj: kbs.h
d99 1
a99 1
kbrhnd.obj: kbarray.inc kbflag.inc kblow.inc kbreg.inc kbscan.inc type.inc
d101 1
a101 1
kbsflag.obj: kbd.inc kblow.inc
d103 1
a103 1
kbshut.obj: dpmi.h kbint.h kblow.h
d105 1
a105 1
kbssig.obj: kbd.inc kblow.inc type.inc
d107 1
a107 1
kbsstat.obj: kbd.inc kblow.inc type.inc
d109 1
a109 2
kbstart.obj: dpmi.h kbarray.h kbglob.h kbint.h kblow.h kbqueue.h kbs.h \
	 string.h
d111 1
a111 1
kbstate.obj: kbarray.inc kbd.inc kblow.inc type.inc
d113 1
a113 5
mouse.obj: _mouse.h dbg.h dbgmacro.h dos.h dpmi.h error.h i86.h lg.h \
	 lgalt.h malloc.h memall.h memmacro.h mouse.h stdio.h stdlib.h \
	 types.h

ngpjoy.obj: _input.h dbg.h dbgmacro.h dos.h i86.h ngpjoy.h stdio.h types.h
@


1.10
log
@*** empty log message ***
@
text
@d3 3
a5 3
# $Revision: 1.9 $
# $Author: kaboom $
# $Date: 1993/12/01 07:35:09 $
d8 1
a8 1
DEBUG_ON=1
d10 4
a13 4
COMPILER = watcom
SRCDIR = n:\project\lib\src\input
RELDIR = n:\project\lib\release
BUILD_DIR = n:\project\lib\build\input
d15 8
a22 9
OBJDIR = obj
BINDIR =
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = . $(RELDIR)
LIB_TARGETS = input
INST_TARGETS = input
PROG_TARGETS = joytest
d24 2
a25 1
INPUT_OBJS = \
d27 4
a30 3
        kbd.obj kbflush.obj kbgen.obj \
        kbgflag.obj kbgstat.obj \
        kbinit.obj \
d33 5
a37 1
        kbsflag.obj kbssig.obj kbsstat.obj \
d41 1
a41 1
INPUT_HDRS = mouse.h kb.h kbcook.h joystick.h
a42 5
DBG_ON = 1

JOYTEST_OBJS = joytest.obj
JOYTEST_LIBS = _input.lib _lg.lib _mprintf.lib

d45 1
a45 1
kb.h: kbdecl.h kbarray.inc kbd.inc kberr.inc kbflag.inc \
d62 1
a62 2
kbasctab.obj: ctype.h dbg.h error.h kb.h kbcook.h lg.h lgalt.h libdbg.h \
	 malloc.h memall.h stdio.h types.h
d64 5
d71 2
a72 1
kbclose.obj: dpmi.inc kbd.inc kberr.inc kbhnd.inc kblow.inc type.inc
d74 2
a75 2
kbcook.obj: ctype.h dbg.h error.h kb.h kbcook.h lg.h lgalt.h libdbg.h \
	 malloc.h memall.h stdio.h types.h
d89 3
a91 2
kbinit.obj: dpmi.inc kbarray.inc kbd.inc kberr.inc kbhnd.inc kbint.inc \
	 kblow.inc type.inc
d95 2
d100 1
a100 1
	 type.inc
d102 2
d108 2
d114 3
d119 3
a121 2
mouse.obj: dbg.h dos.h error.h i86.h lg.h lgalt.h libdbg.h malloc.h \
	 memall.h mouse.h stdio.h types.h
d123 1
@


1.9
log
@Removed kbclose.obj,kb{r,p}hnd.obj since they're included by kbinit.
@
text
@d3 1
a3 1
# $Revision: 1.8 $
d5 1
a5 1
# $Date: 1993/11/19 03:02:01 $
d23 1
d34 1
a34 1
        joyflat.obj \
d37 5
@


1.8
log
@Removed whitespace in before macro modifier $(^,M\.h).
@
text
@d3 1
a3 1
# $Revision: 1.7 $
d5 1
a5 1
# $Date: 1993/05/17 11:40:43 $
d13 1
a13 1
BUILD_DIR = N:\project\lib\build\input
d24 2
a25 1
INPUT_OBJS = mouse.obj  mousedev.obj kbclose.obj kbcstat.obj \
d30 1
a30 1
        kbnext.obj kbphnd.obj kbrhnd.obj \
d32 3
a34 2
        kbstate.obj kbcook.obj kbasctab.obj  joyflat.obj kbbflush.obj

@


1.7
log
@Changed rule for kb.h to put #ifndef block around body and remove all
the // comments.
@
text
@d3 1
a3 1
# $Revision: 1.6 $
d5 1
a5 1
# $Date: 1993/05/05 15:47:52 $
d41 1
a41 1
        !foreach FILE $(^, M\.h)
d44 1
a44 1
        !foreach FILE $(^, M\.inc)
@


1.6
log
@Took out test program targets; moved to test directory.
@
text
@d2 5
a6 4
# $Source$
# $Revision$
# $Author$
# $Date$
d38 3
a40 2
      kblow.inc kbscan.inc kbstate.inc
        @@rm $(@@,F)
d42 1
a42 1
          @@cat $(FILE) >>$(@@,F)
d45 1
a45 1
          @@inc2h $(FILE) $(@@,F)
d47 4
@


1.5
log
@mouse_init no longer takes a screen mode argument.
@
text
@d1 5
d7 1
a19 1
PROG_TARGETS = 
a20 1
HDR_TARGETS =  
a31 1

a33 8

MORTIMER_OBJS = mousetst.obj
MORTIMER_LIBS = input.lib lg.lib mprintf.lib

JOYTEST_OBJS = joytest.obj
JOYTEST_LIBS = input.lib


a35 1

a45 3



d48 2
a49 2
mouse.obj: dbg.h dos.h error.h fix.h  i86.h lg.h lgalt.h \
	 libdbg.h malloc.h math.h memall.h mouse.h stdarg.h stdio.h types.h
d51 1
a51 2
mousetst.obj: dbg.h error.h fix.h  lg.h lgalt.h libdbg.h \
	 malloc.h math.h memall.h mouse.h stdarg.h stdio.h stdlib.h types.h
a52 1

d55 3
d80 2
d90 2
a91 3

joytest.obj: joystick.h stdio.h stdlib.h types.h

@


1.4
log
@added kbbflush.asm to input.lib
@
text
@d14 1
a14 1
PROG_TARGETS = mortimer joytest
d57 1
a57 1
mouse.obj: 2d.h dbg.h dos.h error.h fix.h grindex.h i86.h lg.h lgalt.h \
d60 1
a60 1
mousetst.obj: 2d.h dbg.h error.h fix.h grindex.h lg.h lgalt.h libdbg.h \
@


1.3
log
@The big honking input library makefile, which contains all the dependencies in the
makefiles of the mouse, kb, and joystick libraries. 
@
text
@d26 1
a26 1
        kbstate.obj kbcook.obj kbasctab.obj  joyflat.obj
@


1.2
log
@Did 'make depend'
@
text
@a0 6
#
# $Source: n:/project/lib/src/joystick/rcs/makefile $
# $Revision: 1.1 $
# $Author: matt $
# $Date: 1993/03/29 15:54:24 $
#
a2 5
DEBUG_ON = 1
DBG_ON = 1
WARN_ON = 1
SPEW_ON = 1

d4 3
a6 3
SRCDIR = n:\project\lib\src\joystick
RELDIR = $(LGLIBDIR)
BUILD_DIR = n:\project\lib\build\joystick
d9 1
d14 4
d19 8
a26 2
INST_TARGETS = joystick
LIB_TARGETS = joystick
a27 2
JOYSTICK_OBJS = joyflat.obj
JOYSTICK_HDRS = joystick.h
d29 1
a29 1
PROG_TARGETS = joytest
d31 4
d36 1
a36 1
JOYTEST_LIBS = joystick.lib
d38 1
d41 14
d57 40
d98 1
@


1.1
log
@Initial revision
@
text
@d2 4
a5 4
# $Source: $
# $Revision: $
# $Author: $
# $Date: $
d40 1
@
