# version 460

uniform sampler2D font;

in vec2 texCoord;
in flat vec4 color;
in flat int use_tex;

void main()
{
    if (use_tex > 0)
        gl_FragColor = texture(font, texCoord) * color;
    else
        gl_FragColor = color;
}