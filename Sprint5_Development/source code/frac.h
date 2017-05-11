#ifndef Frac_H
#define Frac_H

#include <QtOpenGL/QGLWidget>
#include <QtGui/QtGui>
//#include <GL/glu.h>
#include <QtOpenGL/QtOpenGL>
#include <GL/glut.h>

class Frac : public QGLWidget  {
    Q_OBJECT

public:
    Frac(QWidget *parent = 0);
    ~Frac();
public slots:
     void timer();
 
protected:
    void initializeGL();
    void paintGL();
   void triangle(GLfloat *a, GLfloat *b, GLfloat *c);
   void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c,int m); 

   QTimer *timerobj;     
};

#endif
