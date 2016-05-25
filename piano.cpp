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
    pianobox = OBJParser::parseFromFileByName((char *)"models/pianobox.obj", "Cube", shader);
    pianocover = OBJParser::parseFromFileByName((char *)"models/pianocover.obj", "Plane", shader);
    rskey = OBJParser::parseFromFileByName((char *)"models/rskey.obj", "C_Cube.001", shader);
    rskey->fillWithColor(1.0f, 1.0f, 1.0f, 1.0f);
    bskey = OBJParser::parseFromFileByName((char *)"models/bskey.obj", "D_Cube.002", shader);
    bskey->fillWithColor(1.0f, 1.0f, 1.0f, 1.0f);
    lskey = OBJParser::parseFromFileByName((char *)"models/lskey.obj", "E_Cube.003", shader);
    lskey->fillWithColor(1.0f, 1.0f, 1.0f, 1.0f);
    black_key = OBJParser::parseFromFileByName((char *)"models/blackkey.obj", "C#_Cube.009", shader);
    black_key->fillWithColor(0.0f, 0.0f, 0.0f, 1.0f);
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

    glm::mat4 M = glm::translate(mM,glm::vec3(pianobox->getXmin(),pianobox->getYmax(),0));
     M = glm::rotate(M, -openAngle, glm::vec3(1.0f,0,0));
    pianocover->drawModel(mP, mV,M ,light);
    drawOctaves( mP, mV, glm::translate(mM,glm::vec3(-pianobox->getXmin()-1.5*rskey->getWidth(),0,-pianobox->getLength()*0.6f)), light, 3);
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
void Piano::drawOctaves(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM,glm::vec4 light, int count){
    glm::mat4 M2 = mM;
    float translation;
    for(int i=0; i<count;i++){
        rskey->drawModel(mP,mV,M2,light);

        translation = 1.1*rskey->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        bskey->drawModel(mP,mV,M2,light);

        translation = 1.1*bskey->getWidth();
        M2 = glm::translate(M2,glm::vec3(- translation,0,0));
        lskey->drawModel(mP,mV,M2,light);

        translation = 1.1*lskey->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        rskey->drawModel(mP,mV,M2,light);

        translation = 1.1*rskey->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        bskey->drawModel(mP,mV,M2,light);

        translation = 1.1*bskey->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        bskey->drawModel(mP,mV,M2,light);

        translation = 1.1*bskey->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        lskey->drawModel(mP,mV,M2,light);
        
        translation = 1.1*lskey->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
    }
    M2 = mM;
    for(int i=0; i<count;i++){
        translation = 2.2*rskey->getWidth()/3;
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        black_key->drawModel(mP,mV,M2,light);

        translation = bskey->getWidth()/3+ black_key->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        black_key->drawModel(mP,mV,M2,light);

        translation = 2.2*lskey->getWidth()/3 + 2*rskey->getWidth()/3 + black_key->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        black_key->drawModel(mP,mV,M2,light);

        translation = 1.1*bskey->getWidth()/3+ black_key->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        black_key->drawModel(mP,mV,M2,light);

        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
        black_key->drawModel(mP,mV,M2,light);

        translation = 2.2*lskey->getWidth()/3 + black_key->getWidth();
        M2 = glm::translate(M2,glm::vec3(-translation,0,0));
    }
}
