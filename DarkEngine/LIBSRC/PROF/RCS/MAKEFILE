head	 1.8;
branch   ;
access   ;
symbols  ;
locks    TOML:1.8; strict;
comment  @# @;


1.8
date	 1995.10.06.13.38.55;  author buzzard;  state Exp;
branches ;
next	 1.7;

1.7
date	 1995.01.17.13.07.05;  author dfan;  state Exp;
branches ;
next	 1.6;

1.6
date	 1995.01.17.12.54.01;  author buzzard;  state Exp;
branches ;
next	 1.5;

1.5
date	 1995.01.17.11.25.51;  author buzzard;  state Exp;
branches ;
next	 1.4;

1.4
date	 1995.01.17.07.54.12;  author buzzard;  state Exp;
branches ;
next	 1.3;

1.3
date	 1995.01.16.14.20.15;  author buzzard;  state Exp;
branches ;
next	 1.2;

1.2
date	 1995.01.16.14.18.18;  author buzzard;  state Exp;
branches ;
next	 1.1;

1.1
date	 1995.01.16.14.12.08;  author buzzard;  state Exp;
branches ;
next	 ;


desc
@makefile for C self-profiling library
@


1.8
log
@new build system somehow didn't get checked in?
@
text
@# $Header: r:/prj/lib/src/prof/RCS/makefile 1.7 1995/01/17 13:07:05 dfan Exp $
# $Log: makefile $

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = prof

prof_OBJS = prof

prof_HDRS = prof.h

%include $(MRC)\make.rc
@


1.7
log
@Turn off stack checking the right way
OBJDIR was set to objo, causing much unanticipated havoc
@
text
@d1 1
a1 2
#
# $Header: r:/prj/lib/src/prof/rcs/makefile 1.6 1995/01/17 12:54:01 buzzard Exp $
a2 19
# Revision 1.6  1995/01/17  12:54:01  buzzard
# fix stack checking
# 
# Revision 1.5  1995/01/17  11:25:51  buzzard
# no stack checking
# 
# Revision 1.4  1995/01/17  07:54:12  buzzard
# dependencies
# 
# Revision 1.3  1995/01/16  14:20:15  buzzard
# duh
# 
# Revision 1.2  1995/01/16  14:18:18  buzzard
# build dir
# 
# Revision 1.1  1995/01/16  14:12:08  buzzard
# Initial revision
# 
#
d4 1
a4 1
DEV_BASE = r:\prj\lib
d6 1
a6 9
COMPILER = watcom
SRCDIR = $(DEV_BASE)\src\prof
RELDIR = $(DEV_BASE)\rel
OBJDIR = obj
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = $(RELDIR)
BUILD_DIR = $(DEV_BASE)\build\prof
d8 1
a8 3
# normal and stereo version
LIB_TARGETS = prof
INST_TARGETS = prof
d10 1
a10 3
PROF_OBJS = prof.obj
PROF_HDRS = prof.h
PROF_CFLAGS = -s
d12 1
a12 1
!include $(INIT)/make.rc
d14 1
a14 1
### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.
d16 3
a18 2
prof.obj objo\prof.obj objd\prof.obj: fix.h lgsprntf.h prof.h stdarg.h stdio.h stdlib.h string.h \
	 timer.h types.h
@


1.6
log
@fix stack checking
@
text
@d2 1
a2 1
# $Header: r:/prj/lib/src/prof/rcs/makefile 1.5 1995/01/17 11:25:51 buzzard Exp $
d4 3
d29 1
a29 1
OBJDIR = objo
d42 1
a42 1
PROF.C_CFLAGS = -s
@


1.5
log
@no stack checking
@
text
@d2 1
a2 1
# $Header: r:/prj/lib/src/prof/rcs/makefile 1.4 1995/01/17 07:54:12 buzzard Exp $
d4 3
d39 1
a39 1
PROF_CFLAGS = -s
@


1.4
log
@dependencies
@
text
@d2 1
a2 1
# $Header: r:/prj/lib/src/prof/rcs/makefile 1.3 1995/01/16 14:20:15 buzzard Exp $
d4 3
d36 1
@


1.3
log
@duh
@
text
@d2 1
a2 1
# $Header: r:/prj/lib/src/prof/rcs/makefile 1.2 1995/01/16 14:18:18 buzzard Exp $
d4 3
d37 3
@


1.2
log
@build dir
@
text
@d2 1
a2 1
# $Header: r:/prj/lib/src/prof/rcs/makefile 1.1 1995/01/16 14:12:08 buzzard Exp $
d4 3
a27 1
# this is kind of bad, since you lose other dependencies
@


1.1
log
@Initial revision
@
text
@d2 5
a6 2
# $Header$
# $Log$
d9 2
d12 2
a13 2
SRCDIR = r:\prj\lib\src\prof
RELDIR = r:\prj\lib\rel
d19 1
@
