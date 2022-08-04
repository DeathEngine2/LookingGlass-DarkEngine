/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

#ifndef _COVERAGE_H
#define _COVERAGE_H

#ifdef COVERAGE_TEST

   extern int coverage_if(int value, char *file, int line);
   extern int coverage_while(int value, char *file, int line);
   extern int coverage_for(int value, char *file, int line);

   #define if(x)       if (coverage_if(!!(x), __FILE__, __LINE__))
   #define while(x)    while (coverage_while(!!(x), __FILE__, __LINE__))
   #define cfor(x,y,z) for ((x); coverage_for(!!(y), __FILE__, __LINE__); (z))
   #define coverage()  coverage_for(TRUE, __FILE__, __LINE__)

#else

   #define cfor(x,y,z) for ((x); (y); (z))
   #define coverage()  do ; while (0)

#endif

#endif
