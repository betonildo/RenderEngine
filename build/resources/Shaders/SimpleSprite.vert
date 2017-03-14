// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;
varying vec2 UV;

void main() {
    UV = vertexUV;
    gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
}