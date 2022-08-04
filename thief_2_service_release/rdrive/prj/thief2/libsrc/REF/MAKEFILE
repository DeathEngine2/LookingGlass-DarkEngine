#
# $Source: r:/t2repos/thief2/libsrc/ref/makefile,v $
# $Revision: 1.1 $
# $Author: mahk $
# $Date: 1998/03/14 22:05:15 $
#
# Makefile for object system
#

MAKETOP = $(CWD)
PROJECT = cam
PRJBACK ?= r:\prj
COMP ?= w105
SYS ?= win32
EXETYPE = con

#####

%include $(MRC)\env.rc
%include $(MRC)\init.rc

#####

LIBTARGS = ref


##### ref.lib

ref_OBJS = \
	refsys

ref_HDRS = \
	refsys.h \
        objupd.h


%include $(MRC)/make.rc
