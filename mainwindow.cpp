#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("Input Bug Number");
    baseWebURL = "http://XXX.XXX.com/bugs/files/0/";
    baseFolderURL = "file:///Z:/files/0/";

    HANDLE clip;
    if (OpenClipboard(NULL)) {
     clip = GetClipboardData(CF_TEXT);
     CloseClipboard();
    }
    QString clip_str = QString::fromUtf8((char*)clip);
    QString clip_toInt = QString::number(clip_str.toInt());
    qDebug() << clip_toInt;
    if (clip_toInt != "0")
        ui->lineEdit->setText(clip_toInt);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// web button
void MainWindow::on_pushButton_released()
{
    QString path = ui->lineEdit->text(); //check valid data
    QString url = this->baseWebURL;
    if(path.size() == 0)
        return;
    for (int i = 0; i < path.size(); ++i)
    {
        if (path.at(i) >= QChar('0') && path.at(i) <= QChar('9'))
        {
            url += path.at(i);
            url += "/";
        }
        else
        {
            qDebug() << "Invalid input";
            ui->label->setText("Invalid Bug Number!");
            ui->lineEdit->selectAll();
            ui->lineEdit->setFocus();
            return;
        }
    }
    QDesktopServices::openUrl(QUrl(url, QUrl::TolerantMode));
    ui->label->setText("Input Bug Number");
}



// folder button
void MainWindow::on_pushButton_2_released()
{
    QString path = ui->lineEdit->text(); //check valid data
    QString url = this->baseFolderURL;
    if(path.size() == 0)
        return;
    for (int i = 0; i < path.size(); ++i)
    {
        if (path.at(i) >= QChar('0') && path.at(i) <= QChar('9'))
        {
            url += path.at(i);
            url += "/";
        }
        else
        {
            qDebug() << "Invalid input";
            ui->label->setText("Invalid Bug Number!");
            ui->lineEdit->selectAll();
            ui->lineEdit->setFocus();
            return;
        }
    }
    QDesktopServices::openUrl(QUrl(url, QUrl::TolerantMode));
    ui->label->setText("Input Bug Number");
}
