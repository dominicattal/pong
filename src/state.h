#ifndef STATE_H
#define STATE_H

#include "data.h"
#include "window/window.h"
#include "renderer/renderer.h"
#include "game/game.h"
#include "gui/gui.h"

void state_init(void);
void state_loop(void);
void state_destroy(void);

#endif