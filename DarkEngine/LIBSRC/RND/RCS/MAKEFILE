head	 2.2;
branch   ;
access   ;
symbols  SHIPPED_F95:2.1 oldnmk:1.1.1 FLT_SHIP:1.1.1.1;
locks    ; strict;
comment  @# @;


2.2
date	 1996.04.08.16.54.42;  author TOML;  state Exp;
branches ;
next	 2.1;

2.1
date	 1995.10.02.20.10.30;  author MBAER;  state Exp;
branches ;
next	 1.1;

1.1
date	 1993.04.06.09.56.39;  author rex;  state Exp;
branches 1.1.1.1;
next	 ;

1.1.1.1
date	 1994.12.10.10.38.59;  author lmfeeney;  state Exp;
branches ;
next	 ;


desc
@@


2.2
log
@*** empty log message ***
@
text
@# 
# $Source: x:/prj/tech/libsrc/rnd/RCS/makefile $
# $Revision: 2.1 $
# $Author: MBAER $
# $Date: 1995/10/02 20:10:30 $
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = rnd

rnd_OBJS = rnd
rnd_HDRS = rnd.h

%include $(MRC)\make.rc


@


2.1
log
@Getting rid of old nmk.
@
text
@d2 4
a5 4
# $Source: r:/prj/lib/src/rnd/rcs/makefile $
# $Revision: 1.1.1.1 $
# $Author: lmfeeney $
# $Date: 1994/12/10 10:38:59 $
d10 1
a10 1
PROJECT = windex
@


1.1
log
@Initial revision
@
text
@a0 3
#	----------------------------------
#	Makefile for RND library
#	----------------------------------
d2 5
d8 1
a8 4
DEBUG_ON = 1
DBG_ON = 1
WARN_ON = 1
SPEW_ON = 1
d10 1
a10 9
COMPILER = watcom
SRCDIR = n:\project\lib\src\res
RELDIR = n:\project\lib\release
OBJDIR = obj
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
BINDIR = n:\bin
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = $(RELDIR)
d12 1
a12 4
PROG_TARGETS = rndtest
LIB_TARGETS = rnd
INST_TARGETS = rnd
EXTRA_TARGETS =
d14 1
a14 3
RND_SRCS	= rnd.c
RND_OBJS = rnd.obj
RND_HDRS	= rnd.h
d16 1
a16 3
RNDTEST_SRCS = rndtest.c
RNDTEST_OBJS = rndtest.obj
RNDTEST_LIBS = rnd.lib fix.lib lg.lib mprintf.lib
d18 2
a19 1
!include n:/etc/make.rc
d21 1
a21 3
#	----------------------------------
#	Object file dependencies
#	----------------------------------
a22 1
### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.
a23 5
rnd.obj: dbg.h fix.h lg.h lgalt.h libdbg.h malloc.h math.h memall.h rnd.h \
	 stdio.h types.h

rndtest.obj: conio.h ctype.h fix.h math.h rnd.h stdio.h stdlib.h string.h \
	 types.h
@


1.1.1.1
log
@new make regime
@
text
@d1 3
a4 5
# $Source:$
# $Revision:$
# $Author:$
# $Date:$
#
d6 4
a9 1
MAKETOP = $(CWD)
d11 9
a19 1
PROJECT = windex
d21 4
a24 1
%include $(MRC)\env.rc
d26 3
a28 1
%include $(MRC)\init.rc
d30 3
a32 1
LIBTARGS = rnd
d34 1
a34 2
rnd_OBJS = rnd
rnd_HDRS = rnd.h
d36 3
a38 1
%include $(MRC)\make.rc
d40 1
d42 5
@
