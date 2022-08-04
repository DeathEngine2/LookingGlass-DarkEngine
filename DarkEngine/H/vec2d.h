#ifndef __VEC2D_H
#define __VEC2D_H

#include <fix.h>

typedef struct vec2d {
   fix x,y;
} vec2d;

// v1 + v2
void vec2d_add(vec2d *dest,vec2d *v1,vec2d *v2);

// v1 - v2
void vec2d_sub(vec2d *dest,vec2d *v1,vec2d *v2);

void vec2d_scale(vec2d *v1,vec2d *v2,fix s);

// v1 cross
fix  vec2d_cross(vec2d *v1,vec2d *v2);

fix vec2d_dot(vec2d *v1,vec2d *v2);


#endif // vec2d
