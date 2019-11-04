#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage image(500,500,QImage::Format_RGB32);
QRgb fillcolor = qRgb(255,0,0);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->mFillPolygonButton->setVisible(false);
    ui->mRedEditText->setVisible(false);
    ui->mBlueEditText->setVisible(false);
    ui->mGreenEditText->setVisible(false);

    complete = false;

    x1=y1=x2=y2=0;
    vertexCount=0;
    first=true;
    setinit=false;

    ui->drawingarea->setMouseTracking(true);
    connect(this,SIGNAL(clicked()),this,SLOT(clickEvent()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::line(int x1,int y1,int x2,int y2)
{
    int dx=(x2-x1);
        int dy=(y2-y1);
        int length;
        float x,y;
        if(abs(dx)>=abs(dy))
            length=abs(dx);
        else
            length=abs(dy);

        float xinc=dx/float(length);
        float yinc=dy/float(length);

        x=x1;
        y=y1;
        int i=1;
        while(i<=length)
        {
            image.setPixel(round(x),round(y),qRgb(255, 255, 255));
            x=x+xinc;
            y=y+yinc;
            i++;
        }
     image.setPixel(x1,y1,qRgb(255,255,255));
     image.setPixel(x2,y2,qRgb(255,255,255));
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(complete){
        seedX = ev->pos().x();
        seedY = ev->pos().y();
        return;
    }
        if(first==true)
        {
            x1=ev->pos().x();
            y1=ev->pos().y();
            first=false;
            polygon[vertexCount][0] = x1;
            polygon[vertexCount][1] = y1;
            vertexCount++;
            emit(clicked());
            return;
        }
        if(first==false)
        {
            x2=ev->pos().x();
            y2=ev->pos().y();
            setinit=true;
            first=true;
            polygon[vertexCount][0] = x2;
            polygon[vertexCount][1] = y2;
            vertexCount++;
        }
        emit(clicked());
}

void MainWindow::clickEvent()
{
    ui->drawingarea->setPixmap(QPixmap::fromImage(image));
    if(!setinit)
        return;
    QRgb border = image.pixel(x2,y2);
    if(border != qRgb(0,255,255))
    {
        line(x1,y1,x2,y2);
        ui->drawingarea->setPixmap(QPixmap::fromImage(image));
        return;
    }
}

void MainWindow::on_mDrawPolygonButton_clicked(){
    line(polygon[0][0],polygon[0][1],polygon[vertexCount-1][0],polygon[vertexCount-1][1]);
    ui->drawingarea->setPixmap(QPixmap::fromImage(image));

    complete = true;

    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->mFillPolygonButton->setVisible(true);
    ui->mRedEditText->setVisible(true);
    ui->mBlueEditText->setVisible(true);
    ui->mGreenEditText->setVisible(true);
}

void floodfill(int x,int y,QRgb borderColor){
    if(image.pixel(x,y)!=borderColor && image.pixel(x,y)!=fillcolor){
        image.setPixel(x,y,fillcolor);
        floodfill(x+1,y,borderColor);
        floodfill(x,y-1,borderColor);
        floodfill(x,y+1,borderColor);
        floodfill(x-1,y,borderColor);
    }
}

void MainWindow::on_mFillPolygonButton_clicked(){
    int red = ui->mRedEditText->toPlainText().toInt();
    int green = ui->mGreenEditText->toPlainText().toInt();
    int blue = ui->mBlueEditText->toPlainText().toInt();
    fillcolor = qRgb(red,green,blue);
    floodfill(seedX,seedY,qRgb(255,255,255));
    ui->drawingarea->setPixmap(QPixmap::fromImage(image));
}
