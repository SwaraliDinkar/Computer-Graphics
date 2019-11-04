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
    QPlainTextEdit *editText_X;
    QPlainTextEdit *editText_Y;
    QPlainTextEdit *parameter2EditText;
    QPlainTextEdit *parameter1EditText;
    QLabel *inputYLabel;
    QLabel *inputXLabel;
    QLabel *parameter1Label;
    QLabel *parameter2Label;
    QPushButton *mSetPointButton;
    QPushButton *mDrawPolygonButton;
    QPushButton *mTranslationButton;
    QPushButton *mTransformButton;
    QPushButton *mScalingButton;
    QPushButton *mRotationButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        drawingArea = new QLabel(centralWidget);
        drawingArea->setObjectName(QStringLiteral("drawingArea"));
        drawingArea->setGeometry(QRect(0, 0, 700, 700));
        editText_X = new QPlainTextEdit(centralWidget);
        editText_X->setObjectName(QStringLiteral("editText_X"));
        editText_X->setGeometry(QRect(870, 50, 40, 30));
        editText_Y = new QPlainTextEdit(centralWidget);
        editText_Y->setObjectName(QStringLiteral("editText_Y"));
        editText_Y->setGeometry(QRect(870, 90, 40, 30));
        parameter2EditText = new QPlainTextEdit(centralWidget);
        parameter2EditText->setObjectName(QStringLiteral("parameter2EditText"));
        parameter2EditText->setGeometry(QRect(910, 500, 40, 30));
        parameter1EditText = new QPlainTextEdit(centralWidget);
        parameter1EditText->setObjectName(QStringLiteral("parameter1EditText"));
        parameter1EditText->setGeometry(QRect(810, 500, 40, 30));
        inputYLabel = new QLabel(centralWidget);
        inputYLabel->setObjectName(QStringLiteral("inputYLabel"));
        inputYLabel->setGeometry(QRect(800, 90, 65, 30));
        inputXLabel = new QLabel(centralWidget);
        inputXLabel->setObjectName(QStringLiteral("inputXLabel"));
        inputXLabel->setGeometry(QRect(800, 50, 65, 30));
        parameter1Label = new QLabel(centralWidget);
        parameter1Label->setObjectName(QStringLiteral("parameter1Label"));
        parameter1Label->setGeometry(QRect(800, 460, 59, 30));
        parameter2Label = new QLabel(centralWidget);
        parameter2Label->setObjectName(QStringLiteral("parameter2Label"));
        parameter2Label->setGeometry(QRect(900, 460, 59, 30));
        mSetPointButton = new QPushButton(centralWidget);
        mSetPointButton->setObjectName(QStringLiteral("mSetPointButton"));
        mSetPointButton->setGeometry(QRect(840, 150, 80, 30));
        mDrawPolygonButton = new QPushButton(centralWidget);
        mDrawPolygonButton->setObjectName(QStringLiteral("mDrawPolygonButton"));
        mDrawPolygonButton->setGeometry(QRect(830, 200, 100, 30));
        mTranslationButton = new QPushButton(centralWidget);
        mTranslationButton->setObjectName(QStringLiteral("mTranslationButton"));
        mTranslationButton->setGeometry(QRect(840, 270, 80, 30));
        mTransformButton = new QPushButton(centralWidget);
        mTransformButton->setObjectName(QStringLiteral("mTransformButton"));
        mTransformButton->setGeometry(QRect(850, 600, 80, 30));
        mTransformButton->setMinimumSize(QSize(0, 30));
        mScalingButton = new QPushButton(centralWidget);
        mScalingButton->setObjectName(QStringLiteral("mScalingButton"));
        mScalingButton->setGeometry(QRect(840, 320, 80, 30));
        mRotationButton = new QPushButton(centralWidget);
        mRotationButton->setObjectName(QStringLiteral("mRotationButton"));
        mRotationButton->setGeometry(QRect(840, 370, 80, 30));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        drawingArea->setText(QString());
        inputYLabel->setText(QApplication::translate("MainWindow", "Point 1 Y:", Q_NULLPTR));
        inputXLabel->setText(QApplication::translate("MainWindow", "Point 1 X:", Q_NULLPTR));
        parameter1Label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        parameter2Label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        mSetPointButton->setText(QApplication::translate("MainWindow", "Set Point", Q_NULLPTR));
        mDrawPolygonButton->setText(QApplication::translate("MainWindow", "Draw Polygon", Q_NULLPTR));
        mTranslationButton->setText(QApplication::translate("MainWindow", "Translation", Q_NULLPTR));
        mTransformButton->setText(QApplication::translate("MainWindow", "Transform", Q_NULLPTR));
        mScalingButton->setText(QApplication::translate("MainWindow", "Scaling", Q_NULLPTR));
        mRotationButton->setText(QApplication::translate("MainWindow", "Rotation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
