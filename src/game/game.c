#include "game.h"
#include <stdio.h>
#include <stdlib.h>

Game game;

void game_init() {
    game.paddle1 = paddle_create();
    game.paddle2 = paddle_create();
    game.ball = ball_create();
}

void game_update() {

}

void game_destroy() {
    free(game.paddle1);
    free(game.paddle2);
    free(game.ball);
    puts("Successfully destroyed game");
}