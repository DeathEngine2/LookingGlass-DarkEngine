/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: r:/prj/lib/src/snd/rcs/lgsndimp.h $
 * $Revision: 1.1 $
 * $Author: dc $
 * $Date: 1994/12/01 02:06:31 $
 */

// non-software implementation layer numbers
// midi controllers/positions
// card number id's
// so on

/****************** card numbers */
#define GENERIC				0
#define SOUNDBLASTER			1
#define SOUNDBLASTERPRO		2
#define SB16               3
#define ADLIB					4
#define MT32					5
#define PCSPEAKER				6
#define TANDY					7
#define PAS						8
#define PAS2					9
#define ADLIBGOLD				10
#define GRAVISULTRASOUND   11
#define GRAVISULTRASTUPID  11
#define GENMIDI            12
#define AWE32              13
#define SOUNDSCAPE         14
#define SOUNDBLASTERPRO2	15
#define RAP_10             16

/****************** MIDI messages */
#define MIDI_NOTE_OFF			0x80
#define MIDI_NOTE_ON				0x90
#define MIDI_POLY_PRESSURE		0xa0
#define MIDI_CONTROL_CHANGE	0xb0
#define MIDI_PROGRAM_CHANGE	0xc0
#define MIDI_CHANNEL_PRESSURE	0xd0
#define MIDI_PITCH_WHEEL		0xe0

#define MIDI_CTRL_VOLUME		0x07
#define MIDI_CTRL_PAN			0x0a
#define MIDI_CTRL_EXPRESSION	0x0b
#define XMIDI_BANK_SELECT		0x72
#define MIDI_CTRL_RESET			0x79
#define MIDI_CTRL_ALL_NOTES_OFF	0x7b

/****************** MIDI controllers */
#define MIDI_PART_VOLUME				7
#define MIDI_MODULATION					1
#define MIDI_PANPOT						10
#define MIDI_EXPRESSION					11
#define MIDI_SUSTAIN						64
#define XMIDI_PATCH_BANK_SELECT		114
#define XMIDI_CHANNEL_LOCK				110
#define XMIDI_CHANNEL_LOCK_PROTECT 	111
#define XMIDI_VOICE_PROTECT			112
#define XMIDI_CALLBACK_TRIGGER		119
#define XMIDI_TIMBRE_PROTECT			113


