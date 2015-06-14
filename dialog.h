#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTabWidget>
#include <QLabel>
#include <QSpinBox>
#include <QBoxLayout>
#include <QGridLayout>
#include <QComboBox>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QPushButton>
#include <QApplication>
#include <QDebug>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void sendaction();
    void openaction();
    void readaction();
private:
    void line0();
    void tri0();
    void rect0();
    void circle0();
    void ellipse0();
    void workwithdata();
    void color0();
   //  void polygon0();
    QTabWidget *tab;
    QWidget *line;
    QLabel *linex0;QSpinBox *lineex0;
    QLabel *liney0;QSpinBox *lineey0;
    QLabel *linex1;QSpinBox *lineex1;
    QLabel *liney1;QSpinBox *lineey1;
    QWidget *tri;
    QLabel *tria;QSpinBox *editax;QSpinBox *editay;
    QLabel *trib;QSpinBox *editbx;QSpinBox *editby;
    QLabel *tric;QSpinBox *editcx;QSpinBox *editcy;
    QWidget *rect;
    QLabel *rectx0;QSpinBox *rectex0;
    QLabel *recty0;QSpinBox *rectey0;
    QLabel *rectx1;QSpinBox *rectex1;
    QLabel *recty1;QSpinBox *rectey1;
    QWidget *circle;
    QLabel *circlex;QSpinBox *circleex;
    QLabel *circley;QSpinBox *circleey;
    QLabel *circler;QSpinBox *circleer;
    QWidget *ellipse;
    QLabel *ellipsex;QSpinBox *ellipseex;
    QLabel *ellipsey;QSpinBox *ellipseey;
    QLabel *ellipsea;QSpinBox *ellipseea;
    QLabel *ellipseb;QSpinBox *ellipseeb;
    //QWidget *polygon;
    QComboBox *comnum;
    QPushButton *quitbt,*sendbt,*openbt;
    QByteArray data,Rdata;
    QSerialPort *myport;
    QLabel *tclab,*bylab;
    QComboBox *tccolor,*bycolor;
    bool ok;
};

#endif // DIALOG_H
