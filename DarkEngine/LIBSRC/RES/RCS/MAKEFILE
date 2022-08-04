head	 2.11;
branch   ;
access   ;
symbols  SHIPPED_F95:2.1 oldnmk:1.15.1 FLT_SHIP:1.15.1.2;
locks    ; strict;
comment  @# @;


2.11
date	 1997.05.17.17.45.57;  author JAEMZ;  state Exp;
branches ;
next	 2.10;

2.10
date	 1997.03.06.21.46.48;  author TOML;  state Exp;
branches ;
next	 2.9;

2.9
date	 1997.02.24.23.49.32;  author TOML;  state Exp;
branches ;
next	 2.8;

2.8
date	 1997.02.12.00.30.49;  author TOML;  state Exp;
branches ;
next	 2.7;

2.7
date	 1997.01.14.16.36.38;  author TOML;  state Exp;
branches ;
next	 2.6;

2.6
date	 1996.12.19.10.32.24;  author TOML;  state Exp;
branches ;
next	 2.5;

2.5
date	 1996.11.21.17.15.26;  author mahk;  state Exp;
branches ;
next	 2.4;

2.4
date	 1996.09.14.16.11.03;  author TOML;  state Exp;
branches ;
next	 2.3;

2.3
date	 1996.08.30.10.25.13;  author TOML;  state Exp;
branches ;
next	 2.2;

2.2
date	 1996.04.08.16.54.37;  author TOML;  state Exp;
branches ;
next	 2.1;

2.1
date	 1995.10.02.20.11.44;  author MBAER;  state Exp;
branches ;
next	 1.15;

1.15
date	 1994.12.07.14.18.52;  author mahk;  state Exp;
branches 1.15.1.1;
next	 1.14;

1.14
date	 1994.09.22.10.49.43;  author rex;  state Exp;
branches ;
next	 1.13;

1.13
date	 1994.09.21.09.35.17;  author rex;  state Exp;
branches ;
next	 1.12;

1.12
date	 1994.08.29.14.13.33;  author xemu;  state Exp;
branches ;
next	 1.11;

1.11
date	 1994.08.07.20.22.15;  author xemu;  state Exp;
branches ;
next	 1.10;

1.10
date	 1994.07.21.14.43.11;  author rex;  state Exp;
branches ;
next	 1.9;

1.9
date	 1994.07.05.16.02.28;  author xemu;  state Exp;
branches ;
next	 1.8;

1.8
date	 1994.02.17.11.28.14;  author rex;  state Exp;
branches ;
next	 1.7;

1.7
date	 1993.08.13.22.30.04;  author jaemz;  state Exp;
branches ;
next	 1.6;

1.6
date	 1993.08.05.11.08.33;  author rex;  state Exp;
branches ;
next	 1.5;

1.5
date	 1993.07.23.15.26.41;  author rex;  state Exp;
branches ;
next	 1.4;

1.4
date	 1993.07.22.19.17.15;  author rex;  state Exp;
branches ;
next	 1.3;

1.3
date	 1993.05.11.14.53.47;  author rex;  state Exp;
branches ;
next	 1.2;

1.2
date	 1993.03.22.10.35.55;  author rex;  state Exp;
branches ;
next	 1.1;

1.1
date	 1993.03.04.18.48.09;  author rex;  state Exp;
branches ;
next	 ;

1.15.1.1
date	 1994.12.10.10.30.06;  author lmfeeney;  state Exp;
branches ;
next	 1.15.1.2;

1.15.1.2
date	 1995.02.16.12.12.18;  author lmfeeney;  state Exp;
branches ;
next	 ;


desc
@@


2.11
log
@Added callbacks to resources
@
text
@#
# $Source: x:/prj/tech/libsrc/res/rcs/makefile $
# $Revisiion: $
# $Author: TOML $
# $Date: 1997/03/06 21:46:48 $

MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = res

res_OBJS = lzw lzwfd2bf res restypes resfile resacc refacc \
           resload resmem rescum resbuild resmake resexblk \
           resmisc resarq resthred resagg resguid rescache \
           rescback pkzip

nostackchk_OBJS = pkzip

%if '$(flav)'=='dbg'
res_opt_objs = lzw
%endif

res_HDRS = lzw.h res.h restypes.h resrect.h resguid.h resagg.h resthred.h

%include  $(MRC)\make.rc

@


2.10
log
@*** empty log message ***
@
text
@d5 1
a5 1
# $Date: 1997/02/24 23:49:32 $
d20 1
a20 2
           pkzip

@


2.9
log
@New resource cache logic
@
text
@d5 1
a5 1
# $Date: 1997/02/12 00:30:49 $
d29 1
a29 1
res_HDRS = lzw.h res.h restypes.h resrect.h resguid.h resagg.h
@


2.8
log
@partial lock support
@
text
@d5 1
a5 1
# $Date: 1997/01/14 16:36:38 $
d19 3
a21 3
           resmisc resarq resthred resagg resguid \
           pkzip 
           
@


2.7
log
@pk support
@
text
@d5 1
a5 1
# $Date: 1996/12/19 10:32:24 $
d20 2
a21 2
           pkzip
           #crc32 explode implode
@


2.6
log
@*** empty log message ***
@
text
@d2 1
a2 1
# $Source: x:/prj/tech/libsrc/res/RCS/makefile $
d4 2
a5 2
# $Author: mahk $
# $Date: 1996/11/21 17:15:26 $
d18 4
a21 2
	resload resmem rescum resbuild resmake resexblk \
        resmisc resarq resthred resagg resguid
d23 2
a29 3



@


2.5
log
@Added aggregate member.
@
text
@d2 1
a2 1
# $Source: x:/prj/tech/libsrc/res/rcs/makefile $
d4 2
a5 2
# $Author: TOML $
# $Date: 1996/09/14 16:11:03 $
d21 4
d26 2
@


2.4
log
@Prepared for revision
@
text
@d5 1
a5 1
# $Date: 1996/08/30 10:25:13 $
d19 1
a19 1
        resmisc resarq resthred
d21 1
a21 1
res_HDRS = lzw.h res.h restypes.h resrect.h
@


2.3
log
@Initial revision
@
text
@d5 1
a5 1
# $Date: 1996/04/08 16:54:37 $
@


2.2
log
@*** empty log message ***
@
text
@d2 1
a2 1
# $Source: x:/prj/tech/libsrc/res/RCS/makefile $
d4 2
a5 2
# $Author: MBAER $
# $Date: 1995/10/02 20:11:44 $
d19 1
a19 1
        resmisc
@


2.1
log
@Getting rid of old nmk.
@
text
@d2 1
a2 1
# $Source: r:/prj/lib/src/res/rcs/makefile $
d4 2
a5 2
# $Author: lmfeeney $
# $Date: 1995/02/16 12:12:18 $
d9 1
a9 1
PROJECT = windex
@


1.15
log
@Added resrect.h
@
text
@d1 5
a5 4
#	----------------------------------
#	Makefile for RES library
#	----------------------------------
# 
d7 1
a7 4
DEBUG_ON = 1
DBG_ON = 1
WARN_ON = 1
SPEW_ON = 1
d9 1
a9 9
COMPILER = watcom
SRCDIR = r:\prj\lib\src\res
RELDIR = r:\prj\lib\rel
OBJDIR = obj
LIBDIR = $(RELDIR)
INCDIR = $(RELDIR)
BINDIR = n:\bin
INCPATH = . $(SRCDIR) $(RELDIR)
LIBPATH = $(RELDIR)
d11 1
a11 4
PROG_TARGETS = resdump respack restest lzwtest
LIB_TARGETS = res
INST_TARGETS = res resdump respack
EXTRA_TARGET =
d13 1
a13 4
RES_OBJS = lzw.obj lzwfd2bf.obj res.obj restypes.obj resfile.obj \
	resacc.obj refacc.obj resload.obj resmem.obj rescum.obj resbuild.obj \
	resmake.obj resexblk.obj resmisc.obj
RES_HDRS = lzw.h res.h restypes.h resrect.h
d15 1
a15 2
RESDUMP_OBJS	= resdump.obj
RESDUMP_LIBS	= res.lib _lg.lib mprintf.lib
d17 3
a19 2
RESPACK_OBJS	= respack.obj
RESPACK_LIBS	= res.lib _lg.lib mprintf.lib
d21 1
a21 2
RESTEST_OBJS	= restest.obj
RESTEST_LIBS	= res.lib _lg.lib mprintf.lib
a22 2
LZWTEST_OBJS	= lzwtest.obj
LZWTEST_LIBS	= res.lib _lg.lib mprintf.lib
d24 1
a24 1
!include n:/etc/make.rc
a25 72
#	----------------------------------
#	Object file dependencies
#	----------------------------------

### OPUS MKMF:  Do not remove this line!  Automatic dependencies follow.

lzw.obj objo\lzw.obj objd\lzw.obj: dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h malloc.h memall.h \
	 memmacro.h stat.h stdio.h stdlib.h string.h types.h

lzwfd2bf.obj objo\lzwfd2bf.obj objd\lzwfd2bf.obj: dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h malloc.h memall.h \
	 memmacro.h stat.h stdio.h stdlib.h string.h types.h

lzwtest.obj objo\lzwtest.obj objd\lzwtest.obj: dbg.h dbgmacro.h lg.h lgalt.h lzw.h malloc.h memall.h \
	 memmacro.h stdio.h stdlib.h types.h

refacc.obj objo\refacc.obj objd\refacc.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
	 malloc.h memall.h memmacro.h res.h res_.h restypes.h stat.h \
	 stdio.h stdlib.h string.h types.h

res.obj objo\res.obj objd\res.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
	 malloc.h memall.h memmacro.h res.h res_.h restypes.h stat.h \
	 stdio.h stdlib.h string.h types.h

resacc.obj objo\resacc.obj objd\resacc.obj: _res.h datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h res.h res_.h restypes.h stdio.h stdlib.h \
	 string.h types.h

resbuild.obj objo\resbuild.obj objd\resbuild.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
	 malloc.h memall.h memmacro.h res.h res_.h restypes.h stat.h \
	 stdio.h stdlib.h string.h types.h

rescum.obj objo\rescum.obj objd\rescum.obj: _res.h datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h res.h res_.h restypes.h stdio.h stdlib.h \
	 string.h types.h

resdump.obj objo\resdump.obj objd\resdump.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h res.h res_.h restypes.h stat.h stdio.h \
	 stdlib.h string.h types.h

resexblk.obj objo\resexblk.obj objd\resexblk.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
	 malloc.h memall.h memmacro.h res.h res_.h restypes.h stat.h \
	 stdio.h stdlib.h string.h types.h

resfile.obj objo\resfile.obj objd\resfile.obj: _res.h datapath.h dbg.h dbgmacro.h fcntl.h io.h lg.h lgalt.h \
	 malloc.h memall.h memmacro.h res.h res_.h restypes.h stat.h \
	 stdio.h stdlib.h string.h types.h

resload.obj objo\resload.obj objd\resload.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
	 malloc.h memall.h memmacro.h res.h res_.h restypes.h stat.h \
	 stdio.h stdlib.h types.h

resmake.obj objo\resmake.obj objd\resmake.obj: _res.h datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h res.h res_.h restypes.h stdio.h stdlib.h \
	 string.h types.h

resmem.obj objo\resmem.obj objd\resmem.obj: _res.h datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h memstat.h res.h res_.h restypes.h stdio.h \
	 stdlib.h string.h types.h

resmisc.obj objo\resmisc.obj objd\resmisc.obj: datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h memall.h \
	 memmacro.h mprintf.h res.h restypes.h stdio.h stdlib.h types.h

respack.obj objo\respack.obj objd\respack.obj: datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h res.h restypes.h stat.h stdio.h stdlib.h \
	 string.h types.h

restest.obj objo\restest.obj objd\restest.obj: _res.h conio.h ctype.h datapath.h dbg.h dbgmacro.h fcntl.h \
	 io.h lg.h lgalt.h lzw.h malloc.h memall.h memmacro.h mprintf.h \
	 res.h restypes.h stat.h stdio.h stdlib.h string.h types.h

restypes.obj objo\restypes.obj objd\restypes.obj: datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h memall.h \
	 memmacro.h res.h restypes.h stdio.h stdlib.h types.h
@


1.15.1.1
log
@new make regime
@
text
@d1 4
a4 5
#
# $Source: $
# $Revisiion: $
# $Author: $
# $Date: $
d6 4
a9 1
MAKETOP = $(CWD)
d11 9
a19 1
PROJECT = windex
d21 4
a24 1
%include $(MRC)\env.rc
d26 4
a29 1
%include $(MRC)\init.rc
d31 2
a32 1
LIBTARGS = res
d34 2
a35 3
res_OBJS = lzw lzwfd2bf res restypes resfile resacc refacc \
	resload resmem rescum resbuild resmake resexblk \
        resmisc
d37 2
a38 1
res_HDRS = lzw.h res.h restypes.h
d40 2
d43 1
a43 1
%include  $(MRC)\make.rc
d45 72
@


1.15.1.2
log
@resrect.h
@
text
@d2 1
a2 1
# $Source: r:/prj/lib/src/res/rcs/makefile $
d4 2
a5 2
# $Author: lmfeeney $
# $Date: 1994/12/10 10:30:06 $
d21 1
a21 1
res_HDRS = lzw.h res.h restypes.h resrect.h
@


1.14
log
@Dependencies
@
text
@d29 1
a29 1
RES_HDRS = lzw.h res.h restypes.h
a109 4

resswap.obj objo\resswap.obj objd\resswap.obj: _res.h datapath.h dbg.h dbgmacro.h fcntl.h io.h lg.h lgalt.h \
	 lzw.h malloc.h memall.h memmacro.h res.h res_.h restypes.h stat.h \
	 stdio.h stdlib.h string.h types.h
@


1.13
log
@Added lzwfd2bf.obj
@
text
@d51 1
a51 1
lzw.obj: dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h malloc.h memall.h \
d54 7
a60 1
refacc.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
d64 1
a64 1
res.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
d68 1
a68 1
resacc.obj: _res.h datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h \
d72 1
a72 1
resbuild.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
d76 1
a76 1
rescum.obj: _res.h datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h \
d80 1
a80 1
resdump.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h malloc.h \
d84 1
a84 1
resexblk.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
d88 1
a88 1
resfile.obj: _res.h datapath.h dbg.h dbgmacro.h fcntl.h io.h lg.h lgalt.h \
d92 1
a92 1
resload.obj: _res.h datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h lzw.h \
d96 1
a96 1
resmake.obj: _res.h datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h \
d100 1
a100 1
resmem.obj: _res.h datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h \
d102 1
a102 1
	 stdlib.h types.h
d104 4
a107 1
respack.obj: datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h malloc.h \
d111 5
a115 1
restest.obj: _res.h conio.h ctype.h datapath.h dbg.h dbgmacro.h fcntl.h \
d119 1
a119 1
restypes.obj: datapath.h dbg.h dbgmacro.h lg.h lgalt.h malloc.h memall.h \
@


1.12
log
@added resmisc.c
@
text
@d26 3
a28 3
RES_OBJS = lzw.obj res.obj restypes.obj resfile.obj resacc.obj refacc.obj \
	resload.obj resmem.obj rescum.obj resbuild.obj resmake.obj resexblk.obj \
        resmisc.obj
@


1.11
log
@hey, rel not release
@
text
@d27 2
a28 1
	resload.obj resmem.obj rescum.obj resbuild.obj resmake.obj resexblk.obj
@


1.10
log
@Added LZWTEST
@
text
@d13 1
a13 1
RELDIR = r:\prj\lib\release
@


1.9
log
@r: drive
@
text
@d21 1
a21 1
PROG_TARGETS = resdump respack restest
d38 3
@


1.8
log
@Split res.c and resbuild.c into much files, added res_.h too
@
text
@d12 2
a13 2
SRCDIR = n:\project\lib\src\res
RELDIR = n:\project\lib\release
@


1.7
log
@New depend
@
text
@d26 2
a27 1
RES_OBJS = lzw.obj res.obj restypes.obj resbuild.obj
d50 2
a51 2
res.obj: _res.h datapath.h dbg.h dbgmacro.h fcntl.h io.h lg.h lgalt.h lzw.h \
	 malloc.h memall.h memmacro.h memstat.h res.h restypes.h stat.h \
d54 18
a71 2
resbuild.obj: _res.h datapath.h dbg.h dbgmacro.h fcntl.h io.h lg.h lgalt.h \
	 lzw.h malloc.h memall.h memmacro.h res.h restypes.h stat.h stdio.h \
d74 14
a87 2
resdump.obj: datapath.h dbg.h dbgmacro.h io.h lg.h lgalt.h malloc.h \
	 memall.h memmacro.h res.h restypes.h stat.h stdio.h stdlib.h \
d89 4
@


1.6
log
@Dependencies
@
text
@d46 5
a50 3
lzw.obj: _2d.h _3d.h _babl2.h _dstruct.h _edms.h _lg.h _mouse.h _network.h \
	 _parse.h _res.h _sound.h _testlib.h _ui.h dbg.h dbgmacro.h io.h \
	 lg.h lgalt.h libdbg.h lzw.h malloc.h memall.h memmacro.h stat.h \
d53 2
a54 4
res.obj: _2d.h _3d.h _babl2.h _dstruct.h _edms.h _lg.h _mouse.h _network.h \
	 _parse.h _res.h _sound.h _testlib.h _ui.h datapath.h dbg.h \
	 dbgmacro.h fcntl.h io.h lg.h lgalt.h libdbg.h lzw.h malloc.h \
	 memall.h memmacro.h memstat.h res.h restypes.h stat.h stdio.h \
d57 1
a57 3
resbuild.obj: _2d.h _3d.h _babl2.h _dstruct.h _edms.h _lg.h _mouse.h \
	 _network.h _parse.h _res.h _sound.h _testlib.h _ui.h datapath.h \
	 dbg.h dbgmacro.h fcntl.h io.h lg.h lgalt.h libdbg.h lzw.h malloc.h \
d61 3
a63 5
resdump.obj: _2d.h _3d.h _babl2.h _dstruct.h _edms.h _lg.h _mouse.h \
	 _network.h _parse.h _res.h _sound.h _testlib.h _ui.h datapath.h \
	 dbg.h dbgmacro.h io.h lg.h lgalt.h libdbg.h malloc.h memall.h \
	 memmacro.h res.h restypes.h stat.h stdio.h stdlib.h string.h \
	 types.h
d65 3
a67 5
respack.obj: _2d.h _3d.h _babl2.h _dstruct.h _edms.h _lg.h _mouse.h \
	 _network.h _parse.h _res.h _sound.h _testlib.h _ui.h datapath.h \
	 dbg.h dbgmacro.h io.h lg.h lgalt.h libdbg.h malloc.h memall.h \
	 memmacro.h res.h restypes.h stat.h stdio.h stdlib.h string.h \
	 types.h
d69 1
a69 9
restest.obj: _2d.h _3d.h _babl2.h _dstruct.h _edms.h _lg.h _mouse.h \
	 _network.h _parse.h _res.h _sound.h _testlib.h _ui.h conio.h \
	 ctype.h datapath.h dbg.h dbgmacro.h fcntl.h io.h lg.h lgalt.h \
	 libdbg.h lzw.h malloc.h memall.h memmacro.h mprintf.h res.h \
	 restypes.h stat.h stdio.h stdlib.h string.h types.h

restypes.obj: _2d.h _3d.h _babl2.h _dstruct.h _edms.h _lg.h _mouse.h \
	 _network.h _parse.h _res.h _sound.h _testlib.h _ui.h datapath.h \
	 dbg.h dbgmacro.h lg.h lgalt.h libdbg.h malloc.h memall.h \
@


1.5
log
@Changed _res.lib to res.lib
@
text
@d46 3
a48 1
lzw.obj: dbg.h io.h lg.h lgalt.h libdbg.h lzw.h malloc.h memall.h stat.h \
d51 5
a55 2
res.obj: datapath.h dbg.h fcntl.h io.h lg.h lgalt.h libdbg.h lzw.h malloc.h \
	 memall.h res.h restypes.h stat.h stdio.h stdlib.h string.h types.h
d57 4
a60 2
resbuild.obj: datapath.h dbg.h fcntl.h io.h lg.h lgalt.h libdbg.h lzw.h \
	 malloc.h memall.h res.h restypes.h stat.h stdio.h stdlib.h \
d63 5
a67 2
resdump.obj: datapath.h dbg.h io.h lg.h lgalt.h libdbg.h malloc.h memall.h \
	 res.h restypes.h stat.h stdio.h stdlib.h string.h types.h
d69 5
a73 2
respack.obj: datapath.h dbg.h io.h lg.h lgalt.h libdbg.h malloc.h memall.h \
	 res.h restypes.h stat.h stdio.h stdlib.h string.h types.h
d75 8
a82 2
restest.obj: conio.h ctype.h datapath.h dbg.h fcntl.h io.h lg.h lgalt.h \
	 libdbg.h lzw.h malloc.h memall.h mprintf.h res.h restypes.h stat.h \
d83 2
a84 4
	 stdio.h stdlib.h string.h types.h

restypes.obj: datapath.h dbg.h lg.h lgalt.h libdbg.h malloc.h memall.h \
	 res.h restypes.h stdio.h stdlib.h types.h
@


1.4
log
@Changed lg.lib to _lg.lib in tools
@
text
@d30 1
a30 1
RESDUMP_LIBS	= _res.lib _lg.lib mprintf.lib
d33 1
a33 1
RESPACK_LIBS	= _res.lib _lg.lib mprintf.lib
d36 1
a36 1
RESTEST_LIBS	= _res.lib _lg.lib mprintf.lib
@


1.3
log
@Added restypes.c
@
text
@d30 1
a30 1
RESDUMP_LIBS	= res.lib lg.lib mprintf.lib
d33 1
a33 1
RESPACK_LIBS	= res.lib lg.lib mprintf.lib
d36 1
a36 1
RESTEST_LIBS	= res.lib lg.lib mprintf.lib
@


1.2
log
@Changed hdr targets
@
text
@d26 1
a26 1
RES_OBJS = lzw.obj res.obj resbuild.obj
d65 3
@


1.1
log
@Initial revision
@
text
@d24 1
a24 1
EXTRA_TARGETS = lzw.h res.h restypes.h
d27 1
@
