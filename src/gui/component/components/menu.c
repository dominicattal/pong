#include "../component.h"

void comp_menu_create(Component *comp) {

}

void comp_menu_mouse_button_callback(Component *comp, i32 button, i32 action) {
    game_stop();

    component_destroy_children(comp_root);

    Component* local = component_create(100, 200, 150, 100, COMP_LOCAL);
    local->a = 0.5;
    local->interactable = TRUE;
    local->alignment.x = ALIGN_CENTER;
    local->alignment.y = ALIGN_CENTER;
    component_set_text(local, 28, "Local");

    Component* lan = component_create(300, 200, 150, 100, COMP_LAN);
    lan->a = 0.5;
    lan->interactable = TRUE;
    lan->alignment.x = ALIGN_CENTER;
    lan->alignment.y = ALIGN_CENTER;
    component_set_text(lan, 28, "LAN");

    Component* exit = component_create(250, 50, 150, 100, COMP_EXIT);
    exit->a = 0.5;
    exit->interactable = TRUE;
    exit->alignment.x = ALIGN_CENTER;
    exit->alignment.y = ALIGN_CENTER;
    component_set_text(exit, 28, "Exit");

    component_attach(comp_root, local);
    component_attach(comp_root, lan);
    component_attach(comp_root, exit);
}

void comp_menu_hover_callback(Component *comp, i32 action) {

}

void comp_menu_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {

}

void comp_menu_update(Component *comp) {

}

void comp_menu_destroy(Component *comp) {

}