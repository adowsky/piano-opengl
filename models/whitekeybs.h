#ifndef WHITEKEYBS_H
#define WHITEKEYBS_H

#include "model.h"
#include "../lodepng.h"

namespace Models {
	namespace WhiteKeyBSInternal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class WhiteKeyBS: public Model {
			GLuint tex;
		public:
			WhiteKeyBS();
			virtual ~WhiteKeyBS();
			virtual void drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM);
			void init();
	};

	extern WhiteKeyBS whitekeybs;
}

#endif
