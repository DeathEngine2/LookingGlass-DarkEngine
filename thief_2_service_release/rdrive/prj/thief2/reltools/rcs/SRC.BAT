head	 1.11;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @REM @;


1.11
date	 2000.02.24.19.15.25;  author adurant;  state Exp;
branches ;
next	 1.10;

1.10
date	 2000.02.01.09.36.05;  author adurant;  state Exp;
branches ;
next	 1.9;

1.9
date	 2000.01.31.18.31.19;  author adurant;  state Exp;
branches ;
next	 1.8;

1.8
date	 2000.01.25.15.17.50;  author adurant;  state Exp;
branches ;
next	 1.7;

1.7
date	 1999.12.23.10.37.27;  author adurant;  state Exp;
branches ;
next	 1.6;

1.6
date	 1999.12.08.20.26.36;  author adurant;  state Exp;
branches ;
next	 1.5;

1.5
date	 1999.12.08.16.57.49;  author adurant;  state Exp;
branches ;
next	 1.4;

1.4
date	 1999.12.08.12.02.08;  author adurant;  state Exp;
branches ;
next	 1.3;

1.3
date	 1999.12.07.21.11.34;  author adurant;  state Exp;
branches ;
next	 1.2;

1.2
date	 1999.12.07.21.08.58;  author adurant;  state Exp;
branches ;
next	 1.1;

1.1
date	 1999.10.05.18.29.40;  author adurant;  state Exp;
branches ;
next	 ;


desc
@NOT a good src yet
@


1.11
log
@cd2 goodness
@
text
@@@echo off
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

if .%@@lower[%RunOneStep].==.y. goto Exit

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

@@echo Starting build on %_cwd
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

if .%@@lower[%RunOneStep].==.y. goto Exit

:Depend
s:
cd \prj\thief2\src
make depend sb=s:\prj dark comp=v60
make depend sb=s:\prj hybrid comp=v60

if .%@@lower[%RunOneStep].==.y. goto Exit

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

if .%@@lower[%RunOneStep].==.y. goto Exit

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

if .%@@lower[%RunOneStep].==.y. goto Exit

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

if .%@@lower[%RunOneStep].==.y. goto Exit

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

if .%@@lower[%RunOneStep].==.y. goto Exit

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

if .%@@lower[%RunOneStep].==.y. goto Exit


goto SKUP
rem ******************************************************
rem we do not do dbsdark by default, has to be specified 
rem dbs build (debug but with ship defines) Outputs thief.exe,thief.pdb
rem ******************************************************


:DbsDark
s:
echo make -k build dark  THIEF=THIEF FLAV=dbs MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1

make -k build dark THIEF=THIEF FLAV=dbs MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1

if .%@@lower[%RunOneStep].==.y. goto Exit


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

if .%@@lower[%RunOneStep].==.y. goto Exit

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

if .%@@lower[%RunOneStep].==.y. goto Exit

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






@


1.10
log
@dark, not hybrid editor
@
text
@d36 2
d113 2
a114 2
copy %_PRJPATH_%\src\dark.cfg  %_DAILYTHIEF_%\dark.cfg      >>r:\prj\thief2\reltools\copy.log
copy %_PRJPATH_%\src\cam.cfg  %_DAILYTHIEF_%\cam.cfg      >>r:\prj\thief2\reltools\copy.log
d221 4
d277 1
@


1.9
log
@thief2 nor cam
@
text
@d356 1
a356 1
echo make -k build THIEF=THIEF FLAV=dbg MASTER=editdbg SB=s:\prj comp=v60 sys=win32 portal_dbg=1 DISPLAY_PROGRESS=1
d376 1
a376 1
echo make -k build THIEF=THIEF FLAV=opt MASTER=editprof SB=s:\prj comp=v60 sys=win32 debug_portals=1 DISPLAY_PROGRESS=1
@


1.8
log
@cpysrc uses PRJDRV instead of DAILYDRV now
@
text
@d97 2
a98 1
perl5 %_PRJDRV_%\prj\thief2\reltools\cpysrc.pl -targetroot s:
d104 1
a104 1
copy r:\prj\cam\src\propraw.h  s:\prj\cam\src\propraw.h
d131 1
a131 1
mkdirs %_DAILYPRJ_%\cam\scripts\rel_h >& nul
d133 1
a133 1
echo xcopy x:\prj\tech\h\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
d135 1
a135 1
xcopy r:\prj\cam\scripts\rel_h\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
d161 1
a161 1
cd \prj\cam\libsrc\ref
d192 1
a192 1
cd \prj\cam\src
d221 1
a221 1
cd \prj\cam\src
d243 12
a254 12
call r:\prj\cam\reltools\buildscr.bat ..\src\miss09 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\gen /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\victory /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss1 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss4 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\convict /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss7 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\traps /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\evidence /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\gizmo /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\archer /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss10 /o >> log.scr
d263 1
a263 1
cd \prj\cam\src
d286 1
a286 1
cd \prj\cam\src
d310 1
a310 1
cd \prj\cam\src
d355 1
a355 1
cd \prj\cam\src
d375 1
a375 1
cd \prj\cam\src
@


1.7
log
@dbgdrom now built with master=editdbg, recognizes thief2.exe
@
text
@d97 1
a97 1
perl5 %_DAILYDRV_%\prj\thief2\reltools\cpysrc.pl -targetroot s:
@


1.6
log
@THIEF=THIEF
@
text
@d227 2
a228 2
   copy thief.exe %_DAILYTHIEF_%\thief.exe
   copy thief.map %_DAILYDIR_%\thief.map
d265 2
a266 2
iff not exist thief.exe then
   echo Failed to build thief.exe (shp)
d269 2
a270 2
   copy thief.exe %_DAILYDIR_%\shpthief.exe
   copy thief.map %_DAILYDIR_%\shpthief.map
d273 2
a274 2
   mv thief.exe shpthief.exe
   mv thief.map shpthief.map
d280 1
a280 1
rem flav=shp master=SHIP produces thief.exe. note it renamed
d355 2
a356 8
echo make -k build THIEF=THIEF FLAV=dbg MASTER=editor SB=s:\prj comp=v60 sys=win32 portal_dbg=1 DISPLAY_PROGRESS=1
make -k build THIEF=THIEF FLAV=dbg MASTER=editor SB=s:\prj comp=v60 sys=win32 portal_dbg=1 DISPLAY_PROGRESS=1 >>log.edb

if exist dbgdrom.exe rm dbgdrom.exe
if exist dbgdrom.pdb rm dbgdrom.pdb

mv dromed.exe dbgdrom.exe >> log.edb
mv dromed.pdb dbgdrom.pdb >> log.edb 
@


1.5
log
@do rel_h copy better
@
text
@d221 2
a222 2
echo make -k build dark  FLAV=shp MASTER=SHIPPROT SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark  FLAV=shp MASTER=SHIPPROT SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1>> log.spp
d263 2
a264 2
echo make -k build dark  FLAV=shp MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark  FLAV=shp MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1>> log.shp
d286 2
a287 2
echo make -k build dark FLAV=opt MASTER=PLAYTEST SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark FLAV=opt MASTER=PLAYTEST SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1 >> log.opt
d310 1
a310 1
echo make -k build dark  FLAV=dbg MASTER=dbg SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1
d312 1
a312 1
make -k build dark  FLAV=dbg MASTER=dbg SB=s:\prj comp=v60 sys=win32 addres=1  DISPLAY_PROGRESS=1 >> log.dbg
d334 1
a334 1
echo make -k build dark  FLAV=dbs MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1
d336 1
a336 1
make -k build dark  FLAV=dbs MASTER=SHIP SB=s:\prj comp=v60 sys=win32 addres=1 DISPLAY_PROGRESS=1
d355 2
a356 2
echo make -k build FLAV=dbg MASTER=editor SB=s:\prj comp=v60 sys=win32 portal_dbg=1 DISPLAY_PROGRESS=1
make -k build FLAV=dbg MASTER=editor SB=s:\prj comp=v60 sys=win32 portal_dbg=1 DISPLAY_PROGRESS=1 >>log.edb
d381 2
a382 2
echo make -k build FLAV=opt MASTER=editprof SB=s:\prj comp=v60 sys=win32 debug_portals=1 DISPLAY_PROGRESS=1
make -k build FLAV=opt MASTER=editprof SB=s:\prj comp=v60 sys=win32 debug_portals=1 DISPLAY_PROGRESS=1 >> log.dro
@


1.4
log
@uses v60 instead of v50 now
@
text
@d134 1
a134 46
xcopy x:\prj\tech\h\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
rem for the designers 
xcopy x:\prj\tech\h\*.h %_PRJPATH_%\scripts\rel_h /q


echo xcopy %_DAILYPRJ_%\cam\h\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\h\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\h\*.h %_PRJPATH_%\scripts\rel_h /q

echo xcopy %_DAILYPRJ_%\cam\src\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\*.h %_PRJPATH_%\scripts\rel_h /q

echo xcopy %_DAILYPRJ_%\cam\src\ai\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\ai\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\ai\*.h %_PRJPATH_%\scripts\rel_h /q

echo xcopy %_DAILYPRJ_%\cam\src\dark\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\dark\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\dark\*.h %_PRJPATH_%\scripts\rel_h /q

echo xcopy %_DAILYPRJ_%\cam\src\shock\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\shock\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\shock\*.h %_PRJPATH_%\scripts\rel_h /q


echo xcopy %_DAILYPRJ_%\cam\src\physics\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\physics\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\physics\*.h %_PRJPATH_%\scripts\rel_h /q


echo xcopy %_DAILYPRJ_%\cam\src\motion\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\motion\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\motion\*.h %_PRJPATH_%\scripts\rel_h /q

echo xcopy %_DAILYPRJ_%\cam\src\editor\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\editor\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\editor\*.h %_PRJPATH_%\scripts\rel_h /q

echo xcopy %_DAILYPRJ_%\cam\src\csg\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\csg\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\csg\*.h %_PRJPATH_%\scripts\rel_h /q

echo xcopy %_DAILYPRJ_%\cam\src\portal\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\portal\*.h %_DAILYPRJ_%\cam\scripts\rel_h /q
xcopy %_DAILYPRJ_%\cam\src\portal\*.h %_PRJPATH_%\scripts\rel_h /q
@


1.3
log
@fixed cpysrc call
@
text
@d207 1
a207 1
make depend flav=dbg sb=s:\prj comp=v50
d209 9
a217 9
make build flav=dbg sb=s:\prj comp=v50
make build flav=opt sb=s:\prj comp=v50
make build flav=shp sb=s:\prj comp=v50
make build flav=dbs sb=s:\prj comp=v50

make local flav=dbg sb=s:\prj comp=v50
make local flav=opt sb=s:\prj comp=v50
make local flav=shp sb=s:\prj comp=v50
make local flav=dbs sb=s:\prj comp=v50
d220 1
a220 1
make depend flav=dbg sb=s:\prj comp=v50
d222 9
a230 9
make build flav=dbg sb=s:\prj comp=v50
make build flav=opt sb=s:\prj comp=v50
make build flav=shp sb=s:\prj comp=v50
make build flav=dbs sb=s:\prj comp=v50

make local flav=dbg sb=s:\prj comp=v50
make local flav=opt sb=s:\prj comp=v50
make local flav=shp sb=s:\prj comp=v50
make local flav=dbs sb=s:\prj comp=v50
d237 2
a238 2
make depend sb=s:\prj dark comp=v50
make depend sb=s:\prj hybrid comp=v50
d266 2
a267 2
echo make -k build dark  FLAV=shp MASTER=SHIPPROT SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark  FLAV=shp MASTER=SHIPPROT SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1>> log.spp
d308 2
a309 2
echo make -k build dark  FLAV=shp MASTER=SHIP SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark  FLAV=shp MASTER=SHIP SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1>> log.shp
d331 2
a332 2
echo make -k build dark FLAV=opt MASTER=PLAYTEST SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1
make -k build dark FLAV=opt MASTER=PLAYTEST SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1 >> log.opt
d355 1
a355 1
echo make -k build dark  FLAV=dbg MASTER=dbg SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1
d357 1
a357 1
make -k build dark  FLAV=dbg MASTER=dbg SB=s:\prj comp=v50 sys=win32 addres=1  DISPLAY_PROGRESS=1 >> log.dbg
d379 1
a379 1
echo make -k build dark  FLAV=dbs MASTER=SHIP SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1
d381 1
a381 1
make -k build dark  FLAV=dbs MASTER=SHIP SB=s:\prj comp=v50 sys=win32 addres=1 DISPLAY_PROGRESS=1
d400 2
a401 2
echo make -k build FLAV=dbg MASTER=editor SB=s:\prj comp=v50 sys=win32 portal_dbg=1 DISPLAY_PROGRESS=1
make -k build FLAV=dbg MASTER=editor SB=s:\prj comp=v50 sys=win32 portal_dbg=1 DISPLAY_PROGRESS=1 >>log.edb
d426 2
a427 2
echo make -k build FLAV=opt MASTER=editprof SB=s:\prj comp=v50 sys=win32 debug_portals=1 DISPLAY_PROGRESS=1
make -k build FLAV=opt MASTER=editprof SB=s:\prj comp=v50 sys=win32 debug_portals=1 DISPLAY_PROGRESS=1 >> log.dro
@


1.2
log
@thief2 instead of cam where appropriate
@
text
@d97 1
a97 1
perl5 %_DAILYDRV_%\prj\thief2\reltools\cpysrc.pl -targetroot s:\
@


1.1
log
@Initial revision
@
text
@d29 1
a29 1
call r:\prj\cam\reltools\init.bat
d49 2
a50 2
echos Mapping %_DAILYDRV_%\PRJ\CAM\DAILY to s: 
map root s:=%_DAILYDRV_%\PRJ\CAM\DAILY
a72 1
   InstallList
d97 1
a97 1
perl5 %_DAILYDRV_%\prj\cam\reltools\cpysrc.pl -targetroot %_DAILYDRV_%\prj\cam\daily
d101 3
a103 3
copy x:\prj\tech\h\dbgmacro.h  r:\prj\cam\daily\prj\tech\h\dbgmacro.h
copy x:\prj\tech\h\memmacro.h  r:\prj\cam\daily\prj\tech\h\memmacro.h
copy r:\prj\cam\src\propraw.h  r:\prj\cam\daily\prj\cam\src\propraw.h
d110 2
a111 2
copy %_PRJPATH_%\src\dark.cfg  %_DAILYTHIEF_%\dark.cfg      >>r:\prj\cam\reltools\copy.log
copy %_PRJPATH_%\src\cam.cfg  %_DAILYTHIEF_%\cam.cfg      >>r:\prj\cam\reltools\copy.log
d119 4
a122 4
copy %_PRJPATH_%\src\dark.bnd   r:\prj\cam\reltools\bnd\eng\dark.bnd    >> r:\prj\cam\reltools\copy.log
copy %_PRJPATH_%\src\quake.bnd  r:\prj\cam\reltools\bnd\eng\quake.bnd   >> r:\prj\cam\reltools\copy.log
copy %_PRJPATH_%\src\unreal.bnd r:\prj\cam\reltools\bnd\eng\unreal.bnd  >> r:\prj\cam\reltools\copy.log
copy %_PRJPATH_%\src\cfg????.bnd r:\prj\cam\reltools\bnd\eng\saves  >> r:\prj\cam\reltools\copy.log
d285 1
a285 1
cd \prj\cam\scripts\osm
a286 7
call r:\prj\cam\reltools\buildscr.bat ..\src\miss01 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss02 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss03 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss04 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss05 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss06 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss07 /o >> log.scr
d288 10
a298 4
call r:\prj\cam\reltools\buildscr.bat ..\src\miss11 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss12 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss13 /o >> log.scr
call r:\prj\cam\reltools\buildscr.bat ..\src\miss14 /o >> log.scr
a391 2
echo ** NOT BUILDING EDITOR **
goto InstallList
a448 6

:InstallList
s:
cd %_DAILYTHIEF_%

perl5 r:\prj\cam\reltools\mkitype.pl 
@
