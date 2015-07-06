/*
 * Author: Fitsum Kiros
 * Date: 04-07-2015
 *
*/
#include <VirtualCamera.h>
#include <math.h>

GLfloat convertDegToRad(GLfloat);
VirtualCamera::VirtualCamera(GLfloat px, GLfloat py, GLfloat pz, GLfloat dx, GLfloat dy, GLfloat dz, GLfloat viewAngle, GLfloat distance ){
        this->px = px; this->py = py; this->pz = pz;
        this->dx = dx; this->dy = dy; this->dz = dz;
        this->viewAngle = viewAngle;
        this->distance = distance;
}
void VirtualCamera::view(){
     gluLookAt(px, py, pz, dx, dy, dz, 0, 1, 0);
}
void VirtualCamera::moveFaster(){
     distance = distance + 1;
}
void VirtualCamera::moveSlower(){
     if(distance - 1 > 0)
         distance = distance - 1;
}
//move forward along the direction of sight
void VirtualCamera::moveForward(){
     px = px + distance * sin(convertDegToRad(viewAngle)); 
     pz = pz + distance * cos(convertDegToRad(viewAngle));
     //adjust sight direction vector
     dx = px + sin(convertDegToRad(viewAngle));
     dz = pz + cos(convertDegToRad(viewAngle));
}
//move backward
void VirtualCamera::moveBackward(){
     px = px - distance * sin(convertDegToRad(viewAngle));
     pz = pz - distance * cos(convertDegToRad(viewAngle));
     
}
//rotate counter clock wise (left)
void VirtualCamera::turnLeft(){
     viewAngle = viewAngle + 10; // increment the angle to turn counter clockwise
     viewAngle = (viewAngle >= 360 ? 0 : viewAngle); // adjust angle to zero if it exceeds 360
     dx = px + sin(convertDegToRad(viewAngle)); // adjust x component of sight direction vector
     dz = pz + cos(convertDegToRad(viewAngle)); // adjust y component of sight directionv ector
}
//rotate clockwise (right)
void VirtualCamera::turnRight(){
     viewAngle = viewAngle - 10; // decrement the angle to turn clockwise
     viewAngle = (viewAngle <= -360 ? 0 : viewAngle); //adjust the angle to zero if it exceeds -360
     dx = px + sin(convertDegToRad(viewAngle)); // adjust x component of sight direction vector
     dz = pz + cos(convertDegToRad(viewAngle)); // adjust y component of sight direction vector
}
GLfloat convertDegToRad(GLfloat degree){
        return degree * (22.0/7) * (1.0/180);
}
