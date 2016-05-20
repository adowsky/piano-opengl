#include "piano.h"

Piano::Piano(){
    isOpening = false;
    openAngle = 0.0f;
}

Piano::~Piano(){

}

void Piano::drawObject(glm::mat4 V, glm::mat4 M){
    pianobox.drawSolid();
    glm::mat4 M2 = glm::translate(M, glm::vec3(0,0.602f,-0.1375f));
    if(isOpening && openAngle>-maxAngle)
        openAngle -= 0.7*glfwGetTime();
    else if(!isOpening &&openAngle<0)
        openAngle += 0.7*glfwGetTime();
    M2 = glm::rotate(M2,openAngle,glm::vec3(1,0,0));

    glLoadMatrixf(glm::value_ptr(V*M2));
    pianocover.drawSolid();
    M2 = glm::translate(M, glm::vec3(-0.71f,0,0));
    drawOctaves(V, M2, 7);
    glLoadMatrixf(glm::value_ptr(V*M));
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
    Models::WhiteKeyBS keybs;
    Models::WhiteKeyRS keyrs;
    Models::BlackKey bkey;
    glm::mat4 M2 = M;
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

    }
}
