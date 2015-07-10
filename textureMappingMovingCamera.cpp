/*
 * Author: Fitsum Kiros
 * Date: 04-07-2015
<<<<<<< HEAD

=======
 *
>>>>>>> origin/master
 */
#include <GL/glut.h>
#include <VirtualCamera.h> //header file for virtual camera navigation
#include <texture.h> //hader file for texture mapping
#include <illuminationModel.h> //header file for lighting

/*********************Global Variables*****************************************/
//Virutal Camera Movement and Rotation Global Variables
GLfloat px = 0.0, pz = 5.0, //x and z coordinates of the virtual camera's position
        dx = 0.0, dz = pz - 1.0, //a unit vector which defines the direction of sight
        viewAngle = 180.0, // the camera is looking towards the negative z-axis
        distance = 1.0 ; // the distance a virutal camera will move back and forth in a single key press
const GLfloat py = -5.0, dy = -5.0; //camera moves and rotates in the x-z plane only
GLboolean solid = true; //a variable which determines solid or wireframe rendering based on user input 

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
/********************************* Main function: Program Entry Point***********/
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
