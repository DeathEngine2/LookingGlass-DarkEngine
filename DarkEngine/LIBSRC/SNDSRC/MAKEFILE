MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = sndsrc
EXETARGS = playsrc

sndsrc_OBJS = sndsrc
sndsrc_win32_OBJS = playlist refill sndsrcid sndseg rezseg fileseg memseg imaadpcm


sndsrc_HDRS = sndsrc.h playlist.h sndsrcid.h
#   sndsrci.h sndsrcid.h sndseg.h sndsegi.h
#sndsrc_DEFINES = SND_TEST

playsrc_OBJS = playsrc utilmain
playsrc_LIBS = lg mprintf range res \
                cpptools comtools compapis appcore templgen sound \
                sndutil sndsrc
playsrc_COMPILER_LIBS = uuid winmm

%include $(MRC)\make.rc

