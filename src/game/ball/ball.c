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
    ball->speed = 500;
    return ball;
}

void ball_update(Ball* ball, f32 dt) {
    ball->position.x += ball->direction.x * ball->speed * dt;
    ball->position.y += ball->direction.y * ball->speed * dt;
}

void ball_destroy(Ball* ball) {
    free(ball);
}

void ball_randomize_direction(Ball* ball) {
    ball->direction.x = (f32) rand() / (2 * RAND_MAX) + 0.5;
    ball->direction.y = (ball->direction.y >= 0 ? 1 : -1) * (1 - ball->direction.x * ball->direction.x);
}