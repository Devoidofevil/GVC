#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

typedef struct Point {
    float x;
    float y;
} Point;

int n;

void lower(float x, float y, float h, float w, int i)  //i states the number of steps above ground
{
    while (y-h>-0.9+h*i) {     //only while height above ground
        glBegin(GL_POLYGON);
        glColor3f(0.6,0.4, 0.12);		//Brown

        glVertex3f(x, y, 0);	                //Starting from the upper right point of lower block
        glVertex3f(x, y - h, 0);		//first go down(clockwise)
        glVertex3f(x - w, y - h - w,0);		//then right, and down(slant)
        glVertex3f(x - w, y - w,0);		//then go up by h

        glEnd();
        glFlush();
        y = y - h;
    }
}

Point upper(Point start, float h, float w)
{
    float x = start.x;
    float y = start.y;

    glBegin(GL_POLYGON);			
    glColor3f(1, 0, 0);				//Red

    glVertex3f(x, y, 0);			//Going antilockwise from start point
    glVertex3f(x, y + h, 0);			//First fo up by h
    glVertex3f(x - 3*h, y + 2*h, 0);	//then go to the left and slightly up, to give impression of 3d
    glVertex3f(x - 3*h, y + 1*h, 0);	//Then come down by h
    glEnd();					//that drew the vertical face...now we draw the horizontal one(the face where the feet walk on)

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);				//Blue

    glVertex3f(x, y + h, 0);			//the lower must point for this would be the top right point for vertical face
    glVertex3f(x+w, y+h+w, 0);		//again going anticlockwise	
    glVertex3f(x-3*h+w, y+2*h+w,0);
    glVertex3f(x-3*h, y+2*h,0);	
    glEnd();					//drawn this
						// 
    glFlush();					//|\ --A
    Point end;					//| \ --A
    end.x = x + w;				//\ |   
    end.y = y + h + w;				// \|
    return end;
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);     //Clear Screen

    Point start;
    start.x = -0.1;
    start.y = -0.9;

    float h = 0.21;
    float w = 0.20;


    for (int i = 0; i < n; i++) {
        start = upper(start,h,w);   //draws the upper part of staircase(where one keeps feet)
        lower(start.x, start.y,h,w,i);	//Draws the solid below the upper part,'i' tells us how many steps we are from ground
    }
}

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0);			//Clears color(sets blank frame color)
    glMatrixMode(GL_MODELVIEW);
}	

int main(int argc, char *argv[])
{
    n = atoi(argv[1]);			//Gives number of steps
    glutInit(&argc, argv);				//Initializes glut window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//Intializes color mode
    glutInitWindowSize(500, 650);			//Sets window size
    glutCreateWindow("RedBrown Staircase");			
    init2D(0.75, 0.75, 0.75);				//Background of frame = grey

    glutDisplayFunc(display);				//displays
    glutMainLoop();					//loops
}

