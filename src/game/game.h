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
extern f32 game_dt;

void game_init(void);
void game_destroy(void);

#endif