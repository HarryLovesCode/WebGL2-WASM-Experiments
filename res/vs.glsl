#version 300 es

uniform mat4 m_proj;
uniform mat4 m_view;
uniform mat4 m_mod;

layout(location=0) in lowp vec3 v_pos;
layout(location=1) in lowp vec3 n_pos;
layout(location=2) in lowp vec3 u_pos;

out lowp vec2 u_pos_vs;

void main(void)
{
	u_pos_vs = u_pos.xy;
    gl_Position = m_proj * m_view * m_mod * vec4(v_pos, 1.0);
}
