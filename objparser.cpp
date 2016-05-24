#include "objparser.h"
Models::OBJModel* OBJParser::parseFromFileByName(char *fileLoc, string objName, ShaderProgram* shader){
    ifstream in(fileLoc, ios::in);
   if (!in){
       throw "IOException";
   }
   string line;
   bool found = false;
   vector<glm::vec3> vertices;
   vector<float> textures;
   vector<glm::vec4> normals;
   vector<int>faces[3];
   unsigned int minVertexNo = UINT_MAX;
   unsigned int minNormalsNo = UINT_MAX;
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
               glm::vec4 v;
               s >> v.x;
               s >> v.y;
               s >> v.z;
               v.w = 0.0f;
               //v = glm::normalize(v);
               normals.push_back(v);
           }else if(line.substr(0,3) == "vt "){
               istringstream s(line.substr(3));
               glm::vec2 v;
               s >> v.x;
               s >> v.y;
               textures.push_back(v.x);
               textures.push_back(v.y);
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
   vector<float> realVertices;
   vector<float> realNormals;
   for(unsigned int i=0;i<faces[0].size();i++){
       realVertices.push_back(vertices[(faces[0][i] - minVertexNo)].x);
       realVertices.push_back(vertices[(faces[0][i] - minVertexNo)].y);
       realVertices.push_back(vertices[(faces[0][i] - minVertexNo)].z);
       realVertices.push_back(1.0f);
   }
   printf("read vertices\n" );
   for(unsigned int i=0;i<faces[2].size();i++){
       realNormals.push_back(normals[(faces[2][i] - minNormalsNo)].x);
       realNormals.push_back(normals[(faces[2][i] - minNormalsNo)].y);
       realNormals.push_back(normals[(faces[2][i] - minNormalsNo)].z);
       realNormals.push_back(normals[(faces[2][i] - minNormalsNo)].w);
   }
      printf("read normals\n");
   Models::OBJModel* model = new Models::OBJModel(shader);
   model->vertices(realVertices)->normals(realNormals);
   return model;
}
Models::OBJModel* OBJParser::parseFromFileByName(char *fileLoc, string objName, char* vShader, char* fShader){
    return parseFromFileByName(fileLoc,objName, new ShaderProgram(vShader,NULL,fShader));
}
