#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::sign(double number){
    if(number<0)
        return -1;
    else if(number>0)
        return 1;
        return 0;
}

void MainWindow::drawLineDDA(QImage &mQImage,double initialX,double initialY,double finalX,double finalY){
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
        mQImage.setPixel(x,y,qRgb(255,255,255));
        x = x+dx;
        y = y+dy;
        i=i+1;
    }
}

void MainWindow::drawLineBre(QImage &mQImage,double initialX,double initialY,double finalX,double finalY){
    double x = initialX;
    double y = initialY;

    double dx = abs(finalX-initialX);
    double dy = abs(finalY-initialY);

    int S1 = sign(finalX-initialX);
    int S2 = sign(finalY-initialY);
    bool interchange;

    if(dy>dx){
        double temp = dx;
        dx = dy;
        dy = temp;
        interchange = true;
    }
    else
        interchange = false;

    int e = 2*dy-dx;
    for(int i=1;i<dx;i++){
        mQImage.setPixel(x,y,qRgb(255,255,255));
        while(e>0){
            if(interchange)
                x = x + S1;
            else
                y = y +S2;
            e = e -2*dx;
        }
        if(interchange)
            y = y +S2;
        else
            x = x +S1;

        e = e+2*dy;
    }
}

void MainWindow::drawImage(QImage &mQImage, double initialX, double initialY,double side){
    double finalX = initialX + side;
    double finalY = initialY + side;

    //Draw Outer Square
    drawLineDDA(mQImage,initialX,initialY,initialX,finalY);
    drawLineDDA(mQImage,initialX,initialY,finalX,initialY);
    drawLineDDA(mQImage,initialX,finalY,finalX,finalY);
    drawLineDDA(mQImage,finalX,initialY,finalX,finalY);

    double midpointY = (initialX+finalX)/2;
    double midpointX = (initialY+finalY)/2;

    //Draw Diamond
    drawLineBre(mQImage,initialX,midpointY,midpointX,finalY);
    drawLineBre(mQImage,initialX,midpointY,midpointX,initialY);
    drawLineBre(mQImage,finalX,midpointY,midpointX,finalY);
    drawLineBre(mQImage,finalX,midpointY,midpointX,initialY);

    double midpointX2 = (finalX+midpointX)/2;
    double midpointX1 = (initialX+midpointX)/2;
    double midpointY2 = (finalY+midpointX)/2;
    double midpointY1 = (initialY+midpointX)/2;

    //Draw Inner Square
    drawLineDDA(mQImage,midpointX2,midpointY1,midpointX2,midpointY2);
    drawLineDDA(mQImage,midpointX1,midpointY1,midpointX1,midpointY2);
    drawLineDDA(mQImage,midpointX1,midpointY1,midpointX2,midpointY1);
    drawLineDDA(mQImage,midpointX1,midpointY2,midpointX2,midpointY2);
}

void MainWindow::on_pushButton_clicked()
{
   double xi,yi,side;
   xi = ui->editText_X1->toPlainText().toDouble();
   yi = ui->editText_Y1->toPlainText().toDouble();

   side = ui->sideEditText->toPlainText().toDouble();

   QImage mQImage(600,400,QImage::Format_RGB888);
   drawImage(mQImage,xi,yi,side);

   ui->drawingArea->clear();
   ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}
