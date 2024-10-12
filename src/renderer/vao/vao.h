#ifndef VAO_H
#define VAO_H

#include "../vbo/vbo.h"
#include "../ebo/ebo.h"
#include "../../util.h"

#define NUM_VAOS   3
#define PADDLE_VAO 0
#define BALL_VAO   1
#define GUI_VAO    2

typedef struct {
    u32 id, length;
    GLenum usage, mode;
    VBO* vbo;
    EBO* ebo;
} VAO;

VAO vao_create(GLenum usage, GLenum mode, u32 length, bool use_ebo);
void vao_attr(VAO vao, u32 index, u32 length, u32 offset);
void vao_update(VAO vao, u32 vbo_offset, u32 vbo_length, f32* vbo_buffer, u32 ebo_offset, u32 ebo_length, u32* ebo_buffer);
void vao_malloc(VAO vao, u32 vbo_length, u32 ebo_length);
void vao_draw(VAO vao);
void vao_destroy(VAO vao);

#endif