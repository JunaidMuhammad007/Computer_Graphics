#include <windows.h>
#include <GL/glut.h>
#include<math.h>

float move_x = 0.5f;
float move_y = 0.5f;
float move_z = 0.5f;

void makecube()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_QUADS);
	glVertex3f(move_x, move_y, -move_z);
	glVertex3f(-move_x, move_y, -move_z);
	glVertex3f(-move_x, move_y, move_z);
	glVertex3f(move_x, move_y, move_z);

	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, -move_z);
	glVertex3f(move_x, -move_y, -move_z);

	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(-move_x, move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);

	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f(move_x, -move_y, -move_z);
	glVertex3f(-move_x, -move_y, -move_z);
	glVertex3f(-move_x, move_y, -move_z);
	glVertex3f(move_x, move_y, -move_z);

	glColor3f(0.0f, 0.0f, 1.0f);     // Blue
	glVertex3f(-move_x, move_y, move_z);
	glVertex3f(-move_x, move_y, -move_z);
	glVertex3f(-move_x, -move_y, -move_z);
	glVertex3f(-move_x, -move_y, move_z);

	glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3f(move_x, move_y, -move_z);
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(move_x, -move_y, -move_z);

	glEnd();

	glFlush();

}
GLfloat xcor = 0.0;
GLfloat ycor = 0.0;

GLfloat mousemoleft = 0.0;
GLfloat mousemoright = -4.5;

void display() {


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5, 5, -5, 5);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xcor, ycor, 1, mousemoleft, mousemoright, 0, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 3.5, 0);
	glColor3f(1, 1, 1);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2.5, 0);
	glColor3f(0, 1, 1);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(1, 0, 1);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glColor3f(1, 1, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glColor3f(1, 0, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.5, 0);
	glColor3f(0, 1, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.5, 0);
	glColor3f(0, 0, 1);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -3.5, 0);
	glColor3f(1.5, 0, 1.5);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -4.5, 0);
	glColor3f(1.89, 1.89, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -5.5, 0);
	glColor3f(1.89, 1.89, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();



	//glFlush();
	glutSwapBuffers();
}

void timer(int x)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPopMatrix();
	glRotatef(10, 1.0, 1.0, 0.0);

	glutPostRedisplay();
	glutTimerFunc(1000 / 25., timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd' : case 'D' :
		xcor = xcor + 0.5;
		break;
	case 'a' : case 'A' :
		xcor = xcor - 0.5;
		break;
	case 'w' : case 'W' :
		ycor = ycor + 0.5;
		break;
	case 's' : case 'S' :
		ycor = ycor - 0.5;
		break;
	}
	glutPostRedisplay();
}

void myMouseMove(int x, int y)
{
	mousemoright = sin(x + 00.1);
	mousemoleft = -cos(y+00.1);


	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Setup Test");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutPassiveMotionFunc(myMouseMove);
	glutTimerFunc(1000 / 25., timer, 0);
	glutReshapeWindow(500, 500);
	glutMainLoop();

}
