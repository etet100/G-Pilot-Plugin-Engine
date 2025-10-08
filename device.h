#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include "export.h"

class PLUGINENGINE_EXPORT Device : public QObject {
    Q_OBJECT

public:
    Device();

    // High level commands
    Q_INVOKABLE void home();
    Q_INVOKABLE void moveTo(double x, double y, double z);
    Q_INVOKABLE void setSpeed(double speed);
    Q_INVOKABLE void reset();
    Q_INVOKABLE void setAbsolutePositioning();
    Q_INVOKABLE void setRelativePositioning();

    // Low level commands
    Q_INVOKABLE void send(QString line);
    Q_INVOKABLE void waitResponses();
    Q_INVOKABLE bool sendCommand(QString line);
    Q_INVOKABLE void storeParserState();
    Q_INVOKABLE void restoreParserState();
};

#endif // DEVICE_H
