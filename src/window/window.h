#ifndef WINDOW_H
#define WINDOW_H

#include <glad.h>
#include <glfw.h>

typedef struct {
    GLFWwindow* handle;
} Window;

extern Window window;

void window_init(void);
void window_update(void);
void window_destroy(void);

#endif