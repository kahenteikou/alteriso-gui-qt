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
    void set_kernel(QString);
    QString get_kernel();
    void set_channel(QString);
    QString get_channel();
    void set_lang(QString);
    QString get_lang();
    QString get_comp_type();
    void set_comp_type(QString);
    QString get_user_name();
    void set_user_name(QString);
    QString get_pass_word();
    void set_pass_word(QString);
private:
    QString archtecture;
    QStringList kernel_list;
    QStringList lang_list;
    QStringList channel_list;
    QString kernel;
    QString lang;
    QString channel;
    QString comp_type;
    QString user_name;
    QString password_kun;
signals:

};

#endif // BUILD_SETTING_H
