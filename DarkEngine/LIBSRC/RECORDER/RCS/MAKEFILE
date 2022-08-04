head	 1.5;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.5
date	 1996.10.29.10.19.31;  author TOML;  state Exp;
branches ;
next	 1.4;

1.4
date	 1996.09.05.11.52.41;  author TOML;  state Exp;
branches ;
next	 1.3;

1.3
date	 1996.08.27.13.09.48;  author TOML;  state Exp;
branches ;
next	 1.2;

1.2
date	 1996.08.12.15.43.54;  author TOML;  state Exp;
branches ;
next	 1.1;

1.1
date	 1996.08.12.14.43.27;  author TOML;  state Exp;
branches ;
next	 ;


desc
@@


1.5
log
@*** empty log message ***
@
text
@#
# $Source: x:/prj/tech/libsrc/recorder/rcs/makefile $
# $Revision: 1.4 $
# $Author: TOML $
# $Date: 1996/09/05 11:52:41 $
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
# $Date: 1996/08/27 13:09:48 $
d33 1
a33 1
recorder_OBJS = recorder rectempl
@


1.3
log
@Latest from Jeff
@
text
@d3 1
a3 1
# $Revision: 1.2 $
d5 1
a5 1
# $Date: 1996/08/12 15:43:54 $
d33 1
a33 1
recorder_OBJS = recorder recdata rectempl
@


1.2
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1996/08/12 14:43:27 $
d20 14
a33 1
recorder_OBJS = recorder recdata
@


1.1
log
@Initial revision
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/windisp/rcs/makefile $
# $Revision: 1.4 $
d5 1
a5 1
# $Date: 1996/08/06 16:01:15 $
d20 1
a20 1
recorder_OBJS = recorder
@
