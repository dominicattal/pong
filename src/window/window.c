#include "window.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_WINDOW_WIDTH 500
#define DEFAULT_WINDOW_HEIGHT 500

// global window
Window window;

void error_callback(int code, const char* desc) {
    fprintf(stderr, "GLFW error 0x%08X: %s\n", code, desc);
    exit(1);
}

void window_init(void) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwSetErrorCallback(error_callback);

    window.handle = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "pong", NULL, NULL);
    glfwMakeContextCurrent(window.handle);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
}

void window_update(void) {
    glfwPollEvents();
    glfwSwapBuffers(window.handle);
}

void window_destroy(void) {
    glfwSetWindowShouldClose(window.handle, 1);
    glfwTerminate();
    puts("Successfully destroyed window");
}