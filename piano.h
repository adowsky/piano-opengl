#ifndef PIANO_H
#define PIANO_H

#include "models/objmodel.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "models/shaderprogram.h"
#include "objparser.h"

class Piano{
    Models::OBJModel* pianobox;
    Models::OBJModel* pianocover;
    Models::OBJModel* rskey;
    Models::OBJModel* bskey;
    Models::OBJModel* lskey;
    Models::OBJModel* black_key;
    bool isOpening;
    float openAngle;
    const float maxAngle = 2.0f/3*PI;
    void drawOctaves(glm::mat4 V, glm::mat4 M, int count);
public:
    Piano();
    Piano(ShaderProgram*);
    virtual ~Piano();
    virtual void drawObject(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM,glm::vec4 light);
    float height();
    void open();
    void close();

};

#endif
