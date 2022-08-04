/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: x:/prj/tech/libsrc/ser/RCS/serial.h $
 * $Revision: 1.12 $
 * $Author: TOML $
 * $Date: 1996/10/23 09:40:27 $
 *
 * $Log: serial.h $
 * Revision 1.12  1996/10/23  09:40:27  TOML
 * *** empty log message ***
 * 
 * Revision 1.11  1996/02/20  14:15:56  DAVET
 * Added cplusplus stuff
 *
 * Revision 1.10  1995/08/04  12:57:04  jlehrer
 * fixed peek
 *
 * Revision 1.9  1995/07/31  17:08:54  jlehrer
 * Changed both queues back to 256 bytes
 *
 * Revision 1.8  1995/07/24  13:44:23  jlehrer
 * Add functions to clear read and write queues
 *
 * Revision 1.7  1995/07/21  17:34:12  jlehrer
 * Varying send\rcv queue size
 * overflow flag added
 * fixed lost interrupt bug
 *
 *
 * Revision 1.6  1994/11/21  22:19:51  jaemz
 * New system
 *
 * Revision 1.5  1994/10/25  14:34:29  jaemz
 * Added header and ifdef stuff
 *
 *
*/

#ifndef __SERIAL_H
#define __SERIAL_H

#ifndef _WIN32
#ifdef __cplusplus
extern "C"  {
#endif  // cplusplus


#define SPD_WRITE_QUEUE_SIZE 256
#define SPD_WRITE_QUEUE_MASK (SPD_WRITE_QUEUE_SIZE-1)

#define SPD_READ_QUEUE_SIZE 256
#define SPD_READ_QUEUE_MASK (SPD_READ_QUEUE_SIZE-1)

#define SPP_NONE  0
#define SPP_ODD   1
#define SPP_EVEN  3
#define SPP_MARK  5
#define SPP_SPACE 7

// indicates we've opened it
#define SPP_OPEN  1
// indicates irq is enabled
#define SPP_USED  2

typedef struct {
   bool  open;       // whether or not its open
   uchar pic_mask;   // old pic_mask before opening, used for closing
   // basic info
   uchar irq;
   ushort adr;
   //old values
   uchar ier,lcr,mcr;
   uchar lsr,msr,scr;
   void far *old_prot_handler;
   ulong    old_real_handler;
} sps_comdata;

typedef struct {
   int rover;
   int rhead;
   int rtail;
   int whead;
   int wtail;
   uchar rbuf[SPD_READ_QUEUE_SIZE];
   uchar wbuf[SPD_WRITE_QUEUE_SIZE];
} sps_comport;

// two ports
extern sps_comport *spd_port;

int sp_init(void);
int sp_close(void);
void sp_open_port(int port,int baud,int data,int parity,int stop);
void sp_close_port(int port);
int sp_putchar(int c,int port);
int sp_getchar(int port);
uchar sp_poll_port(int port);
int sp_write(uchar *c,int len,int port);
int sp_read(uchar *c,int len,int port);
bool sp_write_done(int port);
int sp_write_avail(int port);
int sp_read_avail(int port);
uchar sp_peek_char(int c, int port);
int sp_peek(uchar *c, int len, int offset, int port);
int sp_get_overflow(int port);
void sp_reset_overflow(int port);
int sp_is_write_empty(int port);
void sp_clear_read(int port);
void sp_clear_write(int port);

// secret mono stuff
extern int spd_mono_port;
void sp_mono_scan(char *s,int len);

#define mono_serial_support(x) mono_spc_func=sp_mono_scan;spd_mono_port=x


#ifdef __cplusplus
}
#endif  // cplusplus

#endif
#endif /* __SERIAL_H */
