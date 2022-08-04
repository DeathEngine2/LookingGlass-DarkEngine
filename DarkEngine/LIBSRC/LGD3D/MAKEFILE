# 	$Header: x:/prj/tech/libsrc/lgd3d/RCS/makefile 1.11 1997/11/21 14:08:59 KEVIN Exp $

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
