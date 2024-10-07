#include "state.h"
#include "data.h"
#include "window/window.h"
#include "renderer/renderer.h"

void state_init(void) {
    window_init();
    renderer_init();
    data_init();
}

void state_loop(void) {
    while (!glfwWindowShouldClose(window.handle)) {
        window_update();
        renderer_render();
    }
}

void state_destroy(void) {
    window_destroy();
    renderer_destroy();
    data_destroy();
}