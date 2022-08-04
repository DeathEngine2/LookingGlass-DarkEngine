#
# $Source: x:/prj/tech/libsrc/lgalloc/RCS/makefile $
# $Revision: 1.5 $
# $Author: TOML $
# $Date: 1997/08/16 14:01:37 $
#
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = lgalloc

EXETARGS = memtest
#heapperf

EXETYPE = con

lgalloc_OBJS = allcguid memall memcore membase pool poolimp \
               multpool dbgalloc nonover heap memtimer primallc \
               stdalloc nullallc

lgalloc_opt_objs = pool poolimp multpool heap memtimer stdalloc

#heapimp

lgalloc_HDRS = allocapi.h allcguid.h allocovr.h memall.h virtmem.h \
               pool.h poolimp.h mallocdb.h dbmem.h

memtest_objs = memtest
memtest_libs = lgalloc lg mprintf

#heapperf_objs = heapperf
#heapperf_libs = multheap lg mprintf

%include $(MRC)\make.rc
