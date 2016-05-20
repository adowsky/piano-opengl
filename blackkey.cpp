#include "blackkey.h"



namespace Models {

    BlackKey blackkey;

    BlackKey::BlackKey(){
        vertices = BlackKeyInternal::vertices;
        normals = BlackKeyInternal::normals;
        vertexNormals = BlackKeyInternal::vertexNormals;
        texCoords = BlackKeyInternal::texCoords;
        colors = BlackKeyInternal::colors;
        vertexCount = BlackKeyInternal::vertexCount;
    }
    BlackKey::~BlackKey(){

    }

    void BlackKey::drawSolid(){ //TODO przekopiowane z Cube.cpp(sprawidzić czy wgl działa)

        glEnable(GL_NORMALIZE);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(4,GL_FLOAT,0,vertices);
		glColorPointer(4,GL_FLOAT,0,colors);
		glNormalPointer(GL_FLOAT,sizeof(float)*4,vertexNormals);
		//glTexCoordPointer(2,GL_FLOAT,0,texCoords);

		glDrawArrays(GL_TRIANGLES,0,vertexCount);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    namespace BlackKeyInternal{
        unsigned int vertexCount = 36;
        float lenght = 0.156f;
        float height = 0.12f;
        float width = 0.025f;

        float vertices[] = {
        //góra
        0,height,lenght,1.0f,
        0,height,0,1.0f,
        width,height,lenght,1.0f,

        width,height,0,1.0f,
        0,height,0,1.0f,
        width,height,lenght,1.0f,

        //lewa sciana
        0,0.0f,0,1.0f,
        0,0,lenght,1.0f,
        0,height,0,1.0f,

        0,height,lenght,1.0f,
        0,0,lenght,1.0f,
        0,height,0,1.0f,

        //tylna ściana
        0,0,0,1.0f,
        0,height,0,1.0f,
        width,0.0f,0,1.0f,

        width,height,0,1.0f,
        0,height,0,1.0f,
        width,0.0f,0,1.0f,

        //prawy bok
        width,0.0f,0,1.0f,
        width,0,lenght,1.0f,
        width,height,0,1.0f,

        width,height,lenght,1.0f,
        width,0,lenght,1.0f,
        width,height,0,1.0f,

        //dolny bok
        0,0,lenght,1.0f,
        0,0,0,1.0f,
        width,0,lenght,1.0f,

        width,0,0,1.0f,
        0,0,0,1.0f,
        width,0,lenght,1.0f,
        //przednia ściana
        0,0,lenght,1.0f,
        0,height,lenght,1.0f,
        width,0.0f,lenght,1.0f,

        width,height,lenght,1.0f,
        0,height,lenght,1.0f,
        width,0.0f,lenght,1.0f,
        };
        float colors[]={//TODO to refactor
            //góra
            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            //lewa sciana
            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            //tylna ściana
            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            //prawy bok
            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            //dolny bok
            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            //przednia ściana
            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,

            0,0,0,1.0f,
            0,0,0,1.0f,
            0,0,0,1.0f,
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
                //góra
                0,height,lenght,1.0f,
                0,height,0,1.0f,
                width,height,lenght,1.0f,

                width,height,0,1.0f,
                0,height,0,1.0f,
                width,height,lenght,1.0f,

                //lewa sciana
                0,0.0f,0,1.0f,
                0,0,lenght,1.0f,
                0,height,0,1.0f,

                0,height,lenght,1.0f,
                0,0,lenght,1.0f,
                0,height,0,1.0f,

                //tylna ściana
                0,0,0,1.0f,
                0,height,0,1.0f,
                width,0.0f,0,1.0f,

                width,height,0,1.0f,
                0,height,0,1.0f,
                width,0.0f,0,1.0f,

                //prawy bok
                width,0.0f,0,1.0f,
                width,0,lenght,1.0f,
                width,height,0,1.0f,

                width,height,lenght,1.0f,
                width,0,lenght,1.0f,
                width,height,0,1.0f,

                //dolny bok
                0,0,lenght,1.0f,
                0,0,0,1.0f,
                width,0,lenght,1.0f,

                width,0,0,1.0f,
                0,0,0,1.0f,
                width,0,lenght,1.0f,
                //przednia ściana
                0,0,lenght,1.0f,
                0,height,lenght,1.0f,
                width,0.0f,lenght,1.0f,

                width,height,lenght,1.0f,
                0,height,lenght,1.0f,
                width,0.0f,lenght,1.0f,
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
