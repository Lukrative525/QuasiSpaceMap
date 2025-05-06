#version 330 core

in vec2 tex_coord;
in float frag_alpha;

out vec4 frag_color;

uniform sampler2D texture_map;

void main()
{
    vec4 tex_color = texture(texture_map, tex_coord);
    frag_color = vec4(tex_color.rgb, tex_color.a * frag_alpha);
}
