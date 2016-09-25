#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

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
}
