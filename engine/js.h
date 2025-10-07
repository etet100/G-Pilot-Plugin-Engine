#ifndef JS_H
#define JS_H

#include "../engine.h"
#include <QJSEngine>
#include <QMainWindow>

class Js : public Engine
{
public:
    Js(QMainWindow *mainWindow);
    bool execute(const QString &script) override;
    bool supported(const QString &script) override;

protected:
    void init() override;

private:
    QJSEngine engine;
};

#endif // JS_H
