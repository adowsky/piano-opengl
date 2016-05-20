#include "whitekeybs.h"



namespace Models {

    WhiteKeyBS whitekeybs;

    WhiteKeyBS::WhiteKeyBS(){
        vertices = WhiteKeyBSInternal::vertices;
        normals = WhiteKeyBSInternal::normals;
        vertexNormals = WhiteKeyBSInternal::vertexNormals;
        texCoords = WhiteKeyBSInternal::texCoords;
        colors = WhiteKeyBSInternal::colors;
        vertexCount = WhiteKeyBSInternal::vertexCount;
    }
    WhiteKeyBS::~WhiteKeyBS(){

    }

    void WhiteKeyBS::drawSolid(){ //TODO przekopiowane z Cube.cpp(sprawidzić czy wgl działa)

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

    namespace WhiteKeyBSInternal{
        unsigned int vertexCount = 72;
        float lenght = 0.26f;
        float height = 0.1f;
        float width = 0.022f;

        float vertices[] = {
        //góra cienka
        1.0f/3*width,height,3.0f/5*lenght,1.0f,
        1.0f/3*width,height,0,1.0f,
        2.0f/3*width,height,3.0f/5*lenght,1.0f,

        2.0f/3*width,height,0,1.0f,
        1.0f/3*width,height,0,1.0f,
        2.0f/3*width,height,3.0f/5*lenght,1.0f,

        //góra szeroka
        0,height,lenght,1.0f,
        0,height,3.0f/5*lenght,1.0f,
        width,height,lenght,1.0f,

        width,height,3.0f/5*lenght,1.0f,
        0,height,3.0f/5*lenght,1.0f,
        width,height,lenght,1.0f,

        //lewa sciana cienka
        1.0f/3*width,0.0f,0,1.0f,
        1.0f/3*width,0,3.0f/5*lenght,1.0f,
        1.0f/3*width,height,0,1.0f,

        1.0f/3*width,height,3.0f/5*lenght,1.0f,
        1.0f/3*width,0,3.0f/5*lenght,1.0f,
        1.0f/3*width,height,0,1.0f,

        //lewa ściana szeroka
        0,0.0f,3.0f/5*lenght,1.0f,
        0,0,lenght,1.0f,
        0,height,3.0f/5*lenght,1.0f,

        0,height,lenght,1.0f,
        0,0,lenght,1.0f,
        0,height,3.0f/5*lenght,1.0f,

        //tylna ściana cienka
        1.0f/3*width,0,0,1.0f,
        1.0f/3*width,height,0,1.0f,
        2.0f/3*width,0.0f,0,1.0f,

        2.0f/3*width,height,0,1.0f,
        1.0f/3*width,height,0,1.0f,
        2.0f/3*width,0.0f,0,1.0f,

        //tylna lewa szeroka
        0,0,3.0f/5*lenght,1.0f,
        0,height,3.0f/5*lenght,1.0f,
        1.0f/3*width,0.0f,3.0f/5*lenght,1.0f,

        1.0f/3*width,height,3.0f/5*lenght,1.0f,
        0,height,3.0f/5*lenght,1.0f,
        1.0f/3*width,0.0f,3.0f/5*lenght,1.0f,

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
        1.0f/3*width,0,3.0f/5*lenght,1.0f,
        1.0f/3*width,0,0,1.0f,
        2.0f/3*width,0,3.0f/5*lenght,1.0f,

        2.0f/3*width,0,0,1.0f,
        1.0f/3*width,0,0,1.0f,
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
            //lewa ściana szeroka
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

            //tylna ściana szeroka lewa
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
                1.0f/3*width,height,3.0f/5*lenght,1.0f,
                1.0f/3*width,height,0,1.0f,
                2.0f/3*width,height,3.0f/5*lenght,1.0f,

                2.0f/3*width,height,0,1.0f,
                1.0f/3*width,height,0,1.0f,
                2.0f/3*width,height,3.0f/5*lenght,1.0f,

                //góra szeroka
                0,height,lenght,1.0f,
                0,height,3.0f/5*lenght,1.0f,
                width,height,lenght,1.0f,

                width,height,3.0f/5*lenght,1.0f,
                0,height,3.0f/5*lenght,1.0f,
                width,height,lenght,1.0f,

                //lewa sciana cienka
                1.0f/3*width,0.0f,0,1.0f,
                1.0f/3*width,0,3.0f/5*lenght,1.0f,
                1.0f/3*width,height,0,1.0f,

                1.0f/3*width,height,3.0f/5*lenght,1.0f,
                1.0f/3*width,0,3.0f/5*lenght,1.0f,
                1.0f/3*width,height,0,1.0f,

                //lewa ściana szeroka
                0,0.0f,3.0f/5*lenght,1.0f,
                0,0,lenght,1.0f,
                0,height,3.0f/5*lenght,1.0f,

                0,height,lenght,1.0f,
                0,0,lenght,1.0f,
                0,height,3.0f/5*lenght,1.0f,

                //tylna ściana cienka
                1.0f/3*width,0,0,1.0f,
                1.0f/3*width,height,0,1.0f,
                2.0f/3*width,0.0f,0,1.0f,

                2.0f/3*width,height,0,1.0f,
                1.0f/3*width,height,0,1.0f,
                2.0f/3*width,0.0f,0,1.0f,

                //tylna lewa szeroka
                0,0,0,1.0f,
                0,height,0,1.0f,
                1.0f/3*width,0.0f,0,1.0f,

                1.0f/3*width,height,0,1.0f,
                0,height,0,1.0f,
                1.0f/3*width,0.0f,0,1.0f,

                //tylna prawa szeroka
                2.0f/3*width,0,0,1.0f,
                2.0f/3*width,height,0,1.0f,
                width,0.0f,0,1.0f,

                width,height,0,1.0f,
                2.0f/3*width,height,0,1.0f,
                width,0.0f,0,1.0f,

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
                1.0f/3*width,0,3.0f/5*lenght,1.0f,
                1.0f/3*width,0,0,1.0f,
                2.0f/3*width,0,3.0f/5*lenght,1.0f,

                2.0f/3*width,0,0,1.0f,
                1.0f/3*width,0,0,1.0f,
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
