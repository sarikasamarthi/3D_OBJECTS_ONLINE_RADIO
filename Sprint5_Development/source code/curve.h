#ifndef Curve_H
#define Curve_H

#include <QtOpenGL/QGLWidget>

class Curve : public QGLWidget  {
    Q_OBJECT

public:
    Curve(QWidget *parent = 0);
    ~Curve();

//public slots:
   
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void ngon(int n);
//private:
    
};

#endif
