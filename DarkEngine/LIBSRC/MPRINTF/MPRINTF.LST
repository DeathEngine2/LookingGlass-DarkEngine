
Module: x:\prj\windex\libsrc\mprintf\mprintf.c
Group: 'DGROUP' CONST,CONST2,_DATA,_BSS
Group: 'FLAT' 

Segment: '_TEXT' PARA  000015f4 bytes  

/*
 * $Source: x:/prj/windex/libsrc/mprintf/RCS/mprintf.c $
 * $Revision: 1.15 $
 * $Author: NOAH $
 * $Date: 1996/02/14 14:46:38 $
 * 
 * Monochrome printf.
 */

/* things to do - logon/logoff w/o destroying fname */

#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>

#include <lgsprntf.h>
#include <mprintf.h>

#define MONO_BASE    0xb0000
#define CGA_BASE     0xb8000
#define MONO_PAGE_SZ 0x01000

#define MONO_CARD    0
#define CGA_CARD     1

/* video bios constants. */
#define VBIOS_INT    0x10
#define VB_GET_COMBO 0x1a00
#define VB_SET_XY    0x0200

/* monochrome register ports. */
#define M_CNTRL      0x3b8             /* mono controller register */
#define M_SRX_ADR    0x3b4             /* mono sequencer address port */
#define M_SRX_DATA   0x3b5             /* mono sequencer data port */
#define SR_CTP       0x0a              /* cursor top and bottom */
#define SR_CBT       0x0b
#define SR_AHI       0x0c              /* page address hi and low */
#define SR_ALO       0x0d
#define SR_CLH       0x0e              /* seq cursor location high */
#define SR_CLL       0x0f              /* low */

#define C_SRX_ADR    0x3d4             /* cga sequencer address port */
#define C_SRX_DATA   0x3d5             /* cga sequencer data port */

#define COMBO_MONO   1
#define MONO_WID     80
#define MONO_HGT     25
#define MONO_ROW     (2*MONO_WID)
#define MONO_OFF     0
#define MONO_ON      1
#define MONO_TOG     2
#define MONO_FILE    "mprintf.log"
#define MONO_DUMP    "mono.dmp"

/* have we yet called mono_init()? */
static bool mono_done_init = FALSE;
              
/* TRUE if there's a monochrome screen present. */
static bool mono_screen = FALSE;

/* MONO_ON when monochrome printing enabled. */
static uchar mono_mode = MONO_OFF;

/* cursor position on the mono screen. - abs cursor pos */
static uchar mono_x = 0;
static uchar mono_y = 0;

typedef struct {
   uchar axis;
   char  coord, win;
   uchar w, h;
   uchar x, y;
   uchar *base;
   uchar lcoor[MONO_WIN_MAX][2];
   char  lfocus;
   uchar *addr;
   uchar flags;
   char  *msg;
} page_parms;

static page_parms _mono_screens[MONO_MAX_PAGES];
/* last is for flip/unflip  - init to 1 so setpage 0 at start does stuff */
static char       _cur_mono_page=1, _last_mono_page=-1, _cur_mono_focus=0;
static uint       _inited_mpages=0;    /* bitfielded list of which pages are inited */
static uchar      _cur_card=0;         /* MDA */

static char *def_wrap_msg=MONO_WRAP_MESSAGE;

static int srx_adr[2]={M_SRX_ADR,C_SRX_ADR};
static int srx_data[2]={M_SRX_DATA,C_SRX_DATA};

#define cur_stru     (_mono_screens[_cur_mono_page])
#define split_axis   ((cur_stru).axis)
#define split_coord  ((cur_stru).coord)
#define split_win    ((cur_stru).win)
#define split_w      ((cur_stru).w)
#define split_h      ((cur_stru).h)
#define split_x      ((cur_stru).x)
#define split_y      ((cur_stru).y)
#define split_base   ((cur_stru).base)
#define page_addr    ((cur_stru).addr)
#define split_lcoor  ((cur_stru).lcoor)
#define split_lfocus ((cur_stru).lfocus)
#define split_flags  ((cur_stru).flags)
#define split_msg    ((cur_stru).msg)

#ifdef OLD_WAY
/* static split screen stuff */
static uchar split_axis  = MONO_AXIS_X;
static char  split_coord  = -1;
static char  split_win    = -1;	/* which window is active, -1 for no windows, else 1 or 2 */
static uchar split_w=MONO_WID, split_h=MONO_HGT;
static uchar split_x=0, split_y=0;
static uchar *split_base=MONO_BASE;
static uchar split_lcoor[MONO_WIN_MAX][2]={{0xff,0xff},{0xff,0xff}};
static char  split_lfocus=-1;
#endif

/* current drawing attribute */
static uchar mono_attr = 7; /* MA_NORMAL */

/* handle of the log file or -1 if no log file. */
static int mono_file = -1;
static uchar mlog=0;                   /* last/cur log file parms, mostly for which windows to log */
/* name of last log file */
static char last_lf[PATH_MAX]=MONO_FILE; /* pretend default was last */

int _mprint(char *s, int n);

// just extern this and set it if you want to see things go...
void (*mono_spc_func)(char *,int)=NULL;

#define _mono_spc_check(s,n) \
   if (mono_spc_func!=NULL)  \
      (*mono_spc_func)(s,n)

/* memset that sets n shorts starting a s to c. */
void *smemset (void *s, short c, int n);
#pragma aux smemset=       \
   "push edi"              \
   "rep  stosw"            \
   "pop  eax"              \
   parm [edi] [eax] [ecx]  \
   modify [edi eax ecx];

#define out_mda(reg,val) outp(M_SRX_ADR,reg); outp(M_SRX_DATA,val)

#define out_set(card,reg,val)\
   outp(srx_adr[card],reg);\
   outp(srx_data[card],val)

#ifdef USE_OLD_MONO_DETECT
bool mono_detect(void)
{
   union REGS r;

   r.w.ax = VB_GET_COMBO;
   int386 (VBIOS_INT, &r, &r);
   return ((r.h.bh==COMBO_MONO)||(r.h.bl==COMBO_MONO));
}
#endif /* USE_OLD_MONO_DETECT */

#ifdef USE_VBIO_CALL
/* video bios call */
int vbio_call (int parm_ax)
{
   union REGS r;

   r.w.ax = parm_ax;
   int386 (VBIOS_INT, &r, &r);
   return r.w.bx;
}
#endif /* USE_VBIO_CALL */

int mono_get_combo(void);
#pragma aux mono_get_combo=\
   "mov eax,0x1a00" \
   "int 0x10" \
   "mov eax,ebx" \
   "and eax,0xffff" \
   modify exact [ebx];

/* returns TRUE if the secondary display is monochrome. */
bool mono_detect(void)
{
#ifdef WIN32
   // Fake this out under Windows, for now assume there is a monochrome
   // board at 0xB000 and monitor present and hope for the best.  The
   // more this crashes on other setups, the sooner we'll have to come
 0000  53                mono_detect_    push    ebx
 0001  52                                push    edx

 0002  89 c2                             mov     edx,eax
 0004  81 e2 ff 00 00 00                 and     edx,000000ffH

   // up with something else.
   return TRUE;
#else
 000a  b8 00 1a 00 00                    mov     eax,00001a00H
 000f  cd 10                             int     10H
 0011  89 d8                             mov     eax,ebx
 0013  25 ff ff 00 00                    and     eax,0000ffffH
 0018  83 fa 01                          cmp     edx,0001H
 001b  74 0d                             je      L1
 001d  c1 f8 08                          sar     eax,08H
 0020  83 f8 01                          cmp     eax,0001H
 0023  74 05                             je      L1
 0025  83 f8 05                          cmp     eax,0005H
 0028  75 05                             jne     L2
 002a  b0 01             L1              mov     al,01H
 002c  5a                                pop     edx
 002d  5b                                pop     ebx
 002e  c3                                ret     
 002f  30 c0             L2              xor     al,al

   int combo;

   combo=mono_get_combo();
   // note the 5 is for Jaemz's machine which bites.
 0031  5a                                pop     edx
 0032  5b                                pop     ebx
 0033  c3                                ret     

   return (combo&0xff)==COMBO_MONO || (combo>>8)==COMBO_MONO || (combo>>8)==5;
#endif
 0034  52                mono_setmode_   push    edx
 0035  8a 15 00 00 00 00                 mov     dl,_mono_mode+158aH

}

 003b  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_screen+3d80H,00H
 0042  74 14                             je      L5

/* sets the monochrome printing mode to the mode passed in.  it can be one of
   MONO_ON, MONO_OFF, or MONO_TOG.  returns new mono mode. */
 0044  83 f8 02                          cmp     eax,0002H
 0047  75 0d                             jne     L4

int mono_setmode (int mode)
 0049  80 fa 01                          cmp     dl,01H
 004c  75 04                             jne     L3

{
 004e  30 d2                             xor     dl,dl

   if (mono_screen)
 0050  eb 06                             jmp     L5

   {  /* lets do this only if we have a mono screen */
	   if (mode == MONO_TOG)
	   {
 0052  b2 01             L3              mov     dl,01H
 0054  eb 02                             jmp     L5

	      if (mono_mode == MONO_ON)
	         mono_mode = MONO_OFF;
	      else
	         mono_mode = MONO_ON;
	   }
 0056  88 c2             L4              mov     dl,al

	   else
 0058  31 c0             L5              xor     eax,eax
 005a  88 d0                             mov     al,dl

	      mono_mode = mode;
   }
// it really already should be this
 005c  88 15 00 00 00 00                 mov     _mono_mode+1588H,dl
 0062  5a                                pop     edx
 0063  c3                                ret     

// else mono_mode=MONO_OFF;

 0064  53                mono_set_flags_ push    ebx
 0065  51                                push    ecx
 0066  89 c1                             mov     ecx,eax
 0068  89 d3                             mov     ebx,edx

   return mono_mode;
 006a  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 0070  c1 fa 18                          sar     edx,18H
 0073  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 007a  29 d0                             sub     eax,edx
 007c  c1 e0 03                          shl     eax,03H
 007f  01 d0                             add     eax,edx
 0081  88 88 14 00 00 00                 mov     __mono_screens+8888H[eax],cl

}
 0087  f6 c1 04                          test    cl,04H
 008a  74 0a                             je      L6
 008c  85 db                             test    ebx,ebx
 008e  74 06                             je      L6


 0090  89 98 15 00 00 00                 mov     __mono_screens+9889H[eax],ebx

/* setup for wrapping on mono as opposed to scrolling */
void mono_set_flags(int flags, char *msg)
{
   split_flags=flags;
 0096  59                L6              pop     ecx
 0097  5b                                pop     ebx
 0098  c3                                ret     
 0099  8d 40 00                          lea     eax,+0H[eax]

   if ((flags&MONO_FLG_MSG)&&(msg!=NULL))
	   split_msg=msg;
}

 009c  53                mono_init_      push    ebx
 009d  51                                push    ecx
 009e  52                                push    edx

/* fire up the monochrome screen printer.  returns TRUE if there is a
 009f  c6 05 00 00 00 00 
       01                                mov     byte ptr _mono_done_init+5c6H,01H

   monochrome screen present. */
 00a6  30 f6                             xor     dh,dh
 00a8  88 35 00 00 00 00                 mov     _mono_y+3588H,dh
 00ae  88 35 00 00 00 00                 mov     _mono_x+3588H,dh
 00b4  89 c2                             mov     edx,eax
 00b6  81 e2 ff 00 00 00                 and     edx,000000ffH

bool mono_init(void)
 00bc  b8 00 1a 00 00                    mov     eax,00001a00H
 00c1  cd 10                             int     10H
 00c3  89 d8                             mov     eax,ebx
 00c5  25 ff ff 00 00                    and     eax,0000ffffH
 00ca  83 fa 01                          cmp     edx,0001H
 00cd  74 0d                             je      L7
 00cf  c1 f8 08                          sar     eax,08H
 00d2  83 f8 01                          cmp     eax,0001H
 00d5  74 05                             je      L7
 00d7  83 f8 05                          cmp     eax,0005H
 00da  75 04                             jne     L8
 00dc  b0 01             L7              mov     al,01H
 00de  eb 02                             jmp     L9
 00e0  30 c0             L8              xor     al,al

 00e2  31 d2             L9              xor     edx,edx
 00e4  88 c2                             mov     dl,al

{
 00e6  a2 00 00 00 00                    mov     _mono_screen+0a2c2H,al
 00eb  89 d3                             mov     ebx,edx
 00ed  84 c0                             test    al,al
 00ef  74 26                             je      L12
 00f1  83 fa 02                          cmp     edx,0002H
 00f4  75 1c                             jne     L11
 00f6  80 3d 00 00 00 00 
       01                                cmp     byte ptr _mono_mode+3d80H,01H
 00fd  75 0a                             jne     L10
 00ff  30 ed                             xor     ch,ch
 0101  88 2d 00 00 00 00                 mov     _mono_mode+2d88H,ch
 0107  eb 0e                             jmp     L12
 0109  c6 05 00 00 00 00 
       01                L10             mov     byte ptr _mono_mode+5c6H,01H
 0110  eb 05                             jmp     L12
 0112  a2 00 00 00 00    L11             mov     _mono_mode+0a205H,al
 0117  a0 00 00 00 00    L12             mov     al,_mono_mode+0a000H

   bool r;
 011c  88 c3                             mov     bl,al


   mono_done_init=TRUE;
 011e  84 c0                             test    al,al
 0120  74 0c                             je      L13
 0122  ba 01 00 00 00                    mov     edx,00000001H
 0127  31 c0                             xor     eax,eax
 0129  e8 00 00 00 00                    call    mono_setpage_

   mono_x=mono_y=0;
   mono_screen=mono_detect();
   r=mono_setmode(mono_screen);
   if (r) mono_setpage(0,TRUE);        /* put cursor at upper left, get to page 0 */
   return r;
}

/* Mono Logging functions, logon, logoff, logdel */

/* turn on logging of monochrome activities.
 *  if how&MONO_LOG_CON use the last file logged to
 012e  88 d8             L13             mov     al,bl
 0130  5a                                pop     edx
 0131  59                                pop     ecx
 0132  5b                                pop     ebx
 0133  c3                                ret     

 *  if how&MONO_LOG_DEF always use default log
 *  if how&MONO_LOG_NEW erase existing log file
 *  if CON and DEF, CON overrides, so there
 0134  51                mono_logon_     push    ecx
 0135  56                                push    esi
 0136  57                                push    edi
 0137  89 c1                             mov     ecx,eax
 0139  89 d0                             mov     eax,edx

 013b  8b 35 00 00 00 00                 mov     esi,_mono_file+358bH

 * which uses the MONO_LOG_ALLWIN, or FULLSC defines, or | together MONO_WIN_ONE,TWO,etc
 */
 0141  ba 21 00 00 00                    mov     edx,00000021H
 0146  83 fe ff                          cmp     esi,0ffffH
 0149  74 09                             je      L14

int mono_logon (char *fn, int how, int which)
 014b  b8 ff ff ff ff                    mov     eax,0ffffffffH
 0150  5f                                pop     edi
 0151  5e                                pop     esi
 0152  59                                pop     ecx
 0153  c3                                ret     

{
 0154  a8 08             L14             test    al,08H
 0156  74 07                             je      L15

	int open_flags=O_WRONLY|O_CREAT;
 0158  b9 00 00 00 00                    mov     ecx,offset _last_lf+0b907H

   if (mono_file != -1)
 015d  eb 0d                             jmp     L17
 015f  85 c9             L15             test    ecx,ecx
 0161  74 04                             je      L16
 0163  a8 01                             test    al,01H
 0165  74 05                             je      L17

      return -1;
 0167  b9 08 00 00 00    L16             mov     ecx,offset L142

   if	(how&MONO_LOG_CON)
 016c  a8 02             L17             test    al,02H
 016e  74 05                             je      L18

		fn = last_lf;							/* continue with last */
 0170  80 ca 40                          or      dl,40H

	else if ((fn == NULL)||(how&MONO_LOG_DEF))
 0173  eb 03                             jmp     L19

      fn = MONO_FILE;
 0175  80 ca 10          L18             or      dl,10H

	if (how&MONO_LOG_NEW)
 0178  81 f9 00 00 00 00 L19             cmp     ecx,offset _last_lf+0f981H
 017e  74 21                             je      L22
 0180  bf 00 00 00 00                    mov     edi,offset _last_lf+0bf21H

		open_flags|=O_TRUNC;
 0185  89 ce                             mov     esi,ecx
 0187  57                                push    edi
 0188  8a 06             L20             mov     al,[esi]
 018a  88 07                             mov     [edi],al
 018c  3c 00                             cmp     al,00H
 018e  74 10                             je      L21
 0190  8a 46 01                          mov     al,+1H[esi]
 0193  83 c6 02                          add     esi,0002H
 0196  88 47 01                          mov     +1H[edi],al
 0199  83 c7 02                          add     edi,0002H
 019c  3c 00                             cmp     al,00H
 019e  75 e8                             jne     L20
 01a0  5f                L21             pop     edi

	else
 01a1  68 80 00 00 00    L22             push    00000080H
 01a6  52                                push    edx
 01a7  51                                push    ecx
 01a8  e8 00 00 00 00                    call    open_
 01ad  83 c4 0c                          add     esp,000cH
 01b0  a3 00 00 00 00                    mov     _mono_file+0a30cH,eax

		open_flags|=O_APPEND;
	if (fn!=last_lf)
 01b5  88 1d 00 00 00 00                 mov     _mlog+1d88H,bl

		strcpy(last_lf,fn);
   mono_file = open (fn, open_flags, S_IWRITE);
   mlog=which;
 01bb  5f                                pop     edi
 01bc  5e                                pop     esi
 01bd  59                                pop     ecx
 01be  c3                                ret     
 01bf  90                                nop     

   return mono_file;
}
 01c0  53                mono_logoff_    push    ebx
 01c1  52                                push    edx


/* turn off logging of monochrome screen. */
 01c2  8b 15 00 00 00 00                 mov     edx,_mono_file+158bH
 01c8  83 fa ff                          cmp     edx,0ffffH
 01cb  74 12                             je      L23

void mono_logoff (void)
 01cd  89 d0                             mov     eax,edx

{
	if (mono_file!=-1)
 01cf  bb ff ff ff ff                    mov     ebx,0ffffffffH
 01d4  e8 00 00 00 00                    call    close_
 01d9  89 1d 00 00 00 00                 mov     _mono_file+1d89H,ebx

	{
	   close (mono_file);
   	mono_file = -1;
	}
}

/* delete log
 *  kill_last is last log/default log
 01df  5a                L23             pop     edx
 01e0  5b                                pop     ebx
 01e1  c3                                ret     
 01e2  8b c0                             mov     eax,eax

 *  always is even if open delete
 *
 01e4  53                mono_logdel_    push    ebx
 01e5  51                                push    ecx
 01e6  56                                push    esi
 01e7  88 c3                             mov     bl,al

 * this is bizarrely broken, what to return re:kill_last
 */ 
 01e9  8b 0d 00 00 00 00                 mov     ecx,_mono_file+0d8bH
 01ef  83 f9 ff                          cmp     ecx,0ffffH
 01f2  74 1c                             je      L25

bool mono_logdel (bool kill_last, bool always)
 01f4  84 d2                             test    dl,dl
 01f6  75 06                             jne     L24

{
	if (mono_file!=-1)
	{
 01f8  30 c0                             xor     al,al
 01fa  5e                                pop     esi
 01fb  59                                pop     ecx
 01fc  5b                                pop     ebx
 01fd  c3                                ret     

		if (!always)
 01fe  89 c8             L24             mov     eax,ecx

			return FALSE;
		else
		{
 0200  be ff ff ff ff                    mov     esi,0ffffffffH
 0205  e8 00 00 00 00                    call    close_
 020a  89 35 00 00 00 00                 mov     _mono_file+3589H,esi

			close(mono_file);
 0210  84 db             L25             test    bl,bl
 0212  74 07                             je      L26

			mono_file=-1;
		}
 0214  b8 00 00 00 00                    mov     eax,offset _last_lf+0b807H
 0219  eb 05                             jmp     L27

	}
 021b  b8 08 00 00 00    L26             mov     eax,offset L141
 0220  e8 00 00 00 00    L27             call    remove_

	if (kill_last)
		return remove(last_lf);
	else
		return remove(MONO_FILE);
}
 0225  5e                                pop     esi
 0226  59                                pop     ecx
 0227  5b                                pop     ebx
 0228  c3                                ret     
 0229  8d 40 00                          lea     eax,+0H[eax]


/* internal routines for memory access, screen parameter setting */
 022c  53                _mono_init_page_ push    ebx
 022d  51                                push    ecx
 022e  52                                push    edx
 022f  89 c1                             mov     ecx,eax


 0231  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 0237  c1 fa 18                          sar     edx,18H
 023a  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 0241  29 d0                             sub     eax,edx
 0243  c1 e0 03                          shl     eax,03H
 0246  01 d0                             add     eax,edx
 0248  b3 50                             mov     bl,50H
 024a  30 d2                             xor     dl,dl
 024c  88 98 03 00 00 00                 mov     __mono_screens+9888H[eax],bl
 0252  88 90 00 00 00 00                 mov     __mono_screens+9088H[eax],dl
 0258  b7 19                             mov     bh,19H
 025a  8a 90 0f 00 00 00                 mov     dl,__mono_screens+908aH[eax]
 0260  88 b8 04 00 00 00                 mov     __mono_screens+0b888H[eax],bh
 0266  fe ca                             dec     dl
 0268  88 90 02 00 00 00                 mov     __mono_screens+9088H[eax],dl
 026e  88 90 01 00 00 00                 mov     __mono_screens+9088H[eax],dl

/* this is called for a page we have never visited before */
 0274  30 f6                             xor     dh,dh
 0276  88 b0 06 00 00 00                 mov     __mono_screens+0b088H[eax],dh
 027c  bb 04 00 00 00                    mov     ebx,00000004H
 0281  88 b0 05 00 00 00                 mov     __mono_screens+0b088H[eax],dh

void _mono_init_page(int pageid)
 0287  05 00 00 00 00                    add     eax,offset __mono_screens+500H
 028c  ba ff 00 00 00                    mov     edx,000000ffH
 0291  83 c0 0b                          add     eax,000bH
 0294  e8 00 00 00 00                    call    memset_
 0299  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 029f  c1 fa 18                          sar     edx,18H
 02a2  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 02a9  29 d0                             sub     eax,edx

{
 02ab  89 cb                             mov     ebx,ecx
 02ad  c1 e0 03                          shl     eax,03H
 02b0  c1 e3 0c                          shl     ebx,0cH
 02b3  01 d0                             add     eax,edx
 02b5  81 c3 00 00 0b 00                 add     ebx,000b0000H
 02bb  89 98 10 00 00 00                 mov     __mono_screens+9889H[eax],ebx

   split_axis=MONO_AXIS_X; split_coord=split_win=split_lfocus-1;
 02c1  30 ed                             xor     ch,ch
 02c3  89 98 07 00 00 00                 mov     __mono_screens+9889H[eax],ebx
 02c9  8b 15 00 00 00 00                 mov     edx,_def_wrap_msg+158bH
 02cf  88 a8 14 00 00 00                 mov     __mono_screens+0a888H[eax],ch
 02d5  89 90 15 00 00 00                 mov     __mono_screens+9089H[eax],edx

   split_x=split_y=0; split_w=MONO_WID; split_h=MONO_HGT;
 02db  b8 01 00 00 00                    mov     eax,00000001H
 02e0  8b 15 00 00 00 00                 mov     edx,__inited_mpages+158bH
 02e6  d3 e0                             shl     eax,cl
 02e8  09 c2                             or      edx,eax
 02ea  89 15 00 00 00 00                 mov     __inited_mpages+1589H,edx

   memset(split_lcoor,0xff,4);
   split_base=page_addr=(uchar *)(MONO_BASE+(pageid*MONO_PAGE_SZ));
   split_flags=0; split_msg=def_wrap_msg;
 02f0  5a                                pop     edx
 02f1  59                                pop     ecx
 02f2  5b                                pop     ebx
 02f3  c3                                ret     

   _inited_mpages|=(1<<pageid);
}
 02f4  53                _maddr_         push    ebx
 02f5  51                                push    ecx
 02f6  89 c1                             mov     ecx,eax
 02f8  89 d3                             mov     ebx,edx


 02fa  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 0300  c1 fa 18                          sar     edx,18H
 0303  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 030a  29 d0                             sub     eax,edx
 030c  c1 e0 03                          shl     eax,03H
 030f  01 c2                             add     edx,eax
 0311  31 c0                             xor     eax,eax
 0313  8a 82 03 00 00 00                 mov     al,__mono_screens+828aH[edx]
 0319  39 c1                             cmp     ecx,eax
 031b  7d 2a                             jge     L28
 031d  31 c0                             xor     eax,eax
 031f  8a 82 04 00 00 00                 mov     al,__mono_screens+828aH[edx]
 0325  39 c3                             cmp     ebx,eax
 0327  7d 1e                             jge     L28

/* get memory address of x,y in current window */
uchar *_maddr(int x, int y)
 0329  89 d8                             mov     eax,ebx
 032b  c1 e0 02                          shl     eax,02H
 032e  01 d8                             add     eax,ebx
 0330  8b 92 07 00 00 00                 mov     edx,__mono_screens+928bH[edx]
 0336  c1 e0 05                          shl     eax,05H
 0339  01 c2                             add     edx,eax
 033b  8d 04 4d 00 00 00 
       00                                lea     eax,+0H[ecx*2]
 0342  01 d0                             add     eax,edx
 0344  59                                pop     ecx
 0345  5b                                pop     ebx
 0346  c3                                ret     

{
 0347  31 c0             L28             xor     eax,eax

   if ((x<split_w)&&(y<split_h))
		return (uchar *)split_base+MONO_ROW*y+x*2;
   else
 0349  59                                pop     ecx
 034a  5b                                pop     ebx
 034b  c3                                ret     

      return NULL;
}
 034c  51                _mget_          push    ecx
 034d  57                                push    edi
 034e  83 ec 04                          sub     esp,0004H
 0351  89 c1                             mov     ecx,eax
 0353  88 1c 24                          mov     [esp],bl


 0356  84 db                             test    bl,bl
 0358  75 05                             jne     L29
 035a  83 38 ff                          cmp     dword ptr [eax],0ffffH
 035d  75 2a                             jne     L30
 035f  8b 1d fd ff ff ff L29             mov     ebx,__cur_mono_page+1d8bH
 0365  c1 fb 18                          sar     ebx,18H
 0368  8d 04 9d 00 00 00 
       00                                lea     eax,+0H[ebx*4]
 036f  29 d8                             sub     eax,ebx
 0371  c1 e0 03                          shl     eax,03H
 0374  01 d8                             add     eax,ebx
 0376  31 db                             xor     ebx,ebx
 0378  8a 98 05 00 00 00                 mov     bl,__mono_screens+988aH[eax]
 037e  31 c0                             xor     eax,eax
 0380  a0 00 00 00 00                    mov     al,_mono_x+0a0c0H
 0385  29 d8                             sub     eax,ebx
 0387  89 01                             mov     [ecx],eax

/* returns whether the gotten coordinates are or are not on the screen */
 0389  80 3c 24 00       L30             cmp     byte ptr [esp],00H
 038d  75 05                             jne     L31
 038f  83 3a ff                          cmp     dword ptr [edx],0ffffH
 0392  75 2a                             jne     L32
 0394  8b 1d fd ff ff ff L31             mov     ebx,__cur_mono_page+1d8bH
 039a  c1 fb 18                          sar     ebx,18H
 039d  8d 04 9d 00 00 00 
       00                                lea     eax,+0H[ebx*4]
 03a4  29 d8                             sub     eax,ebx
 03a6  8a 84 c3 06 00 00 
       00                                mov     al,__mono_screens+0c384H[ebx+eax*8]
 03ad  31 db                             xor     ebx,ebx
 03af  25 ff 00 00 00                    and     eax,000000ffH
 03b4  8a 1d 00 00 00 00                 mov     bl,_mono_y+1d8aH
 03ba  29 c3                             sub     ebx,eax
 03bc  89 1a                             mov     [edx],ebx

static bool _mget(int *x, int *y, bool always)
 03be  8b 39             L32             mov     edi,[ecx]
 03c0  85 ff                             test    edi,edi
 03c2  7c 17                             jl      L33
 03c4  83 ff 50                          cmp     edi,0050H
 03c7  7d 12                             jge     L33
 03c9  8b 02                             mov     eax,[edx]
 03cb  85 c0                             test    eax,eax
 03cd  7c 0c                             jl      L33
 03cf  83 f8 19                          cmp     eax,0019H
 03d2  7d 07                             jge     L33
 03d4  b8 01 00 00 00                    mov     eax,00000001H
 03d9  eb 02                             jmp     L34
 03db  31 c0             L33             xor     eax,eax
 03dd  85 c0             L34             test    eax,eax
 03df  0f 95 c0                          setne   al

{
 	if (always||(*x==-1)) *x=mono_x-split_x;
 03e2  83 c4 04                          add     esp,0004H
 03e5  5f                                pop     edi
 03e6  59                                pop     ecx
 03e7  c3                                ret     

 	if (always||(*y==-1)) *y=mono_y-split_y;
   return (!(((*x)<0)||((*x)>=MONO_WID)||((*y)<0)||((*y)>=MONO_HGT)));
 03e8  53                _mset_          push    ebx
 03e9  51                                push    ecx
 03ea  89 c3                             mov     ebx,eax

}
 03ec  85 c0                             test    eax,eax
 03ee  7c 33                             jl      L35
 03f0  8b 0d fd ff ff ff                 mov     ecx,__cur_mono_page+0d8bH
 03f6  c1 f9 18                          sar     ecx,18H
 03f9  8d 04 8d 00 00 00 
       00                                lea     eax,+0H[ecx*4]
 0400  29 c8                             sub     eax,ecx
 0402  c1 e0 03                          shl     eax,03H
 0405  01 c8                             add     eax,ecx
 0407  31 c9                             xor     ecx,ecx
 0409  8a 88 03 00 00 00                 mov     cl,__mono_screens+888aH[eax]
 040f  39 cb                             cmp     ebx,ecx
 0411  7d 10                             jge     L35
 0413  85 d2                             test    edx,edx
 0415  7c 0c                             jl      L35
 0417  31 c9                             xor     ecx,ecx
 0419  8a 88 04 00 00 00                 mov     cl,__mono_screens+888aH[eax]
 041f  39 ca                             cmp     edx,ecx
 0421  7e 05                             jle     L36
 0423  30 c0             L35             xor     al,al
 0425  59                                pop     ecx
 0426  5b                                pop     ebx
 0427  c3                                ret     


 0428  8a b0 05 00 00 00 L36             mov     dh,__mono_screens+0b08aH[eax]
 042e  8a 80 06 00 00 00                 mov     al,__mono_screens+808aH[eax]
 0434  00 de                             add     dh,bl
 0436  00 d0                             add     al,dl
 0438  88 35 00 00 00 00                 mov     _mono_x+3588H,dh
 043e  a2 00 00 00 00                    mov     _mono_y+0a200H,al
 0443  b0 01                             mov     al,01H

static bool _mset(int x, int y)
{
 0445  59                                pop     ecx
 0446  5b                                pop     ebx
 0447  c3                                ret     

   if ((x<0)||(x>=split_w)||(y<0)||(y>split_h)) return FALSE;
 	mono_x=split_x+x; mono_y=split_y+y; return TRUE;
 0448  53                _out_of_win_    push    ebx
 0449  51                                push    ecx
 044a  89 c3                             mov     ebx,eax

}
 044c  83 f8 ff                          cmp     eax,0ffffH
 044f  74 26                             je      L37
 0451  85 c0                             test    eax,eax
 0453  7c 4d                             jl      L38
 0455  8b 0d fd ff ff ff                 mov     ecx,__cur_mono_page+0d8bH
 045b  c1 f9 18                          sar     ecx,18H
 045e  8d 04 8d 00 00 00 
       00                                lea     eax,+0H[ecx*4]
 0465  29 c8                             sub     eax,ecx
 0467  8a 84 c1 03 00 00 
       00                                mov     al,__mono_screens+0c184H[ecx+eax*8]
 046e  25 ff 00 00 00                    and     eax,000000ffH
 0473  39 c3                             cmp     ebx,eax
 0475  7d 2b                             jge     L38
 0477  83 fa ff          L37             cmp     edx,0ffffH
 047a  74 2b                             je      L39
 047c  85 d2                             test    edx,edx
 047e  7c 22                             jl      L38
 0480  8b 1d fd ff ff ff                 mov     ebx,__cur_mono_page+1d8bH
 0486  c1 fb 18                          sar     ebx,18H
 0489  8d 04 9d 00 00 00 
       00                                lea     eax,+0H[ebx*4]
 0490  29 d8                             sub     eax,ebx
 0492  8a 84 c3 04 00 00 
       00                                mov     al,__mono_screens+0c384H[ebx+eax*8]
 0499  25 ff 00 00 00                    and     eax,000000ffH
 049e  39 c2                             cmp     edx,eax
 04a0  7c 05                             jl      L39
 04a2  b0 01             L38             mov     al,01H
 04a4  59                                pop     ecx
 04a5  5b                                pop     ebx
 04a6  c3                                ret     
 04a7  30 c0             L39             xor     al,al


static bool _out_of_win(int x, int y)
{
 04a9  59                                pop     ecx
 04aa  5b                                pop     ebx
 04ab  c3                                ret     

   return (((x!=-1)&&((x<0)||(x>=split_w)))||((y!=-1)&&((y<0)||(y>=split_h))));
}
 04ac  52                _mono_top_      push    edx


 04ad  8a 25 00 00 00 00                 mov     ah,_mono_done_init+258aH
 04b3  84 e4                             test    ah,ah
 04b5  75 38                             jne     L40
 04b7  b2 01                             mov     dl,01H
 04b9  88 25 00 00 00 00                 mov     _mono_y+2588H,ah
 04bf  88 25 00 00 00 00                 mov     _mono_x+2588H,ah
 04c5  88 15 00 00 00 00                 mov     _mono_done_init+1588H,dl
 04cb  e8 00 00 00 00                    call    mono_detect_
 04d0  a2 00 00 00 00                    mov     _mono_screen+0a200H,al
 04d5  25 ff 00 00 00                    and     eax,000000ffH
 04da  e8 00 00 00 00                    call    mono_setmode_
 04df  84 c0                             test    al,al
 04e1  74 0c                             je      L40
 04e3  ba 01 00 00 00                    mov     edx,00000001H
 04e8  31 c0                             xor     eax,eax
 04ea  e8 00 00 00 00                    call    mono_setpage_

/* the beginning of all mono_ external calls - returns true to really do it */
 04ef  80 3d 00 00 00 00 
       00                L40             cmp     byte ptr _mono_mode+3d80H,00H
 04f6  0f 95 c0                          setne   al

static bool _mono_top(void)
{
   if (!mono_done_init) mono_init ();
   return (mono_mode != MONO_OFF);
}

 04f9  5a                                pop     edx
 04fa  c3                                ret     
 04fb  90                                nop     

#define _mono_focused() (_cur_mono_focus==_cur_mono_page)

 04fc  51                mget_           push    ecx
 04fd  83 ec 08                          sub     esp,0008H
 0500  89 c1                             mov     ecx,eax
 0502  89 14 24                          mov     [esp],edx
 0505  89 5c 24 04                       mov     +4H[esp],ebx

/* routines to get and put single characters */
 0509  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_done_init+3d80H,00H
 0510  75 05                             jne     L41
 0512  e8 00 00 00 00                    call    mono_init_
 0517  80 3d 00 00 00 00 
       00                L41             cmp     byte ptr _mono_mode+3d80H,00H
 051e  0f 95 c0                          setne   al
 0521  84 c0                             test    al,al
 0523  74 3b                             je      L42
 0525  8b 54 24 04                       mov     edx,+4H[esp]
 0529  8b 04 24                          mov     eax,[esp]
 052c  e8 00 00 00 00                    call    _out_of_win_
 0531  84 c0                             test    al,al
 0533  75 2b                             jne     L42
 0535  8d 54 24 04                       lea     edx,+4H[esp]
 0539  89 e0                             mov     eax,esp
 053b  31 db                             xor     ebx,ebx
 053d  e8 00 00 00 00                    call    _mget_
 0542  84 c0                             test    al,al
 0544  74 1a                             je      L42

/* returns -1 if out of range or no mono screen */
 0546  8b 54 24 04                       mov     edx,+4H[esp]
 054a  8b 04 24                          mov     eax,[esp]
 054d  e8 00 00 00 00                    call    _maddr_
 0552  8a 00                             mov     al,[eax]
 0554  88 01                             mov     [ecx],al
 0556  25 ff 00 00 00                    and     eax,000000ffH
 055b  83 c4 08                          add     esp,0008H
 055e  59                                pop     ecx
 055f  c3                                ret     

int  mget(uchar *s, int x, int y)   /* get current character (at x,y specified w/o moving cursor ) */
 0560  b8 ff ff ff ff    L42             mov     eax,0ffffffffH

{
 0565  c6 01 00                          mov     byte ptr [ecx],00H

   if ((_mono_top())&&(!_out_of_win(x,y))&&(_mget(&x,&y,FALSE)))
      return (int)(*s=*_maddr(x,y));
 0568  83 c4 08                          add     esp,0008H
 056b  59                                pop     ecx
 056c  c3                                ret     
 056d  8d 40 00                          lea     eax,+0H[eax]

   else
    { *s=0; return -1; }
 0570  51                mput_           push    ecx
 0571  83 ec 08                          sub     esp,0008H
 0574  88 c1                             mov     cl,al
 0576  89 14 24                          mov     [esp],edx
 0579  89 5c 24 04                       mov     +4H[esp],ebx

}
 057d  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_done_init+3d80H,00H
 0584  75 05                             jne     L43
 0586  e8 00 00 00 00                    call    mono_init_
 058b  80 3d 00 00 00 00 
       00                L43             cmp     byte ptr _mono_mode+3d80H,00H
 0592  0f 95 c0                          setne   al
 0595  84 c0                             test    al,al
 0597  74 3b                             je      L44
 0599  8b 54 24 04                       mov     edx,+4H[esp]
 059d  8b 04 24                          mov     eax,[esp]
 05a0  e8 00 00 00 00                    call    _out_of_win_
 05a5  84 c0                             test    al,al
 05a7  75 2b                             jne     L44
 05a9  8d 54 24 04                       lea     edx,+4H[esp]
 05ad  89 e0                             mov     eax,esp
 05af  31 db                             xor     ebx,ebx
 05b1  e8 00 00 00 00                    call    _mget_
 05b6  84 c0                             test    al,al
 05b8  74 1a                             je      L44


int  mput(uchar s, int x, int y)    /* put single character  ( or a -1 for x means at current loc) */
 05ba  8b 54 24 04                       mov     edx,+4H[esp]
 05be  8b 04 24                          mov     eax,[esp]
 05c1  e8 00 00 00 00                    call    _maddr_
 05c6  88 08                             mov     [eax],cl
 05c8  88 c8                             mov     al,cl
 05ca  25 ff 00 00 00                    and     eax,000000ffH
 05cf  83 c4 08                          add     esp,0008H
 05d2  59                                pop     ecx
 05d3  c3                                ret     

{
 05d4  b8 ff ff ff ff    L44             mov     eax,0ffffffffH

   if ((_mono_top())&&(!_out_of_win(x,y))&&(_mget(&x,&y,FALSE)))
      return (int)(*_maddr(x,y)=s);
   else
      return -1;
 05d9  83 c4 08                          add     esp,0008H
 05dc  59                                pop     ecx
 05dd  c3                                ret     
 05de  8b c0                             mov     eax,eax

}

 05e0  51                _mwin_set_      push    ecx
 05e1  56                                push    esi
 05e2  83 ec 08                          sub     esp,0008H
 05e5  89 c1                             mov     ecx,eax
 05e7  89 54 24 04                       mov     +4H[esp],edx

/* split screen stuff */
/* internal get/set correct window parameters */
 05eb  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 05f1  c1 fa 18                          sar     edx,18H
 05f4  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 05fb  29 d0                             sub     eax,edx
 05fd  c1 e0 03                          shl     eax,03H
 0600  01 d0                             add     eax,edx
 0602  8b 90 ff ff ff ff                 mov     edx,__mono_screens+908bH[eax]
 0608  c1 fa 18                          sar     edx,18H

static bool _mwin_set(int pick,int axe,int loc)
 060b  88 88 02 00 00 00                 mov     __mono_screens+8888H[eax],cl
 0611  89 14 24                          mov     [esp],edx
 0614  8b 90 10 00 00 00                 mov     edx,__mono_screens+908bH[eax]
 061a  89 90 07 00 00 00                 mov     __mono_screens+9089H[eax],edx

{
 0620  c6 80 03 00 00 00 
       50                                mov     byte ptr __mono_screens+80c6H[eax],50H
 0627  c6 80 04 00 00 00 
       19                                mov     byte ptr __mono_screens+80c6H[eax],19H
 062e  30 d2                             xor     dl,dl
 0630  88 90 06 00 00 00                 mov     __mono_screens+9088H[eax],dl
 0636  88 90 05 00 00 00                 mov     __mono_screens+9088H[eax],dl

   int save_focus=split_win;
 063c  83 f9 ff                          cmp     ecx,0ffffH
 063f  0f 84 34 01 00 00                 je      L50


   split_win=pick; split_base=(uchar *)page_addr;
	split_w=MONO_WID; split_h=MONO_HGT; split_x=split_y=0;
 0645  83 7c 24 04 00                    cmp     dword ptr +4H[esp],0000H
 064a  75 3d                             jne     L46

	if (pick==-1) goto no_split;
	if (axe==MONO_AXIS_X)
 064c  83 fb 50                          cmp     ebx,0050H
 064f  0f 8d 24 01 00 00                 jge     L50

	{
 0655  83 f9 01                          cmp     ecx,0001H
 0658  75 08                             jne     L45
 065a  88 98 03 00 00 00                 mov     __mono_screens+9888H[eax],bl

#ifdef FULL_CHECKING
      if (loc>=MONO_WID) goto no_split;
#endif
		if (pick==1)			split_w=loc;
		else        		 { split_w=MONO_WID-loc; split_base+=2*loc; split_x=loc; }
 0660  eb 67                             jmp     L48
 0662  b2 50             L45             mov     dl,50H
 0664  28 da                             sub     dl,bl
 0666  8b b0 07 00 00 00                 mov     esi,__mono_screens+0b08bH[eax]
 066c  88 90 03 00 00 00                 mov     __mono_screens+9088H[eax],dl
 0672  8d 14 5d 00 00 00 
       00                                lea     edx,+0H[ebx*2]
 0679  01 d6                             add     esi,edx
 067b  88 98 05 00 00 00                 mov     __mono_screens+9888H[eax],bl
 0681  89 b0 07 00 00 00                 mov     __mono_screens+0b089H[eax],esi
 0687  eb 40                             jmp     L48

	}
	else
 0689  83 fb 19          L46             cmp     ebx,0019H
 068c  0f 8d e7 00 00 00                 jge     L50

	{
 0692  83 f9 01                          cmp     ecx,0001H
 0695  75 08                             jne     L47
 0697  88 98 04 00 00 00                 mov     __mono_screens+9888H[eax],bl

#ifdef FULL_CHECKING
      if (loc>=MONO_HGT) goto no_split;
 069d  eb 2a                             jmp     L48
 069f  b2 19             L47             mov     dl,19H
 06a1  28 da                             sub     dl,bl
 06a3  88 90 04 00 00 00                 mov     __mono_screens+9088H[eax],dl
 06a9  8d 14 9d 00 00 00 
       00                                lea     edx,+0H[ebx*4]
 06b0  01 da                             add     edx,ebx
 06b2  8b 88 07 00 00 00                 mov     ecx,__mono_screens+888bH[eax]
 06b8  c1 e2 05                          shl     edx,05H
 06bb  88 98 06 00 00 00                 mov     __mono_screens+9888H[eax],bl
 06c1  01 d1                             add     ecx,edx
 06c3  89 88 07 00 00 00                 mov     __mono_screens+8889H[eax],ecx

#endif
 06c9  8b 15 fd ff ff ff L48             mov     edx,__cur_mono_page+158bH
 06cf  c1 fa 18                          sar     edx,18H
 06d2  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 06d9  29 d0                             sub     eax,edx
 06db  c1 e0 03                          shl     eax,03H
 06de  01 d0                             add     eax,edx
 06e0  8a 54 24 04                       mov     dl,+4H[esp]
 06e4  88 90 00 00 00 00                 mov     __mono_screens+9088H[eax],dl

		if (pick==1)			split_h=loc;
 06ea  8b 90 0c 00 00 00                 mov     edx,__mono_screens+908bH[eax]
 06f0  c1 fa 18                          sar     edx,18H
 06f3  88 98 01 00 00 00                 mov     __mono_screens+9888H[eax],bl
 06f9  83 fa ff                          cmp     edx,0ffffH
 06fc  75 14                             jne     L49
 06fe  bb 04 00 00 00                    mov     ebx,00000004H

		else        		 { split_h=MONO_HGT-loc; split_base+=MONO_ROW*loc; split_y=loc; }
 0703  05 00 00 00 00                    add     eax,offset __mono_screens+500H
 0708  31 d2                             xor     edx,edx
 070a  83 c0 0b                          add     eax,000bH
 070d  e8 00 00 00 00                    call    memset_

	}
 0712  8b 15 fd ff ff ff L49             mov     edx,__cur_mono_page+158bH
 0718  c1 fa 18                          sar     edx,18H
 071b  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 0722  29 d0                             sub     eax,edx
 0724  c1 e0 03                          shl     eax,03H
 0727  01 d0                             add     eax,edx
 0729  8b 90 ff ff ff ff                 mov     edx,__mono_screens+908bH[eax]
 072f  c1 fa 18                          sar     edx,18H
 0732  01 d2                             add     edx,edx
 0734  01 d0                             add     eax,edx
 0736  31 d2                             xor     edx,edx
 0738  8a 90 0a 00 00 00                 mov     dl,__mono_screens+908aH[eax]
 073e  8a 80 09 00 00 00                 mov     al,__mono_screens+808aH[eax]
 0744  25 ff 00 00 00                    and     eax,000000ffH
 0749  e8 00 00 00 00                    call    mono_setxy_

   split_axis=axe; split_coord=loc;
 074e  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 0754  c1 fa 18                          sar     edx,18H
 0757  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 075e  29 d0                             sub     eax,edx
 0760  c1 e0 03                          shl     eax,03H
 0763  01 d0                             add     eax,edx
 0765  8a 90 02 00 00 00                 mov     dl,__mono_screens+908aH[eax]
 076b  88 90 0f 00 00 00                 mov     __mono_screens+9088H[eax],dl

   if (split_lfocus==-1)          /* brand new split */
      memset(split_lcoor,0,(MONO_WIN_MAX*2));
 0771  b0 01                             mov     al,01H
 0773  83 c4 08                          add     esp,0008H
 0776  5e                                pop     esi
 0777  59                                pop     ecx
 0778  c3                                ret     

   mono_setxy(split_lcoor[split_win-1][0],split_lcoor[split_win-1][1]); /* go to correct position */
 0779  8b 15 fd ff ff ff L50             mov     edx,__cur_mono_page+158bH
 077f  c1 fa 18                          sar     edx,18H
 0782  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 0789  29 d0                             sub     eax,edx
 078b  c1 e0 03                          shl     eax,03H
 078e  01 d0                             add     eax,edx
 0790  8a 14 24                          mov     dl,[esp]
 0793  88 90 0f 00 00 00                 mov     __mono_screens+9088H[eax],dl

   split_lfocus=split_win;
 0799  83 f9 ff                          cmp     ecx,0ffffH
 079c  0f 94 c0                          sete    al

   return TRUE;
no_split:
   split_lfocus=save_focus;
   return (pick==-1);
 079f  83 c4 08                          add     esp,0008H
 07a2  5e                                pop     esi
 07a3  59                                pop     ecx
 07a4  c3                                ret     
 07a5  8d 40 00                          lea     eax,+0H[eax]

}

 07a8  53                mono_split_     push    ebx
 07a9  51                                push    ecx
 07aa  56                                push    esi
 07ab  83 ec 04                          sub     esp,0004H
 07ae  89 c1                             mov     ecx,eax

/* externals */
 07b0  8b 1d fd ff ff ff                 mov     ebx,__cur_mono_page+1d8bH
 07b6  c1 fb 18                          sar     ebx,18H
 07b9  8d 04 9d 00 00 00 
       00                                lea     eax,+0H[ebx*4]
 07c0  29 d8                             sub     eax,ebx
 07c2  c1 e0 03                          shl     eax,03H
 07c5  01 d8                             add     eax,ebx
 07c7  8b 98 0c 00 00 00                 mov     ebx,__mono_screens+988bH[eax]
 07cd  c1 fb 18                          sar     ebx,18H
 07d0  89 1c 24                          mov     [esp],ebx

/* split returns number of windows, or -1 if there are already windows */
 07d3  8b 98 ff ff ff ff                 mov     ebx,__mono_screens+988bH[eax]
 07d9  c1 fb 18                          sar     ebx,18H
 07dc  be 01 00 00 00                    mov     esi,00000001H
 07e1  83 fb ff                          cmp     ebx,0ffffH
 07e4  75 58                             jne     L54

int  mono_split (int axe, int loc)
 07e6  83 f9 02                          cmp     ecx,0002H
 07e9  75 16                             jne     L51
 07eb  8b 34 24                          mov     esi,[esp]
 07ee  8b 90 fe ff ff ff                 mov     edx,__mono_screens+908bH[eax]
 07f4  31 c9                             xor     ecx,ecx
 07f6  c1 fa 18                          sar     edx,18H
 07f9  8a 88 00 00 00 00                 mov     cl,__mono_screens+888aH[eax]
 07ff  eb 07                             jmp     L52
 0801  c6 80 0f 00 00 00 
       ff                L51             mov     byte ptr __mono_screens+80c6H[eax],0ffH

{
 0808  89 d3             L52             mov     ebx,edx
 080a  89 f0                             mov     eax,esi
 080c  89 ca                             mov     edx,ecx
 080e  e8 00 00 00 00                    call    _mwin_set_
 0813  84 c0                             test    al,al
 0815  74 07                             je      L53
 0817  b8 02 00 00 00                    mov     eax,00000002H
 081c  eb 25                             jmp     L55

   int save_focus=split_lfocus, focus=1;
 081e  8b 15 fd ff ff ff L53             mov     edx,__cur_mono_page+158bH
 0824  c1 fa 18                          sar     edx,18H
 0827  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 082e  29 d0                             sub     eax,edx
 0830  c1 e0 03                          shl     eax,03H
 0833  01 d0                             add     eax,edx
 0835  8a 14 24                          mov     dl,[esp]
 0838  88 90 0f 00 00 00                 mov     __mono_screens+9088H[eax],dl
 083e  b8 ff ff ff ff    L54             mov     eax,0ffffffffH

	if (split_win!=-1) return -1;			/* already an open window */
   if (axe==MONO_AXIS_R)   { axe=split_axis; loc=split_coord; focus=split_lfocus; } else split_lfocus=-1;
   if (_mwin_set(focus,axe,loc)) return MONO_WIN_MAX;						/* there are 2 windows */
 0843  83 c4 04          L55             add     esp,0004H
 0846  5e                                pop     esi
 0847  59                                pop     ecx
 0848  5b                                pop     ebx
 0849  c3                                ret     
 084a  8b c0                             mov     eax,eax

   else                    { split_lfocus=save_focus; return -1; }
}
 084c  53                mono_unsplit_   push    ebx
 084d  52                                push    edx


 084e  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 0854  c1 fa 18                          sar     edx,18H
 0857  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 085e  29 d0                             sub     eax,edx
 0860  8b 84 c2 ff ff ff 
       ff                                mov     eax,__mono_screens+0c284H[edx+eax*8]
 0867  c1 f8 18                          sar     eax,18H
 086a  83 f8 ff                          cmp     eax,0ffffH
 086d  74 17                             je      L56
 086f  bb ff ff ff ff                    mov     ebx,0ffffffffH
 0874  89 da                             mov     edx,ebx
 0876  89 d8                             mov     eax,ebx
 0878  e8 00 00 00 00                    call    _mwin_set_
 087d  84 c0                             test    al,al
 087f  74 05                             je      L56
 0881  b0 01                             mov     al,01H
 0883  5a                                pop     edx
 0884  5b                                pop     ebx
 0885  c3                                ret     
 0886  30 c0             L56             xor     al,al

/* returns false if it cannot unsplit the window */
bool mono_unsplit (void)
{
 0888  5a                                pop     edx
 0889  5b                                pop     ebx
 088a  c3                                ret     
 088b  90                                nop     

	return (split_win!=-1)&&(_mwin_set(-1,-1,-1));
}

 088c  53                mono_setwin_    push    ebx
 088d  52                                push    edx

/* returns whether the pickwin was succesful, ie. whether you passed legal in */
bool mono_setwin (int which)
 088e  8b 1d fd ff ff ff                 mov     ebx,__cur_mono_page+1d8bH
 0894  c1 fb 18                          sar     ebx,18H
 0897  8d 14 9d 00 00 00 
       00                                lea     edx,+0H[ebx*4]
 089e  29 da                             sub     edx,ebx
 08a0  8b 94 d3 ff ff ff 
       ff                                mov     edx,__mono_screens+0d394H[ebx+edx*8]
 08a7  c1 fa 18                          sar     edx,18H
 08aa  83 fa ff                          cmp     edx,0ffffH
 08ad  74 09                             je      L57
 08af  85 c0                             test    eax,eax
 08b1  7c 05                             jl      L57
 08b3  83 f8 03                          cmp     eax,0003H
 08b6  7e 05                             jle     L58
 08b8  30 c0             L57             xor     al,al
 08ba  5a                                pop     edx
 08bb  5b                                pop     ebx
 08bc  c3                                ret     

{
 08bd  39 d0             L58             cmp     eax,edx
 08bf  74 43                             je      L60

#ifdef FULL_CHECKING
 08c1  83 f8 03                          cmp     eax,0003H
 08c4  75 0d                             jne     L59

	if ((split_win==-1)||(which<0)||(which>MONO_WIN_NXT)) return FALSE;
 08c6  8d 42 01                          lea     eax,+1H[edx]
 08c9  83 f8 03                          cmp     eax,0003H
 08cc  75 05                             jne     L59
 08ce  b8 01 00 00 00                    mov     eax,00000001H

#endif
 08d3  8b 1d fd ff ff ff L59             mov     ebx,__cur_mono_page+1d8bH
 08d9  c1 fb 18                          sar     ebx,18H
 08dc  8d 14 9d 00 00 00 
       00                                lea     edx,+0H[ebx*4]
 08e3  29 da                             sub     edx,ebx
 08e5  c1 e2 03                          shl     edx,03H
 08e8  01 da                             add     edx,ebx
 08ea  8b 9a fe ff ff ff                 mov     ebx,__mono_screens+9a8bH[edx]
 08f0  c1 fb 18                          sar     ebx,18H
 08f3  8a 92 00 00 00 00                 mov     dl,__mono_screens+928aH[edx]
 08f9  81 e2 ff 00 00 00                 and     edx,000000ffH
 08ff  e8 00 00 00 00                    call    _mwin_set_

	if (which==split_win) return TRUE;	/* already focused on this window */
 0904  b0 01             L60             mov     al,01H

	if (which==MONO_WIN_NXT)
		if ((which=split_win+1)==MONO_WIN_MAX+1) which=1;
 0906  5a                                pop     edx
 0907  5b                                pop     ebx
 0908  c3                                ret     
 0909  8d 40 00                          lea     eax,+0H[eax]

	_mwin_set(which,split_axis,split_coord);
	return TRUE;
}
 090c  52                mono_getwin_    push    edx


 090d  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 0913  c1 fa 18                          sar     edx,18H
 0916  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 091d  29 d0                             sub     eax,edx
 091f  8b 84 c2 ff ff ff 
       ff                                mov     eax,__mono_screens+0c284H[edx+eax*8]
 0926  c1 f8 18                          sar     eax,18H

int mono_getwin(void)
{
// printf("Axe %d, loc %d, cur %d, last %d scr %d %d %d %d\n",split_axis,split_coord,split_win,split_lfocus,split_x,split_y,split_w,split_h);
 0929  5a                                pop     edx
 092a  c3                                ret     
 092b  90                                nop     

   return split_win;
}
 092c  53                mono_setpage_   push    ebx
 092d  51                                push    ecx
 092e  89 c3                             mov     ebx,eax
 0930  88 d5                             mov     ch,dl


 0932  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_done_init+3d80H,00H
 0939  75 05                             jne     L61
 093b  e8 00 00 00 00                    call    mono_init_
 0940  80 3d 00 00 00 00 
       00                L61             cmp     byte ptr _mono_mode+3d80H,00H
 0947  0f 95 c0                          setne   al
 094a  84 c0                             test    al,al
 094c  74 51                             je      L66

/* direct page set/get */
 094e  a1 fd ff ff ff                    mov     eax,__cur_mono_page+0a151H
 0953  c1 f8 18                          sar     eax,18H
 0956  39 d8                             cmp     eax,ebx
 0958  75 05                             jne     L62
 095a  30 d8                             xor     al,bl
 095c  59                                pop     ecx
 095d  5b                                pop     ebx
 095e  c3                                ret     

bool mono_setpage(int pageid, bool focus)
{
 095f  83 fb 0c          L62             cmp     ebx,000cH
 0962  7c 05                             jl      L63
 0964  30 c0                             xor     al,al
 0966  59                                pop     ecx
 0967  5b                                pop     ebx
 0968  c3                                ret     
 0969  b8 01 00 00 00    L63             mov     eax,00000001H

 096e  88 d9                             mov     cl,bl
 0970  8b 15 00 00 00 00                 mov     edx,__inited_mpages+158bH
 0976  d3 e0                             shl     eax,cl

   if (!_mono_top()) return FALSE;
   if (_cur_mono_page==pageid) return FALSE;
   if (pageid>=MONO_MAX_PAGES) return FALSE;
 0978  88 1d 00 00 00 00                 mov     __cur_mono_page+1d88H,bl
 097e  85 d0                             test    eax,edx
 0980  75 10                             jne     L64

   _cur_mono_page=pageid;
 0982  89 d8                             mov     eax,ebx
 0984  e8 00 00 00 00                    call    _mono_init_page_

   if ((_inited_mpages&(1<<pageid))==0)
   {
 0989  31 d2                             xor     edx,edx
 098b  31 c0                             xor     eax,eax
 098d  e8 00 00 00 00                    call    mono_setxy_

      _mono_init_page(pageid);
 0992  84 ed             L64             test    ch,ch
 0994  74 07                             je      L65

      mono_setxy(0,0);
 0996  89 d8                             mov     eax,ebx
 0998  e8 00 00 00 00                    call    mono_setfocus_

   }
 099d  b0 01             L65             mov     al,01H

   if (focus)
      mono_setfocus(pageid);
 099f  59                L66             pop     ecx
 09a0  5b                                pop     ebx
 09a1  c3                                ret     
 09a2  8b c0                             mov     eax,eax

   return TRUE;
}

 09a4  a1 fd ff ff ff    mono_getpage_   mov     eax,__cur_mono_page+0a1c0H
 09a9  c1 f8 18                          sar     eax,18H

int mono_getpage(void)
{
 09ac  c3                                ret     
 09ad  8d 40 00                          lea     eax,+0H[eax]

   return _cur_mono_page;
}

 09b0  53                mono_setfocus_  push    ebx
 09b1  52                                push    edx
 09b2  89 c3                             mov     ebx,eax

int mono_setfocus(int pageid)
 09b4  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_done_init+3d80H,00H
 09bb  75 05                             jne     L67
 09bd  e8 00 00 00 00                    call    mono_init_
 09c2  80 3d 00 00 00 00 
       00                L67             cmp     byte ptr _mono_mode+3d80H,00H
 09c9  0f 95 c0                          setne   al
 09cc  84 c0                             test    al,al
 09ce  75 05                             jne     L68
 09d0  31 c0                             xor     eax,eax
 09d2  5a                                pop     edx
 09d3  5b                                pop     ebx
 09d4  c3                                ret     

{
 09d5  a1 fd ff ff ff    L68             mov     eax,__cur_mono_focus+0a1c3H
 09da  c1 f8 18                          sar     eax,18H
 09dd  39 d8                             cmp     eax,ebx
 09df  75 05                             jne     L69
 09e1  31 d8                             xor     eax,ebx
 09e3  5a                                pop     edx
 09e4  5b                                pop     ebx
 09e5  c3                                ret     

   int page_offs;
 09e6  83 fb 08          L69             cmp     ebx,0008H
 09e9  7d 29                             jge     L70

   if (!_mono_top()) return FALSE;
 09eb  30 db                             xor     bl,bl
 09ed  88 1d 00 00 00 00                 mov     __cur_card+1d88H,bl
 09f3  8b 1d fd ff ff ff                 mov     ebx,__cur_mono_page+1d8bH
 09f9  c1 fb 18                          sar     ebx,18H
 09fc  8d 04 9d 00 00 00 
       00                                lea     eax,+0H[ebx*4]
 0a03  29 d8                             sub     eax,ebx
 0a05  8b 9c c3 10 00 00 
       00                                mov     ebx,__mono_screens+0c39cH[ebx+eax*8]
 0a0c  81 eb 00 00 0b 00                 sub     ebx,000b0000H

   if (_cur_mono_focus==pageid) return FALSE;
 0a12  eb 29                             jmp     L71
 0a14  8b 1d fd ff ff ff L70             mov     ebx,__cur_mono_page+1d8bH
 0a1a  c1 fb 18                          sar     ebx,18H
 0a1d  8d 04 9d 00 00 00 
       00                                lea     eax,+0H[ebx*4]
 0a24  29 d8                             sub     eax,ebx
 0a26  8b 9c c3 10 00 00 
       00                                mov     ebx,__mono_screens+0c39cH[ebx+eax*8]

   if (pageid<MONO_NUM_PAGES)
    { _cur_card=MONO_CARD; page_offs=(int)(page_addr-MONO_BASE); }
 0a2d  b6 01                             mov     dh,01H
 0a2f  81 c3 00 80 f4 ff                 add     ebx,0fff48000H
 0a35  88 35 00 00 00 00                 mov     __cur_card+3588H,dh
 0a3b  d1 fb                             sar     ebx,1

   else
 0a3d  31 d2             L71             xor     edx,edx
 0a3f  8a 15 00 00 00 00                 mov     dl,__cur_card+158aH
 0a45  b0 0c                             mov     al,0cH
 0a47  8b 14 95 00 00 00 
       00                                mov     edx,_srx_adr+9514H[edx*4]
 0a4e  ee                                out     dx,al
 0a4f  31 d2                             xor     edx,edx
 0a51  89 d8                             mov     eax,ebx
 0a53  8a 15 00 00 00 00                 mov     dl,__cur_card+158aH
 0a59  c1 f8 08                          sar     eax,08H
 0a5c  8b 14 95 00 00 00 
       00                                mov     edx,_srx_data+9514H[edx*4]
 0a63  ee                                out     dx,al

    { _cur_card=CGA_CARD; page_offs=(int)(page_addr-CGA_BASE)>>1; }
// printf("Trying to set to %x on card %d\n",page_offs,_cur_card);
 0a64  31 d2                             xor     edx,edx
 0a66  8a 15 00 00 00 00                 mov     dl,__cur_card+158aH
 0a6c  b0 0d                             mov     al,0dH
 0a6e  8b 14 95 00 00 00 
       00                                mov     edx,_srx_adr+9514H[edx*4]
 0a75  ee                                out     dx,al
 0a76  31 d2                             xor     edx,edx
 0a78  89 d8                             mov     eax,ebx
 0a7a  8a 15 00 00 00 00                 mov     dl,__cur_card+158aH
 0a80  25 ff 00 00 00                    and     eax,000000ffH
 0a85  8b 14 95 00 00 00 
       00                                mov     edx,_srx_data+9514H[edx*4]
 0a8c  ee                                out     dx,al

   out_set(_cur_card,SR_AHI,(page_offs)>>8); 
 0a8d  b8 01 00 00 00                    mov     eax,00000001H

   out_set(_cur_card,SR_ALO,(page_offs)&0xff);
// vbio_call(0x0500+pageid-(_cur_card==CGA_CARD?8:0));
 0a92  5a                                pop     edx
 0a93  5b                                pop     ebx
 0a94  c3                                ret     
 0a95  8d 40 00                          lea     eax,+0H[eax]

   return TRUE;
}

 0a98  a1 fd ff ff ff    mono_getfocus_  mov     eax,__cur_mono_focus+0a100H
 0a9d  c1 f8 18                          sar     eax,18H

int mono_getfocus(void)
{
   return _cur_mono_focus;
 0aa0  c3                                ret     
 0aa1  8d 40 00                          lea     eax,+0H[eax]

}

 0aa4  52                mono_scr_disable_ push    edx

/* goofy turn off screen thing */
 0aa5  ba b8 03 00 00                    mov     edx,000003b8H
 0aaa  29 c0                             sub     eax,eax
 0aac  ec                                in      al,dx

void mono_scr_disable(void)
 0aad  24 f7                             and     al,0f7H

{
 0aaf  ee                                out     dx,al

   int ostate=inp (M_CNTRL);
   ostate&=(~(1<<3));
 0ab0  5a                                pop     edx
 0ab1  c3                                ret     
 0ab2  8b c0                             mov     eax,eax

   outp(M_CNTRL,ostate);
}
 0ab4  52                mono_scr_enable_ push    edx


 0ab5  ba b8 03 00 00                    mov     edx,000003b8H
 0aba  29 c0                             sub     eax,eax
 0abc  ec                                in      al,dx

void mono_scr_enable(void)
 0abd  0c 08                             or      al,08H

{
 0abf  ee                                out     dx,al

   int ostate=inp (M_CNTRL);
   ostate|=(1<<3);
   outp(M_CNTRL,ostate);
 0ac0  5a                                pop     edx
 0ac1  c3                                ret     
 0ac2  8b c0                             mov     eax,eax

}

 0ac4  51                mono_cursor_    push    ecx
 0ac5  56                                push    esi
 0ac6  89 d1                             mov     ecx,edx

/* warning, bizarrly broken on some mono cards */
 0ac8  31 f6                             xor     esi,esi

void mono_cursor(bool cur_mon, int start, int stop)
 0aca  39 da                             cmp     edx,ebx
 0acc  7e 04                             jle     L72
 0ace  89 d9                             mov     ecx,ebx
 0ad0  89 d3                             mov     ebx,edx

{
 0ad2  84 c0             L72             test    al,al
 0ad4  74 07                             je      L73
 0ad6  0f b6 35 00 00 00 
       00                                movzx   esi,byte ptr __cur_card+35b6H
 0add  b0 0a             L73             mov     al,0aH

   int card=MONO_CARD;
 0adf  8b 14 b5 00 00 00 
       00                                mov     edx,_srx_adr+0b514H[esi*4]
 0ae6  ee                                out     dx,al
 0ae7  88 c8                             mov     al,cl
 0ae9  8b 14 b5 00 00 00 
       00                                mov     edx,_srx_data+0b514H[esi*4]
 0af0  ee                                out     dx,al
 0af1  b0 0b                             mov     al,0bH

   if (start>stop) {int tmp=start; start=stop; stop=tmp; }
 0af3  8b 14 b5 00 00 00 
       00                                mov     edx,_srx_adr+0b514H[esi*4]
 0afa  ee                                out     dx,al
 0afb  88 d8                             mov     al,bl
 0afd  8b 14 b5 00 00 00 
       00                                mov     edx,_srx_data+0b514H[esi*4]
 0b04  ee                                out     dx,al

   if (cur_mon) card=_cur_card;
   out_set(card,SR_CTP,start);
   out_set(card,SR_CBT,stop);
 0b05  5e                                pop     esi
 0b06  59                                pop     ecx
 0b07  c3                                ret     

}

/* screen flip stuff */
 0b08  53                mono_flip_      push    ebx
 0b09  52                                push    edx

 0b0a  ba 01 00 00 00                    mov     edx,00000001H

bool mono_flip(int pageid)
{
 0b0f  8b 1d fd ff ff ff                 mov     ebx,__cur_mono_page+1d8bH
 0b15  e8 00 00 00 00                    call    mono_setpage_
 0b1a  88 c4                             mov     ah,al
 0b1c  c1 fb 18                          sar     ebx,18H

   int old_page=_cur_mono_page;
   bool retv=mono_setpage(pageid,TRUE);
 0b1f  84 c0                             test    al,al
 0b21  74 06                             je      L74
 0b23  88 1d 00 00 00 00                 mov     __last_mono_page+1d88H,bl

   if (retv) _last_mono_page=old_page;
   return retv;
 0b29  88 e0             L74             mov     al,ah
 0b2b  5a                                pop     edx
 0b2c  5b                                pop     ebx
 0b2d  c3                                ret     
 0b2e  8b c0                             mov     eax,eax

}

bool mono_unflip(void)
 0b30  52                mono_unflip_    push    edx

{
 0b31  a1 fd ff ff ff                    mov     eax,__last_mono_page+0a152H
 0b36  c1 f8 18                          sar     eax,18H
 0b39  83 f8 ff                          cmp     eax,0ffffH
 0b3c  75 04                             jne     L75
 0b3e  30 c0                             xor     al,al
 0b40  5a                                pop     edx
 0b41  c3                                ret     

   bool retv;
 0b42  ba 01 00 00 00    L75             mov     edx,00000001H
 0b47  e8 00 00 00 00                    call    mono_setpage_
 0b4c  88 c4                             mov     ah,al
 0b4e  84 c0                             test    al,al
 0b50  74 07                             je      L76

   if (_last_mono_page==-1) return FALSE;
 0b52  c6 05 00 00 00 00 
       ff                                mov     byte ptr __last_mono_page+5c6H,0ffH

   if (retv=mono_setpage(_last_mono_page,TRUE))
 0b59  88 e0             L76             mov     al,ah

	   _last_mono_page=-1;              /* so it wont be able to double unflip */
   return retv;
}
 0b5b  5a                                pop     edx
 0b5c  c3                                ret     
 0b5d  8d 40 00                          lea     eax,+0H[eax]


/* set the current text attributes. */
void mono_setattr (uchar attrib)
 0b60  a2 00 00 00 00    mono_setattr_   mov     _mono_attr+0a200H,al

{
   mono_attr = attrib;
}
 0b65  c3                                ret     
 0b66  8b c0                             mov     eax,eax


/* set the (x,y) location of the cursor. - window relative */
 0b68  53                mono_setxy_     push    ebx

bool mono_setxy (int x, int y)
 0b69  e8 00 00 00 00                    call    _mset_
 0b6e  84 c0                             test    al,al
 0b70  0f 84 9b 00 00 00                 je      L79

{
 0b76  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_done_init+3d80H,00H
 0b7d  75 05                             jne     L77
 0b7f  e8 00 00 00 00                    call    mono_init_
 0b84  80 3d 00 00 00 00 
       00                L77             cmp     byte ptr _mono_mode+3d80H,00H
 0b8b  0f 95 c0                          setne   al
 0b8e  84 c0                             test    al,al
 0b90  0f 84 7b 00 00 00                 je      L79

	if (!_mset(x,y)) return FALSE;				/* set even if screen disabled */
   if (!_mono_top()) return FALSE;
 0b96  a0 00 00 00 00                    mov     al,__cur_mono_focus+0a000H
 0b9b  3a 05 00 00 00 00                 cmp     al,__cur_mono_page+53aH
 0ba1  75 6c                             jne     L78

   if (_mono_focused())
 0ba3  31 d2                             xor     edx,edx
 0ba5  8a 15 00 00 00 00                 mov     dl,_mono_y+158aH
 0bab  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 0bb2  31 db                             xor     ebx,ebx
 0bb4  01 d0                             add     eax,edx
 0bb6  8a 1d 00 00 00 00                 mov     bl,_mono_x+1d8aH
 0bbc  c1 e0 04                          shl     eax,04H
 0bbf  01 c3                             add     ebx,eax

   {
 0bc1  31 c0                             xor     eax,eax
 0bc3  a0 00 00 00 00                    mov     al,__cur_card+0a0c0H
 0bc8  8b 14 85 00 00 00 
       00                                mov     edx,_srx_adr+8514H[eax*4]
 0bcf  b0 0e                             mov     al,0eH
 0bd1  ee                                out     dx,al
 0bd2  31 d2                             xor     edx,edx
 0bd4  89 d8                             mov     eax,ebx
 0bd6  8a 15 00 00 00 00                 mov     dl,__cur_card+158aH
 0bdc  c1 f8 08                          sar     eax,08H
 0bdf  8b 14 95 00 00 00 
       00                                mov     edx,_srx_data+9514H[edx*4]
 0be6  ee                                out     dx,al

	   int c_offset = MONO_WID*mono_y + mono_x;
	   out_set(_cur_card,SR_CLH,(c_offset)>>8);
 0be7  31 c0                             xor     eax,eax
 0be9  a0 00 00 00 00                    mov     al,__cur_card+0a0c0H
 0bee  8b 14 85 00 00 00 
       00                                mov     edx,_srx_adr+8514H[eax*4]
 0bf5  b0 0f                             mov     al,0fH
 0bf7  ee                                out     dx,al
 0bf8  31 d2                             xor     edx,edx
 0bfa  89 d8                             mov     eax,ebx
 0bfc  8a 15 00 00 00 00                 mov     dl,__cur_card+158aH
 0c02  25 ff 00 00 00                    and     eax,000000ffH
 0c07  8b 14 95 00 00 00 
       00                                mov     edx,_srx_data+9514H[edx*4]
 0c0e  ee                                out     dx,al

	   out_set(_cur_card,SR_CLL,(c_offset)&0xff);
 0c0f  b0 01             L78             mov     al,01H

   }
   return TRUE;
}
 0c11  5b                L79             pop     ebx
 0c12  c3                                ret     
 0c13  90                                nop     


/* return the current x,y coordinates */
 0c14  53                mono_getxy_     push    ebx

void mono_getxy(int *x, int *y)
 0c15  bb 01 00 00 00                    mov     ebx,00000001H
 0c1a  e8 00 00 00 00                    call    _mget_

{
	_mget(x,y,TRUE);
}
 0c1f  5b                                pop     ebx
 0c20  c3                                ret     
 0c21  8d 40 00                          lea     eax,+0H[eax]


/* clear the monochrome screen and reset cursor. */
void mono_clear (void)
 0c24  51                mono_clear_     push    ecx
 0c25  52                                push    edx
 0c26  57                                push    edi

{
 0c27  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_done_init+3d80H,00H
 0c2e  75 05                             jne     L80
 0c30  e8 00 00 00 00                    call    mono_init_
 0c35  80 3d 00 00 00 00 
       00                L80             cmp     byte ptr _mono_mode+3d80H,00H
 0c3c  0f 95 c0                          setne   al
 0c3f  84 c0                             test    al,al
 0c41  0f 84 b6 00 00 00                 je      L84

	int i;
 0c47  8b 0d fd ff ff ff                 mov     ecx,__cur_mono_page+0d8bH
 0c4d  c1 f9 18                          sar     ecx,18H
 0c50  8d 14 8d 00 00 00 
       00                                lea     edx,+0H[ecx*4]
 0c57  29 ca                             sub     edx,ecx
 0c59  c1 e2 03                          shl     edx,03H
 0c5c  01 ca                             add     edx,ecx
 0c5e  8b 8a ff ff ff ff                 mov     ecx,__mono_screens+8a8bH[edx]
 0c64  c1 f9 18                          sar     ecx,18H
 0c67  83 f9 ff                          cmp     ecx,0ffffH
 0c6a  74 47                             je      L82
 0c6c  80 ba 00 00 00 00 
       00                                cmp     byte ptr __mono_screens+0ba80H[edx],00H
 0c73  75 3e                             jne     L82

   if (!_mono_top()) return;
 0c75  31 d2                             xor     edx,edx

	if ((split_win!=-1)&&(split_axis==MONO_AXIS_X))
		for (i=0; i<MONO_HGT; i++)
 0c77  8b 3d fd ff ff ff L81             mov     edi,__cur_mono_page+3d8bH
 0c7d  c1 ff 18                          sar     edi,18H
 0c80  6b ff 19                          imul    edi,19H
 0c83  31 c0                             xor     eax,eax
 0c85  a0 00 00 00 00                    mov     al,_mono_attr+0a0c0H
 0c8a  31 c9                             xor     ecx,ecx
 0c8c  c1 e0 08                          shl     eax,08H
 0c8f  8a 8f 03 00 00 00                 mov     cl,__mono_screens+8f8aH[edi]
 0c95  8b bf 07 00 00 00                 mov     edi,__mono_screens+0bf8bH[edi]
 0c9b  98                                cwde    
 0c9c  01 d7                             add     edi,edx
 0c9e  81 c2 a0 00 00 00                 add     edx,000000a0H
 0ca4  57                                push    edi
 0ca5  f3 66 ab                          repe    stosw 
 0ca8  58                                pop     eax
 0ca9  81 fa a0 0f 00 00                 cmp     edx,00000fa0H
 0caf  74 43                             je      L83
 0cb1  eb c4                             jmp     L81

			smemset(split_base+i*MONO_ROW,mono_attr<<8,split_w);
 0cb3  8b 0d fd ff ff ff L82             mov     ecx,__cur_mono_page+0d8bH
 0cb9  c1 f9 18                          sar     ecx,18H
 0cbc  8d 3c 8d 00 00 00 
       00                                lea     edi,+0H[ecx*4]
 0cc3  29 cf                             sub     edi,ecx
 0cc5  c1 e7 03                          shl     edi,03H
 0cc8  31 c0                             xor     eax,eax
 0cca  01 cf                             add     edi,ecx
 0ccc  31 c9                             xor     ecx,ecx
 0cce  a0 00 00 00 00                    mov     al,_mono_attr+0a0c9H
 0cd3  8a 8f 04 00 00 00                 mov     cl,__mono_screens+8f8aH[edi]
 0cd9  c1 e0 08                          shl     eax,08H
 0cdc  8d 14 8d 00 00 00 
       00                                lea     edx,+0H[ecx*4]
 0ce3  98                                cwde    
 0ce4  01 d1                             add     ecx,edx
 0ce6  8b bf 07 00 00 00                 mov     edi,__mono_screens+0bf8bH[edi]
 0cec  c1 e1 04                          shl     ecx,04H
 0cef  57                                push    edi
 0cf0  f3 66 ab                          repe    stosw 
 0cf3  58                                pop     eax

	else
 0cf4  31 d2             L83             xor     edx,edx
 0cf6  31 c0                             xor     eax,eax
 0cf8  e8 00 00 00 00                    call    mono_setxy_

		smemset(split_base,mono_attr<<8,MONO_WID*split_h);
   mono_setxy (0, 0);
}
 0cfd  5f                L84             pop     edi
 0cfe  5a                                pop     edx
 0cff  59                                pop     ecx
 0d00  c3                                ret     
 0d01  8d 40 00                          lea     eax,+0H[eax]


/* scroll the monochrome screen by n lines, blanking bottom n lines. */
void mono_scroll (int n)
{
	int i;
 0d04  53                mono_scroll_    push    ebx
 0d05  51                                push    ecx
 0d06  52                                push    edx
 0d07  56                                push    esi
 0d08  57                                push    edi
 0d09  55                                push    ebp
 0d0a  83 ec 10                          sub     esp,0010H
 0d0d  89 c5                             mov     ebp,eax

   uchar *src, *dst, *bot;
 0d0f  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_done_init+3d80H,00H
 0d16  75 05                             jne     L85
 0d18  e8 00 00 00 00                    call    mono_init_
 0d1d  80 3d 00 00 00 00 
       00                L85             cmp     byte ptr _mono_mode+3d80H,00H
 0d24  0f 95 c0                          setne   al
 0d27  84 c0                             test    al,al
 0d29  0f 84 bb 02 00 00                 je      L98


 0d2f  a1 fd ff ff ff                    mov     eax,__cur_mono_page+0a100H
 0d34  c1 f8 18                          sar     eax,18H
 0d37  8d 14 85 00 00 00 
       00                                lea     edx,+0H[eax*4]
 0d3e  29 c2                             sub     edx,eax
 0d40  c1 e2 03                          shl     edx,03H
 0d43  01 c2                             add     edx,eax
 0d45  31 c0                             xor     eax,eax
 0d47  8a 82 04 00 00 00                 mov     al,__mono_screens+828aH[edx]
 0d4d  39 c5                             cmp     ebp,eax
 0d4f  7c 1c                             jl      L87

   if (!_mono_top()) return;
 0d51  8a 9a 14 00 00 00                 mov     bl,__mono_screens+9a8aH[edx]
 0d57  84 db                             test    bl,bl
 0d59  74 08                             je      L86
 0d5b  88 d8                             mov     al,bl
 0d5d  24 03                             and     al,03H
 0d5f  3c 03                             cmp     al,03H
 0d61  75 0a                             jne     L87

   if (n >= split_h)
      if ((split_flags==0)||((split_flags&MONO_FLG_WRAPCLEAR)==MONO_FLG_WRAPCLEAR))
 0d63  e8 00 00 00 00    L86             call    mono_clear_
 0d68  e9 7d 02 00 00                    jmp     L98

         { mono_clear (); return; }

   if (split_flags&MONO_FLG_WRAP)
 0d6d  a1 fd ff ff ff    L87             mov     eax,__cur_mono_page+0a100H
 0d72  c1 f8 18                          sar     eax,18H
 0d75  8d 1c 85 00 00 00 
       00                                lea     ebx,+0H[eax*4]
 0d7c  29 c3                             sub     ebx,eax
 0d7e  c1 e3 03                          shl     ebx,03H
 0d81  01 c3                             add     ebx,eax
 0d83  f6 83 14 00 00 00 
       01                                test    byte ptr __mono_screens+83f6H[ebx],01H
 0d8a  0f 84 22 01 00 00                 je      L93

   {
 0d90  bb 01 00 00 00                    mov     ebx,00000001H
 0d95  89 e2                             mov     edx,esp
 0d97  8d 44 24 04                       lea     eax,+4H[esp]
 0d9b  e8 00 00 00 00                    call    _mget_

      int x, y;
      _mget(&x,&y,TRUE);
 0da0  a1 fd ff ff ff                    mov     eax,__cur_mono_page+0a100H
 0da5  c1 f8 18                          sar     eax,18H
 0da8  8d 14 85 00 00 00 
       00                                lea     edx,+0H[eax*4]
 0daf  29 c2                             sub     edx,eax
 0db1  c1 e2 03                          shl     edx,03H
 0db4  01 d0                             add     eax,edx
 0db6  31 d2                             xor     edx,edx
 0db8  8a 90 04 00 00 00                 mov     dl,__mono_screens+908aH[eax]
 0dbe  8b 0c 24                          mov     ecx,[esp]
 0dc1  8d 5a ff                          lea     ebx,-1H[edx]
 0dc4  39 cb                             cmp     ebx,ecx
 0dc6  7e 67                             jle     L89

      if (y<split_h-1)
 0dc8  f6 80 14 00 00 00 
       02                                test    byte ptr __mono_screens+80f6H[eax],02H
 0dcf  74 38                             je      L88
 0dd1  29 ca                             sub     edx,ecx

      {
 0dd3  89 ce                             mov     esi,ecx
 0dd5  8d 5a ff                          lea     ebx,-1H[edx]
 0dd8  8b b8 07 00 00 00                 mov     edi,__mono_screens+0b88bH[eax]
 0dde  8d 0c 9d 00 00 00 
       00                                lea     ecx,+0H[ebx*4]
 0de5  89 f2                             mov     edx,esi
 0de7  01 d9                             add     ecx,ebx
 0de9  c1 e2 02                          shl     edx,02H
 0dec  c1 e1 04                          shl     ecx,04H
 0def  31 db                             xor     ebx,ebx
 0df1  01 f2                             add     edx,esi
 0df3  8a 1d 00 00 00 00                 mov     bl,_mono_attr+1d8aH
 0df9  c1 e2 05                          shl     edx,05H
 0dfc  c1 e3 08                          shl     ebx,08H
 0dff  01 d7                             add     edi,edx
 0e01  0f bf c3                          movsx   eax,bx
 0e04  57                                push    edi
 0e05  f3 66 ab                          repe    stosw 
 0e08  58                                pop     eax

         if (split_flags&MONO_FLG_CLEAR)
	         smemset(split_base+y*MONO_ROW,mono_attr<<8,(split_h-y-1)*MONO_WID);
         n-=(split_h-y-1);
 0e09  a1 fd ff ff ff    L88             mov     eax,__cur_mono_page+0a158H
 0e0e  c1 f8 18                          sar     eax,18H
 0e11  8d 14 85 00 00 00 
       00                                lea     edx,+0H[eax*4]
 0e18  29 c2                             sub     edx,eax
 0e1a  c1 e2 03                          shl     edx,03H
 0e1d  01 c2                             add     edx,eax
 0e1f  31 c0                             xor     eax,eax
 0e21  8b 3c 24                          mov     edi,[esp]
 0e24  8a 82 04 00 00 00                 mov     al,__mono_screens+828aH[edx]
 0e2a  29 f8                             sub     eax,edi
 0e2c  48                                dec     eax
 0e2d  29 c5                             sub     ebp,eax

         
      }  /* now at top of window */
 0e2f  85 ed             L89             test    ebp,ebp
 0e31  7e 47                             jle     L91

      if (n>0)
 0e33  a1 fd ff ff ff                    mov     eax,__cur_mono_page+0a147H
 0e38  c1 f8 18                          sar     eax,18H
 0e3b  8d 3c 85 00 00 00 
       00                                lea     edi,+0H[eax*4]
 0e42  29 c7                             sub     edi,eax
 0e44  c1 e7 03                          shl     edi,03H
 0e47  01 c7                             add     edi,eax
 0e49  f6 87 14 00 00 00 
       02                                test    byte ptr __mono_screens+87f6H[edi],02H
 0e50  74 22                             je      L90

      {
 0e52  8d 0c ad 00 00 00 
       00                                lea     ecx,+0H[ebp*4]
 0e59  31 c0                             xor     eax,eax
 0e5b  8b bf 07 00 00 00                 mov     edi,__mono_screens+0bf8bH[edi]
 0e61  a0 00 00 00 00                    mov     al,_mono_attr+0a000H
 0e66  01 e9                             add     ecx,ebp
 0e68  c1 e0 08                          shl     eax,08H
 0e6b  c1 e1 04                          shl     ecx,04H
 0e6e  98                                cwde    
 0e6f  57                                push    edi
 0e70  f3 66 ab                          repe    stosw 
 0e73  58                                pop     eax

         if (split_flags&MONO_FLG_CLEAR)
	         smemset(split_base,mono_attr<<8,n*MONO_WID);
 0e74  4d                L90             dec     ebp
 0e75  89 2c 24                          mov     [esp],ebp

         y=n-1;
 0e78  eb 24                             jmp     L92
 0e7a  a1 fd ff ff ff    L91             mov     eax,__cur_mono_page+0a124H
 0e7f  c1 f8 18                          sar     eax,18H
 0e82  8d 14 85 00 00 00 
       00                                lea     edx,+0H[eax*4]
 0e89  29 c2                             sub     edx,eax
 0e8b  c1 e2 03                          shl     edx,03H
 0e8e  01 c2                             add     edx,eax
 0e90  31 c0                             xor     eax,eax
 0e92  8a 82 04 00 00 00                 mov     al,__mono_screens+828aH[edx]
 0e98  01 e8                             add     eax,ebp
 0e9a  48                                dec     eax
 0e9b  89 04 24                          mov     [esp],eax

      }
      else y=split_h+n-1;
      _mset(0,y);
   }
 0e9e  8b 14 24          L92             mov     edx,[esp]
 0ea1  31 c0                             xor     eax,eax
 0ea3  e8 00 00 00 00                    call    _mset_
 0ea8  83 c4 10                          add     esp,0010H
 0eab  5d                                pop     ebp
 0eac  5f                                pop     edi
 0ead  5e                                pop     esi
 0eae  5a                                pop     edx
 0eaf  59                                pop     ecx
 0eb0  5b                                pop     ebx
 0eb1  c3                                ret     

	else
   {   
 0eb2  8d 14 ad 00 00 00 
       00                L93             lea     edx,+0H[ebp*4]
 0eb9  01 ea                             add     edx,ebp
 0ebb  8b 83 07 00 00 00                 mov     eax,__mono_screens+838bH[ebx]
 0ec1  c1 e2 05                          shl     edx,05H
 0ec4  8d 0c 10                          lea     ecx,[eax+edx]

 0ec7  31 d2                             xor     edx,edx
 0ec9  8a 93 04 00 00 00                 mov     dl,__mono_screens+938aH[ebx]
 0ecf  29 ea                             sub     edx,ebp
 0ed1  89 54 24 08                       mov     +8H[esp],edx
 0ed5  8b 7c 24 08                       mov     edi,+8H[esp]
 0ed9  c1 e2 02                          shl     edx,02H
 0edc  01 fa                             add     edx,edi
 0ede  c1 e2 05                          shl     edx,05H

	   src = split_base+n*MONO_ROW;
	   dst = split_base;
 0ee1  89 c6                             mov     esi,eax
 0ee3  8d 3c 10                          lea     edi,[eax+edx]

	   bot = split_base+(split_h-n)*MONO_ROW;
	   if ((split_win!=-1)&&(split_axis==MONO_AXIS_X))
 0ee6  8b 93 ff ff ff ff                 mov     edx,__mono_screens+938bH[ebx]
 0eec  c1 fa 18                          sar     edx,18H
 0eef  89 7c 24 0c                       mov     +0cH[esp],edi
 0ef3  83 fa ff                          cmp     edx,0ffffH
 0ef6  0f 84 99 00 00 00                 je      L97
 0efc  80 bb 00 00 00 00 
       00                                cmp     byte ptr __mono_screens+0bb80H[ebx],00H
 0f03  0f 85 8c 00 00 00                 jne     L97
 0f09  89 c7                             mov     edi,eax

		{
 0f0b  31 c6                             xor     esi,eax
 0f0d  eb 24                             jmp     L95

			for (i=0; i<(split_h-n); i++)
 0f0f  8a 9b 03 00 00 00 L94             mov     bl,__mono_screens+9b8aH[ebx]
 0f15  81 e3 ff 00 00 00                 and     ebx,000000ffH
 0f1b  89 ca                             mov     edx,ecx
 0f1d  89 f8                             mov     eax,edi
 0f1f  01 db                             add     ebx,ebx
 0f21  46                                inc     esi
 0f22  e8 00 00 00 00                    call    memmove_
 0f27  81 c7 a0 00 00 00                 add     edi,000000a0H
 0f2d  81 c1 a0 00 00 00                 add     ecx,000000a0H
 0f33  8b 1d fd ff ff ff L95             mov     ebx,__cur_mono_page+1d8bH
 0f39  c1 fb 18                          sar     ebx,18H
 0f3c  6b db 19                          imul    ebx,19H
 0f3f  31 d2                             xor     edx,edx
 0f41  8a 93 04 00 00 00                 mov     dl,__mono_screens+938aH[ebx]
 0f47  29 ea                             sub     edx,ebp
 0f49  39 d6                             cmp     esi,edx
 0f4b  7c c2                             jl      L94

				memmove(dst+i*MONO_ROW,src+i*MONO_ROW,2*split_w);
 0f4d  31 db                             xor     ebx,ebx
 0f4f  85 ed                             test    ebp,ebp
 0f51  0f 8e 93 00 00 00                 jle     L98
 0f57  8b 54 24 0c                       mov     edx,+0cH[esp]

			for (i=0; i<n; i++)
				smemset(bot+i*MONO_ROW,mono_attr<<8,split_w);
		}
		else
 0f5b  8b 0d fd ff ff ff L96             mov     ecx,__cur_mono_page+0d8bH
 0f61  c1 f9 18                          sar     ecx,18H
 0f64  6b c9 19                          imul    ecx,19H
 0f67  8a 89 03 00 00 00                 mov     cl,__mono_screens+898aH[ecx]
 0f6d  66 0f b6 35 00 00 
       00 00                             movzx   si,byte ptr _mono_attr+35b6H
 0f75  81 e1 ff 00 00 00                 and     ecx,000000ffH
 0f7b  89 d7                             mov     edi,edx
 0f7d  c1 e6 08                          shl     esi,08H
 0f80  43                                inc     ebx
 0f81  0f bf c6                          movsx   eax,si
 0f84  81 c2 a0 00 00 00                 add     edx,000000a0H
 0f8a  57                                push    edi
 0f8b  f3 66 ab                          repe    stosw 
 0f8e  58                                pop     eax
 0f8f  39 eb                             cmp     ebx,ebp
 0f91  7d 57                             jge     L98
 0f93  eb c6                             jmp     L96

		{
 0f95  a1 fd ff ff ff    L97             mov     eax,__cur_mono_page+0a1c6H
 0f9a  c1 f8 18                          sar     eax,18H
 0f9d  8d 14 85 00 00 00 
       00                                lea     edx,+0H[eax*4]
 0fa4  29 c2                             sub     edx,eax
 0fa6  c1 e2 03                          shl     edx,03H
 0fa9  01 c2                             add     edx,eax
 0fab  31 c0                             xor     eax,eax
 0fad  8a 82 04 00 00 00                 mov     al,__mono_screens+828aH[edx]
 0fb3  29 e8                             sub     eax,ebp
 0fb5  8d 1c 85 00 00 00 
       00                                lea     ebx,+0H[eax*4]
 0fbc  01 c3                             add     ebx,eax
 0fbe  89 ca                             mov     edx,ecx
 0fc0  c1 e3 05                          shl     ebx,05H
 0fc3  89 f0                             mov     eax,esi
 0fc5  8b 7c 24 0c                       mov     edi,+0cH[esp]
 0fc9  e8 00 00 00 00                    call    memmove_
 0fce  31 c0                             xor     eax,eax

		   memmove (dst, src, (split_h-n)*MONO_ROW);
		   smemset (bot, mono_attr<<8, n*MONO_WID);
		}
 0fd0  8d 0c ad 00 00 00 
       00                                lea     ecx,+0H[ebp*4]
 0fd7  a0 00 00 00 00                    mov     al,_mono_attr+0a000H
 0fdc  01 e9                             add     ecx,ebp
 0fde  c1 e0 08                          shl     eax,08H
 0fe1  c1 e1 04                          shl     ecx,04H
 0fe4  98                                cwde    
 0fe5  57                                push    edi
 0fe6  f3 66 ab                          repe    stosw 
 0fe9  58                                pop     eax

   }
}
 0fea  83 c4 10          L98             add     esp,0010H
 0fed  5d                                pop     ebp
 0fee  5f                                pop     edi
 0fef  5e                                pop     esi
 0ff0  5a                                pop     edx
 0ff1  59                                pop     ecx
 0ff2  5b                                pop     ebx
 0ff3  c3                                ret     


bool _mono_log(void)
{
 0ff4  52                _mono_log_      push    edx

//   return ((mono_spc_func!=NULL)||((mono_file!=-1)&&(!mono_screen||(mlog&split_win))));
   return    (mono_spc_func!=NULL) ||
            ((mono_file!=-1)&&
 0ff5  83 3d 00 00 00 00 
       00                                cmp     dword ptr _mono_spc_func+3d83H,0000H
 0ffc  75 43                             jne     L99
 0ffe  83 3d 00 00 00 00 
       ff                                cmp     dword ptr _mono_file+3d83H,0ffffH
 1005  74 3e                             je      L100
 1007  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_screen+3d80H,00H
 100e  74 31                             je      L99
 1010  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mlog+3d80H,00H
 1017  74 28                             je      L99
 1019  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 101f  c1 fa 18                          sar     edx,18H
 1022  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 1029  29 d0                             sub     eax,edx
 102b  8b 84 c2 ff ff ff 
       ff                                mov     eax,__mono_screens+0c284H[edx+eax*8]
 1032  31 d2                             xor     edx,edx
 1034  c1 f8 18                          sar     eax,18H
 1037  8a 15 00 00 00 00                 mov     dl,_mlog+158aH
 103d  85 c2                             test    edx,eax
 103f  74 04                             je      L100
 1041  b0 01             L99             mov     al,01H
 1043  5a                                pop     edx
 1044  c3                                ret     
 1045  30 c0             L100            xor     al,al

               (!mono_screen||((mlog==0)||(mlog&split_win))));
}

 1047  5a                                pop     edx
 1048  c3                                ret     
 1049  8d 40 00                          lea     eax,+0H[eax]

// doesnt correctly support split width stuff....
int _mscroll_msg(int *x, int *y)
 104c  53                _mscroll_msg_   push    ebx
 104d  51                                push    ecx
 104e  56                                push    esi
 104f  57                                push    edi
 1050  55                                push    ebp
 1051  83 ec 10                          sub     esp,0010H
 1054  89 c5                             mov     ebp,eax
 1056  89 d3                             mov     ebx,edx

{
 1058  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 105e  c1 fa 18                          sar     edx,18H
 1061  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 1068  29 d0                             sub     eax,edx
 106a  c1 e0 03                          shl     eax,03H
 106d  01 c2                             add     edx,eax
 106f  f6 82 14 00 00 00 
       02                                test    byte ptr __mono_screens+82f6H[edx],02H
 1076  74 3a                             je      L101
 1078  31 c0                             xor     eax,eax
 107a  a0 00 00 00 00                    mov     al,_mono_attr+0a0c0H
 107f  c1 e0 08                          shl     eax,08H
 1082  8b 0b                             mov     ecx,[ebx]
 1084  66 89 44 24 0c                    mov     +0cH[esp],ax
 1089  8d 04 8d 00 00 00 
       00                                lea     eax,+0H[ecx*4]
 1090  01 c8                             add     eax,ecx
 1092  8b ba 07 00 00 00                 mov     edi,__mono_screens+0ba8bH[edx]
 1098  c1 e0 05                          shl     eax,05H

   if (split_flags&MONO_FLG_CLEAR)
 109b  0f b6 b2 03 00 00 
       00                                movzx   esi,byte ptr __mono_screens+0b2b6H[edx]
 10a2  01 c7                             add     edi,eax
 10a4  8b 44 24 0a                       mov     eax,+0aH[esp]
 10a8  89 f1                             mov     ecx,esi
 10aa  c1 f8 10                          sar     eax,10H
 10ad  57                                push    edi
 10ae  f3 66 ab                          repe    stosw 
 10b1  58                                pop     eax

      smemset(split_base+(*y)*MONO_ROW,mono_attr<<8,split_w);
   if ((split_flags&MONO_FLG_MSG)&&(split_msg!=NULL))
 10b2  8b 15 fd ff ff ff L101            mov     edx,__cur_mono_page+158bH
 10b8  c1 fa 18                          sar     edx,18H
 10bb  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 10c2  29 d0                             sub     eax,edx
 10c4  c1 e0 03                          shl     eax,03H
 10c7  01 d0                             add     eax,edx
 10c9  f6 80 14 00 00 00 
       04                                test    byte ptr __mono_screens+80f6H[eax],04H
 10d0  0f 84 eb 00 00 00                 je      L103
 10d6  83 b8 15 00 00 00 
       00                                cmp     dword ptr __mono_screens+0b883H[eax],0000H
 10dd  0f 84 de 00 00 00                 je      L103
 10e3  8b b8 15 00 00 00                 mov     edi,__mono_screens+0b88bH[eax]

   {
 10e9  8b 13                             mov     edx,[ebx]
 10eb  29 c9                             sub     ecx,ecx
 10ed  49                                dec     ecx
 10ee  31 c0                             xor     eax,eax
 10f0  f2 ae                             repne   scasb 
 10f2  f7 d1                             not     ecx
 10f4  49                                dec     ecx
 10f5  89 54 24 08                       mov     +8H[esp],edx

      int old_y=*y, chars_in_msg=strlen(split_msg);
 10f9  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 10ff  c1 fa 18                          sar     edx,18H
 1102  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 1109  29 d0                             sub     eax,edx
 110b  0f b6 bc c2 04 00 
       00 00                             movzx   edi,byte ptr __mono_screens+0c2bcH[edx+eax*8]
 1113  8b 13                             mov     edx,[ebx]
 1115  42                                inc     edx
 1116  89 d0                             mov     eax,edx
 1118  c1 fa 1f                          sar     edx,1fH
 111b  f7 ff                             idiv    edi
 111d  89 13                             mov     [ebx],edx

      *y=((*y)+1)%split_h;
 111f  8b 45 00                          mov     eax,+0H[ebp]
 1122  89 ce                             mov     esi,ecx
 1124  e8 00 00 00 00                    call    _mset_

      _mset(*x,*y);
 1129  85 c9                             test    ecx,ecx
 112b  7e 64                             jle     L102
 112d  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 1133  c1 fa 18                          sar     edx,18H
 1136  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 113d  29 d0                             sub     eax,edx
 113f  c1 e0 03                          shl     eax,03H
 1142  01 c2                             add     edx,eax
 1144  8b 82 15 00 00 00                 mov     eax,__mono_screens+828bH[edx]
 114a  80 7c 06 ff 0a                    cmp     byte ptr -1H[esi+eax],0aH
 114f  75 40                             jne     L102

      if ((chars_in_msg>0)&&(split_msg[chars_in_msg-1]=='\n'))
 1151  31 c0                             xor     eax,eax
 1153  8a 82 03 00 00 00                 mov     al,__mono_screens+828aH[edx]
 1159  89 04 24                          mov     [esp],eax
 115c  8b 03                             mov     eax,[ebx]
 115e  89 44 24 04                       mov     +4H[esp],eax
 1162  66 0f b6 3d 00 00 
       00 00                             movzx   di,byte ptr _mono_attr+3db6H
 116a  8b 4c 24 04                       mov     ecx,+4H[esp]
 116e  c1 e0 02                          shl     eax,02H
 1171  c1 e7 08                          shl     edi,08H
 1174  01 c8                             add     eax,ecx
 1176  8b 92 07 00 00 00                 mov     edx,__mono_screens+928bH[edx]
 117c  c1 e0 05                          shl     eax,05H
 117f  8b 0c 24                          mov     ecx,[esp]
 1182  01 c2                             add     edx,eax
 1184  0f bf c7                          movsx   eax,di
 1187  89 d7                             mov     edi,edx
 1189  57                                push    edi
 118a  f3 66 ab                          repe    stosw 
 118d  58                                pop     eax
 118e  8d 4e ff                          lea     ecx,-1H[esi]

       { smemset(split_base+(*y)*MONO_ROW,mono_attr<<8,split_w); chars_in_msg--; }
 1191  8b 15 fd ff ff ff L102            mov     edx,__cur_mono_page+158bH
 1197  c1 fa 18                          sar     edx,18H
 119a  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 11a1  29 d0                             sub     eax,edx
 11a3  8b 84 c2 15 00 00 
       00                                mov     eax,__mono_screens+0c284H[edx+eax*8]
 11aa  89 ca                             mov     edx,ecx
 11ac  e8 00 00 00 00                    call    _mprint_

      _mprint(split_msg,chars_in_msg);
 11b1  8b 44 24 08                       mov     eax,+8H[esp]
 11b5  89 03                             mov     [ebx],eax

      *y=old_y;
      _mset(*x,*y);
 11b7  89 c2                             mov     edx,eax
 11b9  8b 45 00                          mov     eax,+0H[ebp]
 11bc  e8 00 00 00 00                    call    _mset_

   }
 11c1  8b 03             L103            mov     eax,[ebx]

   return *y;
}
 11c3  83 c4 10                          add     esp,0010H
 11c6  5d                                pop     ebp
 11c7  5f                                pop     edi
 11c8  5e                                pop     esi
 11c9  59                                pop     ecx
 11ca  5b                                pop     ebx
 11cb  c3                                ret     


int _mscroll_us(int n, int *x, int *y)
 11cc  51                _mscroll_us_    push    ecx
 11cd  56                                push    esi
 11ce  57                                push    edi
 11cf  89 c7                             mov     edi,eax
 11d1  89 d6                             mov     esi,edx
 11d3  89 d9                             mov     ecx,ebx

{
 11d5  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 11db  c1 fa 18                          sar     edx,18H
 11de  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 11e5  29 d0                             sub     eax,edx
 11e7  8a 84 c2 04 00 00 
       00                                mov     al,__mono_screens+0c284H[edx+eax*8]
 11ee  25 ff 00 00 00                    and     eax,000000ffH
 11f3  8b 13                             mov     edx,[ebx]
 11f5  29 f8                             sub     eax,edi
 11f7  39 d0                             cmp     eax,edx
 11f9  7e 07                             jle     L104

   if (*y < split_h-n)
 11fb  8d 1c 3a                          lea     ebx,[edx+edi]
 11fe  89 19                             mov     [ecx],ebx

	   (*y)+=n;
   else
 1200  eb 15                             jmp     L105

   {
 1202  89 f8             L104            mov     eax,edi

		mono_scroll (n);
	   _mget(x,y,TRUE);
   }
 1204  bb 01 00 00 00                    mov     ebx,00000001H
 1209  e8 00 00 00 00                    call    mono_scroll_
 120e  89 ca                             mov     edx,ecx
 1210  89 f0                             mov     eax,esi
 1212  e8 00 00 00 00                    call    _mget_

 1217  89 ca             L105            mov     edx,ecx
 1219  89 f0                             mov     eax,esi

   *x = 0;
   _mscroll_msg(x,y);
 121b  c7 06 00 00 00 00                 mov     dword ptr [esi],00000000H
 1221  e8 00 00 00 00                    call    _mscroll_msg_

   return *y;
 1226  8b 01                             mov     eax,[ecx]

}

/* internal print a buffer a length n to the mono screen */
 1228  5f                                pop     edi
 1229  5e                                pop     esi
 122a  59                                pop     ecx
 122b  c3                                ret     
 122c  28 13 00 00                       DD      L139
 1230  58 13 00 00                       DD      mono_detect_
 1234  8c 13 00 00                       DD      mono_detect_
 1238  58 13 00 00                       DD      mono_detect_
 123c  48 13 00 00                       DD      mono_detect_
 1240  1d 13 00 00                       DD      mono_detect_

int _mprint(char *s, int n)
{
   int i,cur_x,cur_y;
   uchar *p;                           /* pointer to current line. */

 1244  53                _mprint_        push    ebx
 1245  51                                push    ecx
 1246  56                                push    esi
 1247  57                                push    edi
 1248  55                                push    ebp
 1249  83 ec 08                          sub     esp,0008H
 124c  89 c1                             mov     ecx,eax
 124e  89 d7                             mov     edi,edx

   if (_mono_log())
 1250  83 3d 00 00 00 00 
       00                                cmp     dword ptr _mono_spc_func+3d83H,0000H
 1257  75 42                             jne     L106
 1259  83 3d 00 00 00 00 
       ff                                cmp     dword ptr _mono_file+3d83H,0ffffH
 1260  74 3d                             je      L107
 1262  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_screen+3d80H,00H
 1269  74 30                             je      L106
 126b  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mlog+3d80H,00H
 1272  74 27                             je      L106
 1274  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 127a  c1 fa 18                          sar     edx,18H
 127d  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 1284  29 d0                             sub     eax,edx
 1286  8b 94 c2 ff ff ff 
       ff                                mov     edx,__mono_screens+0c294H[edx+eax*8]
 128d  31 c0                             xor     eax,eax
 128f  c1 fa 18                          sar     edx,18H
 1292  a0 00 00 00 00                    mov     al,_mlog+0a018H
 1297  85 d0                             test    eax,edx
 1299  74 04                             je      L107
 129b  b0 01             L106            mov     al,01H
 129d  eb 02                             jmp     L108
 129f  30 c0             L107            xor     al,al
 12a1  84 c0             L108            test    al,al
 12a3  74 0e                             je      L109

      write (mono_file, s, n);			/* write even if no screen */
 12a5  a1 00 00 00 00                    mov     eax,_mono_file+0a10eH
 12aa  89 fb                             mov     ebx,edi
 12ac  89 ca                             mov     edx,ecx
 12ae  e8 00 00 00 00                    call    write_

   _mono_spc_check(s,n);

 12b3  83 3d 00 00 00 00 
       00                L109            cmp     dword ptr _mono_spc_func+3d83H,0000H
 12ba  74 0a                             je      L110
 12bc  89 fa                             mov     edx,edi
 12be  89 c8                             mov     eax,ecx
 12c0  ff 15 00 00 00 00                 call    dword ptr _mono_spc_func+15ffH

	if (mono_mode==MONO_OFF || !mono_screen) return n;/* no screen, so dont print */

 12c6  80 3d 00 00 00 00 
       00                L110            cmp     byte ptr _mono_mode+3d80H,00H
 12cd  0f 84 df 00 00 00                 je      L117
 12d3  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_screen+3d80H,00H
 12da  0f 84 d2 00 00 00                 je      L117

	_mget(&cur_x,&cur_y,TRUE);
 12e0  bb 01 00 00 00                    mov     ebx,00000001H
 12e5  89 e2                             mov     edx,esp
 12e7  8d 44 24 04                       lea     eax,+4H[esp]
 12eb  e8 00 00 00 00                    call    _mget_

   for (i=0; i<n; i++)
   {
 12f0  31 f6                             xor     esi,esi
 12f2  85 ff                             test    edi,edi
 12f4  0f 8e ac 00 00 00                 jle     L116

		p = _maddr(cur_x,cur_y);

 12fa  8b 14 24          L111            mov     edx,[esp]
 12fd  8b 44 24 04                       mov     eax,+4H[esp]
 1301  e8 00 00 00 00                    call    _maddr_
 1306  89 c2                             mov     edx,eax

      switch (s[i])
      {
      case '\n':
         _mscroll_us(1,&cur_x,&cur_y);
         break;
      case '\r':
 1308  8a 01                             mov     al,[ecx]
 130a  2c 08                             sub     al,08H
 130c  3c 05                             cmp     al,05H
 130e  77 48                             ja      L113
 1310  25 ff 00 00 00                    and     eax,000000ffH
 1315  2e ff 24 85 2c 12 
       00 00                             jmp     dword ptr cs:L138[eax*4]

         cur_x = 0;
 131d  31 d2                             xor     edx,edx
 131f  89 54 24 04                       mov     +4H[esp],edx

         break;
      case '\b':
 1323  e9 74 00 00 00                    jmp     L115

         if (cur_x > 0)
 1328  8b 44 24 04                       mov     eax,+4H[esp]
 132c  85 c0                             test    eax,eax
 132e  7e 09                             jle     L112

            cur_x--;
 1330  8d 68 ff                          lea     ebp,-1H[eax]
 1333  89 6c 24 04                       mov     +4H[esp],ebp

         else if (cur_y > 0)
 1337  eb 63                             jmp     L115
 1339  8b 14 24          L112            mov     edx,[esp]
 133c  85 d2                             test    edx,edx
 133e  7e 5c                             jle     L115

            cur_y--;
         break;
      case '\014':
         mono_clear();
 1340  8d 5a ff                          lea     ebx,-1H[edx]
 1343  89 1c 24                          mov     [esp],ebx
 1346  eb 54                             jmp     L115

 1348  31 db                             xor     ebx,ebx

         cur_x=cur_y=0;
         break;
 134a  e8 00 00 00 00                    call    mono_clear_
 134f  89 1c 24                          mov     [esp],ebx
 1352  89 5c 24 04                       mov     +4H[esp],ebx

      default:
         p[0] = (uchar)s[i];
 1356  eb 44                             jmp     L115

         p[1] = mono_attr;
 1358  8a 01             L113            mov     al,[ecx]
 135a  88 02                             mov     [edx],al

         if (cur_x < split_w-1)
 135c  a0 00 00 00 00                    mov     al,_mono_attr+0a002H
 1361  88 42 01                          mov     +1H[edx],al

            cur_x++;
 1364  a1 fd ff ff ff                    mov     eax,__cur_mono_page+0a101H
 1369  c1 f8 18                          sar     eax,18H
 136c  6b c0 19                          imul    eax,19H
 136f  8a 80 03 00 00 00                 mov     al,__mono_screens+808aH[eax]
 1375  25 ff 00 00 00                    and     eax,000000ffH
 137a  8b 6c 24 04                       mov     ebp,+4H[esp]
 137e  48                                dec     eax
 137f  39 e8                             cmp     eax,ebp
 1381  7e 09                             jle     L114

         else
 1383  8d 45 01                          lea     eax,+1H[ebp]
 1386  89 44 24 04                       mov     +4H[esp],eax

            _mscroll_us(1,&cur_x,&cur_y);
 138a  eb 10                             jmp     L115

         break;
      }
   }
 138c  89 e3             L114            mov     ebx,esp
 138e  8d 54 24 04                       lea     edx,+4H[esp]
 1392  b8 01 00 00 00                    mov     eax,00000001H
 1397  e8 00 00 00 00                    call    _mscroll_us_

   mono_setxy (cur_x, cur_y);
 139c  46                L115            inc     esi
 139d  41                                inc     ecx
 139e  39 fe                             cmp     esi,edi
 13a0  0f 8c 54 ff ff ff                 jl      L111

   return n;
 13a6  8b 14 24          L116            mov     edx,[esp]
 13a9  8b 44 24 04                       mov     eax,+4H[esp]
 13ad  e8 00 00 00 00                    call    mono_setxy_

}
 13b2  89 f8             L117            mov     eax,edi


/* printf to the monochrome screen.  has the same arguments and return value
   as printf (returns number of items printed).  uses vsprintf to print into
   a 1k buffer which is then transferred to the mono screen char by char. */
int mprintf(char *fmt, ...)
 13b4  83 c4 08                          add     esp,0008H
 13b7  5d                                pop     ebp
 13b8  5f                                pop     edi
 13b9  5e                                pop     esi
 13ba  59                                pop     ecx
 13bb  5b                                pop     ebx
 13bc  c3                                ret     
 13bd  8d 40 00                          lea     eax,+0H[eax]

{
   char buf[1024];
   int n;
   va_list ap;

   if (!_mono_top())
 13c0  53                mprintf_        push    ebx
 13c1  51                                push    ecx
 13c2  52                                push    edx
 13c3  81 ec 04 04 00 00                 sub     esp,00000404H

      if (!_mono_log())
 13c9  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_done_init+3d80H,00H
 13d0  75 05                             jne     L118
 13d2  e8 00 00 00 00                    call    mono_init_
 13d7  80 3d 00 00 00 00 
       00                L118            cmp     byte ptr _mono_mode+3d80H,00H
 13de  0f 95 c0                          setne   al
 13e1  84 c0                             test    al,al
 13e3  75 5d                             jne     L122

	      return -1;
 13e5  83 3d 00 00 00 00 
       00                                cmp     dword ptr _mono_spc_func+3d83H,0000H
 13ec  75 43                             jne     L119
 13ee  83 3d 00 00 00 00 
       ff                                cmp     dword ptr _mono_file+3d83H,0ffffH
 13f5  74 3e                             je      L120
 13f7  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_screen+3d80H,00H
 13fe  74 31                             je      L119
 1400  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mlog+3d80H,00H
 1407  74 28                             je      L119
 1409  8b 1d fd ff ff ff                 mov     ebx,__cur_mono_page+1d8bH
 140f  c1 fb 18                          sar     ebx,18H
 1412  8d 04 9d 00 00 00 
       00                                lea     eax,+0H[ebx*4]
 1419  29 d8                             sub     eax,ebx
 141b  8b 84 c3 ff ff ff 
       ff                                mov     eax,__mono_screens+0c384H[ebx+eax*8]
 1422  31 db                             xor     ebx,ebx
 1424  c1 f8 18                          sar     eax,18H
 1427  8a 1d 00 00 00 00                 mov     bl,_mlog+1d8aH
 142d  85 c3                             test    ebx,eax
 142f  74 04                             je      L120
 1431  b0 01             L119            mov     al,01H
 1433  eb 02                             jmp     L121
 1435  30 c0             L120            xor     al,al
 1437  84 c0             L121            test    al,al
 1439  75 07                             jne     L122


   va_start(ap, fmt);
 143b  bb ff ff ff ff                    mov     ebx,0ffffffffH
 1440  eb 3b                             jmp     L123

   n=lg_vsprintf(buf, fmt, ap);
 1442  8d 84 24 18 04 00 
       00                L122            lea     eax,+418H[esp]

   va_end (ap);
 1449  8d 9c 24 00 04 00 
       00                                lea     ebx,+400H[esp]
 1450  8b 94 24 14 04 00 
       00                                mov     edx,+414H[esp]
 1457  89 84 24 00 04 00 
       00                                mov     +400H[esp],eax
 145e  89 e0                             mov     eax,esp


   /* punt if there was an error. */
   if (n < 0)
 1460  31 c9                             xor     ecx,ecx
 1462  e8 00 00 00 00                    call    lg_vsprintf_
 1467  89 c3                             mov     ebx,eax
 1469  89 8c 24 00 04 00 
       00                                mov     +400H[esp],ecx

      return n;

   /* write this string if we're logging. */
   _mprint(buf,n);
 1470  85 c0                             test    eax,eax
 1472  7c 09                             jl      L123

   return n;
}
 1474  89 c2                             mov     edx,eax
 1476  89 e0                             mov     eax,esp
 1478  e8 00 00 00 00                    call    _mprint_


/* print s with no formating, it's just text folks, just text, nothing to be seen here */
int mprint(char *s)
 147d  89 d8             L123            mov     eax,ebx
 147f  81 c4 04 04 00 00                 add     esp,00000404H
 1485  5a                                pop     edx
 1486  59                                pop     ecx
 1487  5b                                pop     ebx
 1488  c3                                ret     
 1489  8d 40 00                          lea     eax,+0H[eax]

{
   if (!_mono_top())
 148c  53                mprint_         push    ebx
 148d  51                                push    ecx
 148e  52                                push    edx
 148f  57                                push    edi
 1490  89 c3                             mov     ebx,eax

		if (!_mono_log())
 1492  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_done_init+3d80H,00H
 1499  75 05                             jne     L124
 149b  e8 00 00 00 00                    call    mono_init_
 14a0  80 3d 00 00 00 00 
       00                L124            cmp     byte ptr _mono_mode+3d80H,00H
 14a7  0f 95 c0                          setne   al
 14aa  84 c0                             test    al,al
 14ac  75 5d                             jne     L128

	      return -1;
 14ae  83 3d 00 00 00 00 
       00                                cmp     dword ptr _mono_spc_func+3d83H,0000H
 14b5  75 40                             jne     L125
 14b7  83 3d 00 00 00 00 
       ff                                cmp     dword ptr _mono_file+3d83H,0ffffH
 14be  74 3b                             je      L126
 14c0  80 3d 00 00 00 00 
       00                                cmp     byte ptr _mono_screen+3d80H,00H
 14c7  74 2e                             je      L125
 14c9  8a 0d 00 00 00 00                 mov     cl,_mlog+0d8aH
 14cf  84 c9                             test    cl,cl
 14d1  74 24                             je      L125
 14d3  8b 15 fd ff ff ff                 mov     edx,__cur_mono_page+158bH
 14d9  c1 fa 18                          sar     edx,18H
 14dc  8d 04 95 00 00 00 
       00                                lea     eax,+0H[edx*4]
 14e3  29 d0                             sub     eax,edx
 14e5  8b 84 c2 ff ff ff 
       ff                                mov     eax,__mono_screens+0c284H[edx+eax*8]
 14ec  31 d2                             xor     edx,edx
 14ee  c1 f8 18                          sar     eax,18H
 14f1  88 ca                             mov     dl,cl
 14f3  85 c2                             test    edx,eax
 14f5  74 04                             je      L126
 14f7  b0 01             L125            mov     al,01H
 14f9  eb 02                             jmp     L127
 14fb  30 c0             L126            xor     al,al
 14fd  84 c0             L127            test    al,al
 14ff  75 0a                             jne     L128

   return _mprint(s,strlen(s));
 1501  b8 ff ff ff ff                    mov     eax,0ffffffffH
 1506  5f                                pop     edi
 1507  5a                                pop     edx
 1508  59                                pop     ecx
 1509  5b                                pop     ebx
 150a  c3                                ret     

}
 150b  89 df             L128            mov     edi,ebx
 150d  29 c9                             sub     ecx,ecx
 150f  49                                dec     ecx
 1510  31 c0                             xor     eax,eax
 1512  f2 ae                             repne   scasb 
 1514  f7 d1                             not     ecx
 1516  49                                dec     ecx
 1517  89 ca                             mov     edx,ecx
 1519  89 d8                             mov     eax,ebx
 151b  e8 00 00 00 00                    call    _mprint_


/* dump screen to fn, erase if set */
bool mono_dump(char *fn, bool erase_it, bool readable)
 1520  5f                                pop     edi
 1521  5a                                pop     edx
 1522  59                                pop     ecx
 1523  5b                                pop     ebx
 1524  c3                                ret     
 1525  8d 40 00                          lea     eax,+0H[eax]

{
	int open_flags=O_WRONLY|O_CREAT|O_BINARY, mono_hnd;
 1528  51                mono_dump_      push    ecx
 1529  56                                push    esi
 152a  57                                push    edi
 152b  83 ec 58                          sub     esp,0058H
 152e  89 c1                             mov     ecx,eax
 1530  88 54 24 54                       mov     +54H[esp],dl

	int x,y,write_wid=MONO_WID;
	uchar *cur_char;
	char on_line[MONO_WID+2];

	if (!_mono_top()) return FALSE;
 1534  ba 21 02 00 00                    mov     edx,00000221H

 1539  8a 25 00 00 00 00                 mov     ah,_mono_done_init+258aH

	if (erase_it) open_flags|=O_TRUNC; else open_flags|=O_APPEND;
	if (fn==NULL) fn=MONO_DUMP;
   if ((mono_hnd = open (fn, open_flags, S_IWRITE))==-1) return FALSE;
   if (readable) { on_line[MONO_WID]=0x0D; on_line[MONO_WID+1]=0x0A; write_wid+=2; }
 153f  be 50 00 00 00                    mov     esi,00000050H
 1544  84 e4                             test    ah,ah
 1546  75 05                             jne     L129
 1548  e8 00 00 00 00                    call    mono_init_
 154d  80 3d 00 00 00 00 
       00                L129            cmp     byte ptr _mono_mode+3d80H,00H
 1554  0f 95 c0                          setne   al

	for (y=0; y<MONO_HGT; y++)
 1557  84 c0                             test    al,al
 1559  0f 84 8e 00 00 00                 je      L137

	{
 155f  80 7c 24 54 00                    cmp     byte ptr +54H[esp],00H
 1564  74 05                             je      L130
 1566  80 ca 40                          or      dl,40H
 1569  eb 03                             jmp     L131
 156b  80 ca 10          L130            or      dl,10H

		cur_char=(uchar *)page_addr+MONO_ROW*y;
 156e  85 c9             L131            test    ecx,ecx
 1570  75 05                             jne     L132
 1572  b9 14 00 00 00                    mov     ecx,offset L142

		for (x=0; x<MONO_WID; x++)
 1577  68 80 00 00 00    L132            push    00000080H
 157c  52                                push    edx
 157d  51                                push    ecx
 157e  e8 00 00 00 00                    call    open_
 1583  83 c4 0c                          add     esp,000cH
 1586  89 c7                             mov     edi,eax
 1588  83 f8 ff                          cmp     eax,0ffffH
 158b  75 04                             jne     L133
 158d  30 c0                             xor     al,al
 158f  eb 5c                             jmp     L137

			on_line[x]=*(cur_char+2*x);
 1591  84 db             L133            test    bl,bl
 1593  74 0f                             je      L134
 1595  b4 0d                             mov     ah,0dH
 1597  b2 0a                             mov     dl,0aH
 1599  83 c6 02                          add     esi,0002H
 159c  88 64 24 50                       mov     +50H[esp],ah
 15a0  88 54 24 51                       mov     +51H[esp],dl

		write(mono_hnd,on_line,write_wid);
	}
 15a4  31 c9             L134            xor     ecx,ecx

	close(mono_hnd);
 15a6  8b 15 fd ff ff ff L135            mov     edx,__cur_mono_page+158bH
 15ac  c1 fa 18                          sar     edx,18H
 15af  6b d2 19                          imul    edx,19H
 15b2  8b 92 10 00 00 00                 mov     edx,__mono_screens+928bH[edx]

	return TRUE;
 15b8  31 c0                             xor     eax,eax
 15ba  01 ca                             add     edx,ecx
 15bc  40                L136            inc     eax

}
 15bd  8a 1a                             mov     bl,[edx]
 15bf  83 c2 02                          add     edx,0002H
 15c2  88 5c 04 ff                       mov     -1H[esp+eax],bl
 15c6  83 f8 50                          cmp     eax,0050H
 15c9  7c f1                             jl      L136
 15cb  89 e2                             mov     edx,esp

ERROR: EOF encountered in source file
 15cd  89 f3                             mov     ebx,esi
 15cf  89 f8                             mov     eax,edi

ERROR: EOF encountered in source file
 15d1  81 c1 a0 00 00 00                 add     ecx,000000a0H
 15d7  e8 00 00 00 00                    call    write_
 15dc  81 f9 a0 0f 00 00                 cmp     ecx,00000fa0H
 15e2  75 c2                             jne     L135

ERROR: EOF encountered in source file
 15e4  89 f8                             mov     eax,edi
 15e6  e8 00 00 00 00                    call    close_

ERROR: EOF encountered in source file
 15eb  b0 01                             mov     al,01H

 15ed  83 c4 58          L137            add     esp,0058H
 15f0  5f                                pop     edi
 15f1  5e                                pop     esi
 15f2  59                                pop     ecx
 15f3  c3                                ret     

4 disassembly errors

------------------------------------------------------------

Segment: 'CONST' DWORD  0000001d bytes  
 0000  2d 2d 2d 2d 2d 0a 00 00 L140            - -----...
 0008  6d 70 72 69 6e 74 66 2e                 - mprintf.
 0010  6c 6f 67 00 6d 6f 6e 6f                 - log.mono
 0018  2e 64 6d 70 00                          - .dmp.

No disassembly errors

------------------------------------------------------------

Segment: '_DATA' DWORD  00000134 bytes  
 0000  00                      _mono_done_init - .
 0001  00                      _mono_screen    - .
 0002  00                      _mono_mode      - .
 0003  00                      _mono_x         - .
 0004  00                      _mono_y         - .
 0005  01                      __cur_mono_page - .
 0006  ff                      __last_mono_page - .
 0007  00                      __cur_mono_focus - .
 0008  00 00 00 00             __inited_mpages - ....
 000c  00 00 00 00             __cur_card      - ....
 0010  00 00 00 00             _def_wrap_msg   DD      DGROUP:L140
 0014  b4 03 00 00 d4 03 00 00 _srx_adr        - ........
 001c  b5 03 00 00 d5 03 00 00 _srx_data       - ........
 0024  07 00 00 00             _mono_attr      - ....
 0028  ff ff ff ff             _mono_file      - ....
 002c  00                      _mlog           - .
 002d  6d 70 72 69 6e 74 66 2e _last_lf        - mprintf.
 0035  6c 6f 67 00 00 00 00 00                 - log.....
 003d  00 00 00 00 00 00 00 00                 - ........
       --- Above line repeats 29 times --- 
 012d  00 00 00                                - ...
 0130  00 00 00 00             _mono_spc_func  - ....

No disassembly errors

------------------------------------------------------------

Segment: '_BSS' DWORD  0000012c bytes  

No disassembly errors

------------------------------------------------------------
