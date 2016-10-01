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
    //original_image = fileName;
    QMessageBox::information(this,tr("File Name"),fileName); /// Just to prove it is working

    /// TODO: Ntiana Display image on form source image position:
    QImage original(fileName);

    int w_or = ui->lbl_Original_Image->width();
    int h_or = ui->lbl_Original_Image->height();

    QPixmap temp = QPixmap::fromImage(original);
    ui->lbl_Original_Image->setPixmap(temp.scaled(w_or,h_or,Qt::KeepAspectRatio));

    /// if this and the IO image are there perform IO
    if(ui->lbl_Overlay_Image->pixmap() != 0 )
    {
        bmp_file overlay_image;
        bmp_file original_image;
        //original_image.imageOverlay(overlay_image, );

    }

}

void MainWindow::DisplayImage (pictureLabels WidgetName, bmp_file picture)
{
    /// TODO: Ntiana display the given image on the given widget

    QImage image(picture.getFileData(),picture.getWidth(),picture.getHeight(),QImage::Format_Grayscale8);
    QPixmap temp = QPixmap::fromImage(image);

    /// Used to make sure pictures are loaded in the correct size
    int w_ir = ui->lbl_Overlay_Result->width();
    int h_ir = ui->lbl_Overlay_Result->height();
    int w_he = ui->lbl_HE_Result->width();
    int h_he = ui->lbl_HE_Result->height();
    int w_sb = ui->lbl_SB_Result->width();
    int h_sb = ui->lbl_SB_Result->height();

    switch(WidgetName)
    {
        case io_result :
            ui->lbl_Overlay_Result->setPixmap(temp.scaled(w_ir,h_ir,Qt::KeepAspectRatio));
            break;
        case he_result:
            ui->lbl_HE_Result->setPixmap(temp.scaled(w_he,h_he,Qt::KeepAspectRatio));
            break;
        case sb_result:
            ui->lbl_SB_Result->setPixmap(temp.scaled(w_sb,h_sb,Qt::KeepAspectRatio));
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
    //DisplayImage(io_source, fileName);
    /// if this and the Source image are there perform IO
}

void peformImageOverlayOnForm()
{
    /// TODO: Imran use the current bmp_file object and the overlay image bmp_file object to create and display the IO result
}

/// Contrast 0 - 300
void MainWindow::on_contrastSlider_valueChanged(int value)
{
    double Decimal_Position = ((double)value / 100.0); //slider only sends ints, range can be edited on form properties
    /// TODO: Ntiana Make this call the sliderbar adjustment function with params
    // see if this triggers while being dragged
    //creates instance of original picture
    //QByteArray temp_orig = original_image.toLatin1();
    //char * outpath_orig = temp_orig.data();
    //bmp_file image_A(outpath_orig);
    bmp_file new_picture;
    bmp_file original_picture;

    //original_picture.sliderBarAdjustment(ui->brightnessSlider->value(), Decimal_Position,original_picture);




    // QByteArray temp = (QDir::currentPath()+"/his_test1.bmp").toLatin1();
     // char * outpath = temp.data();
    //image_A.sliderBarAdjustment(ui->brightnessSlider->value(),Decimal_Position,outpath);

    //update image with function void DisplayImage (string WidgetName, bmp_image Image)
   //DisplayImage(io_result,original_image);

}
/// Brightness 0 - 127
void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    /// TODO: Ntiana Make this call the sliderbar adjustment function with params
    //update image with function void DisplayImage (string WidgetName, bmp_image Image)

   // QByteArray temp_orig = original_image.toLatin1();
  ///  char * outpath_orig = temp_orig.data();
    //bmp_file image_A(outpath_orig);

    QByteArray temp = (QDir::currentPath()+"\his_test1.bmp").toLatin1();
    //QByteArray temp = (QUrl::fromLocalFile("test.bmp"));
    char * outpath = temp.data();

    //image_A.sliderBarAdjustment(value,((ui->contrastSlider->value())/100.0),outpath);
   // DisplayImage(sb_result,QString("C:\Users\ntsak\Documents\ComputerDesign\milestone1.4\bitmaps\his_test1.bmp"));
}


