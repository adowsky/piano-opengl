#include "platform.h"

namespace Models {
    Platform platform;

    Platform::Platform(){
        /*vertices = PlatformInternal::vertices;
        normals = PlatformInternal::normals;
        vertexNormals = PlatformInternal::vertexNormals;
        texCoords = PlatformInternal::texCoords;
        colors = PlatformInternal::colors;
        vertexCount = PlatformInternal::vertexCount;*/
    }
    Platform::~Platform(){

    }
    void Platform::init(){}
    void Platform::drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM){
        /*glEnable(GL_NORMALIZE);
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
		//glDisableClientState(GL_TEXTURE_COORD_ARRAY);*/
    }

    namespace PlatformInternal{
        unsigned int vertexCount = 36;

        float vertices[]={
            //left
            -2.0f,1.0f,2.0f,1.0f,
            -2.0f,0.0f,2.0f,1.0f,
            -2.0f,0.0f,-2.0f,1.0f,

            -2.0f,1.0f,2.0f,1.0f,
            -2.0f,1.0f,-2.0f,1.0f,
            -2.0f,0.0f,-2.0f,1.0f,

            //front
            -2.0f,1.0f,-2.0f,1.0f,
            2.0f,1.0f,-2.0f,1.0f,
            -2.0f,0.0f,-2.0f,1.0f,


            2.0f,0.0f,-2.0f,1.0f,
            2.0f,1.0f,-2.0f,1.0f,
            -2.0f,0.0f,-2.0f,1.0f,

            //right
            2.0f,0.0f,-2.0f,1.0f,
            2.0f,1.0f,-2.0f,1.0f,
            2.0f,0.0f,2.0f,1.0f,

            2.0f,1.0f,2.0f,1.0f,
            2.0f,1.0f,-2.0f,1.0f,
            2.0f,0.0f,2.0f,1.0f,

            //back
            2.0f,1.0f,2.0f,1.0f,
            -2.0f,1.0f,2.0f,1.0f,
            2.0f,0.0f,2.0f,1.0f,

            -2.0f,0.0f,2.0f,1.0f,
            -2.0f,1.0f,2.0f,1.0f,
            2.0f,0.0f,2.0f,1.0f,

            //top
            -2.0f,1.0f,2.0f,1.0f,
            2.0f,1.0f,2.0f,1.0f,
            2.0f,1.0f,-2.0f,1.0f,

            -2.0f,1.0f,-2.0f,1.0f,
            -2.0f,1.0f,2.0f,1.0f,
            2.0f,1.0f,-2.0f,1.0f,

            //bottom
            -2.0f,0.0f,2.0f,1.0f,
            2.0f,0.0f,2.0f,1.0f,
            2.0f,0.0f,-2.0f,1.0f,

            -2.0f,0.0f,-2.0f,1.0f,
            -2.0f,0.0f,2.0f,1.0f,
            2.0f,0.0f,-2.0f,1.0f
        };

            float colors[] = {
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,

                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f,
                0.41f,0.19f,0.22f,1.0f
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
            float vertexNormals[]={
                //left
                -2.0f,1.0f,2.0f,1.0f,
                -2.0f,0.0f,2.0f,1.0f,
                -2.0f,0.0f,-2.0f,1.0f,

                -2.0f,1.0f,2.0f,1.0f,
                -2.0f,1.0f,-2.0f,1.0f,
                -2.0f,0.0f,-2.0f,1.0f,

                //front
                -2.0f,1.0f,-2.0f,1.0f,
                2.0f,1.0f,-2.0f,1.0f,
                -2.0f,0.0f,-2.0f,1.0f,


                2.0f,0.0f,-2.0f,1.0f,
                2.0f,1.0f,-2.0f,1.0f,
                -2.0f,0.0f,-2.0f,1.0f,

                //right
                2.0f,0.0f,-2.0f,1.0f,
                2.0f,1.0f,-2.0f,1.0f,
                2.0f,0.0f,2.0f,1.0f,

                2.0f,1.0f,2.0f,1.0f,
                2.0f,1.0f,-2.0f,1.0f,
                2.0f,0.0f,2.0f,1.0f,

                //back
                2.0f,1.0f,2.0f,1.0f,
                -2.0f,1.0f,2.0f,1.0f,
                2.0f,0.0f,2.0f,1.0f,

                -2.0f,0.0f,2.0f,1.0f,
                -2.0f,1.0f,2.0f,1.0f,
                2.0f,0.0f,2.0f,1.0f,

                //top
                -2.0f,1.0f,2.0f,1.0f,
                2.0f,1.0f,2.0f,1.0f,
                2.0f,1.0f,-2.0f,1.0f,

                -2.0f,1.0f,-2.0f,1.0f,
                -2.0f,1.0f,2.0f,1.0f,
                2.0f,1.0f,-2.0f,1.0f,

                //bottom
                -2.0f,0.0f,2.0f,1.0f,
                2.0f,0.0f,2.0f,1.0f,
                2.0f,0.0f,-2.0f,1.0f,

                -2.0f,0.0f,-2.0f,1.0f,
                -2.0f,0.0f,2.0f,1.0f,
                2.0f,0.0f,-2.0f,1.0f
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
