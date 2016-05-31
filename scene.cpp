#include "scene.h"

Scene::Scene(ShaderProgram* shader){
    model = OBJParser::parseFromFileByName((char*)"models/cube.obj", "Cube",shader);
    vector<const GLchar*> faces;
        faces.push_back("posx.tga");
        faces.push_back("negx.tga");
        faces.push_back("posy.tga");
        faces.push_back("negy.tga");
        faces.push_back("posz.tga");
        faces.push_back("negz.tga");
    model->bindTexture(faces);
    model->fillWithColor(1, 1, 1, 1);
}
Scene::~Scene(){
    delete model;
}
void Scene::drawObject(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM,glm::vec4 light){
    mV[3][0] = mV[3][1] = mV[3][2] = 0;
    model->drawModel( mP,  mV,  mM, light);
}
