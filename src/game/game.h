#ifndef GAME_H
#define GAME_H

#include "paddle/paddle.h"
#include "ball/ball.h"

typedef struct {
    Paddle* paddle1;
    Paddle* paddle2;
    Ball* ball;
} Game;

extern Game game;

void game_init();
void game_update();
void game_destroy();

#endif