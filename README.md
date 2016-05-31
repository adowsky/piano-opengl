# piano-opengl
Academic project. Piano in OpenGL

#Dependencies
*glfw3
*glew
*OpenAL
*SOIL


##Linux instalation
Use commands below to install dependencies under Linux(tested on Ubuntu 16.04).
```
sudo apt-get install cmake xorg-dev libglu1-mesa-dev
sudo apt-get install libglfw3-dev libglew-dev libsoil-dev libalut0 libalut-dev libopenal1 libopenal-dev
```

# 3rd party files
Project need some 3rd party files which are not included in repository.

## Sound files
For sound of piano you will need to provide piano samples to the directory samples/
You can find the some here: http://keppystudios.com/kspproject.html
For samples from Keppy Studios you just need to copy files called KREPSRECxxx (xxx are numbers) into samples directory.

##SkyBox images
You will also need to provide images for skybox and name them properly. Right now project is set on tga file format so if you want other one you will need to change source(scene.cpp).
The files have following names:
```
posx.tga
negx.tga
posy.tga
negy.tga
posz.tga
negz.tga
```

#Compilation
If you have all dependencies, you need only one command to compile whole project:
```
make
```
It will create for you file called main_file which is executable file of the project.

