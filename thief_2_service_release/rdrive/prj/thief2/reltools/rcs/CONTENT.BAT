head	 1.16;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @REM @;


1.16
date	 2000.03.07.11.23.46;  author adurant;  state Exp;
branches ;
next	 1.15;

1.15
date	 2000.03.05.19.37.03;  author adurant;  state Exp;
branches ;
next	 1.14;

1.14
date	 2000.03.04.10.00.41;  author adurant;  state Exp;
branches ;
next	 1.13;

1.13
date	 2000.03.03.23.31.38;  author adurant;  state Exp;
branches ;
next	 1.12;

1.12
date	 2000.02.24.17.43.21;  author adurant;  state Exp;
branches ;
next	 1.11;

1.11
date	 2000.02.23.11.11.52;  author adurant;  state Exp;
branches ;
next	 1.10;

1.10
date	 2000.02.20.12.46.13;  author adurant;  state Exp;
branches ;
next	 1.9;

1.9
date	 2000.02.19.22.23.13;  author adurant;  state Exp;
branches ;
next	 1.8;

1.8
date	 2000.02.09.16.06.18;  author adurant;  state Exp;
branches ;
next	 1.7;

1.7
date	 2000.02.09.10.41.23;  author adurant;  state Exp;
branches ;
next	 1.6;

1.6
date	 2000.02.08.23.13.09;  author adurant;  state Exp;
branches ;
next	 1.5;

1.5
date	 1999.10.13.12.50.18;  author adurant;  state Exp;
branches ;
next	 1.4;

1.4
date	 1999.10.13.11.55.58;  author adurant;  state Exp;
branches ;
next	 1.3;

1.3
date	 1999.10.13.10.33.58;  author adurant;  state Exp;
branches ;
next	 1.2;

1.2
date	 1999.10.12.20.15.48;  author adurant;  state Exp;
branches ;
next	 1.1;

1.1
date	 1999.10.05.18.28.46;  author adurant;  state Exp;
branches ;
next	 ;


desc
@Content.bat
@


1.16
log
@song
@
text
@rem ******************************************************

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
setlocal
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

rem if you get here, you typed something wrong

@@echo Something is wrong.  usage is content [english french german]
goto Exit

:english
set _EXCLUDE1_=french
set _EXCLUDE2_=german
set _lcode_=eng
set _movielang_=english
goto BeginScript

:french
set _EXCLUDE1_=english
set _EXCLUDE2_=german
set _lcode_=frn
set _movielang_=french
goto BeginScript

:german
set _EXCLUDE1_=english
set _EXCLUDE2_=french
set _lcode_=ger
set _movielang_=german
goto BeginScript


:BeginScript

call r:\prj\thief2\reltools\initcon.bat

rem **************************************************************

%_BLDDRV_%

echo "Starting Content build" >> %_DAILY_%\content.log
n:\bin\date >> %_DAILY_%\content.log


rem copy art finals over! 
rem do the individual directories to save copying movies. 

rem temporary hack for thief2 split art tree.

rem xcopy /D /s /I %_ARTPATH_%\finals\bitmap %_BLDDRV_%\prj\cam\art\finals\bitmap
rem xcopy /D /s /I %_ARTPATH_%\finals\fam %_BLDDRV_%\prj\cam\art\finals\fam
rem xcopy /D /s /I %_ARTPATH_%\finals\books %_BLDDRV_%\prj\cam\art\finals\books
rem xcopy /D /s /I %_ARTPATH_%\finals\default %_BLDDRV_%\prj\cam\art\finals\default
rem xcopy /D /s /I %_ARTPATH_%\finals\editor %_BLDDRV_%\prj\cam\art\finals\editor
rem xcopy /D /s /I %_ARTPATH_%\finals\intrface %_BLDDRV_%\prj\cam\art\finals\intrface
rem xcopy /D /s /I %_ARTPATH_%\finals\mesh %_BLDDRV_%\prj\cam\art\finals\mesh
rem xcopy /D /s /I %_ARTPATH_%\finals\motions %_BLDDRV_%\prj\cam\art\finals\motions
rem xcopy /D /s /I %_ARTPATH_%\finals\mschema %_BLDDRV_%\prj\cam\art\finals\mschema
rem xcopy /D /s /I %_ARTPATH_%\finals\obj %_BLDDRV_%\prj\cam\art\finals\obj
rem xcopy /D /s /I %_ARTPATH_%\finals\pal %_BLDDRV_%\prj\cam\art\finals\pal 



rem xcopy /D /s /I %_ARTPATH_%\finals\snd %_BLDDRV_%\prj\cam\art\finals\snd


rem xcopy /D /s /I %_ARTPATH_%\finals\strings %_BLDDRV_%\prj\cam\art\finals\strings





rem so now we grab the separate thief 2 stuff

xcopy /D /s /I %_ARTPATH2_%\finals\bitmap %_BLDDRV_%\prj\cam\art\finals\bitmap
xcopy /D /s /I %_ARTPATH2_%\finals\fam %_BLDDRV_%\prj\cam\art\finals\fam
xcopy /D /s /I %_ARTPATH2_%\finals\books %_BLDDRV_%\prj\cam\art\finals\books
xcopy /D /s /I %_ARTPATH2_%\finals\default %_BLDDRV_%\prj\cam\art\finals\default
xcopy /D /s /I %_ARTPATH2_%\finals\editor %_BLDDRV_%\prj\cam\art\finals\editor
xcopy /D /s /I %_ARTPATH2_%\finals\intrface %_BLDDRV_%\prj\cam\art\finals\intrface
xcopy /D /s /I %_ARTPATH2_%\finals\mesh %_BLDDRV_%\prj\cam\art\finals\mesh
xcopy /D /s /I %_ARTPATH2_%\finals\motions %_BLDDRV_%\prj\cam\art\finals\motions
xcopy /D /s /I %_ARTPATH2_%\finals\mschema %_BLDDRV_%\prj\cam\art\finals\mschema
xcopy /D /s /I %_ARTPATH2_%\finals\obj %_BLDDRV_%\prj\cam\art\finals\obj
xcopy /D /s /I %_ARTPATH2_%\finals\pal %_BLDDRV_%\prj\cam\art\finals\pal
xcopy /D /s /I %_ARTPATH2_%\finals\camera %_BLDDRV_%\prj\cam\art\finals\camera
xcopy /D /s /I %_ARTPATH2_%\finals\snd %_BLDDRV_%\prj\cam\art\finals\snd
xcopy /D /s /I %_ARTPATH2_%\finals\song %_BLDDRV_%\prj\cam\art\finals\song
xcopy /D /s /I %_ARTPATH2_%\finals\strings %_BLDDRV_%\prj\cam\art\finals\strings


@@echo Copying components Over

cd %_DAILYTHIEF_%


rem **************************************************************
rem  get the config files and dll's 

echo %_PRJPATH_%

copy %_PRJPATH_%\reltools\cfgs\* %_DAILYTHIEFCD2_%

rem **************************************************************
rem  get the resources in the data dirctory  

copy %_SRCPATH_%\data\*.res %_DAILYTHIEF_%

rem **************************************************************
rem  Missions might be important... better grab them 
rem **************************************************************

rem of course, we don't have any missions yet.

%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss1.mis %_DAILYTHIEFCD2_%\miss1.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss2.mis %_DAILYTHIEFCD2_%\miss2.mis

%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss4.mis %_DAILYTHIEFCD2_%\miss4.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss5.mis %_DAILYTHIEFCD2_%\miss5.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss6.mis %_DAILYTHIEFCD2_%\miss6.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss7.mis %_DAILYTHIEFCD2_%\miss7.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss8.mis %_DAILYTHIEFCD2_%\miss8.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss9.mis %_DAILYTHIEFCD2_%\miss9.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss10.mis %_DAILYTHIEFCD2_%\miss10.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss11.mis %_DAILYTHIEFCD2_%\miss11.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss12.mis %_DAILYTHIEFCD2_%\miss12.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss13.mis %_DAILYTHIEFCD2_%\miss13.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss14.mis %_DAILYTHIEFCD2_%\miss14.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss15.mis %_DAILYTHIEFCD2_%\miss15.mis
%_PRJPATH_%\bin\misstrip %_MISPATH_%\miss16.mis %_DAILYTHIEFCD2_%\miss16.mis

rem well we have some, but we aren't going to strip them yet.
rem well, now we are stripping them.

rem xcopy /D %_MISPATH_%\*.mis %_DAILYTHIEFCD2_%\*.*

xcopy /D %_MISPATH_%\dark.gam %_DAILYTHIEFCD2_%\*.*

mkdirs %_MAINCRFPATH_%

rem **************************************************************
rem zip the art.  it is on the local drive _BLDDRV_
rem **************************************************************
:SKIP
%_BLDDRV_%
cd %_BLDDRV_%\prj\cam\art\finals

rem **************************************************************
rem   BITMAP    
rem **************************************************************
cd bitmap


find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog


pkzip25 -add -recurse -path=current -nozipextension -exclude=@@%_ZIPDIR_%\elog %_ZIPDIR_%\bitmap.crf  | tee /A r:\prj\thief2\reltools\ziplog 
cd ..

copy %_ZIPDIR_%\bitmap.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\bitmap.crf
del %_ZIPDIR_%\elog

rem **************************************************************
rem   books
rem **************************************************************

cd books

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog

pkzip25 -add  -path=current -recurse -nozipextension -exclude=@@%_ZIPDIR_%\elog %_ZIPDIR_%\books.crf   | tee /A r:\prj\thief2\reltools\ziplog 

cd ..

copy %_ZIPDIR_%\books.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\books.crf

rem **************************************************************
rem   DEFAULT 
rem **************************************************************


cd default

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog

pkzip25 -add -recurse -path=current -nozipextension  -exclude=@@%_ZIPDIR_%\elog %_ZIPDIR_%\default.crf | tee /A r:\prj\thief2\reltools\ziplog 
cd ..

copy %_ZIPDIR_%\default.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\default.crf

rem **************************************************************
rem   EDITOR
rem **************************************************************

cd editor

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog

pkzip25 -add -recurse -path=current -nozipextension  -exclude=@@%_ZIPDIR_%\elog %_ZIPDIR_%\editor.crf  | tee /A r:\prj\thief2\reltools\ziplog 
cd ..

copy %_ZIPDIR_%\editor.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\editor.crf

rem **************************************************************
rem   FAM
rem **************************************************************

cd FAM
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog

pkzip25 -add -recurse -path=current -nozipextension  -exclude=@@%_ZIPDIR_%\elog %_ZIPDIR_%\fam.crf | tee /A r:\prj\thief2\reltools\ziplog 
cd ..

copy %_ZIPDIR_%\fam.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\fam.crf

cd INTRFACE

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog

pkzip25 -add  -recurse -path=current -nozipextension  -exclude=@@%_ZIPDIR_%\elog   %_ZIPDIR_%\intrface.crf   | tee /A r:\prj\thief2\reltools\ziplog 

cd ..

copy %_ZIPDIR_%\intrface.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\intrface.crf

cd mesh

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog

pkzip25 -add -recurse -path=current -nozipextension -exclude=@@%_ZIPDIR_%\elog  %_ZIPDIR_%\mesh.crf  | tee /A r:\prj\thief2\reltools\ziplog 
cd ..

copy %_ZIPDIR_%\mesh.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\mesh.crf

rem **************************************************************
rem   OBJ
rem **************************************************************

cd obj

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog


pkzip25 -add -recurse -path=current -nozipextension -exclude=@@%_ZIPDIR_%\elog  %_ZIPDIR_%\obj.crf  | tee /A r:\prj\thief2\reltools\ziplog 
cd ..

copy %_ZIPDIR_%\obj.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\obj.crf

rem **************************************************************
rem   PAL
rem **************************************************************

cd pal

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog

pkzip25 -add -recurse -path=current -nozipextension -exclude=@@%_ZIPDIR_%\elog  %_ZIPDIR_%\pal.crf  | tee /A r:\prj\thief2\reltools\ziplog 
cd ..

copy %_ZIPDIR_%\pal.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\pal.crf

rem **************************************************************
rem   CAMERA
rem **************************************************************

cd camera

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog

pkzip25 -add -recurse -path=current -nozipextension -exclude=@@%_ZIPDIR_%\elog  %_ZIPDIR_%\camera.crf  | tee /A r:\prj\thief2\reltools\ziplog 
cd ..

copy %_ZIPDIR_%\camera.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\camera.crf

rem **************************************************************
rem   SND
rem **************************************************************

rem note  that we do not compress snd per request of Tom Leonard
cd SND

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog


pkzip25 -add  -path=current -recurse -store  -nozipextension  -exclude=@@%_ZIPDIR_%\elog -store  %_ZIPDIR_%\snd.crf   | tee /A r:\prj\thief2\reltools\ziplog 

cd ..

copy %_ZIPDIR_%\snd.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\snd.crf

rem **************************************************************
rem   SONG
rem **************************************************************

rem note  that we do not compress songs much like sound
cd song

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog


pkzip25 -add  -path=current -recurse -store  -nozipextension  -exclude=@@%_ZIPDIR_%\elog -store  %_ZIPDIR_%\song.crf   | tee /A r:\prj\thief2\reltools\ziplog 

cd ..

copy %_ZIPDIR_%\song.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\song.crf

rem **************************************************************
rem   STRINGS
rem **************************************************************

cd strings

find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE1_% > %_ZIPDIR_%\elog
find . -print | sed 1,$s~./~~ | grep -i %_EXCLUDE2_%  >> %_ZIPDIR_%\elog


pkzip25 -add -recurse -path=current -nozipextension -exclude=@@%_ZIPDIR_%\elog  %_ZIPDIR_%\strings.crf | tee /A r:\prj\thief2\reltools\ziplog 
cd ..

copy %_ZIPDIR_%\strings.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\strings.crf

cd motions
pkzip25 -add -recurse -path=current -nozipextension %_ZIPDIR_%\motions.crf | tee /A r:\prj\thief2\reltools\ziplog 
 
copy %_ZIPDIR_%\motions.crf %_MAINCRFPATH_%
del %_ZIPDIR_%\motions.crf

cd ..

rem we don't zip movies per request of dark team. 
rem simply copy from the tree to the %_DAILYTHIEF_%
mkdirs %_DAILYTHIEFCD2_%\movies
xcopy  %_MOVIEPATH_%\%_movielang_% %_DAILYTHIEFCD2_%\movies

mkdirs %_DAILYTHIEF_%\movies
copy %_MOVIEPATH_%\%_movielang_%\success.avi %_DAILYTHIEF_%\movies
copy %_MOVIEPATH_%\%_movielang_%\death.avi %_DAILYTHIEF_%\movies


rem The motiondb.bin is kinda important

copy mschema\motiondb.bin %_DAILYTHIEFCD2_%\motiondb.bin

rem hack to fix scripts (since TG isn't constantly running src)
rem get mission scripts
copy r:\prj\thief2\scripts\osm\miss*.osm %_DAILYTHIEFCD2_%
copy r:\prj\thief2\scripts\osm\gen.osm %_DAILYTHIEFCD2_%
copy r:\prj\thief2\scripts\osm\convict.osm %_DAILYTHIEFCD2_%
copy r:\prj\thief2\scripts\osm\archer.osm %_DAILYTHIEFCD2_%

:done
set _FINALS_=
set _DEMO_=
set _PRJ_=
set _PRJDRV_= 

echo "Finished  Content build" >> %_DAILY_%\content.log
n:\bin\date >> %_DAILY_%\content.log


:Exit





@


1.15
log
@moved stuff from CD1 to CD2
@
text
@d112 1
d336 18
@


1.14
log
@fixed crf path thing
@
text
@d125 1
a125 1
copy %_PRJPATH_%\reltools\cfgs\* %_DAILYTHIEF_%
d372 1
a372 1
copy mschema\motiondb.bin %_DAILYTHIEF_%\motiondb.bin
@


1.13
log
@deeper crf files
@
text
@d162 2
@


1.12
log
@only some scripts go in.
@
text
@d182 1
a182 1
copy %_ZIPDIR_%\bitmap.crf %_DAILYTHIEF_%
d199 1
a199 1
copy %_ZIPDIR_%\books.crf %_DAILYTHIEF_%
d215 1
a215 1
copy %_ZIPDIR_%\default.crf %_DAILYTHIEF_%
d230 1
a230 1
copy %_ZIPDIR_%\editor.crf %_DAILYTHIEF_%
d244 1
a244 1
copy %_ZIPDIR_%\fam.crf %_DAILYTHIEFCD2_%
d256 1
a256 1
copy %_ZIPDIR_%\intrface.crf %_DAILYTHIEF_%
d267 1
a267 1
copy %_ZIPDIR_%\mesh.crf %_DAILYTHIEF_%
d283 1
a283 1
copy %_ZIPDIR_%\obj.crf %_DAILYTHIEF_%
d298 1
a298 1
copy %_ZIPDIR_%\pal.crf %_DAILYTHIEF_%
d313 1
a313 1
copy %_ZIPDIR_%\camera.crf %_DAILYTHIEF_%
d331 1
a331 1
copy %_ZIPDIR_%\snd.crf %_DAILYTHIEF_%
d347 1
a347 1
copy %_ZIPDIR_%\strings.crf %_DAILYTHIEF_%
d353 1
a353 1
copy %_ZIPDIR_%\motions.crf %_DAILYTHIEF_%
@


1.11
log
@no cam sound
@
text
@d373 5
a377 1
xcopy r:\prj\thief2\scripts\osm\*.osm %_DAILYTHIEFCD2_%
@


1.10
log
@get default
@
text
@d88 1
a88 1
xcopy /D /s /I %_ARTPATH_%\finals\snd %_BLDDRV_%\prj\cam\art\finals\snd
@


1.9
log
@grab bitmap and pal
@
text
@d102 1
a102 1
rem xcopy /D /s /I %_ARTPATH2_%\finals\default %_BLDDRV_%\prj\cam\art\finals\default
@


1.8
log
@strip missions, put missions and gam file on cd2
@
text
@d86 2
d90 1
d94 3
d99 1
a99 1
rem xcopy /D /s /I %_ARTPATH2_%\finals\bitmap %_BLDDRV_%\prj\cam\art\finals\bitmap
d109 1
a109 1
rem xcopy /D /s /I %_ARTPATH2_%\finals\pal %_BLDDRV_%\prj\cam\art\finals\pal
@


1.7
log
@camera copy in right place
@
text
@d132 2
a133 13
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss1.mis %_DAILYTHIEFCD2_%\miss1.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss2.mis %_DAILYTHIEFCD2_%\miss2.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss3.mis %_DAILYTHIEFCD2_%\miss3.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss4.mis %_DAILYTHIEFCD2_%\miss4.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss5.mis %_DAILYTHIEFCD2_%\miss5.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss6.mis %_DAILYTHIEFCD2_%\miss6.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss7.mis %_DAILYTHIEFCD2_%\miss7.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss9.mis %_DAILYTHIEFCD2_%\miss9.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss10.mis %_DAILYTHIEFCD2_%\miss10.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss11.mis %_DAILYTHIEFCD2_%\miss11.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss12.mis %_DAILYTHIEFCD2_%\miss12.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss13.mis %_DAILYTHIEFCD2_%\miss13.mis
rem %_PRJPATH_%\bin\misstrip %_MISPATH_%\miss14.mis %_DAILYTHIEFCD2_%\miss14.mis
d135 14
d150 1
d152 1
a152 1
xcopy /D %_MISPATH_%\*.mis %_DAILYTHIEF_%\*.*
d154 1
a154 1
xcopy /D %_MISPATH_%\*.gam %_DAILYTHIEF_%\*.*
@


1.6
log
@cmaera
er camera.crf
@
text
@d74 12
a85 11
xcopy /D /s /I %_ARTPATH_%\finals\bitmap %_BLDDRV_%\prj\cam\art\finals\bitmap
xcopy /D /s /I %_ARTPATH_%\finals\fam %_BLDDRV_%\prj\cam\art\finals\fam
xcopy /D /s /I %_ARTPATH_%\finals\books %_BLDDRV_%\prj\cam\art\finals\books
xcopy /D /s /I %_ARTPATH_%\finals\default %_BLDDRV_%\prj\cam\art\finals\default
xcopy /D /s /I %_ARTPATH_%\finals\editor %_BLDDRV_%\prj\cam\art\finals\editor
xcopy /D /s /I %_ARTPATH_%\finals\intrface %_BLDDRV_%\prj\cam\art\finals\intrface
xcopy /D /s /I %_ARTPATH_%\finals\mesh %_BLDDRV_%\prj\cam\art\finals\mesh
xcopy /D /s /I %_ARTPATH_%\finals\motions %_BLDDRV_%\prj\cam\art\finals\motions
xcopy /D /s /I %_ARTPATH_%\finals\mschema %_BLDDRV_%\prj\cam\art\finals\mschema
xcopy /D /s /I %_ARTPATH_%\finals\obj %_BLDDRV_%\prj\cam\art\finals\obj
xcopy /D /s /I %_ARTPATH_%\finals\pal %_BLDDRV_%\prj\cam\art\finals\pal
d87 2
a88 2
xcopy /D /s /I %_ARTPATH_%\finals\camera %_BLDDRV_%\prj\cam\art\finals\camera
xcopy /D /s /I %_ARTPATH_%\finals\strings %_BLDDRV_%\prj\cam\art\finals\strings
d104 1
@


1.5
log
@don't want to strip missions yet, but copies them now
@
text
@d86 1
d288 15
@


1.4
log
@something was very screwy about copying thief2 art.  probably my fault.
should be fixed now
@
text
@d143 4
@


1.3
log
@fixed movie copy of extra success and death
@
text
@d91 13
a103 13
rem xcopy /D /s /I thief2\finals\bitmap %_BLDDRV_%\prj\cam\art\finals\bitmap
xcopy /D /s /I thief2\finals\fam %_BLDDRV_%\prj\cam\art\finals\fam
xcopy /D /s /I thief2\finals\books %_BLDDRV_%\prj\cam\art\finals\books
rem xcopy /D /s /I thief2\finals\default %_BLDDRV_%\prj\cam\art\finals\default
xcopy /D /s /I thief2\finals\editor %_BLDDRV_%\prj\cam\art\finals\editor
xcopy /D /s /I thief2\finals\intrface %_BLDDRV_%\prj\cam\art\finals\intrface
xcopy /D /s /I thief2\finals\mesh %_BLDDRV_%\prj\cam\art\finals\mesh
xcopy /D /s /I thief2\finals\motions %_BLDDRV_%\prj\cam\art\finals\motions
xcopy /D /s /I thief2\finals\mschema %_BLDDRV_%\prj\cam\art\finals\mschema
xcopy /D /s /I thief2\finals\obj %_BLDDRV_%\prj\cam\art\finals\obj
rem xcopy /D /s /I thief2\finals\pal %_BLDDRV_%\prj\cam\art\finals\pal
xcopy /D /s /I thief2\finals\snd %_BLDDRV_%\prj\cam\art\finals\snd
xcopy /D /s /I thief2\finals\strings %_BLDDRV_%\prj\cam\art\finals\strings
@


1.2
log
@gets thief2 motions and mschema
@
text
@d332 2
a333 2
copy %_MOVIEPATH_%\movies\%_movielang_%\success.avi %_DAILYTHIEF_%\movies
copy %_MOVIEPATH_%\movies\%_movielang_%\death.avi %_DAILYTHIEF_%\movies
@


1.1
log
@Initial revision
@
text
@d98 2
a99 2
rem xcopy /D /s /I thief2\finals\motions %_BLDDRV_%\prj\cam\art\finals\motions
rem xcopy /D /s /I thief2\finals\mschema %_BLDDRV_%\prj\cam\art\finals\mschema
@
