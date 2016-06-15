#pragma once
#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>
#include "models/shaderprogram.h"
#include <ft2build.h>
#include FT_FREETYPE_H  
#include <stdio.h>

struct Character {
	GLuint     TextureID;  // ID handle of the glyph texture
	glm::ivec2 Size;       // Size of glyph
	glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
	GLuint     Advance;    // Offset to advance to next glyph
};


class TextRenderer {
	GLuint VAO, VBO, texture;
	ShaderProgram* shader;
	std::map<GLchar, Character> Characters;
	int X, Y, height;
public:
	TextRenderer(char* font, int x, int y, int height);
	virtual ~TextRenderer();
	void renderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color, glm::mat4 mP);
	int countMessageWidth(std::string msg, int scale);
	int getCharacterHeight();

};

#endif

