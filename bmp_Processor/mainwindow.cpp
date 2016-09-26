#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
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
    ///Display image on form:
    // void DisplayImage (string WidgetName, bmp_image Image)
}

void MainWindow::on_actionSave_Outputs_triggered()
{
   /// Save the set up outputs to a file using a file save as dialog...
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
   // see if this triggers while being dragged
}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    // might be only after mouse release
}

void MainWindow::DisplayImage (QString WidgetName, bmp_file Image)
{
    // display the given image on the given widget
}
