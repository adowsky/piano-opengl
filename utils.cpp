#ifndef UTILS_CPP
#define UTILS_CPP
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FTGL/ftgl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "piano.h"
#include "platform.h"
#include <iostream>
#include "whitekeyrs.h"
#include "lodepng.h"
//Przypisuje bufor VBO do atrybutu
void assignVBOtoAttribute(ShaderProgram *shaderProgram,char* attributeName, GLuint bufVBO, int vertexSize) {
	GLuint location=shaderProgram->getAttribLocation(attributeName); //Pobierz numery slotów dla atrybutu
	glBindBuffer(GL_ARRAY_BUFFER,bufVBO);  //Uaktywnij uchwyt VBO
	glEnableVertexAttribArray(location); //Włącz używanie atrybutu o numerze slotu zapisanym w zmiennej location
	glVertexAttribPointer(location,vertexSize,GL_FLOAT, GL_FALSE, 0, NULL); //Dane do slotu location mają być brane z aktywnego VBO
}
//Tworzy bufor VBO z tablicy
GLuint makeBuffer(void *data, int vertexCount, int vertexSize) {
	GLuint handle;

	glGenBuffers(1,&handle);//Wygeneruj uchwyt na Vertex Buffer Object (VBO), który będzie zawierał tablicę danych
	glBindBuffer(GL_ARRAY_BUFFER,handle);  //Uaktywnij wygenerowany uchwyt VBO
	glBufferData(GL_ARRAY_BUFFER, vertexCount*vertexSize, data, GL_STATIC_DRAW);//Wgraj tablicę do VBO

	return handle;
}
#endif
