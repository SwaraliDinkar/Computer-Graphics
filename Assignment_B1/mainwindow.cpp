#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

QImage mQImage(750,750,QImage::Format_RGB888);

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

void MainWindow::on_mDrawThinLine_clicked()
{
    mQImage.fill("#000000");
    double initialX = ui->mInitialXEditText->toPlainText().toDouble();
    double initialY = ui->mInitialYEditText->toPlainText().toDouble();
    double finalX = ui->mFinalXEditText->toPlainText().toDouble();
    double finalY = ui->mFinalYEditText->toPlainText().toDouble();

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
        mQImage.setPixel(initialX,initialY,qRgb(255,255,255));
        while(e>0){
            if(interchange)
                initialX = initialX + S1;
            else
                initialY = initialY +S2;
            e = e -2*dx;
        }
        if(interchange)
            initialY = initialY + S2;
        else
            initialX = initialX + S1;

        e = e+2*dy;
    }
    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mDrawDottedLine_clicked()
{
    mQImage.fill("#000000");
    double initialX = ui->mInitialXEditText->toPlainText().toDouble();
    double initialY = ui->mInitialYEditText->toPlainText().toDouble();
    double finalX = ui->mFinalXEditText->toPlainText().toDouble();
    double finalY = ui->mFinalYEditText->toPlainText().toDouble();

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
        if(i%4==0)
            mQImage.setPixel(initialX,initialY,qRgb(255,255,255));
        while(e>0){
            if(interchange)
                initialX = initialX + S1;
            else
                initialY = initialY +S2;
            e = e -2*dx;
        }
        if(interchange)
            initialY = initialY + S2;
        else
            initialX = initialX + S1;

        e = e+2*dy;
    }

    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mDrawDashedLine_clicked()
{
    mQImage.fill("#000000");
    double initialX = ui->mInitialXEditText->toPlainText().toDouble();
    double initialY = ui->mInitialYEditText->toPlainText().toDouble();
    double finalX = ui->mFinalXEditText->toPlainText().toDouble();
    double finalY = ui->mFinalYEditText->toPlainText().toDouble();

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
        if(i%10<5)
            mQImage.setPixel(initialX,initialY,qRgb(255,255,255));
        while(e>0){
            if(interchange)
                initialX = initialX + S1;
            else
                initialY = initialY +S2;
            e = e -2*dx;
        }
        if(interchange)
            initialY = initialY + S2;
        else
            initialX = initialX + S1;

        e = e+2*dy;
    }

    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mDrawDashedDottedLine_clicked()
{
    mQImage.fill("#000000");
    double initialX = ui->mInitialXEditText->toPlainText().toDouble();
    double initialY = ui->mInitialYEditText->toPlainText().toDouble();
    double finalX = ui->mFinalXEditText->toPlainText().toDouble();
    double finalY = ui->mFinalYEditText->toPlainText().toDouble();

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
        if(i%10<4 || i%10==7)
            mQImage.setPixel(initialX,initialY,qRgb(255,255,255));
        while(e>0){
            if(interchange)
                initialX = initialX + S1;
            else
                initialY = initialY +S2;
            e = e -2*dx;
        }
        if(interchange)
            initialY = initialY + S2;
        else
            initialX = initialX + S1;

        e = e+2*dy;
    }

    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mDrawThickLine_clicked()
{
    mQImage.fill("#000000");
    double initialX = ui->mInitialXEditText->toPlainText().toDouble();
    double initialY = ui->mInitialYEditText->toPlainText().toDouble();
    double finalX = ui->mFinalXEditText->toPlainText().toDouble();
    double finalY = ui->mFinalYEditText->toPlainText().toDouble();
    double width = ui->mWidthEditText->toPlainText().toDouble();

    double thickness = (width-1)*(sqrt(pow(finalX-initialX,2)+pow(finalY-initialY,2))/abs(finalX-initialX))/2;

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
            for(int j=thickness;j>-thickness;j--)
                mQImage.setPixel(initialX,initialY-j,qRgb(255,255,255));
        while(e>0){
            if(interchange)
                initialX = initialX + S1;
            else
                initialY = initialY +S2;
            e = e -2*dx;
        }
        if(interchange)
            initialY = initialY + S2;
        else
            initialX = initialX + S1;

        e = e+2*dy;
    }

    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}
