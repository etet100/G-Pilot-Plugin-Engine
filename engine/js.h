#ifndef JS_H
#define JS_H

#include "../engine.h"
#include <QJSEngine>

class Js : public Engine
{
public:
    Js(QWidget *mainWindow);
    bool execute(const QString &script) override;
    bool supported(const QString &script) override;

protected:
    void init() override;

private:
    QJSEngine engine;
};

#endif // JS_H
