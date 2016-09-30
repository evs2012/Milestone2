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
    original_image = fileName;
    QMessageBox::information(this,tr("File Name"),fileName); /// Just to prove it is working
    /// TODO: Ntiana Display image on form source image position:
    // void DisplayImage (string WidgetName, bmp_image Image)
     DisplayImage(source,fileName);

    /// if this and the IO image are there perform IO
}

void MainWindow::DisplayImage (pictureLabels WidgetName, QString ImagePath)
{
    /// TODO: Ntiana display the given image on the given widget
    QPixmap pix(ImagePath);

    /// Used to make sure pictures are loaded in the correct size
    int w_or = ui->lbl_Original_Image->width();
    int h_or = ui->lbl_Original_Image->height();
    int w_is = ui->lbl_Overlay_Image->width();
    int h_is = ui->lbl_Overlay_Image->height();
    int w_ir = ui->lbl_Overlay_Result->width();
    int h_ir = ui->lbl_Overlay_Result->height();
    int w_he = ui->lbl_HE_Result->width();
    int h_he = ui->lbl_HE_Result->height();
    int w_sb = ui->lbl_SB_Result->width();
    int h_sb = ui->lbl_SB_Result->height();

    switch(WidgetName)
    {
        case source:
            ui->lbl_Original_Image->setPixmap(pix.scaled(w_or,h_or,Qt::KeepAspectRatio));
            break;
        case io_source:
            ui->lbl_Overlay_Image->setPixmap(pix.scaled(w_is,h_is,Qt::KeepAspectRatio));
            break;
        case io_result :
            ui->lbl_Overlay_Result->setPixmap(pix.scaled(w_ir,h_ir,Qt::KeepAspectRatio));
            break;
        case he_result:
            ui->lbl_HE_Result->setPixmap(pix.scaled(w_he,h_he,Qt::KeepAspectRatio));
            break;
        case sb_result:
            ui->lbl_SB_Result->setPixmap(pix.scaled(w_sb,h_sb,Qt::KeepAspectRatio));
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
    DisplayImage(io_source, fileName);
    /// if this and the Source image are there perform IO
}

void peformImageOverlayOnForm()
{
    /// TODO: Imran use the current bmp_file object and the overlay image bmp_file object to create and display the IO result
}

/// Contrast 0 - 300
void MainWindow::on_contrastSlider(int /*position*/)
{
    //double Decimal_Position = ((double)position / 100.0); //slider only sends ints, range can be edited on form properties
    /// TODO: Ntiana Make this call the sliderbar adjustment function with params
    // see if this triggers while being dragged

    //creates instance of original picture
    QByteArray temp_orig = original_image.toLatin1();
    char * outpath_orig = temp_orig.data();
    bmp_file image_A(outpath_orig);

    ///TRIED OUTPUTTING TO FILE DIDN'T WORK
    /// I don't think it is entering this function

    //QByteArray temp = (QDir::currentPath()+"/his_test1.bmp").toLatin1();
    //char * outpath = temp.data();
    //image_A.sliderBarAdjustment(ui->brightnessSlider->value(),Decimal_Position,outpath);

    //update image with function void DisplayImage (string WidgetName, bmp_image Image)
   DisplayImage(sb_result,outpath_orig);
}

/// Brightness 0 - 127
void MainWindow::on_brightnessSlider(int position)
{
    /// TODO: Ntiana Make this call the sliderbar adjustment function with params
    //update image with function void DisplayImage (string WidgetName, bmp_image Image)

    QByteArray temp_orig = original_image.toLatin1();
    char * outpath_orig = temp_orig.data();
     bmp_file image_A(outpath_orig);
     QByteArray temp = (QDir::currentPath()).toLatin1();
     //QByteArray temp = (QUrl::fromLocalFile("test.bmp"));
     char * outpath = temp.data();
    image_A.sliderBarAdjustment(position,((ui->contrastSlider->value())/100.0),outpath);
    DisplayImage(sb_result,outpath);
}
