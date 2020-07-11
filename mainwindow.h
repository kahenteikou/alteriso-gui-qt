#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include "main_mainwindow_interface.h"
#include "build_setting.h"
#include <QDir>
#include <iostream>
#include <QTextStream>
#include <QProcess>
#include "log_manager.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(main_mainwindow_interface *m_interface2,QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    main_mainwindow_interface *m_interface;
    struct utsname uname_strkun;
    build_setting bskun;
    QStringList get_kernel_list();
    QStringList get_lang_list();
    QStringList get_list_file(QFile*);
    QStringList get_channel_list();
    QProcess build_qp;

private slots:
    void on_Comp_type_combobox_currentIndexChanged(const QString &arg1);
    void on_kernel_comboBox_currentIndexChanged(const QString &arg1);
    void on_Lang_comboBox_currentIndexChanged(const QString &arg1);
    void on_Channel_ComboBox_currentIndexChanged(const QString &arg1);
    void on_UserName_Lineedit_textEdited(const QString &arg1);
    void on_Password_lineedit_textEdited(const QString &arg1);
    void on_show_passwd_button_toggled(bool checked);
    void on_textEdit_textChanged();
    void on_LogTextEdit_textChanged();
};
#endif // MAINWINDOW_H
