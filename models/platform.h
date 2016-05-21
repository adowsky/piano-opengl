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
			virtual void drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM);
			void init();
	};

	extern Platform platform;
}




#endif
