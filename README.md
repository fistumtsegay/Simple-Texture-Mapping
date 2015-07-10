The program is developed using Dev-Cpp on Windows 7. You need to install dev-cpp and add glut package to run the program. In addition to that you need to add SOIL library. Refer your wiki page to configure your Dev-cpp.
#####textureMappingMovingCamera.dev
The file is a Dev-cpp project file. You have to double click this file to open all the project files.
#####textureMappingMovingCamera.cpp
This file contains the main function which is entry point of the program. GLUT initialization functions, and key board input processing are found in this file.
#####texture.h
This file is a header file, which includes declarations of 4 claases. Texture is an abstract class which creates a texture, loads the texture image, and spcifies how the texture mapping is to be carried out. The other classes (Door, Wall, and Ground) inherit from class texture and have a non-virtual draw function.
#####texture.cpp
This class implements texture header file.
#####VirtualCamera.h
This file contains a header file with declaration of VirtualCamera class. The class declaration includes how to set up the virtual camera, how to move the camera and how to turn the camera.
#####VirtaulCamera.cpp
This file conatins the class which implements the class declaration in the header file VirtualCamera.h.
#####illuminationModel.h
This file contains the funcition that define the lighting properties.
####images
contains images that are mapped to quadrilaterals in the the scene.
