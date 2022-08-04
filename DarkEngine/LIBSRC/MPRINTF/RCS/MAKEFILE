head	 2.4;
branch   ;
access   ;
symbols  SHIPPED_F95:2.3 oldnmk:1.4.1 FLT_SHIP:1.4.1.1;
locks    ; strict;
comment  @# @;


2.4
date	 1996.04.08.16.53.55;  author TOML;  state Exp;
branches ;
next	 2.3;

2.3
date	 1996.02.14.14.35.02;  author JACOBSON;  state Exp;
branches ;
next	 2.2;

2.2
date	 1996.02.14.14.33.29;  author JACOBSON;  state Exp;
branches ;
next	 2.1;

2.1
date	 1995.10.02.20.07.19;  author JON;  state Exp;
branches ;
next	 1.4;

1.4
date	 1994.08.10.20.19.05;  author kaboom;  state Exp;
branches 1.4.1.1;
next	 1.3;

1.3
date	 1993.01.27.16.10.47;  author dc;  state Exp;
branches ;
next	 1.2;

1.2
date	 1992.12.14.18.39.11;  author kaboom;  state Exp;
branches ;
next	 1.1;

1.1
date	 1992.11.25.14.57.22;  author kaboom;  state Exp;
branches ;
next	 ;

1.4.1.1
date	 1994.12.10.10.26.34;  author lmfeeney;  state Exp;
branches ;
next	 ;


desc
@
@


2.4
log
@*** empty log message ***
@
text
@#
# $Source: x:/prj/tech/libsrc/mprintf/RCS/makefile $
# $Revision: 2.3 $
# $Author: JACOBSON $
# $Date: 1996/02/14 14:35:02 $
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = mprintf

mprintf_OBJS = mprintf
mprintf_HDRS = mprintf.h

%include $(MRC)\make.rc

@


2.3
log
@*** empty log message ***
@
text
@d2 2
a3 2
# $Source: x:/prj/windex/libsrc/mprintf/rcs/makefile $
# $Revision: 2.2 $
d5 1
a5 1
# $Date: 1996/02/14 14:33:29 $
d10 1
a10 1
PROJECT = windex
@


2.2
log
@Fixed the makefile to look in windex.
@
text
@d3 3
a5 3
# $Revision: 2.1 $
# $Author: JON $
# $Date: 1995/10/02 20:07:19 $
@


2.1
log
@Branch for new makefile replacing nmk.
@
text
@d2 4
a5 4
# $Source: r:/prj/lib/src/mprintf/rcs/makefile $
# $Revision: 1.4.1.1 $
# $Author: lmfeeney $
# $Date: 1994/12/10 10:26:34 $
d10 1
a10 1
PROJECT = tech
@


1.4
log
@fixed directory.
@
text
@d3 3
a5 3
# $Revision$
# $Author: dc $
# $Date: 1993/01/27 16:10:47 $
d8 1
a8 5
COMPILER = watcom
SRCDIR = r:\prj\lib\src\mprintf
RELDIR = r:\prj\lib\rel
BUILD_DIR = r:\prj\lib\build\mprintf
DEBUG_ON = 1
d10 1
a10 10
OBJDIR = objd
BINDIR =
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = . $(RELDIR)
PROG_TARGETS = mtest
LIB_TARGETS = mprintf
HDR_TARGETS =
INST_TARGETS = mprintf
d12 1
a12 2
MPRINTF_OBJS = mprintf.obj
MPRINTF_HDRS = mprintf.h
d14 1
a14 2
MTEST_OBJS = mtest.obj
MTEST_LIBS = mprintf.lib lg.lib
d16 1
a16 1
%include $(INIT)\make.rc
d18 2
a19 1
### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.
d21 1
a21 2
mprintf.obj: conio.h dos.h fcntl.h i86.h io.h mprintf.h stat.h stdarg.h \
	 stdio.h string.h types.h
a22 2
mtest.obj: ctype.h fcntl.h io.h mprintf.h stat.h stdarg.h stdio.h stdlib.h \
	 string.h time.h types.h
@


1.4.1.1
log
@new make regime
@
text
@d3 3
a5 3
# $Revision: 1.4 $
# $Author: kaboom $
# $Date: 1994/08/10 20:19:05 $
d8 5
a12 1
MAKETOP = $(CWD)
d14 10
a23 1
PROJECT = tech
d25 2
a26 1
%include $(MRC)\env.rc
d28 2
a29 1
%include $(MRC)\init.rc
d31 1
a31 1
LIBTARGS = mprintf
d33 1
a33 2
mprintf_OBJS = mprintf
mprintf_HDRS = mprintf.h
d35 2
a36 1
%include $(MRC)\make.rc
d38 2
@


1.3
log
@with mtest
@
text
@d2 4
a5 3
# $Source: n:/project/lib/src/mprintf/rcs/makefile $
# $Author: kaboom $
# $Date: 1992/12/14 18:39:11 $
d9 4
a12 2
SRCDIR = n:\project\lib\src\mprintf
RELDIR = n:\project\lib\release
d14 1
a14 1
OBJDIR = obj
a25 1

d29 1
a29 1
MTEST_LIBS = mprintf.lib
d31 1
a31 7
#MTEST_CFLAGS    = -d2
#MTEST_LDFLAGS   = debug all

#MPRINTF_CFLAGS  = -d2
#MPRINTF_LDFLAGS = debug all

!include $(INIT)/make.rc
@


1.2
log
@Added MPRINTF_HDRS macro.
@
text
@d4 1
a4 1
# $Date: 1992/11/25 14:57:22 $
d10 1
d13 1
a13 1
LIBDIR = n:\project\lib\release
d16 2
a17 2
LIBPATH = $(RELDIR)
PROG_TARGETS =
d26 2
a27 1
!include n:/etc/make.rc
d29 8
d39 5
a43 2
mprintf.obj: conio.h dos.h fcntl.h i86.h io.h stat.h stdarg.h stdio.h \
	 string.h types.h
@


1.1
log
@Initial revision
@
text
@d2 3
a4 4
# $Source$
# $Revision$
# $Author$
# $Date$
a5 3
# Makefile for Watcom C/Micosoft ASM targets.
#
# $Log$
d21 3
a23 2
MPRINTF_OBJS = \
  mprintf.obj
@
