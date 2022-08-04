rem Set config to build in x:\prj.  Make build each flav. 
x: 
cd x:\prj\tech\libsrc\timer  
MAKE SB=x:\prj FLAV=dft COMP=W105 SYS=win32 build timer 
MAKE SB=x:\prj FLAV=opt COMP=W105 SYS=win32 build timer 
MAKE SB=x:\prj FLAV=dbg COMP=W105 SYS=win32 build timer 
MAKE SB=x:\prj FLAV=dcv COMP=W105 SYS=win32 build timer 
rem  Make local each flav. 
cd x:\prj\tech\libsrc\timer  
MAKE SB=x:\prj FLAV=dft COMP=W105 SYS=win32 local 
MAKE SB=x:\prj FLAV=opt COMP=W105 SYS=win32 local 
MAKE SB=x:\prj FLAV=dbg COMP=W105 SYS=win32 local 
MAKE SB=x:\prj FLAV=dcv COMP=W105 SYS=win32 local 
x: 
rem Restoring state. 
cd x:\prj\tech\libsrc\timer 
MAKE status 
