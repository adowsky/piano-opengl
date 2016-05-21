#ifndef BLACKKEY_H
#define BLACKKEY_H

#include "model.h"

namespace Models {
	namespace BlackKeyInternal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class BlackKey: public Model {
		public:
			BlackKey();
			virtual ~BlackKey();
			virtual void drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM);
			void init();
	};

	extern BlackKey blackkey;
}

#endif
