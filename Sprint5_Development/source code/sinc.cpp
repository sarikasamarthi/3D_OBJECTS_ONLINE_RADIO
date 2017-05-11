/*Example from tracs modified to class and header file and added two user defined functions and two variables and changed the formula to calculate Acos(2*Pi*F*t) */ 
#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "sinc.h"

//Vlaues for amlitude and frequency are initialized here
Sinc::Sinc(QWidget *parent)
    : QGLWidget(parent)
{
	amplitude=1;
	frequency=1;
}

Sinc::~Sinc()
{

}

//Function to set amplitude value when the volume widget is set
void Sinc::setAmplitude(int a){
   amplitude=a;
   updateGL();
}
//Function to set frequency value when the slidder for AM station is set
void Sinc::setFrequency(int f){
  frequency=f;
  updateGL();
}

//Initialize the GL settings
void Sinc::initializeGL()
{
        glClearColor(1.0,1.0,1.0,0.0);       // set white background color
        glColor3f(1.0f, 0.0f, 0.0f);          // set the drawing color 
 	glLineWidth(4.0);		       // a ?dot? is 4 by 4 pixels
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void Sinc::resizeGL( int w, int h )
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
   glOrtho(-9.0, 9.0, -0.3, 1.0,-1,1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

//implicit call to paintGL after resized
}

//Paints the GL scene
void Sinc::paintGL()
{
   glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

	glBegin(GL_LINE_STRIP);
        for(GLfloat x = -10.0; x < 10.0; x += 0.1)     // draw the plot
		glVertex2f(x, amplitude*cos(2*3.14159 *frequency*x)); 
	glEnd();
	glFlush(); 
   
}




