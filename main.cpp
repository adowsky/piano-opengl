#define GLM_FORCE_RADIANS
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <dirent.h>
#include "lodepng.h"
#include "piano.h"
#include "models/objmodel.h"
#include "objparser.h"
#include "models/shaderprogram.h"
#include "scene.h"
#include "camera.h"
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
#include "player.h"
#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif

void mySleep(int sleepMs)
{
#ifdef LINUX
    usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
#endif
#ifdef WINDOWS
    Sleep(sleepMs);
#endif
}
using namespace std;

 float speed;
 float y_axis;
 float x_axis;
 float z_spd;
 const int XWindowSize = 500;
 const int YWindowSize = 500;
 Camera* camera;
 Piano* piano;
 Scene* scene;
 Models::OBJModel* model;
 Player* player;
 glm::vec4 light;
 ShaderProgram* shader;
 ShaderProgram* cube;
 float fov = 50.0f;
 float nearPlaneDist = 1.0f;


void key_callback(GLFWwindow* window, int key,
	int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
        if(key == GLFW_KEY_W) camera->moveForward(true);
        if(key == GLFW_KEY_S){
            if((mods & GLFW_MOD_SHIFT)!=0)
                player->stop();
            else  {
                camera->moveBack(true);
            }
        }
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
        if(key == GLFW_KEY_P){
            if((mods & GLFW_MOD_SHIFT)!=0) player->start();
            else  piano->play(9);
        }
        if(key == GLFW_KEY_N) player -> playNext();
        if(key == GLFW_KEY_B) player -> playPrevious();
        if(key == GLFW_KEY_MINUS) piano->play(10);
        if(key == GLFW_KEY_LEFT_BRACKET) piano->play(11);
        if(key == GLFW_KEY_COMMA) piano->octaveDown();
        if(key == GLFW_KEY_PERIOD) piano->octaveUp();
        if(key == GLFW_KEY_UP) player ->channelUp();
        if(key == GLFW_KEY_DOWN)  player ->channelDown();

	}

	if (action == GLFW_RELEASE) {
        if(key == GLFW_KEY_W) camera->moveForward(false);
        if((key == GLFW_KEY_S) && (mods & GLFW_MOD_SHIFT)==0) camera->moveBack(false);
        if(key == GLFW_KEY_A) camera->moveLeft(false);
        if(key == GLFW_KEY_D) camera->moveRight(false);
	}
}
void mouse_move_callback(GLFWwindow* window,double x, double y){
    camera->rotate( XWindowSize/2.0f -x,  YWindowSize/2.0f -y);
}
//Procedura obsługi błędów
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}
void load_list_of_midi_files(vector<char*>& v){
    DIR* dir;
    struct dirent * dirent;
    dir = opendir("./midi/");
    int  midiLen = strlen("./midi/");
    if(dir != NULL){
        while((dirent = readdir(dir))){
            if(strlen(dirent->d_name)<=2)
                continue;
            char* s = new char[midiLen + strlen(dirent->d_name) + 1];
            strcpy(s, "./midi/");
            strcat(s,dirent->d_name);
            v.push_back(s);
        }
        closedir(dir);
    }
}
void free_list_of_midi_files(vector<char*>& v){
    for(auto& c : v){
        delete[] c;
    }
}
//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {
    	glClearColor(0, 0, 0, 1); //Czyść ekran na czarno
    	glEnable(GL_DEPTH_TEST); //Włącz używanie Z-Bufora
        glEnable(GL_MULTISAMPLE);
    	glfwSetKeyCallback(window, key_callback);
        glfwSetCursorPosCallback(window, mouse_move_callback);
        glfwSetCursor(window,glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR));
        glHint(	GL_POLYGON_SMOOTH_HINT,GL_NICEST);
    cube = new ShaderProgram((char*)"sshaderv.txt",NULL,(char*)"sshaderf.frag");
    shader = new ShaderProgram((char*)"vshader.txt",NULL,(char*)"fshader.txt");
	piano = new Piano(shader);
    camera = new Camera (0,0,-10.0f);
    scene = new Scene(cube);
    std::vector<char*> v;
    load_list_of_midi_files(v);
    player = new Player(v,piano);
    free_list_of_midi_files(v);
    light = glm::vec4(-5.0f,10.0f,10.0f,1.0f);
}

void freeProgram(){
    delete shader;
    delete cube;
    delete piano;
    delete camera;
    delete scene;
    delete player;
}

//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window, float angle, float z_pos, float y_axis, float x_axis,float fps) {
	//************Tutaj umieszczaj kod rysujący obraz******************l

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //Wykonaj czyszczenie bufora kolorów
	glm::mat4 V =camera->getViewMatrix();
    glm::mat4 P = glm::perspective(fov * PI / 180, YWindowSize/(float)XWindowSize, nearPlaneDist, 50.0f); //Wylicz macierz rzutowania
	glm::mat4 M = glm::mat4(1.0f);
    piano->drawObject(P, V, M,light);
    scene->drawObject(P, V, M,light);
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
glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API );
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
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
	float angle = 0.0f; //Kąt obrotu torusa
    float z_pos = 0.0f;
    float y_angle = 0.0f;
    float x_angle = 0.0f;

	glfwSetTime(0); //Wyzeruj licznik czasu
    double lastTime = glfwGetTime();
    int nbFrames = 0;
    double currTime = lastTime;
    float fps =0.0f;
	//Główna pętla
    double timer = 0;
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{  currTime += glfwGetTime();
        if ( currTime - lastTime >= 1.0 ){

         fps = float(nbFrames)/float(currTime - lastTime );
         nbFrames = 0;
         lastTime += 1.0;
     }
        player->tick(timer);
        timer = glfwGetTime();
		angle += speed*timer; //Zwiększ kąt o prędkość kątową razy czas jaki upłynął od poprzedniej klatki
        y_angle += y_axis*timer;
        x_angle += x_axis*timer;
        z_pos += z_spd*timer;
        camera->move(timer);
		glfwSetTime(0); //Wyzeruj licznik czasu
		drawScene(window,angle, z_pos,y_angle,x_angle,fps); //Wykonaj procedurę rysującą
        glfwSetCursorPos(window,XWindowSize/2.0f, YWindowSize  /2.0f);
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
}
	freeProgram();
	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
    alutExit();
	exit(EXIT_SUCCESS);
}
