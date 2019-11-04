#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;

void redisplayFunc(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glColor3f(1.0, 1.0, 1.0);
    glRotatef(xRotated,1.0,0.0,0.0);
	glRotatef(yRotated,0.0,1.0,0.0);
   	glRotatef(zRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);
    glutWireCube(1.0);
    glFlush();
    glutSwapBuffers();
}

void reshapeFunc(int x, int y){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
}

void idleFunc(void){
    xRotated += .5;
    yRotated += .5;
    zRotated += .500;
    redisplayFunc();
}


int main (int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(350,350);
    glutCreateWindow("3D CUBE ROTATION");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    xRotated = yRotated = zRotated = 0.0;

    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(redisplayFunc);
    glutReshapeFunc(reshapeFunc);
    glutIdleFunc(idleFunc);
    glutMainLoop();
    return 0;
}
