#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QObject>
#include <QString>

class MsgBox : public QObject {
    Q_OBJECT
public:
    MsgBox();
    Q_INVOKABLE void info(const QString &title, const QString &msg);
    void info2(std::string title, std::string msg);
    Q_INVOKABLE void warn(const QString &title, const QString &msg);
    void warn2(std::string title, std::string msg);
    Q_INVOKABLE void error(const QString &title, const QString &msg);
    void error2(std::string title, std::string msg);
    Q_INVOKABLE bool confirm(const QString &title, const QString &msg);
    bool confirm2(std::string title, std::string msg);
    Q_INVOKABLE int select(const QString &title, const QStringList &options);
    int select2(std::string title, std::vector<std::string> options);
};

#endif // MESSAGEBOX_H
