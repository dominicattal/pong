#include "../component.h"
#include "../../../game/game.h"

void victory_screen(Component* comp) {
    if (comp->text != NULL)
        return;

    game_stop();
    component_set_text(comp, 28, (game.player1_score == GAME_MAX_SCORE) ? "Player1 wins" : "Player2 wins");

    Component* menu = component_create(250, 250, 100, 100, COMP_MENU);
    menu->relative = FALSE;
    menu->interactable = TRUE;
    menu->alignment.x = ALIGN_CENTER;
    menu->alignment.y = ALIGN_CENTER;
    menu->a = 0.5;
    component_set_text(menu, 28, "Exit");
    component_attach(comp_root, menu);
}

void comp_win_create(Component *comp) {

}

void comp_win_mouse_button_callback(Component *comp, i32 button, i32 action) {

}

void comp_win_hover_callback(Component *comp, i32 action) {

}

void comp_win_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {

}

void comp_win_update(Component *comp) {
    if (game.player1_score == GAME_MAX_SCORE || game.player2_score == GAME_MAX_SCORE)
        victory_screen(comp);
}

void comp_win_destroy(Component *comp) {

}