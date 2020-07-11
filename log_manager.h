#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <QObject>
class Log_Manager : public QObject
{
    Q_OBJECT
public:
    explicit Log_Manager(QObject *parent = nullptr);
    void clear_log();
    void add_log(QString);
    QString get_log();
private:
    QString log_text;
signals:
    void recieve_log(QString);

};

#endif // LOG_MANAGER_H
