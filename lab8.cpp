#include <GL/glut.h>

int x_min = 100, y_min = 100, x_max = 500, y_max = 500;  // Window coordinates
int xc = 300, yc = 300, r = 100;  // Circle center and radius
int x1 = 150, y1 = 400, x2 = 450, y2 = 150;  // Line endpoints

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void mapCoordinates(int& x, int& y) {
    // Map x-coordinate to screen space
    x = ((float)(x - x_min)/(x_max - x_min)) * 600;

    // Map y-coordinate to screen space and flip y-axis
    y = 600 - ((float)(y - y_min)/(y_max - y_min)) * 600;
}

void bresenham_circle() {
    int x = 0, y = r, d = 1 - r;
    while (x <= y) {
        mapCoordinates(xc + x, yc + y);
        setPixel(xc + x, yc + y);
        mapCoordinates(xc + x, yc - y);
        setPixel(xc + x, yc - y);
        mapCoordinates(xc - x, yc + y);
        setPixel(xc - x, yc + y);
        mapCoordinates(xc - x, yc - y);
        setPixel(xc - x, yc - y);
        mapCoordinates(xc + y, yc + x);
        setPixel(xc + y, yc + x);
        mapCoordinates(xc + y, yc - x);
        setPixel(xc + y, yc - x);
        mapCoordinates(xc - y, yc + x);
        setPixel(xc - y, yc + x);
        mapCoordinates(xc - y, yc - x);
        setPixel(xc - y, yc - x);
        if (d < 0) {
            d = d + 2 * x + 3;
        } else {
            d = d + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

void bresenham_line() {
    int dx = x2 - x1, dy = y2 - y1, d, inc1, inc2, x, y;
    if (dx < 0) {
        dx = -dx;
        inc1 = -1;
    } else {
        inc1 = 1;
    }
    if (dy < 0) {
        dy = -dy;
        inc2 = -1;
    } else {
        inc2 = 1;
    }
    x = x1;
    y = y1;
    mapCoordinates(x, y);
    setPixel(x, y);
    if (dx > dy) {
        d = 2 * dy - dx;
        while (x != x2) {
            if (d >= 0) {
                y += inc2;
                d -= 2 * dx;
            }
            x += inc1;
            d += 2 * dy;
            mapCoordinates(x, y);
            setPixel(x, y);
        }
    } else {
        d = 2 * dx - dy;
        while (y != y2) {
            if (d >= 0) {
                x += inc1;
                d -= 2 * dy;
            }

