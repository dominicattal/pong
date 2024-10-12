#include "paddle.h"
#include <stdlib.h>

Paddle* paddle_create(void) {
    Paddle* paddle = malloc(sizeof(Paddle));
    paddle->y = 300;
    paddle->speed = 125;
    paddle->direction = 0;
    paddle->width = 5;
    paddle->height = 40;
    return paddle;
}

void paddle_update(Paddle* paddle, f32 dt) {
    paddle->y += paddle->speed * paddle->direction * dt;
}

void paddle_destroy(Paddle* paddle) {
    free(paddle);
}