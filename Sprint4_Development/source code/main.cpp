//MAIN METHOD WHERE THE CLASS INSTANCE IS CREATED AND IT IS SET TO MAXIMUM SIZE. 

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
     QApplication app(argc, argv);
     app.setApplicationName("AssignmentI3/Widgets,Graphics window,Cos wave Generation");
     MainWindow mainWin;
     mainWin.resize( 800, 600 );
    // mainWin.showMaximized();
     mainWin.show();

     return app.exec();
}
