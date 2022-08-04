head	 1.11;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.11
date	 1997.10.21.16.38.42;  author KEVIN;  state Exp;
branches ;
next	 1.10;

1.10
date	 1997.10.10.15.04.58;  author KEVIN;  state Exp;
branches ;
next	 1.9;

1.9
date	 1997.09.10.14.00.45;  author TOML;  state Exp;
branches ;
next	 1.8;

1.8
date	 1996.11.18.12.42.17;  author TOML;  state Exp;
branches ;
next	 1.7;

1.7
date	 1996.10.21.17.12.10;  author TOML;  state Exp;
branches ;
next	 1.6;

1.6
date	 1996.10.21.15.08.29;  author TOML;  state Exp;
branches ;
next	 1.5;

1.5
date	 1996.08.12.15.45.36;  author TOML;  state Exp;
branches ;
next	 1.4;

1.4
date	 1996.08.06.16.01.15;  author TOML;  state Exp;
branches ;
next	 1.3;

1.3
date	 1996.05.16.17.10.23;  author TOML;  state Exp;
branches ;
next	 1.2;

1.2
date	 1996.05.11.14.48.42;  author TOML;  state Exp;
branches ;
next	 1.1;

1.1
date	 1996.05.08.17.38.38;  author TOML;  state Exp;
branches ;
next	 ;


desc
@@


1.11
log
@update callback stuff.

@
text
@#
# $Source: x:/prj/tech/libsrc/dispdev/rcs/makefile $
# $Revision: 1.10 $
# $Author: KEVIN $
# $Date: 1997/10/10 15:04:58 $
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

@


1.10
log
@renamed wdspdynf.h and wdspdynf.cpp to dddynf.h and dddynf.cpp.
Export dddynf.h.
@
text
@d3 3
a5 3
# $Revision: 1.9 $
# $Author: TOML $
# $Date: 1997/09/10 14:00:45 $
d20 1
a20 1
dispdev_objs = dispbase
d25 1
a25 1
dispdev_HDRS = wdispapi.h wdspguid.h dddynf.h
@


1.9
log
@Initial revision
@
text
@d3 1
a3 1
# $Revision: 1.8 $
d5 1
a5 1
# $Date: 1996/11/18 12:42:17 $
d22 1
a22 1
                     wdcreate wdspdynf wdisptls wdspgshl
d25 1
a25 1
dispdev_HDRS = wdispapi.h wdspguid.h
@


1.8
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.7 $
d5 1
a5 1
# $Date: 1996/10/21 17:12:10 $
d22 1
a22 1
                     wdcreate wdspdynf wdisptls
@


1.7
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.6 $
d5 1
a5 1
# $Date: 1996/10/21 15:08:29 $
d20 3
a22 1
dispdev_win32_OBJS = wdisp wdspprov wdspmode wdispdd wdispgdi wdcreate wdspdynf
@


1.6
log
@*** empty log message ***
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/dispdev/win/RCS/makefile $
# $Revision: 1.5 $
d5 1
a5 1
# $Date: 1996/08/12 15:45:36 $
d20 2
a21 1
dispdev_OBJS = wdisp wdspprov wdspmode wdispdd wdispgdi wdcreate wdspdynf
@


1.5
log
@*** empty log message ***
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/windisp/rcs/makefile $
# $Revision: 1.4 $
d5 1
a5 1
# $Date: 1996/08/06 16:01:15 $
d18 1
a18 1
LIBTARGS = windisp
d20 1
a20 1
windisp_OBJS = wdisp wdspprov wdspmode wdispdd wdispgdi wdcreate wdspdynf
d22 1
a22 1
windisp_HDRS = wdispapi.h wdspguid.h
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
# $Date: 1996/05/16 17:10:23 $
d20 1
a20 1
windisp_OBJS = wdisp wdspprov wdspmode wdispdd wdispgdi wdcreate wdspdynf aggddraw
d22 1
a22 1
windisp_HDRS =
@


1.3
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.2 $
d5 1
a5 1
# $Date: 1996/05/11 14:48:42 $
d20 1
a20 1
windisp_OBJS = wdisp wdspprov wdspmode wdispdd wdispgdi wdcreate wdspdynf
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
# $Date: 1996/05/08 17:38:38 $
d20 1
a20 1
windisp_OBJS = wdisp wdspprov wdspmode wdispdd wdispgdi wdcreate
@


1.1
log
@Initial revision
@
text
@d2 4
a5 4
# $Source: $
# $Revision:  $
# $Author:  $
# $Date: $
d20 1
a20 1
windisp_OBJS = wdisp wdispdd wdispgdi
@
