#include "piano.h"

Piano::Piano(){

}
Piano::Piano(ShaderProgram* shader){
    isOpening = false;
    openAngle = 0.0f;
    dirt = loadTexture((char*)"whiteKeyLayer.png");
    wood = loadTexture((char*)"wood.png");
    floor_img = loadTexture((char*)"floor5.png");
    pianobox = OBJParser::parseFromFileByName((char *)"models/pianobox.obj","Cube", shader);
    pianobox->fillWithColor(1.0f, 1.0f, 1.0f, 1.0f);
    pianobox->bindTexture(wood);
    pianocover = OBJParser::parseFromFileByName((char *)"models/pianocover.obj", "Plane", shader);
    pianocover->fillWithColor(1.0f, 1.0f, 1.0f, 1.0f);
    pianocover->bindTexture(wood);
    rskey = OBJParser::parseFromFileByName((char *)"models/rskey.obj", "C_Cube.001", shader);
    rskey->fillWithColor(1.0f, 1.0f, 1.0f, 1.0f);
    rskey->bindTexture(dirt);
    bskey = OBJParser::parseFromFileByName((char *)"models/bskey.obj", "D_Cube.002", shader);
    bskey->fillWithColor(1.0f, 1.0f, 1.0f, 1.0f);
    bskey->bindTexture(dirt);
    lskey = OBJParser::parseFromFileByName((char *)"models/lskey.obj", "E_Cube.003", shader);
    lskey->fillWithColor(1.0f, 1.0f, 1.0f, 1.0f);
    lskey->bindTexture(dirt);
    black_key = OBJParser::parseFromFileByName((char *)"models/blackkey.obj", "C#_Cube.009", shader);
    black_key->fillWithColor(0.0f, 0.0f, 0.0f, 1.0f);

    octavesCount = 3;
    activeOctave = 0;
    //generateOctaves("samples/CAT0", "", "wav");
    generateOctaves("samples/KEPSREC0", "", "wav");
}

Piano::~Piano(){
    delete pianobox;
    delete pianocover;
    delete rskey;
    delete bskey;
    delete lskey;
    delete black_key;
    glDeleteTextures(1,&floor_img);
    glDeleteTextures(1,&dirt);
    glDeleteTextures(1,&wood);
    if (keyboard) {
        for(int i=0;i<12*octavesCount;++i){
            alDeleteSources(1, &keyboard[i].source);
            alDeleteBuffers(1, &keyboard[i].buffer);
        }
        delete[] keyboard;
    }
}
GLuint Piano::loadTexture(char *texLocation){
    GLuint tex;
   std::vector<unsigned char> image;
   unsigned width, height;
   unsigned error = lodepng::decode(image, width, height, texLocation);
   glGenTextures(1,&tex);

   glBindTexture(GL_TEXTURE_2D, tex);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*) image.data());
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glBindTexture(GL_TEXTURE_2D, 0);
   return tex;

}
void Piano::generateOctaves(string filePrefix, string fileSuffix, string fileFormat){
    keyboard = new PianoKey[12*octavesCount];
    Models::Dim3D mainTranslate, activeTranslateW,activeTranslateB;
    Models::Dim3D zeroRotation;
    mainTranslate.x = -pianobox->getXmin()-1.5*rskey->getWidth();
    mainTranslate.y = 0;
    mainTranslate.z = -pianobox->getLength()*0.63f;
    zeroRotation.x = zeroRotation.y = zeroRotation.z = 0;
    activeTranslateW = mainTranslate;
    activeTranslateB = mainTranslate;

    for(int i=0;i<octavesCount;++i){
        //C
        keyboard[i*12].rotation = zeroRotation;
        keyboard[i*12].translation = activeTranslateW;
        keyboard[i*12].movState = MovementState::NONE;
        keyboard[i*12].model = rskey;
        activeTranslateW.x -=  1.1*rskey->getWidth();
        //C#
        activeTranslateB.x += -2.2*rskey->getWidth()/3;
        keyboard[i*12 +1].rotation = zeroRotation;
        keyboard[i*12 +1].translation = activeTranslateB;
        keyboard[i*12 +1].movState = MovementState::NONE;
        keyboard[i*12 +1].model = black_key;
        activeTranslateB.x -= bskey->getWidth()/3+ black_key->getWidth();
        //d
        keyboard[i*12 +2].rotation = zeroRotation;
        keyboard[i*12 +2].translation = activeTranslateW;
        keyboard[i*12 +2].movState = MovementState::NONE;
        keyboard[i*12 +2].model = bskey;
        activeTranslateW.x -= 1.1*bskey->getWidth();
        //d#
        keyboard[i*12 +3].rotation = zeroRotation;
        keyboard[i*12 +3].translation = activeTranslateB;
        keyboard[i*12 +3].movState = MovementState::NONE;
        keyboard[i*12 +3].model = black_key;
        activeTranslateB.x -= 2.2*lskey->getWidth()/3 + 2.2*rskey->getWidth()/3 + black_key->getWidth();
        //e
        keyboard[i*12 +4].rotation = zeroRotation;
        keyboard[i*12 +4].translation = activeTranslateW;
        keyboard[i*12 +4].movState = MovementState::NONE;
        keyboard[i*12 +4].model = lskey;
        activeTranslateW.x -= 1.1*lskey->getWidth();
        //f
        keyboard[i*12 +5].rotation = zeroRotation;
        keyboard[i*12 +5].translation = activeTranslateW;
        keyboard[i*12 +5].movState = MovementState::NONE;
        keyboard[i*12 +5].model = rskey;
        activeTranslateW.x += -1.1*rskey->getWidth();
        //f#
        keyboard[i*12 +6].rotation = zeroRotation;
        keyboard[i*12 +6].translation = activeTranslateB;
        keyboard[i*12 +6].movState = MovementState::NONE;
        keyboard[i*12 +6].model = black_key;
        activeTranslateB.x -= 1.1*bskey->getWidth()/3+ black_key->getWidth();
        //g
        keyboard[i*12 +7].rotation = zeroRotation;
        keyboard[i*12 +7].translation = activeTranslateW;
        keyboard[i*12 +7].movState = MovementState::NONE;
        keyboard[i*12 +7].model = bskey;
        activeTranslateW.x += -1.1*bskey->getWidth();
        //g#
        keyboard[i*12 +8].rotation = zeroRotation;
        keyboard[i*12 +8].translation = activeTranslateB;
        keyboard[i*12 +8].movState = MovementState::NONE;
        keyboard[i*12 +8].model = black_key;
        activeTranslateB.x -= 1.1*bskey->getWidth()/3+ black_key->getWidth();
        //a
        keyboard[i*12 +9].rotation = zeroRotation;
        keyboard[i*12 +9].translation = activeTranslateW;
        keyboard[i*12 +9].movState = MovementState::NONE;
        keyboard[i*12 +9].model = bskey;
        activeTranslateW.x += -1.1*bskey->getWidth();
        //a#
        keyboard[i*12 +10].rotation = zeroRotation;
        keyboard[i*12 +10].translation = activeTranslateB;
        keyboard[i*12 +10].movState = MovementState::NONE;
        keyboard[i*12 +10].model = black_key;
        activeTranslateB.x -= (2.2)*lskey->getWidth()/3 + black_key->getWidth();
        //b
        keyboard[i*12 +11].rotation = zeroRotation;
        keyboard[i*12 +11].translation = activeTranslateW;
        keyboard[i*12 +11].movState = MovementState::NONE;
        keyboard[i*12 +11].model = lskey;
        activeTranslateW.x += -1.1*lskey->getWidth();
    }
    for(int i=0;i<12*octavesCount;++i){

            string fileName = filePrefix + to_string(12*4+i) + fileSuffix + "." + fileFormat;
            printf("Loading: %s",fileName.c_str());
            keyboard[i].buffer = alutCreateBufferFromFile(fileName.c_str());
            if(keyboard[i].buffer == AL_NONE){
                printf("[ERROR]\n");
            }else{
                printf("[OK]\n");
            }
            alGenSources(1, &keyboard[i].source);
            alSourcei(keyboard[i].source, AL_BUFFER, keyboard[i].buffer);
    }
}

void Piano::drawKeyboard(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM,glm::vec4 light){
    for(int i=0;i<12*octavesCount;++i){
        glm::mat4 M = glm::translate(mM,glm::vec3(keyboard[i].translation.x,keyboard[i].translation.y,keyboard[i].translation.z));
        if(keyboard[i].movState == MovementState::MOVING && keyboard[i].rotation.z>-maxKeyAngle){
            keyboard[i].rotation.z -= keyRotationSpeed*glfwGetTime();
        }else if(keyboard[i].movState == MovementState::BACKING && keyboard[i].rotation.z<0){
            keyboard[i].rotation.z += keyRotationSpeed*glfwGetTime();
        }
        else if(keyboard[i].movState == MovementState::MOVING && keyboard[i].rotation.z<=-maxKeyAngle){
            keyboard[i].movState = MovementState::BACKING;
        }
        else if(keyboard[i].movState == MovementState::BACKING && keyboard[i].rotation.z>=0){
            keyboard[i].movState = MovementState::NONE;
            keyboard[i].rotation.z = 0.0f;
        }
        M = glm::rotate(M,keyboard[i].rotation.z,glm::vec3(1.0f,0,0));
        keyboard[i].model->drawModel(mP, mV,M ,light);
    }
}

void Piano::drawObject(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM,glm::vec4 light){
    if(isOpening && openAngle>-maxAngle)
        openAngle -= PI/2*glfwGetTime();
    else if(!isOpening &&openAngle<0)
        openAngle += PI/2*glfwGetTime();

    pianobox->drawModel(mP, mV, mM,light);
    glm::mat4 M = glm::translate(mM,glm::vec3(pianobox->getXmin(),pianobox->getYmax(),0));
    M = glm::rotate(M, -openAngle, glm::vec3(1.0f,0,0));
    pianocover->drawModel(mP, mV,M ,light);
    drawKeyboard(mP,  mV, mM, light);

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

void Piano::play(int keyNo){
    alGetSourcei(keyboard[activeOctave*12+keyNo].source, AL_SOURCE_STATE, &keyboard[activeOctave*12+keyNo].state);
        if(keyboard[activeOctave*12+keyNo].state == AL_PLAYING){
            alSourceStop(keyboard[activeOctave*12+keyNo].source);
        }
        alSourcePlay(keyboard[activeOctave*12+keyNo].source);
        alGetSourcei(keyboard[activeOctave*12+keyNo].source, AL_SOURCE_STATE, &keyboard[activeOctave*12+keyNo].state);
        keyboard[activeOctave*12+keyNo].movState = MovementState::MOVING;

}

void Piano::octaveUp(){
    if(activeOctave<octavesCount -1){
        activeOctave++;
    }
}
void Piano::octaveDown(){
    if (activeOctave>0){
        activeOctave--;
    }
}

namespace PianoInternal {
    string keyNames[] = {"c", "c#", "d", "d#", "e" , "f", "f#", "g", "g#", "a" , "a#", "b"};
}
