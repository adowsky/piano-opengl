LIBS= -lGL -lglfw -lGLEW  -lftgl -lalut -lopenal -lSOIL -lmidifile
SFLAGS= -lGL -lX11 -lGLEW -L./libs -lglfw -lalut -lopenal -lSOIL  -lGL -lpthread -ldl
FILES=main.cpp piano.cpp lodepng.cpp utils.cpp models/shaderprogram.cpp models/objmodel.cpp objparser.cpp camera.cpp scene.cpp player.cpp

main_file: $(FILES)
	g++ -std=c++11 -o main_file $(FILES)  $(LIBS)

static: $(FILES)
	g++ -std=c++11 -o main_file   $(FILES) $(SFLAGS)
clean:
	rm ./*.gch
	rm model/*.gch
	rm ./main_file
