#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <Windows.h>

#define DEFAULT_GAME_WIDTH 500
#define DEFAULT_GAME_HEIGHT 500
#define RESET_TIME 1.5

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
    game.player1_score = 0;
    game.player2_score = 0;
    
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

void game_set_paddle1_direction(i8 direction) {
    game_wait();
    game.paddle1->direction = direction;
    game_post();
}

void game_set_paddle2_direction(i8 direction) {
    game_wait();
    game.paddle2->direction = direction;
    game_post();
}

static bool collide_paddle1_ball(void) {
    f32 px, py, pw, ph, bx, by, bw, bh;
    px = 0,                     py = game.paddle1->y,       pw = game.paddle1->width, ph = game.paddle1->height;
    bx = game.ball->position.x, by = game.ball->position.y, bw = game.ball->width,    bh = game.ball->width;
    return py <= by + bh && py + ph >= by && px <= bx + bw && px + pw >= bx;
}

static bool collide_paddle2_ball(void) {
    f32 px, py, pw, ph, bx, by, bw, bh;
    px = game.width - game.paddle2->width, py = game.paddle2->y,       pw = game.paddle2->width, ph = game.paddle2->height;
    bx = game.ball->position.x,            by = game.ball->position.y, bw = game.ball->width,    bh = game.ball->width;
    return py <= by + bh && py + ph >= by && px <= bx + bw && px + pw >= bx;
}

void collide(void) {
    if (game.paddle1->y < 0)
        game.paddle1->y = 0;
    if (game.paddle1->y + game.paddle1->height > game.height)
        game.paddle1->y = game.height - game.paddle1->height;
    if (game.paddle2->y < 0)
        game.paddle2->y = 0;
    if (game.paddle2->y + game.paddle2->height > game.height)
        game.paddle2->y = game.height - game.paddle2->height;
    
    if (game.reset_timer > 0)
        return;

    if (collide_paddle1_ball() && game.ball->direction.x < 0) {
        ball_randomize(game.ball);
    }

    if (collide_paddle2_ball() && game.ball->direction.x > 0) {
        ball_randomize(game.ball);
        game.ball->direction.x *= -1;
    }

    if (game.ball->position.y < 0 || game.ball->position.y + game.ball->width > game.height)
        game.ball->direction.y *= -1;

    if (game.ball->position.x < -150 || game.ball->position.x > game.width + 150) {
        ball_randomize(game.ball);
        if (game.ball->position.x > game.width + 150) {
            game.player1_score++;
            game.ball->direction.x *= -1;
        } else {
            game.player2_score++;
        }
        game.ball->position.x = game.width / 2 - game.ball->width / 2;
        game.ball->position.y = game.height / 2 - game.ball->width / 2;
        game.reset_timer = RESET_TIME;
    }
}