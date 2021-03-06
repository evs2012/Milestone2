/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Bitmap;
    QAction *actionLoad_Overlay_Image;
    QAction *actionSave_Image_Overlay_Result;
    QAction *actionSave_Histogram_Equalization_Result;
    QAction *actionSave_Slider_Bar_Image_Result;
    QWidget *centralWidget;
    QSlider *brightnessSlider;
    QSlider *contrastSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *lbl_Original_Image;
    QLabel *lbl_Overlay_Image;
    QLabel *lbl_Overlay_Result;
    QLabel *lbl_HE_Result;
    QLabel *lbl_SB_Result;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(650, 858);
        actionLoad_Bitmap = new QAction(MainWindow);
        actionLoad_Bitmap->setObjectName(QStringLiteral("actionLoad_Bitmap"));
        actionLoad_Overlay_Image = new QAction(MainWindow);
        actionLoad_Overlay_Image->setObjectName(QStringLiteral("actionLoad_Overlay_Image"));
        actionSave_Image_Overlay_Result = new QAction(MainWindow);
        actionSave_Image_Overlay_Result->setObjectName(QStringLiteral("actionSave_Image_Overlay_Result"));
        actionSave_Histogram_Equalization_Result = new QAction(MainWindow);
        actionSave_Histogram_Equalization_Result->setObjectName(QStringLiteral("actionSave_Histogram_Equalization_Result"));
        actionSave_Slider_Bar_Image_Result = new QAction(MainWindow);
        actionSave_Slider_Bar_Image_Result->setObjectName(QStringLiteral("actionSave_Slider_Bar_Image_Result"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        brightnessSlider = new QSlider(centralWidget);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(20, 710, 160, 22));
        brightnessSlider->setToolTipDuration(-4);
        brightnessSlider->setMinimum(50);
        brightnessSlider->setMaximum(150);
        brightnessSlider->setSingleStep(1);
        brightnessSlider->setValue(100);
        brightnessSlider->setOrientation(Qt::Horizontal);
        contrastSlider = new QSlider(centralWidget);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setGeometry(QRect(20, 760, 160, 22));
        contrastSlider->setMinimum(0);
        contrastSlider->setMaximum(127);
        contrastSlider->setValue(127);
        contrastSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 690, 111, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 740, 111, 16));
        lbl_Original_Image = new QLabel(centralWidget);
        lbl_Original_Image->setObjectName(QStringLiteral("lbl_Original_Image"));
        lbl_Original_Image->setGeometry(QRect(20, 30, 256, 256));
        lbl_Original_Image->setFrameShape(QFrame::Box);
        lbl_Original_Image->setAlignment(Qt::AlignCenter);
        lbl_Overlay_Image = new QLabel(centralWidget);
        lbl_Overlay_Image->setObjectName(QStringLiteral("lbl_Overlay_Image"));
        lbl_Overlay_Image->setGeometry(QRect(280, 30, 256, 256));
        lbl_Overlay_Image->setFrameShape(QFrame::Box);
        lbl_Overlay_Image->setAlignment(Qt::AlignCenter);
        lbl_Overlay_Result = new QLabel(centralWidget);
        lbl_Overlay_Result->setObjectName(QStringLiteral("lbl_Overlay_Result"));
        lbl_Overlay_Result->setGeometry(QRect(280, 290, 256, 256));
        lbl_Overlay_Result->setFrameShape(QFrame::Box);
        lbl_Overlay_Result->setAlignment(Qt::AlignCenter);
        lbl_HE_Result = new QLabel(centralWidget);
        lbl_HE_Result->setObjectName(QStringLiteral("lbl_HE_Result"));
        lbl_HE_Result->setGeometry(QRect(20, 290, 256, 256));
        lbl_HE_Result->setFrameShape(QFrame::Box);
        lbl_HE_Result->setAlignment(Qt::AlignCenter);
        lbl_SB_Result = new QLabel(centralWidget);
        lbl_SB_Result->setObjectName(QStringLiteral("lbl_SB_Result"));
        lbl_SB_Result->setGeometry(QRect(280, 550, 256, 256));
        lbl_SB_Result->setFrameShape(QFrame::Box);
        lbl_SB_Result->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        lbl_Overlay_Result->raise();
        label->raise();
        label_2->raise();
        contrastSlider->raise();
        brightnessSlider->raise();
        lbl_Original_Image->raise();
        lbl_Overlay_Image->raise();
        lbl_HE_Result->raise();
        lbl_SB_Result->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_Bitmap);
        menuFile->addAction(actionLoad_Overlay_Image);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Image_Overlay_Result);
        menuFile->addAction(actionSave_Histogram_Equalization_Result);
        menuFile->addAction(actionSave_Slider_Bar_Image_Result);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad_Bitmap->setText(QApplication::translate("MainWindow", "Load Bitmap...", 0));
#ifndef QT_NO_TOOLTIP
        actionLoad_Bitmap->setToolTip(QApplication::translate("MainWindow", "Browse for a bitmap file for the program to process.", 0));
#endif // QT_NO_TOOLTIP
        actionLoad_Overlay_Image->setText(QApplication::translate("MainWindow", "Load Overlay Image...", 0));
        actionSave_Image_Overlay_Result->setText(QApplication::translate("MainWindow", "Save Image Overlay Result...", 0));
        actionSave_Histogram_Equalization_Result->setText(QApplication::translate("MainWindow", "Save Histogram Equalization Result...", 0));
        actionSave_Slider_Bar_Image_Result->setText(QApplication::translate("MainWindow", "Save Slider Bar Image Result", 0));
        label->setText(QApplication::translate("MainWindow", "Adjust Brightness", 0));
        label_2->setText(QApplication::translate("MainWindow", "Adjust Contrast", 0));
        lbl_Original_Image->setText(QApplication::translate("MainWindow", "ORIGINAL IMAGE", 0));
        lbl_Overlay_Image->setText(QApplication::translate("MainWindow", "OVERLAY IMAGE", 0));
        lbl_Overlay_Result->setText(QApplication::translate("MainWindow", "OVERLAY RESULT", 0));
        lbl_HE_Result->setText(QApplication::translate("MainWindow", "HE RESULT", 0));
        lbl_SB_Result->setText(QApplication::translate("MainWindow", "SLIDERBAR RESULT", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
