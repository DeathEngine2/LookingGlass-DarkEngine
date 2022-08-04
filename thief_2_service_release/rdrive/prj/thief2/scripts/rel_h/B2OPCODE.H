/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

//		B2OPCODE.H		BABL2 Opcode list
//		Rex E. Bradford (REX)
/*
* $Header: r:/prj/lib/src/babl2/rcs/b2opcode.h 1.12 1994/09/15 16:09:13 rex Exp $
* $Log: b2opcode.h $
 * Revision 1.12  1994/09/15  16:09:13  rex
 * Added OP_MOVIECLEAR and OP_MOVIEPAL
 * 
 * Revision 1.11  1994/09/15  10:53:00  rex
 * Added movie playing opcodes
 * 
 * Revision 1.10  1994/05/19  10:33:53  rex
 * Added new debug opcode - OP_LINENO
 * 
 * Revision 1.9  1993/10/15  13:29:19  rex
 * Added message opcodes, renumbered everything below
 * 
 * Revision 1.8  1993/08/11  16:47:04  rex
 * Removed OP_POP2ND
 * 
 * Revision 1.7  1993/08/11  16:11:16  rex
 * Changed name of OP_POPRETVAL to OP_POP2ND
 * 
 * Revision 1.6  1993/08/05  13:31:44  rex
 * Changed some comments to reflect accurate opcode args
 * 
 * Revision 1.5  1993/07/30  14:21:21  rex
 * Modified comment beside OP_VPCREATE
 * 
 * Revision 1.4  1993/07/21  18:21:57  rex
 * Added OP_PALL opcode
 * 
 * Revision 1.3  1993/07/16  17:27:25  rex
 * Moved text opcodes back into main set
 * 
 * Revision 1.2  1993/06/30  11:18:03  rex
 * Added OP_DRAWPICT opcode, renumbered plug-in opcode ranges
 * 
 * Revision 1.1  1993/06/29  18:38:56  rex
 * Initial revision
 * 
*/

#ifndef B2OPCODE_H
#define B2OPCODE_H

//	Data scopes

#define VAL_CONSTANT	0		// constant numeric value
#define VAL_GLOBAL	1		// global babl2 var
#define VAL_STATIC	2		// file-scoped babl2 var
#define VAL_LOCAL		3		// function-scoped babl2 var
#define VAL_EXTERN	4		// external C var
#define VAL_STRING	5		// string var
#define VAL_MSGARG	6		// message arg

/*	Generated opcodes:
*
*		vvvvvvvv = 32-bit value
*		vvvv = 16-bit value
*		vv   = 8-bit value
*		oooo = 16-bit offset
*		iiii = 16-bit index
*		llll = 16-bit label
*		ff   = 8-bit flags arg
*		rrrr:rrrr = 32-bit ref
*     nnnn = line number
*/

#define OP_INVALID		0		// invalid opcode

#define OP_PUSHI8			0x01	// OP vv - push (expanded) 8-bit immed value
#define OP_PUSHI16		0x02	// OP vvvv - push (expanded) 16-bit immed value
#define OP_PUSHI32		0x03	// OP vvvvvvvv - push 32-bit immediate value
#define OP_PUSHG			0x04	// OP oooo - push global value
#define OP_PUSHS			0x05	// OP oooo - push static value
#define OP_PUSHL			0x06	// OP oooo - push local/arg value
#define OP_PUSHE			0x07	// OP iiii - push external value
#define OP_PUSHGOFF		0x08	// OP oooo - push global address
#define OP_PUSHSOFF		0x09	// OP oooo - push static address
#define OP_PUSHLOFF		0x0A	// OP oooo - push local/arg address
#define OP_PUSHEOFF		0x0B	// OP iiii - push external address
#define OP_PUSHM			0x0C	// OP vv - push msg arg (vv holds size/offset)
#define OP_PUSHSTR		0x0D	// OP rrrr:rrrr - push string ref
#define OP_POP				0x0E	// OP - pop top stack value & discard

#define OP_ADD				0x0F	// '+'	(all binary ops single byte)
#define OP_SUB				0x10	// '-'
#define OP_MUL				0x11	// '*'
#define OP_DIV				0x12	// '/'
#define OP_MOD				0x13	// MOD
#define OP_ARITHAND		0x14	// '&'
#define OP_ARITHOR		0x15	// '|'
#define OP_ARITHXOR		0x16	// '^'
#define OP_LOGAND			0x17	// '&&'
#define OP_LOGOR			0x18	// '||'
#define OP_TESTEQ			0x19	// '=='
#define OP_TESTNE			0x1A	// '!='
#define OP_TESTGT			0x1B	// '>'
#define OP_TESTGE			0x1C	// '>='
#define OP_TESTLT			0x1D	// '<'
#define OP_TESTLE			0x1E	// '<='

#define OP_NEG				0x1F	// UNARY '-'	(all unary ops single byte)
#define OP_NOT				0x20	// '!'

#define OP_INDEX			0x21	// OP - pop addr & index, restack indexed addr
#define OP_INDEXFETCH	0x22	// OP - pop addr & index, get & restack value
#define OP_STORE			0x23	// OP - pop val & addr, store val into addr

#define OP_BEQ				0x24	// OP llll - pop stack, branch if 0
#define OP_CALL			0x25	// OP rrrr:rrrr - push retaddr & CALL
#define OP_RETURN			0x26	// OP vvvv - pop n bytes & return addr, return
#define OP_ENTERFUNC		0x27	// OP vvvv - push bp, add n to sp
#define OP_RESERVED27	0x28	// reserved
#define OP_STACKARG		0x29	// OP - pull arg from expstack to real stack
#define OP_EXCALL			0x2A	// OP iiii vv - call exfunc iiii with vv args
#define OP_TESTCASEINT	0x2B	// OP llll - pop val, == top?, branch if NE
#define OP_TESTCASESTR	0x2C	// OP llll - pop str, == top?, branch if NE
#define OP_GOTO			0x2D	// OP llll - branch to label

#define OP_RUN				0x2E	// OP ff llll - run func/script, with options
#define OP_SIGNAL			0x2F	// OP - pop arg,signal,dest, do signal
#define OP_WAITSIGNAL	0x30	// OP - pop arg,signal, block on it
#define OP_BLOCK			0x31	// OP - give up timeslice
#define OP_WAITTIME		0x32	// OP - pop game time, block
#define OP_ELAPSETIME	0x33	// OP - pop game time delay, block
#define OP_DELAY			0x34	// OP - pop realtime delay, block

#define OP_MENU			0x35	// OP oooo - Do menu at offset
#define OP_SAY				0x36	// OP - pop str, pop speaker, SAY
#define OP_WAITKEYCLICK 0x37	// OP ff - block on keyclick, ff = pop timeout

#define OP_MSGSENDSTART	0x38	// OP - grab msg to begin filling in
#define OP_MSGSENDARG	0x39	// OP vv - pop arg, place carefully in msg struct
#define OP_MSGSEND		0x3A	// OP vv - pop dest, send msg vv
#define OP_MSGRECEIVE	0x3B	// OP ff - wait for msg, maybe timeout
#define OP_MSGRECEIVETEST 0x3C	// OP vv llll - test msg vs. vv, branch if .ne.
#define OP_MSGRECEIVEDONE	0x3D	// OP - free msg

#define OP_BADRET			0x3E	// OP - if hit this, ran into end of func
#define OP_EXIT			0x3F	// OP - terminate thread

//	--------------------------------------------------------
//	These opcodes are 'ranged' opcodes for user installation
//	--------------------------------------------------------
//
//	Animation range - for animation playing and control

#define OP_ANIMNEW		0x40	// OP ff - pop args, animnew, wait if flag
#define OP_ANIMCHANGE	0x41	// OP ff - pop args, animchange, wait if flag
#define OP_ANIMWAIT		0x42	// OP - pop animId, animwait
#define OP_ANIMKILL		0x43	// OP - pop animId, animkill
#define OP_ANIMRATE		0x44	// OP - pop animId & rate, animrate
#define OP_ANIMSPEED		0x45	// OP - pop args, animspeed
#define OP_ANIMPRELOAD	0x46	// OP - pop animRef, preload frames

//	Palette range

#define OP_FADEDOWN		0x48	// OP - pop fadespeed, fade down
#define OP_FADEUP			0x49	// OP - pop fadespeed, fade up
#define OP_PALL			0x4A	// OP - pop ref, change pall
#define OP_PALLANIM		0x4B	// OP - pop ref, change pall

//	Graphics range - for graphics output other than animation

#define OP_VPCREATE		0x50	// OP tt - pop rect & depth, create viewport (transp flag)
#define OP_VPDELETE		0x51	// OP - pop viewport id, delete viewport
#define OP_VPMOVEBY		0x52	// OP - pop viewport id & delta, move
#define OP_VPMOVETO		0x53	// OP - pop viewport id & newloc, move
#define OP_VPHIDE			0x54	// OP - pop viewport id, hide
#define OP_VPSHOW			0x55	// OP - pop viewport id, show
#define OP_VPOPEN			0x56	// OP - pop viewport id, open
#define OP_VPCLOSE		0x57	//	OP ff - pop viewport id, rect if flags, close
#define OP_DRAWSETFONT	0x58	// OP - pop font id, set it
#define OP_DRAWSETCOLOR	0x59	// OP - pop color, set it
#define OP_DRAWSETBACKCOLOR 0x5A	// OP - pop back color, set it
#define OP_DRAWSETCLIPRECT	0x5B	// OP - pop cliprect, set it
#define OP_DRAWCLEAR		0x5C	// OP - pop color, clear
#define OP_DRAWLINE		0x5D	// OP - pop 2 points, draw line
#define OP_DRAWBOX		0x5E	// OP - pop rect, draw box
#define OP_DRAWRECT		0x5F	// OP - pop rect, draw rect
#define OP_DRAWBITMAP	0x60	// OP - pop ref & x,y, draw bitmap
#define OP_DRAWTEXT		0x61	// OP - pop point & qstring, draw text
#define OP_DRAWPICT		0x62	// OP ff - If flags 1, pop rect, else pop x,y

//	Sound & music range

#define OP_SOUND			0x68	// OP ff - If flags 1, wait till done
#define OP_MUSIC			0x69	// OP ff - If flags 1, wait till done

//	Movie range - for movie playing and control

#define OP_MOVIEPREP		0x70	// OP - pop fd or id, movieprep or movieprepres
#define OP_MOVIEPLAY		0x71	// OP ff - pop movie* & xy, play movie, wait if flags
#define OP_MOVIECLEAR	0x72	// OP - pop movie*, movieclearcanvas
#define OP_MOVIEPAL		0x73	// OP - pop movie*, moviesetpal
#define OP_MOVIEWAIT		0x74	// OP - pop movie*, moviewait
#define OP_MOVIEKILL		0x75	// OP - pop movie*, moviekill

//	Debugging

#define OP_LINENO			0x7F	// OP nnnn - line number debug opcode

#endif


