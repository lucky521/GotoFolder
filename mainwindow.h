#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QString>
#include <QDebug>
#include <string>
#include <windows.h>
#pragma comment(lib, "user32")

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool eventFilter(QObject *object, QEvent *event);
    ~MainWindow();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::MainWindow *ui;

    QString baseWebURL;
    QString baseFolderURL;
};

#endif // MAINWINDOW_H
