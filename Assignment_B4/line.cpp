#include "line.h"
#include "mainwindow.h"
line::line()
{
}

int MainWindow::sign(int number){
    if(number<0)
        return -1;
    else if(number>0)
        return 1;
        return 0;
}

void line::draw_line(QImage &mQImage,int initialX,int initialY,int finalX,int finalY)
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
        mQImage.setPixel(x,y,qRgb(255,255,255));
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
