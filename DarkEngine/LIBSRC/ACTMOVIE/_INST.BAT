rem Set config to build in x:\prj.  Make build each flav. 
x: 
cd x:\prj\tech\libsrc\actmovie  
MAKE SB=x:\prj FLAV=opt COMP=w105 SYS=win32 build actmovie 
MAKE SB=x:\prj FLAV=dbg COMP=w105 SYS=win32 build actmovie 
MAKE SB=x:\prj FLAV=dcv COMP=w105 SYS=win32 build actmovie 
MAKE SB=x:\prj FLAV=ocv COMP=w105 SYS=win32 build actmovie 
rem  Make local each flav. 
cd x:\prj\tech\libsrc\actmovie  
MAKE SB=x:\prj FLAV=opt COMP=w105 SYS=win32 local 
MAKE SB=x:\prj FLAV=dbg COMP=w105 SYS=win32 local 
MAKE SB=x:\prj FLAV=dcv COMP=w105 SYS=win32 local 
MAKE SB=x:\prj FLAV=ocv COMP=w105 SYS=win32 local 
x: 
rem Restoring state. 
cd x:\prj\tech\libsrc\actmovie 
MAKE status 
