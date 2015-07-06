# 9_textureMappingMovingCamera
Message to Students
========================
 The program is written primarily to introduce you to texture mapping and navigation of a 3D scene using the virtual camera. Before you attempt to read or use any of the code for your project, you MUST study and understand the theory of transformations, viewing pipeline, illumination model and texture mapping. You have to know this program is very trival and far from complete and the coding style do not follow conventional software engineering practices such as consistent commenting and so on. You are expceted to submit a much developed program according to the specifications in your guideline.
Texture Mapping
~~~~~~~~~~~~~~~
The library I used for texture mapping is called SOIL(Simple OpenGL Image Library). You can read how to use functions of the library from the HTML file (soil.html) located in the soil folder, which you can download from the website and go through the files in "Simple OpenGL Image Library\src". You can download the library from http://www.lonesock.net/soil.html. Once you have downloaded a zip from the website you have to configure Dev-Cpp using the following instructions (on Windows)
	1. Extract the zip folder to a folder of your choice
	2. Copy the contents of the folder "Simple OpenGL Image Library\src" found in the extracted folder to the folder "[Dev-Cpp installation directory]\Dev-Cpp\include"
	3. Copy the file "Simple OpenGL Image Library\lib\libSOIL.a" to "[Dev-Cpp installation directory]\Dev-Cpp\lib".
	4. Open Project->Project Options-> Parameters
	5. On the linker text area add "-lSOIL" at the start (without the double quotes)
The code for texture mapping is separated in the header file (texture.h) and C++ implementation file (texture.cpp). The code for creating a texture, loading an image from the folder ".\images\" and specifying the nature of texture mapping is done by the abstract class Texture. The rest three classes classes (Door, Ground and Wall) inherit from class Texture and implement how a primitive is drawn by specifying 2D texture coordintaes and 3D geometric coordinates. 
Virtual Camera Navigation
~~~~~~~~~~~~~~~~~~~~~~~~~
The program enables navigation of a 3D scene by pressing arrow keys. The code for of the virutal camera is separated in a header (VirtualCamera.h)  and C++ implementation (VirtualCamera.cpp) files. All you need to understand the code is basic trigonomety from your high school Math lessons.
Other Features
~~~~~~~~~~~~~~~
Other features of the prgram are keyboard input (forinstance to see the wireframe rendering of the scence, open and close a door in the scene, etc.)
I hope this will give you a hint of how you shall start developing your programs.
Best of Luck with your Projects,
Your instructor
