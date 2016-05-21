#ifndef WHITEKEYRS_H
#define WHITEKEYRS_H

#include "model.h"
#include "../lodepng.h"

namespace Models {
	namespace WhiteKeyRSInternal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class WhiteKeyRS: public Model {
		public:
			WhiteKeyRS();
			virtual ~WhiteKeyRS();
			virtual void drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM);
			void init();
	};

	extern WhiteKeyRS whitekeyrs;
}

#endif
