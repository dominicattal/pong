#ifndef RENDERER_H
#define RENDERER_H

#include "../util.h"
#include "vao/vao.h"
#include "shader/shader.h"

typedef struct {
    Shader shader;
    VAO vao;
} Renderer;

extern Renderer renderer;

void renderer_init(void);
void renderer_malloc(u32 vbo_length);
void renderer_update(u32 vbo_offset, u32 vbo_length, f32* vbo_buffer);
void renderer_render(void);
void renderer_destroy(void);

#endif