
// Values that stay constant for the whole mesh.
uniform sampler2D spriteTexture;
uniform mat4 MVP;

in vec2 UV;
varying vec4 color;

void main() {

    gl_FragColor = texture2D(spriteTexture, UV).rgba * color;
}

