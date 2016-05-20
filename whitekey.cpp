#include "whitekey.h"


namespace Models {

    WhiteKey whitekey;

    WhiteKey::WhiteKey(){
        vertices = WhiteKeyInternal::vertices;
        normals = WhiteKeyInternal::normals;
        vertexNormals = WhiteKeyInternal::vertexNormals;
        texCoords = WhiteKeyInternal::texCoords;
        colors = WhiteKeyInternal::colors;
        vertexCount = WhiteKeyInternal::vertexCount;
    }
    WhiteKey::~WhiteKey(){

    }

    void WhiteKey::drawSolid(){ //TODO przekopiowane z Cube.cpp(sprawidzić czy wgl działa)

        glEnable(GL_NORMALIZE);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(4,GL_FLOAT,0,vertices);
		glColorPointer(4,GL_FLOAT,0,colors);
		glNormalPointer(GL_FLOAT,sizeof(float)*4,vertexNormals);
		//glTexCoordPointer(2,GL_FLOAT,0,texCoords);
        /*float Am[4] = {0, 0, 0, 0 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Am );

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Am );

        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Am );
        float f = 0.0f;
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, f );
*/
		glDrawArrays(GL_TRIANGLES,0,vertexCount);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    namespace WhiteKeyInternal{
        unsigned int vertexCount = 36;

        float vertices[] = {
        //góra
        0,0.1f,0.26f,1.0f,
        0,0.1f,0,1.0f,
        0.021f,0.1f,0.26f,1.0f,

        0.021f,0.1f,0,1.0f,
        0,0.1f,0,1.0f,
        0.021f,0.1f,0.26f,1.0f,

        //lewa sciana
        0,0.0f,0,1.0f,
        0,0,0.26f,1.0f,
        0,0.1f,0,1.0f,

        0,0.1f,0.26f,1.0f,
        0,0,0.26f,1.0f,
        0,0.1f,0,1.0f,

        //tylna ściana
        0,0,0,1.0f,
        0,0.1f,0,1.0f,
        0.021f,0.0f,0,1.0f,

        0.021f,0.1f,0,1.0f,
        0,0.1f,0,1.0f,
        0.021f,0.0f,0,1.0f,

        //prawy bok
        0.021f,0.0f,0,1.0f,
        0.021f,0,0.26f,1.0f,
        0.021f,0.1f,0,1.0f,

        0.021f,0.1f,0.26f,1.0f,
        0.021f,0,0.26f,1.0f,
        0.021f,0.1f,0,1.0f,

        //dolny bok
        0,0,0.26f,1.0f,
        0,0,0,1.0f,
        0.021f,0,0.26f,1.0f,

        0.021f,0,0,1.0f,
        0,0,0,1.0f,
        0.021f,0,0.26f,1.0f,


        //przednia ściana
        0,0,0.26f,1.0f,
        0,0.1f,0.26f,1.0f,
        0.021f,0.0f,0.26f,1.0f,

        0.021f,0.1f,0.26f,1.0f,
        0,0.1f,0.26f,1.0f,
        0.021f,0.0f,0.26f,1.0f,
        };
        float colors[]={//TODO to refactor
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            //lewa sciana
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            //tylna ściana
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            //prawy bok
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            //dolny bok
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,


            //przednia ściana
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,
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
                0,0.1f,0.27f,1.0f,
                0,0.1f,0,1.0f,
                0.0277f,0.1f,0.27f,1.0f,

                0.0277f,0.1f,0,1.0f,
                0,0.1f,0,1.0f,
                0.0277f,0.1f,0.27f,1.0f,

                //lewa sciana
                0,0.0f,0,1.0f,
                0,0,0.27f,1.0f,
                0,0.1f,0,1.0f,

                0,0.1f,0.27f,1.0f,
                0,0,0.27f,1.0f,
                0,0.1f,0,1.0f,

                //tylna ściana
                0,0,0,1.0f,
                0,0.1f,0,1.0f,
                0.0277f,0.0f,0,1.0f,

                0.0277f,0.1f,0,1.0f,
                0,0.1f,0,1.0f,
                0.0277f,0.0f,0,1.0f,

                //prawy bok
                0.0277f,0.0f,0,1.0f,
                0.0277f,0,0.27f,1.0f,
                0.0277f,0.1f,0,1.0f,

                0.0277f,0.1f,0.27f,1.0f,
                0.0277f,0,0.27f,1.0f,
                0.0277f,0.1f,0,1.0f,

                //dolny bok
                0,0,0.27f,1.0f,
                0,0,0,1.0f,
                0.0277f,0,0.27f,1.0f,

                0.0277f,0,0,1.0f,
                0,0,0,1.0f,
                0.0277f,0,0.27f,1.0f,


                //przednia ściana
                0,0,0.27f,1.0f,
                0,0.1f,0.27f,1.0f,
                0.0277f,0.0f,0.27f,1.0f,

                0.0277f,0.1f,0.27f,1.0f,
                0,0.1f,0.27f,1.0f,
                0.0277f,0.0f,0.27f,1.0f,
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
