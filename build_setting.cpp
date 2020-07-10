#include "build_setting.h"

build_setting::build_setting(QObject *parent) : QObject(parent)
{

}
QString build_setting::get_archtecture(){
    return archtecture;
}
void build_setting::set_archtecture(QString a){
    archtecture=a;
}
QStringList build_setting::get_kernel_list(){
    return kernel_list;
}
void build_setting::set_kernel_list(QStringList lkun){
    kernel_list=lkun;
}
