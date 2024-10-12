#include "ball.h"
#include <stdlib.h>
#include <stdio.h>

Ball* ball_create(void) {
    Ball* ball = malloc(sizeof(Ball));
    ball->position.x = 250;
    ball->position.y = 250;
    ball->direction.x = 1;
    ball->direction.y = 0;
    ball->width = 10;
    ball->speed = 250;
    return ball;
}

void ball_update(Ball* ball, f32 dt) {
    ball->position.x += ball->direction.x * ball->speed * dt;
}

void ball_destroy(Ball* ball) {
    free(ball);
}