#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QKeyEvent>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void numberEmitted(int number);

private slots:
    void clear();
    void equals();
    void buttonPushed();
    void operationPushed();
    void setGeo();
    void submitPath();
    void fileOperation(const char *i,const char *o);
    void keyPressEvent(QKeyEvent *e);
    void addNumber(QString num);
    void addOpe(QString ope);
    void getResult();
    void fileOpeAppear();
    void fileOpeDisappear();
    void BackSpace();

private:
    QLabel *title;
    QLabel *label;
    QPushButton *submitButton;
    QPushButton *operationButton[10];
    QPushButton *buttons[10];
    QLineEdit *inputPath;
    QLineEdit *outputPath;
    QPushButton *filePath;
    QPushButton *hideFilePath;
    QPushButton *backspace;

};

#endif // MAINWINDOW_H
