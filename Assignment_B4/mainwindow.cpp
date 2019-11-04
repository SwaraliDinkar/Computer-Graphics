#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

QImage mQImage(1050,768,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    index=0;
    for(int i=0;i<10;i++)
        polygon[i][0] = polygon[i][1] = 0;
    ui->setupUi(this);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);

    ui->arbitaryX->setVisible(false);
    ui->arbitaryY->setVisible(false);
    ui->angleEditText->setVisible(false);
    ui->mRotateButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::sign(int number){
    if(number<0)
        return -1;
    else if(number>0)
        return 1;
        return 0;
}

void MainWindow::line(QImage &mQImage,int initialX,int initialY,int finalX,int finalY,QRgb mQRgb=qRgb(255,255,255))
{
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
            e = e - 2*dx;
        }
        if(interchange)
            y = y +S2;
        else
            x = x +S1;

        e = e+2*dy;
    }
}

void MainWindow::drawAxis(QImage &mQImage){
    line(mQImage,525,0,525,768);
    line(mQImage,0,384,1050,384);
}

void MainWindow::on_mSetPointButton_clicked()
{
    double pointX = ui->cordinateX->toPlainText().toDouble();
    double pointY = ui->cordinateY->toPlainText().toDouble();

    polygon[index][0] = pointX;
    polygon[index][1] = pointY;
    index++;
}

void MainWindow::on_mDrawButton_clicked()
{

    drawAxis(mQImage);

    for(int i=0;i<index-1;i++){
        line(mQImage,polygon[i][0]+525,384-polygon[i][1],525+polygon[i+1][0],384-polygon[i+1][1],qRgb(0,255,0));
    }
    line(mQImage,525+polygon[0][0],384-polygon[0][1],525+polygon[index-1][0],384-polygon[index-1][1],qRgb(0,255,0));

    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mRotateFunctionButton_clicked()
{
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);
    ui->label_6->setVisible(true);

    ui->arbitaryX->setVisible(true);
    ui->arbitaryY->setVisible(true);
    ui->angleEditText->setVisible(true);
    ui->mRotateButton->setVisible(true);
}

void MainWindow::on_mXRelfectButton_clicked()
{
    int temp[index][2];

    for(int i=0;i<index;i++){
        temp[i][0] = polygon[i][0];
        temp[i][1] = -1*(polygon[i][1]);
    }

    drawAxis(mQImage);

    for(int i=0;i<index-1;i++){
        line(mQImage,temp[i][0]+525,384-temp[i][1],525+temp[i+1][0],384-temp[i+1][1],qRgb(255,0,0));
    }
    line(mQImage,525+temp[0][0],384-temp[0][1],525+temp[index-1][0],384-temp[index-1][1],qRgb(255,0,0));

    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mYReflectButton_clicked()
{
    int temp[index][2];

    for(int i=0;i<index;i++){
        temp[i][0] = -1*polygon[i][0];
        temp[i][1] = polygon[i][1];
    }

    drawAxis(mQImage);

    for(int i=0;i<index-1;i++){
        line(mQImage,temp[i][0]+525,384-temp[i][1],525+temp[i+1][0],384-temp[i+1][1],qRgb(255,0,0));
    }
    line(mQImage,525+temp[0][0],384-temp[0][1],525+temp[index-1][0],384-temp[index-1][1],qRgb(255,0,0));

    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mXYReflectButton_clicked()
{
    drawAxis(mQImage);

    for(int i=0;i<index-1;i++){
        line(mQImage,polygon[i][1]+525,384-polygon[i][0],525+polygon[i+1][1],384-polygon[i+1][0],qRgb(255,0,0));
    }
    line(mQImage,525+polygon[0][1],384-polygon[0][0],525+polygon[index-1][1],384-polygon[index-1][0],qRgb(255,0,0));

    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mRotateButton_clicked()
{
    int pointX = ui->arbitaryX->toPlainText().toInt();
    int pointY = ui->arbitaryY->toPlainText().toInt();
    double angle = ui->angleEditText->toPlainText().toDouble();
    angle = (angle*3.142f)/180;

    int x1,x2,y1,y2;

    for(int i=0;i<index-1;i++){
        x1 = (cos(angle)*polygon[i][0])-(sin(angle)*polygon[i][1])+pointX;
        y1 = (sin(angle)*polygon[i][0])+(cos(angle)*polygon[i][1])+pointY;
        x2 = (cos(angle)*polygon[i+1][0])-(sin(angle)*polygon[i+1][1])+pointX;
        y2 = (sin(angle)*polygon[i+1][0])+(cos(angle)*polygon[i+1][1])+pointY;

         line(mQImage,x1+525,384-y1,525+x2,384-y2,qRgb(255,0,0));
    }

    drawAxis(mQImage);

    x1 = (cos(angle)*polygon[0][0])-(sin(angle)*polygon[0][1])+pointX;
    y1 = (sin(angle)*polygon[0][0])+(cos(angle)*polygon[0][1])+pointY;
    x2 = (cos(angle)*polygon[index-1][0])-(sin(angle)*polygon[index-1][1])+pointX;
    y2 = (sin(angle)*polygon[index-1][0])+(cos(angle)*polygon[index-1][1])+pointY;

    line(mQImage,x1+525,384-y1,525+x2,384-y2,qRgb(255,0,0));

    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}
