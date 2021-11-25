#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

