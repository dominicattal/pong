#version 460 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec4 aColor;
layout (location = 3) in float aUseTex;

out vec2 texCoord;
out flat vec4 color;
out flat int use_tex;

void main()
{
    gl_Position = vec4(aPos, 0.0f, 1.0f);
    texCoord = aTexCoord;
    color = aColor;
    use_tex = int(round(aUseTex));
}