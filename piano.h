#ifndef PIANO_H
#define PIANO_H

#include "pianobox.h"
#include "pianocover.h"
#include "whitekeyrs.h"
#include "whitekeybs.h"
#include "blackkey.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class Piano{
    Models::PianoBox pianobox;
    Models::PianoCover pianocover;
    bool isOpening;
    float openAngle;
    const float maxAngle = 2.0f/3*PI;
    void drawOctaves(glm::mat4 V, glm::mat4 M, int count);
public:
    Piano();
    virtual ~Piano();
    virtual void drawObject(glm::mat4 V, glm::mat4 M);
    float height();
    void open();
    void close();

};

#endif
