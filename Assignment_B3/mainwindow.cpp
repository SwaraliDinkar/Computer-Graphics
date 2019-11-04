#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "line.h"

line l;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tempX1=tempX2=tempY1=tempY2=0;
    x1=y1=x2=y2=0;
    first=true;
    initset=false;
    ui->drawingArea->setMouseTracking(true);
    connect(this, SIGNAL(clicked()),this, SLOT(clickev()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(tempX1==tempX2 && tempX1==tempY1 && tempY1==tempY2){

    }
    else{
        if(first==true)
        {
            x1=ev->pos().x();
            y1=ev->pos().y();
            first=false;
            emit(clicked());
            return;
        }
        if(first==false)
        {
            x2=ev->pos().x();
            y2=ev->pos().y();
            initset=true;
            first=true;
        }
        emit(clicked());
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{

}


void MainWindow::clickev()
{
    bool start[4],end[4];
    QImage image(768,768,QImage::Format_RGB888);
    image = l.draw_line(tempX1,tempY1,tempX1,tempY2);
    image = l.draw_line(tempX1,tempY1,tempX2,tempY1);
    image = l.draw_line(tempX2,tempY2,tempX1,tempY2);
    image = l.draw_line(tempX2,tempY2,tempX2,tempY1);
    ui->drawingArea->setPixmap(QPixmap::fromImage(image));
    if(!initset)
        return;
    QRgb border = image.pixel(x2,y2);
    if(border != qRgb(0,255,255))
    {
        start[0] = x1<tempX1;
        start[1] = x1>tempX2;
        start[2] = y1<tempY1;
        start[3] = y1>tempY2;

        end[0] = x2<tempX1;
        end[1] = x2>tempX2;
        end[2] = y2<tempY1;
        end[3] = y2>tempY2;

        if((start[0] && end[0]) || (start[1] && end[1]) || (start[2] && end[2]) || (start[3] && end[3])){
            image = l.draw_line(0,0,1,1);
            ui->drawingArea->setPixmap(QPixmap::fromImage(image));
        }
        else{
            image = l.draw_line(x1,y1,x2,y2);
            ui->drawingArea->setPixmap(QPixmap::fromImage(image));
        }
        return;
    }
}

void MainWindow::on_setWindow_clicked()
{
    tempX1 = ui->mTopLeftXEditText->toPlainText().toInt();
    tempY1 = ui->mTopLeftYEditText->toPlainText().toInt();
    tempX2 = ui->mBottomRightXEditText->toPlainText().toInt();
    tempY2 = ui->mBottomRightYEditText->toPlainText().toInt();
    l.setPoints(tempX1,tempY1,tempX2,tempY2);
}
