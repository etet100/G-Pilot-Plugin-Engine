// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#include "luaimpl.h"

LuaImpl::LuaImpl(QWidget *mainWindow) : Engine(mainWindow) {
    init();
}

bool LuaImpl::execute(const QString &script)
{
    try {
        lua.script(script.toStdString());
    } catch (const sol::error& e) {
        console_.error("LUA error: " + QString(e.what()));
    }

    return true;
}

bool LuaImpl::supported(const QString &script)
{
    int score = 0;

    if (script.contains(QRegularExpression("--\\[\\["))) score += 5;
    if (script.contains(QRegularExpression("(?m)(^|\\s)--"))) score += 4;
    if (script.contains(QRegularExpression("\\blocal\\b"))) score += 5;
    if (script.contains(QRegularExpression("\\bend\\b"))) score += 5;
    if (script.contains(QRegularExpression("\\bnil\\b"))) score += 3;

    return score > 3; // próg heurystyczny
}

void LuaImpl::init()
{
    lua.open_libraries(sol::lib::base, sol::lib::string, sol::lib::math, sol::lib::table);

    lua.new_usertype<Console>("console",
                              "log", &Console::log2,
                              "warn", &Console::warn,
                              "error", &Console::error
                              );
    lua["console"] = &console_;
    lua["c"] = &console_;

    lua.new_usertype<MsgBox>("msgBox",
                                 "info", &MsgBox::info2,
                                 "warn", &MsgBox::warn2,
                                 "error", &MsgBox::error2,
                                 "confirm", &MsgBox::confirm2,
                                 "select", &MsgBox::select2
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
