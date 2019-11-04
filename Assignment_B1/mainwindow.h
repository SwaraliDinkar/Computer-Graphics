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

    int sign(double number);

private slots:
    void on_mDrawThinLine_clicked();

    void on_mDrawDottedLine_clicked();

    void on_mDrawDashedLine_clicked();

    void on_mDrawDashedDottedLine_clicked();

    void on_mDrawThickLine_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
