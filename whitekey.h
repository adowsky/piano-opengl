#ifndef WHITEKEY_H
#define WHITEKEY_H

#include "model.h"

namespace Models {
	namespace WhiteKeyInternal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class WhiteKey: public Model {
		public:
			WhiteKey();
			virtual ~WhiteKey();
			virtual void drawSolid();
	};

	extern WhiteKey whitekey;
}

#endif
