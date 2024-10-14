#include "../component.h"
#include "../../../game/game.h"
#include <stdio.h>

void comp_online_create(Component *comp) {

}

void comp_online_mouse_button_callback(Component *comp, i32 button, i32 action) {

}

void comp_online_hover_callback(Component *comp, i32 action) {

}

void comp_online_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {

}

void comp_online_update(Component *comp) {
    char score[10];
    sprintf(score, "%d", game.player2_score);
    component_set_text(comp, 28, score);
}

void comp_online_destroy(Component *comp) {

}