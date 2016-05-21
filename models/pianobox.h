#ifndef PIANOBOX_H
#define PIANOBOX_H

#include "model.h"
#include "../lodepng.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace Models {
	namespace PianoBoxInternal {
		extern float vertices[];
		extern float normals[];
		extern float vertexNormals[];
		extern float texCoords[];
		extern float colors[];
		extern unsigned int vertexCount;
	}

	class PianoBox: public Model {
		public:
			PianoBox();
			virtual ~PianoBox();
			virtual void drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM);
			void init();
	};

	extern PianoBox pianobox;
}

#endif
