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

#endif // NETWORK_H
