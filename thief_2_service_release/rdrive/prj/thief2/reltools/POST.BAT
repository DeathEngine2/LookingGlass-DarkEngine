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

loadbtm on
unalias *
alias del *del /q
setdos /c%=&
unset /q cflags precomp

rem ******************************************************

echo %1a
if %1a=a goto english
if %1a=englisha goto english
if %1a=frencha goto french
if %1a=germana goto german
if %1a=britisha goto british
if %1a=japanesea goto japanese
rem if you get here, you typed something wrong

@echo Something is wrong.  usage is content [english french german british]
goto Exit

rem ******************************************************
rem Please note!  lcode refers to language such as eng (english) 
rem or frn (french).  Country refers to the country to which the 
rem installer is destined to be sold in, such as gbr (Great Britian) 
rem or jpn (Japan).  The reason for this is that some contries get 
rem an English language installer without some of the features that 
rem the good ole USA gets.  Like the registration url since we 
rem ******************************************************

:english
set _lcode_=eng
set _country_=eng
set _readme_=readme
goto BeginScript

:french
set _lcode_=frn
set _country_=frn
set _readme_=lisezmoi
goto BeginScript

:german
set _lcode_=ger
set _country_=ger
set _readme_=readme
goto BeginScript

rem Always that guy that does not fit the mold... For British we 
rem want basically a eng but with different urls and a different readme

:british
set _lcode_=eng
set _country_=gbr
set _readme_=readme
goto BeginScript

:japanese
set _lcode_=eng
set _country_=jpn  
set _readme_=readme
goto BeginScript
:BeginScript

rem **************************************************************
rem init the variables
rem **************************************************************

call r:\prj\thief2\reltools\init.bat

rem **************************************************************
rem second arg can be the name of the daily directory. For betaFx.x
rem usage would would be post french betafx.x
rem **************************************************************

iff .%2. != .. then
   set _DAILYDIR_=%_DAILYDRV_%\prj\thief2\%2
   set _DAILYCD_=%_DAILYDIR_%\cd1
   set _DAILYTHIEF_=%_DAILYDIR_%\cd1\thief2
   set _DAILYCD2_=%_DAILYDIR_%\cd2
   set _DAILYTHIEFCD2_=%_DAILYDIR_%\cd2\thief2
   set _DAILY_=%2
   mkdirs %_DAILYCD_%\thief2
   mkdirs %_DAILYCD2_%\thief2
else 
   set _DAILY_=daily
endiff

%_DAILYDRV_%

cd %_DAILYCD_%
mkdirs redist\directx\drivers\eng
mkdirs redist\x86

xcopy /s r:\prj\thief2\reltools\redist redist

cd %_DAILYCD2_%
mkdirs redist\directx\drivers\eng
mkdirs redist\x86

xcopy /s r:\prj\thief2\reltools\redist redist

copy r:\prj\thief2\reltools\redist\crt\msvcrt40.dll %_DAILYTHIEF_%

rem **************************************************************
rem if doing a non english verion, then grab it's version
rem Please note that the trailing '%' on the last _lcode_ is not there.
rem 4dos seemed to have a problem evaluating when it was there. Go figure.
rem **************************************************************

iff %_lcode_% != eng then 

cd %_DAILYCD_%
mkdirs redist\directx\drivers\%_lcode_%
xcopy r:\prj\thief2\reltools\redist\directx\drivers\%_lcode_% redist\directx\drivers\%_lcode_

cd %_DAILYCD2_%
mkdirs redist\directx\drivers\%_lcode_%
xcopy r:\prj\thief2\reltools\redist\directx\drivers\%_lcode_% redist\directx\drivers\%_lcode_

endiff 

rem **************************************************************
rem japanese is english as far as _lcode_ is concerned
rem so we test for it and do the right thing. 
rem **************************************************************

iff %_country_% = jpn then 
  mkdirs redist\directx\drivers\jpn
  mkdirs redist\directx\drivers\nec
  xcopy r:\prj\thief2\reltools\redist\directx\drivers\jpn redist\directx\drivers\jpn
  xcopy r:\prj\thief2\reltools\redist\directx\drivers\nec redist\directx\drivers\nec
endiff


rem iv5play on cd2 so it gets done when we switch and stay to cd2
copy  r:\prj\thief2\reltools\iv5play.exe %_DAILYCD2_%
rem lgvid.ax on cd1 so it gets easily installed.
copy  x:\prj\tech\libsrc\actmovie\lgvid\retail\lgvid.ax %_DAILYTHIEF_%

rem **************************************************************
rem the bnd files!  
rem **************************************************************

copy r:\prj\thief2\reltools\bnd\%_lcode_%\dark.bnd %_DAILYTHIEFCD2_%

mkdirs %_DAILYTHIEFCD2_%\saves
copy r:\prj\thief2\reltools\bnd\%_lcode_%\saves\cfg????.bnd %_DAILYTHIEFCD2_%\saves

rem **************************************************************
rem 3dfx drivers  
rem **************************************************************

rem cd %_DAILYCD_%

rem mkdirs drivers\voodoo1
rem mkdirs drivers\voodoo2

rem   r:\prj\campatch\reltools\drivers\voodoo2\rkv2dx6.exe  drivers\voodoo2\rkv2dx6.exe
rem   r:\prj\campatch\reltools\drivers\voodoo1\rkvg.exe  drivers\voodoo1\rkvg.exe


rem **************************************************************
rem the readme.wri file!  (note that it lives in the top level of the CD)
rem note that different localizations have differnt readme's
rem **************************************************************

rem put the readme EVERYWHERE

copy r:\prj\thief2\docs\readme\%_country_%\*.wri %_DAILYCD_%
copy r:\prj\thief2\docs\readme\%_country_%\*.wri %_DAILYTHIEF_%
copy r:\prj\thief2\docs\readme\%_country_%\*.wri %_DAILYCD2_%
copy r:\prj\thief2\docs\readme\%_country_%\*.wri %_DAILYTHIEFCD2_%

rem **************************************************************
rem The urls.  Eidos.url and ets (eidos tech support) are different
rem for each variant. The other three (register, lgt,eidos store) are 
rem identical.  But my .02 says that will change.  We maintain 
rem seperate sets of all five. Now copied to the thief directory
rem so they get installed to the hard drive. This is good for two reasons:
rem 1. No installer work needed since the ilist.X will take care of it, and
rem 2. the top level of the CD has five less files. 
rem **************************************************************

copy r:\prj\thief2\reltools\url\%_country_%\*.url  %_DAILYTHIEFCD2_%
copy r:\prj\thief2\reltools\url\%_country_%\patch.url  %_DAILYTHIEFCD_%
copy r:\prj\thief2\reltools\url\%_country_%\patch.url  %_DAILYCD_%
copy r:\prj\thief2\reltools\url\%_country_%\patch.url  %_DAILYCD2_%

rem **************************************************************
rem put the installer in place
rem **************************************************************

%_PRJDRV_%

cd %_ALTPATH_%\install

make local sb=r:\prj lcode=%_lcode_% COUNTRY=%_country_% INSTALL=%_DAILY_%\cd1

cd %_DAILYCD2_%
xcopy /s r:\prj\thief2\install\cd2\%_lcode_%\* .

rem **************************************************************
rem get the SafeDisc stuff
rem **************************************************************

copy r:\prj\thief2\reltools\safedisc\* %_DAILYTHIEFCD2_%

rem **************************************************************
rem build the dromed portable release
rem **************************************************************

mkdirs %_DAILYCD_%\editor
cd %_DAILYCD_%\editor
copy r:\prj\thief2\reltools\dromread\readme.txt .
copy r:\prj\thief2\release\dromed.exe r:\prj\thief2\reltools\dromrel
copy r:\prj\thief2\release\*.res r:\prj\thief2\reltools\dromrel
pkzip dromed.zip r:\prj\thief2\reltools\dromrel\*.*
pkzip missions.zip r:\prj\thief2\levels\shipping\*.mis
mkdir schema
copy r:\prj\thief2\art\src\schema\*.sch schema
copy r:\prj\thief2\art\src\schema\base.arc schema
copy r:\prj\thief2\art\src\schema\*.spc schema
copy r:\prj\thief2\bin\missblat.exe .
copy r:\prj\thief2\bin\misstrip.exe .
copy r:\prj\thief2\reltools\dromtools\* .
mkdir docs
copy r:\prj\thief2\reltools\dromdocs\* docs


rem **************************************************************
rem build the ilist files
rem **************************************************************

cd %_DAILYCD_%\thief2

perl5 r:\prj\thief2\reltools\mkitype.pl r:\prj\thief2\reltools\thief2.ist

rem **************************************************************
rem Done!
rem **************************************************************




:Exit





