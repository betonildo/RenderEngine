#version 130
uniform mat4 MVP = mat4(1.0);
attribute vec3 position;
attribute vec3 normal;
attribute vec2 uv;

varying vec2 UV;
varying vec4 color;

void main() {
    UV = uv;
    color = vec4(position + vec3(0.5, 0.5, 0.5), 1);
    gl_Position = MVP * vec4(position, 1);
}