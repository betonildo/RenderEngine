#version 330

// Values that stay constant for the whole mesh.
uniform mat4 MVP;
varying vec2 UV;

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;
    
void main() {
    UV = uv;
    gl_Position = vec4(position, 1);
}

