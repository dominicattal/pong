#include "../component.h"
#include "../../../game/game.h"
#include <stdio.h>

void comp_score_player_1_create(Component *comp) {

}

void comp_score_player_1_mouse_button_callback(Component *comp, i32 button, i32 action) {

}

void comp_score_player_1_hover_callback(Component *comp, i32 action) {

}

void comp_score_player_1_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {

}

void comp_score_player_1_update(Component *comp) {
    char score[10];
    sprintf(score, "%d", game.player1_score);
    component_set_text(comp, 28, score);
}

void comp_score_player_1_destroy(Component *comp) {

}