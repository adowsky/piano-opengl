#include "pianocover.h"


namespace Models {

    PianoCover pianocover;

    PianoCover::PianoCover(){
        vertices = PianoCoverInternal::vertices;
        normals = PianoCoverInternal::normals;
        vertexNormals = PianoCoverInternal::vertexNormals;
        texCoords = PianoCoverInternal::texCoords;
        colors = PianoCoverInternal::colors;
        vertexCount = PianoCoverInternal::vertexCount;
    }
    PianoCover::~PianoCover(){

    }

    void PianoCover::drawSolid(){ //TODO przekopiowane z Cube.cpp(sprawidzić czy wgl działa)

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
        float Am[4] = {0.3f, 0.3f, 0.3f, 1.0f };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Am );

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

    namespace PianoCoverInternal{
        unsigned int vertexCount = 36;

        float vertices[] = {
        //góra
        -0.723f,0.002f,0,1.0f,
        -0.723f,0.002f,0.1375f,1.0f,
        0.723f,0.002f,0,1.0f,

        -0.723f,0.002f,0.1375f,1.0f,
        0.723f,0.002f,0,1.0f,
        0.723f,0.002f,0.1375f,1.0f,

        //lewa sciana
        -0.723f,0.0f,0,1.0f,
        -0.723f,0.002f,0.1375f,1.0f,
        -0.723f,0.002f,0,1.0f,

        -0.723f,0.0f,0,1.0f,
        -0.723f,0.002f,0.1375f,1.0f,
        -0.723f,0,-0.1375f,1.0f,

        //tylna ściana
        -0.723f,0.002f,0.1375f,1.0f,
        0.723f,0.002f,0.1375f,1.0f,
        -0.723f,0.0f,0.1375f,1.0f,

        0.723f,0.0f,0.1375f,1.0f,
        0.723f,0.002f,0.1375f,1.0f,
        -0.723f,0.0f,0.1375f,1.0f,

        //prawy bok
        0.723f,0.0f,0,1.0f,
        0.723f,0.002f,0.1375f,1.0f,
        0.723f,0.002f,0,1.0f,

        0.723f,0.0f,0,1.0f,
        0.723f,0.002f,0.1375f,1.0f,
        0.723f,0,0.1375f,1.0f,

        //dolny bok
        -0.723f,0.0f,0,1.0f,
        -0.723f,0.0f,0.1375f,1.0f,
        0.723f,0.0f,0,1.0f,

        -0.723f,0.0f,0.1375f,1.0f,
        0.723f,0.0f,0,1.0f,
        0.723f,0.0f,0.1375f,1.0f,


        //przednia ściana
        -0.723f,0.002f,0.0f,1.0f,
        0.723f,0.002f,0.0f,1.0f,
        -0.723f,0.0f,0.0f,1.0f,

        0.723f,0.0f,0.0f,1.0f,
        0.723f,0.002f,0.0f,1.0f,
        -0.723f,0.0f,0.0f,1.0f,


        };
        float colors[]={//TODO to refactor
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
                -0.723f,0.002f,0,1.0f,
                -0.723f,0.002f,-0.1375f,1.0f,
                0.723f,0.002f,0,1.0f,

                -0.723f,0.002f,-0.1375f,1.0f,
                0.723f,0.002f,0,1.0f,
                0.723f,0.002f,-0.1375f,1.0f,

                //lewa sciana
                -0.723f,0.0f,0,1.0f,
                -0.723f,0.002f,-0.1375f,1.0f,
                -0.723f,0.002f,0,1.0f,

                -0.723f,0.0f,0,1.0f,
                -0.723f,0.002f,-0.1375f,1.0f,
                -0.723f,0,-0.1375f,1.0f,

                //tylna ściana
                -0.723f,0.002f,-0.1375f,1.0f,
                0.723f,0.002f,-0.1375f,1.0f,
                -0.723f,0.0f,-0.1375f,1.0f,

                0.723f,0.0f,-0.1375f,1.0f,
                0.723f,0.002f,-0.1375f,1.0f,
                -0.723f,0.0f,-0.1375f,1.0f,

                //prawy bok
                0.723f,0.0f,0,1.0f,
                0.723f,0.002f,-0.1375f,1.0f,
                0.723f,0.002f,0,1.0f,

                0.723f,0.0f,0,1.0f,
                0.723f,0.002f,-0.1375f,1.0f,
                0.723f,0,-0.1375f,1.0f,

                //dolny bok
                -0.723f,0.0f,0,1.0f,
                -0.723f,0.0f,-0.1375f,1.0f,
                0.723f,0.0f,0,1.0f,

                -0.723f,0.0f,-0.1375f,1.0f,
                0.723f,0.0f,0,1.0f,
                0.723f,0.0f,-0.1375f,1.0f,


                //przednia ściana
                -0.723f,0.002f,0.0f,1.0f,
                0.723f,0.002f,0.0f,1.0f,
                -0.723f,0.0f,0.0f,1.0f,

                0.723f,0.0f,0.0f,1.0f,
                0.723f,0.002f,0.0f,1.0f,
                -0.723f,0.0f,0.0f,1.0f,
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
