#ifndef WINDOW_H
#define WINDOW_H

#include "../util.h"
#include <glfw.h>

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 500

typedef struct {
    GLFWwindow* handle;
    struct {
        GLFWcursor *handle;
        vec2 position;
    } cursor;
    i32 width, height;
    f32 last_frame, dt, fps;
} Window;

extern Window window;

void window_init(void);
void window_update(void);
bool window_key_pressed(GLenum key);
void window_close(void);
void window_destroy(void);

#endif