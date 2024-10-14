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

    Component* online = component_create(500, 200, 150, 100, COMP_ONLINE);
    online->a = 0.5;
    online->interactable = TRUE;
    online->alignment.x = ALIGN_CENTER;
    online->alignment.y = ALIGN_CENTER;
    component_set_text(online, 28, "Online");

    component_attach(comp_root, local);
    component_attach(comp_root, lan);
    component_attach(comp_root, online);
}

void comp_menu_hover_callback(Component *comp, i32 action) {

}

void comp_menu_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {

}

void comp_menu_update(Component *comp) {

}

void comp_menu_destroy(Component *comp) {

}