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
			virtual void drawSolid();
	};

	extern PianoCover pianocover;
}

#endif
