#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int initialX,initialY,finalX,finalY;
    bool first;

    void line(QImage &mQImage,double initialX,double initialY,double finalX,double finalY);
    int sign(int number);

    void mousePressEvent(QMouseEvent *ev);

private slots:
    void on_redButton_clicked();

    void on_blueButton_clicked();

    void on_greenButton_clicked();

    void on_whiteButton_clicked();

    void clickEvent();
private:
    Ui::MainWindow *ui;

signals:
    void clicked();
};

#endif // MAINWINDOW_H
