#ifndef PADDLE_H
#define PADDLE_H

#include "../../util.h"

typedef struct {
    f32 y, speed;
    i32 width, height;
    i8 direction;
} Paddle;

Paddle* paddle_create(void);
void paddle_update(Paddle* paddle, f32 dt);
void paddle_destroy(Paddle* paddle);

#endif