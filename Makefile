LIBS=-lGL -lglfw -lGLEW  -lftgl -lalut -lopenal -I/usr/include/freetype2
FILES=main.cpp piano.cpp lodepng.cpp utils.cpp models/shaderprogram.cpp models/objmodel.cpp objparser.cpp camera.cpp

main_file: $(FILES)
	g++ -std=c++11 -o main_file $(FILES)  $(LIBS)
clean:
	rm ./*.gch
	rm model/*.gch
	rm ./main_file
