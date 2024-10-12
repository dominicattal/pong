#include "data.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LENGTH 100000
#define PADDLE_WIDTH (5.0 / 500)
#define PADDLE_HEIGHT (200.0 / 500)
#define BALL_WIDTH (10.0 / 500)

Data data;

static i8 rect_x[4] = { 0, 1, 0, 1 };
static i8 rect_y[4] = { 0, 0, 1, 1 };
static i8 rect_ebo[6] = { 0, 1, 2, 1, 2, 3 };

static void push_paddle1_data(Paddle* paddle1);
static void push_paddle2_data(Paddle* paddle2);
static void push_ball_data(Ball* ball);

void data_init() {
    data.vbo_buffer = malloc(BUFFER_LENGTH * sizeof(f32));
    data.ebo_buffer = malloc(BUFFER_LENGTH * sizeof(u32));
    renderer_malloc(PADDLE_VAO, 16, 12);
    renderer_malloc(BALL_VAO, 8, 6);
}

void data_update() {
    push_paddle1_data(game.paddle1);
    push_paddle2_data(game.paddle2);
    renderer_update(PADDLE_VAO, 0, 16, data.vbo_buffer, 0, 12, data.ebo_buffer);
    push_ball_data(game.ball);
    renderer_update(BALL_VAO, 0, 8, data.vbo_buffer, 0, 6, data.ebo_buffer);
}

void data_destroy() {
    free(data.vbo_buffer);
    free(data.ebo_buffer);
    puts("Successfully destroyed data buffer");
}

void push_paddle1_data(Paddle* paddle1) {
    for (i32 i = 0; i < 4; i++) {
        data.vbo_buffer[2*i]   = rect_x[i] * PADDLE_WIDTH;
        data.vbo_buffer[2*i+1] = paddle1->y + rect_y[i] * PADDLE_HEIGHT - PADDLE_HEIGHT / 2;
    }
    for (i32 i = 0; i < 6; i++)
        data.ebo_buffer[i] = rect_ebo[i];
}

void push_paddle2_data(Paddle* paddle2) {
    for (i32 i = 0; i < 4; i++) {
        data.vbo_buffer[8+2*i]   = 1 - rect_x[i] * PADDLE_WIDTH;
        data.vbo_buffer[8+2*i+1] = paddle2->y + rect_y[i] * PADDLE_HEIGHT - PADDLE_HEIGHT / 2;
    }
    for (i32 i = 0; i < 6; i++)
        data.ebo_buffer[6+i] = rect_ebo[i] + 4;
}

void push_ball_data(Ball* ball) {
    for (i32 i = 0; i < 4; i++) {
        data.vbo_buffer[2*i]   = ball->x + rect_x[i] * BALL_WIDTH;
        data.vbo_buffer[2*i+1] = ball->y + rect_y[i] * BALL_WIDTH;
    }
    for (i32 i = 0; i < 6; i++)
        data.ebo_buffer[i] = rect_ebo[i];
}
