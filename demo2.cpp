#include<GL/glut.h>
#include<stdio.h>
#include<string.h>

GLint ww=400, wh=400;
char str[30];

void init(void)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-50.0,150.0,-50.0,100.0);
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0.0,0.0);
 glPointSize(6.0);
}

void winReshape(GLint nw, GLint nh)
{
 glViewport(0,0,nw,nh);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,GLdouble(nw),0.0,GLdouble(nh));
 ww = nw;
 wh = nh;
}

void plotPoint(GLint x,GLint y)
{
 glBegin(GL_POINTS);
  glVertex2i(x,y); 
 glEnd();
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
 glClear(GL_COLOR_BUFFER_BIT);
 if(button == GLUT_LEFT_BUTTON && action == GLUT_UP)
 {
  sprintf(str,"%d, %d",xMouse (-ww/2), (wh/2) -yMouse); 
  glRasterPos2i(xMouse,wh-yMouse);
  for(int i=0;i<strlen(str);i++)
  {
   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
  }
 }
 glFlush();
 printf("%d %d\n",xMouse, -yMouse);
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,100);
 glutInitWindowSize(ww,wh);
 glutCreateWindow("mouse demo1");
 
 init();
 glutDisplayFunc(display);
 glutReshapeFunc(winReshape);
 glutMouseFunc(mousePtPlot);

 glutMainLoop();
 return 0;
}

