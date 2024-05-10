#include<GL/glut.h>

GLfloat xRotated,yRotated,zRotated;
void init(){
  glClearColor(0.0,0.0,0.0,0.0);
}

void drawCube(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0f,0.0f,-10.5f);
  glRotatef(xRotated,1.0,0.0,0.0);
  glRotatef(yRotated,0.0,1.0,0.0);
  glRotatef(zRotated,0.0,0.0,1.0);
  glBegin(GL_QUADS);
  //top
  glColor3f(1.0,0.0,0.0);   //tr
  glVertex3f(1.0,1.0,-1.0);  //tl
  glVertex3f(-1.0,1.0,-1.0);  //bl
  glVertex3f(-1.0,1.0,1.0);  //br
  glVertex3f(1.0,1.0,1.0);
  //bottom
  glColor3f(1.0,1.0,0.0);
  glVertex3f(1.0,-1.0,1.0);
  glVertex3f(-1.0,-1.0,1.0);
  glVertex3f(-1.0,-1.0,-1.0);
  glVertex3f(1.0,-1.0,-1.0);
  //front
  glColor3f(1.0,0.0,1.0);
  glVertex3f(1.0,1.0,1.0);
  glVertex3f(-1.0,1.0,1.0);
  glVertex3f(-1.0,-1.0,1.0);
  glVertex3f(1.0,-1.0,1.0);
  //back
  glColor3f(1.0,0.5,0.0);
  glVertex3f(-1.0,1.0,-1.0);
  glVertex3f(1.0,1.0,-1.0);
  glVertex3f(1.0,-1.0,-1.0);
  glVertex3f(-1.0,-1.0,-1.0);
  //left
  glColor3f(0.0,1.0,0.0);
  glVertex3f(-1.0,1.0,1.0);
  glVertex3f(-1.0,1.0,-1.0);
  glVertex3f(-1.0,-1.0,-1.0);
  glVertex3f(-1.0,-1.0,1.0);
  //right
  glColor3f(0.0,0.0,1.0);
  glVertex3f(1.0,1.0,-1.0);
  glVertex3f(1.0,1.0,1.0);
  glVertex3f(1.0,-1.0,1.0);
  glVertex3f(1.0,-1.0,-1.0);
  glEnd();
  glFlush();
}

void animate(){
  yRotated+=0.2;
  drawCube();
}

void reshape(int x,int y){
  if(y==0 || x==0) return;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
  glMatrixMode(GL_MODELVIEW);
  glViewport(0,0,x,y);
}

int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(800,800);
  glutInitWindowPosition(100,100);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(drawCube);
  glutReshapeFunc(reshape);
  glutIdleFunc(animate);
  glutMainLoop();
  return 0;
}  
  
