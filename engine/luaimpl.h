#ifndef LUAIMPL_H
#define LUAIMPL_H

#include "../sol/sol.hpp"
#include "../engine.h"

class LuaImpl : public Engine
{
public:
    LuaImpl(QWidget *mainWindow);
    bool execute(const QString &script);
    bool supported(const QString &script);
    void init();

private:
    sol::state lua;
};

#endif // LUAIMPL_H
