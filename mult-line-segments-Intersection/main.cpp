#include "windows.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include "gl/glut.h"
#include <math.h>
#include "findInte.h"

const GLint screenWidth=800,screenHeight=600;

int found[NUM_INTE][3];
float points[NUM_PT][2];
float inte[NUM_INTE][2];
int _inteCount;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glShadeModel(GL_FLAT);
	glLineWidth(1.0);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);

	findIntersection(points);

	glFlush();
}

void reshape(int width,int height)
{
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)width,0.0,(GLdouble)height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,100);
	glutCreateWindow("test");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	myInit();
	glutMainLoop();
	return 0;
}
