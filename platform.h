#ifndef PLATFORM_H
#define PLATFORM_H


#include "model.h"
#include <stdio.h>

namespace Models {
	namespace PlatformInternal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class Platform: public Model {
		public:
			Platform();
			virtual ~Platform();
			virtual void drawSolid();
	};

	extern Platform platform;
}




#endif
