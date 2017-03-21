// Input vertex data, different for all executions of this shader.
struct SpriteVertex {
    vec3 position;
    vec3 normal;
    vec2 uv;
};


layout(location = 0) in SpriteVertex vertex;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;
varying vec2 UV;

void main() {
    UV = vertex.uv;
    gl_Position = MVP * vec4(vertex.position, 1);
}