#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "bmp_file.h"

enum pictureLabels
{
    source,
    io_source,
    io_result,
    he_result,
    sb_result
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    ///Member bmp objects
    bmp_file original_image;
    bmp_file overlay_image;
    bmp_file result_overlay_image;
    bmp_file histogram_equalized_image;
    bmp_file sliderbar_image;

private slots:
    void on_actionLoad_Bitmap_triggered();

    void on_actionSave_Image_Overlay_Result_triggered();

    void on_actionSave_Histogram_Equalization_Result_triggered();

    void on_actionLoad_Overlay_Image_triggered();

    void on_brightnessSlider_valueChanged(int value);

    void on_contrastSlider_valueChanged(int value);


private:
    Ui::MainWindow *ui;

    void DisplayImage (pictureLabels WidgetName, bmp_file picture);
};

#endif // MAINWINDOW_H
