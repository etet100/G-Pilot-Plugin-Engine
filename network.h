#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include "export.h"

class PLUGINENGINE_EXPORT Network : public QObject {
    Q_OBJECT
public:
    Network();
    Q_INVOKABLE void connect(QString ip,int port);
    Q_INVOKABLE void send();
    Q_INVOKABLE void listen(int port);
    Q_INVOKABLE void query(QString url, QStringList params);
    Q_INVOKABLE void post(QString url, QStringList params);
};

class PLUGINENGINE_EXPORT TCP : public QObject {
    Q_OBJECT
};

class PLUGINENGINE_EXPORT HTTP : public TCP {
    Q_OBJECT
};

#endif // NETWORK_H
