#include <texture.h>
#include <stdio.h>
#include <string>
/*
 * Author: Fitsum Kiros
 * Date: 04-07-2015
 *
 */
/*Member function definition of Texture*/
Texture::Texture(GLint width, GLint height,const  char * imagePath){
     this->width = width;
     this->height = height;
     this->imagePath = imagePath;
}
void Texture::configure(){
     //create texture
     texId = SOIL_load_OGL_texture(
             this->imagePath,
             SOIL_LOAD_AUTO,
             SOIL_CREATE_NEW_ID,
             SOIL_FLAG_TEXTURE_REPEATS
     );
     glGenTextures(1, &texId);
     glBindTexture(GL_TEXTURE_2D, texId);
     imageData = SOIL_load_image(
            imagePath,
            &width,
            &height,
            0,
            SOIL_LOAD_RGBA
     );
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);   
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
}
Texture::~Texture(){
     SOIL_free_image_data(imageData);
     glBindTexture(GL_TEXTURE_2D,0);
     glDisable(GL_TEXTURE_2D);
}
/*Member function definition of Door*/
Door::Door(GLint width, GLint height,const  char * imagePath) 
                  : Texture::Texture(width, height, imagePath){
     opened = false; 
}
void Door::draw(){
     
     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
     glBindTexture(GL_TEXTURE_2D, texId);
     glEnable(GL_TEXTURE_2D);
     
     glPushMatrix();
     if(opened == false)
             glTranslatef(16,-5,-10);
     else{
             glTranslatef(16,-5,-10);
             glRotatef(-90, 0, 1, 0);       
     }
     glBegin(GL_QUADS);
           glTexCoord2f(0,0);glVertex3f(-6, -5, 0);
           glTexCoord2f(1,0);glVertex3f(0, -5, 0);
           glTexCoord2f(1,1);glVertex3f(0, 5, 0);
           glTexCoord2f(0,1);glVertex3f(-6, 5, 0);
     glEnd(); 
     glPopMatrix();
     glDisable(GL_TEXTURE_2D);
}
GLboolean Door::isOpen(){
    return opened;      
}
void Door::open(){
     opened = true;
}
void Door::close(){
     opened = false;
}
Door::~Door(){
}
/*Member fucntion definition of Ground*/
Ground::Ground(GLint width, GLint height,const  char * imagePath)
                      : Texture::Texture(width, height, imagePath){
}
void Ground::draw(){
     glEnable(GL_TEXTURE_2D);
     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
     glBindTexture(GL_TEXTURE_2D, texId);
     glColor4f(0.5,1.0,0.5, 1.0);
     glBegin(GL_QUADS);
           glTexCoord2f(0,0);glVertex3f(-100, -10, 100);
           glTexCoord2f(80,0);glVertex3f(100, -10, 100);
           glTexCoord2f(80,80);glVertex3f(100, -10, -100);
           glTexCoord2f(0,80);glVertex3f(-100, -10, -100);
     glEnd(); 
     glDisable(GL_TEXTURE_2D);  
}
Ground::~Ground(){
}
/*Memeber function definition of Wall*/
Wall::Wall(GLint width, GLint height,const  char * imagePath)
                  : Texture::Texture(width, height, imagePath){
                  
}
void Wall::draw(){
     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
     glBindTexture(GL_TEXTURE_2D, texId);
     glEnable(GL_TEXTURE_2D);
     glBegin(GL_QUADS);
           glTexCoord2f(0,0);glVertex3f(-10, -10, -10);
           glTexCoord2f(.5,0);glVertex3f(10, -10, -10);
           glTexCoord2f(.5,.5);glVertex3f(10, 10, -10);
           glTexCoord2f(0,.5);glVertex3f(-10, 10, -10);
           
           glTexCoord2f(0,0.0);glVertex3f(10, 0, -10);
           glTexCoord2f(0.15,0.0);glVertex3f(16, 0, -10);
           glTexCoord2f(0.15,0.25);glVertex3f(16, 10, -10);
           glTexCoord2f(0,0.25);glVertex3f(10, 10, -10);
           
           glTexCoord2f(0,0);glVertex3f(16, -10, -10);
           glTexCoord2f(0.075,0);glVertex3f(19, -10, -10);
           glTexCoord2f(0.075,0.5);glVertex3f(19, 10, -10);
           glTexCoord2f(0,0.5);glVertex3f(16, 10, -10);
     glEnd(); 
     glBindTexture(GL_TEXTURE_2D, 0);
}
Wall::~Wall(){

}
