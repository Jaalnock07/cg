#include<GL/freeglut.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>

using namespace std;

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500,500,-500,500);
}

void plotpixel(int xc, int yc, int x, int y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(xc+x, yc+y);
    glVertex2i(xc-x, yc+y);
    glVertex2i(xc+x, yc-y);
    glVertex2i(xc-x, yc-y);
    glVertex2i(xc+y, yc+x);
    glVertex2i(xc+y, yc-x);
    glVertex2i(xc-y, yc+x);
    glVertex2i(xc-y, yc-x);
    glEnd();
    glFlush();
}

void bca(int xc, int yc, int r)
{
    int x=0, y=r;
    
    int d = 3 - 2*r;
    plotpixel(xc, yc, x, y);
    while(x <= y)
    {
        x++;
        if(d <= 0)
        {
            d = d + 4*x + 6;
            y = y;
        }
        else
        {
            d = d + 4*(x-y) + 10;
            y = y - 1;
        }
        plotpixel(xc, yc, x, y);
    }
}

void display()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(-500,0);
    glVertex2i( 500,0);
    glVertex2i( 0,-500);
    glVertex2i( 0, 500);
    glEnd();
    glFlush();

    bca(0,0,150);
    bca(0,0,50);

    int angle = 0;
    int x = 75, y = 0;
    bca(x, y, 75);
    int R = 75;

    for (int i = 0; i < 8; i++)
    {
        angle = angle + 45;
        x = R * cos(angle*(3.14/180));
        y = -R * sin(angle*(3.14/180));
        bca(x, y, 75);
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("bangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
