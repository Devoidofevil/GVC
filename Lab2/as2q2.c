#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//For square
	glColor3f(1, 0, 1);
	glBegin(GL_QUADS);

	glVertex2i(100, 100);
	glVertex2i(85, 115);
	glVertex2i(100, 175);
	glVertex2i(115, 115);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2i(100, 100);
	glVertex2i(115, 115);
	glVertex2i(175, 100);
	glVertex2i(115, 85);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2i(100, 100);
	glVertex2i(115, 85);
	glVertex2i(100, 25);
	glVertex2i(85, 85);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2i(100, 100);
	glVertex2i(85, 85);
	glVertex2i(25, 100);
	glVertex2i(85, 115);

	glEnd();
	glFlush();
	glTranslatef(100,100,0);
	glRotatef(45,0.0,0.0,1.0);
	glTranslatef(-100,-100,0);

	glBegin(GL_QUADS);

	glVertex2i(100, 100);
	glVertex2i(85, 115);
	glVertex2i(100, 175);
	glVertex2i(115, 115);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2i(100, 100);
	glVertex2i(115, 115);
	glVertex2i(175, 100);
	glVertex2i(115, 85);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2i(100, 100);
	glVertex2i(115, 85);
	glVertex2i(100, 25);
	glVertex2i(85, 85);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex2i(100, 100);
	glVertex2i(85, 85);
	glVertex2i(25, 100);
	glVertex2i(85, 115);

	glEnd();
	glFlush();
}

void init2D(float r, float g, float b)
{
	glClearColor(r, g, b, 0);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0, 200, 0, 200);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Question 1");
	init2D(0.175, 0.175, 0.175);
	glutDisplayFunc(display);
	glutMainLoop();
}

