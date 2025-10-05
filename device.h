#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>

class Device : public QObject {
    Q_OBJECT
public:
    Device();
    Q_INVOKABLE void send(QString line);
    Q_INVOKABLE void waitResponses();
    Q_INVOKABLE bool sendCommand(QString line);
    Q_INVOKABLE void storeParserState();
    Q_INVOKABLE void restoreParserState();
};

#endif // DEVICE_H
