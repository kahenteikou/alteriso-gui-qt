#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "main_mainwindow_interface.h"

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
};
#endif // MAINWINDOW_H
