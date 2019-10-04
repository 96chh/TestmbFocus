#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    wkeSetWkeDllPath(L"node.dll");
    wkeInitialize();
    window = wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL,
                                           (HWND)(ui->widget->winId()), 0, 0, ui->widget->width(), ui->widget->height());
    wkeLoadURL(window, "www.baidu.com");
    wkeShowWindow(window, TRUE);
}

MainWindow::~MainWindow()
{
    delete ui;
}
