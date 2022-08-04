head	 2.2;
branch   ;
access   ;
symbols  SHIPPED_F95:2.1 noldnmk:1.12.1 FLT_SHIP:1.12.1.1;
locks    ; strict;
comment  @# @;


2.2
date	 1996.04.08.16.51.13;  author TOML;  state Exp;
branches ;
next	 2.1;

2.1
date	 1995.10.02.19.59.51;  author JON;  state Exp;
branches ;
next	 1.12;

1.12
date	 1994.08.22.17.13.21;  author rex;  state Exp;
branches 1.12.1.1;
next	 1.11;

1.11
date	 1994.08.22.17.09.12;  author xemu;  state Exp;
branches ;
next	 1.10;

1.10
date	 1994.08.20.16.22.09;  author xemu;  state Exp;
branches ;
next	 1.9;

1.9
date	 1993.11.04.11.22.17;  author rex;  state Exp;
branches ;
next	 1.8;

1.8
date	 1993.10.07.10.22.01;  author rex;  state Exp;
branches ;
next	 1.7;

1.7
date	 1993.08.09.20.32.00;  author mahk;  state Exp;
branches ;
next	 1.6;

1.6
date	 1993.05.03.10.55.48;  author rex;  state Exp;
branches ;
next	 1.5;

1.5
date	 1993.04.29.12.11.12;  author mahk;  state Exp;
branches ;
next	 1.4;

1.4
date	 1993.04.22.13.06.04;  author rex;  state Exp;
branches ;
next	 1.3;

1.3
date	 1993.04.16.22.12.05;  author mahk;  state Exp;
branches ;
next	 1.2;

1.2
date	 1993.04.16.11.04.39;  author rex;  state Exp;
branches ;
next	 1.1;

1.1
date	 1993.03.25.19.25.20;  author mahk;  state Exp;
branches ;
next	 ;

1.12.1.1
date	 1994.12.10.10.15.54;  author lmfeeney;  state Exp;
branches ;
next	 ;


desc
@This might one day be a mighty makefile for a mighty data structure library,
but as it currently only makes hashtables, it's not so mighty.
@


2.2
log
@y
@
text
@
# $Source: x:/prj/tech/libsrc/dstruct/RCS/makefile $
# $Revision: 2.1 $
# $Author: JON $
# $Date: 1995/10/02 19:59:51 $

MAKETOP = $(CWD)

PROJECT = tech 

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = dstruct

DSTRUCT_OBJS = array fname hash hheap huffde huffen llist lllist \
	message pqueue rect strall  symdump symtab 

DSTRUCT_HDRS = array.h fname.h hash.h hheap.h huff.h huffde.h llist.h \
	message.h pqueue.h rect.h slist.h strall.h symtab.h

%include $(MRC)\make.rc

@


2.1
log
@Branch for new makefile replacing nmk.
@
text
@d2 4
a5 4
# $Source: r:/prj/lib/src/dstruct/rcs/makefile $
# $Revision: 1.12.1.1 $
# $Author: lmfeeney $
# $Date: 1994/12/10 10:15:54 $
d9 1
a9 1
PROJECT = windex 
@


1.12
log
@Added huffman code (huffen.c and huffde.c)
@
text
@a0 4
DEBUG_ON = 1
SPEW_ON = 1
WARN_ON = 1
DBG_ON = 1
d2 4
d7 1
a7 3
COMPILER = watcom
SRCDIR = r:\prj\lib\src\dstruct
RELDIR = r:\prj\lib\rel
d9 1
a9 10
OBJDIR = obj
BINDIR =
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = . $(RELDIR)
PROG_TARGETS = arraytst fnamtest hashtest msgtest symtest #pqtest
LIB_TARGETS = dstruct
HDR_TARGETS =  
INST_TARGETS = dstruct
d11 1
a11 5
DSTRUCT_OBJS = array.obj fname.obj hash.obj hheap.obj huffde.obj huffen.obj \
	lllist.obj llist.obj message.obj pqueue.obj rect.obj strall.obj \
	symtab.obj symdump.obj
DSTRUCT_HDRS = array.h fname.h hash.h hheap.h huff.h huffde.h llist.h \
	message.h pqueue.h rect.h slist.h strall.h symtab.h
d13 1
a13 2
ARRAYTST_OBJS = arraytst.obj
ARRAYTST_LIBS = _lg.lib _mprintf.lib dstruct.lib
d15 1
a15 2
FNAMTEST_OBJS = fnamtest.obj
FNAMTEST_LIBS = _lg.lib mprintf.lib dstruct.lib
d17 2
a18 2
HASHTEST_OBJS = hashtest.obj hashlex.obj
HASHTEST_LIBS = _lg.lib mprintf.lib dstruct.lib
d20 2
a21 2
MSGTEST_OBJS  = msgtest.obj
MSGTEST_LIBS  = _lg.lib mprintf.lib fix.lib dstruct.lib
d23 1
a23 2
PQTEST_OBJS   = pqtest.obj
PQTEST_LIBS   = _lg.lib dstruct.lib mprintf.lib
a24 71
SYMTEST_OBJS  = symtest.obj
SYMTEST_LIBS  = _lg.lib mprintf.lib fix.lib dstruct.lib

!include $(INIT)/make.rc

hashtest.c: hashtest.y 
	 yacc -D hashtok.h -o hashtest.c hashtest.y

hashlex.c: hashlex.lex hashtok.h 
         lex -o hashlex.c hashlex.lex

### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.

array.obj objo\array.obj objd\array.obj: array.h dbg.h dbgmacro.h error.h lg.h lgalt.h malloc.h memall.h \
	 memmacro.h stdio.h string.h types.h

arraytst.obj objo\arraytst.obj objd\arraytst.obj: array.h dbg.h dbgmacro.h error.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h stdio.h stdlib.h types.h

fname.obj objo\fname.obj objd\fname.obj: fname.h string.h types.h

fnamtest.obj objo\fnamtest.obj objd\fnamtest.obj: conio.h ctype.h fname.h stdio.h stdlib.h types.h

hash.obj objo\hash.obj objd\hash.obj: _dstruct.h dbg.h dbgmacro.h error.h hash.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h stdio.h stdlib.h string.h types.h

hashlex.obj objo\hashlex.obj objd\hashlex.obj: dbg.h dbgmacro.h hashtest.h hashtok.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h stdio.h stdlib.h string.h types.h

hashtest.obj objo\hashtest.obj objd\hashtest.obj: _dstruct.h dbg.h dbgmacro.h error.h hash.h hashtest.h lg.h \
	 lgalt.h malloc.h memall.h memmacro.h mprintf.h stdio.h stdlib.h \
	 string.h types.h

hheap.obj objo\hheap.obj objd\hheap.obj: dbg.h dbgmacro.h hheap.h lg.h lgalt.h llist.h malloc.h memall.h \
	 memmacro.h stdio.h stdlib.h string.h types.h

huffde.obj objo\huffde.obj objd\huffde.obj: dbg.h dbgmacro.h huff.h stdio.h string.h types.h

huffen.obj objo\huffen.obj objd\huffen.obj: dbg.h dbgmacro.h huff.h stdio.h stdlib.h string.h types.h

llist.obj objo\llist.obj objd\llist.obj: llist.h malloc.h memall.h memmacro.h string.h types.h

lllist.obj objo\lllist.obj objd\lllist.obj: llist.h types.h

message.obj objo\message.obj objd\message.obj: _dstruct.h dbg.h dbgmacro.h lg.h lgalt.h lgsprntf.h malloc.h \
	 memall.h memmacro.h message.h stdarg.h stdio.h stdlib.h string.h \
	 types.h

msgtest.obj objo\msgtest.obj objd\msgtest.obj: _dstruct.h conio.h ctype.h dbg.h dbgmacro.h lg.h lgalt.h \
	 malloc.h memall.h memmacro.h message.h mprintf.h stdio.h stdlib.h \
	 string.h types.h

pqueue.obj objo\pqueue.obj objd\pqueue.obj: dbg.h dbgmacro.h error.h io.h lg.h lgalt.h malloc.h memall.h \
	 memmacro.h pqueue.h stat.h stdio.h string.h types.h

rect.obj objo\rect.obj objd\rect.obj: rect.h

strall.obj objo\strall.obj objd\strall.obj: dbg.h dbgmacro.h hheap.h lg.h lgalt.h llist.h malloc.h memall.h \
	 memmacro.h stdio.h strall.h string.h types.h

symdump.obj objo\symdump.obj objd\symdump.obj: ctype.h dbg.h dbgmacro.h fix.h hheap.h lg.h lgalt.h llist.h \
	 malloc.h memall.h memmacro.h slist.h stdio.h string.h symtab.h \
	 types.h

symtab.obj objo\symtab.obj objd\symtab.obj: ctype.h dbg.h dbgmacro.h fix.h hheap.h lg.h lgalt.h lgsprntf.h \
	 llist.h malloc.h memall.h memmacro.h slist.h stdarg.h stdio.h \
	 strall.h string.h symtab.h types.h

symtest.obj objo\symtest.obj objd\symtest.obj: conio.h ctype.h dbg.h dbgmacro.h fix.h hheap.h lg.h lgalt.h \
	 llist.h malloc.h memall.h memmacro.h slist.h stdio.h stdlib.h \
	 strall.h symtab.h types.h
@


1.12.1.1
log
@new make regime
@
text
@d1 4
a5 4
# $Source: $
# $Revision: $
# $Author: $
# $Date: $
d7 3
a9 1
MAKETOP = $(CWD)
d11 10
a20 1
PROJECT = windex 
d22 5
a26 1
%include $(MRC)\env.rc
d28 2
a29 1
%include $(MRC)\init.rc
d31 2
a32 1
LIBTARGS = dstruct
d34 2
a35 2
DSTRUCT_OBJS = array fname hash hheap huffde huffen llist lllist \
	message pqueue rect strall  symdump symtab 
d37 2
a38 2
DSTRUCT_HDRS = array.h fname.h hash.h hheap.h huff.h huffde.h llist.h \
	message.h pqueue.h rect.h slist.h strall.h symtab.h
d40 2
a41 1
%include $(MRC)\make.rc
d43 71
@


1.11
log
@hey, rel not release
@
text
@d22 5
a26 4
DSTRUCT_OBJS = array.obj fname.obj hash.obj hheap.obj lllist.obj llist.obj \
	message.obj pqueue.obj rect.obj strall.obj symtab.obj symdump.obj
DSTRUCT_HDRS = array.h fname.h hash.h hheap.h llist.h message.h pqueue.h \
	rect.h slist.h strall.h symtab.h
d56 1
a56 1
array.obj: array.h dbg.h dbgmacro.h error.h lg.h lgalt.h malloc.h memall.h \
d59 1
a59 1
arraytst.obj: array.h dbg.h dbgmacro.h error.h lg.h lgalt.h malloc.h \
d62 1
a62 1
fname.obj: fname.h string.h types.h
d64 1
a64 1
fnamtest.obj: conio.h ctype.h fname.h stdio.h stdlib.h types.h
d66 1
a66 1
hash.obj: _dstruct.h dbg.h dbgmacro.h error.h hash.h lg.h lgalt.h malloc.h \
d69 1
a69 1
hashlex.obj: dbg.h dbgmacro.h hashtest.h hashtok.h lg.h lgalt.h malloc.h \
d72 1
a72 1
hashtest.obj: _dstruct.h dbg.h dbgmacro.h error.h hash.h hashtest.h lg.h \
d76 1
a76 1
hheap.obj: dbg.h dbgmacro.h hheap.h lg.h lgalt.h llist.h malloc.h memall.h \
d79 1
a79 1
llist.obj: llist.h malloc.h memall.h memmacro.h string.h types.h
d81 1
a81 1
lllist.obj: llist.h types.h
d83 1
a83 2
message.obj: _dstruct.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h memall.h \
	 memmacro.h message.h stdio.h stdlib.h string.h types.h
d85 7
a91 1
msgtest.obj: _dstruct.h conio.h ctype.h dbg.h dbgmacro.h lg.h lgalt.h \
d95 1
a95 1
pqueue.obj: dbg.h dbgmacro.h error.h io.h lg.h lgalt.h malloc.h memall.h \
d98 1
a98 1
rect.obj: rect.h
d100 1
a100 1
strall.obj: dbg.h dbgmacro.h hheap.h lg.h lgalt.h llist.h malloc.h memall.h \
d103 3
a105 3
symtab.obj: ctype.h dbg.h dbgmacro.h fix.h hheap.h lg.h lgalt.h llist.h \
	 malloc.h memall.h memmacro.h slist.h stdio.h strall.h string.h \
	 symtab.h types.h
d107 5
a111 1
symtest.obj: conio.h ctype.h dbg.h dbgmacro.h fix.h hheap.h lg.h lgalt.h \
a113 1

@


1.10
log
@gee, finally move to R;
@
text
@d9 1
a9 1
RELDIR = r:\prj\lib\release
@


1.9
log
@Added symdump.obj
@
text
@d8 2
a9 2
SRCDIR = n:\project\lib\src\dstruct
RELDIR = n:\project\lib\release
d104 1
@


1.8
log
@Added Message sources and tester
@
text
@d23 1
a23 1
	message.obj pqueue.obj rect.obj strall.obj symtab.obj
@


1.7
log
@Added priority queue.
@
text
@d17 1
a17 1
PROG_TARGETS = hashtest arraytst fnamtest symtest pqtest
d23 3
a25 3
	rect.obj strall.obj symtab.obj pqueue.obj
DSTRUCT_HDRS = array.h fname.h hash.h hheap.h llist.h rect.h slist.h \
	strall.h symtab.h  pqueue.h
d27 2
a28 2
ARRAYTST_OBJS = arraytst.obj array.obj
ARRAYTST_LIBS = _lg.lib _mprintf.lib
d31 1
a31 1
FNAMTEST_LIBS = lg.lib mprintf.lib dstruct.lib
d33 2
a34 2
HASHTEST_OBJS = hashtest.obj  hashlex.obj hash.obj
HASHTEST_LIBS = lg.lib mprintf.lib
d36 2
a37 2
SYMTEST_OBJS  = symtest.obj
SYMTEST_LIBS  = lg.lib mprintf.lib fix.lib dstruct.lib
d40 1
a40 1
PQTEST_LIBS   = lg.lib dstruct.lib mprintf.lib
d42 5
a52 2
!include $(INIT)/make.rc

d82 6
a87 2
pqtest.obj: dbg.h dbgmacro.h error.h fcntl.h io.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h pqueue.h stat.h stdio.h stdlib.h types.h
@


1.6
log
@Added slist.h, 'fname' module with test, and 'symtab' module with test
@
text
@d17 1
a17 1
PROG_TARGETS = hashtest arraytst fnamtest symtest
d23 1
a23 1
	rect.obj strall.obj symtab.obj
d25 1
a25 1
	strall.h symtab.h
d39 3
d52 2
a53 2
array.obj: array.h dbg.h error.h lg.h lgalt.h libdbg.h malloc.h memall.h \
	 stdio.h string.h types.h
d55 2
a56 2
arraytst.obj: array.h dbg.h error.h lg.h lgalt.h libdbg.h malloc.h memall.h \
	 stdio.h stdlib.h types.h
d62 2
a63 2
hash.obj: dbg.h error.h hash.h lg.h lgalt.h libdbg.h malloc.h memall.h \
	 stdio.h stdlib.h string.h types.h
d65 2
a66 2
hashtest.obj: dbg.h error.h hash.h hashtest.h lg.h lgalt.h libdbg.h \
	 malloc.h memall.h mprintf.h stdio.h stdlib.h string.h types.h
d68 3
a70 2
hheap.obj: dbg.h hheap.h lg.h lgalt.h libdbg.h llist.h malloc.h memall.h \
	 stdio.h stdlib.h string.h types.h
d72 2
a73 1
llist.obj: llist.h malloc.h memall.h string.h types.h
d75 2
d79 6
d87 2
a88 2
strall.obj: dbg.h hheap.h lg.h lgalt.h libdbg.h llist.h malloc.h memall.h \
	 stdio.h strall.h string.h types.h
d90 3
a92 3
symtab.obj: ctype.h dbg.h fix.h hheap.h lg.h lgalt.h libdbg.h llist.h \
	 malloc.h memall.h slist.h stdio.h strall.h string.h symtab.h \
	 types.h
d94 3
a96 3
symtest.obj: conio.h ctype.h dbg.h fix.h hheap.h lg.h lgalt.h libdbg.h \
	 llist.h malloc.h memall.h slist.h stdio.h stdlib.h strall.h \
	 symtab.h types.h
@


1.5
log
@Added array.obj to the dstruct lib
@
text
@d17 1
a17 1
PROG_TARGETS = hashtest arraytst
d22 4
a25 3
DSTRUCT_OBJS = hash.obj hheap.obj lllist.obj llist.obj rect.obj strall.obj \
               array.obj
DSTRUCT_HDRS = array.h hash.h hheap.h llist.h rect.h strall.h 
d27 6
d36 2
a37 2
ARRAYTST_OBJS = arraytst.obj array.obj
ARRAYTST_LIBS = _lg.lib _mprintf.lib
d55 4
d66 1
a66 1
	 stdio.h types.h
d76 8
@


1.4
log
@Added hheap, strall, rect
@
text
@d22 3
a24 2
DSTRUCT_OBJS = hash.obj hheap.obj lllist.obj llist.obj rect.obj strall.obj
DSTRUCT_HDRS = array.h hash.h hheap.h llist.h rect.h strall.h
@


1.3
log
@Added dependencies for array type.
@
text
@d22 2
a23 2
DSTRUCT_OBJS = hash.obj lllist.obj llist.obj
DSTRUCT_HDRS = hash.h llist.h array.h
d46 18
@


1.2
log
@Added llist to dstruct.lib
@
text
@d17 1
a17 1
PROG_TARGETS = hashtest
d23 1
a23 1
DSTRUCT_HDRS = hash.h llist.h
d28 3
d41 2
a42 2
hash.obj: dbg.h error.h hash.h lg.h lgalt.h libdbg.h malloc.h memall.h \
	 stdio.h stdlib.h string.h types.h
d44 2
a45 3
llist.obj: llist.h malloc.h memall.h string.h types.h

lllist.obj: llist.h types.h
@


1.1
log
@Initial revision
@
text
@d22 2
a23 2
DSTRUCT_OBJS = hash.obj
DSTRUCT_HDRS = hash.h
d41 1
a41 2
hashlex.obj: dbg.h hashtest.h hashtok.h lg.h lgalt.h libdbg.h malloc.h \
	 memall.h stdio.h stdlib.h string.h types.h
d43 1
a43 2
hashtest.obj: dbg.h error.h hash.h hashtest.h lg.h lgalt.h libdbg.h \
	 malloc.h memall.h mprintf.h stdio.h stdlib.h string.h types.h
@
