#include "../component.h"
#include "../../../networking/client/client.h"
#include <stdio.h>

void comp_join_create(Component *comp) {

}

void comp_join_mouse_button_callback(Component *comp, i32 button, i32 action) {
    component_destroy_children(comp_root);
    puts("Joining");
    client_start();
}

void comp_join_hover_callback(Component *comp, i32 action) {

}

void comp_join_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {

}

void comp_join_update(Component *comp) {
}

void comp_join_destroy(Component *comp) {

}