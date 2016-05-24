#ifndef OBJPARSER_H
#define OBJPARSER_H
#include "models/objmodel.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <climits>
using namespace std;
class OBJParser{
public:
    static Models::OBJModel* parseFromFileByName(char* fileloc,string objName,char* vShader, char* fShader);
};
#endif
