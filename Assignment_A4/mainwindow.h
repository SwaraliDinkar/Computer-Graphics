#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>  // for string streams
#include <string>  // for string

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    double polygon[10][2];
    int vertices;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void line(double initialX,double initialY,double finalX,double finalY,QRgb mQRgb);
    int sign(double number);

    void translate(double tx,double ty);
    void scale(double sx,double sy);
    void rotate(double angle);
    int operation;

private slots:
    void on_mSetPointButton_clicked();

    void on_mDrawPolygonButton_clicked();

    void on_mTranslationButton_clicked();

    void on_mTransformButton_clicked();

    void on_mScalingButton_clicked();

    void on_mRotationButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
