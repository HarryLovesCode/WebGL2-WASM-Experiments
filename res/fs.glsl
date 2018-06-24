#version 300 es

in lowp vec2 u_pos_vs;
in lowp vec3 u_frag;
in lowp vec3 u_norm;

out lowp vec4 color_out;

uniform sampler2D tex;
uniform lowp vec3 l_pos;
uniform lowp vec3 l_col;
uniform lowp vec3 c_pos;

void main(void)
{
    lowp float ambient_level = 0.1;
    lowp vec3 l_dir = normalize(l_pos - u_frag);
    lowp vec4 ambient = vec4(ambient_level * l_col, 1.0);

    lowp float diff = max(dot(u_norm, l_dir), 0.0);
    lowp vec4 diffuse = vec4(diff * l_col, 1.0);

    lowp vec3 viewDir = normalize(c_pos - u_frag);
    lowp vec3 reflDir = reflect(-l_dir, u_norm);
    lowp float spec = pow(max(dot(viewDir, reflDir), 0.0), 32.0);
    lowp vec4 specular = vec4(0.6 * spec * l_col, 1.0);

    lowp vec4 object = vec4(texture(tex, u_pos_vs).rgb, 1.0);

    color_out = (ambient + diffuse + specular) * object;
}
