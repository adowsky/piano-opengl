#ifndef WHITEKEYBS_H
#define WHITEKEYBS_H

#include "model.h"

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
		public:
			WhiteKeyBS();
			virtual ~WhiteKeyBS();
			virtual void drawSolid();
	};

	extern WhiteKeyBS whitekeybs;
}

#endif
