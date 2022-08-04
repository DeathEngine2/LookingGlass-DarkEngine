@echo off
call n:\bin\win95\win95go.bat
call n:\bin\win95\miscdev.bat
call n:\bin\win95\buildsys.bat
if exist o:\bin\winstart.bat call o:\bin\winstart.bat %1 %2 %3 %4 %5 %6 %7 %8 %9
