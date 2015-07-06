/*
 * Author: Fitsum Kiros
 * Date: 04-07-2015
 *
 */

/*Illumination Model Parameters*/
const GLfloat position[] = {0.0,2.0,-5.0,0.0};
const GLfloat ambient[] = {1.0,1.0,1.0,1.0};
const GLfloat specular[] = {1.0,1.0,1.0,1.0};
const GLfloat diffuse[] = {1.0,1.0,1.0,1.0};

void illuminationModel(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.001);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.001);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.001);
}
