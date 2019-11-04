/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *drawingArea;
    QPlainTextEdit *mTopLeftXEditText;
    QPlainTextEdit *mBottomRightYEditText;
    QPlainTextEdit *mBottomRightXEditText;
    QPlainTextEdit *mTopLeftYEditText;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *setWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1366, 768);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        drawingArea = new QLabel(centralWidget);
        drawingArea->setObjectName(QStringLiteral("drawingArea"));
        drawingArea->setGeometry(QRect(0, 0, 768, 768));
        mTopLeftXEditText = new QPlainTextEdit(centralWidget);
        mTopLeftXEditText->setObjectName(QStringLiteral("mTopLeftXEditText"));
        mTopLeftXEditText->setGeometry(QRect(870, 60, 50, 30));
        mBottomRightYEditText = new QPlainTextEdit(centralWidget);
        mBottomRightYEditText->setObjectName(QStringLiteral("mBottomRightYEditText"));
        mBottomRightYEditText->setGeometry(QRect(1100, 60, 50, 30));
        mBottomRightXEditText = new QPlainTextEdit(centralWidget);
        mBottomRightXEditText->setObjectName(QStringLiteral("mBottomRightXEditText"));
        mBottomRightXEditText->setGeometry(QRect(1100, 100, 50, 30));
        mTopLeftYEditText = new QPlainTextEdit(centralWidget);
        mTopLeftYEditText->setObjectName(QStringLiteral("mTopLeftYEditText"));
        mTopLeftYEditText->setGeometry(QRect(870, 100, 50, 30));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(800, 60, 70, 30));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1000, 60, 100, 30));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1000, 100, 100, 30));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(800, 100, 70, 30));
        setWindow = new QPushButton(centralWidget);
        setWindow->setObjectName(QStringLiteral("setWindow"));
        setWindow->setGeometry(QRect(930, 160, 150, 30));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        drawingArea->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Top Left X:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Bottom Right X:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Bottom Right Y:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Top Left Y:", Q_NULLPTR));
        setWindow->setText(QApplication::translate("MainWindow", "Set Clipping Window", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
