@echo off
rem first, map the drives
if %windir%a==a goto windir_not_set
goto mod_them_paths

rem DC i bet we could do this and all would work
rem :windir_not_set
rem set windir=c:\windows

:mod_them_paths               
rem next, lets get some path

path n:\bin\win95;n:\bin

if %OS%a==Windows_NTa goto NTsetup

:95setup
pathmod OS_PATH %windir%\command
goto finPath
:NTsetup
pathmod OS_PATH %windir%\system32
set NOMAP=NOMAP
echo Setting NOMAP so build will work under NT shell

:finPath
pathmod NET_PATH n:\bin\win95;n:\bin;m:\public;m:\system
pathmod WIN_PATH %windir%
call pathmk

goto done

:windir_not_set
echo Enviroment variable windir must be set.

:done
