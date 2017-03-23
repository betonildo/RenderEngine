
// Values that stay constant for the whole mesh.
uniform sampler2D spriteTexture;
uniform mat4 MVP;
varying vec2 UV;

void main() {

    gl_FragColor = vec4(1, 0, 1, 1);// texture2D(spriteTexture, UV);
}

