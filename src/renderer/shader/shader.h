#ifndef SHADER_H
#define SHADER_H

#include "../../util.h"

#define NUM_SHADERS   2
#define PADDLE_SHADER 0
#define BALL_SHADER   1

typedef struct {
    u32 id;
} Shader;

Shader shader_create(char* vs_path, char* fs_path);
void shader_use(Shader shader);
void shader_destroy(Shader shader);

#endif