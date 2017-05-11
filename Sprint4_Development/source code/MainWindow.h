//HEADER FILE WHERE ALL THE VARIABLES,METHODS AND CONSTRUCTORS ARE INITIALIZED.FOLLOWED THE EXAMPLE FROM APPLICATION(MAIN WINDOW) FROM EXAMPLES AND DEMOS AS SPECIFIED BY THE PROFESSOR IN CLASS.SLOTS IMPLEMENTED ARE OPEN,SAVE,LOADFILE,SAVEFILE,SETCURRENTFILE,ABOUT.METHODS IMPLEMENTED ARE CREATEACTIONS,CREATEMENUS,CREATEDOCKWINDOWS,CREATESTATUSBAR.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QCheckBox>

//class QAction;
class QMenu;
//class QPlainTextEdit;
class GLobj;
class Sinc;

class MainWindow : public QMainWindow
 {
     Q_OBJECT

 	public:
     		MainWindow();

	//private slots:
     		
     		/*void open();
     		bool save();
     		void loadFile(const QString &fileName);
     		bool saveFile(const QString &fileName);
     		void setCurrentFile(const QString &fileName);
		void about();*/

	private:
		//void createActions();
     		void createMenus();
		//void createStatusBar();
		void createDockWidgets();

	/*QPlainTextEdit *textEdit;
	QString curFile;*/
        QWidget *centralWidget;

	QMenu *fileMenu;
     	QMenu *exitMenu;
     	QMenu *helpMenu;
	/*QAction *openAct;
        QAction *saveAct;
	QAction *exitAct;
	QAction *aboutAct;
        QAction *aboutQtAct;*/

	GLobj *globj;
	Sinc *sinc;
 };

#endif
