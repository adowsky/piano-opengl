#include "whitekeyrs.h"



namespace Models {

    WhiteKeyRS whitekeyrs;

    WhiteKeyRS::WhiteKeyRS(){
        vertices = WhiteKeyRSInternal::vertices;
        normals = WhiteKeyRSInternal::normals;
        vertexNormals = WhiteKeyRSInternal::vertexNormals;
        texCoords = WhiteKeyRSInternal::texCoords;
        colors = WhiteKeyRSInternal::colors;
        vertexCount = WhiteKeyRSInternal::vertexCount;
    }
    WhiteKeyRS::~WhiteKeyRS(){

    }

    void WhiteKeyRS::drawSolid(){ //TODO przekopiowane z Cube.cpp(sprawidzić czy wgl działa)

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

    namespace WhiteKeyRSInternal{
        unsigned int vertexCount = 60;
        float lenght = 0.26f;
        float height = 0.1f;
        float width = 0.022f;

        float vertices[] = {
        //góra cienka
        0,height,3.0f/5*lenght,1.0f,
        0,height,0,1.0f,
        2.0f/3*width,height,3.0f/5*lenght,1.0f,

        2.0f/3*width,height,0,1.0f,
        0,height,0,1.0f,
        2.0f/3*width,height,3.0f/5*lenght,1.0f,

        //góra szeroka
        0,height,lenght,1.0f,
        0,height,3.0f/5*lenght,1.0f,
        width,height,lenght,1.0f,

        width,height,3.0f/5*lenght,1.0f,
        0,height,3.0f/5*lenght,1.0f,
        width,height,lenght,1.0f,

        //lewa sciana
        0,0.0f,0,1.0f,
        0,0,lenght,1.0f,
        0,height,0,1.0f,

        0,height,lenght,1.0f,
        0,0,lenght,1.0f,
        0,height,0,1.0f,

        //tylna ściana cienka
        0,0,0,1.0f,
        0,height,0,1.0f,
        2.0f/3*width,0.0f,0,1.0f,

        2.0f/3*width,height,0,1.0f,
        0,height,0,1.0f,
        2.0f/3*width,0.0f,0,1.0f,


        //tylna prawa szeroka
        2.0f/3*width,0,3.0f/5*lenght,1.0f,
        2.0f/3*width,height,3.0f/5*lenght,1.0f,
        width,0.0f,3.0f/5*lenght,1.0f,

        width,height,3.0f/5*lenght,1.0f,
        2.0f/3*width,height,3.0f/5*lenght,1.0f,
        width,0.0f,3.0f/5*lenght,1.0f,

        //prawy bok cienki
        2.0f/3*width,0.0f,0,1.0f,
        2.0f/3*width,0,3.0f/5*lenght,1.0f,
        2.0f/3*width,height,0,1.0f,

        2.0f/3*width,height,3.0f/5*lenght,1.0f,
        2.0f/3*width,0,3.0f/5*lenght,1.0f,
        2.0f/3*width,height,0,1.0f,

        //prawy bok szeroki
        width,0.0f,3.0f/5*lenght,1.0f,
        width,0,lenght,1.0f,
        width,height,3.0f/5*lenght,1.0f,

        width,height,lenght,1.0f,
        width,0,lenght,1.0f,
        width,height,3.0f/5*lenght,1.0f,

        //dolny bok cienki
        0,0,3.0f/5*lenght,1.0f,
        0,0,0,1.0f,
        2.0f/3*width,0,3.0f/5*lenght,1.0f,

        2.0f/3*width,0,0,1.0f,
        0,0,0,1.0f,
        2.0f/3*width,0,3.0f/5*lenght,1.0f,

        //dolny bok szeroki
        0,0,lenght,1.0f,
        0,0,3.0f/5*lenght,1.0f,
        width,0,lenght,1.0f,

        width,0,3.0f/5*lenght,1.0f,
        0,0,3.0f/5*lenght,1.0f,
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
            //góra wąska
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,
            //góra szeroka
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            //lewa sciana wąska
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            //tylna ściana wąska
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            //tylna ściana szeroka prawa
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            //prawy bok wąski
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,
            //prawy bok szeroki
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            //dolny bok wąski
            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,

            1,1,1,1.0f,
            1,1,1,1.0f,
            1,1,1,1.0f,
            //dolny bok szeroki
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
                //góra cienka
                0,height,3.0f/5*lenght,1.0f,
                0,height,0,1.0f,
                0,height,3.0f/5*lenght,1.0f,

                2.0f/3*width,height,0,1.0f,
                0,height,0,1.0f,
                2.0f/3*width,height,3.0f/5*lenght,1.0f,

                //góra szeroka
                0,height,lenght,1.0f,
                0,height,3.0f/5*lenght,1.0f,
                width,height,lenght,1.0f,

                width,height,3.0f/5*lenght,1.0f,
                0,height,3.0f/5*lenght,1.0f,
                width,height,lenght,1.0f,

                //lewa sciana
                0,0.0f,0,1.0f,
                0,0,lenght,1.0f,
                0,height,0,1.0f,

                0,height,lenght,1.0f,
                0,0,lenght,1.0f,
                0,height,0,1.0f,

                //tylna ściana cienka
                0,0,0,1.0f,
                0,height,0,1.0f,
                2.0f/3*width,0.0f,0,1.0f,

                2.0f/3*width,height,0,1.0f,
                0,height,0,1.0f,
                2.0f/3*width,0.0f,0,1.0f,


                //tylna prawa szeroka
                2.0f/3*width,0,3.0f/5*lenght,1.0f,
                2.0f/3*width,height,3.0f/5*lenght,1.0f,
                width,0.0f,3.0f/5*lenght,1.0f,

                width,height,3.0f/5*lenght,1.0f,
                2.0f/3*width,height,3.0f/5*lenght,1.0f,
                width,0.0f,3.0f/5*lenght,1.0f,

                //prawy bok cienki
                2.0f/3*width,0.0f,0,1.0f,
                2.0f/3*width,0,3.0f/5*lenght,1.0f,
                2.0f/3*width,height,0,1.0f,

                2.0f/3*width,height,3.0f/5*lenght,1.0f,
                2.0f/3*width,0,3.0f/5*lenght,1.0f,
                2.0f/3*width,height,0,1.0f,

                //prawy bok szeroki
                width,0.0f,3.0f/5*lenght,1.0f,
                width,0,lenght,1.0f,
                width,height,3.0f/5*lenght,1.0f,

                width,height,lenght,1.0f,
                width,0,lenght,1.0f,
                width,height,3.0f/5*lenght,1.0f,

                //dolny bok cienki
                0,0,3.0f/5*lenght,1.0f,
                0,0,0,1.0f,
                2.0f/3*width,0,3.0f/5*lenght,1.0f,

                2.0f/3*width,0,0,1.0f,
                0,0,0,1.0f,
                2.0f/3*width,0,3.0f/5*lenght,1.0f,

                //dolny bok szeroki
                0,0,lenght,1.0f,
                0,0,3.0f/5*lenght,1.0f,
                width,0,lenght,1.0f,

                width,0,3.0f/5*lenght,1.0f,
                0,0,3.0f/5*lenght,1.0f,
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
                //góra cienka
                0,height, 0,height, 2.0f/3*width,height,
                2.0f/3*width, 0,height, 2.0f/3*width,height,
                //góra szeroka
                0,height, 0,height, width,height,
                width,height, 0,height, width,height,
                //lewa sciana
                0,0.0f, 0,0, 0,height,
                0,height, 0,0, 0,height,
                //tylna ściana cienka
                0,0, 0,height, 2.0f/3*width,
                2.0f/3*width,height, 0,height, 2.0f/3*width,0.0f,
                //tylna prawa szeroka
                2.0f/3*width,0, 2.0f/3*width,height, width,0.0f,
                width,height, 2.0f/3*width,height, width,0.0f,
                //prawy bok cienki
                2.0f/3*width, 2.0f/3*width,0, 2.0f/3*width,height,
                2.0f/3*width,height, 2.0f/3*width,0, 2.0f/3*width,height,
                //prawy bok szeroki
                width,0.0f, width,0, width,height,
                width,height, width,0, width,height,
                //dolny bok cienki
                0,0, 0,0, 2.0f/3*width,0,
                2.0f/3*width,0, 0,0, 2.0f/3*width,0,
                //dolny bok szeroki
                0,0, 0,0, width,0,
                width,0, 0,0, width,0,
                //przednia ściana
                0,0, 0,height, width,0.0f,
                width,height, 0,height, width,0.0f,
			};
    }

}
