#ifndef CHARACTER_H
#define CHARACTER_H

#include "../../util.h"

#define GLYPH_HEIGHT 7
#define MIN_BEARING_Y -1

typedef struct {
    struct { i8 x, y; } size;
    struct { i8 x, y; } bearing;
    i8 u, v, advance;
    char character;
} Character;

extern Character char_map[128];

void char_map_init(void);

#endif