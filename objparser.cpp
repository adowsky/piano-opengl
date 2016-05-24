#include "objparser.h"

Models::OBJModel* OBJParser::parseFromFileByName(char *fileLoc, string objName, char* vShader, char* fShader){
    ifstream in(fileLoc, ios::in);
   if (!in){
       throw "IOException";
   }
   string line;
   bool found = false;
   vector<glm::vec3> vertices;
   vector<float> textures;
   vector<glm::vec3> normals;
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
               glm::vec3 v;
               s >> v.x;
               s >> v.y;
               s >> v.z;
               v = glm::normalize(v);
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
                   int i=0;
                   while(getline(s,single,'/')){
                       int index = stoi(single);
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
   for(int i=0;i<faces[0].size();i++){
       printf("%d\n",(faces[0][i] - minVertexNo));
       realVertices.push_back(vertices[(faces[0][i] - minVertexNo)].x);
       realVertices.push_back(vertices[(faces[0][i] - minVertexNo)].y);
       realVertices.push_back(vertices[(faces[0][i] - minVertexNo)].z);
       realVertices.push_back(1.0f);
   }

   for(int i=0;i<faces[2].size();i++){
       realNormals.push_back(normals[faces[2][i]].x);
       realNormals.push_back(normals[(faces[2][i] - minNormalsNo)].y);
       realNormals.push_back(normals[(faces[2][i] - minNormalsNo)].z);
   }
   Models::OBJModel* model = new Models::OBJModel(vShader,fShader);
   model->vertices(realVertices)->normals(realNormals);
   return model;
}
