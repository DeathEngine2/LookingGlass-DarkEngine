call r:\prj\cam\reltools\init.bat


rem **************************************************************
rem copy the sources!   
rem NOTE!!! Add any new subdirs or libraries to the COPYLIST file

rem perl5 %_DAILYDRV_%\prj\cam\reltools\cpysrc.pl -targetroot %_DAILYDRV_%\prj\cam\daily


rem until I fix the copy script... touch dbgmacro.h and memmacro.h
copy x:\prj\tech\h\dbgmacro.h  r:\prj\cam\daily\prj\tech\h\dbgmacro.h
copy x:\prj\tech\h\memmacro.h  r:\prj\cam\daily\prj\tech\h\memmacro.h

rem **************************************************************
rem remap S: to the copied prjdir 

map root s:=%_DAILYDRV_%\PRJ\CAM\DAILY

rem **************************************************************
rem        Time to make the donuts

rem tom wants additional flavers

rem make build dark flav=dbg master=dbg debug_portals=1
rem make build dark flav=opt master=opt <==== thief.exe
rem make build dark flav=shp master=shp 

s:


cd prj\cam\src

make depend sb=s:\prj

make build dark FLAV=opt MASTER=opt SB=s:\prj comp=v42 sys=win32 >> log.opt

rem for now opt is the thief.exe

copy optdark.exe %_DAILYTHIEF_%\thief.exe
copy optdark.pdb %_DAILYTHIEF_%\thief.pdb

make build FLAV=dbg MASTER=editdbg SB=s:\prj comp=v42 sys=win32 PORTAL_DBG=1 >>log.edb


rem **************************************************************
rem the above made ddromed.exe and ddromed.pdb . Copy to the thief directory

make build dark  FLAV=dbg MASTER=dbg SB=s:\prj comp=v42 sys=win32 debug_portals=1

make build dark  FLAV=shp MASTER=shp SB=s:\prj comp=v42 sys=win32 >> log.shp

