#ifndef GAME_H
#define GAME_H

typedef struct {
    int null;
} Game;

extern Game game;

void game_init();
void game_destroy();

#endif