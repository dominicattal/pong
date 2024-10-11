#include "paddle.h"
#include <stdlib.h>

Paddle* paddle_create(void) {
    Paddle* paddle = malloc(sizeof(Paddle));
    paddle->y = 0.5;
    return paddle;
}

void paddle_destroy(Paddle* paddle) {
    free(paddle);
}