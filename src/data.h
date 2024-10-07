#ifndef DATA_H
#define DATA_H

#include "util.h"
#include "renderer/renderer.h"

typedef struct {
    f32* buffer;
} Data;

extern Data data;

void data_init();
void data_destroy();

#endif