head	 2.4;
branch   ;
access   ;
symbols  oldnmk:1.1.1 FLT_SHIP:1.1.1.1;
locks    ; strict;
comment  @# @;


2.4
date	 1997.08.12.22.34.58;  author JAEMZ;  state Exp;
branches ;
next	 2.3;

2.3
date	 1997.01.31.23.26.07;  author JAEMZ;  state Exp;
branches ;
next	 2.2;

2.2
date	 1995.10.18.12.58.49;  author ept;  state Exp;
branches ;
next	 2.1;

2.1
date	 1995.10.18.12.57.56;  author ept;  state Exp;
branches ;
next	 1.1;

1.1
date	 1994.10.24.23.27.56;  author jaemz;  state Exp;
branches 1.1.1.1;
next	 ;

1.1.1.1
date	 1995.03.20.16.14.41;  author jaemz;  state Exp;
branches ;
next	 ;


desc
@Star makefile
. 
@


2.4
log
@Took out star3d.asm
@
text
@#
# $Source: x:/prj/tech/libsrc/star/rcs/makefile $
# $Revision: 2.3 $
# $Author: JAEMZ $
# $Date: 1997/01/31 23:26:07 $
#
# Makefile for Star library
#
# $Log: makefile $
# Revision 2.3  1997/01/31  23:26:07  JAEMZ
# Ported star library to new libraries
# 
# Revision 2.2  1995/10/18  12:58:49  ept
# Typo fixed.
# 
# Revision 2.1  1995/10/18  12:57:56  ept
# This is the makefile for the new make system.
# 
# Revision 1.1.1.1  1995/03/20  16:14:41  jaemz
# New make system
# 
# Revision 1.1  1994/10/24  23:27:56  jaemz
# Initial revision
# 
#

MAKETOP = $(CWD)

PROJECT = tech 

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = star 

star_OBJS = star 
star_HDRS = star.h 

%include $(INIT)/make.rc

@


2.3
log
@Ported star library to new libraries
@
text
@d3 3
a5 3
# $Revision: 2.2 $
# $Author: ept $
# $Date: 1995/10/18 12:58:49 $
d10 3
d37 1
a37 1
star_OBJS = star star3d
@


2.2
log
@Typo fixed.
@
text
@d2 2
a3 2
# $Source: t:/prj/tech/libsrc/star/rcs/makefile $
# $Revision: 2.1 $
d5 1
a5 1
# $Date: 1995/10/18 12:57:56 $
d10 3
d32 1
a32 2
# normal and stereo version
LIBTARGS = star ststar
a33 3
# this is kind of bad, since you lose other dependencies
ststar_DEFINES = STEREO_ON

a35 6

ststar_OBJS = ststar star3d
ststar_HDRS = star.h

ststar.c: star.c
        copy star.c ststar.c
@


2.1
log
@This is the makefile for the new make system.
@
text
@d3 3
a5 3
# $Revision: 1.1.1.1 $
# $Author: jaemz $
# $Date: 1995/03/20 16:14:41 $
d10 3
d44 1
a44 1
!include $(INIT)/make.rc
@


1.1
log
@Initial revision
@
text
@d2 2
a3 2
# $Source: r:/prj/lib/src/vox/RCS/makefile $
# $Revision: 1.3 $
d5 1
a5 1
# $Date: 1994/07/15 21:15:07 $
d10 6
d18 1
a18 8
COMPILER = watcom
SRCDIR = r:\prj\lib\src\star
RELDIR = r:\prj\lib\rel
OBJDIR = objo
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = $(RELDIR)
d20 6
d27 1
a27 2
LIB_TARGETS = star  ststar
INST_TARGETS = star ststar
d30 1
a30 2
objo\ststar.obj : star.c
	%do "%.obj : %.c" CFLAGS+="-DSTEREO_ON"
d32 2
a33 2
objd\ststar.obj : star.c
	%do "%.obj : %.c" CFLAGS+="-DSTEREO_ON"
d35 2
a36 5
ststar.obj : star.c
	%do "%.obj : %.c" CFLAGS+="-DSTEREO_ON"
	
STAR_OBJS = star.obj star3d.obj
STAR_HDRS = star.h 
d38 2
a39 2
STSTAR_OBJS = ststar.obj star3d.obj
STSTAR_HDRS = star.h
a41 2

### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.
@


1.1.1.1
log
@New make system
@
text
@d2 2
a3 2
# $Source: r:/prj/lib/src/star/RCS/makefile $
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1994/10/24 23:27:56 $
a9 3
# Revision 1.1  1994/10/24  23:27:56  jaemz
# Initial revision
# 
d12 8
a19 1
MAKETOP = $(CWD)
a20 6
PROJECT = tech 

%include $(MRC)\env.rc

%include $(MRC)\init.rc

d22 2
a23 1
LIBTARGS = star ststar
d26 2
a27 1
ststar_DEFINES = STEREO_ON
d29 2
a30 2
star_OBJS = star star3d
star_HDRS = star.h 
d32 5
a36 2
ststar_OBJS = ststar star3d
ststar_HDRS = star.h
d38 2
a39 2
ststar.c: star.c
        copy star.c ststar.c
d42 2
@

