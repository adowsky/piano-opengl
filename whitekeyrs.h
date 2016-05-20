#ifndef WHITEKEYRS_H
#define WHITEKEYRS_H

#include "model.h"
#include "lodepng.h"

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
		GLuint tex;
		public:
			WhiteKeyRS();
			virtual ~WhiteKeyRS();
			virtual void drawSolid();
	};

	extern WhiteKeyRS whitekeyrs;
}

#endif
