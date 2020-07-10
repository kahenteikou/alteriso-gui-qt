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
    QCommandLineOption alteriso_3("alteriso3",QApplication::translate("main","enable alteriso 3"));
    parser.addOptions({alteriso_3});
    parser.process(a);
    main_mainwindow_interface m_interface;
    m_interface.set_alteriso3(parser.isSet(alteriso_3));
    MainWindow w(&m_interface);
    w.show();
    return a.exec();
}
