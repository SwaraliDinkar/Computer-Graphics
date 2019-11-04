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
    int index;
    int polygon[10][2];
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_mSetPointButton_clicked();

    void on_mDrawButton_clicked();

    void on_mRotateFunctionButton_clicked();

    void on_mXRelfectButton_clicked();

    void on_mYReflectButton_clicked();

    void on_mXYReflectButton_clicked();

    void on_mRotateButton_clicked();

private:
    Ui::MainWindow *ui;
    void drawAxis(QImage&);
    void line(QImage&,int,int,int,int,QRgb);
    int sign(int);

};

#endif // MAINWINDOW_H
