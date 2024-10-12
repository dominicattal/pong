#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <Windows.h>

Game game;
f32 game_dt;

static pthread_t thread_id;
static bool kill_thread;
static sem_t mutex;

static void* game_update(void* vargp) {
    while (!kill_thread) {
        struct timeval start, end;
        i64 seconds, microseconds;
        
        if (game_dt > 0.0001) {
            gettimeofday(&start, NULL);
            game.ball->x += 0.5 * game_dt;
        }
        
        gettimeofday(&end, NULL);
        seconds = end.tv_sec - start.tv_sec;
        microseconds = end.tv_usec - start.tv_usec;
        game_dt = seconds + microseconds*1e-6;
        
    }
}

void game_init(void) {
    game.paddle1 = paddle_create();
    game.paddle2 = paddle_create();
    game.ball = ball_create();
    
    game_dt = 0.001;
    kill_thread = FALSE;
    sem_init(&mutex, 0, 1);
    pthread_create(&thread_id, NULL, game_update, NULL);
}

void game_destroy(void) {
    kill_thread = TRUE;
    pthread_join(thread_id, NULL);
    sem_destroy(&mutex);

    free(game.paddle1);
    free(game.paddle2);
    free(game.ball);
    puts("Successfully destroyed game");
}