// lgsprntf.h -- no-floats baby sprintf

// Tim Stellmach
// LookingGlass Technologies 1993

/*
* $Header: r:/prj/lib/src/lg/rcs/lgsprntf.h 1.4 1994/02/27 02:25:50 tjs Exp $
* $Log: lgsprntf.h $
 * Revision 1.4  1994/02/27  02:25:50  tjs
 * Changed format to const
 * 
 * Revision 1.3  1993/11/04  09:44:35  tjs
 * Added this very header.
 * 
 * 
 *
 *
 *
*/

#include <types.h>
#include <stdarg.h>

int lg_sprintf(char *buf, const char *format, ...);
int lg_vsprintf(char *buf, const char *format, va_list arglist);
void lg_sprintf_install_stringfunc(char *(*func)(ulong strnum));
