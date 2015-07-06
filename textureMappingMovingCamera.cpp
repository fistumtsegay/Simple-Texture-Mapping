/*
 * Author: Fitsum Kiros
 * Date: 04-07-2015
 * 
 *                                  Message to Students
 * ==========================================================================================
 * The program is written primarily to introduce you to texture mapping and navigation of a 3D scene using the virtual camera.
 * Before you attempt to read or use any of the code for your project, you MUST study and understand the theory of transformations,
 * viewing pipeline, illumination model and texture mapping. (Concerning texture mapping focus on 2D texture Mapping).
 * The library I used for texture mapping is called SOIL(Simple OpenGL Image Library). You can read how to use functions of the library
 * from the HTML file (soil.html) located in the soil folder. You can either download the library from http://www.lonesock.net/soil.html 
 * or you can use the copy I have uploaded to github. I have included a text file (SOIL for Dev-CPP) to show you how you should configure 
 * Dev-Cpp to use SOIL.
 *
 * The program enables navigation of a 3D scene by pressing arrow keys. The implementation for of the virutal camera is separated 
 * in a header (.h) file and implementation (.cpp) files. Go through both files to see how things work. 
 * To move or rotate the camera use the following
 *     - Left and right arrow keys turn the virtual camera to the left and right respectively
 *     - Down and Up arrow keys move the camera back and forth respecively
 * Key presses 'C' and 'O' close and open the door respectively. Composition Transformation is used to achieve that.
 * Another feature of the program is texture mapping. The grass, ceramic wall and the door are all
 * quadrilaterals with texture (2D) images mapped on them.
 */
#include <GL/glut.h>
#include <VirtualCamera.h> //header file for virtual camera navigation
#include <texture.h> //hader file for texture mapping
#include <illuminationModel.h> //header file for lighting

/*********************Global Variables*****************************************/
//Virutal Camera Movement and Rotation Global Variables
GLfloat px = 0.0, pz = 5.0,
        dx = 0.0, dz = pz - 1.0,
        viewAngle = 180.0,
        distance = 1.0 ;
const GLfloat py = -5.0, dy = -5.0; //camera moves and rotates in the x-z plane only
GLboolean solid = true;

/***********************************GLobal objects************************************/
Door door(256,256, "images\\door.png");
Ground ground(1024,1024, "images\\grass.png");
Wall wall(2048,2048, "images\\ceramicwall.jpg");
VirtualCamera virtualCamera(px, py, pz, dx, dy, dz, viewAngle, distance); //instance of Virtual Camera class


/*********************************function declarations*************************/
void init();
void navigate(int key, int x, int y); //a call backnavigation code is executed based on key press of user
void keypress(unsigned char key, int x, int y); //user input to close or open the door and display the scene as wireframe or solid is processed by this function
void reshape(int w, int h); //viewport and projection transformations
void display();

int main(int argc,char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGBA);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Simple Texture Mapping, Virtual Camera Navigation, ....");
    illuminationModel();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    glutSpecialFunc(navigate);
    init();
    glutMainLoop();
    return 0;
}

void init(){
     glClearColor(0.2,0.2,0.5,1.0);
     door.configure();
     ground.configure();
     wall.configure();
}
void display(){
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     virtualCamera.view();
     if(solid)
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
     else
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);;
     door.draw();
     ground.draw();
     wall.draw();
     glutSwapBuffers();
}
void navigate(int key, int x, int y){
     switch(key){
                 case GLUT_KEY_UP:
                      virtualCamera.moveForward();
                      break;
                 case GLUT_KEY_DOWN:
                      virtualCamera.moveBackward();
                      break;
                 case GLUT_KEY_LEFT:
                      virtualCamera.turnLeft();
                      break;
                 case GLUT_KEY_RIGHT:
                      virtualCamera.turnRight();
                      break;
     } 
     glutPostRedisplay();       
}
void keypress(unsigned char key, int x, int y){
     switch(key){
                 case '+':
                      virtualCamera.moveFaster();
                      break;
                 case '-':
                      virtualCamera.moveSlower();
                      break;
                 case 'o':
                 case 'O':
                      door.open();
                      break;
                 case 'c':
                 case 'C':
                      door.close();
                      break; 
                 case 'w':
                 case 'W':
                      solid = false;
                      break;
                 case 's':
                 case 'S':
                      solid = true;
                      break;  
     }     
     glutPostRedisplay();
}


void reshape(int w, int h){
     glViewport(0, 0, (int)w, (int) h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(120, (GLdouble)w/h, 1, 1000);
}
