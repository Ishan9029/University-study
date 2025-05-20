/********************************************************************************
** Form generated from reading UI file 'chess.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESS_H
#define UI_CHESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chess
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chess)
    {
        if (chess->objectName().isEmpty())
            chess->setObjectName("chess");
        chess->resize(800, 600);
        centralWidget = new QWidget(chess);
        centralWidget->setObjectName("centralWidget");
        chess->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(chess);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        chess->setMenuBar(menuBar);
        statusBar = new QStatusBar(chess);
        statusBar->setObjectName("statusBar");
        chess->setStatusBar(statusBar);

        retranslateUi(chess);

        QMetaObject::connectSlotsByName(chess);
    } // setupUi

    void retranslateUi(QMainWindow *chess)
    {
        chess->setWindowTitle(QCoreApplication::translate("chess", "Chess", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chess: public Ui_chess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESS_H
