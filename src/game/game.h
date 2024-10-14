#ifndef GAME_H
#define GAME_H

#include "paddle/paddle.h"
#include "ball/ball.h"

typedef struct {
    Paddle* paddle1;
    Paddle* paddle2;
    Ball* ball;
    i32 width, height;
    f32 dt, reset_timer;
    i32 player1_score, player2_score;
    bool started, paused;
} Game;

extern Game game;

void game_init(void);
void game_start(void);
void game_stop(void);
bool game_pause(void);
void game_destroy(void);

void game_wait(void);
void game_post(void);

void game_set_paddle1_direction(i8 direction);
void game_set_paddle2_direction(i8 direction);

#endif