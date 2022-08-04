#include <aliasnum.h> 
#ifndef __HHL_H 
#define  __HHL_H 
#define HHLC_SUCCESS     0    
#define HHLC_FAIL       -1
enum {
   HHLC_SYS_INIT,
   HHLC_SYS_SET_MODE,             
   HHLC_SYS_CLOSE,                
   HHLC_SYS_START_FRAME,          
   HHLC_SYS_END_FRAME,            
   HHLC_SYS_SET_FOCUS,
   HHLC_SYS_SWITCH_SURFACE,       
   HHLC_SYS_SET_BOARD_CONTEXT,    
   HHLC_SYS_LOAD_TEXTURE,
   HHLC_SYS_RELOAD_TEXTURE,
   HHLC_SYS_CLEAR_TEXTURE,
   HHLC_SYS_CLEAR_ALL_TEXTURES,
   HHLC_SYS_SET_TEXTURE_DESC,     
   HHLC_SYS_SET_PAL,
   HHLC_NUM_SYS_FUNCS
};
enum {
   HHLC_CLEAR_BUFFER,         
   HHLC_SET_CLIPRECT,         
   HHLC_DRAW_POINT,           
   HHLC_DRAW_UPOINT,
   HHLC_DRAW_LINE,
   HHLC_DRAW_ULINE,
   HHLC_DRAW_RECT,
   HHLC_DRAW_URECT,
   HHLC_DRAW_ELLIPSE,
   HHLC_DRAW_UELLIPSE,
   HHLC_DRAW_DISK,
   HHLC_DRAW_UDISK,
   HHLC_DRAW_POLY,            
   HHLC_DRAW_UPOLY,
   HHLC_DRAW_GPOLY,           
   HHLC_DRAW_UGPOLY,
   HHLC_DRAW_HPOLY,           
   HHLC_DRAW_UHPOLY,
   HHLC_DRAW_TPOLY,           
   HHLC_DRAW_UTPOLY,
   HHLC_ENABLE_BLEND,         
   HHLC_DISABLE_BLEND,
   HHLC_SET_HAZE,
   HHLC_SET_MAX_INTENSITY,
   HHLC_UPLHT_TMAP,
   HHLC_UPLH_TMAP,
   HHLC_UPLT_TMAP,
   HHLC_UPL_TMAP,
   HHLC_UPHT_TMAP,
   HHLC_UPH_TMAP,
   HHLC_UPT_TMAP,
   HHLC_UP_TMAP,
   HHLC_ULHT_TMAP,
   HHLC_ULH_TMAP,
   HHLC_ULT_TMAP,
   HHLC_UL_TMAP,
   HHLC_UHT_TMAP,
   HHLC_UH_TMAP,
   HHLC_UT_TMAP,
   HHLC_U_TMAP,
   HHLC_PLHT_TMAP,
   HHLC_PLH_TMAP,
   HHLC_PLT_TMAP,
   HHLC_PL_TMAP,
   HHLC_PHT_TMAP,
   HHLC_PH_TMAP,
   HHLC_PT_TMAP,
   HHLC_P_TMAP,
   HHLC_LHT_TMAP,
   HHLC_LH_TMAP,
   HHLC_LT_TMAP,
   HHLC_L_TMAP,
   HHLC_HT_TMAP,
   HHLC_H_TMAP,
   HHLC_T_TMAP,
   HHLC_TMAP,
   HHLC_BITMAP,
   HHLC_SCALE_BITMAP,
   HHLC_OVERLAY_CALLBACK,
   HHLC_GET_CALLBACK_ARG,
   HHLC_NUM_TABLE_FUNCS       
};
enum {
   HHLC_CQ_START_FRAME,
   HHLC_CQ_END_FRAME,
   HHLC_CQ_CARD_READY,
   HHLC_CQ_CARD_IDLE,
   HHLC_CQ_CLEAR_BUFFER,
   HHLC_CQ_SET_FOCUS,
   HHLC_CQ_SEND_PRIM,
   HHLC_CQ_LOAD_TEXM,
   HHLC_CQ_BITMAP,
   HHLC_CQ_SCALE_BITMAP,
   HHLC_CQ_OVERLAY_CALLBACK,
   HHLC_CQ_SET_CLIPRECT,
   HHLC_CQ_PARSE_CMDQ,
   HHLC_CQ_BACKGROUND_CHECK,
   HHLC_CQ_TEST_AND_PUSH_PRIM,
   HHLC_CQ_NUM_FUNCS
};
typedef union
{
   struct {
      uint8 red;
      uint8 green;
      uint8 blue;
      uint8 alpha;
   } rgba_s;
   uint32 rgba;                                                                  
} hhls_color;
#define hhl_color_diff(c1,c2) ((c1).rgba != (c2).rgba)
typedef grs_vertex hhls_vertex;
typedef grs_bitmap hhls_bitmap;
typedef struct {
   uint32   tot_buffer_mem;
   uint32   tot_texture_mem;
   uint32   tot_mem;
   uint32   base_texture_load_address;
   unsigned texturemapping    : 1;
   unsigned fogging           : 1;
   unsigned gouraud_shading   : 1;
   unsigned chroma_keying     : 1;
   unsigned dithering         : 1;
   unsigned alpha_blending    : 1;
   unsigned rgb5551           : 1;
   unsigned rgb8888           : 1;
   unsigned transparency      : 1;
   unsigned logical_copy_modes: 1;
   unsigned persp_correct     : 1;
   unsigned clipping          : 1;
   unsigned transparent_blit  : 1;        
   unsigned stupid_tex_handles: 1;        
} hhls_attributes;
typedef enum {
   HHLC_HARDWARE_VESA,
   HHLC_HARDWARE_EAGLE,
   HHLC_HARDWARE_3DFX,
   HHLC_HARDWARE_RENDITION,
   HHLC_HARDWARE_YAMAHA
} hhls_HardwareType;
typedef enum {
   HHLC_PRIMARY_SURFACE,
   HHLC_DIRECT_SURFACE,
   HHLC_SECONDARY_SURFACE
} hhls_SurfaceType;
typedef enum {
   HHLC_DIRECT_BUFFER_IS_AVAIL,
   HHLC_DIRECT_BUFFER_NOT_AVAIL
} hhls_DirectBuffer;
typedef enum {
   HHLC_SINGLE_BUFFER,
   HHLC_DOUBLE_BUFFER_BLIT,
   HHLC_DOUBLE_BUFFER_SWAP,
   HHLC_TRIPLE_BUFFER_SWAP_VISIBLE,
   HHLC_TRIPLE_BUFFER_SWAP_DRAW,
} hhls_buffering_modes;
typedef struct hhls_ctx {
   struct hhls_ctx *base_context; 
   grs_canvas      *canvas_ptr;   
   sint             xOrigin;      
   sint             yOrigin;      
   hhls_SurfaceType surfType;     
} hhls_context;
typedef void (*hhls_overlay_callback)(int32 x, int32 y, void *arg);
typedef uint32 hhls_disk_handle;
typedef int (*hhls_texture_disk_func)(uint32);
typedef struct {
   uint32 opt_prim_number; 
   uint32 cur_prim_number; 
   uint32 opt_stream_size; 
   uint32 cur_stream_size; 
   sint16 bckgd_freq;      
   uint16 delay_fac;       
   sint32 frames_until_check;  
} hhls_gen_config;
typedef enum {
   HHLC_PAL_RGB_332,
   HHLC_PAL_RGB_1555,
   HHLC_PAL_RGB_888,
   HHLC_PAL_BGR_888,
   HHLC_PAL_RGB_8888,
   HHLC_PAL_RGB_1232,
   HHLC_PAL_RGB_4444,
   HHLC_MAX_PALETTE_TYPES
} hhls_pal_type;
typedef struct {
   float   avg_polys_per_rfix;
   float   avg_rfix_per_stream;
   uint32  avg_command_queue_size;
   uint32  max_command_queue_size;
   uint32  commands_in_frame;
   uint32  polys_in_frame;
   uint32  rfixes_in_frame;
   uint32  streams_in_frame;
} hhls_cmdq_stats;
extern hhls_attributes hhld_device_attributes;
extern void (**hhld_function_table)();
extern void (*hhld_egl_function_table[])();
extern void (*hhld_rnd_function_table[])();
extern void (*hhld_2d_function_table[])();
extern void (**hhld_cmdq_function_table)();
extern void (*hhld_cmdq_gen_function_table[])();
extern void (*hhld_cmdq_egl_function_table[])();
extern void (*hhld_cmdq_rnd_function_table[])();
extern void (**hhld_sys_function_table)();
extern void (*hhld_sys_gen_function_table[])();
extern void (*hhld_sys_2d_function_table[])();
extern void (*hhld_sys_egl_function_table[])();
extern void (*hhld_sys_rnd_function_table[])();
extern real hhld_haze_intensity;
extern hhls_HardwareType hhld_hardware_type;
extern hhls_DirectBuffer hhld_direct_buffer;
extern hhls_SurfaceType  hhld_surface_type;
extern hhls_context *hhld_context;
#define hhld_canvas (hhld_context->canvas_ptr)
extern hhls_context hhld_base_draw_context;
extern hhls_context hhld_base_visible_context;
extern hhls_context hhld_base_blit_context;
extern hhls_buffering_modes hhld_buffering_mode;
extern uint32 hhld_frame_count;
extern uint32 hhld_queue_count;
extern hhls_gen_config hhld_pipe_gc;
extern real   hhld_alpha_scale;
extern int    hhld_chroma;
extern uint32 hhld_chroma_value;
#ifdef WARN_ON
extern int hhld_in_frame;
#endif 
extern hhls_cmdq_stats hhld_cmdq_stats;
extern int hhld_curr_poly_area;
#define hhl_malloc(structtype) \
   (structtype *)Malloc(sizeof(structtype))
#define hhl_calloc(n, structtype) \
   (structtype *)Malloc(n * sizeof(structtype))
#define hhl_free(x) do { Free(x); x = NULL; } while (0)
int hhl_set_hardware_type(hhls_HardwareType hardware);
int hhl_set_surface_type(hhls_SurfaceType sType);
int hhl_cmdq_size(void);
int hhl_test_board_ready(void);
void hhl_set_synch_mode(int mode);
void hhl_synch_up(void);      
void hhl_end_frame_synch(void);
int  hhl_set_context(hhls_context *newContext , int inform_board );
int  hhl_push_context( hhls_context *newContext );
hhls_context *hhl_pop_context( void );
int  hhl_alloc_context(hhls_context **new_context, uint8 type, int16 w, int16 h);
void hhl_init_context(hhls_context *context, uint8 *bits, uint8 type, int16 w, int16 h);
void hhl_free_context(hhls_context **old_context);
int hhl_alloc_sub_context(
   hhls_context *base_ontext,
   hhls_context **new_context,
   sint x, sint y,            
   uint w, uint h             
);
void hhl_init_sub_context(
   hhls_context *base_context,
   hhls_context *new_context,
   sint x, sint y,            
   uint w, uint h             
);
void hhl_free_sub_context(hhls_context **contextPtr);
int hhl_start_rendering_context(int inform_board);
int hhl_end_rendering_context(int popContext);
int hhl_start_overlay_context_intern(int inform_board);
#define hhl_start_overlay_context() hhl_start_overlay_context_intern(TRUE)
int hhl_end_overlay_context(int popContext);
void hhl_validate_context(hhls_context *context);
hhls_context *hhl_get_draw_context(void);
hhls_context *hhl_get_visible_context(void);
hhls_context *hhl_get_blit_context(void);
#define hhl_set_pal \
   ((int (*)(int start, int length, uint8 *entries))hhld_sys_function_table[HHLC_SYS_SET_PAL])
int  hhl_alloc_palette(uint8 **new_palette, hhls_pal_type palette_type);
int  hhl_copy_and_convert_palette(uint8 *dest, hhls_pal_type dest_type,
                                  uint8 *src,  hhls_pal_type src_type);
void hhl_free_palette(uint8 **old_palette);
uint32 hhl_install_palette(uint8 *new_palette, hhls_pal_type type);
int   hhl_remove_palette(uint32 pal_index);
void  hhl_remove_all_palettes(void);
int hhl_get_free_texture_memory(void);
void hhl_2d_set_haze_table(uint8 *haze_table, hhls_color *haze_colorp);
#define hhl_init \
   ((int (*)(uint32 max_cmds, uint32 primq_size, uint32 max_textures, uint32 hash_table_size))hhld_sys_function_table[HHLC_SYS_INIT])
#define hhl_set_mode \
   ((int (*)(uint w, uint h, uint d, uint clear, uint dblBuffer))hhld_sys_function_table[HHLC_SYS_SET_MODE])
#define hhl_close \
   ((void (*)())hhld_sys_function_table[HHLC_SYS_CLOSE])
#define hhl_start_frame \
   ((void (*)())hhld_sys_function_table[HHLC_SYS_START_FRAME])
#define hhl_end_frame \
   ((void (*) ())hhld_sys_function_table[HHLC_SYS_END_FRAME])
#define hhl_set_focus \
   ((void (*)(uint8 *base_video_address))hhld_sys_function_table[HHLC_SYS_SET_FOCUS])
#define hhl_switch_surface \
   ((int (*)(hhls_SurfaceType sType))hhld_sys_function_table[HHLC_SYS_SWITCH_SURFACE])
#define hhl_set_board_context \
   ((void (*)(hhls_context *context))hhld_sys_function_table[HHLC_SYS_SET_BOARD_CONTEXT])
#define hhl_clear_buffer \
   ((int (*)(hhls_color *cPtr))hhld_function_table[HHLC_CLEAR_BUFFER])
#define hhl_set_cliprect \
   ((void (*)(sint l, sint t, sint r, sint b))hhld_function_table[HHLC_SET_CLIPRECT])
void hhl_set_translucency(real alpha);
void hhl_activate_chroma_key(void);
void hhl_deactivate_chroma_key(void);
void hhl_set_chroma_value(uint32 chroma);
#define hhl_draw_point \
   ((void (*)(hhls_color *colorPtr, real x0, real y0))hhld_function_table[HHLC_DRAW_POINT])
#define hhl_draw_upoint \
   ((void (*)(hhls_color *colorPtr, real x0, real y0))hhld_function_table[HHLC_DRAW_UPOINT])
#define hhl_draw_line \
   ((void (*)(hhls_color *colorPtr, real x0, real y0, real x1, real y1))hhld_function_table[HHLC_DRAW_LINE])
#define hhl_draw_uline \
   ((void (*)(hhls_color *colorPtr, real x0, real y0, real x1, real y1))hhld_function_table[HHLC_DRAW_ULINE])
#define hhl_draw_ellipse \
   ((void (*)(hhls_color *colorPtr, real cx, real cy, real rx, real ry))hhld_function_table[HHLC_DRAW_ELLIPSE])
#define hhl_draw_uellipse \
   ((void (*)(hhls_color *colorPtr, real cx, real cy, real rx, real ry))hhld_function_table[HHLC_DRAW_UELLIPSE])
#define hhl_draw_disk \
   ((void (*)(hhls_color *colorPtr, real cx, real cy, real rx, real ry))hhld_function_table[HHLC_DRAW_DISK])
#define hhl_draw_udisk \
   ((void (*)(hhls_color *colorPtr, real cx, real cy, real rx, real ry))hhld_function_table[HHLC_DRAW_UDISK])
#define hhl_draw_rect \
   ((void (*)(hhls_color *colorPtr, int32 l, int32 t, int32 r, int32 b))hhld_function_table[HHLC_DRAW_RECT])
#define hhl_draw_urect \
   ((void (*)(hhls_color *colorPtr, int32 l, int32 t, int32 r, int32 b))hhld_function_table[HHLC_DRAW_URECT])
#define hhl_draw_poly \
   ((void (*)(hhls_color *cPtr, uint n, hhls_vertex **vertex_list))hhld_function_table[HHLC_DRAW_POLY])
#define hhl_draw_upoly \
   ((void (*)(hhls_color *cPtr, uint n, hhls_vertex **vertex_list))hhld_function_table[HHLC_DRAW_UPOLY])
#define hhl_draw_gpoly \
   ((void (*)(hhls_color *cPtr, uint n, hhls_vertex **vertex_list))hhld_function_table[HHLC_DRAW_GPOLY])
#define hhl_draw_ugpoly \
   ((void (*)(hhls_color *cPtr, uint n, hhls_vertex **vertex_list))hhld_function_table[HHLC_DRAW_UGPOLY])
#define hhl_draw_hpoly \
   ((void (*)(hhls_color *baseColorPtr, uint n, hhls_vertex **vertex_list))hhld_function_table[HHLC_DRAW_HPOLY])
#define hhl_draw_uhpoly \
   ((void (*)(hhls_color *baseColorPtr, uint n, hhls_vertex **vertex_list))hhld_function_table[HHLC_DRAW_UHPOLY])
#define hhl_draw_tpoly \
   ((void (*)(hhls_color *cPtr, uint n, hhls_vertex **vertex_list))hhld_function_table[HHLC_DRAW_TPOLY])
#define hhl_draw_utpoly \
   ((void (*)(hhls_color *cPtr, uint n, hhls_vertex **vertex_list))hhld_function_table[HHLC_DRAW_UTPOLY])
#define hhl_enable_blending \
   ((void (*)())hhld_function_table[HHLC_ENABLE_BLEND])
#define hhl_disable_blending \
   ((void (*)())hhld_function_table[HHLC_DISABLE_BLEND])
#define hhl_set_haze \
   ((void (*)(hhls_color *colorPtr, real intensity))hhld_function_table[HHLC_SET_HAZE])
#define hhl_set_max_intensity \
   ((void (*)(real i))hhld_function_table[HHLC_SET_MAX_INTENSITY])
#define hhl_uplht_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UPLHT_TMAP])
#define hhl_uplh_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UPLH_TMAP])
#define hhl_uplt_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UPLT_TMAP])
#define hhl_upl_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UPL_TMAP])
#define hhl_upht_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UPHT_TMAP])
#define hhl_uph_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UPH_TMAP])
#define hhl_upt_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UPT_TMAP])
#define hhl_up_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UP_TMAP])
#define hhl_ulht_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_ULHT_TMAP])
#define hhl_ulh_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_ULH_TMAP])
#define hhl_ult_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_ULT_TMAP])
#define hhl_ul_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UL_TMAP])
#define hhl_uht_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UHT_TMAP])
#define hhl_uh_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UH_TMAP])
#define hhl_ut_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_UT_TMAP])
#define hhl_u_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_U_TMAP])
#define hhl_plht_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_PLHT_TMAP])
#define hhl_plh_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_PLH_TMAP])
#define hhl_plt_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_PLT_TMAP])
#define hhl_pl_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_PL_TMAP])
#define hhl_pht_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_PHT_TMAP])
#define hhl_ph_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_PH_TMAP])
#define hhl_pt_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_PT_TMAP])
#define hhl_p_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_P_TMAP])
#define hhl_lht_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_LHT_TMAP])
#define hhl_lh_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_LH_TMAP])
#define hhl_lt_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_LT_TMAP])
#define hhl_l_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_L_TMAP])
#define hhl_ht_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_HT_TMAP])
#define hhl_h_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_H_TMAP])
#define hhl_t_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_T_TMAP])
#define hhl_tmap \
   ((void (*)(uint n, hhls_vertex **vertex_list, hhls_bitmap *bmap))hhld_function_table[HHLC_TMAP])
#define hhl_gt_tmap hhl_egl_gt_tmap
void hhl_egl_gt_tmap(uint32 n, hhls_vertex **vertex_list, hhls_bitmap *bmap);
#define hhl_bitmap \
   ((void (*)(hhls_bitmap *bmp, sint x, sint y, int asynch))hhld_function_table[HHLC_BITMAP])
#define hhl_synch_bitmap(bm, x, y) hhl_bitmap(bm, x, y, FALSE)
#define hhl_asynch_bitmap(bm, x, y) hhl_bitmap(bm, x, y, TRUE)
#define hhl_scale_bitmap \
   ((void(*)(hhls_bitmap *bmp, sint x, sint y, real sx, real sy))hhld_function_table[HHLC_SCALE_BITMAP])
#define hhl_get_callback_arg \
   ((uint8* (*)(int len))hhld_function_table[HHLC_GET_CALLBACK_ARG])
#define hhl_overlay_callback \
   ((void (*)(hhls_overlay_callback callback, void *arg, int len))hhld_function_table[HHLC_OVERLAY_CALLBACK])
#define hhl_load_texture \
   ((int (*)(hhls_bitmap *bm, hhls_disk_handle disk_handle, int synch))hhld_sys_function_table[HHLC_SYS_LOAD_TEXTURE])
#define hhl_reload_texture \
   ((int (*)(hhls_bitmap *oldbm, hhls_bitmap *bm, hhls_disk_handle disk_handle))hhld_sys_function_table[HHLC_SYS_RELOAD_TEXTURE])
#define hhl_clear_texture \
   ((int (*)(hhls_bitmap *oldbm))hhld_sys_function_table[HHLC_SYS_CLEAR_TEXTURE])
#define hhl_clear_all_textures \
   ((void (*)())hhld_sys_function_table[HHLC_SYS_CLEAR_ALL_TEXTURES])
#define hhl_set_texture_desc \
   ((void (*)(int tmap_handle, hhls_bitmap *bm))hhld_sys_function_table[HHLC_SYS_SET_TEXTURE_DESC])
void hhl_set_disk_cache_callbacks(hhls_texture_disk_func lock,
                                  hhls_texture_disk_func validate,
                                  hhls_texture_disk_func unlock);
int hhl_test_texture_loaded(hhls_bitmap *test_bm, int spew);
#define HHLC_NO_CONTEXT       0
#define HHLC_NORMAL_CONTEXT   1
#define HHLC_OVERLAY_CONTEXT  2
void hhl_clear_context_stack(void);
extern int hhld_rendering_context;
#define hhl_cmdq_process()                                       \
   hhl_cmdq_background_check();                                  \
   hhld_pipe_gc.frames_until_check = hhld_pipe_gc.bckgd_freq
#define hhl_cmdq_test()                                          \
   if (hhld_pipe_gc.frames_until_check < 0) {                    \
      hhl_cmdq_process();                                        \
   } else
#define hhl_cmdq_tick() \
   hhld_pipe_gc.frames_until_check--
#define hhl_cmdq_tick_and_test(ticks)                               \
   do {                                                             \
      hhld_pipe_gc.frames_until_check -= ticks;                     \
      if (hhld_pipe_gc.frames_until_check < 0) {                    \
         hhl_cmdq_process();                                        \
      }                                                             \
   } while (0)
#define hhl_cmdq_start_frame \
   ((void (*)())hhld_cmdq_function_table[HHLC_CQ_START_FRAME])
#define hhl_cmdq_end_frame \
   ((void (*)())hhld_cmdq_function_table[HHLC_CQ_END_FRAME])
#define hhl_cmdq_card_ready \
   ((int (*)(bool tmaps, int *size))hhld_cmdq_function_table[HHLC_CQ_CARD_READY])
#define hhl_cmdq_card_idle \
   ((int (*)(void))hhld_cmdq_function_table[HHLC_CQ_CARD_IDLE])
#define hhl_cmdq_clear_buffer \
   ((int (*)(uint8 *data))hhld_cmdq_function_table[HHLC_CQ_CLEAR_BUFFER])
#define hhl_cmdq_set_focus \
   ((int (*)(uint8 *base_video_address))hhld_cmdq_function_table[HHLC_CQ_SET_FOCUS])
#define hhl_cmdq_send_prim \
   ((int (*)(uint32 *len, uint8 *data))hhld_cmdq_function_table[HHLC_CQ_SEND_PRIM])
#define hhl_cmdq_load_texm \
   ((int (*)(hhls_texture_info *data))hhld_cmdq_function_table[HHLC_CQ_LOAD_TEXM])
#define hhl_cmdq_swap_texm \
   ((int (*)(hhls_texture_info *data))hhld_cmdq_function_table[HHLC_CQ_SWAP_TEXM])
#define hhl_cmdq_clear_texm hhl_cmdq_gen_clear_texm
#define hhl_cmdq_flush_texm \
   ((int (*)(hhls_texture_info *data))hhld_cmdq_function_table[HHLC_CQ_FLUSH_TEXM])
#define hhl_cmdq_set_context \
   hhl_cmdq_gen_set_context
#define hhl_cmdq_set_cliprect \
   ((int (*)(uint8 *args))hhld_cmdq_function_table[HHLC_CQ_SET_CLIPRECT])
#define hhl_cmdq_bitmap \
   ((void (*)(uint8 *args))hhld_cmdq_function_table[HHLC_CQ_BITMAP])
#define hhl_cmdq_scale_bitmap \
   ((void (*)(uint8 *args))hhld_cmdq_function_table[HHLC_CQ_SCALE_BITMAP])
#define hhl_cmdq_overlay_callback \
   ((void (*)(uint8 *arg))hhld_cmdq_function_table[HHLC_CQ_OVERLAY_CALLBACK])
#define hhl_cmdq_parse_cmdq \
   ((int (*)(hhls_cmdq_entry *curr_cmd , uint8 *data))hhld_cmdq_function_table[HHLC_CQ_PARSE_CMDQ])
#define hhl_cmdq_background_check \
   ((int (*)(void))hhld_cmdq_function_table[HHLC_CQ_BACKGROUND_CHECK])
#define hhl_cmdq_optimal_push_prim_intern \
   ((void (*)(int len))hhld_cmdq_function_table[HHLC_CQ_TEST_AND_PUSH_PRIM])
#define hhl_cmdq_optimal_push_prim(len) hhl_cmdq_optimal_push_prim_intern(len)
#endif /* __HHL_H */ 
