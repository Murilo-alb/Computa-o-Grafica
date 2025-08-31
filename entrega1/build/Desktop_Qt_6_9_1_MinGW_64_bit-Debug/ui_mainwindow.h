/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <tela.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_desenhar;
    QPushButton *btn_reset;
    QPushButton *btn_novoPoligono;
    QListWidget *listWidget_opcoes;
    QPushButton *btn_sair;
    Tela *Frame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(765, 516);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btn_desenhar = new QPushButton(centralwidget);
        btn_desenhar->setObjectName("btn_desenhar");
        btn_desenhar->setGeometry(QRect(100, 190, 141, 61));
        btn_reset = new QPushButton(centralwidget);
        btn_reset->setObjectName("btn_reset");
        btn_reset->setGeometry(QRect(100, 260, 141, 61));
        btn_novoPoligono = new QPushButton(centralwidget);
        btn_novoPoligono->setObjectName("btn_novoPoligono");
        btn_novoPoligono->setGeometry(QRect(100, 120, 141, 61));
        listWidget_opcoes = new QListWidget(centralwidget);
        listWidget_opcoes->setObjectName("listWidget_opcoes");
        listWidget_opcoes->setGeometry(QRect(60, 10, 231, 91));
        btn_sair = new QPushButton(centralwidget);
        btn_sair->setObjectName("btn_sair");
        btn_sair->setGeometry(QRect(100, 330, 141, 61));
        Frame = new Tela(centralwidget);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(310, 20, 431, 431));
        Frame->setFrameShape(QFrame::Shape::StyledPanel);
        Frame->setFrameShadow(QFrame::Shadow::Raised);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 765, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(btn_sair, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_desenhar->setText(QCoreApplication::translate("MainWindow", "Desenhar Pol\303\255gono", nullptr));
        btn_reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        btn_novoPoligono->setText(QCoreApplication::translate("MainWindow", "Novo Pol\303\255gono", nullptr));
        btn_sair->setText(QCoreApplication::translate("MainWindow", "Sair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
