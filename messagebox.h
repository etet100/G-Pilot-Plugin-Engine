#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QObject>
#include <QString>

class MessageBox : public QObject {
    Q_OBJECT
public:
    MessageBox();
    Q_INVOKABLE void info(const QString &title, const QString &msg);
    Q_INVOKABLE void warn(const QString &title, const QString &msg);
    Q_INVOKABLE void error(const QString &title, const QString &msg);
    Q_INVOKABLE bool confirm(const QString &title, const QString &msg);
    Q_INVOKABLE int select(const QString &title, const QStringList &options);
};

#endif // MESSAGEBOX_H
