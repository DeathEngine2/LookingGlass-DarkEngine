#ifndef _3DTEST_H
#define _3DTEST_H

#include <lg.h>
#include <fix.h>
#include <2d.h>
#include <3d.h>

#define G3TEST         // flag so user code can #ifdef on 3DTEST

enum
{
   G3_NORMAL,             // draw polys normally
   G3_WIRE_OVERLAY,       // draw polys with wireframe overlay
   G3_WIRE,               // draw polys as wireframe
   G3_WIRE_HIDDEN         // draw polys as wireframe with hidden lines removed
};
extern int g3test_wire_mode;
extern int g3test_wire_color;   // fcolor value used for wireframe

extern bool g3test_single_step;
extern bool g3test_double;

extern g3s_vector g3test_camera_position;
extern g3s_angvec g3test_camera_angle;

#define G3TEST_VECTOR    0
#define G3TEST_POINT     1
#define G3TEST_POINT_PTR 2
#define G3TEST_PHANDLE   3
extern void g3test_init(bool init_3d, bool init_2d, int point_mode);
extern void g3test_close(void);

extern void g3test_init_camera(fix x, fix y, fix z);
extern void g3test_update_camera(void (*key_func)(uchar));
extern void g3test_reset_camera(void);

extern void g3test_start_frame(void);
extern void g3test_start_frame_3d(void);   // assume user sets up 3D herself
extern void g3test_end_frame(void);

extern void g3test_draw_tmap(int n, g3s_phandle *vert, grs_bitmap *bm);
extern void g3test_light_tmap(int n, g3s_phandle *vert, grs_bitmap *bm);
extern void g3test_draw_poly(int color, int n, g3s_phandle *vert);
extern void g3test_draw_tluc_poly(int color, int n, g3s_phandle *vert);

#ifndef TEST_3D
#define g3_draw_tmap(a,b,c)  g3test_draw_tmap(a, (g3s_phandle *) b, c)
#define g3_light_tmap(a,b,c) g3test_light_tmap(a, (g3s_phandle *) b, c)
#define g3_draw_poly(a,b,c)  g3test_draw_poly(a, b, (g3s_phandle *) c)
#define g3_draw_tluc_poly(a,b,c)  g3_test_draw_tluc_poly(a, b, (g3s_phandle *) c)

#define g3_start_frame()     g3test_start_frame_3d()
#define g3_end_frame()       g3test_end_frame()
#endif

// this is mostly internal
extern void g3test_init_2d(void);

#endif
