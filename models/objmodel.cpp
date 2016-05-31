#include "objmodel.h"
#include <SOIL/SOIL.h>

namespace Models {
    void OBJModel::assignVBOtoAttribute(ShaderProgram *shaderProgram,char* attributeName, GLuint bufVBO, int vertexSize) {
    	GLuint location=shaderProgram->getAttribLocation(attributeName); //Pobierz numery slotów dla atrybutu
    	glBindBuffer(GL_ARRAY_BUFFER,bufVBO);  //Uaktywnij uchwyt VBO
        glEnableVertexAttribArray(location); //Włącz używanie atrybutu o numerze slotu zapisanym w zmiennej location
    	glVertexAttribPointer(location,vertexSize,GL_FLOAT, GL_FALSE, 0, NULL); //Dane do slotu location mają być brane z aktywnego VBO
    }
    void OBJModel::assignVBOtoAttribute(ShaderProgram *shaderProgram,char* attributeName, GLuint bufVBO, int vertexSize, int stride) {
        shaderProgram->use();
        GLuint location=shaderProgram->getAttribLocation(attributeName); //Pobierz numery slotów dla atrybutu
        glEnableVertexAttribArray(location);
        glBindBuffer(GL_ARRAY_BUFFER,bufVBO);  //Uaktywnij uchwyt VBO
         //Włącz używanie atrybutu o numerze slotu zapisanym w zmiennej location
        glVertexAttribPointer(1, vertexSize, GL_FLOAT, GL_FALSE, stride, NULL);

        shaderProgram->disable();
    }
    //Tworzy bufor VBO z tablicy
    GLuint OBJModel::makeBuffer(void *data, int vertexCount, int vertexSize) {
    	GLuint handle;
    	glGenBuffers(1,&handle);//Wygeneruj uchwyt na Vertex Buffer Object (VBO), który będzie zawierał tablicę danych
    	glBindBuffer(GL_ARRAY_BUFFER,handle);  //Uaktywnij wygenerowany uchwyt VBO
    	glBufferData(GL_ARRAY_BUFFER, vertexCount*vertexSize, data, GL_STATIC_DRAW);//Wgraj tablicę do VBO
    	return handle;
    }
    OBJModel::OBJModel(char* vShaderLoc,char* fShaderLoc) : OBJModel::OBJModel(new ShaderProgram(vShaderLoc,NULL,fShaderLoc)){
    }

    OBJModel::OBJModel(ShaderProgram* shader){
        shaderProgram = shader;
        cubeTexMode= false;
        bufTex = 0;
        vao = 0;
        bufVertices = 0;
        bufColors = 0;
        bufNormals = 0;
        textureShared = false;
        vertexCount = 0;
        vertexData = normalsData = texCoordsData = colorsData = NULL;
        sizes = new Sizes;
        glGenVertexArrays(1,&vao);
        glGenTextures(1,&tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        std::vector<unsigned char> image;
        image.push_back(255);
        image.push_back(255);
        image.push_back(255);
        image.push_back(255);
        glTexImage2D(GL_TEXTURE_2D, 0, 4, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*) image.data());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    }


    OBJModel* OBJModel::vertices4f(float* vertices, int size){
        vertexCount = size;
        countSizes(vertices);
        bufVertices = makeBuffer(vertices,vertexCount, sizeof(float)*4);
        glBindVertexArray(vao); //Uaktywnij nowo utworzony VAO
        assignVBOtoAttribute(shaderProgram,(char*)"vertex\0",bufVertices,4); //"vertex" odnosi się do deklaracji "in vec4 vertex;" w vertex shaderze
        glBindVertexArray(0); //Dezaktywuj VAO
        return this;
    }



    OBJModel* OBJModel::normals4f(float* normals, int size){
        normalsCount = size;
        bufNormals = makeBuffer(normals,normalsCount, sizeof(float)*4);
        glBindVertexArray(vao); //Uaktywnij nowo utworzony VAO
        assignVBOtoAttribute(shaderProgram,(char*)"normal",bufNormals,4); //"vertex" odnosi się do deklaracji "in vec4 vertex;" w vertex shaderze
        glBindVertexArray(0); //Dezaktywuj VAO
        return this;
    }

    OBJModel* OBJModel::colors4f(float* colors, int size){
        colorsCount = size;
        bufColors = makeBuffer(colors,colorsCount, sizeof(float)*4);
        glBindVertexArray(vao); //Uaktywnij nowo utworzony VAO
        assignVBOtoAttribute(shaderProgram,(char*)"color",bufColors,4); //"vertex" odnosi się do deklaracji "in vec4 vertex;" w vertex shaderze
        glBindVertexArray(0); //Dezaktywuj VAO
        return this;
    }

    OBJModel* OBJModel::textureCoords2f(float* coords, int size){
        texCount = size;
        bufTex = makeBuffer(coords,texCount, sizeof(float)*2);
        glBindVertexArray(vao); //Uaktywnij nowo utworzony VAO
        assignVBOtoAttribute(shaderProgram,(char*)"texCoord",bufTex,2); //"vertex" odnosi się do deklaracji "in vec4 vertex;" w vertex shaderze
        glBindVertexArray(0); //Dezaktywuj VAO
        return this;
    }

    OBJModel::~OBJModel(){
        glDeleteVertexArrays(1,&vao);
        glDeleteBuffers(1,&bufVertices);
        glDeleteBuffers(1,&bufNormals);
        glDeleteBuffers(1,&bufColors);
        if(!textureShared) glDeleteTextures(1,&tex);
        if (bufTex) glDeleteBuffers(1,&bufTex);
        delete sizes;
        if(vertexData) delete[] vertexData;
        if(normalsData) delete[] normalsData;
        if(texCoordsData) delete[] texCoordsData;
        if(colorsData) delete[] colorsData;
    }


    void OBJModel::bindTexture(char* texLocation){
         glActiveTexture(GL_TEXTURE0);
        std::vector<unsigned char> image;
        unsigned width, height;
        unsigned error = lodepng::decode(image, width, height, texLocation);
        glDeleteTextures(1,&tex);
        glGenTextures(1,&tex);
        cubeTexMode = false;
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*) image.data());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    void OBJModel::bindTexture(vector<const char*> texLocs){
        glActiveTexture(GL_TEXTURE0);
        glDeleteTextures(1,&tex);
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_CUBE_MAP, tex);
        int width, height, channels;
        for(int i=0;i<texLocs.size();++i){
            printf("%s\n",texLocs[i]);
            unsigned char* img = SOIL_load_image(texLocs[i], &width, &height, &channels, SOIL_LOAD_RGB);
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
        }

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
        cubeTexMode = true;
    }

    void OBJModel::bindTexture(GLuint texture){
         glActiveTexture(GL_TEXTURE0);
         glDeleteTextures(1,&tex);
         tex = texture;
         textureShared = true;
         cubeTexMode = false;
    }
    void OBJModel::drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM, glm::vec4 light){
        shaderProgram->use();
        glActiveTexture(GL_TEXTURE0);

        glUniform1i(shaderProgram->getUniformLocation((char*)"textureMap0"),0);
        glUniform1i(shaderProgram->getUniformLocation((char*)"cube"),0);
        glUniformMatrix4fv(shaderProgram->getUniformLocation((char*)"P"),1, false, glm::value_ptr(mP));
    	glUniformMatrix4fv(shaderProgram->getUniformLocation((char*)"V"),1, false, glm::value_ptr(mV));
    	glUniformMatrix4fv(shaderProgram->getUniformLocation((char*)"M"),1, false, glm::value_ptr(mM));
        glUniform4fv(shaderProgram->getUniformLocation((char*)"lPos"),1, glm::value_ptr(light));
        if(cubeTexMode){
            glBindTexture (GL_TEXTURE_CUBE_MAP, tex);
            glBindTexture(GL_TEXTURE_2D,0);
            glUniform1i(shaderProgram->getUniformLocation((char*)"cubic"),1);
        }else{
            glBindTexture(GL_TEXTURE_2D,tex);
            glBindTexture (GL_TEXTURE_CUBE_MAP, 0);
            glUniform1i(shaderProgram->getUniformLocation((char*)"cubic"),0);
        }

        glBindVertexArray(vao);

        glDrawArrays(GL_TRIANGLES,0,vertexCount);
        glBindVertexArray(0);
        if(cubeTexMode)
            glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
        else
            glBindTexture(GL_TEXTURE_2D,0);
        shaderProgram->disable();
    }

    void OBJModel::drawModel(){
    shaderProgram->use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES,0,vertexCount);
    glBindVertexArray(0);
    shaderProgram->disable();

    }
    void OBJModel::fillWithColor(float r,float g,float b,float a){
        float* buff = new float[vertexCount*4];
        for(int i=0;i<vertexCount;++i){
            buff[i*4] =r;
            buff[i*4+1]=g;
            buff[i*4+2]=b;
            buff[i*4+3]=a;
        }
        colors4f(buff,vertexCount);
    }
    void OBJModel::countSizes(float* vertices){
        sizes->Xmin = numeric_limits<float>::max();
        sizes->Xmax = numeric_limits<float>::lowest();
        sizes->Ymin = numeric_limits<float>::max();
        sizes->Ymax = numeric_limits<float>::lowest();
        sizes->Zmin = numeric_limits<float>::max();
        sizes->Zmax = numeric_limits<float>::lowest();
        for(size_t i=0;i<vertexCount*4;i+=4){
            if(vertices[i]<sizes->Xmin) sizes->Xmin = vertices[i];
            if(vertices[i]>sizes->Xmax) sizes->Xmax = vertices[i];
            if(vertices[i+1]<sizes->Ymin) sizes->Ymin = vertices[i+1];
            if(vertices[i+1]>sizes->Ymax) sizes->Ymax = vertices[i+1];
            if(vertices[i+2]<sizes->Zmin) sizes->Zmin = vertices[i+2];
            if(vertices[i+2]>sizes->Zmax) sizes->Zmax = vertices[i+2];

        }
    }
    void OBJModel::countSizes(vector<glm::vec4>vertices){
        sizes->Xmin = numeric_limits<float>::max();
        sizes->Xmax = numeric_limits<float>::lowest();
        sizes->Ymin = numeric_limits<float>::max();
        sizes->Ymax = numeric_limits<float>::lowest();
        sizes->Zmin = numeric_limits<float>::max();
        sizes->Zmax = numeric_limits<float>::lowest();
        for(size_t i=0;i<vertices.size();i++){
            if(vertices[i].x<sizes->Xmin) sizes->Xmin = vertices[i].x;
            if(vertices[i].x>sizes->Xmax) sizes->Xmax = vertices[i].x;
            if(vertices[i].y<sizes->Ymin) sizes->Ymin = vertices[i].y;
            if(vertices[i].y>sizes->Ymax) sizes->Ymax = vertices[i].y;
            if(vertices[i].z<sizes->Zmin) sizes->Zmin = vertices[i].z;
            if(vertices[i].z>sizes->Zmax) sizes->Zmax = vertices[i].z;
        }
    }
    float OBJModel::getWidth(){
        return sizes->Xmax - sizes->Xmin;
    }
    float OBJModel::getHeight(){
        return sizes->Ymax - sizes->Ymin;
    }
    float OBJModel::getLength(){
        return  sizes->Zmax - sizes->Zmin;
    }
    float OBJModel::getXmin(){
        return sizes->Xmin;
    }
    float OBJModel::getXmax(){
        return sizes->Xmax;
    }
    float OBJModel::getYmin(){
        return sizes->Ymin;
    }
    float OBJModel::getYmax(){
        return sizes->Ymax;
    }
    float OBJModel::getZmin(){
        return sizes->Zmin;
    }
    float OBJModel::getZmax(){
        return sizes->Zmax;
    }
}
