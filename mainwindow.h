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
};
#endif // MAINWINDOW_H
