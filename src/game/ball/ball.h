#ifndef BALL_H
#define BALL_H

#include "../../util.h"

typedef struct {
    f32 speed;
    i32 width;
    vec2 position, direction;
} Ball;

Ball* ball_create(void);
void ball_update(Ball* ball, f32 dt);
void ball_destroy(Ball* ball);
void ball_randomize(Ball* ball);

#endif