#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

QRgb mQRgb = qRgb(255,255,255);

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

void MainWindow::drawCircleBre(QImage &mQImage, int centerX, int centerY, int radius){
    int x = 0;
    int y = radius;
    int h = 1 - radius;
    int De = 3;
    int Dse = 5 - 2*radius;
    plotPoints(mQImage,centerX,centerY,x,y);

    while(y>x){
        if(h<0){
            h = h+De;
            De = De+2;
            Dse = Dse+2;
        }
        else{
            h = h+Dse;
            De = De+2;
            Dse = Dse+4;
            y--;
        }
        x++;
        plotPoints(mQImage,centerX,centerY,x,y);
    }
}

void MainWindow::drawCircleDDA(QImage &mQImage,int centerX,int centerY,int radius){
    float inverseMax;
    float pointX,pointY;
    int value,power;

    pointX = radius;
    pointY = 0;
    power=0;

    do{
        value=pow(2,power);
        power++;
    }while(value<radius);

    inverseMax = 1/pow(2,power-1);

    do{
        pointX = pointX + pointY*inverseMax;
        pointY = pointY - pointX*inverseMax;
        plotPoints(mQImage,centerX,centerY,pointX,pointY);
    }while(pointY<inverseMax || (radius-pointY)>inverseMax);
}

void MainWindow::plotPoints(QImage &mQImage,int centerX,int centerY, int x, int y){
    mQImage.setPixel(centerX+x,centerY+y,mQRgb);
    mQImage.setPixel(centerX+y,centerY+x,mQRgb);
    mQImage.setPixel(centerX+x,centerY-y,mQRgb);
    mQImage.setPixel(centerX-y,centerY+x,mQRgb);
    mQImage.setPixel(centerX-x,centerY+y,mQRgb);
    mQImage.setPixel(centerX+y,centerY-x,mQRgb);
    mQImage.setPixel(centerX-x,centerY-y,mQRgb);
    mQImage.setPixel(centerX-y,centerY-x,mQRgb);
}

int MainWindow::sign(int number){
    if(number<0)
        return -1;
    else if(number>0)
        return 1;
        return 0;
}

void MainWindow::line(QImage &mQImage,double initialX,double initialY,double finalX,double finalY){
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
        mQImage.setPixel(x,y,mQRgb);
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

void MainWindow::drawTriangle(QImage &mQImage, int centerX, int centerY, double radius){
    int initialX = centerX;
    int initialY = centerY-radius;
    int finalX = centerX + radius*(sqrt(3.0))/2;
    int finalY = centerY+radius/2;

    line(mQImage,initialX,initialY,finalX,finalY);

    finalX = centerX - radius*(sqrt(3.0))/2;
    finalY = centerY+radius/2;

    line(mQImage,initialX,initialY,finalX,finalY);

    initialX = centerX + radius*(sqrt(3.0))/2;
    initialY = centerY+radius/2;
    line(mQImage,initialX,initialY,finalX,finalY);
}

void MainWindow::on_mDrawDiagramButton_clicked()
{
    double centerX,centerY,radius;
    QImage mQImage(500,500,QImage::Format_RGB888);

    centerX = ui->editText_X->toPlainText().toDouble();
    centerY = ui->editText_Y->toPlainText().toDouble();
    radius = ui->editText_Radius->toPlainText().toDouble();

    drawCircleDDA(mQImage,centerX,centerY,radius);
    drawTriangle(mQImage,centerX,centerY,radius);
    drawCircleBre(mQImage,centerX,centerY,radius/2);
    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}
