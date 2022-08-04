/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*	SNDCFG.H		
 *	Wes Carroll
 *      November 1994
 *
 *      This is the header file for the soundcard-configuration system,
 *      which includes procedures for reading and writing config files,
 *      which in turn contain all the information necessary to start,
 *      initialize, and use a (MIDI and/or digital) sound card.
 *
 * $Header: r:/prj/lib/src/sndcfg/rcs/sndcfg.h 1.8 1995/03/30 16:42:38 wes Exp $
 * $Log: sndcfg.h $
 * Revision 1.8  1995/03/30  16:42:38  wes
 * new regime
 *  new prototypes
 * 
 * Revision 1.7  1995/01/19  16:07:04  wes
 * Added sndcfg_initialize_structure
 *  tidied up header
 * 
 * Revision 1.6  1995/01/04  00:28:30  wes
 * Extra namespace for card names and soundcard_id's
 * 
 * Revision 1.5  1994/12/14  16:32:44  wes
 * *** empty log message ***
 * 
 * Revision 1.4  1994/10/25  17:27:41  wes
 * removed spurious ailthree dependency
 * 
 * Revision 1.3  1994/10/24  18:03:11  wes
 * *** empty log message ***
 * 
 * Revision 1.2  1994/10/21  07:14:54  wes
 * new prototype for _write_ ...
 * 
 * Revision 1.1  1994/10/17  14:38:52  wes
 * Initial revision
 * 
 */

#ifndef __SNDCFG_H
#define __SNDCFG_H

#include <lg.h>
#include <error.h>
#include <lgsndx.h>

// Revision 3/24/95 wes:

//      * NEW NAME *                                 * OLD NAME *
//      ------------                                 ------------

//      char     cap;     // capabilities field
      
//                                                   char midi_name[16];// approved MIDI card name
//      char     *dname;

//                                                   int  midi_num;	// approved MIDI card number
//      char     type;

//                                                   int  midi_irq;	// MIDI's irq number or SND_IRQ_DEFAULT
//      short    irq;

//                                                   int  midi_dma16;	// MIDI's 16-bit dma number or SND_DMA_DEFAULT
//      short    dma_16bit;

//                                                   int  midi_dma8;	// MIDI's 8-bit dma number or SND_DMA_DEFAULT
//      short    dma_8bit;

//                                                   int  midi_port;	// MIDI's port number
//      short    io;
    
bool is_audio_variable              ( char *var                   );
errtype audio_write_card_cfg        ( char *cfgname, audio_card *digi, audio_card *midi );
errtype audio_read_card_cfg         ( char *cfgname, audio_card *digi, audio_card *midi );

#endif // SNDCFG 

