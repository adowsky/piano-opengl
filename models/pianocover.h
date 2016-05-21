#ifndef PIANOCOVER_H
#define PIANOCOVER_H

#include "model.h"

namespace Models {
	namespace PianoCoverInternal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class PianoCover: public Model {
		public:
			PianoCover();
			virtual ~PianoCover();
			virtual void drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM);
			void init();
	};

	extern PianoCover pianocover;
}

#endif
