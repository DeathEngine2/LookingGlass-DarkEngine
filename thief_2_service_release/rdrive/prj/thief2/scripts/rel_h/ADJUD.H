/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
** adjud.h
**
** The adjudimicator, for running process faster or slower than the frame rate
**
** $Header: r:/prj/lib/src/adjud/rcs/adjud.h 1.1 1995/03/02 11:32:15 dfan Exp $
** $Log: adjud.h $
 * Revision 1.1  1995/03/02  11:32:15  dfan
 * Initial revision
 * 
*/

#ifndef __ADJUD_H



// PUBLIC STUFF

// An Adjudicator function: takes no arguments and returns void.
typedef void (* AdjFunc) (void);

void AdjInit (void);
bool AdjAddFunc (AdjFunc func_ptr, long period, long force_freq);
void AdjRemoveFunc (AdjFunc func_ptr);
#define AdjUpdate(t) do {if ((t) >= gAdjNextTime) AdjUpdate_(t);} while (0)




// PRIVATE STUFF THAT IS HERE BECAUSE IT HAS TO BE

// The next time that something interesting might happen
// Don't you dare touch this
extern ulong gAdjNextTime;

void AdjUpdate_ (ulong time); // don't call this, call AdjUpdate()




#define __ADJUD_H
#endif
