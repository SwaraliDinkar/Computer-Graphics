#ifndef LINE_H
#define LINE_H

#include "mainwindow.h"

class line
{
public:
    line();
    void draw_line(mQImage&,int,int,int,int);
    int sign(int);
    friend class MainWindow;
};

#endif // LINE_H
