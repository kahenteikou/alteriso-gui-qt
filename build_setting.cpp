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
QStringList build_setting::get_lang_list(){
    return lang_list;
}
void build_setting::set_lang_list(QStringList lkun){
    lang_list=lkun;
}

QStringList build_setting::get_channel_list(){
    return channel_list;
}
void build_setting::set_channel_list(QStringList lkun){
    channel_list=lkun;
}
QString build_setting::get_comp_type(){
    return comp_type;
}
void build_setting::set_comp_type(QString cpkun){
    comp_type=cpkun;
}
QString build_setting::get_channel(){
    return channel;
}
void build_setting::set_channel(QString chkun){
    channel=chkun;
}

QString build_setting::get_lang(){
    return lang;
}
void build_setting::set_lang(QString cpkun){
    lang=cpkun;
}

QString build_setting::get_kernel(){
    return kernel;
}
void build_setting::set_kernel(QString cpkun){
    kernel=cpkun;
}
QString build_setting::get_pass_word(){
    return password_kun;
}
void build_setting::set_pass_word(QString p){
    password_kun=p;
}
QString build_setting::get_user_name(){
    return user_name;
}
void build_setting::set_user_name(QString un){
    user_name=un;
}


