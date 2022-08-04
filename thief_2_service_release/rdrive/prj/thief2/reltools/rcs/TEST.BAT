head	 1.1;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @REM @;


1.1
date	 1999.10.05.18.29.52;  author adurant;  state Exp;
branches ;
next	 ;


desc
@@



1.1
log
@Initial revision
@
text
@
iff .%1.==.resume. .OR. .%2.==.resume. then
   input Resume where? %%WhereResume
   iff .%WhereResume.==.. then
      set WhereResume=build
   endiff
   goto %WhereResume
endiff

:Build
echo ha
@
