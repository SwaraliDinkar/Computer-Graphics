#ifndef LINE_H
#define LINE_H

#include "mainwindow.h"
class line
{
public:
    line();
    QImage draw_line(int,int,int,int);
    int sign(int);
    friend class MainWindow;

    int topLeftX,topLeftY,bottomRightX,bottomRightY;

    void setPoints(int topLeftX,int topLeftY,int bottomRightX,int bottomRightY);
};

#endif // LINE_H
