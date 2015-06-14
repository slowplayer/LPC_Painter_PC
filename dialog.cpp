#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    tab=new QTabWidget();
    line0();
    tri0();
    rect0();
    circle0();
    ellipse0();
 //   polygon0();
    color0();
    tab->addTab(line,tr("直线"));
    tab->addTab(tri,tr("三角形"));
    tab->addTab(rect,tr("矩形"));
    tab->addTab(circle,tr("圆形"));
    tab->addTab(ellipse,tr("椭圆"));
 //   tab->addTab(polygon,tr("多边形"));
 //   QHBoxLayout *layout=new QHBoxLayout();
 //   layout->addWidget(tab);
//    setLayout(layout);
    quitbt=new QPushButton(tr("退出"));
    sendbt=new QPushButton(tr("发送"));
    openbt=new QPushButton(tr("打开串口"));
    sendbt->setEnabled(false);
    openbt->setEnabled(false);
    comnum=new QComboBox();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
            QSerialPort serial;
            serial.setPort(info);
            if(serial.open(QIODevice::ReadWrite))
            {
                comnum->addItem(info.portName());
                serial.close();
            }
            openbt->setEnabled(true);
    }
    connect(quitbt,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(sendbt,SIGNAL(clicked()),this,SLOT(sendaction()));
    connect(openbt,SIGNAL(clicked()),this,SLOT(openaction()));
    tclab=new QLabel("背景颜色");
    bylab=new QLabel("背景颜色");
    QHBoxLayout *tclay=new QHBoxLayout();
    tclay->addWidget(tclab);
    tclay->addWidget(tccolor);
 //   QHBoxLayout *bylay=new QHBoxLayout();
 //   bylay->addWidget(bylab);
 //   bylay->addWidget(bycolor);
    QGridLayout *vlay=new QGridLayout();
    vlay->addWidget(comnum,0,0);
    vlay->addWidget(openbt,1,0);
    vlay->addWidget(sendbt,2,0);

    vlay->addWidget(bylab,0,1);
    vlay->addWidget(bycolor,1,1);
    vlay->addWidget(quitbt,2,1);
    QHBoxLayout *hlay=new QHBoxLayout();
    hlay->addWidget(tab);
    hlay->addLayout(vlay);
    setLayout(hlay);
    setWindowTitle(tr("绘图工具"));

}
Dialog::~Dialog()
{

}
void Dialog::color0()
{
    tccolor=new QComboBox();
    tccolor->addItem("Black");
    tccolor->addItem("White");
    tccolor->addItem("Red");
    tccolor->addItem("Blue");
    tccolor->addItem("Green");
    tccolor->addItem("Yellow");
    bycolor=new QComboBox();
    bycolor->addItem("Black");
    bycolor->addItem("White");
    bycolor->addItem("Red");
    bycolor->addItem("Blue");
    bycolor->addItem("Green");
    bycolor->addItem("Yellow");
}

void Dialog::line0()
{
    line=new QWidget();
    linex0=new QLabel(tr("起点坐标x0:"));
    lineex0=new QSpinBox();lineex0->setRange(0,240);lineex0->setValue(0);
    liney0=new QLabel(tr("y0:"));
    lineey0=new QSpinBox();lineey0->setRange(0,240);lineey0->setValue(0);
    linex1=new QLabel(tr("终点坐标x1:"));
    lineex1=new QSpinBox;lineex1->setRange(0,240);lineex1->setValue(0);
    liney1=new QLabel(tr("y1:"));
    lineey1=new QSpinBox();lineey1->setRange(0,240);lineey1->setValue(0);
    QGridLayout *linelay=new QGridLayout();
    linelay->addWidget(linex0,0,0);
    linelay->addWidget(lineex0,0,1);
    linelay->addWidget(liney0,0,2);
    linelay->addWidget(lineey0,0,3);
    linelay->addWidget(linex1,1,0);
    linelay->addWidget(lineex1,1,1);
    linelay->addWidget(liney1,1,2);
    linelay->addWidget(lineey1,1,3);
    line->setLayout(linelay);
}
void Dialog::tri0()
{
    tri=new QWidget();
    tria=new  QLabel(tr("第一个顶点a:"));
    editax=new QSpinBox();editax->setRange(0,240);editax->setValue(0);
    editay=new QSpinBox();editay->setRange(0,240);editay->setValue(0);
    trib=new  QLabel(tr("第二个顶点b:"));
    editbx=new QSpinBox();editbx->setRange(0,240);editbx->setValue(0);
    editby=new QSpinBox();editby->setRange(0,240);editby->setValue(0);
    tric=new  QLabel(tr("第三个顶点c:"));
    editcx=new QSpinBox();editcx->setRange(0,240);editcx->setValue(0);
    editcy=new QSpinBox();editcy->setRange(0,240);editcy->setValue(0);
    QGridLayout *trilayout=new QGridLayout();
    trilayout->addWidget(tria,0,0);
    trilayout->addWidget(editax,0,1);
     trilayout->addWidget(editay,0,2);
    trilayout->addWidget(trib,1,0);
    trilayout->addWidget(editbx,1,1);
    trilayout->addWidget(editby,1,2);
    trilayout->addWidget(tric,2,0);
    trilayout->addWidget(editcx,2,1);
     trilayout->addWidget(editcy,2,2);
    tri->setLayout(trilayout);

}
void Dialog::rect0()
{
    rect=new QWidget();
    rectx0=new QLabel(tr("左上角坐标x0:"));
    rectex0=new QSpinBox();rectex0->setRange(0,240);rectex0->setValue(0);
    recty0=new QLabel(tr("y0:"));
    rectey0=new QSpinBox();rectey0->setRange(0,240);rectey0->setValue(0);
    rectx1=new QLabel(tr("右下角坐标x1:"));
    rectex1=new QSpinBox();rectex1->setRange(0,240);rectex1->setValue(0);
    recty1=new QLabel(tr("y1:"));
    rectey1=new QSpinBox();rectey1->setRange(0,240);rectey1->setValue(0);

    QGridLayout *rectlay=new QGridLayout();
    rectlay->addWidget(rectx0,0,0);
    rectlay->addWidget(rectex0,0,1);
    rectlay->addWidget(recty0,0,2);
    rectlay->addWidget(rectey0,0,3);
    rectlay->addWidget(rectx1,1,0);
    rectlay->addWidget(rectex1,1,1);
    rectlay->addWidget(recty1,1,2);
    rectlay->addWidget(rectey1,1,3);
    rect->setLayout(rectlay);
}
void Dialog::circle0()
{
    circle=new QWidget();
    circlex=new QLabel(tr("圆心坐标x:"));
    circleex=new QSpinBox();circleex->setRange(0,240);circleex->setValue(0);
    circley=new QLabel(tr("y:"));
    circleey=new QSpinBox();circleey->setRange(0,240);circleey->setValue(0);
    circler=new QLabel(tr("半径r:"));
    circleer=new QSpinBox();circleer->setRange(0,255);circleer->setValue(0);
    QGridLayout *cirlay=new QGridLayout();
    cirlay->addWidget(circlex,0,0);
    cirlay->addWidget(circleex,0,1);
    cirlay->addWidget(circley,0,2);
    cirlay->addWidget(circleey,0,3);
    cirlay->addWidget(circler,1,0);
    cirlay->addWidget(circleer,1,1);
    circle->setLayout(cirlay);

}
void Dialog::ellipse0()
{
    ellipse=new QWidget();
    QLabel *ellipsex=new QLabel(tr("中心坐标x:"));
    ellipseex=new QSpinBox();ellipseex->setRange(0,240);ellipseex->setValue(0);
    QLabel *ellipsey=new QLabel(tr("y:"));
     ellipseey=new QSpinBox();ellipseey->setRange(0,240);ellipseey->setValue(0);
    QLabel *ellipsea=new QLabel(tr("长轴a:"));
     ellipseea=new QSpinBox();ellipseea->setRange(0,255);ellipseea->setValue(0);
    QLabel *ellipseb=new QLabel(tr("短轴b:"));
     ellipseeb=new QSpinBox();ellipseeb->setRange(0,255);ellipseeb->setValue(0);
    QGridLayout *ellipselay=new QGridLayout();
    ellipselay->addWidget(ellipsex,0,0);
    ellipselay->addWidget(ellipseex,0,1);
    ellipselay->addWidget(ellipsey,0,2);
    ellipselay->addWidget(ellipseey,0,3);
    ellipselay->addWidget(ellipsea,1,0);
    ellipselay->addWidget(ellipseea,1,1);
    ellipselay->addWidget(ellipseb,1,2);
    ellipselay->addWidget(ellipseeb,1,3);
    ellipse->setLayout(ellipselay);
}
//void Dialog::polygon0()


void Dialog::openaction()
{
    myport=new QSerialPort();
    myport->setPortName(comnum->currentText());
    myport->open(QIODevice::ReadWrite);
    myport->setBaudRate(115200);
    myport->setDataBits(QSerialPort::Data8);
    myport->setParity(QSerialPort::NoParity);
    myport->setStopBits(QSerialPort::OneStop);
    myport->setFlowControl(QSerialPort::NoFlowControl);
    comnum->setEnabled(false);
    sendbt->setEnabled(true);
    connect(myport,SIGNAL(readyRead()),this,SLOT(readaction()));
    qDebug()<<"Open Serial";
    openbt->setEnabled(false);
}
void Dialog::readaction()
{
    qDebug()<<"Read Data";
    ok=true;
}

void Dialog::workwithdata()
{
    switch(tab->currentIndex())
    {
        case 0:
            data[6]=0x01;
            data[0]=lineex0->value();
            data[1]=lineey0->value();
            data[2]=lineex1->value();
            data[3]=lineey1->value();
            data[4]=0;data[5]=0;
            break;
        case 1:
            data[6]=0x02;
            data[0]=editax->value();data[1]=editay->value();
            data[2]=editbx->value();data[3]=editby->value();
            data[4]=editcx->value();data[5]=editcy->value();
            break;
        case 2:
            data[6]=0x03;
            data[0]=rectex0->value();
            data[1]=rectey0->value();
            data[2]=rectex1->value();
            data[3]=rectey1->value();
            data[4]=0;data[5]=0;
            break;
        case 3:
            data[6]=0x04;
            data[0]=circleex->value();
            data[1]=circleey->value();
            data[2]=circleer->value();
            data[3]=0;data[4]=0;data[5]=0;
            break;
       case 4:
            data[6]=0x05;
            data[0]=ellipseex->value();
            data[1]=ellipseey->value();
            data[2]=ellipseea->value();
            data[3]=ellipseeb->value();
            data[4]=0;data[5]=0;
            break;
    }
    data[7]=bycolor->currentIndex();
  //  data[8]=tccolor->currentIndex();
 //   data[9]=data[10]=data[11]=data[12]=data[13]=data[14]=data[15]=0;

}
void Dialog::sendaction()
{
    data="";
    ok=false;
    workwithdata();
    QByteArray hh=data.toHex();
    QString str(hh);
    qDebug()<<str;
    qDebug()<<"Send Data"<<data.size();
 //   myport->write(Rdata);
 //   while(!ok);
  //  qDebug()<<"Send Data again";
    myport->write(data);
}
