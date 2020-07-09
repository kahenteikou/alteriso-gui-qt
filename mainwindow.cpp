#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(main_mainwindow_interface *m_interface2,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_interface=m_interface2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

