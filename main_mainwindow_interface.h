#ifndef MAIN_MAINWINDOW_INTERFACE_H
#define MAIN_MAINWINDOW_INTERFACE_H

#include <QObject>

class main_mainwindow_interface : public QObject
{
    Q_OBJECT
public:
    explicit main_mainwindow_interface(QObject *parent = nullptr);
    bool get_alteriso3();
    void set_alteriso3(bool);
    QString get_alteriso_Dir();
    void set_alteriso_Dir(QString);
signals:
private:
    bool enable_alteriso3;
    QString alteriso_dir;
};

#endif // MAIN_MAINWINDOW_INTERFACE_H
