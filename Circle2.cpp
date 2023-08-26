#include <GL/glut.h>

int xc = 300, yc = 300, r = 100;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc - y, yc - x);
    glEnd();
}

void bresenham_circle()
{
    int x = 0, y = r, d = 1-r;
    while (x <= y)
    {
        plot(x, y);
        if (d < 0)
        {
            d = d + 2 * x + 3;

        }
        else
        {
            d = d + 2 * (x - y) + 5;
            y--;

        }
        x++;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 3.0, 0.0);
    bresenham_circle();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham Circle");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0, 600, 0, 600);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
