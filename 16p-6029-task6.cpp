#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <GL\freeglut.h>
#include <iostream>
#include <GL\glu.h>
#include <math.h>
using namespace std;
GLfloat	theta, x, y;
void make_SPHERE()
{
	glutSolidSphere(1.0, 50, 50);
	glRotatef(theta, 2.0f, 0.5f, 0.5f);
	theta = +1;
}

void specialkey(int key, int x, int y){
    switch(key){
    case GLUT_KEY_UP: //rotate when up key pressed
        y = y +1;
        cout<<y<<endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN: //rotate when down key pressed
        y--;
        cout<<y<<endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT: //rotate when left key pressed
        x--;
        cout<<x<<endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT: //rotate when right key pressed
        x++;
        cout<<x<<endl;
        glutPostRedisplay();
        break;
    }
}

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // Background (R, G, B, alpha), all b/w 0 and 1
	glClear(GL_COLOR_BUFFER_BIT); // Clear output buffer to window color
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	make_SPHERE();
	glFlush(); // force OpenGL to empty the buffer and render
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initializes GLUT Toolkit
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Simple Sphere");
	glutDisplayFunc(display); // Register call back routine for window updates
	glutSpecialFunc(specialkey); //press key to rotate shape
	glutMainLoop(); // Starts the toolkit loop (infinite)
}
