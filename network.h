#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>

class Network : public QObject {
    Q_OBJECT
public:
    Network();
    Q_INVOKABLE void connect(QString ip,int port);
    Q_INVOKABLE void send();
    Q_INVOKABLE void listen(int port);
    Q_INVOKABLE void query(QString url, QStringList params);
    Q_INVOKABLE void post(QString url, QStringList params);
};

class TCP : public QObject {
    Q_OBJECT
};

class HTTP : public TCP {
    Q_OBJECT
};

#endif // NETWORK_H
