#include "console.h"
#include <QDebug>

Console::Console(QObject *parent) : QObject(parent) {}

void Console::log(const QString &msg) {
    emit message(Log, msg);
}

void Console::log2(const std::string &msg)
{
    emit message(Log, QString::fromStdString(msg));
}

void Console::warn(const QString &msg) {
    emit message(Warn, msg);
}

void Console::warn2(const std::string &msg)
{
    emit message(Warn, QString::fromStdString(msg));
}

void Console::error(const QString &msg) {
    emit message(Error, msg);
}

void Console::error2(const std::string &msg)
{
    emit message(Error, QString::fromStdString(msg));
}
