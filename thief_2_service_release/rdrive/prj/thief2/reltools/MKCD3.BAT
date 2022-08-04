rem **************************************************************
rem the drive where the dark project lives
set _PRJDRV_=r:

rem **************************************************************
rem the path to dark 

set _PRJPATH_=%_PRJDRV_%\prj\cam

rem **************************************************************
rem the drive where the daily will be built (change when testing!)

set  _DAILYDRV_=r:

rem **************************************************************
rem set the names of the daily, the daily\cd, the daily\cd\thief
rem and the prj subdirs

set _DAILY_=%_DAILYDRV_%\prj\cam\daily
set _DAILYCD_=%_DAILY_%\cd
set _DAILYTHIEF_=%_DAILYCD_%\thief
set _DAILYPRJ_=%_DAILY_%\PRJ 

r:
cd \prj\cam\art\finals

rem note  that we do not compress snd per request of Tom Leonard
cd SND
pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf ape1\*.*  >> r:\prj\cam\reltools\log


pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf ape1\*.*  >> r:\prj\cam\reltools\log


pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf burrick\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf contrick\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf crayman\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf cutty\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf elemfire\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf eye\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf garrett\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf guard1\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf guard2\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf guard3\*.*  >> r:\prj\cam\reltools\log


pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf hammer1\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf hammer2\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf hammer3\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf haunts\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf keepers\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf murus\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf oldconv\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf pris1\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf pris2\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf ramirez\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf renault\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf sfx\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf spider\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf sv1\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf sv2\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf testvoic\*.*  >> r:\prj\cam\reltools\log

pkzip25 -add  -path=relative -nozipextension  -store  %_DAILYTHIEF_%\snd.crf zombie\*.*  >> r:\prj\cam\reltools\log

cd ..

cd strings
pkzip25 -add -recurse -path=relative -nozipextension  %_DAILYTHIEF_%\strings.crf  >> r:\prj\cam\reltools\log
cd ..

rem The motiondb.bin is kinda important

copy mschema\motiondb.bin %_DAILYTHIEF_%\motiondb.bin

cd %_DAILYTHIEF_%


r:
cd %_DAILYCD_%
mkdir redist
xcopy /s r:\prj\cam\reltools\redist redist
copy  r:\prj\cam\reltools\iv5play.exe
copy  r:\prj\cam\reltools\amovie.exe
copy  x:\prj\tech\libsrc\actmovie\lgvid\retail\lgvid.ax %_DAILYTHIEF_%

rem **************************************************************
rem get the installer

cd %_PRJPATH_%\install
make install sb=r:\prj

rem **************************************************************
rem make the list of files to install

cd %_DAILYTHIEF_%

perl5 r:\prj\cam\reltools\mkitype.pl 

goto done
:error
echo Error has occured! 
