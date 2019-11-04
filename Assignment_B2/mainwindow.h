#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int polygon[10][2];
    int vertexCount;
    int x1,x2,y1,y2;
    bool first,setinit;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool complete;
    int seedX,seedY;

    void line(int x1,int y1,int x2,int y2);
    int sign(int a);

    void mousePressEvent(QMouseEvent *ev);
private:
    Ui::MainWindow *ui;

signals:
    void clicked();

private slots:
    void clickEvent();
    void on_mDrawPolygonButton_clicked();
    void on_mFillPolygonButton_clicked();
};

#endif // MAINWINDOW_H
