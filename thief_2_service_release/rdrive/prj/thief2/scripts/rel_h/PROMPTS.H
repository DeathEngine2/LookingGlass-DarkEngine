/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/prompts.h 1.1 1997/12/02 23:15:01 dc Exp $
// basic prompts for asking for data from the user

#ifndef __PROMPTS_H
#define __PROMPTS_H

// basic "get this value for me" prompts - all modal
EXTERN BOOL   prompt_bool(char *def);
EXTERN int    prompt_int(char *def);
EXTERN double prompt_double(char *def);
EXTERN char  *prompt_string(char *def, char *buf);

// for prompt strings
#define PROMPT_STR_LEN 128

#endif  // __PROMPTS_H
