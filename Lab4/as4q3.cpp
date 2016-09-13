#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

typedef struct Leg {
    public:
        float startx;
        float starty;       
        Leg(float sx, float sy) {
            startx = sx;
            starty = sy;
        }
} Leg;

typedef struct Surface{
    float startx;
    float starty;
    Surface(float sx, float sy) {
        startx = sx;
        starty = sy;
    }
} Surface;

void drawLeg(float x,float y) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x, y - 60);
    glVertex2f(x + 10, y - 60);
    glVertex2f(x + 10, y);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(x, y);
    glVertex2f(x - 2, y + 5);
    glVertex2f(x - 2, y + 5 - 60);
    glVertex2f(x, y - 60);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(x - 2, y + 5);
    glVertex2f(x + 10 - 2, y + 5);
    glVertex2f(x + 10, y);
    glEnd();

    glFlush();
}

void drawSurface(float x,float y) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x - 36.5, y + 25);
    glVertex2f(x + 75, y + 45);
    glVertex2f(x + 115, y + 17);
    glEnd();
    glFlush();
}

void opaqueSurface(float x,float y) {
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x - 36.5, y + 25);
    glVertex2f(x + 75, y + 45);
    glVertex2f(x + 115, y + 17);
    glEnd();
    glFlush();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    Surface *p1 = new Surface(48, 100);
    Surface *p2 = new Surface(48, 98);

    Leg *l1 = new Leg(50, 100);
    Leg *l2 = new Leg(15, 120);
    Leg *l3 = new Leg(115, 135);
    Leg *l4 = new Leg(150, 115);

    drawLeg(l1->startx,l1->starty);
    drawLeg(l2->startx,l2->starty);
    drawLeg(l3->startx,l3->starty);
    drawLeg(l4->startx,l4->starty);    

    glColor3f(0.75, 0.75, 0.75);
    opaqueSurface(p2->startx,p2->starty);
    glColor3f(0, 0, 0);
    drawSurface(p2->startx,p2->starty);
    glColor3f(0.75, 0.75, 0.75);
    opaqueSurface(p1->startx,p1->starty);
    glColor3f(0, 0, 0);
    drawSurface(p1->startx,p1->starty);
}

void init(float r, float g, float b)
{
    glClearColor(r, g, b, 1);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0, 200, 0, 200);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cool Table");
    init(0.75, 0.75, 0.75);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}