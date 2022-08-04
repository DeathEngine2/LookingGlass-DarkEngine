#
# $Source: x:/prj/tech/libsrc/cpptools/RCS/makefile $
# $Revision: 1.21 $
# $Author: TOML $
# $Date: 1997/09/22 22:29:41 $
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
