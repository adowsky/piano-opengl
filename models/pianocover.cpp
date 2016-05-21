#include "pianocover.h"


namespace Models {

    PianoCover pianocover;

    PianoCover::PianoCover(){

    }
    PianoCover::~PianoCover(){

    }
    void PianoCover::init(){
        
    }
    void PianoCover::drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM){ //TODO przekopiowane z Cube.cpp(sprawidzić czy wgl działa)
/*
        glEnable(GL_NORMALIZE);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(4,GL_FLOAT,0,vertices);
		glColorPointer(4,GL_FLOAT,0,colors);
		glNormalPointer(GL_FLOAT,sizeof(float)*4,vertexNormals);
		glTexCoordPointer(2,GL_FLOAT,0,texCoords);
		glDrawArrays(GL_TRIANGLES,0,vertexCount);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);*/
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
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            //lewa sciana
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            //tylna ściana
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            //prawy bok
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            //dolny bok
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,


            //przednia ściana
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,

            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
            0.82f,0.74f,0.65f,1.0f,
			};
            float normals[]={//TODO to refactor
        //góra
        0.0f,1.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,0.0f,

        0.0f,1.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,0.0f,

        //lewa sciana
        -1.0f,0.0f,0.0f,0.0f,
        -1.0f,0.0f,0.0f,0.0f,
        -1.0f,0.0f,0.0f,0.0f,

        -1.0f,0.0f,0.0f,0.0f,
        -1.0f,0.0f,0.0f,0.0f,
        -1.0f,0.0f,0.0f,0.0f,

        //tylna ściana
        0.0f,0.0f,-1.0f,0.0f,
        0.0f,0.0f,-1.0f,0.0f,
        0.0f,0.0f,-1.0f,0.0f,

        0.0f,0.0f,-1.0f,0.0f,
        0.0f,0.0f,-1.0f,0.0f,
        0.0f,0.0f,-1.0f,0.0f,

        //prawy bok
        1.0f,0.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,0.0f,

        1.0f,0.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,0.0f,
        //dolny bok
        0.0f,-1.0f,0.0f,0.0f,
        0.0f,-1.0f,0.0f,0.0f,
        0.0f,-1.0f,0.0f,0.0f,

        0.0f,-1.0f,0.0f,0.0f,
        0.0f,-1.0f,0.0f,0.0f,
        0.0f,-1.0f,0.0f,0.0f,

        //przednia ściana
        0.0f,0.0f,1.0f,0.0f,
        0.0f,0.0f,1.0f,0.0f,
        0.0f,0.0f,1.0f,0.0f,

        0.0f,0.0f,1.0f,0.0f,
        0.0f,0.0f,1.0f,0.0f,
        0.0f,0.0f,1.0f,0.0f,
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
                //nieruchliwa góra
                0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f,
                0.0f,1.0f, 1.0f,0.0f, 1.0f,1.0f,

                //lewa sciana
                1.0f,0.0f, 1.0f,1.0f, 0.0f,0.0f,
                0.0f,1.0f, 1.0f,1.0f, 0.0f,0.0f,

                //tylna ściana
                0.0f,1.0f, 1.0f,1.0f, 0.0f,0.0f,
                1.0f,0.0f, 1.0f,1.0f, 0.0f,0.0f,

                //prawy bok
                1.0f,0.0f, 1.0f,1.0f, 0.0f,0.0f,
                0.0f,1.0f, 1.0f,1.0f, 0.0f,0.0f,

                //dolny bok
                0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f,
                1.0f,1.0f, 0.0f,1.0f, 1.0f,0.0f,
                //przednia ściana
                0.0f,1.0f, 1.0f,1.0f, 0.0f,0.0f,
                1.0f,0.0f, 1.0f,1.0f, 0.0f,0.0f,

			};
    }

}
