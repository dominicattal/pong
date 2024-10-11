#ifndef PADDLE_H
#define PADDLE_H

#include "../../util.h"

typedef struct {
    f32 y;
} Paddle;

Paddle* paddle_create(void);
void paddle_destroy(Paddle* paddle);

#endif