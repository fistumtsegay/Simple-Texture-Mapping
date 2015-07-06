/*
 * Author: Fitsum Kiros
 * Date: 04-07-2015
 *
 */
#include <GL/glut.h>
#include <SOIL.h>

/*Classes that draw texture mapped objects*/
class Texture{
 protected:
        GLint width, height;
        GLubyte * imageData;
        const char * imagePath; 
        GLuint texId;
 public:
       Texture(GLint, GLint,const  char *);
       void configure();
       virtual void draw() = 0;
       ~Texture();
};
class Door: public Texture{
 private:
         GLboolean opened;
 public:
        Door(GLint , GLint,const  char *);
        void draw();
        GLboolean isOpen();
        void open();
        void close();
        ~Door();
};
class Ground: public Texture{
 public:
        Ground(GLint, GLint,const  char *);
        void draw();
        ~Ground();
};
class Wall: public Texture{
 public:
        Wall(GLint, GLint,const  char *);
        void draw();
        ~Wall();
};
