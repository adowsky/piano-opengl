#ifndef PIANO_H
#define PIANO_H

#include "models/pianobox.h"
#include "models/pianocover.h"
#include "models/whitekeyrs.h"
#include "models/whitekeybs.h"
#include "models/blackkey.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <stdio.h>


class Piano{
    Models::PianoBox pianobox;
    Models::PianoCover pianocover;
    Models::BlackKey bkey;
    Models::WhiteKeyBS keybs;
    Models::WhiteKeyRS keyrs;
    bool isOpening;
    float openAngle;
    const float maxAngle = 2.0f/3*PI;
    void drawOctaves(glm::mat4 V, glm::mat4 M, int count);
public:
    Piano();
    virtual ~Piano();
    virtual void drawObject(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM);
    float height();
    void open();
    void close();

};

#endif
