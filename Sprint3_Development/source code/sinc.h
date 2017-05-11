/*Example from tracs modified to class and header file and added two user defined functions and two variables and changed the formula to calculate Acos(2*Pi*F*t) */ 

#ifndef Sinc_H
#define Sinc_H

#include <QtOpenGL/QGLWidget>

class Sinc : public QGLWidget  {
    Q_OBJECT

public:
    Sinc(QWidget *parent = 0);
    ~Sinc();

public slots:
    void setAmplitude(int a);
    void setFrequency(int f);
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void ngon(int n);
private:
    int amplitude;
    int frequency;
};

#endif






