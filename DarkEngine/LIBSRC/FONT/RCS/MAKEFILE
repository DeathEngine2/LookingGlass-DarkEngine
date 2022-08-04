head	 1.2;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.2
date	 1997.01.23.14.43.37;  author KEVIN;  state Exp;
branches ;
next	 1.1;

1.1
date	 1996.04.11.10.28.42;  author KEVIN;  state Exp;
branches ;
next	 ;


desc
@makefile for font library.
@


1.2
log
@new mods
@
text
@#
# $Source: s:/prj/tech/libsrc/font/rcs/makefile $
# $Revision: 1.1 $
# $Author: KEVIN $
# $Date: 1996/04/11 10:28:42 $
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = font

EXETARGS = ftest

irrupt_OBJS = \

font_OBJS = \
        chr chrclr chrsiz \
        f16fl8t setup \
        str strclr strsiz \
        strscl strwrap

FONT_HDRS = font.h

font.h .REREAD :\
        fonts.h chrsiz.h strsiz.h fontf.h stupid.h
	$(eko1) $(@@,F) \<-- $(?,F)
	%do comp_h h_pre="\#include \<dev2d.h\>" h_in="$^" h_out="$(@@,F)"

TBU_TARGS = ftest

%foreach t $(TBU_TARGS)
$t_OBJS = $t
$t_LIBS = font grtb g2 dev2d mprintf lg fix fault uvbelib pmode
%end

%include $(MRC)\make.rc

# this rule generates foo.c files from foo.tbl
%.c .MISER .NODEFAULT: %.tbl
        @@tblmunge $(<,F) $(MAKETOP)\$(@@,F)
@


1.1
log
@Initial revision
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/2d/RCS/makefile $
# $Revision: 2.3 $
d5 1
a5 1
# $Date: 1995/11/09 16:29:57 $
d24 1
@
