#define GLM_FORCE_RADIANS
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FTGL/ftgl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "lodepng.h"
#include "piano.h"
#include "models/objmodel.h"
#include "objparser.h"
#include "cube.h"
#include "models/shaderprogram.h"
#include "camera.h"
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
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
 float fov = 50.0f;
 float nearPlaneDist = 1.0f;


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
        if(key == GLFW_KEY_V) piano->open();
        if(key == GLFW_KEY_C) piano->close();

        if(key == GLFW_KEY_T) piano->play(0);
        if(key == GLFW_KEY_6) piano->play(1);
        if(key == GLFW_KEY_Y) piano->play(2);
        if(key == GLFW_KEY_7) piano->play(3);
        if(key == GLFW_KEY_U) piano->play(4);
        if(key == GLFW_KEY_I) piano->play(5);
        if(key == GLFW_KEY_9) piano->play(6);
        if(key == GLFW_KEY_O) piano->play(7);
        if(key == GLFW_KEY_0) piano->play(8);
        if(key == GLFW_KEY_P) piano->play(9);
        if(key == GLFW_KEY_MINUS) piano->play(10);
        if(key == GLFW_KEY_LEFT_BRACKET) piano->play(11);
        if(key == GLFW_KEY_COMMA) piano->octaveDown();
        if(key == GLFW_KEY_PERIOD) piano->octaveUp();
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
    	glClearColor(0, 0, 0, 1); //Czyść ekran na czarno
    	glEnable(GL_DEPTH_TEST); //Włącz używanie Z-Bufora
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_CULL_FACE);
        //glEnable(GL_BLEND);
        //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    	// glEnable(GL_TEXTURE_2D);
    	glfwSetKeyCallback(window, key_callback);
        glfwSetCursorPosCallback(window, mouse_move_callback);
        glfwSetCursor(window,glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR));
        glHint(	GL_POLYGON_SMOOTH_HINT,GL_NICEST);
    font.FaceSize(20);
    shader = new ShaderProgram((char*)"vshader.txt",NULL,(char*)"fshader.txt");
	piano = new Piano(shader);
    camera = new Camera ();
    light = glm::vec4(0.0f,2.0f,-5.0f,1.0f);
}

void freeProgram(){
    delete shader;
    delete piano;
    delete camera;
}

//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window, float angle, float z_pos, float y_axis, float x_axis,float fps) {
	//************Tutaj umieszczaj kod rysujący obraz******************l

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //Wykonaj czyszczenie bufora kolorów

	glm::mat4 V =camera->getViewMatrix();
    glm::mat4 P = glm::perspective(fov * PI / 180, YWindowSize/(float)XWindowSize, nearPlaneDist, 50.0f); //Wylicz macierz rzutowania
	glm::mat4 M = glm::mat4(1.0f);
    piano->drawObject(P, V, M,light);
    glTranslatef(0.0f,YWindowSize,-1.0f);
    string s = to_string(fps) + " FPS";
    font.Render(s.c_str());
	//Przerzuć tylny bufor na przedni
	glfwSwapBuffers(window);


}



int main(void)
{
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów
    glewExperimental = GL_TRUE;
	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

glfwWindowHint(GLFW_SAMPLES, 4);

	window = glfwCreateWindow(XWindowSize, YWindowSize, "Piano", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

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
    if(!alutInit(0, NULL)){
        printf("Alut init error!\n");
    }
    alGetError();
	initOpenGLProgram(window); //Operacje inicjujące
    ALuint buffer, source;
     ALint state;


     buffer = alutCreateBufferFromFile("majesty.wav");
     alGenSources(1, &source);
     alSourcei(source, AL_BUFFER, buffer);

	float angle = 0.0f; //Kąt obrotu torusa
    float z_pos = 0.0f;
    float y_angle = 0.0f;
    float x_angle = 0.0f;

	glfwSetTime(0); //Wyzeruj licznik czasu
    double lastTime = glfwGetTime();
    int nbFrames = 0;
    double currTime = lastTime;
    float fps =0.0f;
    //alSourcePlay(source);
	//Główna pętla
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{  currTime += glfwGetTime();
        if ( currTime - lastTime >= 1.0 ){

         fps = float(nbFrames)/float(currTime - lastTime );
         nbFrames = 0;
         lastTime += 1.0;
     }
        if(nbFrames<121){
        nbFrames++;

		angle += speed*glfwGetTime(); //Zwiększ kąt o prędkość kątową razy czas jaki upłynął od poprzedniej klatki
        y_angle += y_axis*glfwGetTime();
        x_angle += x_axis*glfwGetTime();
        z_pos += z_spd*glfwGetTime();
        camera->move(glfwGetTime());
		glfwSetTime(0); //Wyzeruj licznik czasu
        alGetSourcei(source, AL_SOURCE_STATE, &state);

		drawScene(window,angle, z_pos,y_angle,x_angle,fps); //Wykonaj procedurę rysującą

		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
    }
	}
	freeProgram();
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW

    alutExit();
	exit(EXIT_SUCCESS);
}
