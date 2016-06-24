#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Scan.h"
#include "Calculation.h"
#include <QtCore/QCoreApplication>
#include <fstream>

QString value = "";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    title = new QLabel("Calculator",this);
    title -> setGeometry(QRect(QPoint(100,25),QSize(200,50)));

    label = new QLabel("0",this);
    label -> setGeometry(QRect(QPoint(50,50),QSize(200,50)));

    QString inStr = "Input Path";
    inputPath = new QLineEdit(inStr,this);
    inputPath -> setGeometry(QRect(QPoint(25,375),QSize(250,50)));
    inputPath -> hide();

    QString outStr = "Output Path";
    outputPath = new QLineEdit(outStr,this);
    outputPath -> setGeometry(QRect(QPoint(25,450),QSize(250,50)));
    outputPath -> hide();

    submitButton = new QPushButton("Submit",this);
    connect(submitButton,SIGNAL(released()),this,SLOT(submitPath()));
    submitButton -> setGeometry(QRect(QPoint(100,525),QSize(100,50)));
    submitButton -> hide();

    filePath = new QPushButton("Open",this);
    connect(filePath,SIGNAL(released()),this,SLOT(fileOpeAppear()));

    hideFilePath = new QPushButton("Close",this);
    connect(hideFilePath,SIGNAL(released()),this,SLOT(fileOpeDisappear()));

    backspace = new QPushButton("backspace",this);
    connect(backspace,SIGNAL(released()),this,SLOT(BackSpace()));

    operationButton[0] = new QPushButton("=",this);
    connect(operationButton[0],SIGNAL(released()),this,SLOT(equals()));
    operationButton[1] = new QPushButton("Esc",this);
    connect(operationButton[1],SIGNAL(released()),this,SLOT(clear()));

    for (int i = 2; i<10; i++) {
        QString operations[] = {"=","ESC","+","-","×","÷","(",")",".","^"};
        operationButton[i] = new QPushButton(operations[i],this);
        connect(operationButton[i],SIGNAL(released()),this,SLOT(operationPushed()));
    }

    for (int i = 0; i<10; i++) {
        QString digit = QString::number(i);
        buttons[i] = new QPushButton(digit,this);
        connect(buttons[i],SIGNAL(released()),this,SLOT(buttonPushed()));
    }
    setGeo();
}


void MainWindow::setGeo() {
    backspace -> setGeometry(QRect(QPoint(25,300),QSize(100,50)));
    filePath -> setGeometry(QRect(QPoint(130,300),QSize(70,50)));
    hideFilePath -> setGeometry(QRect(QPoint(205,300),QSize(70,50)));
    operationButton[0] -> setGeometry(QRect(QPoint(25,250),QSize(50,50)));
    operationButton[1] -> setGeometry(QRect(QPoint(125,250),QSize(50,50)));
    for (int i=2; i<6; i++) {
        operationButton[i] -> setGeometry(QRect(QPoint(175,50*i),QSize(50,50)));
    }
    for (int i=6; i<10; i++) {
        operationButton[i] -> setGeometry(QRect(QPoint(225,-200+50*i),QSize(50,50)));
    }
    buttons[0] -> setGeometry(QRect(QPoint(75,250),QSize(50,50)));
    for (int j=1; j<4; j++) {
        for (int i=1; i<4; i++) {
            buttons[i+3*j-3]->setGeometry(QRect(QPoint(50*i-25,50+50*j),QSize(50,50)));
        }
    }
}


void MainWindow::buttonPushed() {
    QPushButton *button = (QPushButton *)sender();
    emit numberEmitted(button->text()[0].digitValue());
    addNumber(QString::number(button->text()[0].digitValue()));
}



void MainWindow::operationPushed() {
    QPushButton *button = (QPushButton *)sender();
    QString op = button->text();
    if (op=="×") op="*";
    if (op=="÷") op="/";
    addOpe(op);
}


void MainWindow::addNumber(QString num) {
    value += num;
    label -> setText(value);
}


void MainWindow::addOpe(QString ope) {
    value += ope;
    label -> setText(value);
}


void MainWindow::keyPressEvent(QKeyEvent *e) {
    if(e->key()==Qt::Key_1) addNumber("1");
    else if(e->key()==Qt::Key_2) addNumber("2");
    else if(e->key()==Qt::Key_3) addNumber("3");
    else if(e->key()==Qt::Key_4) addNumber("4");
    else if(e->key()==Qt::Key_5) addNumber("5");
    else if(e->key()==Qt::Key_6) addNumber("6");
    else if(e->key()==Qt::Key_7) addNumber("7");
    else if(e->key()==Qt::Key_8) addNumber("8");
    else if(e->key()==Qt::Key_9) addNumber("9");
    else if(e->key()==Qt::Key_0) addNumber("0");
    else if(e->key()==Qt::Key_Plus) addOpe("+");
    else if(e->key()==Qt::Key_Minus) addOpe("-");
    else if(e->key()==Qt::Key_Asterisk) addOpe("*");
    else if(e->key()==Qt::Key_Slash) addOpe("/");
    else if(e->key()==Qt::Key_ParenLeft) addOpe("(");
    else if(e->key()==Qt::Key_ParenRight) addOpe(")");
    else if(e->key()==Qt::Key_AsciiCircum) addOpe("^");
    else if(e->key()==Qt::Key_Period) addOpe(".");
    else if(e->key()==Qt::Key_Escape) clear();
    else if(e->key()==Qt::Key_Equal) {
        value += '=';
        getResult();
    }
    else if(e->key()==Qt::Key_Backspace) BackSpace();
}


void MainWindow::clear() {
    value="";
    label -> setText("0");
}


void MainWindow::BackSpace() {
    if(value.length()!=0) {
        value=value.mid(0,value.length()-1);
    }
    else {
        value = "";
    }
    if (value=="") {
        label -> setText("0");
    }else {
        label-> setText(value);
    }
}


void MainWindow::submitPath() {

    QString Path1 = inputPath -> text();
    QString Path2 = outputPath -> text();
    string Path3 = Path1.toStdString();
    string Path4 = Path2.toStdString();
    const char *inPath = Path3.c_str();
    const char *outPath = Path4.c_str();
    fileOperation(inPath,outPath);

}


void MainWindow::fileOpeAppear() {
    inputPath -> show();
    outputPath -> show();
    submitButton -> show();
    label ->setText("Path Open");
}


void MainWindow::fileOpeDisappear() {
    inputPath -> hide();
    outputPath -> hide();
    submitButton -> hide();
    label ->setText("Path Close");
}


void MainWindow::fileOperation(const char *i,const char *o) {
    string input="";
    ofstream out(o, ios::out);
    ifstream in(i, ios::in);
    if (in.is_open()) {
        while (getline(in,input)) {
            Scan m_scan;
            Calculation m_cal;
            m_scan.ToStringQueue(input, 2);
            if (out.is_open()) {
                if (m_scan.tooBig==true) {
                    out << "ERROR:Number Not Conform To The Requirement." << endl;
                }
                else {
                    m_cal.calculating(m_scan.ToStringQueue(input,2));
                    if (m_cal.idbz==1) {
                        out << "ERROR:Divided By Zero." << endl;
                    }else if (m_cal.idbz==0){
                        out << m_cal.calculating(m_scan.ToStringQueue(input,2)) << endl;
                    }
                }

            }
        }
        in.close();
        out.close();
        value = "Successfully!";
        label -> setText(value);
    }else {
        value = "Path wrong.";
        label -> setText(value);
    }
}


void MainWindow::equals() {
    QPushButton *button = (QPushButton *)sender();
    value += button->text();
    getResult();
}


void MainWindow::getResult() {
    string input = value.toStdString();
    Scan m_scan;
    Calculation m_cal;
    m_scan.ToStringQueue(input, 2);

    if (m_scan.tooBig==true) {
        value =  "ERROR:Number Not Conform To The Requirement.";
    }
    else {
        m_cal.calculating(m_scan.ToStringQueue(input,2));
        if (m_cal.idbz==1) {
            value = "ERROR:Divided By Zero.";
        }else if (m_cal.idbz==0){
            double answer = m_cal.calculating(m_scan.ToStringQueue(input,2));
            value += QString::number(answer);
        }
    }

    label -> setText(value);
    value = "";
}


MainWindow::~MainWindow()
{
}
