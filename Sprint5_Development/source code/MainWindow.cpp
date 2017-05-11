/*HEART OF THIS ASSIGNMENTI2 IS HERE.ALL IMPLEMENTATIONS OF ALL METHODS ARE DONE HERE.FOLLOWED THE EXAMPL FOR APPLICATION FROM MAINWINDOW IN EXAMPLES AND DEMOS.IMPLEMENTED OPEN,SAVE,ABOUT,ABOUTUS.COPIED ALL THE WIDGETS FROM ASSIGNMENTI1 ON THE DOCKWINDOW.*/

#include <QtGui>
#include <QtOpenGL>
#include "MainWindow.h"
#include "globj.h"
#include "sinc.h"
#include "frac.h"
#include "curve.h"

/*CONSTRUCTOR IMPLEMENTATION,TEXTEDITOR INSTANCE IS CREATED AND IT IS SET AS CENTRAL WIDGET.CALLING THE METHODS CREATEACTIONS,CREATEMENUS,CREATESTATUSBAR,CREATEDOCKWIDGETS.*/

MainWindow::MainWindow() {

     	textEdit = new QPlainTextEdit;
     	//setCentralWidget(textEdit);
        centralWidget = new QWidget;
        setCentralWidget(centralWidget);
	globj = new GLobj(this);
        sinc  = new Sinc(this);
	frac = new Frac(this);
        curve = new Curve(this);
         //centralWidget->setLayout(centralLayout);
     	createActions();
     	createMenus();
     	createStatusBar();
     	createDockWidgets();
 }

/*IMPLEMENTATION OF FILE->OPEN IN MENU BAR.FIRST HAVE TO SELECT THE FILE NAME.IF ITS NOT EMPTY IT WILL LOAD THE FILE.*/
void MainWindow::open() {
     
         QString fileName = QFileDialog::getOpenFileName(this);
         if (!fileName.isEmpty())
             loadFile(fileName);
 }

void MainWindow::createActions() {
	
	openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    	//openAct->setShortcuts(QKeySequence::Open);
     	openAct->setStatusTip(tr("Open an existing file"));
     	connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

	exitAct = new QAction(tr("E&xit"), this);
     	//exitAct->setShortcuts(QKeySequence::Quit);
     	exitAct->setStatusTip(tr("Exit the application"));
     	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

//MENUBAR AND MENU ITEMS ARE CREATED
void MainWindow::createMenus() {
     	
	fileMenu = menuBar()->addMenu(tr("&File"));
     	fileMenu->addAction(openAct);
     	//fileMenu->addAction(saveAct);
        exitMenu = menuBar()->addMenu(tr("&Exit"));
     	
	//menuBar()->addAction(exitAct);
     
	helpMenu = menuBar()->addMenu(tr("&Help"));
     	//helpMenu->addAction(aboutAct);
     	//helpMenu->addAction(aboutQtAct);
 }

//IMPLEMENTATION OF STATUSBAR MESSAGE
void MainWindow::createStatusBar() {
     
	statusBar()->showMessage(tr("Ready"));
 }

/*FILE IS LOADED INTO TEXTEDITOR WHEN THE USER OPEN THE FILE USING MENUBAR ITEM OPEN.*/
void MainWindow::loadFile(const QString &fileName) {
     
	QFile file(fileName);
     	
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
         	QMessageBox::warning(this, tr("Application"),
                                    tr("Cannot read file %1:\n%2.")
                                    .arg(fileName)
                                    .arg(file.errorString()));
        return;
        }

        QTextStream in(&file);
 	
	#ifndef QT_NO_CURSOR
    		 QApplication::setOverrideCursor(Qt::WaitCursor);
 	#endif
    
        textEdit->setPlainText(in.readAll());
        
        #ifndef QT_NO_CURSOR
    		 QApplication::restoreOverrideCursor();
 	#endif

    	setCurrentFile(fileName);
    	statusBar()->showMessage(tr("File loaded"), 2000);
 }

void MainWindow::setCurrentFile(const QString &fileName) {
     
	curFile = fileName;
     	textEdit->document()->setModified(false);
     	setWindowModified(false);

     	QString shownName = curFile;
     
	if (curFile.isEmpty())
         	shownName = "untitled.txt";
     	
	setWindowFilePath(shownName);
 }

/*IMPLEMENTATION OF WIDGETS IN THE DOCK.DIRECTLY COPIED FROM ASSIGNMENTI1 AS PER THE REQUIREMENT FOR THIS ASSIGNMENTI2.DIDN'T DO ANYCHANGES AT ALL.*/
/*Implemented all the required widgets for the radio tuner.Used different widgets for different controls.Used QPalette for colors for background and foreground.Used radiobuttons,combobox,vertical slider,lcd,progress bar,horizontal slider,dial,spinbox.Used vertical and horizontal box layout and grid layout.Experimented on many widgets without looking for look and feel of the widget window.*/

void MainWindow::createDockWidgets(){

	QWidget *mywidget=new QWidget(this);
	//mywidget->setFixedSize(250,250);
	
	//USED QPalette FOR COLORS TO BACKGROUND AND FOREGROUND WIDGETS
	QPalette *palette= new QPalette();
	
	palette->setColor(QPalette::Background,Qt::black);
	mywidget->setAutoFillBackground(true);
	
	palette->setColor(QPalette::ButtonText,Qt::white);
	palette->setColor(QPalette::Button,Qt::black);
	
	QPushButton *exit = new QPushButton(tr("Exit"));

	exit->setFont(QFont("Times",12,QFont::Bold));
	exit->setPalette(*palette);
	//When exit button is clicked it closes the window
	connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
	
	//Radio button for AM and FM.
	palette->setColor(QPalette::Foreground,Qt::red);
	QRadioButton *radio1 = new QRadioButton();
	QRadioButton *radio2 = new QRadioButton();
	radio1->setText("AM");
	radio1->setFont(QFont("Times",14,QFont::Bold));
	radio1->setPalette(*palette);
	palette->setColor(QPalette::Foreground,Qt::yellow);
	radio2->setText("FM");
	radio2->setFont(QFont("Times",14,QFont::Bold));
	radio2->setPalette(*palette);
	radio1->setChecked(true);	
	
	QHBoxLayout *radioLayout = new QHBoxLayout;
	radioLayout->addWidget(radio1);
	radioLayout->addWidget(radio2);
	radioLayout->addWidget(exit,0,Qt::AlignRight);
	
	QLabel *label1 = new QLabel(tr("FM STATIONS"));
	label1->setFont(QFont("Times",12,QFont::Bold));
	label1->setStyleSheet("QLabel { background-color : black; color : blue; }");

	palette->setColor(QPalette::Button,Qt::yellow);
	QDial *dial1 = new QDial();
	dial1->setNotchesVisible(false);
	dial1->setPalette(*palette);
	dial1->setRange(53,170);

	QLCDNumber *lcd1 = new QLCDNumber(3);
	lcd1->setSegmentStyle(QLCDNumber::Filled);
	lcd1->setStyleSheet("* { background-color : red; color : blue; }");

	//When dial is clicked the lcd numbers are updated
	connect(dial1,SIGNAL(valueChanged(int)),lcd1,SLOT(display(int)));

	QHBoxLayout *fmLayout = new QHBoxLayout();
	fmLayout->addWidget(label1);
	fmLayout->addWidget(lcd1);
	fmLayout->addWidget(dial1);

	QLabel *label2 = new QLabel(tr("AM STATIONS"));
	label2->setFont(QFont("Times",12,QFont::Bold));
	label2->setStyleSheet("QLabel { background-color : black; color : blue; }");

	QSlider *slider1 = new QSlider(Qt::Horizontal);
	slider1->setRange(1,100);
	slider1->setValue(1);

	QLCDNumber *lcd2 = new QLCDNumber(3);
	lcd2->setSegmentStyle(QLCDNumber::Filled);
	lcd2->setStyleSheet("* { background-color : red; color : blue; }");

	//The slider is connected to the lcd
	connect(slider1,SIGNAL(valueChanged(int)),lcd2,SLOT(display(int)));

	QHBoxLayout *amLayout = new QHBoxLayout();
	amLayout->addWidget(label2);
	amLayout->addWidget(slider1);
	amLayout->addWidget(lcd2);

	QLabel *label3 = new QLabel(tr("VOLUME"));
	label3->setFont(QFont("Times",12,QFont::Bold));
	label3->setStyleSheet("QLabel { background-color : black; color : yellow; }");

	palette->setColor(QPalette::Button,Qt::yellow);

	QDial *dial2 = new QDial();
	dial2->setNotchesVisible(true);
	dial2->setPalette(*palette);
	dial2->setRange(0,5);

	QProgressBar *bar = new QProgressBar();
	bar->setValue(1);
	
	//DIAL AND PROGRESSBAR IS CONNECTED FOR VOLUME CONTROL
	connect(dial2,SIGNAL(valueChanged(int)),bar,SLOT(setValue(int)));

	QVBoxLayout *volume = new QVBoxLayout;
	volume->addWidget(dial2);
	volume->addWidget(label3,Qt::AlignCenter);

	QHBoxLayout *volumeLayout = new QHBoxLayout;
	volumeLayout->addWidget(bar);
	volumeLayout->addLayout(volume);

	QComboBox *box = new QComboBox();
	box->addItem("BASS");
	box->addItem("TREBLE");

	QSlider *verticalGroup = new QSlider(Qt::Vertical);
	
	QLCDNumber *lcd3 = new QLCDNumber(3);
	lcd3->setSegmentStyle(QLCDNumber::Filled);
	lcd3->setStyleSheet("* { background-color : red; color : blue; }");

	QLabel *label4 = new QLabel(tr("BASS CONTROL"));
	label4->setFont(QFont("Times",12,QFont::Bold));
	label4->setStyleSheet("QLabel { background-color : black; color : blue; }");

	connect(verticalGroup,SIGNAL(valueChanged(int)),lcd3,SLOT(display(int)));

	QSpinBox * spin1 = new QSpinBox();
	spin1->setMaximum(170);
	spin1->setMinimum(53);
	
	QLCDNumber *lcd4 = new QLCDNumber(3);
	lcd4->setSegmentStyle(QLCDNumber::Filled);
	lcd4->setStyleSheet("* { background-color : red; color : blue; }");

	QLabel *label5 = new QLabel(tr("TREBLE CONTROL"));
	label5->setFont(QFont("Times",12,QFont::Bold));
	label5->setStyleSheet("QLabel { background-color : black; color : blue; }");

	connect(spin1,SIGNAL(valueChanged(int)),lcd4,SLOT(display(int)));

	QHBoxLayout *bass = new QHBoxLayout;
	bass->addWidget(lcd3);
	bass->addWidget(verticalGroup);
	

	QVBoxLayout *bassLayout = new QVBoxLayout;
	bassLayout->addWidget(label4);
	bassLayout->addLayout(bass);

	QHBoxLayout *treble = new QHBoxLayout;
	treble->addWidget(spin1);
	treble->addWidget(lcd4);

	QVBoxLayout *trebleLayout = new QVBoxLayout;
	trebleLayout->addWidget(label5);
	trebleLayout->addLayout(treble);

	QGridLayout *main = new QGridLayout;
	main->addLayout(radioLayout,0,0);
	main->addLayout(fmLayout,1,0);
	main->addLayout(amLayout,2,0);
 	main->addLayout(volumeLayout,3,0);
	main->addLayout(bassLayout,4,1);
	main->addLayout(trebleLayout,5,0);
	main->addWidget(box,4,0);

	//DOCKWIDGET INSTANCE IS CREATED AND ALIGNEDLEFT.TO THIS THE WIDGET FROM ASSIGNMENTI1 IS ATTACHED.
        QDockWidget *dock = new QDockWidget(tr("AssignmentI1/Radio Tuner"), this);
        mywidget->setLayout(main);
	mywidget->setPalette(*palette);
	dock->setWidget(mywidget);
	dock->setPalette(*palette);
        addDockWidget(Qt::LeftDockWidgetArea, dock);

        //This layout for arranging widgets window ,graphics window and cos wave generation window.
	QGridLayout *mainLayout = new QGridLayout;
         //mainLayout->addWidget(dock,0,0);
    	mainLayout->addWidget(globj,1,0);
	mainLayout->addWidget(sinc,1,1);
        mainLayout->addWidget(frac,2,0);
        mainLayout->addWidget(curve,2,1);
    	centralWidget->setLayout(mainLayout);


	//connect volume and sinwave
 	connect(dial2,SIGNAL(valueChanged(int)),sinc,SLOT(setAmplitude(int)));
        
	 //connect slider and wave
        connect(slider1,SIGNAL(valueChanged(int)),sinc,SLOT(setFrequency(int)));
}

