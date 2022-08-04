head	 1.11;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.11
date	 1997.11.21.14.08.59;  author KEVIN;  state Exp;
branches ;
next	 1.10;

1.10
date	 1997.10.28.15.30.50;  author KEVIN;  state Exp;
branches ;
next	 1.9;

1.9
date	 1997.10.13.14.38.31;  author KEVIN;  state Exp;
branches ;
next	 1.8;

1.8
date	 1997.10.09.15.36.13;  author KEVIN;  state Exp;
branches ;
next	 1.7;

1.7
date	 1997.10.06.14.57.30;  author KEVIN;  state Exp;
branches ;
next	 1.6;

1.6
date	 1997.10.01.09.34.18;  author DAVET;  state Exp;
branches ;
next	 1.5;

1.5
date	 1997.09.10.15.07.17;  author KEVIN;  state Exp;
branches ;
next	 1.4;

1.4
date	 1997.07.23.16.41.51;  author KEVIN;  state Exp;
branches ;
next	 1.3;

1.3
date	 1997.07.07.15.15.26;  author KEVIN;  state Exp;
branches ;
next	 1.2;

1.2
date	 1997.06.10.12.36.29;  author KEVIN;  state Exp;
branches ;
next	 1.1;

1.1
date	 1997.06.02.16.40.42;  author KEVIN;  state Exp;
branches ;
next	 ;


desc
@lgd3d makefile
@


1.11
log
@*** empty log message ***
@
text
@# 	$Header: x:/prj/tech/libsrc/lgd3d/RCS/makefile 1.10 1997/10/28 15:30:50 KEVIN Exp $

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

SPEC_EXETARGS = d3dtest

LIBTARGS = lgd3d


lgd3d_OBJS = tmgr clip

lgd3d_WIN32_OBJS = setup render blit texture enum

lgd3d_HDRS = lgd3d.h tmgr.h


d3dtest_WIN32_OBJS = $(lgd3d_WIN32_OBJS)

d3dtest_OBJS = comshell d3dtest $(lgd3d_OBJS)

d3dtest_LIBS = dxguid grtb $(TECH_SYS_LIBS) $(TECH_CORE_LIBS) $(TECH_GRAPH_LIBS)

%include $(MRC)\make.rc
@


1.10
log
@renamed trifan.c render.c
@
text
@d1 1
a1 1
# 	$Header: x:/prj/tech/libsrc/lgd3d/rcs/makefile 1.9 1997/10/13 14:38:31 KEVIN Exp $
d16 1
a16 1
lgd3d_OBJS = tmgr tmgrold clip
@


1.9
log
@Added d3d device enumeration module.
@
text
@d1 1
a1 1
# 	$Header: x:/prj/tech/libsrc/d3d/rcs/makefile 1.8 1997/10/09 15:36:13 KEVIN Exp $
d18 1
a18 1
lgd3d_WIN32_OBJS = setup trifan blit texture enum
@


1.8
log
@add clip module.
@
text
@d1 1
a1 1
# 	$Header: x:/prj/tech/libsrc/d3d/rcs/makefile 1.7 1997/10/06 14:57:30 KEVIN Exp $
a8 3
# only SYS=WIN32 makes sense
SYS = WIN32

d18 1
a18 1
lgd3d_WIN32_OBJS = setup trifan blit texture 
@


1.7
log
@added d3dtest_WIN32_objs.
@
text
@d1 1
a1 1
# 	$Header: x:/prj/tech/libsrc/d3d/rcs/makefile 1.6 1997/10/01 09:34:18 DAVET Exp $
d19 1
a19 1
lgd3d_OBJS = tmgr tmgrold
@


1.6
log
@took out 3rdback
@
text
@d1 1
a1 1
# 	$Header: x:/prj/tech/libsrc/d3d/rcs/makefile 1.5 1997/09/10 15:07:17 KEVIN Exp $
d18 1
d24 3
@


1.5
log
@make seperate win32 objs.
@
text
@d1 1
a1 2
# 	$Header: x:/prj/tech/libsrc/d3d/rcs/makefile 1.4 1997/07/23 16:41:51 KEVIN Exp $
3RDBACK = x:\dx5b
@


1.4
log
@added backup texture manager.  multiple bugfixes.
@
text
@d1 1
a1 1
# 	$Header: x:/prj/tech/libsrc/d3d/rcs/makefile 1.3 1997/07/07 15:15:26 KEVIN Exp $
d19 3
a21 1
lgd3d_OBJS = setup trifan blit texture tmgr tmgrold
@


1.3
log
@cleaned up tmgr api.
@
text
@d1 1
a1 1
# 	$Header: x:/prj/tech/libsrc/d3d/rcs/makefile 1.2 1997/06/10 12:36:29 KEVIN Exp $
d19 1
a19 1
lgd3d_OBJS = setup trifan blit texture tmgr
@


1.2
log
@Set 3rdback to x:\dx5b
@
text
@d1 1
a1 1
# 	$Header: x:/prj/tech/libsrc/d3d/RCS/makefile 1.1 1997/06/02 16:40:42 KEVIN Exp $
d21 1
a21 1
lgd3d_HDRS = lgd3d.h
@


1.1
log
@Initial revision
@
text
@d1 2
a2 1
# 	$Header: x:/prj/tech/libsrc/grtest/rcs/makefile 1.3 1996/10/01 16:11:40 KEVIN Exp $
@
