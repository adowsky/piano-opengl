#include "objparser.h"
Models::OBJModel* OBJParser::parseFromFileByName(char *fileLoc, string objName, ShaderProgram* shader){
    ifstream in(fileLoc, ios::in);
   if (!in){
       throw "IOException";
   }
   string line;
   bool found = false;
   vector<glm::vec3> vertices;
   vector<glm::vec2> textures;
   vector<glm::vec3> normals;
   vector<int>faces[3];
   unsigned int minVertexNo = UINT_MAX;
   unsigned int minNormalsNo = UINT_MAX;
   unsigned int minTexNo = UINT_MAX;
   while (getline(in, line)){
       if(found){
           if(line.substr(0,2) == "o "){//Beginnig of new object found
               break;
           }else if(line.substr(0,2) == "v "){//vertex data
               istringstream s(line.substr(2));
               glm::vec3 v;
               s >> v.x;
               s >> v.y;
               s >> v.z;
               vertices.push_back(v);

           }else if(line.substr(0,3) == "vn "){
               istringstream s(line.substr(3));
               glm::vec3 v;
               s >> v.x;
               s >> v.y;
               s >> v.z;
               normals.push_back(v);
           }else if(line.substr(0,3) == "vt "){
               istringstream s(line.substr(3));
               glm::vec2 v;
               s >> v.x;
               s >> v.y;
               textures.push_back(v);
           }else if(line.substr(0,2) == "f "){
               istringstream wholeLine(line.substr(2));
               string triplet;
               while(getline(wholeLine,triplet,' ')){
                   istringstream s(triplet);
                   string single;
                   unsigned int i=0;
                   while(getline(s,single,'/')){
                       unsigned int index;
                       try{
                       index = stoi(single);
                   }catch(std::invalid_argument ex){
                       i++;
                       continue;
                   }
                       faces[i].push_back(index);
                       if(i==0 && index< minVertexNo) minVertexNo = index;
                       if(i==1 && index< minTexNo) minTexNo = index;
                       if(i==2 && index< minNormalsNo) minNormalsNo = index;
                    i++;
                   }
               }
           }

       }
       else if(line.substr(0,2) == "o "){
           string name = line.substr(2);
           if(name == objName){
               found = true;
           }
       }
   }

   float* realVertices = new float[faces[0].size()*4];

   float* realNormals = new float[faces[2].size()*4];
   float* realTex = new float[faces[1].size()*2];
   for(unsigned int i=0;i<faces[0].size();i++){
       realVertices[4*i] = vertices[(faces[0][i] - minVertexNo)].x;
       realVertices[4*i+1] = vertices[(faces[0][i] - minVertexNo)].y;
       realVertices[4*i+2] = vertices[(faces[0][i] - minVertexNo)].z;
       realVertices[4*i+3] = 1.0f;

   }
   for(unsigned int i=0;i<faces[2].size();i++){
       realNormals[4*i] = normals[(faces[2][i] - minNormalsNo)].x;
       realNormals[4*i+1] = normals[(faces[2][i] - minNormalsNo)].y;
       realNormals[4*i+2] = normals[(faces[2][i] - minNormalsNo)].z;
       realNormals[4*i+3] = 0.0f;
      }
   for(unsigned int i=0;i<faces[1].size();i++){
       realTex[2*i] = textures[(faces[1][i] - minTexNo)].x;
       realTex[2*i+1] = textures[(faces[1][i] - minTexNo)].y;
   }
   Models::OBJModel* model = new Models::OBJModel(shader);
   model->vertices4f(realVertices,faces[0].size());
   model->normals4f(realNormals,faces[2].size());
   if(faces[1].size()>0) {
       model->textureCoords2f(realTex,faces[1].size());

   }
   return model;
}
Models::OBJModel* OBJParser::parseFromFileByName(char *fileLoc, string objName, char* vShader, char* fShader){
    return parseFromFileByName(fileLoc,objName, new ShaderProgram(vShader,NULL,fShader));
}
