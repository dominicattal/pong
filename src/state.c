#include "state.h"
#include <stdio.h>
#include <stdlib.h>

void state_init(void) {
    window_init();
    renderer_init();
    data_init();
    game_init();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        window_close();
    }
}

void process_input(void) {
    if (window_key_pressed(GLFW_KEY_A))
        puts("Hello");
}

void state_loop(void) {
    while (!glfwWindowShouldClose(window.handle)) {
        process_input();
        data_update();
        window_update();
        renderer_render();
    }
}

void state_destroy(void) {
    window_destroy();
    renderer_destroy();
    data_destroy();
    game_destroy();
}