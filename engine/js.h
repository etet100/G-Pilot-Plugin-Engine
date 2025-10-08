#ifndef JS_H
#define JS_H

#include "../engine.h"
#include "../export.h"
#include <QJSEngine>

class PLUGINENGINE_EXPORT Js : public Engine
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
