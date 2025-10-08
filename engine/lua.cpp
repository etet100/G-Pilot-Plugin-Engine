// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#include "lua.h"
#include "luaimpl.h"

Lua::Lua(QWidget *mainWindow) : Engine(mainWindow), impl(new LuaImpl(mainWindow, this)) {
}

Lua::~Lua()
{
    delete impl;
}

bool Lua::execute(const QString &script)
{
    return impl->execute(script);
}

bool Lua::supported(const QString &script)
{
    return impl->supported(script);
}

void Lua::init()
{
    impl->init();
}
