head	 1.5;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.5
date	 1997.08.16.14.01.37;  author TOML;  state Exp;
branches ;
next	 1.4;

1.4
date	 1997.07.15.21.27.47;  author TOML;  state Exp;
branches ;
next	 1.3;

1.3
date	 1997.07.10.17.12.30;  author TOML;  state Exp;
branches ;
next	 1.2;

1.2
date	 1997.07.10.11.26.41;  author TOML;  state Exp;
branches ;
next	 1.1;

1.1
date	 1997.07.08.10.47.59;  author TOML;  state Exp;
branches ;
next	 ;


desc
@@


1.5
log
@moved null allocator out
@
text
@#
# $Source: x:/prj/tech/libsrc/lgalloc/rcs/makefile $
# $Revision: 1.4 $
# $Author: TOML $
# $Date: 1997/07/15 21:27:47 $
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
@


1.4
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.3 $
d5 1
a5 1
# $Date: 1997/07/10 17:12:30 $
d26 1
a26 1
               stdalloc
@


1.3
log
@*** empty log message ***
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/memcore/rcs/makefile $
# $Revision: 1.2 $
d5 1
a5 1
# $Date: 1997/07/10 11:26:41 $
d24 6
a29 2
lgalloc_OBJS = allcguid memall memcore membase primallc pool poolimp \
               multpool dbgalloc
d33 1
a33 1
               pool.h poolimp.h
@


1.2
log
@*** empty log message ***
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/multheap/rcs/makefile $
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1997/07/08 10:47:59 $
d17 1
a17 1
LIBTARGS = memcore
d24 2
a25 1
memcore_OBJS = allcguid memcore membase primallc stdalloc
d28 2
a29 1
memcore_HDRS = allocapi.h allcguid.h allocovr.h
d32 1
a32 1
memtest_libs = memcore
@


1.1
log
@Initial revision
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/multheap/RCS/makefile $
# $Revision: 1.3 $
d5 1
a5 1
# $Date: 1996/08/07 17:55:45 $
d17 1
a17 1
LIBTARGS = multheap
d19 2
a20 1
EXETARGS = mhtest heapperf
d24 1
a24 1
multheap_OBJS = memcore heap poolcore pool poolimp
d27 1
a27 1
multheap_HDRS =
d29 2
a30 2
mhtest_objs = mhtest
mhtest_libs = multheap
d32 2
a33 2
heapperf_objs = heapperf
heapperf_libs = multheap lg mprintf
@
