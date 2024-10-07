#include "state.h"
#include "window/window.h"

void state_init(void) {
    window_init();
}

void state_loop(void) {
    while (!glfwWindowShouldClose(window.handle)) {
        window_update();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void state_destroy(void) {
    window_destroy();
}