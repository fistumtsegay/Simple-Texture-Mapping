/*
 * Author: Fitsum Kiros
 * Date: 04-07-2015
 *
 */
#include <GL/glut.h>

class VirtualCamera{
  private:
    GLfloat px, py, pz, //position of camera
            dx, dy, dz, //vector of direction of sight
            viewAngle, //for rotation
            distance;  //for moving back and forth
  public: 
       // Constructor
       VirtualCamera(GLfloat px, GLfloat py, GLfloat pz, //coordinates of vitual camer's position
                     GLfloat dx, GLfloat dy, GLfloat dz, //coordintaes of virtual camera's sight direction vector
                     GLfloat viewAngle, //rotation degree of sight direction vector from positive z-axis
                     GLfloat distance //pace of camera in a single movement
                     );
       //perform viewing transformation
       void view();
       //move forward
       void moveForward();
       //move backward
       void moveBackward();
       //rotate counter clock wise (left)
       void turnLeft();
       //rotate clockwise (right)
       void turnRight();
       //speed up virtual camera's speed
       void moveFaster();
       //slow down virtual camera's speed
       void moveSlower();
       //getters
       GLfloat getDx(){
               return dx;
       }
       GLfloat getDy(){
               return dy;        
       }
       GLfloat getDz(){
               return dz;        
       }
};

