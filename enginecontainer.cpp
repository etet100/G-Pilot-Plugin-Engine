// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#include "enginecontainer.h"
#include "engine/js.h"
#include "engine/lua.h"

EngineContainer::EngineContainer(QWidget *mainWindow) : mainWindow_(mainWindow) {
}

Js* EngineContainer::js()
{
    if (!js_) {
        js_ = new Js(mainWindow_);
    }

    return js_;
}

Lua* EngineContainer::lua()
{
    if (!lua_) {
        lua_ = new Lua(mainWindow_);
    }

    return lua_;
}
