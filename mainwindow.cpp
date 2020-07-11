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
    QStringList kernel_listkun=bskun.get_kernel_list();
    ui->kernel_comboBox->addItems(kernel_listkun);
    if(m_interface->get_alteriso3()){
        ui->Enable_japanese_build->setEnabled(false);
        bskun.set_lang_list(get_lang_list());
        QStringList lang_listkun=bskun.get_lang_list();
        ui->Lang_comboBox->addItems(lang_listkun);
    }else{
        ui->Lang_comboBox->setEnabled(false);
        ui->Language_label->setEnabled(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
QStringList MainWindow::get_kernel_list(){

    QDir parent_dir_alter(m_interface->get_alteriso_Dir());
    QFile kernel_list_file(QString(parent_dir_alter.path() + "/system/kernel_list-" + bskun.get_archtecture()));
    return get_list_file(&kernel_list_file);
}
QStringList MainWindow::get_lang_list(){

    QDir parent_dir_alter(m_interface->get_alteriso_Dir());
    QFile lang_list_file(QString(parent_dir_alter.path() + "/system/locale-" + bskun.get_archtecture()));
    QStringList result_strls_old= get_list_file(&lang_list_file);
    QStringList result_strls;
    for(QString qstrkun:result_strls_old){
        result_strls.append(qstrkun.split(" ").first());
    }
    return result_strls;
}
QStringList MainWindow::get_list_file(QFile *fkun){
    if(!fkun->open(QIODevice::ReadOnly)){
        return QStringList({});
    }
    QStringList return_strlist;
    QTextStream linekun(fkun);
    while(!linekun.atEnd()){
        QString line_replace=linekun.readLine();
        //line_replace=line_replace.replace(" ","");
        if(!line_replace.startsWith("#") && !line_replace.isEmpty()){
            return_strlist.append(line_replace.split("#").first());
        }
    }
    return return_strlist;
}
