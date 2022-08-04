/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/****************************************************************************
*
*                         The Universal VESA VBE
*
*                   Copyright (C) 1994 SciTech Software.
*                           All rights reserved.
*
* Filename:     $RCSfile: uvbelib.h $
* Version:      $Revision: 1.3 $
*
* Language:     ANSI C
* Environment:  IBM PC (MS DOS) real and protected mode.
*
* Description:  Header file for the UVBELib(tm) functions.
*
* $Id: uvbelib.h 1.3 1995/05/04 19:20:58 ept Exp $
*
****************************************************************************/

#ifndef __UVBELIB_H
#define __UVBELIB_H

/*-------------------------- Function Prototypes --------------------------*/

#ifdef  __cplusplus
extern "C" {            			/* Use "C" linkage when in C++ mode */
#endif

/* Routines to install the UVBELib VBE 2.0 device support routines */

bool  _cdecl UV_install(char *driverDir,int ignoreVBE,int noBanner,int forceTextMode);
void  _cdecl UV_exit(void);
void  _cdecl UV_getDriverPath(char *argv0,char *buf);

#ifdef  __cplusplus
}                       			/* End of "C" linkage for C++   	*/
#endif

#endif  /* __UVBELIB_H */
