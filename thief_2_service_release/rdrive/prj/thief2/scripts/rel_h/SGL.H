/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

 /******************************************************************************
 * Name : sgl.h
 * Title : Prototypes for SGL library calls
 * Author : VideoLogic Limited
 * Created : 18/04/1995
 *
 * Copyright : 1995 by VideoLogic Limited. All rights reserved.
 * : No part of this software, either material or conceptual 
 * : may be copied or distributed, transmitted, transcribed,
 * : stored in a retrieval system or translated into any 
 * : human or computer language in any form by any means,
 * : electronic, mechanical, manual or other-wise, or 
 * : disclosed to third parties without the express written
 * : permission of VideoLogic Limited, Unit 8, HomePark
 * : Industrial Estate, King's Langley, Hertfordshire,
 * : WD4 8LZ, U.K.
 *
 * Description : Prototypes for SGL library calls
 * Full descpitions of the following SGL functions can
 * be found in the document trdd025a
 *
 * Platform : ANSI compatible
 *
 * (internal only version $Revision: 1.7 $ )
 *
 *****************************************************************************/
#ifndef __SGL_H__
#define __SGL_H__


/*
// On windows, define the calling convention
*/
#ifdef WIN32
#define CALL_CONV __cdecl
#else
#define CALL_CONV
#endif


/*
// If being compiled in C++, inform it that SGL is C
*/
#ifdef __cplusplus
extern "C" {
#endif 


/*
// Byte structure packing for this file
*/
#pragma pack(1)


#define SGL_HEADER_VERSION  "1.15"


#define SGL_MAX_PATH		256

/* Maximum number of planes for a single convex object */
#define SGL_MAX_PLANES 		100 

/* Max limits for polygon meshes */

#define SGL_MAX_VERTS 		10000
#define SGL_MAX_FACES 		10000
#define SGL_MAX_FACE_VERTS 	4


/* Max limits for lights */

#define SGL_MAX_ACTIVE_LIGHTS 	8
#define SGL_MAX_SHADOW_LIGHTS 	1
#define SGL_MAX_SPECULAR_LIGHTS 1


/* Max limits for Collision points */
#define SGL_MAX_ACTIVE_POINTS	50


/*
// SGL_FIRST_ERROR is the most negative number an error code can be.  Codes
// more negative than this are warnings (which start at SGL_FIRST_WARNING).
*/
#define SGL_FIRST_ERROR  -255
#define SGL_FIRST_WARNING  -100

/* 
// Error/warning return codes 
*/
enum
{	
	/*
	// No error/warning (This CANT BE NEGATIVE)
	*/
	sgl_no_err = 0, 

	/*
	// ALL errors and warnings MUST be negative
	*/
	sgl_err_no_mem = SGL_FIRST_ERROR,
	sgl_err_no_name,
	sgl_err_bad_name,
	sgl_err_bad_parameter,
	sgl_err_cyclic_reference,
	sgl_err_list_too_deep,
	sgl_err_too_many_planes,
	sgl_err_no_convex,
    sgl_err_no_mesh,
	sgl_err_bad_index,
	sgl_err_failed_init,
	sgl_err_bad_device,
	sgl_err_texture_memory_full,
	sgl_err_colinear_plane_points,

	sgl_warn_colinear_face_points = SGL_FIRST_WARNING,
	sgl_warn_colinear_uvs,
	sgl_warn_large_uvs,
};


/*
// Define the Special List Names. As these have to be checked specially,
// they can be negative values
*/
#define SGL_DEFAULT_LIST (-1)
#define SGL_NULL_LIST	 (-2)

/*
// Define the texture name to clear the texture.
*/
#define SGL_NULL_TEXTURE (-1)

/*
// The value that represents an unnamed object.
*/
#define SGL_ANON_OBJECT (-1)

/*
// A null material
*/
#define SGL_NULL_MATERIAL SGL_NULL_LIST

/*
// Define boolean values, if not already defined
*/
#ifndef TRUE
	#define TRUE (1)
#endif

#ifndef FALSE
	#define FALSE (0)
#endif
	


/*
// Define standard SGL types
*/
typedef int		sgl_bool;
typedef float	sgl_vector[3];
typedef float	sgl_2d_vec[2];
typedef float	sgl_colour[3];
typedef int		sgl_name;

/*
// Define special integer types
*/ 
typedef signed char 	sgl_int8;
typedef unsigned char	sgl_uint8;
typedef signed short	sgl_int16;
typedef unsigned short	sgl_uint16;
typedef signed long		sgl_int32;
typedef unsigned long	sgl_uint32;
typedef	unsigned int	sgl_uint;

typedef enum tag_device_colour_types
{
	sgl_device_16bit,
	sgl_device_24bit

} sgl_device_colour_types;


#ifdef WIN32
static sgl_vector sgl_x_axis = {1.0f, 0.0f, 0.0f};
static sgl_vector sgl_y_axis = {0.0f, 1.0f, 0.0f};
static sgl_vector sgl_z_axis = {0.0f, 0.0f, 1.0f};
#else
extern sgl_vector sgl_x_axis;
extern sgl_vector sgl_y_axis;
extern sgl_vector sgl_z_axis;
#endif


/*
// Pixel structure for the user-accessible texture map
*/
typedef struct tag_map_pixel
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	alpha; /* 0=Fully Opaque, 255=fully transparent*/

} sgl_map_pixel;

/*
// Structure for the intermediate map
*/
typedef struct
{
	/* 
	// ID for type of map. User accessible version must be set to "IMAP".
	// SGL uses other IDs for the pre-processed maps.
	*/
	char id[4];

	/*
	// X and Y dimensions of texture map
	*/
	int	x_dim;
	int	y_dim;

	/*
	// Array of pixels.
	*/
	sgl_map_pixel	* pixels;

} sgl_intermediate_map;





typedef enum tag_map_types
{
	sgl_map_16bit,
	sgl_map_16bit_mm,
	sgl_map_8bit,
	sgl_map_trans16,
	sgl_map_trans16_mm

} sgl_map_types;

/* Map Base Sizes */

typedef enum tag_map_sizes
{
	sgl_map_32x32,
	sgl_map_64x64,
	sgl_map_128x128,
	sgl_map_256x256

} sgl_map_sizes;



/*
// Texture Wrap Type Definitions 
//
// For reasons described in the SGL design Document, the map type
// values are desgined to occupy unique sets of bits.
//
//	The Smap will use bits 0-1, and the omap 2-4. (SEE TRDD027x.doc)
*/
 
typedef enum tag_smap_types
{
	sgl_smap_plane = 1,
	sgl_smap_cylinder = 2,
	sgl_smap_sphere = 3

} sgl_smap_types;

typedef enum tag_omap_types
{
	sgl_omap_obj_normal   = (1 << 2),
	sgl_omap_inter_normal =	(2 << 2),
	sgl_omap_reflection	  =	(3 << 2),
	sgl_omap_transmission = (4 << 2)

} sgl_omap_types;

 
/******************************
* Device and Viewport Routines 
******************************/

extern void CALL_CONV	sgl_get_errors ( int *earliest_error,
									     int *most_recent_error );

extern void CALL_CONV	sgl_get_warnings ( int *earliest_warning,
									       int *most_recent_warning );

extern int	CALL_CONV	sgl_create_screen_device (  int	device_number,
												int	x_dimension,
												int	y_dimension,
												sgl_device_colour_types device_mode,
												sgl_bool	double_buffer);

extern int	CALL_CONV	sgl_get_device ( int device_name,
									 int * device_number,
									 int * x_dimension,
									 int * y_dimension,
									 sgl_device_colour_types * device_mode,
									 sgl_bool * double_buffer);

extern void CALL_CONV	sgl_delete_device (int device_name);




extern int  CALL_CONV	sgl_create_viewport( int parent_device, 
										 int left, int top, 
										 int right, int bottom, 
										 float cam_rect_left,
										 float cam_rect_top,
										 float cam_rect_right, 
										 float cam_rect_bottom);

extern int  CALL_CONV	sgl_get_viewport( int viewport, 
									  int * left, int * top, 
									  int *right, int *bottom, 
									  float *cam_rect_left,
							   		  float *cam_rect_top, 
									  float *cam_rect_right, 
									  float *cam_rect_bottom);

extern int CALL_CONV	sgl_set_viewport( int viewport, 
									  int left, int top, 
									  int right, int bottom, 
									  float cam_rect_left,
									  float cam_rect_top,
									  float cam_rect_right,		  
									  float cam_rect_bottom);

extern void CALL_CONV	sgl_subtract_viewport( int viewport,
										int removed_viewport);

extern void CALL_CONV	sgl_delete_viewport (int viewport);

/******************************
* List and Instance Routines 
*
* Also define the Limits associated with 
******************************/

#define SGL_MAX_INSTANCE_PARAMS 10
#define SGL_MAX_INSTANCE_SUBS   30

extern int 	CALL_CONV   sgl_create_list (sgl_bool generate_name, 
										sgl_bool preserve_state, 
										sgl_bool separate_list);

extern void CALL_CONV	sgl_to_parent (void);

extern void CALL_CONV	sgl_modify_list (int list_name, sgl_bool clear_list);

extern void CALL_CONV	sgl_delete_list (int list_name);

extern void	CALL_CONV	sgl_detach_list (int list_name);

extern void CALL_CONV 	sgl_attach_list (int list_name);

extern void CALL_CONV 	sgl_set_ignore_list (int list_name, sgl_bool ignore);

extern void	CALL_CONV	sgl_use_instance(int list_to_instance);

extern void	CALL_CONV	sgl_instance_substitutions(int num_subs, 
										int *instance_params);

/*
// The following two lines may be removed if stdio.h is not desired and
// sgl_dump_list is not required.
*/
#include <stdio.h>
extern void CALL_CONV	sgl_dump_list(int listname, FILE * outfile, 
									sgl_bool traverse_instances);

/****************************/
/* Transformation Rountines */
/****************************/

extern int 	CALL_CONV	sgl_create_transform (sgl_bool generate_name);

extern void CALL_CONV	sgl_modify_transform (int name, sgl_bool clear_transform);

extern void CALL_CONV	sgl_translate (float x, float y, float z);

extern void CALL_CONV	sgl_rotate (sgl_vector axis, float angle);

extern void	CALL_CONV	sgl_scale(float x, float y, float z);

/*****************************/
/* Objects creation routines */
/*****************************/

extern int  CALL_CONV	sgl_create_convex (sgl_bool generate_name);

extern int	CALL_CONV	sgl_create_light_volume(const sgl_bool bGenerateName,
											const sgl_bool bLightVol,
											const int LightName);

extern int	CALL_CONV	sgl_create_hidden_convex( sgl_bool bGenerateName);


extern void	CALL_CONV 	sgl_modify_convex (int name, sgl_bool clear);

extern void CALL_CONV	sgl_add_simple_plane (sgl_vector surface_point,
										  sgl_vector normal, 
										  sgl_bool invisible);

extern void CALL_CONV	sgl_add_plane ( sgl_vector	surface_point,
									sgl_vector	point2,
									sgl_vector	point3,
									sgl_bool	invisible,
									sgl_vector	normal1,
									sgl_vector	normal2,
									sgl_vector	normal3,
									sgl_2d_vec	uv1,
									sgl_2d_vec	uv2,
									sgl_2d_vec	uv3);

extern void CALL_CONV	sgl_set_simple_plane (  int			plane_index,
											sgl_vector  surface_point,
											sgl_vector  normal,
											sgl_bool 	invisible);

extern void CALL_CONV	sgl_set_plane ( int 		plane_index,
									sgl_vector	surface_point,
									sgl_vector	point2,
									sgl_vector	point3,
									sgl_bool 	invisible,
									sgl_vector	normal1,
									sgl_vector	normal2,
									sgl_vector	normal3,
									sgl_2d_vec	uv1,
									sgl_2d_vec	uv2,
									sgl_2d_vec	uv3);

extern void CALL_CONV	sgl_delete_plane (int plane_index);

extern int	CALL_CONV	sgl_plane_count ();


/*****************/
/* Mesh Routines */
/*****************/


extern int	CALL_CONV	sgl_create_mesh (sgl_bool generate_name);

extern void	CALL_CONV	sgl_delete_mesh (int mesh_name);

extern void CALL_CONV	sgl_modify_mesh (int mesh_name, sgl_bool clear_mesh);

extern void CALL_CONV	sgl_add_vertices (  int			num_to_add,
										sgl_vector  *vertices,
										sgl_vector  *vertex_normals,
										sgl_2d_vec  *vertex_uvs);

extern void CALL_CONV	sgl_add_face (int num_face_points, int *vertex_ids);



typedef enum 
{
	sgl_no_cull, 		/*keeps all faces (default for each mesh)*/
	sgl_cull_anticlock, /*removes anticlockwise faces*/
	sgl_cull_clockwise  /*removes clockwise faces*/
}sgl_cull_mode;

extern void	CALL_CONV	sgl_set_cull_mode(sgl_cull_mode  cull_mode);

extern int	CALL_CONV	sgl_num_vertices (void);

extern int	CALL_CONV	sgl_num_faces (void);

extern int	CALL_CONV	sgl_num_face_vertices (int face);

extern int	CALL_CONV	sgl_get_vertex (int vertex, 
									   sgl_vector position, 
									   sgl_vector normal, 
									   sgl_2d_vec uv);

extern void	CALL_CONV	sgl_set_vertex (int vertex, 
								sgl_vector position, 
								sgl_vector normal, 
								sgl_2d_vec uv);

extern int	CALL_CONV	sgl_get_face (int face, int *vertex_indices);

extern void CALL_CONV	sgl_set_face (int face, 
									 int num_vertices, 
									 int *vertex_indices);

extern void CALL_CONV	sgl_delete_vertex (int vertex);

extern void CALL_CONV	sgl_delete_face (int face);


/*********************/
/* Material Routines */
/*********************/

extern int  CALL_CONV	sgl_create_material (sgl_bool generate_name, sgl_bool );

extern void CALL_CONV	sgl_use_material_instance(int instanced_material, 
											sgl_bool param_is_local);

extern void CALL_CONV	sgl_modify_material (int name, sgl_bool clear_material);

extern void	CALL_CONV	sgl_set_ambient (sgl_colour colour);

extern void CALL_CONV	sgl_set_diffuse (sgl_colour colour);

extern void CALL_CONV	sgl_set_specular (sgl_colour colour, int shininess);

extern void CALL_CONV	sgl_set_glow (sgl_colour colour);

extern void CALL_CONV	sgl_set_opacity (float opacity);

extern void CALL_CONV	sgl_set_texture_map (int texture_name, 
											sgl_bool flip_u, 
											sgl_bool flip_v);

extern void	CALL_CONV	sgl_set_texture_effect (sgl_bool affect_ambient,
											sgl_bool affect_diffuse,
											sgl_bool affect_specular,
											sgl_bool affect_glow);

extern int	CALL_CONV	sgl_create_texture (sgl_map_types 		map_type,
										sgl_map_sizes 		map_size, 
										sgl_bool 			generate_mipmap,
										sgl_bool 			dither,
										sgl_intermediate_map *pixel_data,
										sgl_intermediate_map *filtered_maps[]);

extern int	CALL_CONV	sgl_create_cached_texture (long user_id);
						
extern void	CALL_CONV	sgl_load_cached_texture(int 		name, 
										sgl_map_types 		map_type,
										sgl_map_sizes 		map_size, 
										sgl_bool 			generate_mipmap,
										sgl_bool 			dither,
										sgl_intermediate_map *pixel_data,
										sgl_intermediate_map *filtered_maps[],
										sgl_bool	overide_prepocessed_type);


extern int	CALL_CONV	sgl_preprocess_texture (sgl_map_types 		map_type,
									sgl_map_sizes 		map_size, 
									sgl_bool 			generate_mipmap,
									sgl_bool 			dither,
									sgl_intermediate_map *src_pixel_data,
									sgl_intermediate_map *filtered_maps[],
									sgl_intermediate_map *processed_map);

extern void  CALL_CONV	sgl_free_pixels (sgl_intermediate_map *imap);

extern void CALL_CONV	sgl_unload_cached_texture(int 		name);


/*
// Define the structure used for communicating the cached texture requirements
// between sgl and application
*/
typedef struct
{

	/*
	// SGL and User name for texture
	*/
	int  texture_name;
	long user_id;

	/*
	// Whether it is currently loaded,
	// needed for this render,
	// still in use by a previous render, 
	// (and, if needed) the approximate size in pixels, of the largest
	//  object that does use it. (Note this is the whole object, even if
	// only a small surface of that object uses the texture).
	*/
	sgl_bool loaded;
	sgl_bool needed;
	sgl_bool used_previous_render;
	int		 approx_object_size;

}sgl_tex_callback_struct;

/*
//Define the texture cache callback routine type
*/
typedef void (CALL_CONV *sgl_tex_callback_func)
						(sgl_tex_callback_struct tex_data_array[],
											int	 num_used,
											long free_space);


extern void CALL_CONV	sgl_register_texture_callback(sgl_tex_callback_func func,
									sgl_tex_callback_struct tex_data_array[],
														int	array_size);





/*
// The following macro calculates the pixel data size of a user accessible 
// intermediate map. This can be used in a malloc type call.
*/
#define	SGL_INTERMEDIATE_MAP_SIZE(x_dim, y_dim) (((long) x_dim * (long) y_dim) * (long) sizeof (sgl_map_pixel))

/*
// This tourine computes the size of the pixel data for ANY type of intermediate
// map. It does this by reading the values in the intermediate map header.
*/
extern long	CALL_CONV	sgl_texture_size (sgl_intermediate_map *texture_map);


extern void CALL_CONV   sgl_set_texture (int				texture_name,
									 sgl_bool 				generate_mipmap,
									 sgl_bool 				dither,
									 sgl_intermediate_map 	*pixel_data,
									 sgl_intermediate_map 	*filtered_maps[]);


extern void CALL_CONV	sgl_delete_texture (int texture_name);


extern unsigned long CALL_CONV sgl_get_free_texture_mem();


extern void CALL_CONV	sgl_set_smap (  sgl_smap_types 	smap_type,
									float			su,
									float			sv,
									float			ou,
									float			ov,
									float			r);

extern void CALL_CONV	sgl_set_omap (sgl_omap_types omap_type, 
									 float refractive_index);




/******************/
/* Light Routines */
/******************/

extern int	CALL_CONV	sgl_create_ambient_light (  sgl_bool 	generate_name,
									   sgl_colour 	colour,
									   sgl_bool 	relative);

extern int	CALL_CONV	sgl_create_parallel_light (	sgl_bool 	generate_name,
									sgl_colour 	colour,
									sgl_vector 	direction,
									sgl_bool	casts_shadows,
									sgl_bool	smooth_highlights);


extern int  CALL_CONV	sgl_create_point_light (	sgl_bool 	generate_name,
									sgl_colour 	colour,
									sgl_vector 	direction,
									sgl_vector 	position,
									int 		concentration,
									sgl_bool	casts_shadows,
									sgl_bool	smooth_highlights);


extern void CALL_CONV	sgl_position_light (int name);


extern void	CALL_CONV	sgl_switch_light( int name, 
									  sgl_bool on, 
									  sgl_bool casts_shadows,
									  sgl_bool smooth_highlights);


extern void CALL_CONV	sgl_set_ambient_light( int name, 
										   sgl_colour colour, 
										   sgl_bool relative);


extern void	CALL_CONV	sgl_set_parallel_light ( int 	name,
									sgl_colour 	colour,
									sgl_vector 	direction,
									sgl_bool 	casts_shadows,
									sgl_bool 	smooth_highlights);

extern void	CALL_CONV	sgl_set_point_light ( int 	name,
									sgl_colour 	colour,
									sgl_vector 	direction,
									sgl_vector 	position,
									int			concentration,
									sgl_bool 	casts_shadows,
									sgl_bool 	smooth_highlights);

extern void	CALL_CONV	sgl_pseudo_multishadows ( sgl_bool enable,
										   sgl_colour colour);

/*******************/
/* Camera Routines */
/*******************/

extern int 	CALL_CONV	sgl_create_camera ( float zoom_factor,
								float foreground,
								float inv_background);


extern int	CALL_CONV	sgl_get_camera (int			name,
									float 		*zoom_factor,
									float 		*foreground,
									float 		*inv_background);

extern void CALL_CONV	sgl_set_camera (int			name,
									float 		zoom_factor,
									float 		foreground,
									float 		inv_background);

extern void CALL_CONV   sgl_render (const int viewport_or_device, 
								const int camera_or_list, 
								const sgl_bool swap_buffers);


/*
// NOT YET IMPLEMENTED
//
extern int	CALL_CONV	sgl_render_time (void);
*/

/****************************/
/* Level of Detail Routines */
/****************************/

extern int  CALL_CONV	sgl_create_detail_levels ( sgl_bool   generate_name,
											   sgl_vector box_corner1,
											   sgl_vector box_corner2,
											   int	      models[3],
											   int		  change_sizes[2] );

extern int  CALL_CONV	sgl_get_detail_levels ( int        name,
										    sgl_vector box_corner1,
											sgl_vector box_corner2,
											int	       models[3],
											int		   change_sizes[2] );

extern void CALL_CONV	sgl_set_detail_levels ( int        name,
										    sgl_vector box_corner1,
											sgl_vector box_corner2,
											int	       models[3],
											int		   change_sizes[2] );

/********************************/
/* Collision Detection Routines */
/********************************/

extern int	CALL_CONV	sgl_create_point ( sgl_vector offset,
								   sgl_bool   collision_check );

extern void	CALL_CONV	sgl_set_point	 ( int		  point_name,
								   sgl_vector offset,
								   sgl_bool   collision_check );

extern void	CALL_CONV	sgl_switch_point ( int      name,
								   sgl_bool enable_check );

extern void	CALL_CONV	sgl_position_point (int name);

typedef struct tag_collision_data
{
	sgl_bool   collision;
	int		   object_name;
	int		   object_plane;
	sgl_vector normal;
	float	   d;
	int		   path_length;
	int		   path[SGL_MAX_PATH];

} sgl_collision_data;

extern int	CALL_CONV	sgl_query_point ( int				 name,
								  sgl_vector		 point_pos,
								  sgl_collision_data *collision_data );


/********************************
* Fog & Background Routines 
********************************/
extern void	CALL_CONV	sgl_set_fog( int  		camera_name,	
							 sgl_colour	fog_colour,
							 float		fog_density);


extern void	CALL_CONV	sgl_set_background_colour( int  		camera_name,	
										   sgl_colour	colour);

/********************************
* Primitive Object Routines 
*
* THESE ROUTINES ARENT TESTED !!!
********************************/
extern int  CALL_CONV	sgl_create_rectprism( 	float x, 
									float y, 
									float z, 
									sgl_bool bName,
									sgl_bool bTexture);

extern int  CALL_CONV	sgl_create_prism(	float height, 
								float radius, 
								int num_sides, 
								sgl_bool bName,
								sgl_bool bSmoothShade,
								sgl_bool bTexture);

extern int  CALL_CONV	sgl_create_sphere(	int sph_type, 
								float radius, 
								int num_sides, 
								sgl_bool bName, 
								sgl_bool bSmoothShade, 
								sgl_bool bTexture);

extern int  CALL_CONV	sgl_create_extruded_poly(	int numpoints, 
						      		float point_list[][2], 
					       			float depth, 
				       				sgl_bool bName,
								sgl_bool bSmoothShade, 
								sgl_bool bTexture);

extern int  CALL_CONV	sgl_revolve_polygon(	int nNoPoints, 
								float pt[][2], 
								int nNoSects,
								sgl_bool bClosed,
  								sgl_bool nYAxis,
  								int bSmoothShade,
  								sgl_bool bTexture);

/********************************
* Translucency Routine 
********************************/

extern void	CALL_CONV	sgl_new_translucent();


/********************************
* Quality Settings 
********************************/
extern void CALL_CONV	sgl_qual_smooth_shading(const sgl_bool enable);

extern void	CALL_CONV	sgl_qual_texturing(const sgl_bool enable);

extern void	CALL_CONV	sgl_qual_collision_detection(const sgl_bool enable, 
										 const sgl_bool enable_offscreen);

extern void	CALL_CONV	sgl_qual_generate_shadows(const sgl_bool enable);

extern void CALL_CONV	sgl_qual_fog(const sgl_bool enable);


/********************************
* random number generator. 
********************************/

extern long CALL_CONV 	sgl_rand();

extern void CALL_CONV	sgl_srand(unsigned long Seed);


/********************************
* Version Information
********************************/
typedef struct
{
	char *library;
	char *required_header;

} sgl_versions;

extern sgl_versions * CALL_CONV sgl_get_versions();


/********************************
* This is only for the simulator
********************************/

extern void CALL_CONV TexasWriteBMP(char * filename);




/********************************
* BMP to Texture laoding code.
*
* Given a filename, load the texture and create an SGL intermediate texture map.
********************************/
extern  sgl_intermediate_map CALL_CONV ConvertBMPtoSGL(char * 	filename,
									 sgl_bool  	Translucent);


/********************************
*  Load a bmp file, work out the biggest texture it will fit into and return
*  a texture handle. NB textures only loaded once! 
********************************/

extern int CALL_CONV	LoadBMPTexture (char *pszFilename, sgl_bool bTranslucent, 
					   sgl_bool generate_mipmap, sgl_bool dither);

/* free a texture loaded with the above function */
extern void CALL_CONV	FreeBMPTexture (int nTextureName);

/* free all textures loaded with the above function */
extern void CALL_CONV	FreeAllBMPTextures (void);



/*
// Load SGLB file
*/
extern int CALL_CONV LoadSglBin(char *pszFileName,	
					 int *noMeshes,		int **meshIDs, 	
					 int *noMaterials,	int **materialIDs,
					 int *noBMPTextures, int **BMPTextureIDs);

extern void CALL_CONV FreeSglBinTextures(int noBMPTextures, int *BMPTextureIDs);


/*============================================================================
// SGL Lite
*/

/*
// ---------------
// SGLTRIANGLETYPE
// ---------------
// These values are different bits that may be ORed together to form the
// material for the face.
*/

typedef enum
{
	SGLTT_GOURAUD 			= 0x0001, /* leave unset for flat shading */
	SGLTT_TEXTURE 			= 0x0002,
	SGLTT_HIGHLIGHT 		= 0x0004,
	SGLTT_MODULATE 			= 0x0008, /* this flag is currently ignored */
	SGLTT_MIPMAP 			= 0x0010,
	SGLTT_GLOBALTRANS 		= 0x0020,
	SGLTT_WRAPU 			= 0x0040, /* for D3D - ignored if bDoUVTimesInvW */
	SGLTT_WRAPV 			= 0x0080, /* is not set */
	SGLTT_FORCEOPAQUE 		= 0x0100,
	SGLTT_VERTEXTRANS 		= 0x0200, /* set if vertex alpha is to be used */

} SGLTRIANGLETYPE;

typedef enum
{
	NO_SHADOWS_OR_LIGHTVOLS,
	ENABLE_SHADOWS,
	ENABLE_LIGHTVOLS

} SGLSHADOWTYPE;

/*
// ----------
// SGLCONTEXT
// ----------
*/

typedef struct tagSGLCONTEXT
{

	/*
	// Enable fog:
	*/
	sgl_bool  bFogOn;


	/*
	// Fog colour:
	*/
	float  fFogR,fFogG,fFogB;  /* 0 <= colour component <= 1 */


	/*
	// Fog density
	// 
	// values range from 0 (hardly any fog) to 31 (a very bad day in LA)
	// This only affects triangles that have been added with bFogOn set to
	// TRUE
	*/
	sgl_uint32	u32FogDensity;

	sgl_bool  bCullBackfacing; /* non-zero to cull backfacing triangles */


	/*
	// Material type for the triangles, using ORed members of SGLTRIANGLETYPE.
	// These flags are specific to the set of triangles currently being added
	// to the frame's scene.
	*/
	sgl_uint32  u32Flags;


	/*
	// Texture name for texturing triangles:
	*/
	int  nTextureName;

	/*
	// If primitive is translucent, this value is used to 
	// sort translucent passes
	*/
	float	fTranslucentPassDepth;

	/*
	// Enable/Disable Clipping.  If zero then all vertices must be on screen.
	*/
	sgl_bool bDoClipping;

	/*
	// Scene background colour
	*/
	sgl_colour	cBackgroundColour;

	/*
	// Shadow or Light volume mode
	//
	// Only one mode can be used per scene; a single mode must be selected
	// on a per scene basis and must be correct before calling 
	// sgltri_startofframe()
	// 
	*/
	SGLSHADOWTYPE	eShadowLightVolMode;

	union
	{
		/*
		// Shadow brightness
		//
		// Can take values between 0.0 and 1.0. A value of 0 makes shadows
		// completely dark, 0.5 half the brightness of surrounding objects.
		// 1.0 gives no shadowing at all, but adds the shadow parameter 
		// processing. Only enabled if eShadowType is ENABLE_SHADOWS. Different
		// values may be selected between primitive routine calls.
		// 
		*/
		float fShadowBrightness;
	
		/*
		// light volume colour (D3DCOLOR format)
		//
		// This is the colour ADDED to the environment whenever a light
		// volume intersects with it. Only enabled if eShadowType is 
		// ENABLE_LIGHTVOLS. Different values may be selected between 
		// primitive routine calls.
		//
		*/
		sgl_uint32  u32LightVolColour;
	} u;

	/*
	// Flip U and V stuff
	*/
	sgl_bool	bFlipU, bFlipV;

	/*
	// If vertices are in d3d format multiply them by fInvW
	*/
	sgl_bool	bDoUVTimesInvW;

	/* ==================== used internally ===================== */

	int		FirstXRegion, LastXRegion, FirstYRegion, LastYRegion;

	float	invRegX, invRegY;

	/* ========================================= */
	
	/* 
	// 0 (Transparent) - 15 (Opaque). Value is ignored if the
	// SGLTT_GLOBALTRANS flag is not set
	*/

	sgl_uint32	u32GlobalTrans; 

} SGLCONTEXT, *PSGLCONTEXT;


/*
// ---------
// SGLVERTEX
// ---------
// This structure is currently physically equivalent to Direct3D's D3DTLVERTEX
// (so one can be cast to the other), with the exception that Direct3D's u and
// v values must be multiplied by the 1/w value.  RAVE vertices already contain
// u/w and v/w.
*/

typedef struct tagSGLVERTEX
{

	/*
	// Projected screen coordinates:
	*/
	float  fX;  /* 0 <= fX < screen width (up to 1024) */
	float  fY;  /* 0 <= fY < screen height (up to 1024) */
	float  fZ;  /* 0 <= fZ <= 1, where 1 is infinite distance away */


	/*
	// 1/w for the perspective projection:
	*/
	float  fInvW;


	/*
	// Material colour (D3DCOLOR format):
	*/
	sgl_uint32  u32Colour;


	/*
	// Specular colour (D3DCOLOR format):
	*/
	sgl_uint32  u32Specular;


	/*
	// Texture coordinates:
	*/
	float  fUOverW, fVOverW;

} SGLVERTEX, *PSGLVERTEX;


/*
// -------------------
// sgltri_startofframe
// -------------------
// see sgltri_triangles
*/

extern void CALL_CONV  sgltri_startofframe (PSGLCONTEXT  pContext);


/*
// ----------------
// sgltri_triangles
// ----------------
// Sends a set of triangles, output by Direct3D or RAVE's transformation and
// lighting stages, to the hardware.
//
// sgltri_startofframe should be called before the first call of this function
// for a frame.
//
// This function can then be called multiple times to add subsequent sets of
// triangles before the sgltri_render function is called to render the complete
// scene.
//
// pContext: Pointer to a context structure for this set of triangles.
// nNumFaces: Number of faces.
// pFaces: Pointer to the first face in the array of faces.
// pVertices: Pointer to the first vertex in the array of vertices, some or all
//   of which are used by the faces pFaces[0..nNumFaces].  This parameter is
//   currently unused.
//
// Error values set by this function (read using sgl_get_errors):
//   sgl_no_error: success
//   sgl_bad_parameter: one or more of the pointer parameters was null, or
//     nNumFaces was negative.
//   sgl_err_failed_init: initialisation failed (probably out of memory)
//	 sgl_err_no_mem: out of memory
//
// It is assumed that the face structures refer to valid vertices.
*/

extern void CALL_CONV  sgltri_triangles ( PSGLCONTEXT  pContext,
										  int  nNumFaces,
										  int  pFaces[][3],
										  PSGLVERTEX  pVertices );

extern void CALL_CONV  sgltri_quads ( PSGLCONTEXT  pContext,
									  int  nNumFaces,
									  int  pFaces[][4],
									  PSGLVERTEX  pVertices );

extern void CALL_CONV  sgltri_shadow (   PSGLCONTEXT  pContext,
										 int		nNumFaces,
										 int		pFaces[][3],
										 PSGLVERTEX  pVertices,
										 float		fBoundingBox[2][2]);

/*
// -------------
// sgltri_render
// -------------
// see sgltri_triangles
//
// Render the entire scene of triangles.
*/

extern void CALL_CONV  sgltri_render (PSGLCONTEXT  pContext);


/*
// -----------------------
// sgltri_isrendercomplete
// -----------------------
//
// If the timeout value is non-zero, the function will loop 
// round until the hardware either finishes or times out,
// otherwise the state is sampled and returned.
*/

typedef enum
{
	IRC_RENDER_COMPLETE,
	IRC_RENDER_NOT_COMPLETE,
	IRC_RENDER_TIMEOUT
} IRC_RESULT;

extern IRC_RESULT CALL_CONV sgltri_isrendercomplete (PSGLCONTEXT  pContext, 
		   											 sgl_uint32 u32Timeout);


/*
// Revert to previous structure packing mode
*/
#pragma pack()


#ifdef __cplusplus
}
#endif 


#endif    /* __SGL_H__ */

/*------------------------------ End of File --------------------------------*/
