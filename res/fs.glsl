#version 330

in vec2 u_pos_vs;

out vec3 color_out;

uniform sampler2D tex;

void main(void)
{
    color_out = texture(tex, u_pos_vs).rgb;
}
