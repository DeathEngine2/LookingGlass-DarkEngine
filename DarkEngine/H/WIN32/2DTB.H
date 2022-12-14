#include <2d.h> 
#ifndef __2DTB_H 
#define  __2DTB_H 
extern int tb_flags;
extern int tb_set_mode_flags;
extern uchar tb_border_color;
extern int tb_default_mode;
extern int tb_blend_levels;
extern int tb_width;
extern int tb_height;
extern grs_screen *tb_screen;
extern grs_canvas *tb_blit_canvas;
extern grs_canvas *tb_draw_canvas;
extern uchar *tb_pal;
extern void tb_uvbe_init();
extern void tb_init();
extern int tb_set_mode(int mode);
extern void tb_start_frame();
extern int tb_end_frame();
extern char *tb_fn_mung (char *name);
extern void tb_clear_boundary(grs_canvas *c);
extern bool tb_check_boundary(grs_canvas *c);
extern grs_canvas *tb_alloc_sub_canvas(grs_canvas *c, int w, int h);
#define TB_DOUBLE_BUFFER             0x0001
#define TB_CLEAR_BUFFER              0x0002
#define TB_VARIABLE_DRAW_CANVAS_SIZE 0x0004
#define TB_CALC_IPAL                 0x0008
#define TB_CALC_LTAB                 0x0010
#define TB_CALC_BLEND                0x0020
#define TB_CLEAR_MONO                0x0040
#endif /* __2DTB_H */ 
