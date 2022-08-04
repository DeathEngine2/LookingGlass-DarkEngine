head	 1.21;
branch   ;
access   ;
symbols  ;
locks    TOML:1.21; strict;
comment  @# @;


1.21
date	 1997.09.22.22.29.41;  author TOML;  state Exp;
branches ;
next	 1.20;

1.20
date	 1997.08.24.18.21.38;  author TOML;  state Exp;
branches ;
next	 1.19;

1.19
date	 1997.08.12.12.17.22;  author TOML;  state Exp;
branches ;
next	 1.18;

1.18
date	 1997.07.21.14.13.28;  author TOML;  state Exp;
branches ;
next	 1.17;

1.17
date	 1997.07.03.13.24.08;  author TOML;  state Exp;
branches ;
next	 1.16;

1.16
date	 1996.12.30.22.20.11;  author mahk;  state Exp;
branches ;
next	 1.15;

1.15
date	 1996.11.06.17.42.12;  author TOML;  state Exp;
branches ;
next	 1.14;

1.14
date	 1996.11.05.17.13.24;  author TOML;  state Exp;
branches ;
next	 1.13;

1.13
date	 1996.08.28.13.56.51;  author TOML;  state Exp;
branches ;
next	 1.12;

1.12
date	 1996.08.20.09.25.41;  author TOML;  state Exp;
branches ;
next	 1.11;

1.11
date	 1996.07.12.11.02.10;  author TOML;  state Exp;
branches ;
next	 1.10;

1.10
date	 1996.06.10.14.24.01;  author TOML;  state Exp;
branches ;
next	 1.9;

1.9
date	 1996.05.10.09.19.00;  author TOML;  state Exp;
branches ;
next	 1.8;

1.8
date	 1996.05.09.11.15.53;  author TOML;  state Exp;
branches ;
next	 1.7;

1.7
date	 1996.05.08.18.38.08;  author TOML;  state Exp;
branches ;
next	 1.6;

1.6
date	 1996.05.01.21.38.23;  author TOML;  state Exp;
branches ;
next	 1.5;

1.5
date	 1996.05.01.20.52.38;  author TOML;  state Exp;
branches ;
next	 1.4;

1.4
date	 1996.05.01.20.38.23;  author TOML;  state Exp;
branches ;
next	 1.3;

1.3
date	 1996.05.01.17.01.17;  author TOML;  state Exp;
branches ;
next	 1.2;

1.2
date	 1996.04.29.17.53.54;  author TOML;  state Exp;
branches ;
next	 1.1;

1.1
date	 1996.04.29.16.27.15;  author TOML;  state Exp;
branches ;
next	 ;


desc
@@


1.21
log
@*** empty log message ***
@
text
@#
# $Source: x:/prj/tech/libsrc/cpptools/rcs/makefile $
# $Revision: 1.20 $
# $Author: TOML $
# $Date: 1997/08/24 18:21:38 $
#
#

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = cpptools

EXETARGS =

SPEC_EXETARGS = hashtest

cpptools_OBJS = delmlist dynfunc filepath filespec fnamutil splitpat str \
                hashset dlist dynarray relocptr pdynarr hashpp packflag

cpptools_HDRS = delmlist.h dynfunc.h filekind.h filepath.h filespec.h  \
                fnamutil.h splitpat.h str.h hashset.h hshsttem.h dlist.h \
                dlisttem.h templexp.h dynarray.h relocptr.h \
                hshstimp.h pdynarr.h fixedque.h hashpp.h hshpptem.h \
                hashfunc.h packflag.h fixedstk.h


#########################################
# HASHPP TEST HARNESS
#

hashtest_OBJS = hashlex hashtest
hashtest_LIBS = $(TECH_LIBS)

# All peoples love yacc and lex!

hashtok.h hashtest.cc: hashtest.y
    yacc -l -D hashtok.h -o hashtest.cc $(.source)

hashlex.c: hashlex.lex hashtok.h
         lex -l -o $(.target) $(.source)




%include $(MRC)\make.rc
@


1.20
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.19 $
d5 1
a5 1
# $Date: 1997/08/12 12:17:22 $
d30 1
a30 1
                hashfunc.h packflag.h
@


1.19
log
@changed C++ hash table for better support of small keys
@
text
@d3 1
a3 1
# $Revision: 1.18 $
d5 1
a5 1
# $Date: 1997/07/21 14:13:28 $
d24 1
a24 1
                hashset dlist dynarray relocptr pdynarr hashpp
d30 1
a30 1
                hashfunc.h 
@


1.18
log
@*** empty log message ***
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/cpptools/RCS/makefile $
# $Revision: 1.17 $
d5 1
a5 1
# $Date: 1997/07/03 13:24:08 $
d24 1
a24 1
                ptrset hashset dlist dynarray relocptr pdynarr hashpp
d28 1
a28 1
                dlisttem.h templexp.h ptrset.h dynarray.h relocptr.h \
@


1.17
log
@*** empty log message ***
@
text
@d2 4
a5 4
# $Source: x:/prj/tech/libsrc/cpptools/rcs/makefile $
# $Revision: 1.16 $
# $Author: mahk $
# $Date: 1996/12/30 22:20:11 $
d30 1
a30 1
                hashfunc.h timings.h
@


1.16
log
@Added hashpp and hashtest.
@
text
@d3 3
a5 3
# $Revision: 1.15 $
# $Author: TOML $
# $Date: 1996/11/06 17:42:12 $
d30 1
a30 1
                hashfunc.h
@


1.15
log
@*** empty log message ***
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/cpptools/RCS/makefile $
# $Revision: 1.14 $
d5 1
a5 1
# $Date: 1996/11/05 17:13:24 $
d21 2
d24 1
a24 1
                ptrset hashset dlist dynarray relocptr pdynarr
d29 20
a48 1
                hshstimp.h pdynarr.h fixedque.h
@


1.14
log
@*** empty log message ***
@
text
@d2 2
a3 2
# $Source: x:/prj/tech/libsrc/cpptools/rcs/makefile $
# $Revision: 1.13 $
d5 1
a5 1
# $Date: 1996/08/28 13:56:51 $
d27 1
a27 1
                hshstimp.h pdynarr.h circque.h
@


1.13
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.12 $
d5 1
a5 1
# $Date: 1996/08/20 09:25:41 $
d27 1
a27 1
                hshstimp.h pdynarr.h
@


1.12
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.11 $
d5 1
a5 1
# $Date: 1996/07/12 11:02:10 $
d22 1
a22 1
                ptrset hashset dlist dynarray relocptr pdynarr thrdtool
d27 1
a27 1
                hshstimp.h pdynarr.h thrdtool.h
@


1.11
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.10 $
d5 1
a5 1
# $Date: 1996/06/10 14:24:01 $
d22 1
a22 1
                ptrset hashset dlist dynarray relocptr pdynarr
d27 1
a27 1
                hshstimp.h pdynarr.h
@


1.10
log
@broke out hash chunk so available to templgen library
@
text
@d3 1
a3 1
# $Revision: 1.9 $
d5 1
a5 1
# $Date: 1996/05/10 09:19:00 $
d22 1
a22 1
                ptrset hashset dlist dynarray relocptr
d27 1
a27 1
                hshstimp.h
@


1.9
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.8 $
d5 1
a5 1
# $Date: 1996/05/09 11:15:53 $
d26 2
a27 1
                dlisttem.h templexp.h ptrset.h dynarray.h relocptr.h
@


1.8
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.7 $
d5 1
a5 1
# $Date: 1996/05/08 18:38:08 $
d22 1
a22 1
                ptrset hashset dlist dynarray
d26 1
a26 1
                dlisttem.h templexp.h ptrset.h dynarray.h
@


1.7
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.6 $
d5 1
a5 1
# $Date: 1996/05/01 21:38:23 $
d22 1
a22 1
                ptrset hashset dlist
d26 1
a26 1
                dlisttem.h templexp.h ptrset.h
@


1.6
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.5 $
d5 1
a5 1
# $Date: 1996/05/01 20:52:38 $
d21 2
a22 1
cpptools_OBJS = delmlist dynfunc filepath filespec fnamutil splitpat str hashset dlist
d24 3
a26 2
cpptools_HDRS = delmlist.h dynfunc.h filekind.h filepath.h filespec.h fnamutil.h \
               splitpat.h str.h hashset.h hshsttem.h dlist.h dlisttem.h templexp.h
@


1.5
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.4 $
d5 1
a5 1
# $Date: 1996/05/01 20:38:23 $
d24 1
a24 1
               splitpat.h str.h hashset.h hshsttem.h dlist.h dlisttem.h
@


1.4
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.3 $
d5 1
a5 1
# $Date: 1996/05/01 17:01:17 $
d24 1
a24 1
               splitpat.h str.h hashset.h hashset.tem dlist.h dlist.tem
@


1.3
log
@*** empty log message ***
@
text
@d3 1
a3 1
# $Revision: 1.2 $
d5 1
a5 1
# $Date: 1996/04/29 17:53:54 $
d21 1
a21 1
cpptools_OBJS = delmlist dynfunc filepath filespec fnamutil splitpat str hashset
d24 1
a24 1
               splitpat.h str.h hashset.h
@


1.2
log
@Watcom compatability
@
text
@d3 1
a3 1
# $Revision: 1.1 $
d5 1
a5 1
# $Date: 1996/04/29 16:27:15 $
d21 1
a21 1
cpptools_OBJS = delmlist dynfunc filepath filespec fnamutil splitpat str
d24 1
a24 1
               splitpat.h str.h
@


1.1
log
@Initial revision
@
text
@d2 4
a5 4
# $Source: $
# $Revision: $
# $Author: $
# $Date: $
d21 1
a21 1
appcore_OBJS = delmlist dynfunc filepath filespec fnamutil hashset splitpat str
d23 2
a24 2
appcore_HDRS = delmlist.h dynfunc.h filekind.h filepath.h filespec.h fnamutil.h \
               hashset.h splitpat.h str.h
@
