#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Drawing the square
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(50, 50);			
    glVertex2i(150, 50);
    glVertex2i(150, 50);
    glVertex2i(150, 140);
    glVertex2i(50, 140);
    glVertex2i(50, 50);
    //Drawing the triangle
    glColor3f(0, 0, 1);
    glVertex2i(150, 140);
    glVertex2i(100, 190);
    glVertex2i(100, 190);
    glVertex2i(50, 140); 
    glVertex2i(50, 140);
    glVertex2i(150, 140);

    glEnd();
    glFlush();
}

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200, 0, 200);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Question 1");
    init2D(0.75, 0.75, 0.75);
    glutDisplayFunc(display);
    glutMainLoop();
}


