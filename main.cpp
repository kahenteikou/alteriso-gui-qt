#include "mainwindow.h"
#include <QtCore/QCommandLineParser>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("alteriso-gui-qt");
    QApplication::setApplicationVersion("1.0");
    QCommandLineParser parser;
    parser.setApplicationDescription("alteriso gui wrapper");
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption alteriso_3("alteriso3","enable alteriso 3");
    QDir curDir(QDir::current());
    QCommandLineOption alteriso_proj_path("alteriso_path","alteriso path [Default current directory]","alteriso dir",curDir.absolutePath());
    parser.addOptions({alteriso_3,alteriso_proj_path});
    parser.process(a);
    main_mainwindow_interface m_interface;
    m_interface.set_alteriso3(parser.isSet(alteriso_3));
    m_interface.set_alteriso_Dir(parser.value(alteriso_proj_path));
    MainWindow w(&m_interface);
    w.show();
    return a.exec();
}
