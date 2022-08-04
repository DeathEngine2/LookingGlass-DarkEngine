/*
 * $Source: x:/prj/tech/libsrc/ipw/RCS/ipw.h $
 * $Revision: 1.20 $
 * $Author: PATMAC $
 * $Date: 1998/07/02 14:35:40 $
 *
 * Image Processing include file
 *
 */

#ifndef __IPW_H
#define __IPW_H

#include <stdio.h>

#include <2d.h>
#include <types.h>
#include <gfile.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IP_RGB_PAL 1
#define IP_SUB_PAL 2
#define IP_R_ABLE 1
#define IP_W_ABLE 2
#define IP_TRANS 4
#define IP_SELECT 8  // this is a cycling color, handle with care in sampling
#define IP_SELECT2 16
#define IP_SELECT3 32
#define IP_SELECT4 64
#define IP_SELECT5 128
#define IP_RGB_IMAGE 4
#define IP_PAL_IMAGE 8
#define IP_IMAGE_SET 16
#define IP_FLOAT_IMAGE 32
#define IP_NONE  3

#define IP_PLAIN  (0)
#define IP_GAUSS  (1)
#define IP_EDGE   (2)
#define IP_LINEAR (3)
#define IP_CREATURE (4)
#define IP_SQUARE (5)

#define IP_OK (1)
#define IP_BAD_ARGUMENT (-1)
#define IP_OUT_OF_MEMORY (-2)
#define IP_NULL_POINTER (-3)
#define IP_FILE_NOT_FOUND (-4)
#define IP_FORMAT_UNSUPPORTED (-5)

typedef int             errcode;
typedef unsigned long   rgb;

/* Palette structures */

extern struct _ipw {
   int      upscaletype; 
   int      upscaleorder; 
   int      upscaletravel;
   int      upscalelimit;
   int      downscaletype; 
   float    downscalelambda;
   float    screengamma;
   uchar    *gamma;  // approx for vga = 1.6 
   bool     copytrans;
   bool     fastipal;
   int      red_intensity;
   int      green_intensity;
   int      blue_intensity;
   int      red_dist;
   int      green_dist;
   int      blue_dist;
   bool     anchoredtile;
} Ipw;

typedef struct _p {
   char        name[30];
   char        path[256];
   uchar       type;    /* RGB_PAL or SUB_PAL */
   uint        numentries;
   struct _p   *pal;    /* Optional pointer to a palette if SUB_PAL */
   struct _i   *image;  /* Optional pointer to parent image */
   uchar       *ipal;   /* Optional pointer to an inverse palette */
   uchar       rsz,gsz,bsz; /* sizes in bits of rgb */
   uchar       rsh,gsh,bsh; /* right shift values for rgb for the inverse palette */
   long        rmsk,gmsk,bmsk; /* masks for rgb */
   ulong       ipalsize; /* size in bytes of optional inverse palette */
   bool        ipalvalid;  /* Valid flag for optional inverse palette */
   uchar       data[1];
   /* data area, RGB entries, permissions*/
} Palette;

/* Image structures */

typedef struct _i {
   char        name[30];
   char        path[256];
   uchar       type;    /* RGB_IMAGE or PAL_IMAGE */
   int         xres;
   int         yres;
   float       scale;   /* displaying scale, default, 1 */
   Palette     *pal;    /* bind to palette or subpalette */
   struct _is  *parent;
   int         curx,cury,nexty; /* optional tiler support */
   int         row,col;       /* optional tiler row and column */
   int         xstag,ystag;   /* x and y staggering */
   int         rtanchorst;    /* right anchor start */
   int         rtanchorend;   /* right anchor end */
   int         botanchorst;   /* bottom anchor start */
   int         botanchorend;  /* bottom anchor end */ 
   bool        borders;       /* TRUE or FALSE */
   uchar       borderpal;     /* border palette value */
   uchar       anchorpal;
   rgb         bordercol;     /* border col */
   rgb         anchorcol;     /* anchored color */
   int         tilespace;     /* space between tiles */
   uchar       data[4];          /* This is Tim suspecting Watcom of word-aligning if we use data[1] */
   /* data, implicit, RGB entries or pal references */
}  Image;   

typedef struct _is {
   char        name[30];
   char        path[256];
   uchar       type;    /* IMAGE_SET */
   int         maxentries;
   int         numentries;
   Image       *child[1];
   /* data, implicit, list of images */
} ImageSet;

/* palette operations */

errcode create_pal(Palette **pal,uchar type,int numentries,uchar defaults);
errcode delete_pal(Palette *pal);

Palette *base_pal(Palette *pal);
/* return the underlying palette of a palette or subpalette */

rgb   bind_rgb(uchar r,uchar g,uchar b);
void  split_rgb(rgb col,uchar *r,uchar *g,uchar *b);

ulong dist_rgb(rgb col1,rgb col2);     // distance squared between two colors 
uchar get_intensity(rgb col);          // get the intensity of it (255-0)

rgb   get_palrgb(Palette *pal,int n);                 // get rgb from pal or subpal 
void  put_palrgb(Palette *pal,int n,rgb color);       // set pal or closest fit subpal to pal 
errcode  put_subpal(Palette *sub,int n,uchar entry);  // set subpalette entry n equal to pal 
int get_subpal(Palette *sub,int n);                   // get the nth entry of subpalette sub 

uchar get_palflag(Palette *pal,int n);
void  put_palflag(Palette *pal,int n,uchar flag);

// return the closest index from the palette 
int   closest_fit(Palette *pal,rgb col);  

// return the closest rgb from the palette whose flag matches flag
int   closest_flag_fit(Palette *pal,uchar flag,rgb col); 

// create an inverse palette of bits per color r,g,b
errcode  create_ipal(Palette *pal,uchar r,uchar g,uchar b); 

// update an inverse palette
errcode  update_ipal(Palette *pal);                   

// delete ipal if exists 
void     delete_ipal(Palette *pal);                   

// Image operations
errcode  create_image(Image **im,uchar type,int xres,int yres,uchar defaults);
errcode  delete_image(Image *im);
errcode  clear_image(Image *im);

rgb      get_rgb(Image *im,uint x,uint y);
int      get_pal(Image *im,uint x,uint y);
void     put_rgb(Image *im,uint x,uint y,rgb col);
void     put_pal(Image *im,uint x,uint y,uchar pal);
uchar    get_flag(Image *im,uint x,uint y);
void     put_flag(Image *im,uint x,uint y,uchar flag);

void     transfer_image(int w,int h,Image *from, int xf,int yf,Image *to,int xt,int yt);
// transfer a region of size wxh from from(xf,yf) to to(xt,yt) 
// if Ipw.copytrans == 0, don't copy transparent pixels              
// cut and paste and the tiler reader uses this 

errcode  upscale(Image *from,Image *to);
errcode  downscale(Image *from,Image *to);
errcode  copy_image(Image *from,Image *to);

errcode  assign(Palette *pal,Image *im);
// Write all the writeable palette entries with
// the best fit to the vector image im.

// Image tiler operations 
errcode  reset_tile(Image *im);              // reset tiler pointer 
bool     write_tile(Image *im,Image *tile);  // stick the tile on the image               
void     cr_tile(Image *im);                 // carriage return im 
Image *  read_tile(Image *im);               // returns the image read or NULL if empty 

/* ImageSet operations */
errcode create_imageset(ImageSet **im,int maxentries);
errcode delete_imageset(ImageSet *im);

errcode add_imageset(ImageSet *imset,Image *im);
errcode prune_imageset(ImageSet *imset,Image *im);

int   find_imageset(ImageSet *imset,Image *im); // return -1 if im not in imageset 
errcode  insert_imageset(ImageSet *imset,Image *im,int n);


/* Dispatchers for format routines, based on pathname extension */
errcode read_pal(char *pathname,Palette **pal);
errcode write_pal(char *pathname,Palette *pal);

errcode read_image(char *pathname,Image **im);
errcode write_image(char *pathname,Image *im);

/* Format routines for images */

errcode  read_nlbm(char *pathname,Image **im);
errcode  write_nlbm(char *pathname,Image *im,char c);

errcode  read_pcx(char *pathname,Image **im);
errcode  write_pcx(char *pathname,Image *im);

errcode  read_gif(char *pathname,Image **im);
errcode  write_gif(char *pathname,Image *im);

errcode  read_tga(char *pathname,Image **im);
errcode  write_tga(char *pathname,Image *im);

// Reads a piece of width and height into a destination
// Assumes you know what you are doing, ie, have clipped
// If *dst is NULL, creates and stuffs file
// if w or h are negative, makes it the size of the image on disk
errcode read_tga_piece(Image **dst,int dx,int dy,int w,int h,char *pathname,int srcx,int srcy);


errcode  read_cel(char *pathname,Image **im);

errcode  read_tiff(char *pathname,Image **im);

errcode read_byt_pal_im(char *pathname,Image **im,int xres,int yres);
errcode read_byt_rgb_im(char *pathname,Image **im,int xres,int yres);

errcode write_bytim(char *pathname,Image *im);
errcode write_fbytim(FILE *fp,Image *im);

/* Format routines for palettes */

// 8 bit binary stream
errcode read_bytpal(char *pathname,Palette **pal);
errcode write_bytpal(char *pathname,Palette *pal);

// 6 bit pal output
errcode read_vgapal(char *pathname,Palette **pal);
errcode write_vgapal(char *pathname,Palette *pal);

// Image processing format
errcode read_ippal(char *pathname,Palette **pal);
errcode write_ippal(char *pathname,Palette *pal);

/* graphics routines */
void install_palette(Palette *pal);
void render_image(Image *im,uint x,uint y);

/* 2d interface code */
void        bm_to_image(grs_bitmap *b,Image **a);
grs_bitmap *image_to_bm(Image *a);
void        image_to_canvas(grs_canvas *c,Image *a);

// Converts as best it can to specified type.
// Uses pal if specified
// Types can be BMT_FLAT8, FLAT16, FLAT24
// If flat 8, uses pal, if pal is NULL, assumes same pal
grs_bitmap *ipw_image2bm_type(Image *a,uint type,Palette *pal);

// Converts rgb palette to ipw pal
// num is number of rgb entries
// Make defaults like creating a pal
Palette *ipw_pal2palette(uchar *base,int num,uchar defaults);


/* return the error string */
char *ipw_err_string(errcode err);

// Set a filter response and filter and downsample
// an image
void ipw_filter_set(float *response,int size);
void ipw_filter_image(Image *dst,Image *src);

 
/* Image processing */
// decorrelate an image from source to dest
// If src and dest are same size it has the exact same
// rgb distribution, otherwise, it's just an approximation
errcode ip_decor(Image *src,Image *dst);

/*

pickminmax
pickbubble
pickkmeans
*/

// Added routines for gfile style compatibility


// --------------------------------------------------------
//
// IpwGetPal() gets partial pallette from a gfile.

void IpwGetPal(Image *pim, PallInfo *ppall);


// -------------------------------------------------------
//
// IpwGetImage() gets image from a graphics file.
//
//    pim   = ptr to image
//    parea = ptr to area to extract
//    pbits = buffer to extract into (must be at least width * height bytes)
//    type = type of buffer, ie, FLAT8 or FLAT16
// automatically converts 24 bit to 16 and 15 bit

void IpwGetImage(Image *pim, Rect *parea, uchar *pbits,uchar type);


// --------------------------------------------------------
//
// IpwFindImage() searches for next image against a background.
// It looks for the upper-left corner of a rectangle set to
// the border color, and assumes an image is inside the rectangle.
//
//    pim     = ptr to image
//    currLoc = point to begin search at
//    parea   = area found (filled in)
//    bordCol = border color

bool IpwFindImage(Image *pim, Point currLoc, Rect *parea);


// --------------------------------------------------------
//
// IpwFindAnchorRect() searches for an anchor rectangle in
// the current image's border.  The current image must be bordered,
// and the bottom and right border edges are searched for strips
// not in the border color.
//
//    pbm     = ptr to bitmap
//    parea   = ptr to image area
//    bordCol = border color
//    panrect = ptr to anchor rect (filled in by this routine unless
//                not present)
//
// Returns:
//
//    0 if no anchor rect
//    1 if anchor rect (can be just point)
//    -1 if error (for instance, bottom side has one but not right)

int IpwFindAnchorRect(Image *pim, Rect *parea, Rect *panrect);


// -------------------------------------------------------
//    ACCESS ROUTINES
// -------------------------------------------------------
//
// IpwRead() grabs the image out of a graphics file.
//
//    ppim     = ptr to ptr to image
//    filename = ptr to filename
//    pdp      = ptr to datapath
//
// Returns: TRUE if successful, FALSE if problem

bool IpwRead(Image **ppIm, char *filename, Datapath *pdp);


#ifdef __cplusplus
}
#endif
#endif
