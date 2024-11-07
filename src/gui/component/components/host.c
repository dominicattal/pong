#include "../component.h"
#include "../../../networking/server/server.h"
#include <stdio.h>

void comp_host_create(Component *comp) {

}

void comp_host_mouse_button_callback(Component *comp, i32 button, i32 action) {
    component_destroy_children(comp_root);
    puts("Hosting");
    server_start();
}

void comp_host_hover_callback(Component *comp, i32 action) {

}

void comp_host_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods) {

}

void comp_host_update(Component *comp) {
}

void comp_host_destroy(Component *comp) {

}