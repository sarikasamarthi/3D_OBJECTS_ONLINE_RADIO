#include <QtGui/QtGui>
#include <GL/glu.h>
#include <QtOpenGL/QtOpenGL>
#include <GL/glut.h>
//#include <GLUT/glut.h>
#include <math.h>
#include "frac.h"

typedef GLfloat point2[2];
point2 v[3]={{-1.0,-0.58},{1.0,-0.58},{0.0,1.15}};
int n=1;

Frac::Frac(QWidget *parent)
    : QGLWidget(parent)
{
   timerobj= new QTimer(this);
   connect(timerobj,SIGNAL(timeout()),this,SLOT(timer()));
   timerobj->start(500);
}

Frac::~Frac()
{

}
void Frac::triangle( point2 a, point2 b, point2 c)

/* display one triangle  */
{
      
      //glBegin(GL_TRIANGLES);
      glVertex2fv(a); 
      glVertex2fv(b);  
      glVertex2fv(c);
      //glEnd();
     // updateGL();
}

void Frac::divide_triangle(point2 a, point2 b, point2 c, int m)
{
/* triangle subdivision using vertex numbers */
    point2 v0, v1, v2;
    int j;
    if(m>0)
     {
        for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
        for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
        for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
        glColor3f(0.33,0.33,0.33);
        divide_triangle(a, v0, v1, m-1);
	glColor3f(0.0,0.0,1.0);
        divide_triangle(c, v1, v2, m-1);
	glColor3f(0.61,0.32,0.05);
        divide_triangle(b, v2, v0, m-1);
    }
    else(triangle(a,b,c));
 /* draw triangle at end of recursion */
  // updateGL();
}

void Frac::timer() {
  /*static GLfloat u = 0.0;
  u += 0.01;
  glLoadIdentity();
  gluLookAt(8*cos(u), 7*cos(u)-1, 4*cos(u/3)+2, .5, .5, .5, cos(u), 1, 0);*/
  //glutPostRedisplay();
  //glutTimerFunc(1000/60.0, timer, v);
  updateGL();
}

//Initialize the GL settings
void Frac::initializeGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,-1.0,-1.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor (1.0, 1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);
    //glutSwapBuffers();
}



//Paints the GL scene
void Frac::paintGL()
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
       divide_triangle(v[0],v[1],v[2],n);
 if(n<=5)
  n++;
 else
  n=1;
    glEnd();
    glFlush();

}

