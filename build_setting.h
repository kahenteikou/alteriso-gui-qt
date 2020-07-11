#ifndef BUILD_SETTING_H
#define BUILD_SETTING_H

#include <QObject>

class build_setting : public QObject
{
    Q_OBJECT
public:
    explicit build_setting(QObject *parent = nullptr);
    void set_archtecture(QString);
    QString get_archtecture();
    void set_kernel_list(QStringList);
    QStringList get_kernel_list();
    void set_channel_list(QStringList);
    QStringList get_channel_list();
    void set_lang_list(QStringList);
    QStringList get_lang_list();
private:
    QString archtecture;
    QStringList kernel_list;
    QStringList lang_list;
    QStringList channel_list;
signals:

};

#endif // BUILD_SETTING_H
