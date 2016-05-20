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
			virtual void drawSolid();
	};

	extern BlackKey blackkey;
}

#endif
