#include "window.h"
#include <stdio.h>
#include <stdlib.h>
#include <glad.h>

#define DEFAULT_WINDOW_WIDTH 500
#define DEFAULT_WINDOW_HEIGHT 500

Window window;

static void error_callback();
extern void key_callback();

void window_init(void) {
    glfwSetErrorCallback(error_callback);
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window.handle = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "pong", NULL, NULL);

    glfwSetKeyCallback(window.handle, key_callback);

    glfwMakeContextCurrent(window.handle);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
}

void window_update(void) {
    glfwPollEvents();
    glfwSwapBuffers(window.handle);
}

bool window_key_pressed(GLenum key) { return glfwGetKey(window.handle, key) == GLFW_PRESS; }

void window_close(void) {
    glfwSetWindowShouldClose(window.handle, 1);
}

void window_destroy(void) {
    glfwTerminate();
    puts("Successfully destroyed window");
}



static void error_callback(int code, const char* desc) {
    fprintf(stderr, "GLFW error 0x%08X: %s\n", code, desc);
}
