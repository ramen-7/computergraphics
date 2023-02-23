#include <GL/glut.h>  // include GLUT library
#include <iostream>

using namespace std;

int x1, y1, x2, y2;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // set clear color to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);  // set up a 2D coordinate system
}

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int incx = x2 > x1 ? 1 : -1;
    int incy = y2 > y1 ? 1 : -1;
    int x = x1;
    int y = y1;
    plot(x, y);
    if (dx > dy) {
        int e = 2 * dy - dx;
        for (int i = 0; i < dx; i++) {
            if (e >= 0) {
                y += incy;
                e -= 2 * dx;
            }
            x += incx;
            e += 2 * dy;
            plot(x, y);
        }
    } else {
        int e = 2 * dx - dy;
        for (int i = 0; i < dy; i++) {
            if (e >= 0) {
                x += incx;
                e -= 2 * dy;
            }
            y += incy;
            e += 2 * dx;
            plot(x, y);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);  // set drawing color to white
    bresenham(x1, y1, x2, y2);
    glFlush();  // force any buffered drawing to complete
}

int main(int argc, char** argv) {
    cout << "Enter the starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the ending point (x2, y2): ";
    cin >> x2 >> y2;

    glutInit(&argc, argv);  // initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // set up display mode
    glutInitWindowSize(500, 500);  // set up window size
    glutCreateWindow("Bresenham Line Algorithm");  // set up window title
    init();  // call initialization function
    glutDisplayFunc(display);  // call display function
    glutMainLoop();  // enter event-processing loop
    return 0;
}
