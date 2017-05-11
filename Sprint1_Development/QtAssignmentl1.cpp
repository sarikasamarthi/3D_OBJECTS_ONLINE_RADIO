//PROGRAM TO IMPLEMENT RADIO TUNER USING DIFFERENT WIDGETS FROM QT LIBRARIES

/*Implemented all the required widgets for the radio tuner.Used different widgets for different controls.Tried to implement user defined functions in slots for radio button and combobox, but will continue for next cycle.The code for that part is at the end in comments.Used QPalette for colors for background and foreground.Used radiobuttons,combobox,vertical slider,lcd,progress bar,horizontal slider,dial,spinbox.Used vertical and horizontal box layout and grid layout.Experimented on many widgets without looking for look and feel of the widget window.*/

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPalette>
#include <QLabel>
#include <QRadioButton>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>
#include <QSlider>
#include <QButtonGroup>
#include <QProgressBar>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>


class MyWidget:public QWidget {

	public:
		MyWidget(QWidget *parent = 0);
       /* private slots:
		void displayWidgets();*/

	/*public slots:
		void handleSelection(int);*/
};

MyWidget::MyWidget(QWidget *parent):QWidget(parent) {

	//USED QPalette FOR COLORS TO BACKGROUND AND FOREGROUND WIDGETS
	QPalette *palette= new QPalette();
	
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

	/*QButtonGroup *group = new QButtonGroup();
	group->addButton(radio1);
	group->addButton(radio2);*/
	
	
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

	//connect(radio1,SIGNAL(clicked()),this,SLOT(displayWidgets()));
	//connect(radio1,SIGNAL(toggled()),dial1,SLOT(setValue(int)));

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
	slider1->setRange(88,108);
	slider1->setValue(88);

	QLCDNumber *lcd2 = new QLCDNumber(3);
	lcd2->setSegmentStyle(QLCDNumber::Filled);
	lcd2->setStyleSheet("* { background-color : red; color : blue; }");

	//connect(radio2,SIGNAL(toggled()),spin1,SLOT(setValue(int)));
	//connect(radio2,SIGNAL(toggled()),dial1,SLOT(setValue(int)));
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
	dial2->setRange(1,100);

	QProgressBar *bar = new QProgressBar();
	bar->setValue(1);

	connect(dial2,SIGNAL(valueChanged(int)),bar,SLOT(setValue(int)));

	QVBoxLayout *volume = new QVBoxLayout;
	volume->addWidget(dial2);
	volume->addWidget(label3,Qt::AlignCenter);

	QHBoxLayout *volumeLayout = new QHBoxLayout;
	volumeLayout->addWidget(bar);
	volumeLayout->addLayout(volume);

	//MyComboBox *box = new MyComboBox(this);
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

	setLayout(main);

}

int main(int argc,char *argv[]) {

	QApplication app(argc,argv);
	
	MyWidget widget;
	widget.resize(250,250);
	QPalette palette;
	palette.setColor(QPalette::Background,Qt::black);
	widget.setAutoFillBackground(true);
	widget.setPalette(palette);
	widget.setWindowTitle("GUI AssignmentI1/Radio Tuner");
	widget.show();

	return app.exec();
}

/*class MyComboBox:public QComboBox {  
	Q_OBJECT
  	public:    
	 MYComboBox(QWidget* parent):QComboBox(parent) {
		this->setParent(parent);
	  connect(this,SIGNAL(currentIndexChanged(int)),this,SLOT(handleSelectionChanged(int)));
	}
	
	public slots:
	void handleSelectionChanged(int index) {
		if(index ==1) {
	
		//palette->setColor(QPalette::Button,Qt::red);

		QDial *dial3 = new QDial();
		dial3->setNotchesVisible(true);
		//dial3->setPalette(*palette);
		dial3->setRange(1,16);

		QLCDNumber *lcd2 = new QLCDNumber(3);
		lcd2->setSegmentStyle(QLCDNumber::Filled);
		lcd2->setStyleSheet("* { background-color : red; color : blue; }");

		connect(dial3,SIGNAL(valueChanged(int)),lcd2,SLOT(display(int)));

		QHBoxLayout *bassLayout = new QHBoxLayout;
		bassLayout->addWidget(dial3);
		bassLayout->addWidget(lcd2);
		setLayout(bassLayout);
		}else {

		QSpinBox * spin1 = new QSpinBox();
		spin1->setMaximum(16);
		spin1->setMinimum(1);

		QSlider *slider2 = new QSlider(Qt::Horizontal);
		slider2->setRange(1,16);
		slider2->setValue(1);
		slider2->setStyleSheet("* { background-color : red; color : black; }");
		connect(spin1,SIGNAL(valueChanged(int)),slider2,SLOT(setValue(int)));
		connect(slider2,SIGNAL(valueChanged(int)),spin1,SLOT(setValue(int)));

		QHBoxLayout *trebleLayout = new QHBoxLayout;
		trebleLayout->addWidget(slider2);
		trebleLayout->addWidget(spin1);
		setLayout(trebleLayout);
		}

		
	}
 
}; */


/*void MyWidget::displayWidgets() {

	QSpinBox * spin1 = new QSpinBox();
	spin1->setMaximum(170);
	spin1->setMinimum(53);

	palette->setColor(QPalette::Button,Qt::yellow);
	QDial *dial1 = new QDial();
	dial1->setNotchesVisible(true);
	dial1->setPalette(*palette);
	dial1->setRange(53,170);

	connect(dial1,SIGNAL(valueChanged(int)),spin1,SLOT(setValue(int)));
	connect(spin1,SIGNAL(valueChanged(int)),dial1,SLOT(setValue(int)));

	QHBoxLayout *fmLayout = new QHBoxLayout();
	fmLayout->addWidget(spin1);
	fmLayout->addWidget(dial1);
	fmLayout->show();
}*/


