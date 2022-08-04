@echo off
npathmk
if errorlevel==1 goto batch_set_path
if errorlevel==0 goto already_set_path
goto failed_to_set

:batch_set_path
echo set path from batch file....
call c:\bin\curpath.bat
goto to_end

:failed_to_set
echo Failed to set the path, sorry
goto to_end

rem This means that pathmk dealt all by itself
:already_set_path
echo path made internally

:to_end
