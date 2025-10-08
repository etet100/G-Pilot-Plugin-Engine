#ifndef LUA_H
#define LUA_H

#include "../engine.h"
#include "../export.h"
#include <QMainWindow>

class LuaImpl;

class PLUGINENGINE_EXPORT Lua : public Engine
{
public:
    Lua(QWidget *mainWindow);
    ~Lua();
    bool execute(const QString &script) override;
    bool supported(const QString &script) override;

protected:
    void init() override;

private:
    LuaImpl* impl;

friend class LuaImpl;
};

#endif // LUA_H
