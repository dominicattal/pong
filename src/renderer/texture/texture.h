#ifndef TEXTURE_H
#define TEXTURE_H

#include <stb_image.h>
#include "../../util.h"

#define NUM_SAMPLES 4

typedef struct {
    u32 id;
} Texture;

Texture texture_create(const char* image_path);
void texture_bind(Texture texture);
void texture_destroy(Texture texture);

#endif