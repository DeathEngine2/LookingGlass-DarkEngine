/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: r:/prj/lib/src/gifd/rcs/gifd.h $
 * $Revision: 1.1 $
 * $Author: jaemz $
 * $Date: 1993/06/15 11:57:30 $
 *
 * Gif Dumping library include file
 *
 * $Log: gifd.h $
 * Revision 1.1  1993/06/15  11:57:30  jaemz
 * Initial revision
 * 
 */

#ifndef __GIFD_H
#define __GIFD_H

/* Dumps the current screen to the file, pointed to by the file
 * pointer fp.  You need to give a temporary buffer *buf,
 * pointing to at least 26k of memory.   Allocate it as
 * you will.
*/
int gd_dump_screen(int fp,unsigned char *buf);

/* Finds the free file in a sequence like
 * "<prefix>000.gif", tries to open it,
 * and returns you a pointer to it.
 * maximum prefix is 5 letters long.
 * numbers the files in oct.
 * Returns -1 if unable to open
*/
int gd_find_free_file(char *prefix);

#endif
