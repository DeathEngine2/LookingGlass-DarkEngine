head	 1.5;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @REM @;


1.5
date	 2000.03.04.10.00.34;  author adurant;  state Exp;
branches ;
next	 1.4;

1.4
date	 2000.03.03.23.31.20;  author adurant;  state Exp;
branches ;
next	 1.3;

1.3
date	 2000.02.08.23.13.23;  author adurant;  state Exp;
branches ;
next	 1.2;

1.2
date	 1999.10.13.11.55.33;  author adurant;  state Exp;
branches ;
next	 1.1;

1.1
date	 1999.10.05.18.29.19;  author adurant;  state Exp;
branches ;
next	 ;


desc
@initcon.bat
dir
@


1.5
log
@fixed crf path thing
@
text
@rem ******************************************************

if .%_4ver%.==.. goto StartUnder4Dos
if %_env LT 2048 goto EnlargeEnvironment
goto Start

:StartUnder4Dos
:EnlargeEnvironment
4dos /e:4096 /c %0 %1 %2 %3 %4 %5 %6 %7 %8 %9
goto Exit

rem ******************************************************
:Start

loadbtm on
unalias *
alias del *del /q
setdos /c%=&
unset /q cflags precomp


rem **************************************************************
rem the drives where the dark project lives and where we are building

iff .%BLDDRV%. != .. then
set _BLDDRV_=%BLDDRV%
else 
set  _BLDDRV_=c:
endiff 

set _PRJDRV_=r:
rem **************************************************************
rem the path to the dark tree on the net

set _PRJPATH_=%_PRJDRV_%\prj\thief2
set _SRCPATH_=%_PRJDRV_%\prj\cam\src
set _MISPATH_=%_PRJDRV_%\prj\thief2\levels\shipping
set _ARTPATH_=%_PRJDRV_%\prj\cam\art
set _ARTPATH2_=%_PRJDRV_%\prj\thief2\art
set _MOVIEPATH_=%_PRJDRV_%\prj\thief2\art\finals\movies
set _NEWPATH_=%_PRJDRV_%\prj\thief2

rem **************************************************************
rem set the names of the daily, the daily\cd, the daily\cd\thief
rem and the prj subdirs

set _DAILY_=%_BLDDRV_%\prj\thief2\daily
set _DAILYCD_=%_DAILY_%\cd1
set _DAILYTHIEF_=%_DAILYCD_%\thief2
set _MAINCRFPATH_=%_DAILYTHIEF_%\res

set _DAILYCD2_=%_DAILY_%\cd2
set _DAILYTHIEFCD2_=%_DAILYCD2_%\thief2
set _DAILYPRJ_=%_DAILY_%\PRJ 

set _ZIPDIR_=%_BLDDRV_%\zips

echo _DAILY_ is %_DAILY_%

rem  make the release directory.  
mkdirs %_DAILYTHIEF_%
mkdirs %_DAILYTHIEFCD2_%
mkdirs %_DAILYPRJ_%

:Exit


@


1.4
log
@res files deeper
@
text
@d50 1
a50 1
set _MAINCRFPATH_=%_DAILYTHIEF_\res
@


1.3
log
@2 cd
@
text
@d50 1
@


1.2
log
@something was very screwy about copying thief2 art.  probably my fault.
should be fixed now
@
text
@d51 1
a51 2
rem for now, cd1 and cd2 are the same.
set _DAILYCD2_=%_DAILY_%\cd1
@


1.1
log
@Initial revision
@
text
@d39 1
@
