// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#ifndef ENGINECONTAINER_H
#define ENGINECONTAINER_H

#include "engine.h"
#include "engine/js.h"
#include "engine/lua.h"

class EngineContainer
{
public:
    EngineContainer(QWidget *mainWindow);

    Js *js();
    Lua *lua();

private:
    QWidget *mainWindow_;
    Js *js_ = nullptr;
    Lua *lua_ = nullptr;
};

#endif // ENGINECONTAINER_H
