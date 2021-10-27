#include "mainwindow.h"

#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setNameFilter("Muzyka (*.mp3 *)");
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    w.show();
    return a.exec();
}
