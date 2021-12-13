#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QFile>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString sPath = "D//";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);
    ui->treeView->setModel(dirmodel);
    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setRootPath(sPath);
    ui -> listView->setModel(filemodel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filtr = "Obrazy (*.jpg *.png *.jpeg *.gif)";
    QString filename = QFileDialog::getOpenFileName(this, tr("Wybierz: "), "D//", filtr);
    if (QString::compare(filename, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_pic->width(), Qt::SmoothTransformation);
            ui->label_pic->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //Error Handling
        }
    }
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(sPath));
}




///void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
///{
///    QString sPath = filemodel->fileInfo(index).absoluteFilePath();
///}


void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    QString sPath = filemodel->fileInfo(index).absoluteFilePath();
    QString filtr = "Obrazy (*.jpg *.png *.jpeg *.gif)";
    QString filename = QFileDialog::getOpenFileName(this, tr("Wybierz: "), sPath, filtr);
    if (QString::compare(filename, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_pic->width(), Qt::SmoothTransformation);
            ui->label_pic->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //Error Handling
        }
    }
}

