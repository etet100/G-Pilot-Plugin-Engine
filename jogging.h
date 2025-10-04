#ifndef JOGGING_H
#define JOGGING_H

#include <QObject>

class Jogging : public QObject {
    Q_OBJECT
public:
    Jogging();
    Q_INVOKABLE bool isPossible();
    Q_INVOKABLE void jog(int axis, int distance);
    Q_INVOKABLE void stop();
    Q_INVOKABLE float getFeedrate();
    Q_INVOKABLE float getStepSize();
};

#endif // JOGGING_H
