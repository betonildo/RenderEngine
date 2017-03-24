#version 330

// Values that stay constant for the whole mesh.
uniform mat4 MVP = mat4(1.0);

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

out vec2 UV;
varying vec4 color;

void main() {
    UV = uv;
    color = vec4(position + vec3(0.5, 0.5, 0.5), 1);
    gl_Position = MVP * vec4(position, 1);
}

