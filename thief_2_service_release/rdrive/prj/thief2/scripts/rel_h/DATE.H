/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/date/RCS/date.h 1.2 1998/10/09 14:45:27 jaemz Exp $

#ifndef __DATE_H
#define __DATE_H

#pragma once

// This little library is used to convert game time seconds into and
// out of standard date representation.  Keeping your game time as doubles
// gives you millisec accuracy out to the year 142,808 A.D.  Everyone
// using it will experience the year 142,808 bug.

// This structure represents an exact date and time,
// in standard format.
typedef struct {
   double rem;  // remainder seconds after sec [0..1)
   int sec;     // seconds after the minute
   int min;     // minutes after the hour
   int hour;    // hours after midnight
   
   int day;     // day of the month [1-31]
   int month;   // month after january [0-11]
   int year;    // year after 0 ad, gregorian calender

   // These are set by DateFromSec, but not used by DateToSec
   int weekday; // day of week after sunday [0-6]
   int yearday; // days past jan 1 of the year [0-365]
} sDate;

// Takes a date and converts it to seconds past
// midnight Jan 1, 0 A.D.
EXTERN double DateToSec(sDate *d);

// Stuffs an sDate constructed from seconds past midnight
// Jan 1, 0 A.D.
EXTERN void DateFromSec(sDate *d,double sec);

// Converts seconds to days:hours:min:sec:rem, ignoring month and
// year.  Basically treats the input as a delta to let you get
// a nicely formatted thing.  So for instance, you can say: Blank
// played for 9 days, 3 hours, 2 minutes, and 1 second
EXTERN void DateElapsedTime(sDate *d,double sec);

// Stuffs the hours, minutes, seconds, and rem of the sDate structure
// Good for converting game time to something you can show on a digital
// clock, and the like.
EXTERN void DateHourMinSec(sDate *d,double sec);

#endif





