#
# $Source: x:/prj/tech/libsrc/g2/RCS/makefile $
# $Revision: 1.30 $
# $Author: KEVIN $
# $Date: 1998/04/28 14:52:20 $
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
	$(eko1) $(@,F) \<-- $(?,F)
	%do comp_h h_pre="\#include \<dev2d.h\>" h_in="$^" h_out="$(@,F)"

%include $(MRC)\make.rc
