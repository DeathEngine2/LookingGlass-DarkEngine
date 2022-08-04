head	 1.9;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.9
date	 1998.06.29.14.32.33;  author JAEMZ;  state Exp;
branches ;
next	 1.8;

1.8
date	 1997.07.04.11.34.57;  author JAEMZ;  state Exp;
branches ;
next	 1.7;

1.7
date	 1996.12.13.12.40.11;  author kate;  state Exp;
branches ;
next	 1.6;

1.6
date	 1996.12.03.14.50.54;  author KEVIN;  state Exp;
branches ;
next	 1.5;

1.5
date	 1996.11.07.15.23.00;  author JAEMZ;  state Exp;
branches ;
next	 1.4;

1.4
date	 1996.10.31.14.52.27;  author JAEMZ;  state Exp;
branches ;
next	 1.3;

1.3
date	 1996.08.23.14.21.42;  author JAEMZ;  state Exp;
branches ;
next	 1.2;

1.2
date	 1996.07.26.10.45.15;  author JAEMZ;  state Exp;
branches ;
next	 1.1;

1.1
date	 1996.07.23.12.42.46;  author JAEMZ;  state Exp;
branches ;
next	 ;


desc
@The makefile for the model library
@


1.9
log
@Export md_.h
@
text
@#
# $Source: x:/prj/tech/libsrc/md/RCS/makefile $
# $Revision: 1.8 $
# $Author: JAEMZ $
# $Date: 1997/07/04 11:34:57 $
#
# Makefile for MD library
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = md

md_OBJS = render debug utils light scale shear fancy hitdet mipmap

md_HDRS= md.h md_.h mds.h mdd.h mdutil.h

%include $(MRC)\make.rc


@


1.8
log
@Added mdutil.h and mipmap.c
@
text
@d2 4
a5 4
# $Source: x:/prj/tech/libsrc/md/rcs/makefile $
# $Revision: 1.7 $
# $Author: kate $
# $Date: 1996/12/13 12:40:11 $
d22 1
a22 1
md_HDRS= md.h mds.h mdd.h mdutil.h
@


1.7
log
@added shear module
@
text
@d3 3
a5 3
# $Revision: 1.6 $
# $Author: KEVIN $
# $Date: 1996/12/03 14:50:54 $
d20 1
a20 1
md_OBJS = render debug utils light scale shear fancy hitdet
d22 1
a22 1
md_HDRS= md.h mds.h mdd.h
@


1.6
log
@added hitdet module.
@
text
@d3 3
a5 3
# $Revision: 1.5 $
# $Author: JAEMZ $
# $Date: 1996/11/07 15:23:00 $
d20 1
a20 1
md_OBJS = render debug utils light scale fancy hitdet
@


1.5
log
@Added fancy.c
@
text
@d3 1
a3 1
# $Revision: 1.4 $
d5 1
a5 1
# $Date: 1996/10/31 14:52:27 $
d20 1
a20 1
md_OBJS = render debug utils light scale fancy
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
# $Date: 1996/08/23 14:21:42 $
d20 1
a20 1
md_OBJS = render debug utils light scale
@


1.3
log
@Added utils.c
@
text
@d3 1
a3 1
# $Revision: 1.2 $
d5 1
a5 1
# $Date: 1996/07/26 10:45:15 $
d20 1
a20 1
md_OBJS = render debug utils light
@


1.2
log
@Added light.c
@
text
@d3 1
a3 1
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1996/07/23 12:42:46 $
d20 1
a20 1
md_OBJS = render debug light
@


1.1
log
@Initial revision
@
text
@d2 4
a5 4
# $Source: x:/prj/tech/libsrc/r3d/rcs/makefile $
# $Revision: 1.17 $
# $Author: buzzard $
# $Date: 1996/06/30 03:10:59 $
d20 1
a20 1
md_OBJS = render debug
@
