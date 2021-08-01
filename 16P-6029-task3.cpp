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
void make_cube()
{

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5); // vertices of the polygon
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.5, 0.5);
	//2nd side
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5); // vertices of the polygon
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.5, -0.5);
	//3rd side
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5); // vertices of the polygon
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.5, 0.5);
	//4th side
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5); // vertices of the polygon
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	//5th side
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5); // vertices of the polygon
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	//6th side
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5); // vertices of the polygon
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	glPushMatrix();
	glRotatef(theta, 2.0f, 1.0f, 1.0f);
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
	make_cube();
	glColor3f(1.0, 0.0, 0.0); // Drawing color (R, G, B), all b/w 0 and 1
	glFlush(); // force OpenGL to empty the buffer and render
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initializes GLUT Toolkit
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("TRIANGLE MESH COLORS");
	glutDisplayFunc(display); // Register call back routine for window updates
	glutSpecialFunc(specialkey); //call keyboard function
	glutMainLoop(); // Starts the toolkit loop (infinite)
}
