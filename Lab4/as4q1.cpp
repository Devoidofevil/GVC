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

void drawCircle(Point *center) {
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(float theta =0.0 ; theta < 2*pi ; theta+=0.001) {
		glVertex2f(center->x + c->radius*cos(theta),center->y + c->radius*sin(theta));
	}
	glEnd();
	glFlush();
}

void drawBeauty() {
	float xwise = sqrt(pow(c->radius,2)-pow(c->radius/2.0,2));
	float ywise = c->radius/2;
	float xmoves[7] = {0,xwise,xwise,0,-xwise,-xwise,0};
	float ymoves[7] = {0,ywise,-ywise,-2*ywise,-ywise,ywise,2*ywise};
	Point *newcenter;
	for(int i=0;i<7;i++) {
		newcenter = new Point(c->center->x + xmoves[i],c->center->y + ymoves[i]);
		drawCircle(newcenter);
	}
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
	glutCreateWindow("Nature's Beauty");
	init2d(0.75,0.75,0.75);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

