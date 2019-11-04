#include "line.h"
#include "mainwindow.h"
line::line()
{
}

QImage line::draw_line(int x1,int y1,int x2,int y2)
{
    QImage img(768,768,QImage::Format_RGB888);
    double len;
    if (abs(x2-x1)>=abs(y2-y1))
        len=abs(x2-x1);
    else
        len=abs(y2-y1);
    double X=(x2-x1)/len;
    double Y=(y2-y1)/len;
    double x=x1+(0.5*sign(X));
    double y=y1+(0.5*sign(Y));
    int i=1;
    while(i<=len)
    {
        if((x>topLeftX && x<bottomRightX) && (y<bottomRightY && y> topLeftY))
            img.setPixel(x,y,qRgb(255,255,255));
        else if((x==topLeftX || x==bottomRightX) && y<bottomRightY && y>topLeftY){
            img.setPixel(x,y,qRgb(0,255,0));
        }
        else if((y==topLeftY || y==bottomRightY) && x<bottomRightX && x>topLeftX){
            img.setPixel(x,y,qRgb(0,255,0));
        }
        x=x+X;
        y=y+Y;
        i+=1;
     }
    return img;
}

int line::sign(int a)
{
    if(a<0)
        return -1;
    else if(a>0)
        return 1;
    else
        return 0;

}

void line::setPoints(int topLeftX,int topLeftY,int bottomRightX,int bottomRightY){
    this->topLeftX = topLeftX;
    this->topLeftY = topLeftY;
    this->bottomRightX = bottomRightX;
    this->bottomRightY = bottomRightY;
}
