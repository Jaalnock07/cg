#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

#define Xmax 1400
#define Ymax 900
#define Radian (3.14/180)


//void draw(int );
//void drawkoch(float,float,float,float,int);


void draw(int n)
{
   glBegin(GL_LINES);
      drawkoch(600,100,800,400,n);
      drawkoch(800,400,400,400,n);
      drawkoch(400,400,600,100,n);
   glEnd();
   glFlush();
      
}

void drawkoch(float x1,float y1,float x2,float y2,int n)
{
  float x3,y3,x4,y4,midx,midy;
  
  x3=(2*x1+x2)/3;
  y3=(2*y1+y2)/3;
  x4=(2*x2+x1)/3;
  y4=(2*y2+y1)/3;
  
  midx=x3+((x4-x3)*cos(60*Radian))+((y4-y3)*sin(60*Radian));
  midy=y3-((x4-x3)*sin(60*Radian))+((y4-y3)*cos(60*Radian));
  
  if(n>0)
  { 
    drawkoch(x1,y1,x3,y3,n-1);
    drawkoch(x3,y3,midx,midy,n-1);
    drawkoch(midx,midy,x4,y4,n-1);
    drawkoch(x4,y4,x2,y2,n-1);
  }
  else{
      glVertex2f(x1,y1);
      glVertex2f(x3,y3);
      
      glVertex2f(x3,y3);
      glVertex2f(midx,midy);
      
      glVertex2f(midx,midy);
      glVertex2f(x4,y4);
      
      glVertex2f(x4,y4);
      glVertex2f(x2,y2);
      
  }
  
}

void init()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0,0,0,0.3);
  glColor3f(1,1,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,Xmax,0,Ymax); 
}

int main(int argc,char **argv)
{
int n;
cout<<"Enter the no of iteration u want::"<<endl;
cin>>n;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
glutInitWindowSize(500,500);
//glutInitWindowPosition(0,0);
glutCreateWindow("Koch Curve");
init();
draw(n);

glutMainLoop();
return 0;
}





