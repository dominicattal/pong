#ifndef COMPONENT_H
#define COMPONENT_H

#include "../../util.h"
#include "../../window/window.h"
#include "../../game/game.h"
#include "../../audio/audio.h"
#include "character.h"

#define ALIGN_LEFT   0
#define ALIGN_TOP    0
#define ALIGN_RIGHT  1
#define ALIGN_DOWN   1
#define ALIGN_CENTER 2
#define JUSTIFY      3

typedef struct Component Component;

typedef struct Component {
    i32 x, y, w, h;
    f32 r, g, b, a;
    Component **children;
    u32 num_children, id, font_size;
    struct {
        u8 x, y;
    } alignment;
    bool interactable, hoverable, hovered, relative, update_children;
    char* text;
} Component;

extern Window window;
extern Component *comp_root;

Component* component_create(i32 x, i32 y, i32 w, i32 h, u32 id);
void component_attach(Component *parent, Component *child);
void component_detach(Component *parent, Component *child);
void component_destroy(Component *comp);
void component_detach_and_destroy(Component *comp, Component *child);
void component_destroy_children(Component *comp);

bool component_input_paused(void);
void component_pause_input(Component *comp, bool val);
void component_set_text(Component *comp, u8 font_size, char *text);
void component_remove_text(Component *comp);
void component_mouse_button_callback(Component *comp, i32 button, i32 action);
void component_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods);
void component_update(Component *comp);
void component_hover_callback(Component *comp, i32 action);

#define HOVER_OFF 0
#define HOVER_ON  1

#define COMP_DEFAULT 0
#define COMP_SCORE_PLAYER_1 1
#define COMP_SCORE_PLAYER_2 2
#define COMP_LOCAL 3
#define COMP_LAN 4
#define COMP_ONLINE 5
#define COMP_PAUSE 6
#define COMP_MENU 7

#define _COMP_INIT(_ltype) \
    void comp_##_ltype##_create(Component *comp); \
    void comp_##_ltype##_mouse_button_callback(Component *comp, i32 button, i32 action); \
    void comp_##_ltype##_hover_callback(Component *comp, i32 action); \
    void comp_##_ltype##_key_callback(Component *comp, i32 key, i32 scancode, i32 action, i32 mods); \
    void comp_##_ltype##_update(Component *comp); \
    void comp_##_ltype##_destroy(Component *comp);

_COMP_INIT(score_player_1)
_COMP_INIT(score_player_2)
_COMP_INIT(local)
_COMP_INIT(lan)
_COMP_INIT(online)
_COMP_INIT(pause)
_COMP_INIT(menu)

#endif