#include "../component.h"
#include "../../../game/game.h"
#include <stdio.h>

void comp_lan_create(Component *comp) {

}

void comp_lan_mouse_button_callback(Component *comp, i32 button, i32 action) {
    component_destroy_children(comp_root);

    Component* host = component_create(50, 400, 100, 50, COMP_HOST);
    host->a = 0.5;
    host->interactable = TRUE;
    component_set_text(host, 28, "HOST");

    Component* join = component_create(300, 400, 100, 50, COMP_JOIN);
    join->a = 0.5;
    join->interactable = TRUE;
    component_set_text(join, 28, "JOIN");
    
    component_attach(comp_root, host);
    component_attach(comp_root, join);
}

void comp_lan_hover_callback(Component *comp, i32 action) {

}

void comp_lan_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {

}

void comp_lan_update(Component *comp) {
    
}

void comp_lan_destroy(Component *comp) {

}