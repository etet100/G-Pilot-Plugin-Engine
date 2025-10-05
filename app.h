#ifndef APP_H
#define APP_H

#include <QObject>
#include <QMap>
#include <QJSValue>

class App : public QObject {
    Q_OBJECT
public:
    App(QObject *parent = nullptr) : QObject(parent) {}
    Q_INVOKABLE void onEvent(const QString &event, const QJSValue &callback) {
        events[event] = callback;
    }
private:
    QMap<QString, QJSValue> events;
};

#endif // APP_H
