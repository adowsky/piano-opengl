#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FTGL/ftgl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "constants.h"

class Camera{
    float horizontalSensivity;
    float verticalSensivity;
    float horizontalAngle;
    float verticalAngle;
    float speed;
    glm::vec3 direction;
    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 position;
    int horizontalMove;
    int straightMove;
public:
    Camera();
    virtual ~Camera();
    void rotate( int horizontal, int vertical);
    void move(double seconds);
    void setVerticalSensivity(float);
    void setHorizontalSensivity(float);
    void setSpeed(float);
    void moveForward(bool);
    void moveLeft(bool);
    void moveRight(bool);
    void moveBack(bool);
    glm::vec3 getPosition();
    glm::mat4 getViewMatrix();
    glm::vec3 getDirectionVector();
    glm::vec3 getRightVector();
    glm::vec3 getUpVector();
};
