#include<glut.h>

int x,y;

void Timer( int value )
{
   if( value ) glutPostRedisplay();
   glutTimerFunc(100,Timer,value);
}

void keyboard(unsigned char key,int x,int y)
{
	if(key=='c')
	{
		Timer(0);
		glClearColor(1,0,0,0);

	}
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
	glutPostRedisplay();
	glFlush();
}

void idle()
{
	int z;
	x=0;
	//glClearColor(x,0,0,0);
	x+=0.1;
	if(x==1)
		x=0;
	glutPostRedisplay();
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
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}