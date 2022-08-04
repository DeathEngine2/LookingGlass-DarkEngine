head	 2.1;
branch   ;
access   ;
symbols  oldnmk:1.5.1 FLT_SHIP:1.5.1.1;
locks    TOML:2.1; strict;
comment  @# @;


2.1
date	 1995.10.02.20.00.08;  author ept;  state Exp;
branches ;
next	 1.5;

1.5
date	 1994.08.22.17.40.19;  author rex;  state Exp;
branches 1.5.1.1;
next	 1.4;

1.4
date	 1993.10.07.09.44.55;  author rex;  state Exp;
branches ;
next	 1.3;

1.3
date	 1993.09.27.19.22.42;  author rex;  state Exp;
branches ;
next	 1.2;

1.2
date	 1993.09.27.18.01.07;  author rex;  state Exp;
branches ;
next	 1.1;

1.1
date	 1993.09.27.16.38.55;  author rex;  state Exp;
branches ;
next	 ;

1.5.1.1
date	 1995.02.16.11.40.10;  author ept;  state Exp;
branches ;
next	 ;


desc
@@


2.1
log
@This is the new branch of things so that we can get rid of the nmk branch.
@
text
@#	----------------------------------
#	Makefile for GFILE library
#	----------------------------------
#
# $Header: r:/prj/lib/src/gfile/rcs/makefile 1.5.1.1 1995/02/16 11:40:10 ept Exp $

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = gfile 

gfile_OBJS = gfile pcx gif cel bmp

gfile_HDRS = gfile.h

%include $(MRC)\make.rc@


1.5
log
@Moved to r:
@
text
@d5 1
a5 15
# $Header: r:/prj/lib/src/gfile/rcs/makefile 1.4 1993/10/07 09:44:55 rex Exp $
# $Log: makefile $
# Revision 1.4  1993/10/07  09:44:55  rex
# Added bmp.obj
# 
# Revision 1.3  1993/09/27  19:22:42  rex
# Added cel.obj
# 
# Revision 1.2  1993/09/27  18:01:07  rex
# Added gif.obj
# 
# Revision 1.1  1993/09/27  16:38:55  rex
# Initial revision
# 
# 
d7 1
a7 4
DEBUG_ON = 1
DBG_ON = 1
WARN_ON = 1
SPEW_ON = 1
d9 1
a9 9
COMPILER = watcom
SRCDIR = r:\prj\lib\src\gfile
RELDIR = r:\prj\lib\rel
OBJDIR = obj
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
BINDIR =
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = $(RELDIR)
d11 1
a11 2
LIB_TARGETS  = gfile
INST_TARGETS = gfile
d13 1
a13 2
GFILE_OBJS = gfile.obj pcx.obj gif.obj cel.obj bmp.obj
GFILE_HDRS = gfile.h
d15 1
a15 1
BUILD_DIR	= r:\prj\lib\build\gfile
d17 1
a17 1
!include n:/etc/make.rc
d19 1
a19 3
#	----------------------------------
#	Object file dependencies
#	----------------------------------
d21 1
a21 21
### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.

bmp.obj: 2d.h datapath.h dbg.h dbgmacro.h fix.h gfile.h lg.h lgalt.h \
	 malloc.h memall.h memmacro.h rect.h stdio.h stdlib.h string.h \
	 types.h

cel.obj: 2d.h datapath.h dbg.h dbgmacro.h fix.h gfile.h lg.h lgalt.h \
	 limits.h malloc.h memall.h memmacro.h pjfli.h pjstypes.h rect.h \
	 stddef.h stdio.h stdlib.h string.h types.h

gfile.obj: 2d.h datapath.h dbg.h dbgmacro.h fix.h fname.h gfile.h lg.h \
	 lgalt.h malloc.h memall.h memmacro.h rect.h stdio.h stdlib.h \
	 string.h types.h

gif.obj: 2d.h datapath.h dbg.h dbgmacro.h fix.h gfile.h lg.h lgalt.h \
	 malloc.h memall.h memmacro.h rect.h stdio.h stdlib.h string.h \
	 types.h

pcx.obj: 2d.h datapath.h dbg.h dbgmacro.h fix.h gfile.h lg.h lgalt.h \
	 malloc.h memall.h memmacro.h rect.h stdio.h stdlib.h string.h \
	 types.h
@


1.5.1.1
log
@This is the new style makefile.
@
text
@d5 15
a19 1
# $Header: r:/prj/lib/src/gfile/rcs/makefile 1.5 1994/08/22 17:40:19 rex Exp $
d21 4
a24 1
MAKETOP = $(CWD)
d26 9
a34 1
PROJECT = tech
d36 2
a37 1
%include $(MRC)\env.rc
d39 2
a40 1
%include $(MRC)\init.rc
d42 1
a42 1
LIBTARGS = gfile 
d44 1
a44 1
gfile_OBJS = gfile pcx gif cel bmp
d46 3
a48 1
gfile_HDRS = gfile.h
d50 21
a70 1
%include $(MRC)\make.rc@


1.4
log
@Added bmp.obj
@
text
@d5 1
a5 1
# $Header: n:/project/lib/src/gfile/RCS/makefile 1.3 1993/09/27 19:22:42 rex Exp $
d7 3
d27 2
a28 2
SRCDIR = n:\project\lib\src\gfile
RELDIR = n:\project\lib\release
d42 1
a42 1
BUILD_DIR	= n:\project\lib\build\gfile
@


1.3
log
@Added cel.obj
@
text
@d5 1
a5 1
# $Header: n:/project/lib/src/gfile/RCS/makefile 1.2 1993/09/27 18:01:07 rex Exp $
d7 3
d36 1
a36 1
GFILE_OBJS = gfile.obj pcx.obj gif.obj cel.obj
d48 4
@


1.2
log
@Added gif.obj
@
text
@d5 1
a5 1
# $Header: n:/project/lib/src/gfile/RCS/makefile 1.1 1993/09/27 16:38:55 rex Exp $
d7 3
d33 1
a33 1
GFILE_OBJS = gfile.obj pcx.obj gif.obj
d45 4
@


1.1
log
@Initial revision
@
text
@d5 4
a8 2
# $Header: $
# $Log: $
d10 1
d30 1
a30 1
GFILE_OBJS = gfile.obj pcx.obj
d46 4
@
