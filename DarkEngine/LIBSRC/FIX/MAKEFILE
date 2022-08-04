# $Source: x:/prj/tech/libsrc/fix/RCS/makefile $
# $Revision: 2.4 $
# $Author: TOML $
# $Date: 1997/04/24 13:58:58 $

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = fix

# need to deal with making trigtab.c  with fmaketab !!

fix_OBJS = fix fix_pow fixsprnt fix_asm atofix fix24 f_exp trigtab \
        fixdiv safefix

irrupt_OBJS = fix

fix_HDRS = fix.h altfix.h fix.inc safefix.h

%include $(MRC)\make.rc
