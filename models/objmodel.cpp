#include "objmodel.h"

namespace Models {
    void OBJModel::assignVBOtoAttribute(ShaderProgram *shaderProgram,char* attributeName, GLuint bufVBO, int vertexSize) {

    	GLuint location=shaderProgram->getAttribLocation(attributeName); //Pobierz numery slotów dla atrybutu
    	glBindBuffer(GL_ARRAY_BUFFER,bufVBO);  //Uaktywnij uchwyt VBO
    	glEnableVertexAttribArray(location); //Włącz używanie atrybutu o numerze slotu zapisanym w zmiennej location
    	glVertexAttribPointer(location,vertexSize,GL_FLOAT, GL_FALSE, 0, NULL); //Dane do slotu location mają być brane z aktywnego VBO
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
        glGenVertexArrays(1,&vao);

    }

    OBJModel* OBJModel::vertices(vector<float> vertices){
        vertexCount = vertices.size()/4;
        countSizes(vertices);

        bufVertices = makeBuffer(&vertices[0],vertices.size()/4, sizeof(float)*4);
        glBindVertexArray(vao); //Uaktywnij nowo utworzony VAO
        assignVBOtoAttribute(shaderProgram,(char*)"vertex",bufVertices,4); //"vertex" odnosi się do deklaracji "in vec4 vertex;" w vertex shaderze
        glBindVertexArray(0); //Dezaktywuj VAO
        return this;
    }
    OBJModel* OBJModel::normals(vector<float> normals){
        bufNormals = makeBuffer(&normals[0],normals.size()/4, sizeof(float)*4);
        glBindVertexArray(vao); //Uaktywnij nowo utworzony VAO
        assignVBOtoAttribute(shaderProgram,(char*)"normal",bufNormals,4); //"vertex" odnosi się do deklaracji "in vec4 vertex;" w vertex shaderze
        glBindVertexArray(0); //Dezaktywuj VAO
        return this;
    }
    OBJModel* OBJModel::colors(vector<float>colors){
        bufColors = makeBuffer(&colors[0],colors.size()/4, sizeof(float)*4);
        glBindVertexArray(vao); //Uaktywnij nowo utworzony VAO
        assignVBOtoAttribute(shaderProgram,(char*)"color",bufColors,4); //"vertex" odnosi się do deklaracji "in vec4 vertex;" w vertex shaderze
        glBindVertexArray(0); //Dezaktywuj VAO
        return this;
    }
    OBJModel::~OBJModel(){
        //glDeleteTextures(1,&tex);
        glDeleteBuffers(1,&bufVertices);
        glDeleteBuffers(1,&bufNormals);
        glDeleteBuffers(1,&bufColors);
        glDeleteBuffers(1,&bufTex);
        glDeleteVertexArrays(1,&vao);
    }
    OBJModel* OBJModel::textureCoords(vector<float> coords){
        bufTex = makeBuffer(&coords[0],coords.size()/2, sizeof(float)*2);
        glBindVertexArray(vao); //Uaktywnij nowo utworzony VAO
        assignVBOtoAttribute(shaderProgram,(char*)"color",bufTex,2); //"vertex" odnosi się do deklaracji "in vec4 vertex;" w vertex shaderze
        glBindVertexArray(0); //Dezaktywuj VAO
        return this;
    }
    void OBJModel::drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM, glm::vec4 light){
        shaderProgram->use();
        glUniformMatrix4fv(shaderProgram->getUniformLocation((char*)"P"),1, false, glm::value_ptr(mP));
    	glUniformMatrix4fv(shaderProgram->getUniformLocation((char*)"V"),1, false, glm::value_ptr(mV));
    	glUniformMatrix4fv(shaderProgram->getUniformLocation((char*)"M"),1, false, glm::value_ptr(mM));
        glUniformMatrix4fv(shaderProgram->getUniformLocation((char*)"lPos"),1, false, glm::value_ptr(light));
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES,0,vertexCount);
        glBindVertexArray(0);
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
        vector<float> buff;
        for(int i=0;i<vertexCount;++i){
            buff.push_back(r);
            buff.push_back(g);
            buff.push_back(b);
            buff.push_back(a);
        }
        colors(buff);
    }
    void OBJModel::countSizes(vector<float>vertices){
        float min_x = FLT_MAX;
        float max_x = FLT_MIN;
        float min_y = FLT_MAX;
        float max_y = FLT_MIN;
        float min_z = FLT_MAX;
        float max_z = FLT_MIN;
        for(size_t i=0;i<vertices.size();i+=4){
            if(vertices[i]<min_x) min_x = vertices[i];
            if(vertices[i]>max_x) max_x = vertices[i];
            if(vertices[i+1]<min_y) min_y = vertices[i+1];
            if(vertices[i+1]>max_y) max_y = vertices[i+1];
            if(vertices[i+2]<min_z) min_z = vertices[i+2];
            if(vertices[i+2]>max_z) max_z = vertices[i+2];
        }
        width = max_x - min_x;
        height = max_y - min_y;
        length = max_z - min_z;
    }
    float OBJModel::getWidth(){
        return width;
    }
    float OBJModel::getHeight(){
        return height;
    }
    float OBJModel::getLength(){
        return this->length;
    }
}
