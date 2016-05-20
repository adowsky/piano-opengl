#ifndef PIANOBOX_H
#define PIANOBOX_H

#include "model.h"

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
		void wall();
		public:
			PianoBox();
			virtual ~PianoBox();
			virtual void drawSolid();
	};

	extern PianoBox pianobox;
}

#endif
