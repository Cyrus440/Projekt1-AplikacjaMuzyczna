#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QFile>

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
    QString filtr = "Pliki Muzyczne (*.mp3)";
    QString nazwa_pliku = QFileDialog::getOpenFileName(this, "wybierz pliki", "D//", filtr);
    QFile plik(nazwa_pliku);
    QMessageBox::information(this,"..", nazwa_pliku);
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(sPath));
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{

}

