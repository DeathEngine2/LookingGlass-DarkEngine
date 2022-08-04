//		3DS2COM.H	- Header for 3d Studio -> .COM file converter
//
/*
* $Header: n:/project/cmds/src/3dsconv/RCS/3ds2com.h 1.4 1994/03/04 16:57:32 rex Exp $
* $Log: 3ds2com.h $
 * Revision 1.4  1994/03/04  16:57:32  rex
 * Added flags field to run new tool instead of old
 * 
 * Revision 1.3  1993/09/23  16:34:47  rex
 * Changed comment to outName (may have path now)
 * 
 * Revision 1.2  1993/09/23  12:50:20  rex
 * Added 2 more args (intdir and intdel)
 * 
 * Revision 1.1  1993/09/22  15:39:50  rex
 * Initial revision
 * 
*/

#include <lg.h>

//	Here is the mother of all C routine converters:
//	(Returns 0 if ok, -1 if error with errBuff[] filled with error msg)

int ComFrom3ds(
	char **models,		// NULL-terminated list of ptrs to model filenames
	char **eflags,		// list of ptrs to EMUNGE flags, 1 per model
							// if NULL or any ptr NULL, uses stdFlagsE
	char **dflags,		// list of ptrs to DAT2CG flags, 1 per model
							// if NULL or any ptr NULL, uses stdFlagsD
	char *outName,		// name of output files to make (no ext, may have path)
	char *stdFlagsE,	// standard EMUNGE flags
	char *stdFlagsD,	// standard DAT2CG flags
	char *path3,		// path to .3ds files
	char *pathE,		// path to .e files
	char *pathA,		// path to .asm files
	char *intdir,		// directory to put intermediate files in
	bool intdel,		// delete intermediate files (won't del .asm's)
	char *asmName,		// name of assembler to run
	char *asmFlags,	// flags to use with assembler
	char *errBuff,		// error buffer, filled in if error (must be 128 bytes)
	ushort flags,		// CF3_XXX
	bool verbose		// run verbosely (else silent)
);

#define CF3_NEWCG	0x01		// use new cg_tool instead of dat2cg!!!
