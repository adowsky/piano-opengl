LIBS=-lGL -lglfw -lGLEW  -lftgl -I/usr/include/freetype2
FILES=main.cpp models/model.cpp piano.cpp models/pianobox.cpp models/platform.cpp models/pianocover.cpp models/whitekeybs.cpp models/whitekeyrs.cpp models/blackkey.cpp lodepng.cpp utils.cpp models/shaderprogram.cpp
main_file: $(FILES)
	g++ -std=c++11 -o main_file $(FILES)  $(LIBS)
