@echo off
rem ******************************************************

if .%_4ver%.==.. goto StartUnder4Dos
if %_env LT 2048 goto EnlargeEnvironment
goto Start

:StartUnder4Dos
:EnlargeEnvironment
4dos /e:4096 /c %0 %1 %2 %3 %4 %5 %6 %7 %8 %9
goto Exit

rem ******************************************************
:Start

echo Building Thief release (%_date, %_time)

loadbtm on
setlocal
unalias *
alias del *del /q
setdos /c%=&
unset /q cflags precomp lcache

rem ******************************************************

call dt.bat


echo Setting environment...
rem call r:\prj\cam\reltools\init.bat
echo    _PRJDRV_ = %_PRJDRV_
echo    _PRJPATH_ = %_PRJPATH_
echo    _DAILYDRV_ = %_DAILYDRV_
echo    _DAILY_ = %_DAILY_
echo    _DAILYCD_ = %_DAILYCD_
echo    _DAILYTHIEF_ = %_DAILYTHIEF_
echo    _DAILYPRJ_ = %_DAILYPRJ_
echo    _ZIPDIR_ = %_ZIPDIR_
echo.


rem **************************************************************
rem remap S: to the copied prjdir 
rem **************************************************************

echos Mapping r:\prj\cam\final1.04 to s: 
map root s:=r:\prj\cam\final1.04


:build

rem **************************************************************
rem        Time to make the donuts
rem **************************************************************

rem ******************************************************
rem The exe wanted for the CD directory should be produced first
rem flav=opt master=playtest produces thief.exe. Note it is renamed
rem ******************************************************

:Thief
s:
cd \prj\cam\src

rem ******************************************************
# first exe is copy protected!!!!!!!
# exe goes to the cd 
rem ******************************************************

echo make -k build dark  FLAV=shp MASTER=SHIPPROT SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark  FLAV=shp MASTER=SHIPPROT SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1>> log.shp
iff not exist thief.exe then
   echo Failed to build thief.exe (cpyprotect)
   grep -i error log.shp
else 
   copy thief.exe r:\prj\cam\final1.04\cd\thief\thief.exe
   copy thief.map r:\prj\cam\final1.04\thief.map
   if exist cpythief.exe rm cpythief.exe
   if exist cpythief.map rm cpythief.map
   mv thief.exe cpythief.exe
   mv thief.map cpythief.map
endiff


rem ******************************************************
# second exe is ship without copy protection
# exe goes to the directory above the cd 
rem ******************************************************

echo make -k build dark  FLAV=shp MASTER=SHIP SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark  FLAV=shp MASTER=SHIP SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1>> log.shp
iff not exist thief.exe then
   echo Failed to build thief.exe (nocpyprotect)
   grep -i error log.shp
else 
   copy thief.exe r:\prj\cam\final1.04\shpthief.exe
   copy thief.map r:\prj\cam\final1.04\shpthief.map
   if exist shpthief.exe rm shpthief.exe
   if exist shpthief.map rm shpthief.map
   mv thief.exe shpthief.exe
   mv thief.map shpthief.map
endiff


rem ******************************************************

rem ******************************************************

:OptDark
s:
cd \prj\cam\src
echo make -k build dark FLAV=opt MASTER=PLAYTEST SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark FLAV=opt MASTER=PLAYTEST SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1 >> log.opt

iff not exist thief.exe then
   echo Failed to build thief.exe (opt)
   grep -i error log.opt
else 
   copy thief.exe r:\prj\cam\final1.04\optthief.exe
   copy thief.map r:\prj\cam\final1.04\optthief.map
   if exist optthief.exe rm optthief.exe
   if exist optthief.map rm optthief.exe
   mv thief.exe optthief.exe
   mv thief.map optthief.map
endiff


rem ******************************************************
rem pure dbg  build 
rem ******************************************************

:DebugDark
s:
cd \prj\cam\src
echo make -k build dark  FLAV=dbg MASTER=dbg SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1

make -k build dark  FLAV=dbg MASTER=dbg SB=s:\prj comp=v50 sys=win32 addres=1  DISPLAY_PROGRESS=1 >> log.dbg
iff not exist dbgdark.exe then
   echo Failed to build dbgdark.exe
   grep -i error log.dbg
else 
   copy dbgdark.exe r:\prj\cam\final1.04\dbgdark.exe
   copy dbgdark.pdb r:\prj\cam\final1.04\dbgdark.pdb
   if exist dbgdark.exe rm dbgdark.exe
endiff

if .%@lower[%RunOneStep].==.y. goto Exit


:Exit






