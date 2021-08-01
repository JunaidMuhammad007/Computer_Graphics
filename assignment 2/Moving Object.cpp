//Junaid Muhammad p166029 CG Assignment 2 Movement of object.

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <GL\freeglut.h>
#include <iostream>

float x1 = 2.5;
float y1 = 2.0;
float z1 = 1.0;

float x2 = 2.5;
float y2 = 2.0;
float z2 = 1.0;

static int coordinate = 1;

void display() {


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5, 5, -5, 5);

	glPointSize(35);
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex3f(x1, y1, 1);
	glEnd();

	glPointSize(35);
	glBegin(GL_POINTS);
	glColor3f(0, 1, 0);
	glVertex3f(x2, y2, 1);
	glEnd();

	//glutSwapBuffers();

	glFlush();


}
void timer(int x)
{

	if (coordinate)
	{
		float v1 = float(rand() % 6);
		float v2 = float(rand() % 6);
		float v11 = float(rand() % 6);
		float v22 = float(rand() % 6);
		x1 = v1;
		y1 = v2;
		x2 = v11;
		y2 = v22;
		glTranslatef(x1, y1, 1);
		glTranslatef(x2, y2, 1);
		if (x2 > 4.9)
		{
			coordinate = 0;
		}


	}


	if (!coordinate)
	{
		x1 = 2.5;
		x2 = 2.0;
	}

	glTranslatef(x1, y1, 0);
	glTranslatef(x2, y2, 0);
	glutPostRedisplay();
	glutTimerFunc(1000 / 2., timer, 0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Object Movement");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutReshapeWindow(500, 500);
	glutTimerFunc(1000 / 25., timer, 0);
	glutMainLoop();

}
