#include "log_manager.h"

Log_Manager::Log_Manager(QObject *parent) : QObject(parent)
{
    log_text="";
}
void Log_Manager::clear_log(){
    log_text="";
    emit recieve_log("");
}
void Log_Manager::add_log(QString lg){
    log_text+=lg;
    emit recieve_log(lg);
}
QString Log_Manager::get_log(){
    return log_text;
}
