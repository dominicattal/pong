#include "data.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LENGTH 100000

Data data;

static i8 rect[6] = {
    0, 0,
    1, 0,
    0, 1
};

static void push_paddle_data(Paddle* paddle) {
    for (i32 i = 0; i < 6; i++)
        data.buffer[i] = rect[i];
}

void data_init() {
    data.buffer = malloc(BUFFER_LENGTH * sizeof(f32));
    if (data.buffer == NULL) {
        fprintf(stderr, "Could not allocate buffer memory");
        exit(1);
    }
    renderer_malloc(6);
}

void data_update() {
    data.vbo_length = 0;
    push_paddle_data(game.paddle1);
    renderer_update(0, 6, data.buffer);
}

void data_destroy() {
    free(data.buffer);
    puts("Successfully destroyed data buffer");
}