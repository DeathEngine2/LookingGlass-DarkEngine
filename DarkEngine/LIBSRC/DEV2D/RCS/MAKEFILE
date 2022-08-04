head	 1.28;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.28
date	 1998.04.28.13.51.16;  author KEVIN;  state Exp;
branches ;
next	 1.27;

1.27
date	 1998.04.02.11.47.26;  author KEVIN;  state Exp;
branches ;
next	 1.26;

1.26
date	 1998.03.31.15.13.52;  author KEVIN;  state Exp;
branches ;
next	 1.25;

1.25
date	 1998.03.26.12.59.46;  author KEVIN;  state Exp;
branches ;
next	 1.24;

1.24
date	 1998.01.27.16.50.14;  author JAEMZ;  state Exp;
branches ;
next	 1.23;

1.23
date	 1997.03.11.10.43.16;  author KEVIN;  state Exp;
branches ;
next	 1.22;

1.22
date	 1997.02.17.14.50.23;  author KEVIN;  state Exp;
branches ;
next	 1.21;

1.21
date	 1997.02.07.11.22.14;  author KEVIN;  state Exp;
branches ;
next	 1.20;

1.20
date	 1996.12.13.16.02.23;  author TOML;  state Exp;
branches ;
next	 1.19;

1.19
date	 1996.12.06.15.46.47;  author KEVIN;  state Exp;
branches ;
next	 1.18;

1.18
date	 1996.12.06.15.28.49;  author KEVIN;  state Exp;
branches ;
next	 1.17;

1.17
date	 1996.12.06.14.32.14;  author KEVIN;  state Exp;
branches ;
next	 1.16;

1.16
date	 1996.09.26.15.20.53;  author KEVIN;  state Exp;
branches ;
next	 1.15;

1.15
date	 1996.09.20.12.37.38;  author KEVIN;  state Exp;
branches ;
next	 1.14;

1.14
date	 1996.09.09.14.16.10;  author KEVIN;  state Exp;
branches ;
next	 1.13;

1.13
date	 1996.08.29.09.43.52;  author KEVIN;  state Exp;
branches ;
next	 1.12;

1.12
date	 1996.08.22.15.12.18;  author KEVIN;  state Exp;
branches ;
next	 1.11;

1.11
date	 1996.08.19.12.23.21;  author KEVIN;  state Exp;
branches ;
next	 1.10;

1.10
date	 1996.08.07.13.17.06;  author KEVIN;  state Exp;
branches ;
next	 1.9;

1.9
date	 1996.07.23.09.52.11;  author KEVIN;  state Exp;
branches ;
next	 1.8;

1.8
date	 1996.05.15.16.00.12;  author KEVIN;  state Exp;
branches ;
next	 1.7;

1.7
date	 1996.05.07.10.35.21;  author KEVIN;  state Exp;
branches ;
next	 1.6;

1.6
date	 1996.04.30.16.13.01;  author KEVIN;  state Exp;
branches ;
next	 1.5;

1.5
date	 1996.04.25.12.36.14;  author KEVIN;  state Exp;
branches ;
next	 1.4;

1.4
date	 1996.04.22.14.56.52;  author KEVIN;  state Exp;
branches ;
next	 1.3;

1.3
date	 1996.04.11.14.31.18;  author KEVIN;  state Exp;
branches ;
next	 1.2;

1.2
date	 1996.04.11.14.23.25;  author KEVIN;  state Exp;
branches ;
next	 1.1;

1.1
date	 1996.04.10.17.06.25;  author KEVIN;  state Exp;
branches ;
next	 ;


desc
@dev2d makefile
@


1.28
log
@export grs.inc.
@
text
@#
# $Source: x:/prj/tech/libsrc/dev2d/rcs/makefile $
# $Revision: 1.27 $
# $Author: KEVIN $
# $Date: 1998/04/02 11:47:26 $
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = dev2d

dev_gdtest = gdtest
dev_lib_flav = dbg
SPEC_EXETARGS = gdtest

irrupt_OBJS = \
        f16bm fl8bm bk8bm mxbm \
        genf16 genfl8 genmx genrsd8 \
        fl8fl8 fl8bk8 fl8mx \
        bk8fl8 mxfl8 f16f16 f16fl8 \
        gdbm gdgbm canvas bitmap grnull \
        astring hflip

dev2d_OBJS = \
        astring cstring bitmap blend gr \
        bank canvas mxlatch screen grd \
        grnull grmalloc valloc \
        init svgainit cominit novinit \
        mode \
        bk8cnv bk8p8f \
        bk8vlinf bk8hlinf bk8ubmf \
        bk8pix bk8lin bk8bm  \
        bk8pix8 bk8hlin bk8vlin \
        bk8fl8 \
        clut16 \
        fl8cnv fl8p8f fl8p16f \
        fl8vlinf fl8hlinf fl8ubmf \
        fl8pix fl8lin fl8bm \
        fl8pix8 fl8hlin fl8vlin \
        fl8fl8 fl8mono fl8bk8 fl8mx fl8rsd8 \
        f16cnv f16p8f f16p16f \
        f16hlinf f16vlinf f16ubmf \
        f16pix f16lin f16bm \
        f16pix8 f16pix16 f16hlin f16vlin \
        f16fl8 f16mono f16f16 f16rsd8 \
        f16set f16il f16fl8il \
        f16f16c f16f16l \
        fcolor \
        gdbm gdgbm gdrect gdlin gdpix \
        genbm \
        genlin genfl8u genf16u genmonou \
        genbmf genfl8 genmono genmx \
        genrsd8 genf16 \
        gpix \
        hflip lpix light ltab \
        mxcnv mxp8f \
        mxvlinf mxhlinf mxubmf \
        mxpix mxlin mxbm \
        mxpix8 mxhlin mxvlin \
        mxfl8 \
        nulcnv \
        pal pal16 ipal gpal cpal \
        rsdcvt rsdunpck rsdblt8 rsdblt16 \
        smode stastk \
        tluctab \
        comdtab fl8dtab novdtab \
        vgadtab vsadtab w32dtab \
        comdfcn nulldfcn \
        vesac vesaasm vsastate \
        vgaasm vgasmod vgastate \
        clpfl8 \
        ddevcnv ddevblt

gdtest_OBJS = gdtest

gdtest_LIBS = lg dev2d mprintf

DEV2D_HDRS = dev2d.h astring.h grs.inc bitmap.inc cseg.inc dseg.inc gdican.inc

newline_hack=" "
newline=$(newline_hack,W\n)
dependent_includes="\#include \<fix.h\>"$(newline)"\#include \<matrixs.h\>"

dev2d.h .REREAD :\
        emode.h grs.h bitmap.h canvas.h screen.h mode.h alpha.h \
        fill.h clip.h icanvas.h idevice.h grd.h context.h \
        bmftype.h linftype.h pixftype.h \
        gdbm.h gdlin.h gdrect.h gdpix.h grdev.h \
        pal.h gpal.h cpal.h pal16.h init.h \
        tluctab.h grmalloc.h grnull.h indexmac.h gr.h \
        rgb.h blnfcn.h rsdcfg.h fcolor.h \
        stupid.h 
	$(eko1) $(@@,F) \<-- $(?,F)
	%do comp_h h_pre=$(dependent_includes) h_in="$^" h_out="$(@@,F)"

%include $(MRC)\make.rc

# this rule generates foo.c files from foo.tbl

.PATH.tbl = $(.PATH.c)

%.c .MISER .NODEFAULT: %.tbl
        @@%setenv INCLUDE=$(IPATH)
	$(eko1) $(@@,F) \<-- nonexistent
        @@tblmunge $(<,F) $(MAKETOP)\$(@@,F)

@


1.27
log
@added optimized flat16 vlines.
@
text
@d3 1
a3 1
# $Revision: 1.26 $
d5 1
a5 1
# $Date: 1998/03/31 15:13:52 $
d84 1
a84 1
DEV2D_HDRS = dev2d.h astring.h bitmap.inc cseg.inc dseg.inc gdican.inc
@


1.26
log
@added fcolor.obj.
@
text
@d3 1
a3 1
# $Revision: 1.25 $
d5 1
a5 1
# $Date: 1998/03/26 12:59:46 $
d48 1
a48 1
        f16hlinf f16ubmf \
d50 1
a50 1
        f16pix8 f16pix16 f16hlin \
@


1.25
log
@added ltab.obj
@
text
@d3 3
a5 3
# $Revision: 1.24 $
# $Author: JAEMZ $
# $Date: 1998/01/27 16:50:14 $
d54 1
d97 2
a98 2
        rgb.h blnfcn.h rsdcfg.h \
        stupid.h
@


1.24
log
@Added cpal and gpal and cpal to the header
@
text
@d3 3
a5 3
# $Revision: 1.23 $
# $Author: KEVIN $
# $Date: 1997/03/11 10:43:16 $
d60 1
a60 1
        hflip lpix light \
@


1.23
log
@added rsd unpacking configuration to dev2d.h
@
text
@d3 1
a3 1
# $Revision: 1.22 $
d5 1
a5 1
# $Date: 1997/02/17 14:50:23 $
a66 1
        pal pal16 ipal gpal \
d67 2
a68 1
        rsdcvt rsdunpck rsdblt8 rsdblt16 \
d94 1
a94 1
        pal.h pal16.h init.h \
@


1.22
log
@new inner loop modules.
@
text
@d3 1
a3 1
# $Revision: 1.21 $
d5 1
a5 1
# $Date: 1997/02/07 11:22:14 $
d96 1
a96 1
        rgb.h blnfcn.h \
@


1.21
log
@*** empty log message ***
@
text
@d3 3
a5 3
# $Revision: 1.20 $
# $Author: TOML $
# $Date: 1996/12/13 16:02:23 $
d52 2
a53 1
        f16set f16il f16fl8il f16til \
d60 1
a60 1
        hflip lpix \
@


1.20
log
@*** empty log message ***
@
text
@d3 3
a5 3
# $Revision: 1.19 $
# $Author: KEVIN $
# $Date: 1996/12/06 15:46:47 $
d31 1
a31 1
        astring bitmap blend gr \
@


1.19
log
@Added "#include <matrixs.h>\n" to dev2d.h.
@
text
@d3 1
a3 1
# $Revision: 1.18 $
d5 1
a5 1
# $Date: 1996/12/06 15:28:49 $
d75 2
a76 1
        clpfl8
d107 1
a107 1
        @@%setenv INCLUDE=$(IPATH)        
@


1.18
log
@Added alpha.h and blnfcn.h to dev2d.h.
@
text
@d3 1
a3 1
# $Revision: 1.17 $
d5 1
a5 1
# $Date: 1996/12/06 14:32:14 $
d83 4
d97 1
a97 1
	%do comp_h h_pre="\#include \<fix.h\>" h_in="$^" h_out="$(@@,F)"
@


1.17
log
@Set dev_lib_flav = dbg and dev_gdtest = gdtest.
@
text
@d3 1
a3 1
# $Revision: 1.16 $
d5 1
a5 1
# $Date: 1996/09/26 15:20:53 $
d84 1
a84 1
        emode.h grs.h bitmap.h canvas.h screen.h mode.h \
d90 1
a90 1
        rgb.h \
@


1.16
log
@Added 400x300 and 512x384 modes.
@
text
@d3 1
a3 1
# $Revision: 1.15 $
d5 1
a5 1
# $Date: 1996/09/20 12:37:38 $
d18 2
@


1.15
log
@export astring.h
@
text
@d3 1
a3 1
# $Revision: 1.14 $
d5 1
a5 1
# $Date: 1996/09/09 14:16:10 $
d82 1
a82 1
        grs.h bitmap.h canvas.h screen.h mode.h \
@


1.14
log
@Added various optimized 16 bit inner loops.
@
text
@d3 1
a3 1
# $Revision: 1.13 $
d5 1
a5 1
# $Date: 1996/08/29 09:43:52 $
d79 1
a79 1
DEV2D_HDRS = dev2d.h bitmap.inc cseg.inc dseg.inc gdican.inc
@


1.13
log
@Added initialization routines that use no video hardware.
@
text
@d3 1
a3 1
# $Revision: 1.12 $
d5 1
a5 1
# $Date: 1996/08/22 15:12:18 $
d18 1
a18 1
EXETARGS = gdtest
d50 1
a50 1
        f16il \
@


1.12
log
@Added exportable gdican.inc for use by 3d.
@
text
@d3 1
a3 1
# $Revision: 1.11 $
d5 1
a5 1
# $Date: 1996/08/19 12:23:21 $
d32 1
a32 1
        init svgainit cominit \
d68 3
a70 2
        comdtab vgadtab fl8dtab w32dtab vsadtab \
        comdfcn \
@


1.11
log
@added module for 16 bit clut generation routines.
@
text
@d3 1
a3 1
# $Revision: 1.10 $
d5 1
a5 1
# $Date: 1996/08/07 13:17:06 $
d78 1
a78 1
DEV2D_HDRS = dev2d.h bitmap.inc cseg.inc dseg.inc
@


1.10
log
@Added optimized rsd to flat16 blitter.
@
text
@d3 1
a3 1
# $Revision: 1.9 $
d5 1
a5 1
# $Date: 1996/07/23 09:52:11 $
d39 1
@


1.9
log
@Added module for gr_get_pixel_bm()
@
text
@d2 2
a3 2
# $Source: s:/prj/tech/libsrc/dev2d/rcs/makefile $
# $Revision: 1.8 $
d5 1
a5 1
# $Date: 1996/05/15 16:00:12 $
d48 1
a48 1
        f16fl8 f16mono f16f16 \
d64 1
a64 1
        rsdcvt rsdunpck rsdblt \
@


1.8
log
@Added hflip in place module.
@
text
@d3 1
a3 1
# $Revision: 1.7 $
d5 1
a5 1
# $Date: 1996/05/07 10:35:21 $
d55 1
@


1.7
log
@added astring to irrupt_OBJS
@
text
@d3 1
a3 1
# $Revision: 1.6 $
d5 1
a5 1
# $Date: 1996/04/30 16:13:01 $
d26 1
a26 1
        astring 
d55 1
a55 1
        lpix \
@


1.6
log
@aligned string routines.  flat16 inner loop.
@
text
@d3 1
a3 1
# $Revision: 1.5 $
d5 1
a5 1
# $Date: 1996/04/25 12:36:14 $
d25 2
a26 1
        gdbm gdgbm canvas bitmap grnull
@


1.5
log
@added more flat16 bitmap support.
@
text
@d3 1
a3 1
# $Revision: 1.4 $
d5 1
a5 1
# $Date: 1996/04/22 14:56:52 $
d28 1
a28 1
        bitmap blend gr \
d42 1
a42 1
        fl8fl8 fl8mono fl8bk8 fl8mx \
d47 2
a48 1
        f16fl8 f16mono f16f16 fl8rsd8 \
@


1.4
log
@Added .path.tbl definition.
@
text
@d3 1
a3 1
# $Revision: 1.3 $
d5 1
a5 1
# $Date: 1996/04/11 14:31:18 $
d50 1
a50 1
        genlin genfl8u genmonou \
@


1.3
log
@added genmx and f16bm to irrupt_objs.
@
text
@d2 2
a3 2
# $Source: s:/prj/tech/libsrc/dev2d/RCS/makefile $
# $Revision: 1.2 $
d5 1
a5 1
# $Date: 1996/04/11 14:23:25 $
d91 3
d98 1
@


1.2
log
@Added irrup flags in makefile.
@
text
@d3 1
a3 1
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1996/04/10 17:06:25 $
d21 2
a22 2
        fl8bm bk8bm mxbm \
        genfl8 genf16 genrsd8 \
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
d22 2
a23 1
        genfl8 fl8fl8 fl8bk8 fl8mx \
@
