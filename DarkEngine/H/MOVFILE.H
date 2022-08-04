//		MOVFILE.H		Movie file access
//		Rex E. Bradford

/*
 * $Source: x:/prj/tech/libsrc/afile/RCS/movfile.h $
 * $Revision: 1.1 $
 * $Author: rex $
 * $Date: 1994/08/25 10:56:18 $
 * $Log: movfile.h $
 * Revision 1.1  1994/08/25  10:56:18  rex
 * Initial revision
 * 
*/

#ifndef __MOVFILE_H
#define __MOVFILE_H

#ifndef __DATAPATH_H
#include <datapath.h>
#endif
#ifndef __MOVIE_H
#include <movie.h>
#endif

typedef struct {
	FILE *fp;
	MovieHeader *phdr;
	MovieChunk *pchunks;
	MovieChunk *pCurrChunk;
} MovieFile;

//	Reading from movie file

bool MovieFileOpenRead(MovieFile *pmf, Datapath *pdp, char *filename);
long MovieFileReadChunk(MovieFile *pmf, MovieChunk *pmc, uchar *buff,
	long buffLen);
void MovieFileCloseRead(MovieFile *pmf);

//	Writing to movie file

bool MovieFileOpenWrite(MovieFile *pmf, char *filename, int numEstChunks);
void MovieFileSetVideo(MovieFile *pmf, int numBits, int frameWidth,
	int frameHeight, fix frameRate);
void MovieFileSetPalette(MovieFile *pmf, uchar *pal);
void MovieFileSetAudio(MovieFile *pmf, int numChans, int sampSize, fix rate);
bool MovieFileAddChunk(MovieFile *pmf, int chunkType, int chunkFlags,
	long chunkTime, uchar *buff, long len);
void MovieFileEndWrite(MovieFile *pmf, long time);

#endif


