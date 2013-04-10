#include<glut.h>

int angle=0,x,y;
int angle1=0;

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
glScalef(1,1,1.0001);
glColor3f(1,0,0);
glutWireSphere(2,10,10);
angle+=0.5;
glutPostRedisplay();
glFlush();
}



void drawstring(char *s)
{
int i;
glColor3f(0,1,0);
glRotatef(angle1,1,0,0);
glRasterPos2f(0,-3);
for(i=0;s[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
angle1+=0.5;
glutPostRedisplay();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glRotatef(angle1,1,0,0);
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
glutTimerFunc(25,cube,0);
glutKeyboardFunc(keyboard);
glutMainLoop();
}
