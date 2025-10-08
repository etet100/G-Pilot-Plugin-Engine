#ifndef LUAIMPL_H
#define LUAIMPL_H

#include "../sol/sol.hpp"
#include "lua.h"
#include "../engine.h"

class LuaImpl
{
public:
    LuaImpl(QWidget *mainWindow, Lua *lua);
    bool execute(const QString &script);
    bool supported(const QString &script);
    void init();

private:
    Lua *lua;
    sol::state luaState;
};

#endif // LUAIMPL_H
