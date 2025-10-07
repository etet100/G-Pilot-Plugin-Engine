#ifndef LUA_H
#define LUA_H

#include "../engine.h"
#include "../sol/sol.hpp"
#include <QMainWindow>

class Lua : public Engine
{
public:
    Lua(QMainWindow *mainWindow);
    bool execute(const QString &script) override;
    bool supported(const QString &script) override;

protected:
    void init() override;

private:
    sol::state lua;
};

#endif // LUA_H
