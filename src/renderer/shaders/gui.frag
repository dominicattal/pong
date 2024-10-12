# version 460

uniform sampler2D font;

in vec2 texCoord;
in flat vec4 color;

void main()
{
    gl_FragColor = texture(font, texCoord) * vec4(1.0, 1.0, 1.0, 1.0);
}