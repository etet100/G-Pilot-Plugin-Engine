// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#include "lua.h"

Lua::Lua(QMainWindow *mainWindow) : Engine(mainWindow) {
    init();
}

bool Lua::execute(const QString &script)
{
    try {
        lua.script(script.toStdString());
    } catch (const sol::error& e) {
        console_.error("LUA error: " + QString(e.what()));
    }
}

void Lua::init()
{
    lua.open_libraries(sol::lib::base, sol::lib::string, sol::lib::math, sol::lib::table);

    lua.new_usertype<Console>("console",
                              "log", &Console::log2,
                              "warn", &Console::warn,
                              "error", &Console::error
                              );
    lua["console"] = &console_;
    lua["c"] = &console_;

    lua.new_usertype<MessageBox>("msgBox",
                                 "info", &MessageBox::info2,
                                 "warn", &MessageBox::warn2,
                                 "error", &MessageBox::error2,
                                 "confirm", &MessageBox::confirm2,
                                 "select", &MessageBox::select2
                                 );

    lua["msgBox"] = &msgBox_;
    lua["m"] = &msgBox_;

    lua.new_usertype<Settings>("settings",
                               "get", &Settings::get,
                               "set", &Settings::set
                               );

    lua["settings"] = &settings_;
    lua["s"] = &settings_;

    lua.new_usertype<UI>("ui",
                         "loadUiFile", &UI::loadUiFile2,
                         "createWindow", &UI::createWindow2
                         );

    lua["ui"] = &ui_;
    lua["u"] = &ui_;
}
