#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <Windows.h>

#define DEFAULT_GAME_WIDTH 500
#define DEFAULT_GAME_HEIGHT 500
#define RESET_TIME 3

Game game;

static pthread_t thread_id;
static bool kill_thread;
static sem_t mutex;

static void collide(void);

static void* game_update(void* vargp) {
    while (!kill_thread) {
        struct timeval start, end;
        i64 seconds, microseconds;
        
        if (game.dt > 0.0001) {
            gettimeofday(&start, NULL);

            if (game.reset_timer > 0)
                game.reset_timer -= game.dt;
            else
                ball_update(game.ball, game.dt);

            paddle_update(game.paddle1, game.dt);
            paddle_update(game.paddle2, game.dt);
            collide();
        }
        
        gettimeofday(&end, NULL);
        seconds = end.tv_sec - start.tv_sec;
        microseconds = end.tv_usec - start.tv_usec;
        game.dt = seconds + microseconds*1e-6;
        
    }
}

void game_init(void) {
    game.paddle1 = paddle_create();
    game.paddle2 = paddle_create();
    game.ball = ball_create();
    game.width = DEFAULT_GAME_WIDTH;
    game.height = DEFAULT_GAME_HEIGHT;
    game.dt = 0.001;
    game.reset_timer = 0;
    
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
    if (game.paddle1->y < 0)
        game.paddle1->y = 0;
    if (game.paddle1->y + game.paddle1->height > game.height)
        game.paddle1->y = game.height - game.paddle1->height;
    
    if (game.reset_timer > 0)
        return;

    if (game.ball->position.y < 0 || game.ball->position.y + game.ball->width > game.height)
        game.ball->direction.y *= -1;
    if (game.ball->position.x > game.width - game.paddle2->width - game.ball->width) {
        if (!collide_paddle_ball(game.paddle2, game.ball)) {
            puts("+1");
            game.ball->position.x = game.width / 2 - game.ball->width / 2;
            game.ball->position.y = game.height / 2 - game.ball->width / 2;
            game.reset_timer = RESET_TIME;
        }
        ball_randomize_direction(game.ball);
        game.ball->direction.x *= -1;
    }
    else if (game.ball->position.x < game.paddle1->width) {
        if (!collide_paddle_ball(game.paddle1, game.ball)) {
            puts("-1");
            game.ball->position.x = game.width / 2 - game.ball->width / 2;
            game.ball->position.y = game.height / 2 - game.ball->width / 2;
            game.reset_timer = RESET_TIME;
        } 
        ball_randomize_direction(game.ball);
    }
}