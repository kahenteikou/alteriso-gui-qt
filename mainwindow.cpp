#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(main_mainwindow_interface *m_interface2,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_interface=m_interface2;

    if(uname(&uname_strkun)!=0){
        return;
    }
    bskun.set_archtecture(uname_strkun.machine);
    bskun.set_kernel_list(get_kernel_list());
    QStringList lkun=bskun.get_kernel_list();
    ui->kernel_comboBox->addItems(lkun);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QStringList MainWindow::get_kernel_list(){

    QDir parent_dir_alter(m_interface->get_alteriso_Dir());
    QFile kernel_list_file(QString(parent_dir_alter.path() + "/system/kernel_list-" + bskun.get_archtecture()));
    if(!kernel_list_file.open(QIODevice::ReadOnly)){
        return QStringList({});
    }
    QStringList return_strlist;
    QTextStream linekun(&kernel_list_file);
    while(!linekun.atEnd()){
        QString line_replace=linekun.readLine();
        line_replace=line_replace.replace(" ","");
        if(!line_replace.startsWith("#") && !line_replace.isEmpty()){
            return_strlist.append(line_replace.split("#").first());
        }
    }
    return return_strlist;
}

