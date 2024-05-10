#include<iostream>
#include<GL/glut.h>
#include<cmath>
using namespace std;

void plot(int x,int y){
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void bresCircle(int xc, int yc, int rad){
	int x = 0;
	int y = rad;
	int P = 3-2*rad;
	
	while(x<=y){
		x++;
		if(P<0){P+=4*x+6;}
		else{
			y--;
			P+=4*(x-y)+10;
		}
		
		plot(xc + x, yc+y);
		plot(xc - x, yc+y);
		plot(xc + x, yc-y);
		plot(xc - x, yc-y);
		plot(xc + y, yc+x);
		plot(xc - y, yc+x);
		plot(xc + y, yc-x);
		plot(xc - y, yc-x);
	}
	glFlush();
}

void display(){
	//bresCircle(250,250,75);
	int cx=100;
	int cy = 100;
	int rad = 100;
	bresCircle(cx,cy,rad);
	bresCircle(cx,cy,rad/2);
	
	bresCircle(cx,cy+rad/2,rad/2);
	bresCircle(cx,cy-rad/2,rad/2);
	bresCircle(cx+rad/2,cy,rad/2);
	bresCircle(cx-rad/2,cy,rad/2);
	bresCircle(cx+rad/2/sqrt(2),cy+rad/2/sqrt(2),rad/2);
	bresCircle(cx+rad/2/sqrt(2),cy-rad/2/sqrt(2),rad/2);
	bresCircle(cx-rad/2/sqrt(2),cy+rad/2/sqrt(2),rad/2);
	bresCircle(cx-rad/2/sqrt(2),cy-rad/2/sqrt(2),rad/2);
	
}

void mouse(int button,int state,int x,int y){
	cout<<x<<" "<<y<<endl;
	bresCircle(x,y,20);
}

void init(){
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,500,0);
}

int main(int argv,char** argc){
	int x=250;
	int y=250;
	glutInit(&argv,argc);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Necklace or Bangle");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
