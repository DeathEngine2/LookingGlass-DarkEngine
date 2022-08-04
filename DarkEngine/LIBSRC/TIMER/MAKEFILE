#
# $Source: x:/prj/tech/libsrc/timer/RCS/makefile $
# $Revision: 2.5 $
# $Author: TOML $
# $Date: 1996/10/21 16:53:11 $
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = timer

irrupt_OBJS = tmrt

tmact.asm       tmd.asm         tminit.asm      tmrem.asm       tmsfreq.asm
tmadd.asm       tmdeact.asm     tmphnd.asm      tmsden.asm      tmsper.asm
tmclose.asm     tmfast.asm      tmrate.asm

timer_OBJS = tmrt \
             tmftab tmlibt tmail \
             tmwin32

timer_dos4g_OBJS = \
    tmact tmd tmadd tmclose tmdeact tmfast tminit tmphnd \
    tmrate tmrem tmsden tmsfreq tmsper

timer_HDRS = timer.h tminit.h

timer.h: tmdecl.h tmftab.h tmmac.h tmd.inc tmflag.inc tmlow.inc tmreg.inc
	%do comp_h h_pre="\#include \<fix.h\>" h_in="$(^,M\.h)" inc_in="$(^,M\.inc)" h_out="$@"

%include $(MRC)\make.rc
