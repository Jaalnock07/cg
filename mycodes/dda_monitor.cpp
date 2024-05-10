#include<GL/freeglut.h>
#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

void init(){
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0,0,0,0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-500,500,-500,500);
}

void plotpixel(float x, float y){
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

void dda(float x1, float y1, float x2, float y2){
  float dx,dy,xinc,yinc,x,y;
  int steps;
  
  dx=x2-x1;
  dy=y2-y1;
  
  steps=(abs(dx)>abs(dy))?abs(dx):abs(dy);
  
  xinc=dx/(float)steps;
  yinc=dy/(float)steps;
  
  x=x1;
  y=y1;
  plotpixel(x,y);
  
  for(int i=0; i<steps; i++){
    x+=xinc;
    y+=yinc;
    plotpixel(x,y);
  }
}

void display(){
  glColor3f(1.0,1.0,0.0);
  dda(-200,-200,-200,200);
  dda(-200,200,200,200);
  dda(200,200,200,-200);
  dda(200,-200,-200,-200);
  dda(-200,-200,-100,-100);
  dda(-100,-100,-50,-150);
  dda(-50,-150,0,-200);
  dda(-50,-150,50,50);
  dda(50,50,200,-200);
  dda(-225,-225,-225,225);
  dda(-225,225,225,225);
  dda(225,225,225,-225);
  dda(225,-225,75,-225);
  dda(75,-225,150,-250);
  dda(150,-250,-150,-250);
  dda(-150,-250,-75,-225);
  dda(-75,-225,-225,-225);
}

int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(800,800);
  glutInitWindowPosition(100,100);
  glutCreateWindow("DDA");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}


