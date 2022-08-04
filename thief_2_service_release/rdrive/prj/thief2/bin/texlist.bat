@echo off
rm texlist.fil
n:\bin\win95\egrep -fr:\prj\thief2\bin\pattern.grp %1 > texlist2.bat
cat texlist2.bat | n:\bin\sed 's/[0-9][0-9][0-9]x[0-9][0-9][0-9]/,/g' > texlist2.bat
cat texlist2.bat | n:\bin\win95\awk -F, '{print $1}' | n:\bin\win95\awk '{print $NF}' > texlist2.bat
cat texlist2.bat | n:\bin\win95\grep -i -v 'grin' | n:\bin\win95\grep -i -v 'grout' > texlist2.bat
cat texlist2.bat | n:\bin\win95\grep -i -v 'blin' | n:\bin\win95\grep -i -v 'blout' > texlist2.bat
cat texlist2.bat | n:\bin\win95\grep -i -v 'Unknown' > texlist2.bat
cat texlist2.bat | n:\bin\win95\awk '{print "n:\\bin\\win95\\ls .\\art\\finals\\fam\\*\\" $1 ".* \076\076 texlist.fil"}' > texlist2.bat
call texlist2.bat
cat texlist.fil | n:\bin\sed 's/\.art\\finals\\fam\\//g' > texlist.fil
cat texlist.fil | n:\bin\win95\awk -F\\ '{if(last!=$NF) {print $(NF-1) "\\" $NF} else {print $(NF-1) "\\" $NF " !!!"} ; last=$NF}' > texlist.fil



