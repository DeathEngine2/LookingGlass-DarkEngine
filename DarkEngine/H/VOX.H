#ifndef __VOX_H
#define __VOX_H

#include <2d.h>

// Voxel structure
typedef struct {
   fix pix_dist;     // space between pixels in 3d units
   fix pix_size;     // size of pixels in 3d units
   int w,h,d;     // size of voxel in source pixels
   // any pointer set to Null is not rendered
   grs_bitmap *col;  // Pointers to color maps
   grs_bitmap *ht;   // Pointers to height maps
} vxs_vox;


// Startup for the voxel system, it needs to allocate
// space for the incremental multiplication tables
// pass it the maximum pixel dimension of any of the
// voxel objects you anticipate drawing
// returns TRUE for success, FALSE if unable to allocate
bool vx_init(int max_depth);

// Close the voxel system
void vx_close();

// Initialize a voxel
// Pass it pointer to the voxel structure
// 3d distance between the pixels in the bitmaps
// 2d size of each pixel at a distance of 1 3d unit
// pointer to colormap
// pointer to height map
void vx_init_vox(vxs_vox *v,fix pix_dist,fix pix_size,int depth,grs_bitmap *col,grs_bitmap *ht);

// Render voxel object v, after calling g3_start_object
// don't forget to call g3_end_object afterwards
void vx_render(vxs_vox *v);


#endif /* !__VOX_H */


