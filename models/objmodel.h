/*
Niniejszy program jest wolnym oprogramowaniem; możesz go
rozprowadzać dalej i / lub modyfikować na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundację Wolnego
Oprogramowania - według wersji 2 tej Licencji lub(według twojego
wyboru) którejś z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on
użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej
gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH
ZASTOSOWAŃ.W celu uzyskania bliższych informacji sięgnij do
Powszechnej Licencji Publicznej GNU.

Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
jeśli nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#ifndef OBJMODEL_H
#define OBJMODEL_H
#define GLM_FORCE_RADIANS
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "shaderprogram.h"
#include "constants.h"
#include "datastructs.h"
using namespace std;
namespace Models {

	class OBJModel {
		GLuint bufVertices;
		GLuint bufColors;
		GLuint bufNormals;
		GLuint vao;
		ShaderProgram *shaderProgram;
		int vertexCount;
		Sizes* sizes;
		void countSizes(vector<float>vertices);
	protected:
	void assignVBOtoAttribute(ShaderProgram *shaderProgram,char* attributeName, GLuint bufVBO, int vertexSize);
	GLuint makeBuffer(void *data, int vertexCount, int vertexSize);


	public:
			OBJModel(char* vShaderLoc,char* fShaderLoc);
			OBJModel(ShaderProgram* shader);
			virtual ~OBJModel();
			OBJModel* vertices(vector<float>);
			OBJModel* normals(vector<float>);
			OBJModel* colors(vector<float>);
			OBJModel* textureCoords(vector<float>);
			void fillWithColor(float r,float g,float b,float a);
			virtual void drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM, glm::vec4 light);
			virtual void drawModel();
			float getWidth();
			float getHeight();
			float getLength();
			float getXmin();
			float getXmax();
			float getYmin();
			float getYmax();
			float getZmin();
			float getZmax();
	};
}

#endif
