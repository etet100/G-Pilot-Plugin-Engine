#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>

class Console : public QObject {
    Q_OBJECT
public:
    enum Level {
        Log,
        Warn,
        Error
    };

    explicit Console(QObject *parent = nullptr);
    Q_INVOKABLE void log(const QString &msg);
    void log2(const std::string &msg);
    Q_INVOKABLE void warn(const QString &msg);
    void warn2(const std::string &msg);
    Q_INVOKABLE void error(const QString &msg);
    void error2(const std::string &msg);

signals:
    void message(Level level, const QString &msg);
};

#endif // CONSOLE_H
