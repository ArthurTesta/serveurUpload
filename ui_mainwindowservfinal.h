/********************************************************************************
** Form generated from reading UI file 'mainwindowservfinal.ui'
**
** Created: Tue Nov 27 20:01:17 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWSERVFINAL_H
#define UI_MAINWINDOWSERVFINAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowServFinal
{
public:
    QWidget *centralWidget;
    QPushButton *ServLaunch;
    QLabel *labelChooseInterface;
    QListWidget *listInterface;
    QLabel *labelPort;
    QSpinBox *spinBoxPort;
    QLabel *labelPath;
    QLineEdit *lineEditPath;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowServFinal)
    {
        if (MainWindowServFinal->objectName().isEmpty())
            MainWindowServFinal->setObjectName(QString::fromUtf8("MainWindowServFinal"));
        MainWindowServFinal->resize(265, 424);
        centralWidget = new QWidget(MainWindowServFinal);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ServLaunch = new QPushButton(centralWidget);
        ServLaunch->setObjectName(QString::fromUtf8("ServLaunch"));
        ServLaunch->setGeometry(QRect(30, 320, 191, 27));
        labelChooseInterface = new QLabel(centralWidget);
        labelChooseInterface->setObjectName(QString::fromUtf8("labelChooseInterface"));
        labelChooseInterface->setGeometry(QRect(0, 20, 251, 17));
        listInterface = new QListWidget(centralWidget);
        listInterface->setObjectName(QString::fromUtf8("listInterface"));
        listInterface->setGeometry(QRect(0, 40, 256, 141));
        labelPort = new QLabel(centralWidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setGeometry(QRect(0, 190, 261, 17));
        spinBoxPort = new QSpinBox(centralWidget);
        spinBoxPort->setObjectName(QString::fromUtf8("spinBoxPort"));
        spinBoxPort->setGeometry(QRect(90, 210, 60, 27));
        spinBoxPort->setMinimum(1000);
        spinBoxPort->setMaximum(4000);
        spinBoxPort->setValue(4000);
        labelPath = new QLabel(centralWidget);
        labelPath->setObjectName(QString::fromUtf8("labelPath"));
        labelPath->setGeometry(QRect(0, 250, 111, 17));
        lineEditPath = new QLineEdit(centralWidget);
        lineEditPath->setObjectName(QString::fromUtf8("lineEditPath"));
        lineEditPath->setGeometry(QRect(0, 270, 251, 27));
        MainWindowServFinal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowServFinal);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 265, 25));
        MainWindowServFinal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowServFinal);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowServFinal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowServFinal);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowServFinal->setStatusBar(statusBar);

        retranslateUi(MainWindowServFinal);

        QMetaObject::connectSlotsByName(MainWindowServFinal);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowServFinal)
    {
        MainWindowServFinal->setWindowTitle(QApplication::translate("MainWindowServFinal", "Serveur 0.1", 0, QApplication::UnicodeUTF8));
        ServLaunch->setText(QApplication::translate("MainWindowServFinal", "Launch", 0, QApplication::UnicodeUTF8));
        labelChooseInterface->setText(QApplication::translate("MainWindowServFinal", "Choose interface :", 0, QApplication::UnicodeUTF8));
        labelPort->setText(QApplication::translate("MainWindowServFinal", "Choose port :", 0, QApplication::UnicodeUTF8));
        labelPath->setText(QApplication::translate("MainWindowServFinal", "Choose path :", 0, QApplication::UnicodeUTF8));
        lineEditPath->setText(QApplication::translate("MainWindowServFinal", "/home/web/test", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowServFinal: public Ui_MainWindowServFinal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWSERVFINAL_H
