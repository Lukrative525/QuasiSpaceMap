#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture_coordinates;
layout(location = 2) in vec3 instance_position;
layout(location = 3) in vec2 instance_size;

out vec2 TexCoord;

uniform mat4 model_view_projection;

void main()
{
    vec3 scaled_position = position;
    scaled_position.x *= instance_size.x;
    scaled_position.y *= instance_size.y;

    vec3 world_position = scaled_position + instance_position;

    gl_Position = model_view_projection * vec4(world_position, 1.0);

    TexCoord = texture_coordinates;
}
