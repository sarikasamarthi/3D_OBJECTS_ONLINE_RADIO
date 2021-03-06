/*Graphics window is generated here.But changed projection to perspective using glFrustum and scaled the objects to increase the size.*/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj::~GLobj()
{

}

//Initialize the GL settings
void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
     glPointSize(2.0);		       
     glLineWidth(4.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GLobj::resizeGL( int w, int h )
{
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
   if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);
     

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-1, 1, -1, 1, -1, 1);
    glFrustum(-1.0, +1.0, -1.0, 1.0, 5.0, 60.0);
    glTranslated(0.0, 0.0, -40.0);
    glScalef(8,9,10);
    glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();


    //implicit call to paintGL after resized
}

//Paints the GL scene
void GLobj::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    GLfloat mycolor[18][3] = {{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.5,0.5,0.5},{1.0,1.0,0.0},{0.0,1.0,1.0},{1.0,0.0,1.0},{0.4,0.5,0.6},{0.3,0.2,1.0},{0.9,0.7,0.8},{0.6,0.73,0.51},{0.43,0.21,0.64},{0.4,0.9,0.1},{0.67,0.95,0.54},{0.32,0.42,0.71},{0.94,0.73,0.62},{0.54,0.63,0.82},{0.62,0.81,0.64}};

	//point 
	glBegin(GL_POINTS) ;
	glColor3fv(mycolor[1]);
	glVertex3f(0.6,0.6,0.0);
	glColor3fv(mycolor[8]);
	glVertex3f(0.63,0.63,0.0); 
	glColor3fv(mycolor[10]);
	glVertex3f(0.65,0.65,0.0);        
	glEnd();
	glFlush ();

	//line 
	glBegin(GL_LINES) ;
	glColor3fv(mycolor[2]);
	glVertex3f(0.97,0.85,0.0);         
	glVertex3f(0.97,-0.85,0.0) ; 
	glEnd();
	glFlush ();

	//triangle
	glBegin(GL_TRIANGLES);
	glColor3fv(mycolor[3]);
	glVertex3f(0.9,0.6,0.0);
        glVertex3f(0.6,0.9,0.0);
        glVertex3f(0.8,0.6,0.0);
	glEnd( );
	glFlush();

	//Line loop
	glBegin(GL_LINE_LOOP);
	glColor3fv(mycolor[4]);
	glVertex3f(-0.9,-0.6,0.0);
        glVertex3f(-0.6,-0.9,0.0);
        glVertex3f(-0.8,-0.6,0.0);
	//glVertex2f(-0.6,-0.9);
        glVertex3f(-0.6,-0.8,0.0);
        glVertex3f(-0.8,-0.9,0.0);
	glEnd( );
	glFlush();
    
	//Draw a quad rectangle
        glBegin(GL_QUADS);
        glColor3fv(mycolor[5]);
        glVertex3f(-0.2, -0.3,0.0);
        glVertex3f( 0.2, -0.3,0.0);
        glVertex3f( 0.2,  0.3,0.0);
        glVertex3f(-0.2, 0.3,0.0);
        glEnd(); 
        glFlush ();

       //hexagon with mathematical formula.
       glBegin(GL_LINE_LOOP) ;
       float theta = 2 * 3.1415926 /6;
       for (int i = 1; i <=6; i++){
	       glColor3fv(mycolor[i*+2]);
               glVertex3f(-0.6* sin(theta*i),-0.6* cos(theta*i),0.0);
       }
       glEnd();
       glFlush(); 

       //Octagon with matematical formula same as above with 8sides
       glBegin(GL_LINE_LOOP) ;
       float theta1 = 2 * 3.1415926 /8;
       for (int i = 1; i <=8; i++){
		glColor3fv(mycolor[i*2-1]);
    		glVertex3f(0.7* sin(theta1*i),-0.7* cos(theta1*i),0.0);
       }
       glEnd();
       glFlush(); 


       glBegin(GL_POLYGON);
       glColor3f(0.0f, 0.0f, 1.0f);
       glVertex3f(-0.4,-0.6,0.0);
       glVertex3f(-0.5,-0.5,0.0);
       glVertex3f(-0.6,-0.6,0.0);
       glVertex3f(-0.5,-0.7,0.0);
       glVertex3f(-0.4,-0.7,0.0);
       glEnd();
       glFlush();

        //cube front
	glBegin(GL_LINE_LOOP) ;
	glColor3fv(mycolor[16]);
	glVertex3f(-0.35,0.35,0.35);       
	glVertex3f(-0.35,-0.35,0.35) ;
	glVertex3f(0.35,-0.35,0.35);         
	glVertex3f(0.35,0.35,0.35) ;
	glFlush();
        glEnd();
	//cube back
	glBegin(GL_LINE_LOOP) ;
	glColor3fv(mycolor[15]);
	glVertex3f(-0.35,0.35,-0.35);         
	glVertex3f(-0.35,-0.35,-0.35) ;
	glVertex3f(0.35,-0.35,-0.35);         
	glVertex3f(0.35,0.35,-0.35) ;
        glEnd();
	glFlush();
	//cube left
	glBegin(GL_LINE_LOOP) ;
	glColor3fv(mycolor[14]);
	glVertex3f(-0.35,0.35,0.35);        
	glVertex3f(-0.35,0.35,-0.35) ;
	glVertex3f(-0.35,-0.35,-0.35);         
	glVertex3f(-0.35,-0.35,0.35) ;
        glEnd();
	glFlush();
	//cube right
	glBegin(GL_LINE_LOOP) ;
	glColor3fv(mycolor[13]);
	glVertex3f(0.35,0.35,0.35);         
	glVertex3f(0.35,-0.35,0.35) ;
	glVertex3f(0.35,-0.35,-0.35);         
	glVertex3f(0.35,0.35,-0.35) ;
        glEnd();
	glFlush();
	//cube top
	glBegin(GL_LINE_LOOP) ;
	glColor3fv(mycolor[12]);
	glVertex3f(-0.35,0.35,0.35);         
	glVertex3f(0.35,0.35,0.35) ;
	glVertex3f(0.35,0.35,-0.35);         
	glVertex3f(-0.35,0.35,-0.35) ;
        glEnd();
	glFlush();
	//cube bottom
	glBegin(GL_LINE_LOOP) ;
	glColor3fv(mycolor[11]);
	glVertex3f(-0.35,-0.35,0.35);       
	glVertex3f(0.35,-0.35,0.35) ;
	glVertex3f(0.35,-0.35,-0.35);         
	glVertex3f(-0.35,-0.35,-0.35) ;
        glEnd();
	glFlush();
}




