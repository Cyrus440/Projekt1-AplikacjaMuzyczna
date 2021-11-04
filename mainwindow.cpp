#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QtMultimedia/QAudio>
#include <QtMultimedia/QMediaPlayer>
#include <QDebug>
#include <QtMultimedia/QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player ->setAudioOutput(audioOutput);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filtr = "Pliki Muzyczne (*.mp3)" ;
    QString nazwa_pliku =  QFileDialog::getOpenFileName(this, "Otwarcie Pliku", "D://", filtr);
    QMessageBox::information(this, "..", nazwa_pliku);
}


void MainWindow::on_horizontalSlider_Progress_sliderMoved(int position)
{
    player->setPosition(position);
}


void MainWindow::on_horizontalSlider_Volume_sliderMoved(int position)
{
    audioOutput->setVolume(position);
}

void MainWindow::on_pushButton_2_clicked()
{
    player->setSource(QUrl::fromLocalFile("C:/Users/sobol_000/Tu"));
    player->play();
    qDebug() << player->errorString();
}


void MainWindow::on_pushButton_3_clicked()
{
    player->stop();
}

void MainWindow::on_positionChanged(qint64 position)
{
    ui->horizontalSlider_Progress->setValue(position);
}

void MainWindow::on_durationChanged(qint64 position)
{
    ui->horizontalSlider_Progress->setMaximum(position);
}
