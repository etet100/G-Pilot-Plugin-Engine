#include "console.h"
#include <QDebug>

Console::Console(QObject *parent) : QObject(parent) {}

void Console::log(const QString &msg) {
    emit message(Log, msg);
}

void Console::warn(const QString &msg) {
    emit message(Warn, msg);
}

void Console::error(const QString &msg) {
    emit message(Error, msg);
}
