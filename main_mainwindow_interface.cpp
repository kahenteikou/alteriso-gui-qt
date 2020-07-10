#include "main_mainwindow_interface.h"

main_mainwindow_interface::main_mainwindow_interface(QObject *parent) : QObject(parent)
{

}
bool main_mainwindow_interface::get_alteriso3(){
    return enable_alteriso3;
}
void main_mainwindow_interface::set_alteriso3(bool a){
    enable_alteriso3=a;
}
QString main_mainwindow_interface::get_alteriso_Dir(){
    return alteriso_dir;
}
void main_mainwindow_interface::set_alteriso_Dir(QString d){
    alteriso_dir=d;
}
