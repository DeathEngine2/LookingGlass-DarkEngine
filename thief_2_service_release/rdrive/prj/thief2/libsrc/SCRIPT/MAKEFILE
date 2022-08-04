#
# $Source: r:/t2repos/thief2/libsrc/script/makefile,v $
# $Revision: 1.11 $
# $Author: toml $
# $Date: 2000/02/22 19:49:44 $
#
# Makefile for scripting library
#

MAKETOP = $(CWD)

PROJECT = thief2

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = script

script_OBJS = scrptman scrptmod multparm scrptmsg nullsrv \
              scrobj smodinfo persist

script_HDRS = scrptapi.h scrptimp.h scrptsrv.h scrptmm.h scrptbas.h \
              scrptmsg.h scrguid.h multparm.h scrpttyp.h persist.h \
	      scrptmem.h scrptnet.h scrptobj.h

%include $(MRC)\make.rc

