/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// header for vse (vender specific extentions)

#ifndef __SND_VSE_H
#define __SND_VSE_H

typedef struct
{
   char *bank_name;
   snd_errno err;
   snd_handle  init_seq;
   long ram;
   int num_maps;     // right now only one works so this is
   int maps[128];    // not used
} snd_awe32_sfont;

// various error codes
enum {
 AWE_OK,         
 AWE_FILE_OPEN,  
 AWE_FILE_READ,  
 AWE_MEMORY,     
 AWE_MEM_MAP,    
 AWE_BAD_HEADER, 
 AWE_SF_INFO,    
 AWE_PACKET_READ,
 AWE_STREAM,     
 AWE_DOSMEMORY,  
 AWE_PRESET_LOAD,
 AWE_FREE
};

// prototypes
void snd_midi_vse(int type);
void snd_stop_midi_vse(void);

snd_errno snd_load_awe32(MDI_DRIVER *mdi, char *bankname);
void      snd_free_awe32(MDI_DRIVER *mdi);


#endif // __SND_VSE_H
