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

        std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
        unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
        //Wczytaj obrazek
        unsigned error = lodepng::decode(image, width, height, "wood.png");
        if(error != 0)
        printf("error\n");
        //Import do pamięci karty graficznej
        glGenTextures(1,&tex); //Zainicjuj jeden uchwyt
        glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
        glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
        glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
         GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*) image.data());
    }
    PianoBox::~PianoBox(){
        glDeleteTextures(1,&tex);
    }

    void PianoBox::drawSolid(){ //TODO przekopiowane z Cube.cpp(sprawidzić czy wgl działa)

        glEnable(GL_NORMALIZE);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,tex);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY); //Włącz używanie tablicy wierzchołków
        glEnableClientState(GL_COLOR_ARRAY); //Włącz używanie tablicy kolorów
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glVertexPointer(4, GL_FLOAT, 0, vertices); //Wskaż tablicę wierzchołków
        glNormalPointer(GL_FLOAT,sizeof(float)*4,vertexNormals);
        glColorPointer(4, GL_FLOAT, 0, colors); //Wskaż tablicę kolorów
        glTexCoordPointer( 2, GL_FLOAT, 0, texCoords);
        glDrawArrays(GL_TRIANGLES, 0, 72); //Wykonaj rysowanie
    glEnableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY); //Wyłącz używanie tablicy wierzchołków
    glDisableClientState(GL_COLOR_ARRAY); //Wyłącz używanie tablicy kolorów
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
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

        //prawy bok klawiszy
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,

        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,

        //lewy bok klawiszy
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,

        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,

        //dół klawiszy
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,

        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,

        //front klawiszy
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,

        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,
        0.82f,0.74f,0.65f,1.0f,
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

                //prawy bok klawiszy
                1.0f,0.0f, 1.0f,1.0f, 0.0f,1.0f,
                1.0f,0.0f, 0.0f,0.0f, 0.0f,1.0f,

                //lewy bok klawiszy
                1.0f,0.0f, 1.0f,1.0f, 0.0f,1.0f,
                1.0f,0.0f, 0.0f,0.0f, 0.0f,1.0f,

                //dół klawiszy
                0.0f,1.0f, 1.0f,1.0f, 1.0f,0.0f,
                0.0f,1.0f, 0.0f,0.0f, 1.0f,0.0f,

                //front klawiszy
                0.0f,1.0f, 1.0f,1.0f, 1.0f,0.0f,
                0.0f,1.0f, 0.0f,0.0f, 1.0f,0.0f,
			};
    }

}
