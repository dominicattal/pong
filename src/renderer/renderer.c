#include "renderer.h"
#include <glad.h>
#include <stdio.h>
#include <stdlib.h>

Renderer renderer;

static void message_callback();

void renderer_init() {
    glDebugMessageCallback(message_callback, 0);

    renderer.shader = shader_create("src/renderer/shaders/default.vert", "src/renderer/shaders/default.frag");
    renderer.vao = vao_create(GL_STATIC_DRAW, GL_TRIANGLES, 2);
    vao_attr(renderer.vao, 0, 2, 0);
}

void renderer_malloc(u32 vbo_length) {
    vao_malloc(renderer.vao, vbo_length);
}

void renderer_update(u32 vbo_offset, u32 vbo_length, f32* vbo_buffer) {
    vao_update(renderer.vao, vbo_offset, vbo_length, vbo_buffer);
}

void renderer_render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader_use(renderer.shader);
    vao_draw(renderer.vao);
}

void renderer_destroy() {
    vao_destroy(renderer.vao);
    shader_destroy(renderer.shader);
    puts("Successfully destroyed renderer");
}

static void GLAPIENTRY message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    printf("\nGL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n", ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ), type, severity, message);
}