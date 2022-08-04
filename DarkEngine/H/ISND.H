#ifndef _ISND_H
#define _ISND_H

#include <lgsndx.h>

// midi interactive stuff
void       snd_switch_on_beat(snd_handle from, snd_handle to, int flags);
void       snd_switch_on_trigger(snd_handle from, snd_handle to, int flags);
void       snd_random_branch(snd_handle from, snd_handle to, int range, int flags);
void       snd_play_on_end(snd_handle id, int flags);
snd_handle snd_get_current_seq(void);
void       snd_clear_requests(bool);

void       snd_midi_set_next(snd_handle id, snd_handle next);
void       snd_midi_end_on_beat(snd_handle id);
void       snd_midi_end_on_trigger(snd_handle id);


#endif
