head	 2.1;
branch   ;
access   ;
symbols  oldnmk:1.3.1 FLT_SHIP:1.3.1.1;
locks    TOML:2.1; strict;
comment  @# @;


2.1
date	 1995.10.18.12.56.34;  author ept;  state Exp;
branches ;
next	 1.4;

1.4
date	 1995.08.22.19.03.24;  author JAEMZ;  state Exp;
branches ;
next	 1.3;

1.3
date	 1994.07.15.18.18.24;  author jaemz;  state Exp;
branches 1.3.1.1;
next	 1.2;

1.2
date	 1994.06.10.13.54.43;  author jaemz;  state Exp;
branches ;
next	 1.1;

1.1
date	 1994.04.21.13.27.16;  author jaemz;  state Exp;
branches ;
next	 ;

1.3.1.1
date	 1995.05.18.14.38.42;  author LMFEENEY;  state Exp;
branches ;
next	 ;


desc
@Makefile for skeleton library
@


2.1
log
@This is the new style makefile for the new make system.
@
text
@#
# $Source: t:/prj/tech/libsrc/skel/rcs/makefile $
# $Revision: 1.3.1.1 $
# $Author: LMFEENEY $
# $Date: 1995/05/18 14:38:42 $
#
# Makefile for Skel library
#

MAKETOP = $(CWD)
PROJECT = tech

%include $(MRC)\env.rc
%include $(MRC)\init.rc

LIBTARGS = skel

skel_OBJS = \
        skel\
        sklist\
        skdraw\
        render

skel_HDRS = \
        skel.h

%include $(MRC)/make.rc

@


1.4
log
@Ha ah
@
text
@@


1.3
log
@added bitmap support
@
text
@d2 4
a5 4
# $Source: r:/prj/lib/src/skel/rcs/makefile $
# $Revision: 1.2 $
# $Author: jaemz $
# $Date: 1994/06/10 13:54:43 $
a8 8
# $Log: makefile $
# Revision 1.2  1994/06/10  13:54:43  jaemz
# updated for new setup
# 
# Revision 1.1  1994/04/21  13:27:16  jaemz
# Initial revision
# 
#
d10 2
a11 10
COMPILER = watcom
SRCDIR = r:\prj\lib\src\skel
RELDIR = r:\prj\lib\rel
OBJDIR = objo
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = $(RELDIR)
LIB_TARGETS = skel
INST_TARGETS = skel
d13 2
a14 6
SKEL_OBJS = \
        skel.obj\
        sklist.obj\
        skdraw.obj\
        render.obj
        
d16 9
a24 1
SKEL_HDRS = \
d27 1
a27 3
!include $(INIT)/make.rc

### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.
@



1.3.1.1
log
@initial revision with nwe development environment
@
text
@d2 2
a3 2
# $Source: r:/prj/lib/src/skel/RCS/makefile $
# $Revision: 1.3 $
d5 1
a5 1
# $Date: 1994/07/15 18:18:24 $
d9 8
d18 10
a27 2
MAKETOP = $(CWD)
PROJECT = tech
d29 6
a34 2
%include $(MRC)\env.rc
%include $(MRC)\init.rc
d36 2
a37 1
LIBTARGS = skel
d39 1
a39 5
skel_OBJS = \
        skel\
        sklist\
        skdraw\
        render
d41 1
a41 4
skel_HDRS = \
        skel.h

%include $(MRC)/make.rc
@



1.2
log
@updated for new setup
@
text
@d2 2
a3 2
# $Source: n:/project/lib/src/skel/rcs/makefile $
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1994/04/21 13:27:16 $
d10 3
d19 1
a19 1
SRCDIR = n:\project\lib\src\skel
d32 2
a33 1
        skdraw.obj
@



1.1
log
@Initial revision
@
text
@d2 4
a5 4
# $Source$
# $Revision$
# $Author$
# $Date$
d9 4
a12 1
# $Log$
d17 1
a17 1
RELDIR = n:\project\lib\release
@

