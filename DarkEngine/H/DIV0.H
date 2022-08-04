/*
 * $Source: r:/prj/lib/src/div0/rcs/div0.h $
 * $Revision: 1.2 $
 * $Author: matt $
 * $Date: 1993/06/03 16:29:36 $
 *
 * C declarations for divide-by-zero handler.
 *
 * $Log: div0.h $
 * Revision 1.2  1993/06/03  16:29:36  matt
 * Changed prototype for dz_init() which now takes the mode, and added 
 * constants for error codes.
 * 
 * Revision 1.1  1993/05/28  15:48:09  kaboom
 * Initial revision
 * 
 */

extern int dz_init (int mode);
extern int dz_close (void);
extern int dz_set_mode (int mode);
extern long dzd_count;

enum {
   DZM_ERROR,
   DZM_HANDLE,
   DZM_MODES
};

enum {
   DZE_NO_ERROR,
   DZE_BAD_SET,	//unable to set handler address
   DZE_BAD_MODE
};
