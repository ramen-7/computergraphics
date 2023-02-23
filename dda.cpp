#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <algorithm>

using namespace std;

GLdouble X1, X2, Y1, Y2;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(1.0, 0.0, 0.0);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glPointSize(5.0); // point width
	gluOrtho2D(0, 640, 0, 480);
}

void display()
{
	GLdouble dx = X2 - X1, dy = Y2 - Y1, steps;
	float xInc, yInc, x = X1, y = Y1;
	steps = max(abs(dx), abs(dy));
	xInc = dx / (float)steps;
	yInc = dy / (float)steps;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	glVertex2d(x, y); //draws point
	for (int i = 0; i < steps; i++)
	{
		x += xInc;
		y += yInc;
		glVertex2d(x, y);
	}
	glEnd();
	glFlush(); //empties all buffers
}

int main(int argc, char** argv)
{
	cout << "Enter Two Points for Draw LineDDA:\n";
	cout << "\nEnter Point1( X1 , Y1):";
	cin >> X1 >> Y1;
	cout << "\nEnter Point2( X2 , Y2):";
	cin >> X2 >> Y2;
	glutInit(&argc, argv); //initializes GLU lib
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Line DDA");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
