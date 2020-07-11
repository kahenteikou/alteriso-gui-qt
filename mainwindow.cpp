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
    //kernel
    bskun.set_kernel_list(get_kernel_list());
    QStringList kernel_listkun=bskun.get_kernel_list();
    ui->kernel_comboBox->addItems(kernel_listkun);
    //lang
    if(m_interface->get_alteriso3()){
        ui->Enable_japanese_build->setEnabled(false);
        bskun.set_lang_list(get_lang_list());
        QStringList lang_listkun=bskun.get_lang_list();
        ui->Lang_comboBox->addItems(lang_listkun);
    }else{
        ui->Lang_comboBox->setEnabled(false);
        ui->Language_label->setEnabled(false);
    }
    //channel
    QStringList channel_listkun=get_channel_list();
    bskun.set_channel_list(channel_listkun);
    ui->Channel_ComboBox->addItems(channel_listkun);
    //comp
    QStringList comp_list({"zstd","lzma","lzo","lz4","xz","gzip"});
    ui->Comp_type_combobox->addItems(comp_list);
    //log
    QTextCursor textCursor = ui->LogTextEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
    ui->LogTextEdit->setTextCursor(textCursor);
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
QStringList MainWindow::get_channel_list(){
    QDir parent_dir_alter(m_interface->get_alteriso_Dir());
    QDir channels_dir(QString(parent_dir_alter.path() + "/channels"));
    QStringList channels_dirs=channels_dir.entryList(QDir::Dirs);
    QStringList result_channel_lists;
    for(QString channel_dir_path:channels_dirs){
        if(channel_dir_path != "." && channel_dir_path != ".." && channel_dir_path != "share"){

            QDir ch_dirkun(QString(channels_dir.path() + "/" + channel_dir_path));
            if(!ch_dirkun.isEmpty()){
                if(channel_dir_path.endsWith(".add")){
                    result_channel_lists.append(channel_dir_path.mid(0,channel_dir_path.length() -4));
                }else{
                    result_channel_lists.append(channel_dir_path);
                }
            }
        }
    }
    return result_channel_lists;
}

void MainWindow::on_Comp_type_combobox_currentIndexChanged(const QString &arg1)
{
    bskun.set_comp_type(arg1);
}

void MainWindow::on_kernel_comboBox_currentIndexChanged(const QString &arg1)
{
    bskun.set_kernel(arg1);
}

void MainWindow::on_Lang_comboBox_currentIndexChanged(const QString &arg1)
{
    bskun.set_lang(arg1);
}

void MainWindow::on_Channel_ComboBox_currentIndexChanged(const QString &arg1)
{
    bskun.set_channel(arg1);
}

void MainWindow::on_UserName_Lineedit_textEdited(const QString &arg1)
{
    bskun.set_user_name(arg1);
}

void MainWindow::on_Password_lineedit_textEdited(const QString &arg1)
{
    bskun.set_pass_word(arg1);
}

void MainWindow::on_show_passwd_button_toggled(bool checked)
{
    if(checked){
        ui->Password_lineedit->setEchoMode(QLineEdit::Normal);
    }else{
        ui->Password_lineedit->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::on_LogTextEdit_textChanged()
{

}
