#
# $Source: x:/prj/tech/libsrc/matrix/RCS/makefile $
# $Revision: 1.18 $
# $Author: JAEMZ $
# $Date: 1997/10/07 15:31:05 $
#
# Makefile for Matrix library
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = matrix

# line 2 of each of these is the generated double precision stuff

matrix_OBJS = \
        vecvec vec2 matmat matvec vecang matang trans transasm dmat \
        vec2d vecvecd matmatd matvecd vecangd matangd transd 

matrix_HDRS = \
        matrix.h matrixs.h dmat.h dmats.h mxsym.h mxang.h mxcvrt.h \
        matrixd.h matrixds.h mxsymd.h

# zany override fun

# WARNING: do not hand edit *d.c or *d.h
#  they are built from the sed script, which has zany rules
#  see matdbl.txt in libsrc/matrix

.PATH.sed = $(.PATH.c)

mxd.sed .ALWAYS: 
        @%set fullpath_for_sed_script = $(.TARGET)

%if ($(LGFIRSTTARGET,lc) == 'build') || ($(LGFIRSTTARGET,lc) == 'depend')
.BEFORE: mxd.sed matrixd.h matrixds.h mxsymd.h
%endif

build_double_version: 
        @echo Building double version of $(source)
        -@chmod +w $(target,F)
        @sed -f $(fullpath_for_sed_script) $(source) > $(target,F)
        @chmod -w $(target,F)

vecvecd.c .MISER .NODEFAULT: vecvec.c
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

vec2d.c .MISER .NODEFAULT: vec2.c
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

matmatd.c .MISER .NODEFAULT: matmat.c
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

matvecd.c .MISER .NODEFAULT: matvec.c
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

vecangd.c .MISER .NODEFAULT: vecang.c
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

matangd.c .MISER .NODEFAULT: matang.c
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

transd.c .MISER .NODEFAULT: trans.c
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

matrixd.h .MISER .NODEFAULT: matrix.h
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

matrixds.h .MISER .NODEFAULT: matrixs.h
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

mxsymd.h .MISER .NODEFAULT: mxsym.h
        %do build_double_version source=$(.SOURCE) target=$(.TARGET)

%include $(MRC)\make.rc

