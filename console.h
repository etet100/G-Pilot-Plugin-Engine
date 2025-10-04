#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>

class Console : public QObject {
    Q_OBJECT
public:
    explicit Console(QObject *parent = nullptr);
    Q_INVOKABLE void log(const QString &msg);
    Q_INVOKABLE void warn(const QString &msg);
    Q_INVOKABLE void error(const QString &msg);
};

#endif // CONSOLE_H
