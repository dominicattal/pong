#ifndef DATA_H
#define DATA_H

#include "util.h"
#include "window/window.h"
#include "renderer/renderer.h"
#include "game/game.h"

typedef struct {
    f32* vbo_buffer;
    u32* ebo_buffer;
    u32 vbo_length, ebo_length;
    bool initialized;
} Data;

extern Data data;

void data_init(void);
void data_update(void);
void data_destroy(void);

#endif