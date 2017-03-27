uniform sampler2D spriteTexture;
uniform mat4 MVP;
varying vec2 UV;
varying vec4 color;

void main() {

    gl_FragColor = color; //texture2D(spriteTexture, UV).rgba *
}