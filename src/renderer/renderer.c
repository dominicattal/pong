#include "renderer.h"
#include <glad.h>
#include <stdio.h>
#include <stdlib.h>
#include "vao/vao.h"
#include "shader/shader.h"

Renderer renderer;

static void message_callback();

void renderer_init() {
    glDebugMessageCallback(message_callback, 0);

    renderer.shaders = malloc(NUM_SHADERS * sizeof(Shader));
    renderer.shaders[PADDLE_SHADER] = shader_create("src/renderer/shaders/paddle.vert", "src/renderer/shaders/paddle.frag");
    renderer.shaders[BALL_SHADER]   = shader_create("src/renderer/shaders/ball.vert", "src/renderer/shaders/ball.frag");

    renderer.vaos = malloc(NUM_VAOS * sizeof(VAO));
    renderer.vaos[PADDLE_VAO] = vao_create(GL_DYNAMIC_DRAW, GL_TRIANGLES, 2, TRUE);
    renderer.vaos[BALL_VAO]   = vao_create(GL_DYNAMIC_DRAW, GL_TRIANGLES, 2, TRUE);
    vao_attr(renderer.vaos[PADDLE_VAO], 0, 2, 0);
    vao_attr(renderer.vaos[BALL_VAO]  , 0, 2, 0);
}

void renderer_malloc(u32 vao_idx, u32 vbo_length, u32 ebo_length) {
    vao_malloc(renderer.vaos[vao_idx], vbo_length, ebo_length);
}

void renderer_update(u32 vao_idx, u32 vbo_offset, u32 vbo_length, f32* vbo_buffer, u32 ebo_offset, u32 ebo_length, u32* ebo_buffer) {
    vao_update(renderer.vaos[vao_idx], vbo_offset, vbo_length, vbo_buffer, ebo_offset, ebo_length, ebo_buffer);
}

void renderer_render(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader_use(renderer.shaders[PADDLE_SHADER]);
    vao_draw(renderer.vaos[PADDLE_VAO]);
    shader_use(renderer.shaders[BALL_SHADER]);
    vao_draw(renderer.vaos[BALL_VAO]);
}

void renderer_destroy(void) {
    shader_destroy(renderer.shaders[PADDLE_SHADER]);
    shader_destroy(renderer.shaders[BALL_SHADER]);
    free(renderer.shaders);
    vao_destroy(renderer.vaos[PADDLE_VAO]);
    vao_destroy(renderer.vaos[BALL_VAO]);
    free(renderer.vaos);
    puts("Successfully destroyed renderer");
}

static void GLAPIENTRY message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    fprintf(stderr, "\nGL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n", ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ), type, severity, message);
}