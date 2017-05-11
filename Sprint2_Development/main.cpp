//MAIN METHOD WHERE THE CLASS INSTANCE IS CREATED AND IT IS SET TO MAXIMUM SIZE. 

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
     QApplication app(argc, argv);
     app.setApplicationName("AssignmentI2/Menu Bar,TextEditor,AssignmentI1 Widgets");
     MainWindow mainWin;
     mainWin.showMaximized();
     mainWin.show();

     return app.exec();
}
