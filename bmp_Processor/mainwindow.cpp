#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_Bitmap_triggered()
{
    ///Open a file dialog to browse for a bitmap file.
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("Open Bitmap"),
                "C://", /// I would prefer this to be %HOMEDRIVE% & %HOMEPATH%
                "Bitmap Images (*.bmp);;All Files (*.*)"
                );
    QMessageBox::information(this,tr("File Name"),fileName); /// Just to prove it is working
    /// TODO: Ntiana Display image on form source image position:
    // void DisplayImage (string WidgetName, bmp_image Image)
   DisplayImage(source,);

    /// if this and the IO image are there perform IO
}

void MainWindow::DisplayImage (pictureLabels WidgetName, QString ImagePath)
{
    /// TODO: Ntiana display the given image on the given widget
    QPixmap pix(ImagePath);


    switch(WidgetName)
    {
        case source:
            ui->lbl_Original_Image->setPixmap(pix);
            break;
        case io_source:
            ui->lbl_Overlay_Image->setPixmap(pix);
            break;
        case io_result :
            ui->lbl_Overlay_Result->setPixmap(pix);
            break;
        case he_result:
            ui->lbl_HE_Result->setPixmap(pix);
            break;
        case sb_result:
            ui->lbl_SB_Result->setPixmap(pix);
            break;

    }
}

void MainWindow::on_actionSave_Image_Overlay_Result_triggered()
{
    /// TODO: Maria -might need to wait for other parts- save the resulting IO to a file supplied with a save as file dialog
}

void MainWindow::on_actionSave_Histogram_Equalization_Result_triggered()
{
    /// TODO: Maria -might need to wait for other parts- save the resulting HE to a file supplied with a save as file dialog
    /// make sure to save the one created using the sliders
}

void MainWindow::on_actionLoad_Overlay_Image_triggered()
{
    /// Open a file dialog to browse for a bitmap file.
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("Open Bitmap"),
                "C://", /// I would prefer this to be %HOMEDRIVE% & %HOMEPATH%
                "Bitmap Images (*.bmp);;All Files (*.*)"
                );
    QMessageBox::information(this,tr("File Name"),fileName); /// Just to prove it is working
    /// TODO: Ntiana Display image on form in the IO position:
    // void DisplayImage (string WidgetName, bmp_image Image)

    /// if this and the Source image are there perform IO
}

void peformImageOverlayOnForm()
{
    /// TODO: Imran use the current bmp_file object and the overlay image bmp_file object to create and display the IO result
}

/// Contrast 0 - 300
void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    double Decimal_Position = ((double)position / 100.0); //slider only sends ints, range can be edited on form properties
    /// TODO: Ntiana Make this call the sliderbar adjustment function with params
    // see if this triggers while being dragged
    bmp_file image_A;
    image_A.sliderBarAdjustment(1,Decimal_Position);



    //update image with function void DisplayImage (string WidgetName, bmp_image Image)
}

/// Brightness 0 - 127
void MainWindow::on_horizontalSlider_2_sliderMoved(int)
{
    /// TODO: Ntiana Make this call the sliderbar adjustment function with params
    //update image with function void DisplayImage (string WidgetName, bmp_image Image)
}
