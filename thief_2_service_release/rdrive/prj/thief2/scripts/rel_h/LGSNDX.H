/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: x:/prj/tech/libsrc/snd/RCS/lgsndx.h $
// $Author: TOML $
// $Date: 1996/05/21 12:06:22 $
// $Revision: 1.16 $
//
// @Note (toml 05-21-96): This is a *very* crude merge of shodan\user and
// jabberock\oem tech trees.  There is a *lot* of overlap.
// Since this library is not under further
// development, this should suffice for now.
//

#ifndef __LGSNDX_H
#define __LGSNDX_H

#ifndef __FIX_H
#include <fix.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__DOS4G)
#pragma message ("OK!")
///////////////////////////////////////////////////////////////////////////////
//
// DOS
//

//----------------------------------------------------------
// types
//----------------------------------------------------------


// all the different kinds of samples in the world
typedef enum {
   mono8,
   mono16,
   stereo8,
   stereo16
} snd_samp_bitrate;

// typedef these in case they change
typedef char       snd_handle;
typedef uchar      snd_samp_motion;
typedef uchar      snd_samp_flags;
typedef int        snd_errno;
typedef int        snd_seq_index;
typedef void       LG_SND_DRIVER;
typedef char       snd_card;
typedef short      snd_cfg;
typedef uchar      snd_status;

// function pointer types
typedef void (*snd_miditrig_func)(snd_handle id, int value);
typedef long (*snd_prefix_func)(snd_handle id,int chan,int val);
typedef void (*snd_void_func)(void *data);

// actually they are all callbacks, but this is the normal one
typedef void (*snd_callback)(snd_handle id, void* data);

enum {
   snd_first_cfg,
   snd_io = 0,
   snd_irq,
   snd_dma_8bit,
   snd_dma_16bit,
   snd_use_vse,
   snd_last_cfg
};

typedef struct {
   snd_card type;
   char    *dname;
   char     fullname[256];
   char     cap;     // capabilities field
   snd_cfg  cfg[snd_last_cfg];
} audio_card;

typedef struct {
   uchar    pan;
   uchar    vol;
   uchar    pri;
   uchar    flags;
   void    *data;
} snd_parms;

typedef struct {
   uchar    pan;
   uchar    vol;
   uchar    pri;
   uchar    flags;
   uchar    motion;
   uchar    bitdepth;
   fix24    native_rate;   /* wes */
   fix      play_rate;     /* wes */
   int      snd_ref;
   int      loops;
   uchar   *sample;
   void    *data;
   int      len;
   void    *internal_form;
} snd_digi_parms;

typedef struct {
   uchar          vol;
   uchar          pri;
   uchar          flags;
   long           tempo;   // as percentage of original...
   int            snd_ref;
   void          *data;
   void          *user_data;
   snd_seq_index  seq_num;
   bool           pre_init;      // defaults to false
   void          *internal_form;
   snd_handle     next;          // a sequence to play when this one is done
} snd_midi_parms;

typedef struct {
   snd_handle  id;      // the sequence's handle id
   long        beat;
   long        measure;
} snd_seq_location;

//-----------------------------------------------------------------
// enums
//-----------------------------------------------------------------

enum {
   snd_midi_Null,
   snd_midi_SB,
   snd_midi_SBPro1,
   snd_midi_SBPro2,
   snd_midi_AdLib,
   snd_midi_MT32,
   snd_midi_PCSpeaker,
   snd_midi_Tandy,
   snd_midi_PAS,
   snd_midi_PASPlus,
   snd_midi_AdLibG,
   snd_midi_Ultra,
   snd_midi_MPU401,
   snd_midi_Awe32,
   snd_midi_SoundScape,
   snd_midi_SBPro2_2,
   snd_midi_MPU401_2,
   snd_Wildcard = 19,
   snd_midi_LastCard = 20
};

enum {
   snd_digi_NULL,
   snd_digi_SB,
   snd_digi_SBPro,
   snd_digi_SB16,
   snd_digi_Ultra       = 11,
   snd_digi_SB16_2      = 13,
   snd_digi_SoundScape  = 14,
   snd_digi_SBPro_2     = 15,
   snd_digi_Rap10       = 16,
   snd_digi_LastCard    = 20
};

typedef enum {
   snd_digi_pan,
   snd_digi_volume,
   snd_digi_playback_rate,
   snd_digi_loops,
   snd_digi_position,
   snd_digi_priority,
   snd_digi_user_data
} snd_digi_attr;

//--------------------------------------------------------
// globals
//--------------------------------------------------------

extern LG_SND_DRIVER *snd_digi;
extern uchar          snd_digi_vol;
extern uchar          snd_midi_vol;
extern snd_void_func  snd_finish;
extern snd_void_func  snd_update;

extern snd_void_func  seq_finish;

extern void cdecl   (*snd_nblock)(snd_digi_parms *dprm);

extern snd_errno      snd_error;
extern int            snd_genmidi_or_not;
extern uchar          snd_stereo_reverse;

//------------------------------------------------------------------------
// macros  - do we want this?????? do we *need* it?? really????
//------------------------------------------------------------------------
#define snd_sample_ptr_from_parms(ps)   ((SAMPLE *)ps->internal_form)
#define snd_sequence_ptr_from_parms(ps) ((SEQUENCE *)ps->internal_form)
#define snd_sample_ptr_from_id(pid)     ((SAMPLE *)snd_get_sample(pid))
#define snd_sequence_ptr_from_id(pid)   ((SEQUENCE *)snd_get_sequence(pid))

//------------------------------------------------------------------------
// prototypes
//------------------------------------------------------------------------
void       snd_startup(void);
void       snd_setup(void *d_path, char *prefix);
void       snd_shutdown(void);
snd_errno  snd_card_init(audio_card *digi, audio_card *midi);
snd_errno  snd_set_midi_sequences(int chan_cnt);
snd_errno  snd_start_digital(audio_card *digi_card);
snd_errno  snd_stop_digital(void);
snd_errno  snd_set_digital_channels(int chan_cnt);
snd_errno  snd_start_midi(audio_card *midi_card);
snd_errno  snd_stop_midi(void);
void       snd_lock();
void       snd_unlock();

// digi
snd_handle snd_sample_play(int snd_ref, int len, uchar *smp, snd_digi_parms *dprm);
snd_handle snd_sample_init(uchar *smp, int len, uchar pri, void *data, uchar flags);
snd_errno  snd_sample_start(snd_handle id);
void       snd_sample_stop(snd_handle id);
void       snd_sample_pause(snd_handle id);
void       snd_sample_resume(snd_handle id);

void       snd_end_sample(snd_handle samp_id);
void       snd_kill_all_samples(void);
void       snd_sample_reload_parms(snd_digi_parms *sdp);
snd_status snd_sample_status(snd_handle id);
long       snd_sample_get_attr(snd_handle id, snd_digi_attr attr);
void       snd_sample_set_attr(snd_handle id, snd_digi_attr attr, long val);
snd_errno  snd_sample_fade(snd_handle id, long val, long time, int flags);

// attr macros:
#define    snd_sample_set_volume(id, val)          snd_sample_set_attr((id), snd_digi_volume, (val))
#define    snd_sample_set_pan(id, val)             snd_sample_set_attr((id), snd_digi_pan, (val))
#define    snd_sample_set_playback_rate(id, val)   snd_sample_set_attr((id), snd_digi_playback_rate, (val))
#define    snd_sample_set_priority(id, val)        snd_sample_set_attr((id), snd_digi_priority, (val))
#define    snd_sample_set_data(id, val)            snd_sample_set_attr((id), snd_digi_user_data, (val))
#define    snd_sample_set_loops(id, val)           snd_sample_set_attr((id), snd_digi_loops, (val))
#define    snd_sample_set_position(id, val)        snd_sample_set_attr((id), snd_digi_position, (val))

#define    snd_sample_get_volume(id)               snd_sample_get_attr((id), snd_digi_volume)
#define    snd_sample_get_pan(id)                  snd_sample_get_attr((id), snd_digi_pan)
#define    snd_sample_get_playback_rate(id)        snd_sample_get_attr((id), snd_digi_playback_rate)
#define    snd_sample_get_priority(id)             snd_sample_get_attr((id), snd_digi_priority)
#define    snd_sample_get_data(id)                 snd_sample_get_attr((id), snd_digi_user_data)
#define    snd_sample_get_loops(id)                snd_sample_get_attr((id), snd_digi_loops)
#define    snd_sample_get_position(id)             snd_sample_get_attr((id), snd_digi_position)

void       snd_do_for_all_samples(snd_callback f, void *data);
snd_callback snd_sample_register_eos_callback(snd_callback func, void *data);
void       snd_digi_set_master_volume(long volume);
long       snd_digi_get_master_volume();
int        snd_digi_count_free_handles(int pri);

// new priority stuff
snd_errno  snd_samp_kill_oldest(int pri);

// want this to go away
snd_digi_parms *snd_sample_parms(snd_handle samp_id);
void      *snd_get_sample(snd_handle samp_id);

// midi
snd_handle snd_sequence_play(int snd_ref, uchar *seq_dat, int seq_num, snd_midi_parms *mparm);
void       snd_end_sequence(snd_handle seq_id);
void      *snd_get_sequence(snd_handle seq_id);
void       snd_kill_all_sequences(void);

int        snd_seq_volume(snd_handle seq_id, int val, long msec);
int        snd_seq_get_volume(snd_handle seq_id);
long       snd_seq_tempo(snd_handle seq_id, long tempo, long msec);
long       snd_seq_get_tempo(snd_handle seq_id);
snd_handle snd_seq_init(uchar* dat, int uid, int seq_num,int pri);
snd_errno  snd_seq_start(snd_handle seq_id);
snd_errno  snd_seq_start_ex(snd_handle seq_id);

void       snd_seq_pause(snd_handle seq_id);
void       snd_seq_resume(snd_handle seq_id);
void       snd_seq_branch(snd_handle seq_id, long branch);
void       snd_seq_set_data(snd_handle seq_id, void *data);
void      *snd_seq_get_data(snd_handle seq_id);

int        snd_midi_count_playing();
int        snd_midi_count_free_handles(void);
void       snd_midi_set_master_volume(long volume);
long       snd_midi_get_master_volume();


char      *snd_load_raw(char *fname, int *ldat);

snd_callback      snd_midi_register_beat_callback(snd_callback func);
snd_miditrig_func snd_midi_register_trigger_callback(snd_miditrig_func func);
snd_prefix_func   snd_midi_register_prefix_callback(snd_prefix_func func);
void              snd_midi_register_start_callback(snd_callback func);
snd_callback      snd_midi_register_eos_callback(snd_callback func, void *data);

snd_callback      snd_seq_register_eos_callback(snd_handle seq_id, snd_callback func, void *data);

//-------------------------------------------------------------
// parm + flag defines for digital
//-------------------------------------------------------------

#define SND_PARM_NULL         0xff

#define SND_DEF_PAN           64
#define SND_DEF_VOL           0x7f           /* wes */
#define SND_DEF_PRI           0x3f
#define SND_DEF_TYPE          DIG_F_MONO_8   /* wes */
#define SND_DEF_NATIVE_RATE   fix24_make(22050,0) /* wes */
#define SND_DEF_PLAY_RATE     0              /* wes */
#define SND_DEF_LOOPS         1              /* wes */
#define SND_DEF_TEMPO         100

// status flags

#define SND_FREE              0x0001
#define SND_DONE              0x0002
#define SND_PLAYING           0x0004
#define SND_STOPPED           0x0008

#define SND_FLG_DONE          0x00
#define SND_FLG_DOUBLE_BUFFER 0x01
#define SND_FLG_INUSE         0x02

#define SND_FLG_RAWDATA       0x80
#define SND_FLG_RAWD_STEREO   0x40
#define SND_FLG_SPEED         0x30
#define SND_FLG_RAWMASK       0xF0

// size/scale defines
#define SND_MAX_SAMPLES       16
#define SND_MAX_SEQUENCES     8

// capabilities field
#define SND_CAP_DIGI          0x0001
#define SND_CAP_MIDI          0x0002
#define SND_CAP_GENMIDI       0x0004
#define SND_CAP_STEREO        0x0008
#define SND_CAP_GAIN          0x0010

// what to do when done with a fade
#define SND_FADE_STOP         0x0001
#define SND_FADE_REVERSE      0x0002

// ise flags
#define SND_JUMP_EX           0x0001

//--------------------------------------------------------------------
// error codes
//--------------------------------------------------------------------

#define SND_OK                0x0000

#define SND_GENERIC_ERROR     0x0001
#define SND_OUT_OF_MEMORY     0x0002
#define SND_NO_DRIVER         0x0003
#define SND_NOT_SUPPORTED     0x0004

// specialized errors
#define SND_DRIVER_ALREADY    0x0100
#define SND_NO_DRIVER_NAME    0x0101
#define SND_CANT_INIT_DRIVER  0x0102
#define SND_CANT_FIND_CARD    0x0103
#define SND_CANT_FIND_CFG     0x0104
#define SND_NO_MIDI           0x1000
#define SND_NO_DIGI           0x2000
#define SND_NO_TIMERS         0x4000

// vender specific codes
#define SND_AWE32             0x0001

#define SND_NO_HANDLE         0x0200

#define SND_NULL_HANDLE       -1

// to use with functions which want to return 0->n values
#define SND_PERROR            -1


#elif defined(_WIN32)
///////////////////////////////////////////////////////////////////////////////
//
// Windows
//

typedef int snd_handle;
typedef int snd_errno;

// the generic callback
typedef void (*snd_callback)(int id, void *ref);
typedef void (*snd_void_func)(void *data);



struct IDirectSoundBuffer;
typedef struct IDirectSoundBuffer IDirectSoundBuffer;

// What is a SAMPLE???
typedef struct {
   IDirectSoundBuffer * pDSB;  // pointer to direct sound secondary buffer
   int sample_idx;            // what index it is in our global array
   int flags;
   int curBuf;                // the current audible buffer for double buffering
   int lastBuf;               // the last buffer to get loaded
   int bufSz;                 // how big its halfbuffers are
} SAMPLE;

typedef struct {              // the audio_card struct is just a placeholder
	long reserved;
} audio_card;

// all the different kinds of samples in the world
typedef enum {
   snd_mono8,
   snd_mono16,
   snd_stereo8,
   snd_stereo16
} snd_bitdepth;

#define snd_num_channels(b) (b&snd_stereo8?2:1)
#define snd_num_bits(b)     (b&snd_mono16?16:8)

typedef enum {
   snd_pcm_unsigned = 0x0000,
   snd_pcm_sign = 0x0001,
   snd_pcm_order = 0x0002
} snd_pcm_flags;

typedef struct {
   int32 sample_rate;
   snd_bitdepth  bitdepth;
   snd_pcm_flags pcm_flags;
   uint8 *sample;          // the actual pcm data
   int32 len;
} snd_raw_sample;

typedef struct snd_digi_parms {
   uint8    pan;
   uint8    vol;
   uint8    pri;
   uint8    flags;
   uint8    bitdepth;
   fix24    native_rate;
   fix      play_rate;
   int      snd_ref;
   int      loops;
   uint8   *sample;
   void    *data;
   int      len;
   void    *internal_form;
} snd_digi_parms;

#define snd_sample_ptr_from_parms(ps)   ((SAMPLE *)ps->internal_form)
#define snd_sample_ptr_from_id(pid)     ((SAMPLE *)snd_get_sample(pid))


extern snd_void_func  snd_finish;

//----------------------------------------------------------------------
// prototypes
//----------------------------------------------------------------------

void        snd_startup(void);
void        snd_setup(void *d_path, int8 *prefix);
void        snd_shutdown(void);
snd_errno   snd_card_init(audio_card *digi, audio_card *midi);

snd_digi_parms *snd_sample_parms(snd_handle samp_id);
void           *snd_get_sample(snd_handle samp_id);

void        snd_end_sample(snd_handle samp_id);
void        snd_kill_all_samples(void);
void        snd_sample_reload_parms(snd_digi_parms *sdp);

snd_handle  snd_sample_play(int snd_ref, int len, uint8 *smp, snd_digi_parms *dprm);

snd_errno   snd_start_digital(audio_card *digi_card);
snd_errno   snd_set_digital_channels(int chan_cnt);
snd_errno   snd_stop_digital(void);

snd_callback snd_digi_register_eos_callback(snd_callback func);

int  snd_sample_status(snd_handle id);



void		snd_update();

snd_handle snd_sample_init_double_buffer(snd_raw_sample *raw);
void snd_load_sample_buffer(snd_handle id, int num, int8 *dat, long len);
void snd_set_sample_type(snd_handle id, int type);
void snd_set_sample_playback_rate(snd_handle id, long rate);
int         snd_sample_buffer_ready(snd_handle id);

#define AIL_sample_status(s) snd_sample_status(s->sample_idx)
#define AIL_load_sample_buffer(s,i,b,l) snd_load_sample_buffer(s->sample_idx,i,b,l)
#define AIL_sample_buffer_ready(s) snd_sample_buffer_ready(s->sample_idx)

#define DIG_F_MONO_8             snd_mono8        // PCM data formats
#define DIG_F_MONO_16            snd_mono16
#define DIG_F_STEREO_8           snd_stereo8
#define DIG_F_STEREO_16          snd_stereo16

//-------------------------------------------------------------
// parms + flag defines for digital
//-------------------------------------------------------------

#define SND_PARM_NULL         0xff

#define SND_DEF_PAN           64
#define SND_DEF_VOL           0x7f
#define SND_DEF_PRI           0x3f
#define SND_DEF_TYPE          DIG_F_MONO_8
#define SND_DEF_NATIVE_RATE   fix24_make(22050,0)
#define SND_DEF_PLAY_RATE     0
#define SND_DEF_LOOPS         1
#define SND_DEF_TEMPO         100

// status flags


#define SND_FREE              0x0000
#define SND_DONE              0x0001
#define SND_PLAYING           0x0002

#define SMP_PLAYING           SND_PLAYING

#define SND_STOPPED           0x0004

#define SND_FLG_DONE          0x00
#define SND_FLG_DOUBLE_BUFFER 0x01
#define SND_FLG_INUSE         0x02

#define SND_FLG_RAWDATA       0x80
#define SND_FLG_RAWD_STEREO   0x40
#define SND_FLG_SPEED         0x30
#define SND_FLG_RAWMASK       0xF0

// size/scale defines
#define SND_MAX_SAMPLES       16
#define SND_MAX_SEQUENCES     8

// capabilities field
#define SND_CAP_DIGI          0x0001
#define SND_CAP_MIDI          0x0002
#define SND_CAP_GENMIDI       0x0004
#define SND_CAP_STEREO        0x0008
#define SND_CAP_GAIN          0x0010

// what to do when done with a fade
#define SND_FADE_STOP         0x0001
#define SND_FADE_REVERSE      0x0002

// ise flags
#define SND_JUMP_EX           0x0001

//--------------------------------------------------------------------
// error codes
//--------------------------------------------------------------------

#define SND_OK                0x0000

#define SND_GENERIC_ERROR     0x0001
#define SND_OUT_OF_MEMORY     0x0002
#define SND_NO_DRIVER         0x0003
#define SND_NOT_SUPPORTED     0x0004

// specialized errors
#define SND_DRIVER_ALREADY    0x0100
#define SND_NO_DRIVER_NAME    0x0101
#define SND_CANT_INIT_DRIVER  0x0102
#define SND_CANT_FIND_CARD    0x0103
#define SND_CANT_FIND_CFG     0x0104
#define SND_NO_MIDI           0x1000
#define SND_NO_DIGI           0x2000
#define SND_NO_TIMERS         0x4000

// vender specific codes
#define SND_AWE32             0x0001

#define SND_NO_HANDLE         0x0200

#define SND_NULL_HANDLE       -1

// to use with functions which want to return 0->n values
#define SND_PERROR            -1

///////////////////////////////////////////////////////////////////////////////

#endif

#ifdef __cplusplus
};
#endif

#endif /* !__LGSNDX_H */

