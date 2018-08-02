#version 410 core
layout (location = 0) in vec3 position;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main (){
    gl_Position = projection * model * view * vec4(position,1.0f);
}