rem **************************************************************
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


