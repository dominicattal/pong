#include "../component.h"
#include "../../../game/game.h"

static void create_pause_menu(Component* comp) {
    Component* menu = component_create(250, 250, 100, 100, COMP_MENU);
    menu->relative = FALSE;
    menu->interactable = TRUE;
    menu->alignment.x = ALIGN_CENTER;
    menu->alignment.y = ALIGN_CENTER;
    menu->a = 0.5;
    component_set_text(menu, 28, "Exit");
    component_attach(comp, menu);
}

void comp_pause_create(Component *comp) {

}

void comp_pause_mouse_button_callback(Component *comp, i32 button, i32 action) {

}

void comp_pause_hover_callback(Component *comp, i32 action) {

}

void comp_pause_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        if (game_pause())
            create_pause_menu(comp);
        else
            component_destroy_children(comp);
    }
}

void comp_pause_update(Component *comp) {
    
}

void comp_pause_destroy(Component *comp) {

}