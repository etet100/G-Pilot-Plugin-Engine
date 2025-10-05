#include "jogging.h"
#include <QStringList>

Jogging::Jogging() {}

// bool Jogging::isPossible() {
//     return true; // TODO: check if jogging is possible
// }

void Jogging::jog(int axis, int distance) {
}

void Jogging::stop() {
}

bool Jogging::take(QString info)
{

}

void Jogging::release()
{

}

int Jogging::getFeedrate()
{

}

float Jogging::getStepSize()
{
    
}

void Jogging::setFeedrate(int feedrate)
{

}

void Jogging::setStepSize(float step)
{

}

QStringList Jogging::getFeedrates()
{
    return QString("1,2,3").split(",");
}

QStringList Jogging::getStepSizes()
{
    return QString("-1,0.1,0.5,1,5").split(",");
}
