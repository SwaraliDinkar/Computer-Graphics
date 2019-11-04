#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int tempX1,tempX2,tempY1,tempY2;
    int x1,y1,x2,y2;
    bool first;
    bool initset;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);


private:
    Ui::MainWindow *ui;

private slots:
    void clickev();

    void on_setWindow_clicked();

signals:
    void clicked();
    void movement();
};

#endif // MAINWINDOW_H
