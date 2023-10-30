/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDDALine;
    QAction *actionMidPointLine;
    QAction *actionBresenhamLine;
    QAction *actionMidPointCircle;
    QAction *actionBresenhamCircle;
    QAction *actionPenSetting;
    QAction *actionGAETPolygon;
    QAction *actionFloodFill4;
    QAction *actionScanLineFill4;
    QAction *actionClipWindow;
    QAction *actionCohen_SutherLandClip;
    QAction *actionLiang_BarskyClip;
    QAction *actionPolygon_Clip;
    QAction *actionBezierCurve;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionDDALine = new QAction(MainWindow);
        actionDDALine->setObjectName("actionDDALine");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/DDA_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDDALine->setIcon(icon);
        actionMidPointLine = new QAction(MainWindow);
        actionMidPointLine->setObjectName("actionMidPointLine");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/MidPoint_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMidPointLine->setIcon(icon1);
        actionBresenhamLine = new QAction(MainWindow);
        actionBresenhamLine->setObjectName("actionBresenhamLine");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/BresenhamLine_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBresenhamLine->setIcon(icon2);
        actionMidPointCircle = new QAction(MainWindow);
        actionMidPointCircle->setObjectName("actionMidPointCircle");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/MidPointCircle_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMidPointCircle->setIcon(icon3);
        actionBresenhamCircle = new QAction(MainWindow);
        actionBresenhamCircle->setObjectName("actionBresenhamCircle");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icons/BresenhamCircle_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBresenhamCircle->setIcon(icon4);
        actionPenSetting = new QAction(MainWindow);
        actionPenSetting->setObjectName("actionPenSetting");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icons/PenSetting_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPenSetting->setIcon(icon5);
        actionGAETPolygon = new QAction(MainWindow);
        actionGAETPolygon->setObjectName("actionGAETPolygon");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icons/AETPoly_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGAETPolygon->setIcon(icon6);
        actionFloodFill4 = new QAction(MainWindow);
        actionFloodFill4->setObjectName("actionFloodFill4");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/icons/FloodFill4_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFloodFill4->setIcon(icon7);
        actionScanLineFill4 = new QAction(MainWindow);
        actionScanLineFill4->setObjectName("actionScanLineFill4");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/icons/ScanLineFill4_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScanLineFill4->setIcon(icon8);
        actionClipWindow = new QAction(MainWindow);
        actionClipWindow->setObjectName("actionClipWindow");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/icons/ClipWinSetting_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClipWindow->setIcon(icon9);
        actionCohen_SutherLandClip = new QAction(MainWindow);
        actionCohen_SutherLandClip->setObjectName("actionCohen_SutherLandClip");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/icons/Cohen-Sutherland_Clip_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCohen_SutherLandClip->setIcon(icon10);
        actionLiang_BarskyClip = new QAction(MainWindow);
        actionLiang_BarskyClip->setObjectName("actionLiang_BarskyClip");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/icons/Liang-Barsky_Clip_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLiang_BarskyClip->setIcon(icon11);
        actionPolygon_Clip = new QAction(MainWindow);
        actionPolygon_Clip->setObjectName("actionPolygon_Clip");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/icons/polygon_Clip_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPolygon_Clip->setIcon(icon12);
        actionBezierCurve = new QAction(MainWindow);
        actionBezierCurve->setObjectName("actionBezierCurve");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/icons/BezierCurve_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBezierCurve->setIcon(icon13);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionPenSetting);
        toolBar->addAction(actionDDALine);
        toolBar->addAction(actionMidPointLine);
        toolBar->addAction(actionBresenhamLine);
        toolBar->addAction(actionMidPointCircle);
        toolBar->addAction(actionBresenhamCircle);
        toolBar->addAction(actionGAETPolygon);
        toolBar->addAction(actionFloodFill4);
        toolBar->addAction(actionScanLineFill4);
        toolBar->addAction(actionClipWindow);
        toolBar->addAction(actionCohen_SutherLandClip);
        toolBar->addAction(actionLiang_BarskyClip);
        toolBar->addAction(actionPolygon_Clip);
        toolBar->addAction(actionBezierCurve);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDDALine->setText(QCoreApplication::translate("MainWindow", "DDALine", nullptr));
#if QT_CONFIG(tooltip)
        actionDDALine->setToolTip(QCoreApplication::translate("MainWindow", "DDA\347\233\264\347\272\277\346\211\253\346\217\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMidPointLine->setText(QCoreApplication::translate("MainWindow", "MidPointLine", nullptr));
#if QT_CONFIG(tooltip)
        actionMidPointLine->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\255\347\202\271\347\224\273\347\272\277\346\263\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBresenhamLine->setText(QCoreApplication::translate("MainWindow", "BresenhamLine", nullptr));
#if QT_CONFIG(tooltip)
        actionBresenhamLine->setToolTip(QCoreApplication::translate("MainWindow", "Bresenham\347\224\273\347\272\277\346\263\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMidPointCircle->setText(QCoreApplication::translate("MainWindow", "MidPointCircle", nullptr));
#if QT_CONFIG(tooltip)
        actionMidPointCircle->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\255\347\202\271\347\224\273\345\234\206\346\263\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBresenhamCircle->setText(QCoreApplication::translate("MainWindow", "BresenhamCircle", nullptr));
#if QT_CONFIG(tooltip)
        actionBresenhamCircle->setToolTip(QCoreApplication::translate("MainWindow", "Bresenham\347\224\273\345\234\206\346\263\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPenSetting->setText(QCoreApplication::translate("MainWindow", "PenSetting", nullptr));
#if QT_CONFIG(tooltip)
        actionPenSetting->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\347\224\273\347\254\224", nullptr));
#endif // QT_CONFIG(tooltip)
        actionGAETPolygon->setText(QCoreApplication::translate("MainWindow", "GAETPolygon", nullptr));
#if QT_CONFIG(tooltip)
        actionGAETPolygon->setToolTip(QCoreApplication::translate("MainWindow", "\346\224\271\350\277\233\347\232\204X\346\211\253\346\217\217\347\272\277\346\226\271\346\263\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFloodFill4->setText(QCoreApplication::translate("MainWindow", "FloodFill4", nullptr));
#if QT_CONFIG(tooltip)
        actionFloodFill4->setToolTip(QCoreApplication::translate("MainWindow", "\347\247\215\345\255\220\345\241\253\345\205\205", nullptr));
#endif // QT_CONFIG(tooltip)
        actionScanLineFill4->setText(QCoreApplication::translate("MainWindow", "ScanLineFill4", nullptr));
#if QT_CONFIG(tooltip)
        actionScanLineFill4->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\253\346\217\217\347\272\277\345\241\253\345\205\205", nullptr));
#endif // QT_CONFIG(tooltip)
        actionClipWindow->setText(QCoreApplication::translate("MainWindow", "ClipWindow", nullptr));
#if QT_CONFIG(tooltip)
        actionClipWindow->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\243\201\345\211\252\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCohen_SutherLandClip->setText(QCoreApplication::translate("MainWindow", "Cohen_SutherLandClip", nullptr));
#if QT_CONFIG(tooltip)
        actionCohen_SutherLandClip->setToolTip(QCoreApplication::translate("MainWindow", "Cohen_SutherLand\350\243\201\345\211\252\347\256\227\346\263\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLiang_BarskyClip->setText(QCoreApplication::translate("MainWindow", "Liang_BarskyClip", nullptr));
#if QT_CONFIG(tooltip)
        actionLiang_BarskyClip->setToolTip(QCoreApplication::translate("MainWindow", "\346\242\201\345\217\213\346\240\213-Barsky\347\233\264\347\272\277\346\256\265\350\243\201\345\211\252", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPolygon_Clip->setText(QCoreApplication::translate("MainWindow", "Polygon_Clip", nullptr));
#if QT_CONFIG(tooltip)
        actionPolygon_Clip->setToolTip(QCoreApplication::translate("MainWindow", "Sutherland-Hodgeman\345\244\232\350\276\271\345\275\242\350\243\201\345\211\252", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBezierCurve->setText(QCoreApplication::translate("MainWindow", "BezierCurve", nullptr));
#if QT_CONFIG(tooltip)
        actionBezierCurve->setToolTip(QCoreApplication::translate("MainWindow", "Bezier\346\233\262\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
