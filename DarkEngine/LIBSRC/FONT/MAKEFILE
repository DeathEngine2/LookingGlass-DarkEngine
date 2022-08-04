#
# $Source: x:/prj/tech/libsrc/font/RCS/makefile $
# $Revision: 1.2 $
# $Author: KEVIN $
# $Date: 1997/01/23 14:43:37 $
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
	$(eko1) $(@,F) \<-- $(?,F)
	%do comp_h h_pre="\#include \<dev2d.h\>" h_in="$^" h_out="$(@,F)"

TBU_TARGS = ftest

%foreach t $(TBU_TARGS)
$t_OBJS = $t
$t_LIBS = font grtb g2 dev2d mprintf lg fix fault uvbelib pmode
%end

%include $(MRC)\make.rc

# this rule generates foo.c files from foo.tbl
%.c .MISER .NODEFAULT: %.tbl
        @tblmunge $(<,F) $(MAKETOP)\$(@,F)
