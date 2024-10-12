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
    i32 move_direction1 = 0, move_direction2 = 0;
    if (window_key_pressed(GLFW_KEY_W))
        move_direction1++;
    if (window_key_pressed(GLFW_KEY_S))
        move_direction1--;
    if (window_key_pressed(GLFW_KEY_UP))
        move_direction2++;
    if (window_key_pressed(GLFW_KEY_DOWN))
        move_direction2--;
    game_set_paddle1_direction(move_direction1);
    game_set_paddle2_direction(move_direction2);
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