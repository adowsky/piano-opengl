LIBS=-lGL -lglfw -lGLEW  -lftgl -I/usr/include/freetype2
FILES=main.cpp model.cpp piano.cpp pianobox.cpp platform.cpp pianocover.cpp whitekeybs.cpp whitekeyrs.cpp blackkey.cpp lodepng.cpp utils.cpp
main_file: $(FILES)
	g++ -std=c++11 -o main_file $(FILES)  $(LIBS)
