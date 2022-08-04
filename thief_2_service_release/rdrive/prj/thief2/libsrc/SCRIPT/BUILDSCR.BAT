@echo off
rem ============================================================
rem
rem $Header: r:/t2repos/thief2/libsrc/script/buildscr.bat,v 1.16 1998/09/11 15:32:12 XEMU Exp $
rem Script builder
rem
rem ============================================================

if .%_4ver%.==.. goto StartUnder4Dos
if %_env LT 2048 goto EnlargeEnvironment
gosub Main
goto Quit

:StartUnder4Dos
:EnlargeEnvironment
4dos /e:4096 /c %0 %1 %2 %3 %4 %5 %6 %7 %8 %9
goto Exit

rem ------------------------------------------------------------
rem
rem Main routine
rem
rem ------------------------------------------------------------

:Main

    rem --- Switch to memory resident mode and localize environment
    loadbtm on
    setlocal
    unalias *
    setdos /c%=&

    rem --- Handle command line
    iff .%1. == .. then
      echo Must specify a target
      quit
    endiff

    iff .%@ext[%1]. == .. then
        set target=%1.scr
    else
        set target=%1
    endiff

    set PrjInclude=.;%sb%\cam\src;%sb%\cam\src\ai;%sb%\cam\src\dark;%sb%\cam\src\shock;%sb%\cam\src\physics;r:\prj\cam\src;r:\prj\cam\src\portal;r:\prj\cam\src\ai;r:\prj\cam\src\dark;r:\prj\cam\src\shock;r:\prj\cam\src\physics;%sb%\cam\h;r:\prj\cam\h
    set PrjFlags=/FI"drkscrpt.h"
    set PrjDesignRel=.;%sb%\cam\scripts\src;r:\prj\cam\scripts\src;r:\prj\cam\scripts\rel_h
    
    iff exist buildscr.cfg then
      set /r buildscr.cfg
    endiff

    if not defined Programmer set PrjInclude=%PrjDesignRel%
    
    set path=p:\v42\bin
    iff not defined Programmer then
       set include=.;%PrjInclude%;p:\v42\include
    else
       set include=.;%PrjInclude%;\prj\tech\h;x:\prj\tech\h;p:\v42\include
    endiff
    set lib=x:\prj\tech\lib\WIN32\v42\a611\opt;p:\v42\lib

    echo %target /Zp1 /FI"scrptimp.h" %PrjFlags% /DSCRIPT /DSCRIPT_MAIN_MODULE /DSTRICT /MT /TP /D_WIN32 /D_WINDLL > buildscr.tmp
    echo /Fe"%@name[%target].osm" >> buildscr.tmp
    iff .%2. == ./o. then
       echo /LD >> buildscr.tmp
       echo /link "/incremental:no /map lg.lib cpptools.lib mprintf.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib" >> buildscr.tmp
    else
       echo /Z7 /LDd >> buildscr.tmp
       echo /link "/debugtype:cv /pdb:NONE /incremental:no /map lg.lib cpptools.lib mprintf.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib" >> buildscr.tmp
    endiff

    echo Compiling script...
    cl /nologo @buildscr.tmp > buildscr.tm2
    n:\bin\win95\grep -i error buildscr.tm2 
    if exist %@name[%target].err del /q %@name[%target].err
    if errorlevel == 0 n:\bin\win95\grep -i error buildscr.tm2 > %@name[%target].err
    echo Done.

    del /q buildscr.tmp
    del /q buildscr.tm2
    del /e /q %@name[%target].lib
    del /e /q %@name[%target].exp
    del /e /q %@name[%target].map
    del /e /q %@name[%target].obj
    del /e /q %@name[%target].pdb

    rem

    return

rem ------------------------------------------------------------

:Quit
    quit

:Exit
