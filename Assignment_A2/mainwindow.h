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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void drawTriangle(QImage &mQImage, int centerX, int centerY, double radius);
    void line(QImage &mQImage,double initialX,double initialY,double finalX,double finalY);
    void plotPoints(QImage &mQImage,int centerX,int centerY, int x, int y);
    void drawCircleDDA(QImage &mQImage,int centerX,int centerY,int radius);
    void drawCircleBre(QImage &mQImage, int centerX, int centerY, int radius);
    int sign(int number);

private slots:
    void on_mDrawDiagramButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
