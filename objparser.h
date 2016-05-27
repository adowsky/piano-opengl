#ifndef OBJPARSER_H
#define OBJPARSER_H
#define GLM_FORCE_RADIANS
#include "models/objmodel.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <climits>
#include "models/shaderprogram.h"
using namespace std;
class OBJParser{
public:
    static Models::OBJModel* parseFromFileByName(char* fileloc,string objName,char* vShader, char* fShader);
    static Models::OBJModel* parseFromFileByName(char *fileLoc, string objName, ShaderProgram* shader);
};
#endif
