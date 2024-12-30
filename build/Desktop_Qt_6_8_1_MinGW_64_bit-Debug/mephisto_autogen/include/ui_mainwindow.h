/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *navbar;
    QPushButton *openFileBtn;
    QPushButton *saveFileBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *runBtn;
    QPushButton *debugBtn;
    QTextEdit *codeEditor;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *data;
    QHBoxLayout *regsData;
    QTableWidget *regsData1;
    QTableWidget *regsData2;
    QTableWidget *regsData3;
    QTableWidget *regsData4;
    QListWidget *memData;
    QPlainTextEdit *textOutput;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1220, 593);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(60, 10, 611, 51));
        navbar = new QHBoxLayout(horizontalLayoutWidget);
        navbar->setObjectName("navbar");
        navbar->setContentsMargins(0, 0, 0, 0);
        openFileBtn = new QPushButton(horizontalLayoutWidget);
        openFileBtn->setObjectName("openFileBtn");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setStrikeOut(false);
        openFileBtn->setFont(font);
        openFileBtn->setAutoFillBackground(false);
        openFileBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 15px;\n"
"\n"
"QPushButton {\n"
"	qpoperty-icon: url(:/assets/OpenFile.png);\n"
"	qproperty-iconSize: 32px 32px;\n"
"	text-align: center;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("assets/OpenFile.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        openFileBtn->setIcon(icon);
        openFileBtn->setIconSize(QSize(32, 32));

        navbar->addWidget(openFileBtn);

        saveFileBtn = new QPushButton(horizontalLayoutWidget);
        saveFileBtn->setObjectName("saveFileBtn");
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        saveFileBtn->setFont(font1);
        saveFileBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 15px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("assets/SaveFile.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        saveFileBtn->setIcon(icon1);
        saveFileBtn->setIconSize(QSize(32, 32));

        navbar->addWidget(saveFileBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        navbar->addItem(verticalSpacer);

        runBtn = new QPushButton(horizontalLayoutWidget);
        runBtn->setObjectName("runBtn");
        runBtn->setFont(font1);
        runBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 15px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("assets/Run.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        runBtn->setIcon(icon2);
        runBtn->setIconSize(QSize(32, 32));

        navbar->addWidget(runBtn);

        debugBtn = new QPushButton(horizontalLayoutWidget);
        debugBtn->setObjectName("debugBtn");
        debugBtn->setFont(font1);
        debugBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border-radius: 15px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("assets/Debug.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        debugBtn->setIcon(icon3);
        debugBtn->setIconSize(QSize(32, 32));

        navbar->addWidget(debugBtn);

        codeEditor = new QTextEdit(centralwidget);
        codeEditor->setObjectName("codeEditor");
        codeEditor->setGeometry(QRect(90, 70, 551, 241));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(710, 20, 441, 551));
        data = new QVBoxLayout(verticalLayoutWidget);
        data->setObjectName("data");
        data->setContentsMargins(0, 0, 0, 0);
        regsData = new QHBoxLayout();
        regsData->setObjectName("regsData");
        regsData1 = new QTableWidget(verticalLayoutWidget);
        if (regsData1->columnCount() < 1)
            regsData1->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        regsData1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (regsData1->rowCount() < 8)
            regsData1->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        regsData1->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        regsData1->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        regsData1->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        regsData1->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        regsData1->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        regsData1->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        regsData1->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        regsData1->setVerticalHeaderItem(7, __qtablewidgetitem8);
        regsData1->setObjectName("regsData1");

        regsData->addWidget(regsData1);

        regsData2 = new QTableWidget(verticalLayoutWidget);
        if (regsData2->columnCount() < 1)
            regsData2->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        regsData2->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        if (regsData2->rowCount() < 8)
            regsData2->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        regsData2->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        regsData2->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        regsData2->setVerticalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        regsData2->setVerticalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        regsData2->setVerticalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        regsData2->setVerticalHeaderItem(5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        regsData2->setVerticalHeaderItem(6, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        regsData2->setVerticalHeaderItem(7, __qtablewidgetitem17);
        regsData2->setObjectName("regsData2");

        regsData->addWidget(regsData2);

        regsData3 = new QTableWidget(verticalLayoutWidget);
        if (regsData3->columnCount() < 1)
            regsData3->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        regsData3->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        if (regsData3->rowCount() < 8)
            regsData3->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        regsData3->setVerticalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        regsData3->setVerticalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        regsData3->setVerticalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        regsData3->setVerticalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        regsData3->setVerticalHeaderItem(4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        regsData3->setVerticalHeaderItem(5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        regsData3->setVerticalHeaderItem(6, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        regsData3->setVerticalHeaderItem(7, __qtablewidgetitem26);
        regsData3->setObjectName("regsData3");

        regsData->addWidget(regsData3);

        regsData4 = new QTableWidget(verticalLayoutWidget);
        if (regsData4->columnCount() < 1)
            regsData4->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        regsData4->setHorizontalHeaderItem(0, __qtablewidgetitem27);
        if (regsData4->rowCount() < 8)
            regsData4->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        regsData4->setVerticalHeaderItem(0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        regsData4->setVerticalHeaderItem(1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        regsData4->setVerticalHeaderItem(2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        regsData4->setVerticalHeaderItem(3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        regsData4->setVerticalHeaderItem(4, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        regsData4->setVerticalHeaderItem(5, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        regsData4->setVerticalHeaderItem(6, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        regsData4->setVerticalHeaderItem(7, __qtablewidgetitem35);
        regsData4->setObjectName("regsData4");

        regsData->addWidget(regsData4);


        data->addLayout(regsData);

        memData = new QListWidget(verticalLayoutWidget);
        memData->setObjectName("memData");

        data->addWidget(memData);

        textOutput = new QPlainTextEdit(centralwidget);
        textOutput->setObjectName("textOutput");
        textOutput->setGeometry(QRect(90, 400, 551, 171));
        textOutput->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mephisto | RISC-V IDE", nullptr));
        openFileBtn->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        saveFileBtn->setText(QCoreApplication::translate("MainWindow", "Save File", nullptr));
        runBtn->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        debugBtn->setText(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        codeEditor->setPlaceholderText(QCoreApplication::translate("MainWindow", "Your ASM (RISC-V) code here...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = regsData1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "data", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = regsData1->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "x0", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = regsData1->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "x1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = regsData1->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "x2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = regsData1->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "x3", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = regsData1->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "x4", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = regsData1->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "x5", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = regsData1->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "x6", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = regsData1->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "x7", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = regsData2->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "data", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = regsData2->verticalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "x8", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = regsData2->verticalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "x9", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = regsData2->verticalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "x10", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = regsData2->verticalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "x11", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = regsData2->verticalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "x12", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = regsData2->verticalHeaderItem(5);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "x13", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = regsData2->verticalHeaderItem(6);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "x14", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = regsData2->verticalHeaderItem(7);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "x15", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = regsData3->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "data", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = regsData3->verticalHeaderItem(0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "x16", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = regsData3->verticalHeaderItem(1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "x17", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = regsData3->verticalHeaderItem(2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "x18", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = regsData3->verticalHeaderItem(3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "x19", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = regsData3->verticalHeaderItem(4);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "x20", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = regsData3->verticalHeaderItem(5);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "x21", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = regsData3->verticalHeaderItem(6);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "x22", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = regsData3->verticalHeaderItem(7);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "x23", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = regsData4->horizontalHeaderItem(0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "data", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = regsData4->verticalHeaderItem(0);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "x24", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = regsData4->verticalHeaderItem(1);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "x25", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = regsData4->verticalHeaderItem(2);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "x26", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = regsData4->verticalHeaderItem(3);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "x27", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = regsData4->verticalHeaderItem(4);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "x28", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = regsData4->verticalHeaderItem(5);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "x29", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = regsData4->verticalHeaderItem(6);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "x30", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = regsData4->verticalHeaderItem(7);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "x31", nullptr));
        textOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Here will be the program output...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
