#ifndef RENDERER_H
#define RENDERER_H

#include "../util.h"
#include "vao/vao.h"
#include "shader/shader.h"

typedef struct {
    Shader* shaders;
    VAO* vaos;
} Renderer;

extern Renderer renderer;

void renderer_init(void);
void renderer_malloc(u32 vao_idx, u32 vbo_length, u32 ebo_length);
void renderer_update(u32 vao_idx, u32 vbo_offset, u32 vbo_length, f32* vbo_buffer, u32 ebo_offset, u32 ebo_length, u32* ebo_buffer);
void renderer_render(void);
void renderer_destroy(void);

#endif