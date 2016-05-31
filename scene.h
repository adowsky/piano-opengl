#ifndef SCENE_H
#define SCENE_H
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "models/objmodel.h"
#include "objparser.h"
class Scene{

    Models::OBJModel* model;
public:
    Scene(ShaderProgram*);
    ~Scene();
    void drawObject(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM,glm::vec4 light);
};

#endif
