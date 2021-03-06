
#version 410 core
layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

out vec2 TexCoords;
out vec4 ParticleColor;

uniform mat4 projection;
uniform vec2 offset;
uniform vec4 color;
uniform mat4 model;

void main()
{
    float scale = 0.2f;
    TexCoords = vertex.xy;
    ParticleColor = color;
    gl_Position = projection * model * vec4((vertex.xy * scale) + offset, 0.0, 1.0);
}
