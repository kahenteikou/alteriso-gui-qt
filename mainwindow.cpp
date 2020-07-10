#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(main_mainwindow_interface *m_interface2,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_interface=m_interface2;
    if(m_interface->get_alteriso3()){
        ui->Enable_Label->setText("Enable");
    }else{
        ui->Enable_Label->setText("Disable");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

