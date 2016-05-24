#include "piano.h"

Piano::Piano(){
    isOpening = false;
    openAngle = 0.0f;
    ShaderProgram* shader = new ShaderProgram((char*)"vshader.txt",NULL,(char*)"fshader.txt");
    pianobox = OBJParser::parseFromFileByName((char *)"models/pianobox.obj", "Cube", shader);
    pianocover = OBJParser::parseFromFileByName((char *)"models/pianobox.obj", "Plane", shader);
}
Piano::Piano(ShaderProgram* shader){
    isOpening = false;
    openAngle = 0.0f;

    pianocover = OBJParser::parseFromFileByName((char *)"models/pianobox.obj", "Plane", shader);
    pianobox = OBJParser::parseFromFileByName((char *)"models/pianobox.obj", "Cube", shader);
    rskey = OBJParser::parseFromFileByName((char *)"models/pianobox.obj", "C_Cube.001", shader);
    bskey = OBJParser::parseFromFileByName((char *)"models/pianobox.obj", "D_Cube.002", shader);
    lskey = OBJParser::parseFromFileByName((char *)"models/pianobox.obj", "E_Cube.003", shader);
    black_key = OBJParser::parseFromFileByName((char *)"models/pianobox.obj", "A#_Cube.013", shader);
}

Piano::~Piano(){
    delete pianobox;
    delete pianocover;
    delete rskey;
    delete bskey;
    delete lskey;
    delete black_key;
}

void Piano::drawObject(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM,glm::vec4 light){
    if(isOpening && openAngle>-maxAngle)
        openAngle -= 0.7*glfwGetTime();
    else if(!isOpening &&openAngle<0)
        openAngle += 0.7*glfwGetTime();

    pianobox->drawModel(mP, mV, mM,light);
    pianocover->drawModel(mP, mV, glm::rotate(mM, openAngle, glm::vec3(1.0f,0,0)),light);
    /*glm::mat4 M2 = glm::translate(M, glm::vec3(0,0.602f,-0.1375f));
    M2 = glm::rotate(M2,openAngle,glm::vec3(1,0,0));

    glLoadMatrixf(glm::value_ptr(V*M2));
    pianocover.drawSolid();
    M2 = glm::translate(M, glm::vec3(-0.71f,0,0));
    drawOctaves(V, M2, 7);
    glLoadMatrixf(glm::value_ptr(V*M));*/
}
float Piano::height(){
    return 1.446f;
}
void Piano::open(){
    isOpening = true;
}
void Piano::close(){
    isOpening = false;
}
void Piano::drawOctaves(glm::mat4 V, glm::mat4 M, int count){
/*    glm::mat4 M2 = M;
    glColor3d(1, 0, 0);
    for(int i=0; i<count;i++){
        //C
        glLoadMatrixf(glm::value_ptr(V*M2));
        keyrs.drawSolid();

        M2 = glm::translate(M2, glm::vec3(0.0147f,0,0));
        //C#
        glLoadMatrixf(glm::value_ptr(V*M2));
        bkey.drawSolid();
        M2 = glm::translate(M2, glm::vec3(0.0147f,0,0));
        //D
        glLoadMatrixf(glm::value_ptr(V*M2));
        keybs.drawSolid();

        M2 = glm::translate(M2, glm::vec3(0.0147f,0,0));
        //D#
        glLoadMatrixf(glm::value_ptr(V*M2));
        bkey.drawSolid();
        M2 = glm::translate(M2, glm::vec3(0.0397f,0,0));
        M2 = glm::scale(M2, glm::vec3(-1,1,1));
        //E
        glLoadMatrixf(glm::value_ptr(V*M2));
        keyrs.drawSolid();

        M2 = glm::scale(M2, glm::vec3(-1,1,1));
        //F
        glLoadMatrixf(glm::value_ptr(V*M2));
        keyrs.drawSolid();

        M2 = glm::translate(M2, glm::vec3(0.0147f,0,0));
        //F#
        glLoadMatrixf(glm::value_ptr(V*M2));
        bkey.drawSolid();
        M2 = glm::translate(M2, glm::vec3(0.0147f,0,0));
        //G
        glLoadMatrixf(glm::value_ptr(V*M2));
        keybs.drawSolid();

        M2 = glm::translate(M2, glm::vec3(0.0147f,0,0));
        //G#
        glLoadMatrixf(glm::value_ptr(V*M2));
        bkey.drawSolid();
        M2 = glm::translate(M2, glm::vec3(0.0147f,0,0));
        //A
        glLoadMatrixf(glm::value_ptr(V*M2));
        keybs.drawSolid();

        M2 = glm::translate(M2, glm::vec3(0.0147f,0,0));
        //A#
        glLoadMatrixf(glm::value_ptr(V*M2));
        bkey.drawSolid();
        M2 = glm::translate(M2, glm::vec3(0.0397f,0,0));
        M2 = glm::scale(M2, glm::vec3(-1,1,1));
        //B
        glLoadMatrixf(glm::value_ptr(V*M2));
        keyrs.drawSolid();
        M2 = glm::scale(M2, glm::vec3(-1,1,1));
*/
    //}
}
