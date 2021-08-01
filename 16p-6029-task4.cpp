#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;
GLfloat	theta, x, y;
void make_pyramid()
{

	glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
	 // Front
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	// Right
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	// Back
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	// Left
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();   // Done drawing the pyramid
	glPushMatrix();
	glRotatef(theta, 2.0f, 0.5f, 0.5f);
	theta = +1;
	glColor3f(1.0f, 0.0f, 0.0f);
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
	make_pyramid();
	glColor3f(0.5, 0.0, 0.0); // Drawing color (R, G, B), all b/w 0 and 1
	glFlush(); // force OpenGL to empty the buffer and render
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initializes GLUT Toolkit
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("PYRAMID");
	glutDisplayFunc(display); // Register call back routine for window updates
	glutSpecialFunc(specialkey); //call keyboard function
	glutMainLoop(); // Starts the toolkit loop (infinite)
}
