head	 1.30;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.30
date	 1998.04.28.14.52.20;  author KEVIN;  state Exp;
branches ;
next	 1.29;

1.29
date	 1998.04.09.09.59.55;  author KEVIN;  state Exp;
branches ;
next	 1.28;

1.28
date	 1998.03.25.15.42.56;  author KEVIN;  state Exp;
branches ;
next	 1.27;

1.27
date	 1998.03.13.13.54.35;  author KEVIN;  state Exp;
branches ;
next	 1.26;

1.26
date	 1998.03.03.12.13.48;  author KEVIN;  state Exp;
branches ;
next	 1.25;

1.25
date	 1997.10.27.14.07.08;  author buzzard;  state Exp;
branches ;
next	 1.24;

1.24
date	 1997.09.30.12.10.31;  author KEVIN;  state Exp;
branches ;
next	 1.23;

1.23
date	 1997.09.23.14.01.30;  author KEVIN;  state Exp;
branches ;
next	 1.22;

1.22
date	 1997.08.28.15.23.55;  author KEVIN;  state Exp;
branches ;
next	 1.21;

1.21
date	 1997.08.28.11.54.26;  author KEVIN;  state Exp;
branches ;
next	 1.20;

1.20
date	 1997.05.16.09.53.42;  author KEVIN;  state Exp;
branches ;
next	 1.19;

1.19
date	 1997.05.05.11.02.46;  author KEVIN;  state Exp;
branches ;
next	 1.18;

1.18
date	 1997.05.01.15.40.25;  author KEVIN;  state Exp;
branches ;
next	 1.17;

1.17
date	 1997.03.12.12.29.29;  author KEVIN;  state Exp;
branches ;
next	 1.16;

1.16
date	 1997.03.11.11.42.38;  author KEVIN;  state Exp;
branches ;
next	 1.15;

1.15
date	 1997.02.24.16.31.30;  author KEVIN;  state Exp;
branches ;
next	 1.14;

1.14
date	 1997.02.18.14.35.21;  author KEVIN;  state Exp;
branches ;
next	 1.13;

1.13
date	 1997.02.07.12.25.05;  author KEVIN;  state Exp;
branches ;
next	 1.12;

1.12
date	 1997.01.31.13.39.30;  author KEVIN;  state Exp;
branches ;
next	 1.11;

1.11
date	 1996.12.11.09.10.46;  author KEVIN;  state Exp;
branches ;
next	 1.10;

1.10
date	 1996.11.13.14.11.25;  author KEVIN;  state Exp;
branches ;
next	 1.9;

1.9
date	 1996.11.07.17.28.37;  author KEVIN;  state Exp;
branches ;
next	 1.8;

1.8
date	 1996.11.04.13.56.53;  author TOML;  state Exp;
branches ;
next	 1.7;

1.7
date	 1996.11.01.09.51.35;  author KEVIN;  state Exp;
branches ;
next	 1.6;

1.6
date	 1996.09.16.11.24.10;  author KEVIN;  state Exp;
branches ;
next	 1.5;

1.5
date	 1996.08.07.13.44.30;  author KEVIN;  state Exp;
branches ;
next	 1.4;

1.4
date	 1996.06.11.14.44.41;  author KEVIN;  state Exp;
branches ;
next	 1.3;

1.3
date	 1996.05.20.10.43.13;  author KEVIN;  state Exp;
branches ;
next	 1.2;

1.2
date	 1996.04.26.10.44.56;  author KEVIN;  state Exp;
branches ;
next	 1.1;

1.1
date	 1996.04.11.10.06.50;  author KEVIN;  state Exp;
branches ;
next	 ;


desc
@g2 library makefile
@


1.30
log
@*** empty log message ***
@
text
@#
# $Source: x:/prj/tech/libsrc/g2/rcs/makefile $
# $Revision: 1.29 $
# $Author: KEVIN $
# $Date: 1998/04/09 09:59:55 $
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = g2

# set_canvas callback is in init.
irrupt_OBJS = \
        init

# all objs related to polygon rendering
POLY_OBJS = \
        grtm permap \
        tmsetup tf \
        genlm fl8lm fl8pm f16lm f16pm \
        genfl8l genf16l genrsdtm \
        o88 lo88 co88 r88 t88oc \
        lo816 \
        lht816 lh816 dlh816 t816oc \
        golftmap shadtmap drytmap shadhack area \
        trigrad trirast \
        genply gensply genrast fl8sply \
        tmapd clip uvgrad

# all objs related to bitmap scaling
SCALE_OBJS = scshell fl8s gens \
        fl8fl8s genfl8s genrsds cc816

# all objs related to sloped line rendering
LINE_OBJS = clplin fl8lin fl8l genline 

# all inner loops (assembly and c)
INNER_LOOP_OBJS = \
        gen8il gen16il \
        o88il o88bil lo88il co88il n88il \
        lo816il

PTMAP_OBJS = \
        ptmap ptmapper ptfloat ptmap_8 ptmap_n ptpersp ptlinear \
        pt_main pt_map pt_duv pt_grad

# function tables compiled from .tbl's
TABLE_OBJS = gencnv fl8cnv f16cnv \
        genlmf genllmf gensf genusf \
        fl8ulf fl8lmf fl8llmf fl8sf fl8usf \
        f16llmf

# miscellaneous primitives, initialization code, and global data
MISC_OBJS = blend init svgainit setdrv g2d g2makewr \
        g2rot g2circ g2el g2ov g2ring point rastel

# legacy code from terra nova; won't be linked into other apps
OLD_CRUFTY_TN_OBJS = chkply chkedges chkedgeb 

G2_OBJS = $(POLY_OBJS) $(SCALE_OBJS) $(LINE_OBJS) $(INNER_LOOP_OBJS) \
        $(TABLE_OBJS) $(PTMAP_OBJS) $(MISC_OBJS) $(OLD_CRUFTY_TN_OBJS)

G2_HDRS= g2.h g2pt.h icanvas.inc

g2.h .REREAD :\
        stupid.h \
	icanvas.h plytyp.h \
        g2spoint.h \
        scancvt.h \
        sftype.h lftype.h tftype.h pftype.h \
        g2d.h g2clip.h \
	grlin.h grtm.h grcurv.h \
	grply.h grscale.h g2tm.h init.h \
        buffer.h blnfcn.h \
        water.h \
        grchkply.h setdrv.h frame.h point.h
	$(eko1) $(@@,F) \<-- $(?,F)
	%do comp_h h_pre="\#include \<dev2d.h\>" h_in="$^" h_out="$(@@,F)"

%include $(MRC)\make.rc
@


1.29
log
@new 8to8 and 8to16 linear mappers.
@
text
@d3 1
a3 1
# $Revision: 1.28 $
d5 1
a5 1
# $Date: 1998/03/25 15:42:56 $
d34 1
a34 1
        tmapd clip 
@


1.28
log
@16 to 16 perspective portal mappers.
@
text
@d3 1
a3 1
# $Revision: 1.27 $
d5 1
a5 1
# $Date: 1998/03/13 13:54:35 $
d26 1
a26 1
        genlm fl8lm fl8pm f16pm \
d29 1
d46 2
a47 1
        o88il o88bil lo88il co88il n88il 
d56 2
a57 1
        fl8ulf fl8lmf fl8llmf fl8sf fl8usf
@


1.27
log
@added g2pt.h
@
text
@d3 1
a3 1
# $Revision: 1.26 $
d5 1
a5 1
# $Date: 1998/03/03 12:13:48 $
d26 1
a26 1
        genlm fl8lm fl8pm \
@


1.26
log
@added scancvt.h to g2.h
@
text
@d3 3
a5 3
# $Revision: 1.25 $
# $Author: buzzard $
# $Date: 1997/10/27 14:07:08 $
d66 1
a66 1
G2_HDRS= g2.h icanvas.inc
@


1.25
log
@Initial revision
@
text
@d3 3
a5 3
# $Revision: 1.24 $
# $Author: KEVIN $
# $Date: 1997/09/30 12:10:31 $
d72 1
@


1.24
log
@further integration of portal texture mappers.
@
text
@d3 1
a3 1
# $Revision: 1.23 $
d5 1
a5 1
# $Date: 1997/09/23 14:01:30 $
d32 1
a32 1
        genply gensply genrast \
@


1.23
log
@added portal texture mappers.
@
text
@d3 1
a3 1
# $Revision: 1.22 $
d5 1
a5 1
# $Date: 1997/08/28 15:23:55 $
d26 1
a26 1
        genlm fl8lm \
d49 1
a49 1
        pt_main pt_map pt_duv
@


1.22
log
@added t816oc.
@
text
@d3 1
a3 1
# $Revision: 1.21 $
d5 1
a5 1
# $Date: 1997/08/28 11:54:26 $
d47 4
d64 1
a64 1
        $(TABLE_OBJS) $(MISC_OBJS) $(OLD_CRUFTY_TN_OBJS)
@


1.21
log
@added c/optimized version of translucent 8 bit texture mapper.
@
text
@d3 1
a3 1
# $Revision: 1.20 $
d5 1
a5 1
# $Date: 1997/05/16 09:53:42 $
d28 2
a29 2
        o88 lo88 co88 t88oc r88 \
        lht816 lh816 dlh816 \
@


1.20
log
@new tmapping regime.
@
text
@d3 1
a3 1
# $Revision: 1.19 $
d5 1
a5 1
# $Date: 1997/05/05 11:02:46 $
d28 1
a28 1
        o88 lo88 co88 t88oc \
@


1.19
log
@adjustments to new tmapping system.
@
text
@d3 1
a3 1
# $Revision: 1.18 $
d5 1
a5 1
# $Date: 1997/05/01 15:40:25 $
d22 10
a31 21
G2_OBJS = \
        blend \
        init svgainit \
        setdrv g2d calcd \
        chkply chkedges chkedgeb \
        clplin clip clip2d \
        fl8cnv \
        fl8sf fl8usf fl8s \
        fl8fl8s fl8il \
        fl8lin fl8ulf fl8l \
        fl8lm fl8lmf fl8llmf \
        fl8fl8l fl8fl8ll \
        f16cnv \
        f16sf f16usf f16s \
        f16llmf f16lmf f16lm f16fl8ll \
        gencnv \
        gensf genusf gens \
        genline \
        genfl8s genrsds genrsdtm \
        genf16s genfl8l genf16l \
        genil gensil genlil \
d33 28
a60 14
        genlm genlmf genllmf \
        g2poly g2tm g2rot \
        g2circ g2el g2ov g2ring \
        g2makewr grwater \
        lmap permap point \
        raster rastel scale \
        sply tmapd trifan \
        fl8o2ni fl8nni fl8o2wi fl8lo2wi \
        trigrad trirast \
        golftmap shadtmap drytmap lht816 lh816 dlh816 \
        cc816 scshell \
        shadhack \
        o2w88i area \
        o88 o88il tf
d71 1
a71 1
	grply.h grscale.h init.h \
@


1.18
log
@added new stuff.
@
text
@d3 1
a3 1
# $Revision: 1.17 $
d5 1
a5 1
# $Date: 1997/03/12 12:29:29 $
d43 1
a43 1
        genply gensply \
@


1.17
log
@Added new regime scaler.
@
text
@d3 1
a3 1
# $Revision: 1.16 $
d5 1
a5 1
# $Date: 1997/03/11 11:42:38 $
d52 1
a52 1
        trigrad trirast plyshell \
d56 2
a57 1
        o2w88i area
@


1.16
log
@Optimizied lit haze texture mappers.
@
text
@d3 1
a3 1
# $Revision: 1.15 $
d5 1
a5 1
# $Date: 1997/02/24 16:31:30 $
d54 1
@


1.15
log
@added shadhack module for golf.  fester.
@
text
@d3 1
a3 1
# $Revision: 1.14 $
d5 1
a5 1
# $Date: 1997/02/18 14:35:21 $
d53 1
a53 1
        golftmap shadtmap drytmap lh816 dlh816 \
@


1.14
log
@added new tmaping modules.
@
text
@d3 1
a3 1
# $Revision: 1.13 $
d5 1
a5 1
# $Date: 1997/02/07 12:25:05 $
d54 1
@


1.13
log
@Added point drawing module.
@
text
@d3 1
a3 1
# $Revision: 1.12 $
d5 1
a5 1
# $Date: 1997/01/31 13:39:30 $
d53 2
a54 1
        golftmap shadtmap drytmap lh816 area
@


1.12
log
@Added floating pt persp mapper.
@
text
@d3 1
a3 1
# $Revision: 1.11 $
d5 1
a5 1
# $Date: 1996/12/11 09:10:46 $
d47 2
a48 3
        g2makewr \
        grwater \
        lmap permap \
d67 1
a67 1
        grchkply.h setdrv.h frame.h
@


1.11
log
@added lit hazed flat8 texture to flat16 canvas mapper.
@
text
@d3 1
a3 1
# $Revision: 1.10 $
d5 1
a5 1
# $Date: 1996/11/13 14:11:25 $
d27 1
a27 1
        clplin clip2d \
d49 1
a49 1
        lmap \
@


1.10
log
@Added more texture mappers for golf.
@
text
@d3 1
a3 1
# $Revision: 1.9 $
d5 1
a5 1
# $Date: 1996/11/07 17:28:37 $
d54 1
a54 1
        golftmap shadtmap drytmap area
@


1.9
log
@polygon canvas pixel area calculation routines.
@
text
@d3 3
a5 3
# $Revision: 1.8 $
# $Author: TOML $
# $Date: 1996/11/04 13:56:53 $
d47 1
d53 2
a54 2
        trigrad trirast plyshell golftmap \
        g2makewr area
@


1.8
log
@Added MakeFunctionWritable() code
@
text
@d3 3
a5 3
# $Revision: 1.7 $
# $Author: KEVIN $
# $Date: 1996/11/01 09:51:35 $
d53 1
a53 1
        g2makewr
d60 1
a65 1
        g2spoint.h \
@


1.7
log
@Added golftmap module, g2spoint.h.
@
text
@d3 1
a3 1
# $Revision: 1.6 $
d5 1
a5 1
# $Date: 1996/09/16 11:24:10 $
d52 2
a53 1
        trigrad trirast plyshell golftmap
@


1.6
log
@added generic flat16 bitmap scaling.
@
text
@d3 1
a3 1
# $Revision: 1.5 $
d5 1
a5 1
# $Date: 1996/08/07 13:44:30 $
d51 2
a52 1
        fl8o2ni fl8nni fl8o2wi fl8lo2wi
d64 1
@


1.5
log
@Added generic rsd unpack and texture functions.
@
text
@d2 2
a3 2
# $Source: s:/prj/tech/libsrc/g2/rcs/makefile $
# $Revision: 1.4 $
d5 1
a5 1
# $Date: 1996/06/11 14:44:41 $
d41 1
a41 1
        genfl8l genf16l \
@


1.4
log
@Added rotation module to g2.lib, Added g2clip.h to g2.h.
@
text
@d3 1
a3 1
# $Revision: 1.3 $
d5 1
a5 1
# $Date: 1996/05/20 10:43:13 $
d40 1
a40 1
        genfl8s genrsds \
@


1.3
log
@Added flat16 canvas modules.  Eliminated cominit.
@
text
@d3 1
a3 1
# $Revision: 1.2 $
d5 1
a5 1
# $Date: 1996/04/26 10:44:56 $
d45 1
a45 1
        g2poly g2tm \
d59 1
a59 1
        g2d.h \
@


1.2
log
@Added wrapping support and flat16 bitmap support.
@
text
@d3 1
a3 1
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1996/04/11 10:06:50 $
d24 1
a24 1
        init svgainit cominit \
d34 3
a68 6

# this rule generates foo.c files from foo.tbl
%.c .MISER .NODEFAULT: %.tbl
        @@%setenv INCLUDE=$(IPATH)        
	$(eko1) $(@@,F) \<-- nonexistent
        @@tblmunge $(<,F) $(MAKETOP)\$(@@,F)
@


1.1
log
@Initial revision
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/2d/rcs/makefile $
# $Revision: 2.3 $
d5 1
a5 1
# $Date: 1995/11/09 16:29:57 $
d37 2
a38 1
        genfl8s genrsds genfl8l \
@
