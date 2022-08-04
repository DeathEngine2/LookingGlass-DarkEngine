#
# $Source: x:/prj/tech/libsrc/recorder/RCS/makefile $
# $Revision: 1.5 $
# $Author: TOML $
# $Date: 1996/10/29 10:19:31 $
#
# Makefile for recorder library
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = recorder

EXETARGS = rectest
EXETYPE = con

rectest_OBJS =          rectest
rectest_LIBS =          mprintf lg recorder  \
                        cpptools comtools compapis appcore \
                        templgen mprintf
rectest_COMPILER_LIBS = uuid

dev_rectest = rectest
dbg_rectest = rectest
opt_rectest = rectest

recorder_OBJS = recorder rectempl recprmpt

recorder_HDRS =

%include $(MRC)\make.rc

