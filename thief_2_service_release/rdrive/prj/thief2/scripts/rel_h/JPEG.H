/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * JPEG: This file contains all of the definitions needed externally for the jpeg
 *       implementation that we have implemented.  This is the file which is
 *       publically available.
 *
 * $Header: x:/prj/tech/libsrc/jpeglg/RCS/jpeg.h 1.9 1996/01/23 17:56:55 ept Exp $
 */

#ifndef __JPEG_H
#define __JPEG_H

#ifdef _MSC_VER
#include "basetype.h"
#else
   #if __WATCOMC__ > 1000
      #pragma pack(push,4)
   #else
      #pragma pack(4)
   #endif
#include <basetype.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

//
// Notes on the JPEG ISO DIS 10918-1
//
// Annex F: Describes the overall process for the following types of encoding:
//   1) Baseline sequential
//   2) Extended sequential, Huffman coding, 8-bit sample precision
//   3) Extended sequential, Arithmetic coding, 8-bit sample precision
//   4) Same for 12-bit sample precision
// F.1 describes encoding
//   F.1.1 describes general sequential DCT-based encoding processes
//   F.1.2 describes the baseline Huffman encoding procedures
//   F.1.3 describes the extended sequential encoding process for Huffman encoding
//   F.1.4 describes the sequential DCT encoding process with arithmetic coding
//   F.1.5 describes sequential DCT encoding with Huffman tables with 12 bit precision
//   F.1.6 describes sequential DCT encoding with arithmetic coding with 12 bit precision
// F.2 describes decoding
//
// Annex K: Describes how to generate the tables needed (from symbol lists) for
//          Huffman encoding.  Also provides "standard" Huffman tables.  Gives
//          "standard" table for the Arithmetic coding too.
//
// Annex C: Describes how to generate other Huffman lists from the data and
//          Huffman tables as given in Annex K.  These are used by the processes
//          described in Annex F.
//
// Annex D: Describes some of the stuff for Arithmetic coding.
//

//
// JCoef:
//
// This is the data type in each of the streams.  Generally this is 8
// bits, but in the future one could imagine it being some other base
// size.  But really one can imagine it being only 16 bits, not anything
// larger.  Also, the max val could be smaller than the arithmetic max of
// the type, so be certain to define MAX and HALF appropriately.
//

typedef uInt8 JCoef;
#define JCOEF_MAX  256
#define JCOEF_HALF (JCOEF_MAX >> 1)

// Shift values are for use in generating the rgb stream from the
// YCbCr streams.  We get rid of multiplication by using tables and
// these shifts.  We give ourselves JPEG_SHIFT number of fraction bits.

#define JPEG_SHIFT 20
#define JPEG_RIGHT_SHIFT(x) ((x) >> JPEG_SHIFT)
#define JPEG_LEFT_SHIFT(x)  ((x) << JPEG_SHIFT)

// The type needed for the blocks needs to be larger than the
// type for the coefficients since we manipulate them and make
// them signed.  A short would be sufficient, but on this processor
// full 32 bit quantities are faster than 16 bit quantities in
// manipulation.

typedef sInt32 BlockCoef;

//
// BLOCK_SIZE:
//
// The size of the basic JPEG block.  It is this block size to which the
// transformation is applied and the quantization then also applied.  So
// everything will depend on the size of this parameter.  We make some
// shorter versions of the name, but all shall depend on BLOCK_SIZE.  Make
// sure therefore to update the BLOCK_SIZE_LOG if BLOCK_SIZE is itself changed.
//

#define BLOCK_SIZE 8
#define BS BLOCK_SIZE

#define BLOCK_SIZE_2 (BS*BS)
#define BS2 BLOCK_SIZE_2

#define BLOCK_SIZE_LOG 3
#define BSL BLOCK_SIZE_LOG

//
// BlockArr:
//
// This is the basic block type that we deal with throughout the whole
// of the procedure.
//

typedef BlockCoef BlockArr[BLOCK_SIZE_2];

//
// MEM_CHUNK_SIZE:
//
// This is the size of the chunk we allocate each time we decide
// the encoder needs to store more information.
//

#define MEM_CHUNK_SIZE (256*1024)          // 64K is basic chunk size

//
// QuantTable:
//
// Simply an enum to keep track of the various quantization tables which
// have been defined.
//

typedef enum {
   IdentTable,
   LuminanceTable,
   ChrominanceTable,
   LuminanceTable2,
   ChrominanceTable2,
   LuminanceTable3,
   ChrominanceTable3,
   NumQuantTables
} QuantTable;

//
// CompressionType:
//
// Need something to indicate the compression method we are supposed to use
// for the block stream which we generate.  The types huffmanMin and
// huffmanFast differ in whether they store or need to recompute the decoding
// tables needed from the basic huffman table data that always is needed.
//

typedef enum {
   huffmanMin,
   huffmanFast,
   arithmetic
} CompressionType;

//
// HuffData:
//
// Structure that contains the huffman coding information needed, i.e. that
// needs to be saved with the compressed image to be able to reconstruct the
// the huffman codes and regenerate the image.
// NOTE: the bits arrays contain counts for bit lengths 1 to 16, not 0 to 15
// and therefore the natural index needs to shift, or the pointer to the
// array needs to be shifted before accessing.

typedef struct _HuffData {
   int tableSize;
   uInt8 bitSizes[16];
   uInt8 huffVals[16];     // but can be longer if tableSize indicates, up to 256
} HuffData;

//
// HuffTables:
//
// This contains the code tables that are used both by encoding and by decoding.
// The tables are only the length that they need to be, i.e. only as long as the
// the number of code words that are generated.  These tables are generated
// directly from HuffData, so in principal we need only store the HuffData, but
// then during decode we would need to generate these tables, so as they are short,
// we will simply store these instead.  The other tables are short tables also
// needed by the decode procedure.  But in any case we need to keep the huffVal
// data too.  So I don't know...
//
// For the time being we just have all of the tables included.
//

typedef struct _HuffTables {
   int    tableSize;
   uWord* huffCodes;
   uInt8* huffSizes;
   uWord  minCode[16];
   uWord  maxCode[16];
   uInt8  valInd[16];
} HuffTables;

//
// HuffInfo:
//
// Structure which contains the extra information needed in order to
// decode the data when Huffman tables are used.  There are two tables,
// one for the necessary huffman tables and the other in case we want
// to save the precomputed decoding tables.
//

typedef struct _HuffInfo1 {
   HuffData* huffDataDC;      // we combine the DC coefs from the 3 streams, using one table
   HuffData* huffDataY;       // this is the huffdata needed to reconstruct the Y stream AC coefs
   HuffData* huffDataCb;      // this is the huffdata needed to reconstruct the Cb stream AC coefs
   HuffData* huffDataCr;      // this is the huffdata needed to reconstruct the Cr stream AC coefs
} HuffInfo1;

typedef struct _HuffInfo2 {
   HuffTables* huffTablesDC;  // tables for the DC coefficients
   HuffTables* huffTablesY;   // tables for the Y AC coefficients
   HuffTables* huffTablesCb;  // tables for the Y Cb coefficients
   HuffTables* huffTablesCr;  // tables for the Y Cr coefficients
} HuffInfo2;

//
// JPEGStream:
//
// This is the structure which contains all of the data necessary to
// produce an output file which can subsequently be read in and decoded.
// The w,h values give the size of the image, the quantization tables
// indicate how each of the three components are quantized.  There is
// also an indication of the entropy encoding method.  If there is extra
// data needed for a particular type of encoder, it is assumed to follow
// immediately the data in this structure.  Therefore there is also a 
// length field which indicates the total length of the JPEGStream
// structure with any extra data that may be included.
// Finally we have all six byte streams which are the compressed data
// for the image.
//

typedef struct _JPEGStream {
   CompressionType cType;  // store the compression type
   int tableSize;          // size of this structure (with possible extra data)
   int w;
   int h;                  // size of the image
   int qFact;              // the quality factor for the quant tables
   QuantTable qTableY;     // quantization table to use for Y
   QuantTable qTableCb;    // quantization table to use for Cb
   QuantTable qTableCr;    // quantization table to use for Cr
   uByte* compStreamYDC;   // the encoded DC stream for the Y component
   int    lengthYDC;       // length of the encoded Y DC stream
   uByte* compStreamYAC;   // the encoded AC stream for the Y component
   int    lengthYAC;       // length of the encoded Y AC stream
   uByte* compStreamCbDC;  // the encoded DC stream for the Cb component
   int    lengthCbDC;      // length of the encoded Cb DC stream
   uByte* compStreamCbAC;  // the encoded AC stream for the Cb component
   int    lengthCbAC;      // length of the encoded Cb AC stream
   uByte* compStreamCrDC;  // the encoded DC stream for the Cr component
   int    lengthCrDC;      // length of the encoded Cr DC stream
   uByte* compStreamCrAC;  // the encoded AC stream for the Cr component
   int    lengthCrAC;      // length of the encoded Cr AC stream
} JPEGStream;

//
// Prototypes:
//
// Finally we need to have the prototypes for the various things that are
// going to be used.
//

JPEGStream* JPEGEncode(
   int w,int h,int stride,
   CompressionType cType,
   int quality,
   QuantTable qTableY,
   QuantTable qTableCb,
   QuantTable qTableCr,
   uByte* srcData,
   uByte* pal
);
uByte* JPEGDecode(JPEGStream* jpegSrc);
void JPEGFreeData(JPEGStream* jpegSrc);

#ifdef __cplusplus
};
#endif

#endif // __JPEG_H

