#include "camera.h"

Camera::Camera(){
    horizontalMove = 0;
    horizontalSensivity = 0.001f;
    horizontalAngle = 0.0f;
    verticalAngle = 0.0f;
    verticalSensivity = 0.001f;
    straightMove = 0;
    position = glm::vec3(0.0f,0.0f,-5.0f);
    direction = glm::vec3(0.0f,0.0f,5.0f);
    right = glm::vec3(1.0f,0.0f,0.0f);
    up = glm::vec3(0.0f,1.0f,0.0f);
    speed = 1.5f;
}

Camera::~Camera(){

}

void Camera::rotate(int horizontal, int vertical){
    horizontalAngle += horizontalSensivity*horizontal;
    verticalAngle += horizontalSensivity*vertical;
    direction = glm::vec3(glm::cos(verticalAngle)*glm::sin(horizontalAngle),glm::sin(verticalAngle),glm::cos(verticalAngle)*glm::cos(horizontalAngle));
    right = glm::vec3(glm::sin(horizontalAngle - PI/2.0f), 0, glm::cos(horizontalAngle - PI/2.0f));
    up = glm::cross(right, direction);
}

void Camera::moveForward(bool enable){
    if(enable)
        straightMove++;
    else
        straightMove--;
}

void Camera::moveBack(bool enable){
    if(enable)
        straightMove--;
    else
        straightMove++;
}

void Camera::moveLeft(bool enable){
    if(enable)
        horizontalMove--;
    else
        horizontalMove++;
}
void Camera::moveRight(bool enable){
    if(enable)
        horizontalMove++;
    else
        horizontalMove--;
}
void Camera::move(double seconds){
    position += direction*(float)(straightMove*seconds*speed);
    position += right*(float)(horizontalMove*seconds*speed);
}

void Camera::setSpeed(float spd){
    speed = spd;
}

void Camera::setHorizontalSensivity(float hs){
    horizontalSensivity = hs;
}

void Camera::setVerticalSensivity(float vs){
    verticalSensivity = vs;
}

glm::vec3 Camera::getPosition(){
    return position;
}
glm::mat4 Camera::getViewMatrix(){
    return glm::lookAt(position, position+direction, up);
}
glm::vec3 Camera::getDirectionVector(){
    return direction;
}
glm::vec3 Camera::getUpVector(){
    return up;
}
glm::vec3 Camera::getRightVector(){
    return right;
}
