head	 1.27;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.27
date	 1997.10.03.13.03.30;  author KEVIN;  state Exp;
branches ;
next	 1.26;

1.26
date	 1997.10.01.13.33.28;  author KEVIN;  state Exp;
branches ;
next	 1.25;

1.25
date	 1997.07.29.16.13.18;  author KEVIN;  state Exp;
branches ;
next	 1.24;

1.24
date	 1997.06.30.17.15.11;  author KEVIN;  state Exp;
branches ;
next	 1.23;

1.23
date	 1997.06.13.18.26.50;  author JAEMZ;  state Exp;
branches ;
next	 1.22;

1.22
date	 1997.05.30.13.02.53;  author JAEMZ;  state Exp;
branches ;
next	 1.21;

1.21
date	 1996.10.22.11.14.34;  author JAEMZ;  state Exp;
branches ;
next	 1.20;

1.20
date	 1996.10.21.19.58.35;  author buzzard;  state Exp;
branches ;
next	 1.19;

1.19
date	 1996.10.17.17.23.00;  author TOML;  state Exp;
branches ;
next	 1.18;

1.18
date	 1996.09.16.14.44.04;  author JAEMZ;  state Exp;
branches ;
next	 1.17;

1.17
date	 1996.06.30.03.10.59;  author buzzard;  state Exp;
branches ;
next	 1.16;

1.16
date	 1996.06.06.19.05.55;  author JAEMZ;  state Exp;
branches ;
next	 1.15;

1.15
date	 1996.06.06.19.00.26;  author JAEMZ;  state Exp;
branches ;
next	 1.14;

1.14
date	 1996.06.06.14.52.00;  author buzzard;  state Exp;
branches ;
next	 1.13;

1.13
date	 1996.05.28.23.41.12;  author buzzard;  state Exp;
branches ;
next	 1.12;

1.12
date	 1996.05.27.16.11.11;  author buzzard;  state Exp;
branches ;
next	 1.11;

1.11
date	 1996.05.20.13.26.39;  author buzzard;  state Exp;
branches ;
next	 1.10;

1.10
date	 1996.05.13.23.20.27;  author buzzard;  state Exp;
branches ;
next	 1.9;

1.9
date	 1996.05.13.18.06.26;  author JAEMZ;  state Exp;
branches ;
next	 1.8;

1.8
date	 1996.05.12.03.09.52;  author JAEMZ;  state Exp;
branches ;
next	 1.7;

1.7
date	 1996.05.12.00.39.17;  author dc;  state Exp;
branches ;
next	 1.6;

1.6
date	 1996.05.11.22.37.54;  author JAEMZ;  state Exp;
branches ;
next	 1.5;

1.5
date	 1996.05.06.08.10.46;  author buzzard;  state Exp;
branches ;
next	 1.4;

1.4
date	 1996.05.06.01.13.17;  author dc;  state Exp;
branches ;
next	 1.3;

1.3
date	 1996.05.06.00.26.15;  author buzzard;  state Exp;
branches ;
next	 1.2;

1.2
date	 1996.05.05.22.40.44;  author JAEMZ;  state Exp;
branches ;
next	 1.1;

1.1
date	 1996.04.30.11.50.57;  author JAEMZ;  state Exp;
branches ;
next	 ;


desc
@Make file for r3d library
@


1.27
log
@add r3d_do_setup flag to delay poly setup until just before 1st poly draw.
@
text
@#
# $Source: x:/prj/tech/libsrc/r3d/rcs/makefile $
# $Revision: 1.26 $
# $Author: KEVIN $
# $Date: 1997/10/01 13:33:28 $
#
# Makefile for r3d library
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = r3d

# These only work under dos, so it breaks under windows, they should
# be in a test directory instead
# EXETARGS = r3dtest1
# r3dtest1_LIBS = r3d 2d lg matrix mprintf
# r3dtest1_OBJS = testcore test1

r3d_OBJS = \
  block    \
  clip     \
  clipclip \
  clipglob \
  clipplan \
  clipproj \
  cliptest \
  clipunsc \
  ctxtguts \
  ctxtmang \
  ctxtmult \
  frame    \
  init     \
  object   \
  prim     \
  primconv \
  primd3d  \
  primface \
  primfunc \
  primg2   \
  primmisc \
  primnull \
  primpoly \
  projfast \
  space    \
  utils    \
  view     \
  xfrmclip \
  xfrmglob \
  xfrmlin  \
  xfrmproj \
  xfrmunsc

r3d_HDRS= r3d.h r3ds.h r3dutil.h

r3d_newline_hack=" "
r3d_newline=$(r3d_newline_hack,W\n)
r3d_dependent_includes="\#include \<matrix.h\>"$(r3d_newline)"\#include \<r3ds.h\>"

#don't really need g2.h anymore!
#$(r3d_newline)"\#include \<g2.h\>"

r3d.h .REREAD :\
        xfrmtab.h xform.h \
        clip.h clipcon.h clipplan.h clipprim.h \
        primcon.h prim.h primtab.h primface.h primconv.h \
        ctxts.h object.h space.h view.h block.h r3dctxt.h init.h \
        clipoff.h
	$(eko1) $(@@,F) \<-- $(?,F)
        %do comp_h h_pre=$(r3d_dependent_includes) h_in="$^" h_out="$(@@,F)"

%include $(MRC)\make.rc


@


1.26
log
@reduce header dependencies.
@
text
@d3 1
a3 1
# $Revision: 1.25 $
d5 1
a5 1
# $Date: 1997/07/29 16:13:18 $
d46 1
@


1.25
log
@Added null driver module (primnull).
@
text
@d3 1
a3 1
# $Revision: 1.24 $
d5 1
a5 1
# $Date: 1997/06/30 17:15:11 $
d63 4
a66 1
r3d_dependent_includes="\#include \<matrix.h\>"$(r3d_newline)"\#include \<r3ds.h\>"$(r3d_newline)"\#include \<g2.h\>"
@


1.24
log
@Add d3d support.
@
text
@d3 3
a5 3
# $Revision: 1.23 $
# $Author: JAEMZ $
# $Date: 1997/06/13 18:26:50 $
d47 1
@


1.23
log
@Added new h file
@
text
@d3 1
a3 1
# $Revision: 1.22 $
d5 1
a5 1
# $Date: 1997/05/30 13:02:53 $
d43 1
@


1.22
log
@Added clipoff
@
text
@d3 1
a3 1
# $Revision: 1.21 $
d5 1
a5 1
# $Date: 1996/10/22 11:14:34 $
d57 1
a57 1
r3d_HDRS= r3d.h r3ds.h
d68 1
a68 1
        utils.h clipoff.h
@


1.21
log
@Added cliptest
@
text
@d3 3
a5 3
# $Revision: 1.20 $
# $Author: buzzard $
# $Date: 1996/10/21 19:58:35 $
d68 1
a68 1
        utils.h
@


1.20
log
@projfast (project space assembly)
@
text
@d3 3
a5 3
# $Revision: 1.19 $
# $Author: TOML $
# $Date: 1996/10/17 17:23:00 $
d33 1
@


1.19
log
@added newlines to auto header generation
@
text
@d3 3
a5 3
# $Revision: 1.18 $
# $Author: JAEMZ $
# $Date: 1996/09/16 14:44:04 $
d46 1
@


1.18
log
@Added utils
@
text
@d3 3
a5 3
# $Revision: 1.17 $
# $Author: buzzard $
# $Date: 1996/06/30 03:10:59 $
d18 1
a18 1
LIBTARGS = r3d 
d57 4
d68 1
a68 1
        %do comp_h h_pre="\#include \<matrix.h\> \#include \<r3ds.h\> \#include \<g2.h\>" h_in="$^" h_out="$(@@,F)"
@


1.17
log
@expose r3_clip_polygon
@
text
@d3 3
a5 3
# $Revision: 1.16 $
# $Author: JAEMZ $
# $Date: 1996/06/06 19:05:55 $
d47 1
d61 2
a62 1
        ctxts.h object.h space.h view.h block.h r3dctxt.h init.h 
@


1.16
log
@Removed exetarg
@
text
@d3 1
a3 1
# $Revision: 1.15 $
d5 1
a5 1
# $Date: 1996/06/06 19:00:26 $
d58 2
a59 2
        clip.h clipcon.h clipplan.h \
        primcon.h prim.h primtab.h primface.h \
@


1.15
log
@Added g2 to it
@
text
@d3 3
a5 3
# $Revision: 1.14 $
# $Author: buzzard $
# $Date: 1996/06/06 14:52:00 $
d20 5
a24 4
EXETARGS = r3dtest1

r3dtest1_LIBS = r3d 2d lg matrix mprintf
r3dtest1_OBJS = testcore test1
@


1.14
log
@*** empty log message ***
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/r3d/RCS/makefile $
# $Revision: 1.15 $
d5 1
a5 1
# $Date: 1996/06/06 14:22:44 $
d61 1
a61 1
        %do comp_h h_pre="\#include \<matrix.h\>  \#include \<r3ds.h\>" h_in="$^" h_out="$(@@,F)"
@


1.13
log
@don't include cliptab; include clippan
clipplan
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/r3d/rcs/makefile $
# $Revision: 1.12 $
d5 1
a5 1
# $Date: 1996/05/27 16:11:11 $
d56 1
a56 1
        grspoint.h r3ds.h rtex.h  xfrmtab.h xform.h \
d61 1
a61 1
        %do comp_h h_pre="\#include \<matrix.h\>  \#include \<2d.h\>" h_in="$^" h_out="$(@@,F)"
@


1.12
log
@delete cliplin from tree
@
text
@d3 1
a3 1
# $Revision: 1.11 $
d5 1
a5 1
# $Date: 1996/05/20 13:26:39 $
d57 1
a57 1
        clip.h clipcon.h cliptab.h \
@


1.11
log
@primface.h
@
text
@d3 1
a3 1
# $Revision: 1.10 $
d5 1
a5 1
# $Date: 1996/05/13 23:20:27 $
a29 1
  cliplin  \
@


1.10
log
@polygon clipping
@
text
@d3 3
a5 3
# $Revision: 1.9 $
# $Author: JAEMZ $
# $Date: 1996/05/13 18:06:26 $
d58 2
a59 1
        clip.h clipcon.h cliptab.h primcon.h prim.h primtab.h \
@


1.9
log
@Took frank out and added concatenating h files
@
text
@d3 1
a3 1
# $Revision: 1.8 $
d5 1
a5 1
# $Date: 1996/05/11 23:09:52 $
d27 1
@


1.8
log
@Added frank
@
text
@d3 3
a5 3
# $Revision: 1.7 $
# $Author: dc $
# $Date: 1996/05/12 00:39:17 $
d20 1
a20 1
EXETARGS = r3dtest1 frank
a21 3
frank_objs = frank 
frank_libs = lg mprintf matrix 2d r3d

d53 8
a60 1
r3d_HDRS = r3d.h r3ds.h
@


1.7
log
@add the first test .exe
@
text
@d3 3
a5 3
# $Revision: 1.6 $
# $Author: JAEMZ $
# $Date: 1996/05/11 22:37:54 $
d20 4
a23 1
EXETARGS = r3dtest1
@


1.6
log
@Included block.c
@
text
@d3 3
a5 3
# $Revision: 1.5 $
# $Author: buzzard $
# $Date: 1996/05/06 08:10:46 $
d19 5
@


1.5
log
@no clip.c currently
@
text
@d3 3
a5 3
# $Revision: 1.4 $
# $Author: dc $
# $Date: 1996/05/06 01:13:17 $
d21 1
@


1.4
log
@add context, init, and frame
alpha and one per line
@
text
@d3 3
a5 3
# $Revision: 1.2 $
# $Author: JAEMZ $
# $Date: 1996/05/05 22:40:44 $
a20 1
  clip     \
@


1.3
log
@*** empty log message ***
@
text
@d21 26
a46 5
prim primconv primface primfunc primmisc primpoly \
clip clipclip clipglob cliplin clipplan clipproj clipunsc \
ctext ctxtguts object \
space view xfrmclip xfrmglob xfrmlin xfrmproj \
xfrmunsc
@


1.2
log
@Added all the files to it
@
text
@d3 1
a3 1
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1996/04/30 11:50:57 $
d21 1
d23 2
a24 2
ctext ctxtguts object prim primconv primface primfunc primmisc \
primpoly primprim space view xfrmclip xfrmglob xfrmlin xfrmproj \
@


1.1
log
@Initial revision
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/3d/rcs/makefile $
# $Revision: 1.37 $
d5 1
a5 1
# $Date: 1995/08/15 11:45:54 $
d20 5
a24 1
r3d_OBJS = ctext globxfrm object space view
@
