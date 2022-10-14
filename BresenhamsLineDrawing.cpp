#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int a1, a2, b1, b2;

// Initializing plot
void drawInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.30980f, 0.40784f, 0.95294f, 1.0f); // Background Colour
	glColor3f(0.96863f, 0.94510f, 0.67451f);		  // Graphic Colour
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500); // Aurthographic Projection
}

// Function For Joining Verteces
void drPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

// Line Using Bresenham's algorithm
void drLine(int x1, int x2, int y1, int y2)
{
	int v1, v2;
	int p1, p2, p3;
	v1 = abs(x2 - x1);
	v2 = abs(y2 - y1);
	p1 = 2 * v2 - v1;
	p2 = 2 * v2;

	p3 = 2 * (v2 - v1);
	drPixel(x1, y1);

	while (x1 < x2)
	{
		x1++;
		if (p1 < 0)
		{
			drPixel(x1, y1);
			p1 += p2;
		}
		else
		{
			y1++;
			drPixel(x1, y1);
			p1 += p3;
		}
	}
}

// Displaying The OutPut
void myDisplay()
{
	drLine(a1, a2, b1, b2);
	glFlush();
}

// Function to draw triangle
void displayTriangle()
{
	glClearColor(0.30980f, 0.40784f, 0.95294f, 1.0f);
	glColor3f(0.96863f, 0.94510f, 0.67451f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glShadeModel(GL_FLAT);
	glVertex2f(-0.90, -0.70);
	glVertex2f(0.90, -0.70);
	glVertex2f(0, 0.70);
	glEnd();
	glutSwapBuffers();
}

// Main Function
int main(int argc, char **argv)
{
	printf("Enter First Coordinate (x1,y1) : ");
	scanf("%d %d", &a1, &b1);
	printf("Enter Second Coordinate (x2,y2) : ");
	scanf("%d %d", &a2, &b2);

	// Bresemham's Line Drawing.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(50, 200); // Relative Postion When Displayed
	glutCreateWindow("Bresenham's Line Drawing Implementation");
	drawInit();
	glutDisplayFunc(myDisplay);

	// Generating a triangle
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(500, 200); // Relative Position When Displayed
	glutCreateWindow("Sample Triangle");
	glutDisplayFunc(displayTriangle);

	// Anti Aliasing using Super Sampling For Previously Generated Triangle
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glEnable(GL_MULTISAMPLE);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(950, 200); // Relative Position When Displayed
	glutCreateWindow("Anti Aliasing & Super Samping For Previously Triangle");
	glutDisplayFunc(displayTriangle);
	glutMainLoop();
}