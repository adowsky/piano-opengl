#version 330 core

in vec3 tex;
out vec4 pixelColor;

uniform samplerCube cubeMap;

void main(void){
    pixelColor = texture(cubeMap,tex);
}
