#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include <stdlib.h>

using namespace std;

#define pi 3.14159256

typedef struct Point{
	float x,y;
	Point(float x,float y) {
		this->x=x;
		this->y=y;
	}
} Point;

typedef struct Circle{
	float radius;
	Point *center;
	Circle(Point *center,float radius) {
		this->center = center;
		this->radius = radius;
	}
} Circle;

Circle *c;

void drawCircle(float radius, int mode) {
	glColor3f(0.0,0.0,0.0);
	int count=0;
	for(float theta =0.0 ; theta <= 2*pi ; theta+=0.01) {
		if( mode % 2 == 1 ) {
			count++;
			glBegin(GL_POINTS);
			if(count<10) continue;
			else
			if(count<20) {}
			else count=0;
		}
		else
			glBegin(GL_LINE_LOOP);
		glVertex2f(c->center->x + radius*cos(theta),c->center->y + radius*sin(theta));
	}
	glEnd();
	glFlush();
}

void drawBeauty() {
	for(int i=1;i<=6;i++) 
		drawCircle(c->radius*i,i);
	
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawBeauty();
}

void init2d(float r,float g,float b) {
	glClearColor(r,g,b,0);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(-200,200,-200,200);
}

int main(int argc,char *argv[]) { 
	cout << "Enter radius of circle and its center's coordinates:\n";
	float radius,centerx,centery;
	cin >> radius >> centerx >> centery;
	Point *center = new Point(centerx,centery);
	c = new Circle(center,radius);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutCreateWindow("Concentric Circles");
	init2d(0.75,0.75,0.75);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

