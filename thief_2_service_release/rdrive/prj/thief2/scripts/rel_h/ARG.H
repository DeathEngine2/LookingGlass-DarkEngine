/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: x:/prj/windex/libsrc/arg/RCS/arg.h $
 * $Revision: 1.2 $
 * $Author: DAVET $
 * $Date: 1996/01/17 18:15:13 $
 *
 * This file is part of the arg library.
 *
 * $Log: arg.h $
 * Revision 1.2  1996/01/17  18:15:13  DAVET
 * Added cplusplus stuff
 * 
 * Revision 1.1  1993/03/22  13:53:30  jak
 * Initial revision
 * 
 */

#ifndef __ARG_H
#define __ARG_H

// thang.h

// ===============================================================================
// Format string:
// keyword spec spec spec
// 
// Where spec starts necessarily with a '%' and keyword simply does not.
// 
// %d matches an int
// %f matches a float
// 
// That's it so far.
// 
// Examples:
// Arg( argc, argv, "start_pos %f %f %f", &x, &y, &z );
// Arg( argc, argv, "num_marbles", &n_marbles );
// ===============================================================================


// Returns number of matches, include
// ===============================================================================

#ifdef __cplusplus
extern "C"  {
#endif

int Arg( int argc, char *argv[], char *fmt, ... );

// Heavy.

#ifdef __cplusplus
}
#endif

#endif /* !__ARG_H */
