#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE
#define GLM_SWIZZLE_FULL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FTGL/ftgl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "lodepng.h"
#include "piano.h"
#include "models/objmodel.h"
#include "objparser.h"
#include "cube.h"
#include "models/shaderprogram.h"
#include "camera.h"
using namespace std;

 float speed;
 float y_axis;
 float x_axis;
 float z_spd;
 const int XWindowSize = 500;
 const int YWindowSize = 500;
 Camera* camera;
 Piano* piano;
 FTGLPixmapFont font("opensans.ttf");
 Models::OBJModel* model;
 glm::vec4 light;
 ShaderProgram* shader;

void key_callback(GLFWwindow* window, int key,
	int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_LEFT) speed = -3.14f;
		if (key == GLFW_KEY_RIGHT) speed = 3.14f;
        if (key == GLFW_KEY_UP) y_axis = 3.14f;
        if (key == GLFW_KEY_DOWN) y_axis = -3.14f;
        if (key == GLFW_KEY_X) x_axis = 3.14f;
        if (key == GLFW_KEY_Z) x_axis = -3.14f;
        if(key == GLFW_KEY_W) camera->moveForward(true);
        if(key == GLFW_KEY_S) camera->moveBack(true);
        if(key == GLFW_KEY_A) camera->moveLeft(true);
        if(key == GLFW_KEY_D) camera->moveRight(true);
        if(key == GLFW_KEY_O) piano->open();
        if(key == GLFW_KEY_C) piano->close();
	}

	if (action == GLFW_RELEASE) {
		if(key == GLFW_KEY_LEFT || key == GLFW_KEY_RIGHT) speed = 0;
        if(key == GLFW_KEY_UP || key == GLFW_KEY_DOWN) y_axis = 0;
        if(key == GLFW_KEY_W) camera->moveForward(false);
        if(key == GLFW_KEY_S) camera->moveBack(false);
        if(key == GLFW_KEY_A) camera->moveLeft(false);
        if(key == GLFW_KEY_D) camera->moveRight(false);
        if (key == GLFW_KEY_X || key == GLFW_KEY_Z) x_axis = 0;
	}
}
void mouse_move_callback(GLFWwindow* window,double x, double y){
    camera->rotate( XWindowSize/2.0f -x,  YWindowSize/2.0f -y);
    glfwSetCursorPos(window,XWindowSize/2.0f, YWindowSize  /2.0f);
}
//Procedura obsługi błędów
void error_callback(int error, const char* description) {
	fputs(description, stderr);

}


//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {
    	glClearColor(1, 1, 1, 1); //Czyść ekran na czarno
    	// glEnable(GL_LIGHTING); //Włącz tryb cieniowania
    	// glEnable(GL_LIGHT0); //Włącz domyslne światło
    	glEnable(GL_DEPTH_TEST); //Włącz używanie Z-Bufora
        //glEnable(GL_BLEND);
    	// glEnable(GL_COLOR_MATERIAL); //glColor3d ma modyfikować własności materiału
    	// glEnable(GL_TEXTURE_2D);
    	glfwSetKeyCallback(window, key_callback);
        glfwSetCursorPosCallback(window, mouse_move_callback);
        glfwSetCursor(window,glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR));
    font.FaceSize(20);
    shader = new ShaderProgram((char*)"vshader.txt",NULL,(char*)"fshader.txt");
	piano = new Piano(shader);
    camera = new Camera();
    light = glm::vec4(0.0f,0.0f,-10.0f,1.0f);
    //model = OBJParser::parseFromFileByName((char *)"models/cube.obj", "Cube",shader);
}

void freeProgram(){
    delete shader;
    //delete model;
    delete piano;
    delete camera;
}
//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window, float angle, float z_pos, float y_axis, float x_axis) {
	//************Tutaj umieszczaj kod rysujący obraz******************l

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //Wykonaj czyszczenie bufora kolorów

	glm::mat4 V =camera->getViewMatrix();

	glm::mat4 P = glm::perspective(50 * PI / 180, 1.0f, 1.0f, 50.0f); //Wylicz macierz rzutowania

	glm::mat4 M = glm::mat4(1.0f);
    M = glm::translate(M, glm::vec3(0.0f,-2.0f,z_pos));
    M = glm::rotate(M,y_axis,glm::vec3(0, 0, 1));
	M = glm::rotate(M, angle, glm::vec3(0, 1, 0));
    M = glm::rotate(M, x_axis, glm::vec3(1, 0, 0));

//    platform.drawSolid();
    M = glm::translate(M, glm::vec3(0.0f,piano->height(),0.0f));
    piano->drawObject(P, V, M,light);
    //model-> drawModel(P,V,M,light);
    glTranslatef(0.0f,0.0f,-1.0f);
    string s = to_string(z_pos);
    font.Render(s.c_str());
	//Przerzuć tylny bufor na przedni
	glfwSwapBuffers(window);


}



int main(void)
{
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(XWindowSize, YWindowSize, "Piano", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

	if (glewInit() != GLEW_OK) { //Zainicjuj bibliotekę GLEW
		fprintf(stderr, "Nie można zainicjować GLEW.\n");
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Operacje inicjujące

	float angle = 0.0f; //Kąt obrotu torusa
    float z_pos = 0.0f;
    float y_angle = 0.0f;
    float x_angle = 0.0f;
	glfwSetTime(0); //Wyzeruj licznik czasu

	//Główna pętla
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
		angle += speed*glfwGetTime(); //Zwiększ kąt o prędkość kątową razy czas jaki upłynął od poprzedniej klatki
        y_angle += y_axis*glfwGetTime();
        x_angle += x_axis*glfwGetTime();
        z_pos += z_spd*glfwGetTime();
        camera->move(glfwGetTime());
		glfwSetTime(0); //Wyzeruj licznik czasu
		drawScene(window,angle, z_pos,y_angle,x_angle); //Wykonaj procedurę rysującą
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}
	freeProgram();
	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}
