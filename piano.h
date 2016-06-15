#ifndef PIANO_H
#define PIANO_H
#define GLM_FORCE_RADIANS
#include "models/objmodel.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "models/shaderprogram.h"
#include "objparser.h"
#include "models/datastructs.h"

namespace PianoInternal {
    extern string keyNames[];
}
enum MovementState{
    MOVING, BACKING, NONE
};
struct PianoKey{
    Models::Dim3D rotation;
    Models::Dim3D translation;
    ALuint buffer, source;
    ALint state;
    MovementState movState;
    Models::OBJModel* model;

};
class Piano{
    Models::OBJModel* pianobox;
    Models::OBJModel* pianocover;
    Models::OBJModel* rskey;
    Models::OBJModel* bskey;
    Models::OBJModel* lskey;
    Models::OBJModel* black_key;
    Models::OBJModel* floor;
    GLuint dirt,wood,floor_img;

    PianoKey* keyboard;
    int octavesCount, lowestNote,highestNote;
    int activeOctave;
    void generateOctaves(string filePrefix, string fileSuffix, string fileFormat);
    bool isOpening;
    float openAngle;
    const float keyRotationSpeed = 0.7*PI;
    const float maxAngle = 0.7*PI;
    const float maxKeyAngle = 0.03f*PI;
    void drawKeyboard(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM,glm::vec4 light);
    GLuint loadTexture(char* loc);

public:
    Piano();
    Piano(ShaderProgram*);
    virtual ~Piano();
    virtual void drawObject(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM,glm::vec4 light,float timer);
    float height();
    void open();
    void close();
    void playAbsolute(int keyNo);
    void playAbsolute(int keyNo, float gain);
    void play(int keyNo);
    void play(int keyNo, float gain);
    void octaveUp();
    void octaveDown();
    int getHighestNote();
    int getLowestNote();

};

#endif
