#include "../component.h"
#include "../../../game/game.h"
#include <stdio.h>

void comp_local_create(Component *comp) {

}

void comp_local_mouse_button_callback(Component *comp, i32 button, i32 action) {
    component_destroy_children(comp_root);

    Component* score1 = component_create(50, 400, 50, 50, COMP_SCORE_PLAYER_1);
    score1->a = 0.5;
    score1->alignment.x = ALIGN_CENTER;
    score1->alignment.y = ALIGN_CENTER;

    Component* score2 = component_create(800-100, 400, 50, 50, COMP_SCORE_PLAYER_2);
    score2->a = 0.5;
    score2->alignment.x = ALIGN_CENTER;
    score2->alignment.y = ALIGN_CENTER;

    Component* pause = component_create(400, 400, 50, 50, COMP_PAUSE);
    pause->a = 0.0;
    pause->interactable = TRUE;

    Component* win = component_create(200, 400, 200, 50, COMP_WIN);
    win->a = 0.0;

    component_attach(comp_root, score1);
    component_attach(comp_root, score2);
    component_attach(comp_root, pause);
    component_attach(comp_root, win);

    game_start();
}

void comp_local_hover_callback(Component *comp, i32 action) {

}

void comp_local_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {
    
}

void comp_local_update(Component *comp) {

}

void comp_local_destroy(Component *comp) {

}