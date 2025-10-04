#include "console.h"
#include "mainwindow.h"
#include <QDebug>

Console::Console(QObject *parent) : QObject(parent) {}

void Console::log(const QString &msg) {
    MainWindow *p = (MainWindow*)this->parent();
    p->addLog("log", msg);
    qDebug() << msg;
}

void Console::warn(const QString &msg) {
    MainWindow *p = (MainWindow*)this->parent();
    p->addLog("warn", msg);
    qWarning() << msg;
}

void Console::error(const QString &msg) {
    MainWindow *p = (MainWindow*)this->parent();
    p->addLog("error", msg);
    qCritical() << msg;
}
