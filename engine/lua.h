#ifndef LUA_H
#define LUA_H

#include "../engine.h"
#include <QMainWindow>

class LuaImpl;

class Lua : public Engine
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
};

#endif // LUA_H
