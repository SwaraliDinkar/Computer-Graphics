#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"

QImage mQImage = QImage(700,700,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vertices = 0;

    ui->mTransformButton->setVisible(false);
    ui->parameter2Label->setVisible(false);
    ui->parameter1Label->setVisible(false);
    ui->parameter2EditText->setVisible(false);
    ui->parameter1EditText->setVisible(false);

    line(0,349,699,349,qRgb(255,255,255));
    line(349,0,349,699,qRgb(255,255,255));
    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
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

void MainWindow::line(double initialX,double initialY,double finalX,double finalY,QRgb mQRgb){
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
    mQImage.setPixel(initialX,initialY,mQRgb);
    mQImage.setPixel(finalX,finalY,mQRgb);
}

void MainWindow::on_mSetPointButton_clicked()
{
    double polygonX = ui->editText_X->toPlainText().toDouble();
    double polygonY = ui->editText_Y->toPlainText().toDouble();
    polygon[vertices][0] = polygonX;
    polygon[vertices][1] = polygonY;
    vertices++;
    ui->inputXLabel->setText("Point " + QString::number(vertices+1) + " X:");
    ui->inputYLabel->setText("Point " + QString::number(vertices+1) + " Y:");
    ui->editText_X->clear();
    ui->editText_Y->clear();
}

void MainWindow::on_mDrawPolygonButton_clicked()
{
    for(int i=0;i<vertices-1;i++)
        line(350+polygon[i][0],350-polygon[i][1],350+polygon[i+1][0],350-polygon[i+1][1],qRgb(0,255,255));

    line(350+polygon[0][0],350-polygon[0][1],350+polygon[vertices-1][0],350-polygon[vertices-1][1],qRgb(0,255,255));
    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::translate(double tx, double ty){
    for(int i=0;i<vertices-1;i++)
        line(350+polygon[i][0]+tx,350-polygon[i][1]-ty,350+polygon[i+1][0]+tx,350-polygon[i+1][1]-ty,qRgb(255,255,0));

    line(350+polygon[0][0]+tx,350-polygon[0][1]-ty,350+polygon[vertices-1][0]+tx,350-polygon[vertices-1][1]-ty,qRgb(255,255,0));
    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mTranslationButton_clicked()
{
    ui->mTransformButton->setVisible(true);
    ui->parameter2Label->setVisible(true);
    ui->parameter1Label->setVisible(true);
    ui->parameter2EditText->setVisible(true);
    ui->parameter1EditText->setVisible(true);

    ui->parameter1Label->setText("Enter Tx");
    ui->parameter1Label->adjustSize();
    ui->parameter2Label->setText("Enter Ty");
    ui->parameter2Label->adjustSize();

    ui->mTransformButton->setText("Translate");
    ui->mTransformButton->adjustSize();
    operation = 1;
}

void MainWindow::on_mTransformButton_clicked()
{
    if(operation==1){
        double tx = ui->parameter1EditText->toPlainText().toDouble();
        double ty = ui->parameter2EditText->toPlainText().toDouble();
        translate(tx,ty);
    }
    else if(operation==2){
        double sx = ui->parameter1EditText->toPlainText().toDouble();
        double sy = ui->parameter2EditText->toPlainText().toDouble();
        scale(sx,sy);
    }
    else{
        double angle = ui->parameter1EditText->toPlainText().toDouble();
        rotate(angle*3.142/180);
    }
}

void MainWindow::scale(double sx, double sy){
    double temp[10][2];
    temp[0][0] = polygon[0][0];
    temp[0][1] = polygon[0][1];
    for(int i=0;i<vertices-1;i++){
        temp[i][0] = sx*polygon[i][0];
        temp[i][1] = sy*polygon[i][1];

        temp[i+1][0] = sx*polygon[i+1][0];
        temp[i+1][1] = sy*polygon[i+1][1];
    }

    temp[vertices-1][0] = sx*polygon[vertices-1][0];
    temp[vertices-1][1] = sy*polygon[vertices-1][1];

    double tx = polygon[0][0] - temp[0][0];
    double ty = polygon[0][1] - temp[0][1];

    for(int i=0;i<vertices-1;i++)
        line(350+temp[i][0]+tx,350-temp[i][1]-ty,350+temp[i+1][0]+tx,350-temp[i+1][1]-ty,qRgb(255,255,0));

    line(350+temp[0][0]+tx,350-temp[0][1]-ty,350+temp[vertices-1][0]+tx,350-temp[vertices-1][1]-ty,qRgb(255,255,0));
    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mScalingButton_clicked()
{
    ui->mTransformButton->setVisible(true);
    ui->parameter2Label->setVisible(true);
    ui->parameter1Label->setVisible(true);
    ui->parameter2EditText->setVisible(true);
    ui->parameter1EditText->setVisible(true);

    ui->parameter1Label->setText("Enter Sx");
    ui->parameter1Label->adjustSize();
    ui->parameter2Label->setText("Enter Sy");
    ui->parameter2Label->adjustSize();

    ui->mTransformButton->setText("Scale");
    ui->mTransformButton->adjustSize();
    operation = 2;
}

void MainWindow::rotate(double angle){
    double temp[10][2];
    double initialX = polygon[0][0];
    double initialY = polygon[0][1];

    for(int i=0;i<vertices-1;i++){
        temp[i][0] = cos(angle)*polygon[i][0]-sin(angle)*polygon[i][1];
        temp[i][1] = (sin(angle)*polygon[i][0])+cos(angle)*polygon[i][1];
        temp[i+1][0] = cos(angle)*polygon[i+1][0]-sin(angle)*polygon[i+1][1];
        temp[i+1][1] = (sin(angle)*polygon[i+1][0])+cos(angle)*polygon[i+1][1];
    }

    temp[0][0] = cos(angle)*polygon[0][0]-sin(angle)*polygon[0][1];
    temp[0][1] = (sin(angle)*polygon[0][0])+cos(angle)*polygon[0][1];
    temp[vertices-1][0] = cos(angle)*polygon[vertices-1][0]-sin(angle)*polygon[vertices-1][1];
    temp[vertices-1][1] = (sin(angle)*polygon[vertices-1][0])+cos(angle)*polygon[vertices-1][1];

    initialX = initialX - temp[0][0];
    initialY = initialY - temp[0][1];


    for(int i=0;i<vertices-1;i++)
        line(350+temp[i][0]+initialX,350-temp[i][1]-initialY,350+temp[i+1][0]+initialX,350-temp[i+1][1]-initialY,qRgb(255,255,0));

    line(350+temp[0][0]+initialX,350-temp[0][1]-initialY,350+temp[vertices-1][0]+initialX,350-temp[vertices-1][1]-initialY,qRgb(255,255,0));
    ui->drawingArea->setPixmap(QPixmap::fromImage(mQImage));
}

void MainWindow::on_mRotationButton_clicked()
{
    ui->mTransformButton->setVisible(true);
    ui->parameter1Label->setVisible(true);
    ui->parameter1EditText->setVisible(true);

    ui->parameter2EditText->setVisible(false);
    ui->parameter2Label->setVisible(false);

    ui->parameter1Label->setText("Enter angle:");
    ui->parameter1Label->adjustSize();

    ui->mTransformButton->setText("Rotate");
    ui->mTransformButton->adjustSize();
    operation = 3;
}
