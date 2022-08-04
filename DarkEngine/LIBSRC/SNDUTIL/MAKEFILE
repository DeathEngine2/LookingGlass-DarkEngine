MAKETOP = $(CWD)

PROJECT = tech

%include $(MRC)\env.rc

%include $(MRC)\init.rc

LIBTARGS = sndutil
EXETARGS = splice stream oneshot

sndutil_OBJS = streamer rstremer fstremer mstremer splicer rsplicer fsplicer \
					imaadpcm oneshot roneshot foneshot

sndutil_HDRS = sndutil.h
#sndutil_DEFINES = SND_TEST

splice_OBJS = splcmain utilmain
splice_LIBS = lg mprintf range res \
                cpptools comtools compapis appcore templgen sound dsound \
                sndutil
splice_COMPILER_LIBS = uuid winmm

stream_OBJS = strmmain utilmain
stream_LIBS = lg mprintf range res \
                cpptools comtools compapis appcore templgen sound dsound \
                sndutil
stream_COMPILER_LIBS = uuid winmm

oneshot_OBJS = onemain utilmain
oneshot_LIBS = lg mprintf range res \
                cpptools comtools compapis appcore templgen sound dsound \
                sndutil
oneshot_COMPILER_LIBS = uuid winmm



%include $(MRC)\make.rc

