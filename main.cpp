#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
using namespace std;
float X = 0, Y = 0, Z = 0, pX = 0, pY = 0;
int COUNTER = 0;
float COLOR_RED = 0.0f, COLOR_GREEN = 0.0f, COLOR_BLUE = 0.0f;
struct WIND;
bool RCLICK = false, RUNNING = true, OVERRIDE = false;
void specialMonitor(int key, int x, int y);
void keyboardMonitor(unsigned char key, int x, int y);
void mouseMonitor(int button, int state, int x, int y);
void detectMotion(int x, int y);
void detectPassiveMotion(int x, int y);
void mouseEntryDetector(int state);
void animateText();
void defaultDisplay();
void animate(int value);

void drawline(float from_x, float from_y, float to_x, float to_y) {
	// From coordinate position
	glVertex2f(from_x, from_y);

	// To coordinate position
	glVertex2f(to_x, to_y);
}

void drawQuad(float v1a, float v1b, float v2a, float v2b, float v3a, float v3b, float v4a, float v4b) {
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.6, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(v1a, v1b); // vertex 1
	glVertex2f(v2a, v2b); // vertex 2
	glVertex2f(v3a, v3b); // vertex 3
	glVertex2f(v4a, v4b); // vertex 1
//	glVertex2f(.2f, 0.1f); // vertex 1
//	glVertex2f(-0.2f,0.1f); // vertex 2
//	glVertex2f(-0.2f, 0.8f); // vertex 3
//	glVertex2f(0.2f, 0.8f); // vertex 4
	glEnd();
	//glFlush();
}
void drawTriangle(float r, float g, float b, float v1a, float v1b, float v2a, float v2b, float v3a, float v3b) {
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
	glVertex2f(v1a, v1b); // vertex 1
	glVertex2f(v2a, v2b); // vertex 2
	glVertex2f(v3a, v3b); // vertex 3
	glEnd();
	//glFlush();
}
void render(void) {


	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho( 0.0, 4.0, 0.0, 4.0, -1, 1 );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw shape one
	glPushMatrix();
	glTranslatef(-0.1, -0.5, 0);
	//drawTriangle(1.0f,1.0f,0.0f,.2f,.1f,.2f,.8f,.5f,.5f);
	defaultDisplay();
	//const unsigned char str[100] = "August Florese";
	glColor3f(0.0f,0.0f,1.0f);
	//glRasterPos2f(X,Y);
	//glutBitmapString(GLUT_BITMAP_HELVETICA_18, str);
	drawQuad(X+.2f,Y+.1f, X+-0.2f,Y+0.1f, X+-0.2f,Y+0.8f, X+0.2f,Y+0.8f);
	if(!OVERRIDE){
		drawTriangle(1.0f,1.0f,0.0f,  X + .2f,Y+.1f,     X+.2f,Y+.8f,    X+.5f,Y+.5f);
		drawTriangle(1.0f,0.0f,1.0f,  X + .2f,Y+.1f,     X+(-.2f),Y+.1f, X+.0f,Y+-.5f);
		drawTriangle(0.0f,1.0f,1.0f,  X + -.2f,Y+.8f,    X+(-.2f),Y+.1f, X+-.5f,Y+.5f);
		drawTriangle(0.0f,.5f,1.0f,   X + -.2f,Y+.8f,    X+.2f,Y+.8f,    X+.0f,Y+1.32f);	
	}else{
		drawTriangle(COLOR_RED,COLOR_GREEN,COLOR_BLUE,  X + .2f,Y+.1f,     X+.2f,Y+.8f,    X+.5f,Y+.5f);
		drawTriangle(COLOR_RED,COLOR_GREEN,COLOR_BLUE,  X + .2f,Y+.1f,     X+(-.2f),Y+.1f, X+.0f,Y+-.5f);
		drawTriangle(COLOR_RED,COLOR_GREEN,COLOR_BLUE,  X + -.2f,Y+.8f,    X+(-.2f),Y+.1f, X+-.5f,Y+.5f);
		drawTriangle(COLOR_RED,COLOR_GREEN,COLOR_BLUE,   X + -.2f,Y+.8f,    X+.2f,Y+.8f,    X+.0f,Y+1.32f);	
	}
	
//	drawTriangle(1.0f,1.0f,0.0f,  X + .2f,Y+.1f,     X+.2f,Y+.8f,    X+.5f,Y+.5f);
//	drawTriangle(1.0f,0.0f,1.0f,  X + .2f,Y+.1f,     X+(-.2f),Y+.1f, X+.0f,Y+-.5f);
//	drawTriangle(0.0f,1.0f,1.0f,  X + -.2f,Y+.8f,    X+(-.2f),Y+.1f, X+-.5f,Y+.5f);
//	drawTriangle(0.0f,.5f,1.0f,   X + -.2f,Y+.8f,    X+.2f,Y+.8f,    X+.0f,Y+1.32f);
//	drawQuad(.2f,.1f, -0.2f,0.1f, -0.2f,0.8f, 0.2f,0.8f);
//	drawTriangle(1.0f,1.0f,0.0f,X + .2f,.1f,.2f,.8f,.5f,.5f);
//	drawTriangle(1.0f,0.0f,1.0f,X + .2f,.1f,-.2f,.1f,.0f,-.5f);
//	drawTriangle(0.0f,1.0f,1.0f,X + -.2f,.8f,-.2f,.1f,-.5f,.5f);
//	drawTriangle(0.0f,.5f,1.0f,X + -.2f,.8f,.2f,.8f,.0f,1.32f);
//
	glFlush();
	glutTimerFunc(1000,animate,5);
//	if(RCLICK){
//
//	}

	glPopMatrix();

	// Draw shape two
	glPushMatrix();
	glTranslatef(-0.1, -0.5, 0);
	//drawTriangle(1.0f,1.0f,0.0f,.2f,.1f,.2f,.8f,.5f,.5f);
	//glTranslatef(2.5, 2.5, 0.0);
	//glTranslatef(X, Y, Z);
	//drawQuad();
	glPopMatrix();

	glutSwapBuffers();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
void init(void) {
	// set clear color to black
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// set fill color to white
	glColor3f(1.0, 1.0, 1.0);
	//set up standard orthogonal view with clipping
	//box as cube of side 2 centered at origin
	//This is the default view and these statements could be removed
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
	std::cout << "August Florese's setup (that's me)";

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1200, 720);
	glutInitWindowPosition (0, 0);
	glutCreateWindow("Technical 2: August Florese Edition");
	init ();
	glutKeyboardFunc(keyboardMonitor);
	glutMouseFunc(mouseMonitor);
	glutSpecialFunc(specialMonitor);
//	glutMotionFunc(detectMotion);
//	glutPassiveMotionFunc(detectPassiveMotion);
	glutDisplayFunc(render);
	
	while (RUNNING) {
		glutMainLoop();
	}
	

	return 0;
}
void keyboardMonitor(unsigned char key, int x, int y) {
	cout<< key << endl;
	switch(key) {
		case 'w':
			Y+= .02f;
		case 'a':
			X-= .02f;
			break;
		case 's':
			Y-= 0.02f;
		case 'd':
			X+= .02f;
			break;
		case 27:
			//glutDestroyWindow (WIND);
      		exit (0);
			glutExit();
			RUNNING = false;
			
			break;
		default:
			X=0.0f;
	}
	glutPostRedisplay();
}
void specialMonitor(int key, int x, int y) {
	cout<< key << endl;
	switch(key) {

		case GLUT_KEY_UP:
			Y+= .02f;

		case GLUT_KEY_LEFT:
			X-= .02f;
			break;

		case GLUT_KEY_DOWN:
			Y-= 0.02f;

		case GLUT_KEY_RIGHT:
			X+= .02f;
			break;
			
		case GLUT_KEY_F1:
			COLOR_RED = 1.0f;
			OVERRIDE = true;
		default:
			X=0.0f;
	}
	glutPostRedisplay();
}

void mouseEntryDetector(int state) {
//	if(state == GLUT_LEFT) {
//		cout<< "Mouse has left the application " <<endl;
//	} else {
//		cout<< "Mouse has re-entered the application " << endl;
//	}
}
void animate(int value) {
	if(COUNTER<5 && RCLICK == true) {
		if(COUNTER==0) {
			
			pX=X;
			pY=Y;
			Sleep(5000);
		}
		X+= 0.05;
		COUNTER+=1;
	}else if (COUNTER >=5){
		RCLICK = false;
		COUNTER = 0;
		X=pX;
		Y=pY;
	} else {
		
		//X-= 0.02;
	}
	glutPostRedisplay();
}
void animateText() {
//	Sleep(1000);
//	X+= .02f;
//	glutPostRedisplay();
}
//void detectMotion(int x, int y) {
//	cout<< x << " " << y << endl;
//}
//void detectPassiveMotion(int x, int y) {
//	cout<< x << "P " << y << endl;
//}
void mouseMonitor(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON) {
		if( state == GLUT_DOWN)
			cout<< "Left button was clicked..." << " " << X << endl;
		else
			cout<< "Left button was released..." << endl;
	} else if(button == GLUT_RIGHT_BUTTON) {
		cout<< "Right button was clicked..." << " " << X << endl;
		RCLICK = true;
	} else {
		cout<< "Middle button was clicked..." << endl;
	}
	//cout<< x << " " << y << endl;
	cout<< RCLICK << endl;
}
void defaultDisplay() {
	//glClear(GL_COLOR_BUFFER_BIT);
//	const unsigned char str[100] = "August Florese";
//	glColor3f(0.0f,0.0f,1.0f);
//	glRasterPos2f(X,Y);
//	glutBitmapString(GLUT_BITMAP_HELVETICA_18, str);
	glFlush();
//	if(RCLICK = true)
//		glutTimerFunc(1000,animate,1);
}