#include "pianobox.h"

namespace Models {

    PianoBox pianobox;

    PianoBox::PianoBox(){
        vertices = PianoBoxInternal::vertices;
        normals = PianoBoxInternal::normals;
        vertexNormals = PianoBoxInternal::vertexNormals;
        texCoords = PianoBoxInternal::texCoords;
        colors = PianoBoxInternal::colors;
        vertexCount = PianoBoxInternal::vertexCount;
    }
    PianoBox::~PianoBox(){

    }
    void PianoBox::wall() {

	}
    void PianoBox::drawSolid(){ //TODO przekopiowane z Cube.cpp(sprawidzić czy wgl działa)

        glEnable(GL_NORMALIZE);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(4,GL_FLOAT,0,vertices);
		glColorPointer(4,GL_FLOAT,0,colors);
		glNormalPointer(GL_FLOAT,sizeof(float)*4,vertexNormals);
		//glTexCoordPointer(2,GL_FLOAT,0,texCoords);
/*
        float Am[4] = {0.1f,0.1f,0.1f,1};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Am );*/
/*
        float Dm[4] = {0.9f, 0.5f, 0.5f, 1.0f };
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Dm );

        float Sm[4] = {0.6f, 0.6f, 0.6f, 1.0f };
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Sm );
        float f = 60.0f;
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, f );
*/
		glDrawArrays(GL_TRIANGLES,0,vertexCount);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    namespace PianoBoxInternal{
        unsigned int vertexCount = 72;

        float vertices[] = {
        //nieruchliwa góra
        -0.723f,0.602f,-0.275f,1.0f,
        -0.723f,0.602f,-0.1375f,1.0f,
        0.723f,0.602f,-0.275f,1.0f,

        -0.723f,0.602f,-0.1375f,1.0f,
        0.723f,0.602f,-0.275f,1.0f,
        0.723f,0.602f,-0.1375f,1.0f,

        //lewa sciana
        -0.723f,0.602f,-0.275f,1.0f,
        -0.723f,0.602f,-0.0f,1.0f,
        -0.723f,-0.602f,-0.275f,1.0f,

        -0.723f,-0.602f,0.0f,1.0f,
        -0.723f,0.602f,0.0f,1.0f,
        -0.723f,-0.602f,-0.275f,1.0f,

        //tylna ściana
        -0.723f,0.602f,-0.275f,1.0f,
        0.723f,0.602f,-0.275f,1.0f,
        -0.723f,-0.602f,-0.275f,1.0f,

        0.723f,-0.602f,-0.275f,1.0f,
        0.723f,0.602f,-0.275f,1.0f,
        -0.723f,-0.602f,-0.275f,1.0f,

        //prawy bok
        0.723f,0.602f,-0.275f,1.0f,
        0.723f,0.602f,-0.0f,1.0f,
        0.723f,-0.602f,-0.275f,1.0f,

        0.723f,-0.602f,0.0f,1.0f,
        0.723f,0.602f,0.0f,1.0f,
        0.723f,-0.602f,-0.275f,1.0f,

        //dolny bok
        -0.723f, -0.602f, -0.275f,1.0f,
        -0.723f, -0.602f, 0.0f,1.0f,
        0.723f, -0.602f, -0.275f,1.0f,

        0.723f, -0.602f, 0.0f,1.0f,
        -0.723f, -0.602f, 0.0f,1.0f,
        0.723f, -0.602f, -0.275f,1.0f,

        //przednia ściana
        -0.723f,0.602f,0.0f,1.0f,
        0.723f,0.602f,0.0f,1.0f,
        -0.723f,-0.602f,0.0f,1.0f,

        0.723f,-0.602f,0.0f,1.0f,
        0.723f,0.602f,0.0f,1.0f,
        -0.723f,-0.602f,0.0f,1.0f,

        //prawy bok klawiszy
        0.723f, 0.15f, 0.0f, 1.0f,
        0.723f, 0.15f, 0.27f, 1.0f,
        0.723f, -0.15f, 0.27f, 1.0f,

        0.723f, 0.15f, 0.0f, 1.0f,
        0.723f, -0.15f, 0.0f, 1.0f,
        0.723f, -0.15f, 0.27f, 1.0f,

        //lewy bok klawiszy
        -0.723f, 0.15f, 0.0f, 1.0f,
        -0.723f, 0.15f, 0.27f, 1.0f,
        -0.723f, -0.15f, 0.27f, 1.0f,

        -0.723f, 0.15f, 0.0f, 1.0f,
        -0.723f, -0.15f, 0.0f, 1.0f,
        -0.723f, -0.15f, 0.27f, 1.0f,

        //dół klawiszy
        -0.723f,-0.15f,0.27f,1.0f,
        0.723f,-0.15f,0.27f,1.0f,
        0.723f,-0.15f,0.0f,1.0f,

        -0.723f,-0.15f,0.27f,1.0f,
        -0.723f,-0.15f,0.0f,1.0f,
        0.723f,-0.15f,0.0f,1.0f,

        //front klawiszy
        -0.723f,0.05f,0.27f,1.0f,
        0.723f,0.05f,0.27f,1.0f,
        0.723f,-0.15f,0.27f,1.0f,

        -0.723f,0.05f,0.27f,1.0f,
        -0.723f,-0.15f,0.27f,1.0f,
        0.723f,-0.15f,0.27f,1.0f,

        };
        float colors[]={//TODO to refactor
                //nieruchliwa góra
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        //lewa sciana
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        //tylna ściana
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        //prawy bok
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        //dolny bok
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        //przednia ściana
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        //prawy bok klawiszy
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        //lewy bok klawiszy
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        //dół klawiszy
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        //front klawiszy
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,

        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
        0.196f,0.121f,0.004f,1.0f,
			};
            float normals[]={//TODO to refactor
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,

				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,

				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,

				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
			};

			float vertexNormals[]={//TODO to refactor
                //nieruchliwa góra
                -0.723f,0.602f,-0.275f,1.0f,
                -0.723f,0.602f,-0.1375f,1.0f,
                0.723f,0.602f,-0.275f,1.0f,

                -0.723f,0.602f,-0.1375f,1.0f,
                0.723f,0.602f,-0.275f,1.0f,
                0.723f,0.602f,-0.1375f,1.0f,

                //lewa sciana
                -0.723f,0.602f,-0.275f,1.0f,
                -0.723f,0.602f,-0.0f,1.0f,
                -0.723f,-0.602f,-0.275f,1.0f,

                -0.723f,-0.602f,0.0f,1.0f,
                -0.723f,0.602f,0.0f,1.0f,
                -0.723f,-0.602f,-0.275f,1.0f,

                //tylna ściana
                -0.723f,0.602f,-0.275f,1.0f,
                0.723f,0.602f,-0.275f,1.0f,
                -0.723f,-0.602f,-0.275f,1.0f,

                0.723f,-0.602f,-0.275f,1.0f,
                0.723f,0.602f,-0.275f,1.0f,
                -0.723f,-0.602f,-0.275f,1.0f,

                //prawy bok
                0.723f,0.602f,-0.275f,1.0f,
                0.723f,0.602f,-0.0f,1.0f,
                0.723f,-0.602f,-0.275f,1.0f,

                0.723f,-0.602f,0.0f,1.0f,
                0.723f,0.602f,0.0f,1.0f,
                0.723f,-0.602f,-0.275f,1.0f,

                //dolny bok
                -0.723f, -0.602f, -0.275f,1.0f,
                -0.723f, -0.602f, 0.0f,1.0f,
                0.723f, -0.602f, -0.275f,1.0f,

                0.723f, -0.602f, 0.0f,1.0f,
                -0.723f, -0.602f, 0.0f,1.0f,
                0.723f, -0.602f, -0.275f,1.0f,

                //przednia ściana
                -0.723f,0.602f,0.0f,1.0f,
                0.723f,0.602f,0.0f,1.0f,
                -0.723f,-0.602f,0.0f,1.0f,

                0.723f,-0.602f,0.0f,1.0f,
                0.723f,0.602f,0.0f,1.0f,
                -0.723f,-0.602f,0.0f,1.0f,

                //prawy bok klawiszy
                0.723f, 0.15f, 0.0f, 1.0f,
                0.723f, 0.15f, 0.27f, 1.0f,
                0.723f, -0.15f, 0.27f, 1.0f,

                0.723f, 0.15f, 0.0f, 1.0f,
                0.723f, -0.15f, 0.0f, 1.0f,
                0.723f, -0.15f, 0.27f, 1.0f,

                //lewy bok klawiszy
                -0.723f, 0.15f, 0.0f, 1.0f,
                -0.723f, 0.15f, 0.27f, 1.0f,
                -0.723f, -0.15f, 0.27f, 1.0f,

                -0.723f, 0.15f, 0.0f, 1.0f,
                -0.723f, -0.15f, 0.0f, 1.0f,
                -0.723f, -0.15f, 0.27f, 1.0f,

                //dół klawiszy
                -0.723f,-0.15f,0.27f,1.0f,
                0.723f,-0.15f,0.27f,1.0f,
                0.723f,-0.15f,0.0f,1.0f,

                -0.723f,-0.15f,0.27f,1.0f,
                -0.723f,-0.15f,0.0f,1.0f,
                0.723f,-0.15f,0.0f,1.0f,

                //front klawiszy
                -0.723f,0.15f,0.27f,1.0f,
                0.723f,0.15f,0.27f,1.0f,
                0.723f,-0.15f,0.27f,1.0f,

                -0.723f,0.15f,0.27f,1.0f,
                -0.723f,-0.15f,0.27f,1.0f,
                0.723f,-0.15f,0.27f,1.0f
			};

			float texCoords[]={//TODO to refactor
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,
			};
    }

}
