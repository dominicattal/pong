#include "data.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LENGTH 100000

Data data;

static i8 rect_vbo[8] = {
    0, 0,
    1, 0,
    0, 1,
    1, 1
};
static u8 rect_ebo[6] = { 0, 1, 2, 1, 2, 3 };

static void push_paddle_data(Paddle* paddle) {
    for (i32 i = 0; i < 8; i++)
        data.vbo_buffer[i] = rect_vbo[i];
    for (i32 i = 0; i < 6; i++)
        data.ebo_buffer[i] = rect_ebo[i];
}

void data_init() {
    data.vbo_buffer = malloc(BUFFER_LENGTH * sizeof(f32));
    data.ebo_buffer = malloc(BUFFER_LENGTH * sizeof(u32));
    renderer_malloc(8, 6);
}

void data_update() {
    data.vbo_length = data.ebo_length = 0;
    push_paddle_data(game.paddle1);
    renderer_update(0, 8, data.vbo_buffer, 0, 6, data.ebo_buffer);
}

void data_destroy() {
    free(data.vbo_buffer);
    free(data.ebo_buffer);
    puts("Successfully destroyed data buffer");
}