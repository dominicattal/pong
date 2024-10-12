#ifndef WINDOW_H
#define WINDOW_H

#include "../util.h"
#include <glfw.h>

typedef struct {
    GLFWwindow* handle;
    f32 last_frame, dt, fps;
} Window;

extern Window window;

void window_init(void);
void window_update(void);
bool window_key_pressed(GLenum key);
void window_close(void);
void window_destroy(void);

#endif