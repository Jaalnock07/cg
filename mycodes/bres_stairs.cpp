#include<GL/freeglut.h>
#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

void plotpixel(float x, float y){
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

void init(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glClearColor(0,0,0,0);
  gluOrtho2D(-500,500,-500,500);
}

void dda(float x1,float y1,float x2,float y2){
  float dx,dy,x,y;
  float P;
  
  dx=x2-x1;
  dy=y2-y1;
  
  x=x1;
  y=y1;
  
  for(int i=0;i<max(dx,dy);i++){
    if(dx>dy){
      P=2*dx-dy;
      x++;
      if(P<0){
        P=P+2*dx;
      }else{
        P=P+2*(dx-dy);
        y++;
      }
    }
  }
  
  if(dx>dy){
    P=2*dy-dx;
    for(int i=0;i<dx;i++,x++){
      if(P<0){
        P=P+2*dy;
      }else{
        y++;
        P=P+2*(dy-dx);
      }
      plotpixel(x,y);
    }
  }else{
    P=2*dx-dy;
    for(int i=0;i<dy;i++,y++){
      if(P<0){
        P=P+2*dx;
      }else{
        x++;
        P=P+2*(dx-dy);
      }
      plotpixel(x,y);
    }
  }
}

void render(){
  dda(200,200,200,-200);
  dda(200,-200,-200,-200);
  dda(-200,-200,-200,-160);
  dda(-200,-160,-160,-160);
  dda(-160,-160,-160,-120);
  dda(-160,-120,-120,-120);
  dda(-120,-120,-120,-80);
  dda(-120,-80,-80,-80);
  dda(-80,-80,-80,-40);
  dda(-80,-40,-40,-40);
  dda(-40,-40,-40,0);
  dda(-40,0,0,0);
  dda(0,0,0,40);
  dda(0,40,40,40);
  dda(40,40,40,80);
  dda(40,80,80,80);
  dda(80,80,80,120);
  dda(80,120,120,120);
  dda(120,120,120,160);
  dda(120,160,160,160);
  dda(160,160,160,200);
  dda(160,200,200,200);
}

int main(int argc, char** argv){
 glutInit(&argc, argv);
 glutInitWindowSize(800,800);
 glutInitWindowPosition(100,100);
 glutCreateWindow("Bres_Stairs");
 glutInitDisplayMode(GLUT_SINGLE);
 init();
 glutDisplayFunc(render);
 glutMainLoop();
 return 0;
}
