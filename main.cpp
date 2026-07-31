#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qDebug() << "System Initialization Started.";
    qDebug() << "About Screen Added";
    qDebug() << "Version 1.0";
    qDebug() << "About Screen Bug Fixed";
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("GitPractice", "Main");

    return QGuiApplication::exec();
}
