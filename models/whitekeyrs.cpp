#include "whitekeyrs.h"



namespace Models {

    WhiteKeyRS whitekeyrs;

    WhiteKeyRS::WhiteKeyRS(){
    /*    vertices = WhiteKeyRSInternal::vertices;
        normals = WhiteKeyRSInternal::normals;
        vertexNormals = WhiteKeyRSInternal::vertexNormals;
        texCoords = WhiteKeyRSInternal::texCoords;
        colors = WhiteKeyRSInternal::colors;
        vertexCount = WhiteKeyRSInternal::vertexCount;

        std::vector<unsigned char> image; //Alokuj wektor do wczytania obrazka
        unsigned width, height; //Zmienne do których wczytamy wymiary obrazka
        //Wczytaj obrazek
        unsigned error = lodepng::decode(image, width, height, "whiteKeyLayer.png");
        //Import do pamięci karty graficznej
        glGenTextures(1,&tex); //Zainicjuj jeden uchwyt
        glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
        glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
        glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*) image.data());*/
    }
    WhiteKeyRS::~WhiteKeyRS(){
        //glDeleteTextures(1,&tex);
    }
    void WhiteKeyRS::init(){}
    void WhiteKeyRS::drawModel(glm::mat4 mP, glm::mat4 mV, glm::mat4 mM){
/*
        glEnable(GL_NORMALIZE);
        glBindTexture(GL_TEXTURE_2D,tex);
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
        float colors[]={
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
            float normals[]={
                //góra cienka
                0.0f,1.0f,0.0f,0.0f,
                0.0f,1.0f,0.0f,0.0f,
                0.0f,1.0f,0.0f,0.0f,

                0.0f,1.0f,0.0f,0.0f,
                0.0f,1.0f,0.0f,0.0f,
                0.0f,1.0f,0.0f,0.0f,

                //góra szeroka
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


                //tylna ściana cienka
                0.0f,0.0f,-1.0f,0.0f,
                0.0f,0.0f,-1.0f,0.0f,
                0.0f,0.0f,-1.0f,0.0f,

                0.0f,0.0f,-1.0f,0.0f,
                0.0f,0.0f,-1.0f,0.0f,
                0.0f,0.0f,-1.0f,0.0f,


                //tylna prawa szeroka
                0.0f,0.0f,-1.0f,0.0f,
                0.0f,0.0f,-1.0f,0.0f,
                0.0f,0.0f,-1.0f,0.0f,

                0.0f,0.0f,-1.0f,0.0f,
                0.0f,0.0f,-1.0f,0.0f,
                0.0f,0.0f,-1.0f,0.0f,

                //prawy bok cienki
                1.0f,0.0f,0.0f,0.0f,
                1.0f,0.0f,0.0f,0.0f,
                1.0f,0.0f,0.0f,0.0f,

                1.0f,0.0f,0.0f,0.0f,
                1.0f,0.0f,0.0f,0.0f,
                1.0f,0.0f,0.0f,0.0f,

                //prawy bok szeroki
                1.0f,0.0f,0.0f,0.0f,
                1.0f,0.0f,0.0f,0.0f,
                1.0f,0.0f,0.0f,0.0f,

                1.0f,0.0f,0.0f,0.0f,
                1.0f,0.0f,0.0f,0.0f,
                1.0f,0.0f,0.0f,0.0f,

                //dolny bok cienki
                0.0f,-1.0f,0.0f,0.0f,
                0.0f,-1.0f,0.0f,0.0f,
                0.0f,-1.0f,0.0f,0.0f,

                0.0f,-1.0f,0.0f,0.0f,
                0.0f,-1.0f,0.0f,0.0f,
                0.0f,-1.0f,0.0f,0.0f,

                //dolny bok szeroki
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

			float vertexNormals[]={
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

			float texCoords[]={
                0.0f,1.0f, 0.0f,0.0f, 1.0f,1.0f,
                1.0f,0.0f, 0.0f,0.0f, 1.0f,1.0f,

                //góra szeroka
                0.0f,1.0f, 0.0f,0.0f, 1.0f,1.0f,
                1.0f,0.0f, 0.0f,0.0f, 1.0f,1.0f,

                //lewa sciana
                0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f,
                1.0f,1.0f, 0.0f,1.0f, 1.0f,0.0f,

                //tylna ściana cienka
                0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f,
                1.0f,1.0f, 0.0f,1.0f, 1.0f,0.0f,

                //tylna lewa szeroka
                0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f,
                1.0f,1.0f, 0.0f,1.0f, 1.0f,0.0f,

                //tylna prawa szeroka
                0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f,
                1.0f,1.0f, 0.0f,1.0f, 1.0f,0.0f,

                //prawy bok cienki
                0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f,
                1.0f,1.0f, 0.0f,1.0f, 1.0f,0.0f,

                //prawy bok szeroki
                0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f,
                1.0f,1.0f, 0.0f,1.0f, 1.0f,0.0f,

                //dolny bok cienki
                0.0f,1.0f, 0.0f,0.0f, 1.0f,1.0f,
                1.0f,0.0f, 0.0f,0.0f, 1.0f,1.0f,

                //dolny bok szeroki
                0.0f,1.0f, 0.0f,0.0f, 1.0f,1.0f,
                1.0f,0.0f, 0.0f,0.0f, 1.0f,1.0f,

                //przednia ściana
                0.0f,0.0f, 0.0f,1.0f, 1.0f,0.0f,
                1.0f,1.0f, 0.0f,1.0f, 1.0f,0.0f,
			};
    }

}
