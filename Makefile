LIBS=-lGL -lglfw -lGLEW  -lftgl -I/usr/include/freetype2
FILES=main.cpp piano.cpp cube.cpp model.cpp lodepng.cpp utils.cpp models/shaderprogram.cpp models/objmodel.cpp objparser.cpp
main_file: $(FILES)
	g++ -std=c++11 -o main_file $(FILES)  $(LIBS)
