#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <Windows.h>

#define DEFAULT_GAME_WIDTH 500
#define DEFAULT_GAME_HEIGHT 500

Game game;
f32 game_dt;

static pthread_t thread_id;
static bool kill_thread;
static sem_t mutex;

static void collide(void);

static void* game_update(void* vargp) {
    while (!kill_thread) {
        struct timeval start, end;
        i64 seconds, microseconds;
        
        if (game_dt > 0.0001) {
            gettimeofday(&start, NULL);
            ball_update(game.ball, game_dt);
            paddle_update(game.paddle1, game_dt);
            paddle_update(game.paddle2, game_dt);
            collide();
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
    game.width = DEFAULT_GAME_WIDTH;
    game.height = DEFAULT_GAME_HEIGHT;
    
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

void game_wait(void) {
    sem_wait(&mutex);
}

void game_post(void) {
    sem_post(&mutex);
}

void game_set_paddle_direction(i8 direction) {
    game_wait();
    game.paddle1->direction = direction;
    game_post();
}

static bool collide_paddle_ball(Paddle* paddle, Ball* ball) {
    return ball->position.y < paddle->y + paddle->height
        && ball->position.y + ball->width > paddle->y;
}

void collide(void) {
    if (game.ball->position.x > game.width - game.paddle2->width - game.ball->width) {
        if (!collide_paddle_ball(game.paddle2, game.ball)) {
            puts("+1");
        }
        game.ball->direction.x = -1;
    }
    else if (game.ball->position.x < game.paddle1->width) {
        if (!collide_paddle_ball(game.paddle1, game.ball))
            puts("-1");
        game.ball->direction.x = 1;
    }
}