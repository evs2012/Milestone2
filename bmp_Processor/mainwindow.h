#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bmp_file.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_Bitmap_triggered();

    void on_horizontalSlider_sliderMoved(int position);

    void on_actionSave_Image_Overlay_Result_triggered();

    void on_actionSave_Histogram_Equalization_Result_triggered();

    void on_actionLoad_Overlay_Image_triggered();

    void on_horizontalSlider_2_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    void DisplayImage (QString WidgetName, bmp_file Image);
};

#endif // MAINWINDOW_H
