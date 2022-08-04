/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
** $Header: r:/prj/lib/src/range/rcs/range.h 1.1 1993/02/16 14:44:20 dfan Exp $
** $Log: range.h $
 * Revision 1.1  1993/02/16  14:44:20  dfan
 * Initial revision
 * 
*/

extern char range_str[200];

void RangeInit (void);
void RangeAdd (int n);
void RangeFlush (void);
