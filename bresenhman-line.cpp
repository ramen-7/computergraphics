#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;
GLdouble X1, Y1, X2, Y2;
void display(void)
{
	int dx = abs(X1 - X2);
	int dy = abs(Y1 - Y2);
	int xInc = X2 > X1 ? 1 : -1;
	int yInc = Y2 > Y1 ? 1 : -1;
	int x = X1, y = Y1;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	if (dx > dy)
	{
		int p = 2 * dy - dx;
		for (int i = 0; i < dx; i++)
		{
			if (p >= 0)
			{
				y += yInc;
				p -= 2 * dx;
			}
			x += xInc;
			p -= 2 * dy;
			glVertex2d(x, y);
		}
	}
	else //if dx < dy
	{
		int p = 2 * dx - dy;
		for (int i = 0; i < dy; i++)
		{
			if (p >= 0)
			{
				x += xInc;
				p -= 2 * dy;
			}
			y += yInc;
			p += 2 * dy;
			glVertex2i(x, y);
		}
	}
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
	cout << "Enter Two Points for Draw LineBresenham:\n";
	cout << "\nEnter Point1( X1 , Y1):";
	cin >> X2 >> Y2;
	cout << "\nEnter Point2( X2 , Y2):";
	cin >> X2 >> Y2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("LineBresenham");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
