#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

GLfloat tri6[18][2] = {{0,0},{0,100},{86.6,50},{0,0},{86.6,50},{86.6,-50},{0,0},{86.6,-50},{0,-100},{0,0},{0,-100},{-86.6,-50},{0,0},{-86.6,-50},{-86.6,50},{0,0},{-86.6,50},{0,100}};

void draw6Triangles() {
	int i;
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
	for(i=0;i<18;i++) {
		glVertex2fv(tri6[i]);
	}
	glEnd();
	glFlush();
	glBegin(GL_LINES);
	glVertex2fv(tri6[16]);
	glVertex2fv(tri6[2]);
	glVertex2fv(tri6[13]);
	glVertex2fv(tri6[5]);
	glVertex2fv(tri6[13]);
	glVertex2fv(tri6[1]);
	glVertex2fv(tri6[5]);
	glVertex2fv(tri6[1]);
	glVertex2fv(tri6[16]);
	glVertex2fv(tri6[8]);
	glVertex2fv(tri6[2]);
	glVertex2fv(tri6[8]);
	glEnd();
	glFlush();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1, 1, 0);
	draw6Triangles();
}

void init3D(float r, float g, float b)
{
	glClearColor(r, g, b, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100, 100, -120, 120);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 200);
	glutCreateWindow("DoubleStar");
	init3D(1, 1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
}
