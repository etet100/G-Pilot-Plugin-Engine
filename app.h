#ifndef APP_H
#define APP_H

#include <QObject>
#include <QMap>
#include <QJSValue>

class AppApi : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE void onEvent(const QString &event, const QJSValue &callback) {
        events[event] = callback;
    }
private:
    QMap<QString, QJSValue> events;
};

#endif // APP_H
