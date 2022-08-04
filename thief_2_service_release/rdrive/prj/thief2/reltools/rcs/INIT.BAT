head	 1.8;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @REM @;


1.8
date	 2000.02.24.17.53.02;  author adurant;  state Exp;
branches ;
next	 1.7;

1.7
date	 2000.01.31.18.30.50;  author adurant;  state Exp;
branches ;
next	 1.6;

1.6
date	 2000.01.25.15.04.13;  author adurant;  state Exp;
branches ;
next	 1.5;

1.5
date	 2000.01.25.14.59.00;  author adurant;  state Exp;
branches ;
next	 1.4;

1.4
date	 1999.12.11.18.13.53;  author adurant;  state Exp;
branches ;
next	 1.3;

1.3
date	 1999.12.07.21.12.16;  author adurant;  state Exp;
branches ;
next	 1.2;

1.2
date	 1999.10.06.11.09.29;  author adurant;  state Exp;
branches ;
next	 1.1;

1.1
date	 1999.10.05.18.28.58;  author adurant;  state Exp;
branches ;
next	 ;


desc
@init.bat
@


1.8
log
@cd2
@
text
@rem **************************************************************
rem the drive where the dark project lives
set _PRJDRV_=r:

rem **************************************************************
rem the path to dark 

set _PRJPATH_=%_PRJDRV_%\prj\thief2
set _ALTPATH_=%_PRJDRV_%\prj\thief2

rem **************************************************************
rem the drive where the daily will be built (change when testing!)

iff .%DAILYDRV%. != .. then
set _DAILYDRV_=%DAILYDRV%
else
set  _DAILYDRV_=r:
endiff

rem **************************************************************
rem set the names of the daily, the daily\cd, the daily\cd\thief
rem and the prj subdirs

set _DAILY_=%_DAILYDRV_%\prj\thief2\daily
set _DAILYCD_=%_DAILY_%\cd1
set _DAILYTHIEF_=%_DAILYCD_%\thief2
set _DAILYCD2_=%_DAILY_%\cd2
set _DAILYTHIEFCD2_=%_DAILYCD2_%\thief2
set _DAILYPRJ_=%_DAILY_%\PRJ 

set _ZIPDIR_=c:\zips

rem **************************************************************
rem we don't want to use the spun off tree, so check X
rem **************************************************************
 
rem tech has moved... unlikely to be mapped to spun off now.

rem **************************************************************
rem  Lets rock and roll!!
rem **************************************************************

rem  make the release directory.  
mkdirs %_DAILYTHIEF_% >& nul
mkdirs %_DAILYTHIEFCD2_% >& nul
mkdirs %_DAILYPRJ_% >& nul


@


1.7
log
@thief2 not cam
@
text
@d27 2
d45 1
@


1.6
log
@fix dailydrv set
@
text
@d8 1
a8 1
set _PRJPATH_=%_PRJDRV_%\prj\cam
@


1.5
log
@support for alternat dailydrv
@
text
@d15 1
a15 1
set _DAILYDRV_ = %DAILYDRV%
d18 1
@


1.4
log
@don't map to wonderland tech.
@
text
@d14 3
@


1.3
log
@use new tech tree
@
text
@d30 2
a31 2

map root x:=\\wonderland\tech\
@


1.2
log
@added ALTPATH
@
text
@d28 1
a28 1
rem we want to use the spun off tree, so remap X:
d31 1
a31 1
map root x:=\\wonderland\tech\stprj
@


1.1
log
@Initial revision
@
text
@d9 1
@
