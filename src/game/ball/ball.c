#include "ball.h"
#include <stdlib.h>

Ball* ball_create(void) {
    Ball* ball = malloc(sizeof(Ball));
    ball->x = 0;
    ball->y = 0.5;
    return ball;
}

void ball_destroy(Ball* ball) {
    free(ball);
}