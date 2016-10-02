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

    //QMessageBox::information(this,tr("File Name"),fileName); /// Just to prove it is working
    if(fileName != "")
    {
        QByteArray temp = fileName.toLatin1();
        original_image= bmp_file(temp.data());\

        DisplayImage(source,original_image);
        /// if this and the IO image are there perform IO
       // if(ui->lbl_Overlay_Image->pixmap() != 0 )
       // {
       //     original_image.imageOverlay(overlay_image,result_overlay_image);
       // }

    }


}

void MainWindow::DisplayImage (pictureLabels WidgetName, bmp_file picture)
{
    QImage image = QImage(picture.getFileData(),picture.getWidth(),picture.getHeight(),QImage::Format_Grayscale8);
    image = image.mirrored(false,true);
    QPixmap temp = QPixmap::fromImage(image);

    /// Used to make sure pictures are loaded in the correct size
    int w_or = ui->lbl_Original_Image->width();
    int h_or = ui->lbl_Original_Image->height();
    int w_io = ui->lbl_Overlay_Image->width();
    int h_io = ui->lbl_Overlay_Image->height();
    int w_ir = ui->lbl_Overlay_Result->width();
    int h_ir = ui->lbl_Overlay_Result->height();
    int w_he = ui->lbl_HE_Result->width();
    int h_he = ui->lbl_HE_Result->height();
    int w_sb = ui->lbl_SB_Result->width();
    int h_sb = ui->lbl_SB_Result->height();

    switch(WidgetName)
    {
        case source:
            ui->lbl_Original_Image->setPixmap(temp.scaled(w_or,h_or,Qt::KeepAspectRatio));
            break;
        case io_source:
            ui->lbl_Overlay_Image->setPixmap(temp.scaled(w_io,h_io,Qt::KeepAspectRatio));
            break;
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

    QPushButton *saveButton;
    saveButton->setToolTip(tr("File Name")); /// I am getting an eror here, can someone please help me set up a button for file name

    ///calling setFileMode
    /// getOpenFileName is the information it will use to write to a file

    QFileDialog dialog(this);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Bitmap"), "C://",(tr("Images (*.png *.jpg)")));

    /// display information about files and directories.

    dialog.setViewMode(QFileDialog::Detail);

    ///the file user selected is put in fileName.
    /// modal blocks input to other visible windows in the same application

    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();


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
   // QMessageBox::information(this,tr("File Name"),fileName); /// Just to prove it is working

    if(fileName != "")
    {
        QByteArray temp = fileName.toLatin1();
        overlay_image = bmp_file(temp.data());
        DisplayImage(io_source,overlay_image);

        /// if this and the IO image are there perform IO
        //if(ui->lbl_Original_Image->pixmap() != 0 )
       //  {
        //    original_image.imageOverlay(overlay_image,result_overlay_image);
       // }
    }

}

void peformImageOverlayOnForm()
{
    /// TODO: Imran use the current bmp_file object and the overlay image bmp_file object to create and display the IO result
}

/// Contrast 0 - 300
void MainWindow::on_contrastSlider_valueChanged(int value)
{
    double Decimal_Position = ((double)value / 100.0); //slider only sends ints, range can be edited on form properties

    original_image.sliderBarAdjustment(ui->brightnessSlider->value(), Decimal_Position,sliderbar_image);

    DisplayImage(sb_result,sliderbar_image);

}

/// Brightness 0 - 127
void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    original_image.sliderBarAdjustment(value,(ui->contrastSlider->value())/100,sliderbar_image);

    DisplayImage(sb_result,sliderbar_image);
}


