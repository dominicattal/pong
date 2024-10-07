#ifndef VAO_H
#define VAO_H

#include "../vbo/vbo.h"
#include "../../util.h"

typedef struct {
    u32 id, length;
    GLenum usage, mode;
    VBO* vbo;
} VAO;

VAO vao_create(GLenum usage, GLenum mode, u32 length);
void vao_attr(VAO vao, u32 index, u32 length, u32 offset);
void vao_update(VAO vao, u32 vbo_offset, u32 vbo_length, f32* vbo_buffer);
void vao_malloc(VAO vao, u32 vbo_length);
void vao_draw(VAO vao);
void vao_destroy(VAO vao);

#endif