
// Values that stay constant for the whole mesh.
uniform sampler2D spriteTexture;
uniform mat4 MVP;
varying vec2 UV;

void main() {

    gl_FragColor = texture(spriteTexture, UV);
}