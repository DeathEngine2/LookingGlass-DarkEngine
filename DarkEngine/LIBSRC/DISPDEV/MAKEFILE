#
# $Source: x:/prj/tech/libsrc/dispdev/RCS/makefile $
# $Revision: 1.11 $
# $Author: KEVIN $
# $Date: 1997/10/21 16:38:42 $
#
# Makefile for windisp library
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = dispdev

dispdev_objs = dispbase cbchain
dispdev_win32_OBJS = wdisp wdspprov wdspmode wdispdd wddmode wdispgdi \
                     wdcreate wdisptls wdspgshl dddynf 
dispdev_dos4g_OBJS = ddisp

dispdev_HDRS = wdispapi.h wdspguid.h wdispcb.h dddynf.h cbchain.h

%include $(MRC)\make.rc

