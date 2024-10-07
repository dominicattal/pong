#include "data.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LENGTH 100000

Data data;

static f32 test_data[6] = {
    -0.5, -0.5,
    0.5, -0.5,
    0, 0.5
};

void data_init() {
    data.buffer = malloc(BUFFER_LENGTH * sizeof(f32));
    if (data.buffer == NULL) {
        fprintf(stderr, "Could not allocate buffer memory");
        exit(1);
    }
    renderer_malloc(6);
    renderer_update(0, 6, test_data);
}

void data_destroy() {
    free(data.buffer);
    puts("Successfully destroyed data buffer");
}