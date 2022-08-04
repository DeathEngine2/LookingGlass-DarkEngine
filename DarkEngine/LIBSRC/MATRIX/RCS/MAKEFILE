head	 1.18;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @# @;


1.18
date	 1997.10.07.15.31.05;  author JAEMZ;  state Exp;
branches ;
next	 1.17;

1.17
date	 1997.10.07.00.49.53;  author JAEMZ;  state Exp;
branches ;
next	 1.16;

1.16
date	 1997.08.15.00.42.26;  author dc;  state Exp;
branches ;
next	 1.15;

1.15
date	 1997.08.15.00.33.51;  author dc;  state Exp;
branches ;
next	 1.14;

1.14
date	 1997.08.13.12.56.18;  author DAVET;  state Exp;
branches ;
next	 1.13;

1.13
date	 1997.08.13.11.07.09;  author DAVET;  state Exp;
branches ;
next	 1.12;

1.12
date	 1997.08.12.19.27.49;  author dc;  state Exp;
branches ;
next	 1.11;

1.11
date	 1997.08.12.14.32.14;  author dc;  state Exp;
branches ;
next	 1.10;

1.10
date	 1997.08.12.14.29.27;  author dc;  state Exp;
branches ;
next	 1.9;

1.9
date	 1997.08.12.14.09.32;  author DAVET;  state Exp;
branches ;
next	 1.8;

1.8
date	 1997.08.12.06.59.53;  author dc;  state Exp;
branches ;
next	 1.7;

1.7
date	 1997.06.07.22.42.42;  author dc;  state Exp;
branches ;
next	 1.6;

1.6
date	 1997.03.31.00.06.38;  author JAEMZ;  state Exp;
branches ;
next	 1.5;

1.5
date	 1996.10.21.20.01.45;  author buzzard;  state Exp;
branches ;
next	 1.4;

1.4
date	 1996.09.23.10.32.53;  author JAEMZ;  state Exp;
branches ;
next	 1.3;

1.3
date	 1996.06.13.11.31.21;  author JAEMZ;  state Exp;
branches ;
next	 1.2;

1.2
date	 1995.08.22.14.38.44;  author JAEMZ;  state Exp;
branches ;
next	 1.1;

1.1
date	 1995.08.15.13.56.04;  author JAEMZ;  state Exp;
branches ;
next	 ;


desc
@Makefile for matrix library
@


1.18
log
@Fixed typo
@
text
@#
# $Source: x:/prj/tech/libsrc/matrix/rcs/makefile $
# $Revision: 1.17 $
# $Author: JAEMZ $
# $Date: 1997/10/07 00:49:53 $
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
        @@%set fullpath_for_sed_script = $(.TARGET)

%if ($(LGFIRSTTARGET,lc) == 'build') || ($(LGFIRSTTARGET,lc) == 'depend')
.BEFORE: mxd.sed matrixd.h matrixds.h mxsymd.h
%endif

build_double_version: 
        @@echo Building double version of $(source)
        -@@chmod +w $(target,F)
        @@sed -f $(fullpath_for_sed_script) $(source) > $(target,F)
        @@chmod -w $(target,F)

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

@


1.17
log
@Added vec2
@
text
@d3 3
a5 3
# $Revision: 1.16 $
# $Author: dc $
# $Date: 1997/08/15 00:42:26 $
d24 1
a24 1
        vec2 vecvecd matmatd matvecd vecangd matangd transd 
@


1.16
log
@depend needs to have the sed script too....
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/matrix/RCS/makefile $
# $Revision: 1.15 $
d5 1
a5 1
# $Date: 1997/08/15 00:33:51 $
d23 2
a24 2
        vecvec matmat matvec vecang matang trans transasm dmat \
        vecvecd matmatd matvecd vecangd matangd transd 
d52 3
@


1.15
log
@work on chmod fun
@
text
@d3 3
a5 3
# $Revision: 1.14 $
# $Author: DAVET $
# $Date: 1997/08/13 12:56:18 $
d41 1
a41 1
%if ($(LGFIRSTTARGET,lc) == 'build') 
@


1.14
log
@only need the .before when building, so changed conditional
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/matrix/rcs/makefile $
# $Revision: 1.13 $
d5 1
a5 1
# $Date: 1997/08/13 11:07:09 $
d47 1
a47 1
        -@@chmod +w $(target)
d49 1
a49 1
        @@chmod -w $(target)
@


1.13
log
@Put conditional around the .before
(ugh...)
@
text
@d3 3
a5 3
# $Revision: 1.12 $
# $Author: dc $
# $Date: 1997/08/12 19:27:49 $
d41 1
a41 1
%if ($(LGFIRSTTARGET,lc) != 'install') 
@


1.12
log
@lets do chmod fun
@
text
@d3 1
a3 1
# $Revision: 1.11 $
d5 1
a5 1
# $Date: 1997/08/12 14:32:14 $
d41 1
d43 1
@


1.11
log
@im a goof
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/matrix/RCS/makefile $
# $Revision: 1.10 $
d5 1
a5 1
# $Date: 1997/08/12 14:29:27 $
d45 1
d47 1
a47 2

#        @@chmod -w $(target)
@


1.10
log
@screen cleanup
@
text
@d2 4
a5 4
# $Source: x:/prj/tech/libsrc/matrix/rcs/makefile $
# $Revision: 1.9 $
# $Author: DAVET $
# $Date: 1997/08/12 14:09:32 $
d44 1
a44 1
        @@echo Building double version of $(target)
@


1.9
log
@Now put the generated *d.* files in the current directory as opposed 
to win32 subdir
@
text
@d3 3
a5 3
# $Revision: 1.8 $
# $Author: dc $
# $Date: 1997/08/12 06:59:53 $
d39 1
a39 1
        %set fullpath_for_sed_script = $(.TARGET)
d44 2
a45 2
        @@echo Build double for $(target) (use $(fullpath_for_sed_script))
        sed -f $(fullpath_for_sed_script) $(source) > $(target,F)
@


1.8
log
@hate hate hate hate
double precision sed script hell
@
text
@d3 1
a3 1
# $Revision: 1.7 $
d5 1
a5 1
# $Date: 1997/06/07 22:42:42 $
d36 1
a36 3
build_double_version:
        @@echo Build double for $(target)
        @@sed -f mxd.sed $(source) > $(target)
d38 9
d49 1
a49 1
vecvecd.c: vecvec.c
d52 1
a52 1
matmatd.c: matmat.c
d55 1
a55 1
matvecd.c: matvec.c
d58 1
a58 1
vecangd.c: vecang.c
d61 1
a61 1
matangd.c: matang.c
d64 1
a64 1
transd.c: trans.c
d67 1
a67 1
matrixd.h: matrix.h
d70 1
a70 1
matrixds.h: matrixs.h
d73 1
a73 1
mxsymd.h: mxsym.h
@


1.7
log
@add mxsym to headers list
@
text
@d3 3
a5 3
# $Revision: 1.6 $
# $Author: JAEMZ $
# $Date: 1997/03/31 00:06:38 $
d20 1
a20 2
matrix_OBJS = vecvec matmat matvec vecang matang trans transasm \
        dmat
d22 46
a67 1
matrix_HDRS = matrix.h matrixs.h dmat.h dmats.h mxsym.h
@


1.6
log
@Added double matrix
@
text
@d3 3
a5 3
# $Revision: 1.5 $
# $Author: buzzard $
# $Date: 1996/10/21 20:01:45 $
d23 1
a23 1
matrix_HDRS = matrix.h matrixs.h dmat.h dmats.h
@


1.5
log
@transformation asm
@
text
@d3 3
a5 3
# $Revision: 1.4 $
# $Author: JAEMZ $
# $Date: 1996/09/23 10:32:53 $
d20 2
a21 1
matrix_OBJS = vecvec matmat matvec vecang matang trans transasm
d23 1
a23 1
matrix_HDRS = matrix.h matrixs.h
@


1.4
log
@Added vector rotating
@
text
@d3 1
a3 1
# $Revision: 1.3 $
d5 1
a5 1
# $Date: 1996/06/13 11:31:21 $
d20 1
a20 1
matrix_OBJS = vecvec matmat matvec vecang matang trans 
@


1.3
log
@Added matrixs.h
@
text
@d2 2
a3 2
# $Source: s:/prj/tech/libsrc/matrix/rcs/makefile $
# $Revision: 1.2 $
d5 1
a5 1
# $Date: 1995/08/22 14:38:44 $
d20 1
a20 1
matrix_OBJS = vecvec matmat matvec matang trans 
@


1.2
log
@Added matang and trans
@
text
@d2 2
a3 2
# $Source: t:/prj/tech/libsrc/matrix/rcs/makefile $
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1995/08/15 13:56:04 $
d22 1
a22 1
matrix_HDRS = matrix.h
@


1.1
log
@Initial revision
@
text
@d2 2
a3 2
# $Source: r:/prj/lib/src/3d/rcs/makefile $
# $Revision: 1.34 $
d5 1
a5 1
# $Date: 1995/07/20 20:21:48 $
d20 1
a20 1
matrix_OBJS = matmat vecvec matvec
@
