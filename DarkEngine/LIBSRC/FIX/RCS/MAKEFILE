head	 2.4;
branch   ;
access   ;
symbols  SHIPPED_F95:2.1 oldnmk:1.18.1 FLT_SHIP:1.18.1.1;
locks    ; strict;
comment  @# @;


2.4
date	 1997.04.24.13.58.58;  author TOML;  state Exp;
branches ;
next	 2.3;

2.3
date	 1996.10.03.09.42.36;  author KEVIN;  state Exp;
branches ;
next	 2.2;

2.2
date	 1996.04.08.16.51.34;  author TOML;  state Exp;
branches ;
next	 2.1;

2.1
date	 1995.10.02.19.55.19;  author ept;  state Exp;
branches ;
next	 1.18;

1.18
date	 1994.08.30.15.52.20;  author dfan;  state Exp;
branches 1.18.1.1;
next	 1.17;

1.17
date	 1994.08.11.12.14.50;  author dfan;  state Exp;
branches ;
next	 1.16;

1.16
date	 1994.08.11.12.11.23;  author dfan;  state Exp;
branches ;
next	 1.15;

1.15
date	 1994.06.18.03.50.39;  author lmfeeney;  state Exp;
branches ;
next	 1.14;

1.14
date	 1994.02.16.17.33.37;  author dfan;  state Exp;
branches ;
next	 1.13;

1.13
date	 1994.02.02.12.50.14;  author kaboom;  state Exp;
branches ;
next	 1.12;

1.12
date	 1993.11.30.13.02.29;  author dfan;  state Exp;
branches ;
next	 1.11;

1.11
date	 1993.11.11.13.51.41;  author rex;  state Exp;
branches ;
next	 1.10;

1.10
date	 1993.11.04.11.06.32;  author rex;  state Exp;
branches ;
next	 1.9;

1.9
date	 1993.06.01.14.13.44;  author dfan;  state Exp;
branches ;
next	 1.8;

1.8
date	 1993.03.22.17.11.46;  author matt;  state Exp;
branches ;
next	 1.7;

1.7
date	 1993.02.15.11.41.14;  author dfan;  state Exp;
branches ;
next	 1.6;

1.6
date	 1993.01.27.17.57.34;  author kaboom;  state Exp;
branches ;
next	 1.5;

1.5
date	 1992.10.15.20.31.17;  author kaboom;  state Exp;
branches ;
next	 1.4;

1.4
date	 1992.09.16.20.05.40;  author kaboom;  state Exp;
branches ;
next	 1.3;

1.3
date	 1992.08.25.08.47.39;  author kaboom;  state Exp;
branches ;
next	 1.2;

1.2
date	 1992.08.24.17.27.40;  author kaboom;  state Exp;
branches ;
next	 1.1;

1.1
date	 1992.08.24.15.34.44;  author kaboom;  state Exp;
branches ;
next	 ;

1.18.1.1
date	 1994.12.10.10.18.35;  author lmfeeney;  state Exp;
branches ;
next	 1.18.1.2;

1.18.1.2
date	 1995.06.26.16.38.05;  author kevin;  state Exp;
branches ;
next	 ;


desc
@Makefile for fixed-point math library.
@


2.4
log
@moved existing "safe" functions to own module, added spiffy new ones
@
text
@# $Source: x:/prj/tech/libsrc/fix/rcs/makefile $
# $Revision: 2.3 $
# $Author: KEVIN $
# $Date: 1996/10/03 09:42:36 $

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = fix

# need to deal with making trigtab.c  with fmaketab !!

fix_OBJS = fix fix_pow fixsprnt fix_asm atofix fix24 f_exp trigtab \
        fixdiv safefix

irrupt_OBJS = fix

fix_HDRS = fix.h altfix.h fix.inc safefix.h

%include $(MRC)\make.rc
@


2.3
log
@Added fixdiv module which contains fix_mul_div_safe and fix_div_safe.
@
text
@a0 2


d2 3
a4 3
# $Revision: 2.2 $
# $Author: TOML $
# $Date: 1996/04/08 16:51:34 $
d19 1
a19 1
        fixdiv
d23 1
a23 1
fix_HDRS = fix.h altfix.h fix.inc
@


2.2
log
@*** empty log message ***
@
text
@d3 4
a6 4
# $Source: x:/prj/tech/libsrc/fix/RCS/makefile $
# $Revision: 2.1 $
# $Author: ept $
# $Date: 1995/10/02 19:55:19 $
d20 2
a21 1
fix_OBJS = fix fix_pow fixsprnt fix_asm atofix fix24 f_exp trigtab 
@


2.1
log
@This is the new branch to get rid of the nmk branch.
@
text
@d3 4
a6 4
# $Source: t:/prj/tech/libsrc/fix/rcs/makefile $
# $Revision: 1.18.1.2 $
# $Author: kevin $
# $Date: 1995/06/26 16:38:05 $
d10 1
a10 1
PROJECT = windex
@


1.18
log
@trigtab.cc should have been trigtab.c
@
text
@a0 6
#
# $Source: r:/prj/lib/src/fix/rcs/makefile $
# $Revision: 1.17 $
# $Author: dfan $
# $Date: 1994/08/11 12:14:50 $
#
a1 8
COMPILER = watcom
SRCDIR = r:\prj\lib\src\fix
RELDIR = r:\prj\lib\rel
OBJDIR = obj
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = $(RELDIR)
d3 4
a6 1
DEBUG_ON = yeah
d8 1
a8 4
PROG_TARGETS = fixtest fix24tst fmaketab trigerr #sqrttest
LIB_TARGETS = fix
HDR_TARGETS = fix
INST_TARGETS = fix
d10 1
a10 4
FIX.C_CFLAGS= -zu -s
FIX_HDRS = fix.h fix.inc
FIX_OBJS = fix.obj fix_pow.obj fixsprnt.obj fix_asm.obj atofix.obj \
           fix24.obj f_exp.obj trigtab.obj
d12 1
a12 1
FIXTEST_OBJS = $(FIX_OBJS) fixtest.obj
d14 1
a14 1
FIX24TST_OBJS = $(FIX_OBJS) fix24tst.obj
d16 1
a16 1
FMAKETAB_OBJS = fmaketab.obj
d18 1
a18 1
# SQRTTEST_OBJS = $(FIX_OBJS) sqrttest.obj
d20 1
a20 1
TRIGERR_OBJS = $(FIX_OBJS) trigerr.obj
d22 1
a22 1
!include $(INIT)/make.rc
d24 1
a24 2
trigtab.c: fmaketab.exe
	fmaketab > trigtab.c
d26 1
a26 30
fix.obj: fix.h trigtab.h

fixtest.obj: fix.h

fix24tst.obj: fix.h

### OPUS MKMF:  Do not remove this line!  Generated dependencies follow.

atofix.obj: fix.h stdio.h stdlib.h types.h

fix.obj: fix.h stdio.h stdlib.h trigtab.h types.h

fix24tst.obj: ctype.h fix.h stdio.h stdlib.h string.h types.h

fix_11.obj: fix.h stdio.h stdlib.h types.h

fix_old.obj: fix.h stdio.h stdlib.h types.h

fixsprnt.obj: fix.h stdio.h stdlib.h types.h

fixtest.obj: ctype.h fix.h stdio.h stdlib.h string.h types.h

floattst.obj: fix.h stdio.h types.h

fmaketab.obj: generic.h iomanip.h iostream.h math.h stddef.h stdlib.h \
	 streambu.h string.h

sqrttest.obj: fix.h stdio.h stdlib.h types.h

trigerr.obj: ctype.h fix.h math.h stdio.h stdlib.h string.h types.h
@


1.18.1.1
log
@new make regime
@
text
@d1 6
d8 8
d17 1
a17 4
# $Source: $
# $Revision: $
# $Author: $
# $Date: $
d19 4
a22 1
MAKETOP = $(CWD)
d24 4
a27 1
PROJECT = windex
d29 1
a29 1
%include $(MRC)\env.rc
d31 1
a31 1
%include $(MRC)\init.rc
d33 1
a33 1
LIBTARGS = fix
d35 1
a35 1
# need to deal with making trigtab.c  with fmaketab !!
d37 1
a37 1
fix_OBJS = fix fix_pow fixsprnt fix_asm atofix fix24 f_exp trigtab 
d39 1
a39 1
irrupt_OBJS = fix
d41 2
a42 1
fix_HDRS = fix.h fix.inc
d44 30
a73 1
%include $(MRC)\make.rc
@


1.18.1.2
log
@added altfix.h to fix_HDRS.
@
text
@d3 4
a6 4
# $Source: r:/prj/lib/src/fix/rcs/makefile $
# $Revision: 1.18.1.1 $
# $Author: lmfeeney $
# $Date: 1994/12/10 10:18:35 $
d24 1
a24 1
fix_HDRS = fix.h altfix.h fix.inc
@


1.17
log
@oops
@
text
@d2 2
a3 2
# $Source: r:/prj/lib/src/fix/RCS/makefile $
# $Revision: 1.16 $
d5 1
a5 1
# $Date: 1994/08/11 12:11:23 $
d41 2
a42 2
trigtab.cc: fmaketab.exe
	fmaketab > trigtab.cc
@


1.16
log
@multiple source directories
trigtab.h has to become trigtab.cc
@
text
@d2 4
a5 4
# $Source: r:/prj/lib/src/fix/rcs/makefile $
# $Revision: 1.15 $
# $Author: lmfeeney $
# $Date: 1994/06/18 03:50:39 $
d41 1
a41 1
trigtab.h: fmaketab.exe
@


1.15
log
@added fix_pow
@
text
@d2 4
a5 4
# $Source: n:/project/lib/src/fix/rcs/makefile $
# $Revision: 1.14 $
# $Author: dfan $
# $Date: 1994/02/16 17:33:37 $
d9 2
a10 2
SRCDIR = n:\project\lib\src\fix
RELDIR = n:\project\lib\release
d26 2
a27 1
FIX_OBJS = fix.obj fix_pow.obj fixsprnt.obj fix_asm.obj atofix.obj
d42 1
a42 1
	fmaketab > trigtab.h
@


1.14
log
@What the hell is fixovtst
@
text
@d3 3
a5 3
# $Revision: 1.13 $
# $Author: kaboom $
# $Date: 1994/02/02 12:50:14 $
d26 1
a26 1
FIX_OBJS = fix.obj fixsprnt.obj fix_asm.obj atofix.obj
@


1.13
log
@Added interrupt/ready flags to fix.c.
@
text
@d3 3
a5 3
# $Revision: 1.12 $
# $Author: dfan $
# $Date: 1993/11/30 13:02:29 $
d19 1
a19 1
PROG_TARGETS = fixtest fix24tst fmaketab trigerr fixovtst #sqrttest
a30 3

FIXOVTST_OBJS = $(FIX_OBJS) fixovtst.obj
FIXOVTST_LIBS = _lg.lib _mprintf.lib
@


1.12
log
@fixovtst
@
text
@d3 3
a5 3
# $Revision: 1.11 $
# $Author: rex $
# $Date: 1993/11/11 13:51:41 $
d24 1
@


1.11
log
@Added atofix.obj to fix.lib
@
text
@d2 2
a3 2
# $Source: n:/project/lib/src/fix/RCS/makefile $
# $Revision: 1.10 $
d5 1
a5 1
# $Date: 1993/11/04 11:06:32 $
d8 1
a8 1
COMPILER = watcom95
d19 1
a19 1
PROG_TARGETS = fixtest fix24tst fmaketab trigerr #sqrttest
d31 3
d50 1
@


1.10
log
@Added fixsprnt.obj
@
text
@d3 3
a5 3
# $Revision: 1.9 $
# $Author: dfan $
# $Date: 1993/06/01 14:13:44 $
d25 1
a25 1
FIX_OBJS = fix.obj fixsprnt.obj fix_asm.obj
d48 2
@


1.9
log
@fmaketab to make trigtab.h, which fix.c includes
@
text
@d3 3
a5 3
# $Revision: 1.8 $
# $Author: matt $
# $Date: 1993/03/22 17:11:46 $
d25 1
a25 1
FIX_OBJS = fix.obj fix_asm.obj
d47 22
@


1.8
log
@Added fix.inc to headers list
@
text
@d3 3
a5 3
# $Revision: 1.7 $
# $Author: dfan $
# $Date: 1993/02/15 11:41:14 $
d8 1
a8 1
COMPILER = watcom
d19 1
a19 1
PROG_TARGETS = fixtest fix24tst #sqrttest
d31 2
d35 2
d39 4
a42 1
fix.obj: fix.h
@


1.7
log
@fix24 stuff
@
text
@d3 3
a5 3
# $Revision: 1.6 $
# $Author: kaboom $
# $Date: 1993/01/27 17:57:34 $
d24 1
a24 1
FIX_HDRS = fix.h
@


1.6
log
@New files for square root and testing.
@
text
@d3 1
a3 1
# $Revision: 1.5 $
d5 1
a5 1
# $Date: 1992/10/15 20:31:17 $
d19 1
a19 1
PROG_TARGETS = fixtest sqrttest
a25 1
FIX_CFLAGS = -d2
d27 1
a27 2
FIXTEST_OBJS = fix.obj fix_asm.obj fixtest.obj
FIXTEST_CFLAGS = -d2
d29 1
a29 2
SQRTTEST_OBJS = fix.obj fix_asm.obj sqrttest.obj
SQRTTEST_CFLAGS = -d2
d31 2
d35 5
a39 1
fix.c:	fix.h
@


1.5
log
@Fixed RCS header stuff to have source instead of rcsfile.
@
text
@d2 2
a3 2
# $Source$
# $Revision$
d5 1
a5 1
# $Date: 1992/09/16 20:05:40 $
a6 19
# Makefile for Watcom C/Micosoft ASM
#
# $Log: makefile $
# Revision 1.4  1992/09/16  20:05:40  kaboom
# Removed fix.lib from targets.  Added a new target type, HDR_TARGET which
# is just a set of header files.  Made the fix point library consist of just
# the fix.h file.
# 
# Revision 1.3  1992/08/25  08:47:39  kaboom
# Added INST_TARGETS macro, a list of which targets should be installed when
# a make install is done.  Executables are copied to $(BIN), libraries are
# copied to $(LIB) and library headers are copied to $(INC).
# 
# Revision 1.2  1992/08/24  17:27:40  kaboom
# Added RCS keywords and header at top of file.
# 
# Revision 1.1  1992/08/20  12:00:00  kaboom
# Initial revision.
#
d8 1
d10 6
a15 4
VPATH =
VPATH.c = $(SRCDIR)
VPATH.h = $(SRCDIR)
VPATH.asm = $(SRCDIR)
d17 1
a17 2
OBJDIR = .\obj
INCDIR = .\
d19 2
a20 2
PROG_TARGETS =
LIB_TARGETS =
d25 2
d28 2
a29 4
WATCOM = p:\w90
BIN = n:\bin
LIB = n:\lib
INC = n:\inc
d31 2
a32 14
CC = wcc386p
CDEBUG = -d2
COPT = -ox
CFLAGS = -3r -w4 -zq -i=$(INCDIR) -i=$(SRCDIR)\inc -fo=$@@ $(CCDEBUG) $(CCOPT)
LD = wlinkp
LDEBUG = debug all
LDFLAGS = system dos4g option caseexact option map option quiet $(LDDEBUG)
AS = ml
ASFLAGS = /nologo /c /Cp /Zd /Fo$@@
AR = wlib
ARFLAGS = -q -n
CP = copy
RM = rm -f
MAKEDEPEND = mkmf
d34 1
a34 4
TARGEXE = $(PROG_TARGETS,>.exe)
TARGLNK = $(PROG_TARGETS,>.lnk)
TARGLIB = $(LIB_TARGETS,>.lib)
TARGAR  = $(LIB_TARGETS,>.ar)
d36 1
a36 84
# clear suffixes so make won't try to make .exe's from .obj's
.SUFFIXES:

.SUFFIXES: .obj .c .asm

# punt -c option for obj->c rule
.c.obj:
	$(CC) $(CFLAGS) $<

.asm.obj:
	$(AS) $(ASFLAGS) $<

#.obj.exe:

all .PHONY: $(PROG_TARGETS) $(LIB_TARGETS) $(HDR_TARGETS)

$(PROG_TARGETS) .PHONY: $*.exe

$(LIB_TARGETS) .PHONY: $*.lib $($*_HDRS)

$(HDR_TARGETS) .PHONY: $($*_HDRS)

$(TARGLNK): makefile
        %do makelnk TARGET=$*

$(TARGEXE): $*.lnk $($*_OBJS,<$(OBJDIR)\) $($*_LIBS)
        %do runlnk TARGET=$*

$(TARGAR): makefile
        %do makear TARGET=$*

$(TARGLIB): $*.ar $($*_OBJS,<$(OBJDIR)\)
        %do runar TARGET=$*

debug .PHONY:
        @@%set CCDEBUG=$(CDEBUG)
        @@%set LDDEBUG=$(LDEBUG)

optimize .PHONY:
        @@%set CCOPT=$(COPT)

depend .PHONY:
        $(MAKEDEPEND) *.c

install .PHONY: $(INST_TARGETS)
        !foreach TARGET $(INST_TARGETS)
          !if '$(PROG_TARGETS,M$(TARGET))'
            $(CP) $(TARGET).exe $(BIN)
          !elseif '$(LIB_TARGETS,M$(TARGET))'
            $(CP) $(TARGET).lib $(LIB)
            !foreach FILE $($(TARGET)_HDRS)
              $(CP) $(SRCDIR)\$(INCDIR)\$(FILE) $(INC)
            !end
          !elseif '$(HDR_TARGETS,M$(TARGET))'
            !foreach FILE $($(TARGET)_HDRS)
              $(CP) $(SRCDIR)\$(INCDIR)\$(FILE) $(INC)
            !end
          !endif
        !end

uninstall .PHONY:
        $(RM) $(TARGEXE,<$(BIN)\)

clean .PHONY:
        $(RM) *.exe *.lib $(OBJDIR)\*.obj *.map *.err

makelnk .PHONY:
        @@echo $(LDFLAGS) >$@@
        !foreach FILE $($(TARGET)_OBJS,<$(OBJDIR)\)
          @@echo file $(FILE) >>$@@
        !end
        !foreach FILE $($(TARGET)_LIBS)
          @@echo library $(FILE) >>$@@
        !end
        @@echo name $(TARGET).exe >>$@@

runlnk .PHONY:
        $(LD) @@$(TARGET).lnk

makear: .PHONY:
        @@echo $(TARGET).lib $($(TARGET)_OBJS,<$(OBJDIR)\) >$@@

runar: .PHONY:
        $(AR) $(ARFLAGS) @@$(TARGET).ar
@


1.4
log
@Removed fix.lib from targets.  Added a new target type, HDR_TARGET which
is just a set of header files.  Made the fix point library consist of just
the fix.h file.
@
text
@d2 2
a3 1
# $RCSFile$
d5 1
a5 1
# $Date: 1992/08/25 08:47:39 $
d10 5
d23 3
@


1.3
log
@Added INST_TARGETS macro, a list of which targets should be installed when
a make install is done.  Executables are copied to $(BIN), libraries are
copied to $(LIB) and library headers are copied to $(INC).
@
text
@d1 1
d4 1
a4 1
# $Date: 1992/08/24 17:27:40 $
d9 5
d28 2
a29 1
LIB_TARGETS = fix
a31 1
FIX_OBJS = fix.obj
d73 1
a73 1
all .PHONY: $(PROG_TARGETS) $(LIB_TARGETS)
d77 1
a77 1
$(LIB_TARGETS) .PHONY: $*.lib
d79 2
d107 1
a107 1
          !else if '$(LIB_TARGETS,M$(TARGET))'
d109 4
@


1.2
log
@Added RCS keywords and header at top of file.
@
text
@d2 2
a3 2
# $Author$
# $Date$
d7 4
a10 1
# $Log$
d12 1
a12 1
SRC_DIR = n:\project\lib\src\fix
d14 3
a16 3
VPATH.c = $(SRC_DIR)
VPATH.h = $(SRC_DIR)
VPATH.asm = $(SRC_DIR)
d23 1
d25 2
a26 2
FIX_OBJS = \
        fix.obj
d30 2
d36 1
a36 1
CFLAGS = -3r -w4 -zq -i=$(INCDIR) -i=$(SRC_DIR)\inc -fo=$@@ $(CCDEBUG) $(CCOPT)
d95 10
a104 3
install .PHONY:
        !foreach FILE $(TARGEXE)
          $(CP) $(FILE) $(BIN)
@


1.1
log
@Initial revision
@
text
@d1 8
@
