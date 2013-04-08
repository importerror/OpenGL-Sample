#include<glut.h>

int angle=0,x,y;

void keyboard(unsigned char key,int x,int y)
{
	if(key=='c')
	{
		glClearColor(1,0,0,0);

	}
}

void cube(int value)
{
	glRotatef(angle,1,0,0);
	glRotatef(angle,0,1,0);
	glRotatef(angle,0,0,1);
	//glTranslatef(2,1,0);
	glColor3f(0,0,1);
	glutWireSphere(2,10,10);
	angle+=0.5;
	glutPostRedisplay();
	glFlush();
}

void color(int value)
{
	int z;
	x=0;
	glClearColor(x,0,0,0);
	x+=0.1;
	if(x==1)
		x=0;
	glutPostRedisplay();
}


void drawstring(char *s)
{
	int i;
	glColor3f(0,1,0);
	glRasterPos2f(0,0);
	for(i=0;s[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawstring("Santosh");
	glutTimerFunc(25,cube,0);
	glFlush();
}


void myReshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 1.2, -5.5); 
}

void main()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,600);
	glutCreateWindow("Splash Screen");
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glutTimerFunc(25,color,0);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}