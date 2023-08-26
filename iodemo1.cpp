#include<GL/glut.h>
#include<stdio.h>

GLsizei ww=400, wh=300;

void init(void)
{
 glClearColor(0.0,0.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,200.0,0.0,150.0);
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0.0,0.0);
 glPointSize(6.0);

 char name[]="ajay sharma";
 glRasterPos2f(100.0,120.0);
 for(int i=0;i<11;i++)
 {
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name[i]);
 }
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
 if(button == GLUT_LEFT_BUTTON && action == GLUT_UP)
 {
  plotPoint(xMouse,wh-yMouse); 
 }
 glFlush();
 printf("%d %d\n",xMouse,yMouse);
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

