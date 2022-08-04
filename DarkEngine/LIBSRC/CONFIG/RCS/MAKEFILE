head	 2.4;
branch   ;
access   ;
symbols  SHIPPED_F95:2.3 oldnmk:1.4.1 FLT_SHIP:1.4.1.2;
locks    ; strict;
comment  @# @;


2.4
date	 1996.04.08.16.50.29;  author TOML;  state Exp;
branches ;
next	 2.3;

2.3
date	 1996.02.06.16.51.26;  author DAVET;  state Exp;
branches ;
next	 2.2;

2.2
date	 1995.11.27.03.23.52;  author mahk;  state Exp;
branches ;
next	 2.1;

2.1
date	 1995.10.02.19.53.54;  author JON;  state Exp;
branches ;
next	 1.4;

1.4
date	 1994.10.03.19.24.26;  author mahk;  state Exp;
branches 1.4.1.1;
next	 1.3;

1.3
date	 1994.06.15.15.56.33;  author mahk;  state Exp;
branches ;
next	 1.2;

1.2
date	 1993.07.27.13.39.00;  author mahk;  state Exp;
branches ;
next	 1.1;

1.1
date	 1993.07.27.13.37.15;  author mahk;  state Exp;
branches ;
next	 ;

1.4.1.1
date	 1994.12.10.10.13.33;  author lmfeeney;  state Exp;
branches ;
next	 1.4.1.2;

1.4.1.2
date	 1995.04.10.04.55.50;  author mahk;  state Exp;
branches ;
next	 ;


desc
@makefile for new config library
@


2.4
log
@*** empty log message ***
@
text
@# $Source: x:/prj/tech/libsrc/config/RCS/makefile $
# $Revision: 2.3 $
# $Author: DAVET $
# $Date: 1996/02/06 16:51:26 $

MAKETOP = $(CWD)

PROJECT = tech 

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = config

config_OBJS = config cfg

config_HDRS = config.h cfgdbg.h cfg.h

%include $(MRC)\make.rc


@


2.3
log
@*** empty log message ***
@
text
@d1 4
a4 4
# $Source: x:/prj/windex/libsrc/config/rcs/makefile $
# $Revision: 2.2 $
# $Author: mahk $
# $Date: 1995/11/27 03:23:52 $
d8 1
a8 1
PROJECT = windex 
@


2.2
log
@added cfg.h and cfg.c 
@
text
@d1 2
a2 2
# $Source: r:/prj/lib/src/config/rcs/makefile $
# $Revision: 1.4.1.2 $
d4 1
a4 1
# $Date: 1995/04/10 04:55:50 $
@


2.1
log
@Branch for new makefile replacing nmk.
@
text
@d16 1
a16 1
config_OBJS = config
d18 1
a18 1
config_HDRS = config.h cfgdbg.h
@


1.4
log
@changed source dir.
@
text
@d1 4
a4 4
DEBUG_ON = 1
SPEW_ON = 1
WARN_ON = 1
DBG_ON = 1
d6 1
d8 1
a8 3
COMPILER = watcom
SRCDIR = r:\prj\lib\src\config
RELDIR = r:\prj\lib\rel
d10 1
a10 10
OBJDIR = obj
BINDIR =
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = . $(RELDIR)
PROG_TARGETS = cnfgtest
LIB_TARGETS = config
HDR_TARGETS =  
INST_TARGETS = config
d12 1
a12 2
CNFGTEST_OBJS = cnfgtest.obj
CNFGTEST_LIBS = _config.lib _dstruct.lib _lg.lib _mprintf.lib
d14 1
a14 2
CONFIG_OBJS = config.obj
CONFIG_HDRS = config.h
d16 1
a16 1
first_target: config _config
d18 1
a18 1
!include $(INIT)/make.rc
d20 2
a21 1
### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.
@


1.4.1.1
log
@new make regime
@
text
@d1 4
a4 4
# $Source: $
# $Revision: $
# $Author: $
# $Date: $
a5 1
MAKETOP = $(CWD)
d7 3
a9 1
PROJECT = windex 
d11 10
a20 1
%include $(MRC)\env.rc
d22 2
a23 1
%include $(MRC)\init.rc
d25 2
a26 1
LIBTARGS = config
d28 1
a28 1
config_OBJS = config
d30 1
a30 1
config_HDRS = config.h
d32 1
a32 2
%include $(MRC)\make.rc

@


1.4.1.2
log
@Added cfgdbg.h
@
text
@d1 4
a4 4
# $Source: r:/prj/lib/src/config/rcs/makefile $
# $Revision: 1.4.1.1 $
# $Author: lmfeeney $
# $Date: 1994/12/10 10:13:33 $
d18 1
a18 1
config_HDRS = config.h cfgdbg.h
@


1.3
log
@New drive R: crunhiness.
@
text
@d8 1
a8 1
SRCDIR = n:\project\lib\src\config
@


1.2
log
@Hey, maybe we should have an install target
@
text
@d9 1
a9 1
RELDIR = n:\project\lib\release
d17 1
a17 1
PROG_TARGETS = 
d22 3
d27 2
@


1.1
log
@Initial revision
@
text
@d20 1
a20 1
INST_TARGETS = 
@
