#ifndef BALL_H
#define BALL_H

#include "../../util.h"

typedef struct {
    f32 x, y;
} Ball;

Ball* ball_create(void);
void ball_destroy(Ball* ball);

#endif