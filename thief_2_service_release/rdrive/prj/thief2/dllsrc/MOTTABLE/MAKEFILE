# $Source: r:/t2repos/thief2/dllsrc/mottable/makefile,v $
# $Revision: 1.2 $
# $Author: kate $
# $Date: 1998/01/08 15:49:44 $
#

#
# THIS ONLY WORKS IF YOU HAVE  TOML_INCLUDE  CONFIG VARIABLE SET. (KJ 1/98)
#

MAKETOP = $(CWD)

PROJECT = cam

%include $(INIT)\env.rc
%include $(INIT)\init.rc

BINLOC=$(SB_PRJ)\bin

DLLTARGS = mottable


#
# DLLs
#

##### mottable.dll

mottable_OBJS = \
        mottable motdata


%include $(MRC)\make.rc

