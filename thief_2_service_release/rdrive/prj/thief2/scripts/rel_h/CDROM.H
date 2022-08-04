/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

//		CDROM.H		CD-ROM INTERFACE
//
//		This is the header file for the CD-ROM interface library, which
//		supplies routines for cd-specific data access.

/*
 * $Source: r:/prj/lib/src/cdrom/RCS/cdrom.h $
 * $Revision: 1.3 $
 * $Author: rex $
 * $Date: 1994/08/29 14:01:10 $
 * $Log: cdrom.h $
 * Revision 1.3  1994/08/29  14:01:10  rex
 * Added header comment, removed audio buffer stuff
 * 
 * Revision 1.2  1994/08/26  18:27:35  rex
 * Totally revamped
 * 
 * 
*/

#ifndef __CDROM_H
#define __CDROM_H

#include <lg.h>
#include <dpmi.h>

//	Some constants

#define CD_SECTOR_SIZE 2048
#define CD_AUDIO_SECTOR_SIZE 2352

//	Public structures

typedef struct {
    uchar VDT; // volume descriptor table
    char  Standard_ID[5]; // should be 'CD001'
    uchar VDV; // volume descriptor version
    uchar unused;
    char  System_Identifier[32];
    char  Volume_Identifier[32];
    uchar unused2[8];
    ulong V_space_SI; // volume space size (Intel)
    ulong V_space_SM; // volume space size (Motorola)
    uchar unused3[32];
    ulong V_set_S; // volume set size
    ulong V_sequence_num; // volume sequence number
    ulong LBS; // logical block size
    ulong PTS_I; // path_table_size (Intel)
    ulong PTS_M; // path_table_size (Motorola)
    ulong loc_typeL_path_table; // location of occurence of type L path table
    ulong loc_opt_typeL_path_table; // location of optional occurence of type L path table
    ulong loc_typeM_path_table; // location of occurence of type M path table
    ulong loc_opt_typeM_path_table; // location of optional occurence of type M path table
    uchar dir_record_root[34]; // drectory record for root directory
    char  V_set_ID[128]; // volume set identifier
    char  publisher_ID[128]; // publisher identifier
    char  data_preparer_ID[128]; // data preparer identifier
    char  application_ID[128]; // application identifier
    char  copyright_file_ID[37]; // copyright file identifier
    char  abstract_file_ID[37]; // abstract file identifier
    char  bibliographic_file_ID[37]; // bibliographic file identifier
    uchar volume_creation_DT[17]; // volume creation date and time
    uchar volume_mod_DT[17]; //volume modification date and time
    uchar volume_exp_DT[17]; // volume expiration date and time
    uchar volume_eff_DT[17]; // volume effective date and time
    uchar file_structure_version; // file structure version
    uchar reserved;
    uchar app_use[512]; // reserved for application use
    uchar reserved2[653];
} cd_PVD;

typedef struct {
  void *next;
  short int attributes;
  short int strategy; //void near *strategy; (no way to specify 2 byte pointer offset)
  short int interrupt_entry; //void near *interrupt_entry;
  char name[8];
  short int reserved;
  uchar first_drive_letter;
  uchar number_drives;
} cd_driver_header;

typedef struct {
    uchar control_code; // should be 10
    uchar low_track_num; // lowest track number
    uchar high_track_num; // highest track number
    ulong lead_out_track_addr; // starting point of lead-out track
} cd_audio_disk_info;

typedef struct {
    uchar control_code; // should be 11
    uchar track_number; // track number
    ulong starting_point; // starting point of track
    uchar track_control_info; // track control information
} cd_audio_track_info;

typedef struct {
	ulong lba;				// logical block address
	ulong len;				// length in bytes
} cd_path_info;

//	Prototypes: CDINIT.C

int cd_init();
int cd_set_curr_drive(int cdnum);
int cd_get_drive_letter();
cd_driver_header *cd_get_driver();
void cd_close();

//	Prototypes: CDREAD.C		(these funcs return 0 on error, 1 on success)

int cd_need_read_buffer_size(int num_sectors);
int cd_set_read_buffer_size(int num_sectors);
int cd_read(void *buffer, ulong sector, int num_sectors);
int cd_read_conv(void *buffer, ulong sector, int num_sectors);
int cd_prefetch(ulong sector, int num_sectors);

//	Prototypes: CDAUDIO.C

int cd_get_audio_disk_info(cd_audio_disk_info *output);
int cd_get_audio_track_info(int track_number, cd_audio_track_info *output);
ulong cd_red2hsg(ulong addr);
ulong cd_get_audio_track_start(int track_number);
// returns starting Red Book Address of track

int cd_play_audio(int addr_mode, ulong start, int num_sectors);
// returns 0 on error, addr_mode: 0 if HSG, 1 if red book addressing
int cd_stop_audio();
int cd_resume_audio();

int cd_read_audio(void *buffer, ulong sector,int num_sectors);
int cd_read_audio_conv(void *buffer, ulong sector, int num_sectors);

//	Prototypes: CDMISC.C

int cd_flush_input_cache();
int cd_get_PVD(cd_PVD *buffer);	// get primary volume descriptor
int cd_get_path_info(char *path, cd_path_info *pinfo);
int cd_benchmark_drive(int starting_sector, int num_sectors_per_read,
	int tot_sectors);	// returns benchmark for CD-ROM drive in Bytes/Sec.

//	Prototypes: CDFCOPY.C

int cd_fast_file_copy(char *path, char *dest);


//	Macro to set data buffer size limit, in sectors

#define cd_set_bufflimit(ns)			(cd_read_buffer_limit = (ns))

extern int cd_read_buffer_limit;		// max size of read buffer in sectors

#endif

