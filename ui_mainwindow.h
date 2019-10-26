/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mygl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionCamera_Controls;
    QWidget *centralWidget;
    MyGL *mygl;
    QListWidget *vertsListWidget;
    QListWidget *halfEdgesListWidget;
    QListWidget *facesListWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *vertPosXSpinBox;
    QDoubleSpinBox *vertPosYSpinBox;
    QDoubleSpinBox *vertPosZSpinBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *faceBlueSpinBox;
    QLabel *label_10;
    QDoubleSpinBox *faceGreenSpinBox;
    QDoubleSpinBox *faceRedSpinBox;
    QLabel *label_11;
    QPushButton *pushButtonAddVertex;
    QPushButton *pushButtonTriangulate;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1067, 489);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionCamera_Controls = new QAction(MainWindow);
        actionCamera_Controls->setObjectName(QStringLiteral("actionCamera_Controls"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QStringLiteral("mygl"));
        mygl->setGeometry(QRect(11, 11, 618, 432));
        vertsListWidget = new QListWidget(centralWidget);
        vertsListWidget->setObjectName(QStringLiteral("vertsListWidget"));
        vertsListWidget->setGeometry(QRect(640, 10, 111, 261));
        halfEdgesListWidget = new QListWidget(centralWidget);
        halfEdgesListWidget->setObjectName(QStringLiteral("halfEdgesListWidget"));
        halfEdgesListWidget->setGeometry(QRect(770, 10, 111, 261));
        facesListWidget = new QListWidget(centralWidget);
        facesListWidget->setObjectName(QStringLiteral("facesListWidget"));
        facesListWidget->setGeometry(QRect(900, 10, 111, 261));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(640, 280, 111, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(770, 280, 111, 16));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(900, 280, 111, 16));
        label_3->setAlignment(Qt::AlignCenter);
        vertPosXSpinBox = new QDoubleSpinBox(centralWidget);
        vertPosXSpinBox->setObjectName(QStringLiteral("vertPosXSpinBox"));
        vertPosXSpinBox->setGeometry(QRect(740, 320, 62, 22));
        vertPosXSpinBox->setMinimum(-99);
        vertPosYSpinBox = new QDoubleSpinBox(centralWidget);
        vertPosYSpinBox->setObjectName(QStringLiteral("vertPosYSpinBox"));
        vertPosYSpinBox->setGeometry(QRect(820, 320, 62, 22));
        vertPosYSpinBox->setMinimum(-99);
        vertPosZSpinBox = new QDoubleSpinBox(centralWidget);
        vertPosZSpinBox->setObjectName(QStringLiteral("vertPosZSpinBox"));
        vertPosZSpinBox->setGeometry(QRect(900, 320, 62, 22));
        vertPosZSpinBox->setMinimum(-99);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(640, 320, 91, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(740, 340, 61, 16));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(820, 340, 61, 16));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(900, 340, 61, 16));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(900, 390, 61, 16));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(740, 390, 61, 16));
        label_9->setAlignment(Qt::AlignCenter);
        faceBlueSpinBox = new QDoubleSpinBox(centralWidget);
        faceBlueSpinBox->setObjectName(QStringLiteral("faceBlueSpinBox"));
        faceBlueSpinBox->setGeometry(QRect(900, 370, 62, 22));
        faceBlueSpinBox->setMaximum(1);
        faceBlueSpinBox->setSingleStep(0.01);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(640, 370, 71, 21));
        faceGreenSpinBox = new QDoubleSpinBox(centralWidget);
        faceGreenSpinBox->setObjectName(QStringLiteral("faceGreenSpinBox"));
        faceGreenSpinBox->setGeometry(QRect(820, 370, 62, 22));
        faceGreenSpinBox->setMaximum(1);
        faceGreenSpinBox->setSingleStep(0.01);
        faceRedSpinBox = new QDoubleSpinBox(centralWidget);
        faceRedSpinBox->setObjectName(QStringLiteral("faceRedSpinBox"));
        faceRedSpinBox->setGeometry(QRect(740, 370, 62, 22));
        faceRedSpinBox->setMaximum(1);
        faceRedSpinBox->setSingleStep(0.01);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(820, 390, 61, 16));
        label_11->setAlignment(Qt::AlignCenter);
        pushButtonAddVertex = new QPushButton(centralWidget);
        pushButtonAddVertex->setObjectName(QStringLiteral("pushButtonAddVertex"));
        pushButtonAddVertex->setGeometry(QRect(710, 420, 93, 28));
        pushButtonTriangulate = new QPushButton(centralWidget);
        pushButtonTriangulate->setObjectName(QStringLiteral("pushButtonTriangulate"));
        pushButtonTriangulate->setGeometry(QRect(870, 420, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1067, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionCamera_Controls);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OpenGLDemo", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCamera_Controls->setText(QApplication::translate("MainWindow", "Camera Controls", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Vertices", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Half-Edges", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Faces", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Vertex Position", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Blue", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Red", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Face Color", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Green", Q_NULLPTR));
        pushButtonAddVertex->setText(QApplication::translate("MainWindow", "Split this Edge", Q_NULLPTR));
        pushButtonTriangulate->setText(QApplication::translate("MainWindow", "Triangulate", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
