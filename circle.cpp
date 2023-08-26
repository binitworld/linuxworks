#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);

    int x0 = 250, y0 = 250, r = 100;
    glBegin(GL_POINTS);
    for(float theta = 0; theta < 360; theta += 0.01) {
        int x = round(x0 + r*cos(theta*3.14159/180));
        int y = round(y0 + r*sin(theta*3.14159/180));
        glVertex2i(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle Scan Conversion");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
