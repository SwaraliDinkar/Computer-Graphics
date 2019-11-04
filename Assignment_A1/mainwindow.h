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

    void drawImage(QImage &mQImage, double initialX, double initialY,double side);
    void drawLineBre(QImage &mQImage,double initialX,double initialY,double finalX,double finalY);
    void drawLineDDA(QImage &mQImage,double initialX,double initialY,double finalX,double finalY);

    int sign(double number);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
