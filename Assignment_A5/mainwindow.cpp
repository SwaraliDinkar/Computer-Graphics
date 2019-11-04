#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage mQImage = QImage(600,600,QImage::Format_RGB888);
QRgb mQRgb = qRgb(255,255,255);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->drawingArea->setMouseTracking(true);
    connect(this,SIGNAL(clicked()),this,SLOT(clickEvent()));
    first = true;
    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    if(ev->pos().x()<0 || ev->pos().x()>600 || ev->pos().y()<0 || ev->pos().y()>600)
        return;

    if(first){
        initialX = ev->pos().x();
        initialY = ev->pos().y();
        first = false;
    }
    else{
        finalX = ev->pos().x();
        finalY = ev->pos().y();
        first = true;
        emit(clicked());
    }
}

int MainWindow::sign(int number){
    if(number<0)
        return -1;
    else if(number>0)
        return 1;
        return 0;
}

void MainWindow::line(QImage &mQImage,double initialX,double initialY,double finalX,double finalY){
    double length;
    double dx,dy;
    if(abs(finalX-initialX)>= abs(finalY-initialY))
        length = abs(finalX-initialX);
    else
        length = abs(finalY-initialY);

    dx = (finalX-initialX)/length;
    dy = (finalY-initialY)/length;

    double x = initialX+0.5*sign(dx);
    double y = initialY+0.5*sign(dy);
    int i=0;
    while(i<=length){
        mQImage.setPixel(x,y,mQRgb);
        x = x+dx;
        y = y+dy;
        i=i+1;
    }
}

void MainWindow::clickEvent(){
    line(mQImage,initialX,initialY,finalX,finalY);
    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_redButton_clicked()
{
    mQRgb = qRgb(255,0,0);
}

void MainWindow::on_blueButton_clicked()
{
    mQRgb = qRgb(0,0,255);
}

void MainWindow::on_greenButton_clicked()
{
    mQRgb = qRgb(0,255,0);
}

void MainWindow::on_whiteButton_clicked()
{
    mQRgb = qRgb(255,255,255);
}
