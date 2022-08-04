rem @echo off
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
echo.

loadbtm on
setlocal
unalias *
alias del *del /q
setdos /c%=&
unset /q cflags precomp lcache

rem ******************************************************

echo Setting environment...
call r:\prj\thief2\reltools\init.bat
echo    _PRJDRV_ = %_PRJDRV_
echo    _PRJPATH_ = %_PRJPATH_
echo    _DAILYDRV_ = %_DAILYDRV_
echo    _DAILY_ = %_DAILY_
echo    _DAILYCD_ = %_DAILYCD_
echo    _DAILYTHIEF_ = %_DAILYTHIEF_
echo 	_DAILYCD2_ = %_DAILYCD2_
echo	_DAILYTHIEFCD2_ = %_DAILYTHIEFCD2_
echo    _DAILYPRJ_ = %_DAILYPRJ_
echo    _ZIPDIR_ = %_ZIPDIR_
echo.

iff not isdir %_DAILYTHIEF_% .or. not isdir %_DAILYTHIEF_% then
   echo ERROR: Failed to create target directories
   cancel
endiff

rem **************************************************************
rem remap S: to the copied prjdir 
rem **************************************************************

echos Mapping %_DAILY_% to s: 
map root s:=%_DAILY_%
echo.

rem ******************************************************
rem Resume
rem ******************************************************

iff .%1.==.resume. .OR. .%2.==.resume. then

text
Valid resume points are:
   Copy
   Build
   DarkLibs   
   Depend
   Thief (skips dependencies)
   Scripts
   ShpDark
   OptDark
   DebugDark
   DbsDark
   DbgDrom
   Dromed
endtext

   input Resume where? %%WhereResume
   iff .%WhereResume.==.. then
      set WhereResume=build
   endiff

   set RunOneStep=N
   inkey /k"yn" /w30 Run only resumed step (y/N)? %%q

   goto %WhereResume
   cancel
endiff

rem **************************************************************
rem copy the sources!   
rem NOTE!!! Add any new subdirs or libraries to the COPYLIST file
rem **************************************************************

:Copy

echo Copying files to build tree...
echo.

rem perl5 %_PRJDRV_%\prj\thief2\reltools\cpysrc.pl -targetroot s:
perl5 r:\prj\thief2\reltools\cpysrc.pl -targetroot s:


rem until I fix the copy script...
copy x:\prj\tech\h\dbgmacro.h  s:\prj\tech\h\dbgmacro.h
copy x:\prj\tech\h\memmacro.h  s:\prj\tech\h\memmacro.h
copy r:\prj\thief2\src\propraw.h  s:\prj\thief2\src\propraw.h


rem ****************************************************
rem grab the specific .cfg files both to release and to the dailythief
rem ****************************************************

copy %_PRJPATH_%\src\dark.cfg  %_DAILYTHIEFCD2_%\dark.cfg      >>r:\prj\thief2\reltools\copy.log
copy %_PRJPATH_%\src\cam.cfg  %_DAILYTHIEFCD2_%\cam.cfg      >>r:\prj\thief2\reltools\copy.log

rem ****************************************************
rem Hey, new feature! keybinding.  Take the current english one 
rem from src and put it in reltools\bnd\eng.  post.bat will copy lang specific
rem ones from reltools\bnd to the CD. 
rem ****************************************************

copy %_PRJPATH_%\src\dark.bnd   r:\prj\thief2\reltools\bnd\eng\dark.bnd    >> r:\prj\thief2\reltools\copy.log
copy %_PRJPATH_%\src\quake.bnd  r:\prj\thief2\reltools\bnd\eng\quake.bnd   >> r:\prj\thief2\reltools\copy.log
copy %_PRJPATH_%\src\unreal.bnd r:\prj\thief2\reltools\bnd\eng\unreal.bnd  >> r:\prj\thief2\reltools\copy.log
copy %_PRJPATH_%\src\cfg????.bnd r:\prj\thief2\reltools\bnd\eng\saves  >> r:\prj\thief2\reltools\copy.log

rem ****************************************************
rem now populate the \prj\cam\scripts\rel_h with all the .h files
rem dailyprj is r:\prj\cam\daily\prj 
rem ****************************************************


mkdirs %_DAILYPRJ_%\thief2\scripts\rel_h >& nul

echo xcopy x:\prj\tech\h\*.h %_DAILYPRJ_%\thief2\scripts\rel_h /q
rem for the cd
xcopy r:\prj\thief2\scripts\rel_h\*.h %_DAILYPRJ_%\thief2\scripts\rel_h /q

if .%@lower[%RunOneStep].==.y. goto Exit

rem **************************************************************
rem Resuming previous build
rem **************************************************************

:build

rem **************************************************************
rem        Time to make the donuts
rem **************************************************************

rem              target  master  flavor  skup     release
rem dromed.exe : build   opt     editprof y        y
rem ddromed.exe: build   dbg     editor   y        y       (rename to dbgdrom.exe/pdb)
rem dbgdark:     dark    dbg     dbg      n        y       <-- rename dbgthief
rem optdark:     dark    opt     opt      n        y       <-- playtester's build until mid-october, rename thief
rem shpdark:     dark    shp     shp      n        y       <-- playtest after mid-october, rename shpthief


:DarkLibs
s:

@echo Starting build on %_cwd
cd \prj\thief2\libsrc\ref

make depend flav=dbg sb=s:\prj comp=v60

make build flav=dbg sb=s:\prj comp=v60
make build flav=opt sb=s:\prj comp=v60
make build flav=shp sb=s:\prj comp=v60
make build flav=dbs sb=s:\prj comp=v60

make local flav=dbg sb=s:\prj comp=v60
make local flav=opt sb=s:\prj comp=v60
make local flav=shp sb=s:\prj comp=v60
make local flav=dbs sb=s:\prj comp=v60
cd ..\script

make depend flav=dbg sb=s:\prj comp=v60

make build flav=dbg sb=s:\prj comp=v60
make build flav=opt sb=s:\prj comp=v60
make build flav=shp sb=s:\prj comp=v60
make build flav=dbs sb=s:\prj comp=v60

make local flav=dbg sb=s:\prj comp=v60
make local flav=opt sb=s:\prj comp=v60
make local flav=shp sb=s:\prj comp=v60
make local flav=dbs sb=s:\prj comp=v60

if .%@lower[%RunOneStep].==.y. goto Exit

:Depend
s:
cd \prj\thief2\src
make depend sb=s:\prj dark comp=v60
make depend sb=s:\prj hybrid comp=v60

if .%@lower[%RunOneStep].==.y. goto Exit

rem ******************************************************
rem for skups, just skip over the building the playtest exes
rem ******************************************************

if %1a=skupa goto skup
if %2a=skupa goto skup

:NOTSKUP

rem ******************************************************
rem to get the .pdb info for the libraries we build them
rem here.  
rem ******************************************************



rem ******************************************************
rem The exe wanted for the CD directory should be produced first
rem flav=opt master=playtest produces thief.exe. Note it is renamed
rem ******************************************************

rem skip building thief bit

goto ShpDark

:Thief
s:
cd \prj\thief2\src
echo make -k build dark THIEF=THIEF FLAV=shp MASTER=SHIPPROT SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark  THIEF=THIEF FLAV=shp MASTER=SHIPPROT SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1>> log.spp
iff not exist thief.exe then
   echo Failed to build thief.exe (spp)
   grep -i error log.spp
else 
   copy thief.exe %_DAILYTHIEF_%\sppthief.exe
   copy thief.map %_DAILYDIR_%\sppthief.map
   if exist sppthief.exe rm sppthief.exe
   if exist sppthief.map rm sppthief.map
   mv thief.exe sppthief.exe
   mv thief.map sppthief.map
endiff

if .%@lower[%RunOneStep].==.y. goto Exit

goto ShpDark
:Scripts
s:
cd \prj\thief2\scripts\osm
rm *.osm
call r:\prj\thief2\reltools\buildscr.bat ..\src\miss09 /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\gen /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\victory /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\miss1 /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\miss4 /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\convict /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\miss7 /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\traps /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\evidence /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\gizmo /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\archer /o >> log.scr
call r:\prj\thief2\reltools\buildscr.bat ..\src\miss10 /o >> log.scr
copy *.osm %_DAILYTHIEF_%\*.*

if .%@lower[%RunOneStep].==.y. goto Exit

rem ******************************************************

:ShpDark
s:
cd \prj\thief2\src
echo make -k build dark THIEF=THIEF FLAV=shp MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark  THIEF=THIEF FLAV=shp MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1>> log.shp
iff not exist thief2.exe then
   echo Failed to build thief2.exe (shp)
   grep -i error log.shp
else 
   copy thief2.exe %_DAILYDIR_%\shpthief.exe
   copy thief2.exe %_DAILYTHIEFCD2_%\thief2.exe
   copy thief2.map %_DAILYDIR_%\shpthief.map
   if exist shpthief.exe rm shpthief.exe
   if exist shpthief.map rm shpthief.exe
   mv thief2.exe shpthief.exe
   mv thief2.map shpthief.map
endiff

if .%@lower[%RunOneStep].==.y. goto Exit

rem ******************************************************
rem flav=shp master=SHIP produces thief2.exe. note it renamed
rem ******************************************************

:OptDark
s:
cd \prj\thief2\src
echo make -k build dark THIEF=THIEF FLAV=opt MASTER=PLAYTEST SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark THIEF=THIEF FLAV=opt MASTER=PLAYTEST SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1 >> log.opt

iff not exist thief.exe then
   echo Failed to build thief.exe (opt)
   grep -i error log.opt
else 
   copy thief.exe %_DAILYDIR_%\optthief.exe
   copy thief.map %_DAILYDIR_%\optthief.map
   if exist optthief.exe rm optthief.exe
   if exist optthief.map rm optthief.exe
   mv thief.exe optthief.exe
   mv thief.map optthief.map
endiff

if .%@lower[%RunOneStep].==.y. goto Exit

rem ******************************************************
rem pure dbg  build 
rem ******************************************************

:DebugDark
s:
cd \prj\thief2\src
echo make -k build dark THIEF=THIEF FLAV=dbg MASTER=dbg SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1

make -k build dark THIEF=THIEF FLAV=dbg MASTER=dbg SB=s:\prj comp=v60 sys=win32 addres=1  DISPLAY_PROGRESS=1 >> log.dbg
iff not exist dbgdark.exe then
   echo Failed to build dbgdark.exe
   grep -i error log.dbg
else 
   copy dbgdark.exe %_DAILYDIR_%\dbgdark.exe
   copy dbgdark.pdb %_DAILYDIR_%\dbgdark.pdb
   if exist dbgdark.exe rm dbgdark.exe
endiff

if .%@lower[%RunOneStep].==.y. goto Exit


goto SKUP
rem ******************************************************
rem we do not do dbsdark by default, has to be specified 
rem dbs build (debug but with ship defines) Outputs thief.exe,thief.pdb
rem ******************************************************


:DbsDark
s:
echo make -k build dark  THIEF=THIEF FLAV=dbs MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1

make -k build dark THIEF=THIEF FLAV=dbs MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1

if .%@lower[%RunOneStep].==.y. goto Exit


rem ******************************************************
rem SKUP make builds start here!
rem ******************************************************

:SKUP


rem ****************************************************** 
rem dromed.exe  (but name changed to be dbgdrom.exe
rem ****************************************************** 

:DbgDrom
s:
cd \prj\thief2\src
echo make -k build dark THIEF=THIEF FLAV=dbg MASTER=editdbg SB=s:\prj comp=v60 sys=win32 portal_dbg=1 DISPLAY_PROGRESS=1
make -k build THIEF=THIEF FLAV=dbg MASTER=editdbg SB=s:\prj comp=v60 sys=win32 portal_dbg=1 DISPLAY_PROGRESS=1 >>log.edb

iff not exist dbgdrom.exe then
   echo Failed to build dbgdrom.exe
   grep -i error log.edb
else 
   copy dbgdrom.exe %_DAILYDIR_%\dbgdrom.exe
   copy dbgdrom.pdb %_DAILYDIR_%\dbgdrom.pdb
endiff

if .%@lower[%RunOneStep].==.y. goto Exit

rem **************************************************************
rem dromed.exe
rem **************************************************************

:Dromed
s:
cd \prj\thief2\src
echo make -k build dark THIEF=THIEF FLAV=opt MASTER=editprof SB=s:\prj comp=v60 sys=win32 debug_portals=1 DISPLAY_PROGRESS=1
make -k build THIEF=THIEF FLAV=opt MASTER=editprof SB=s:\prj comp=v60 sys=win32 debug_portals=1 DISPLAY_PROGRESS=1 >> log.dro

iff not exist dromed.exe then
   echo Failed to build dromed.exe
   grep -i error log.edb
else 
   copy dromed.exe %_DAILYDIR_%\dromed.exe
endiff

if .%@lower[%RunOneStep].==.y. goto Exit

rem **************************************************************

rem **************************************************************
rem make the .osm files (we wanted to build the dromed.exe first)
rem **************************************************************

rem **************************************************************
rem make the list of files to install
rem note that this is done in both src and content cause one might
rem finish first! 
rem **************************************************************

:Exit






