#ifndef SHADER_H
#define SHADER_H

#include "../../util.h"

typedef struct {
    u32 id;
} Shader;

Shader shader_create(char* vs_path, char* fs_path);
void shader_use(Shader shader);
void shader_destroy(Shader shader);

#endif