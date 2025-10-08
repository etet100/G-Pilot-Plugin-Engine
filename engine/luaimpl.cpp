// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#include "luaimpl.h"

class Test {
public:
    void a() {
        qDebug() << "A";
    }

    void b() {
        qDebug() << "B";
    }
};

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

    return score > 3; // heuristic threshold
}

void LuaImpl::init()
{
    lua.open_libraries(sol::lib::base, sol::lib::string, sol::lib::math, sol::lib::table);

    // Test test;

    // lua["m"] = &msgBox_;
    lua.new_usertype<Console>("Console",
            sol::constructors<Console()>(),
            "log", &Console::log2
        );
    lua["c"] = sol::make_reference(lua, &console_);

    // lua.script(R"(
    //     c:a()
    //     c:b()
    // )");

    // lua["MsgBox"]["info"] = &MsgBox::info2;
    // lua["MsgBox"]["warn"] = &MsgBox::warn2;
    // lua["MsgBox"]["error"] = &MsgBox::error2;
    // lua["MsgBox"]["confirm"] = &MsgBox::confirm2;
    // lua["MsgBox"]["select"] = &MsgBox::select2;


    // lua["c"] = &console_;
    // lua.new_usertype<Console>("Console",
    //                           "log", &Console::log2,
    //                           "warn", &Console::warn2,
    //                           "error", &Console::error2
    //                           );


    // lua.new_usertype<Settings>("settings",
    //                            "get", &Settings::get,
    //                            "set", &Settings::set
    //                            );

    // lua["settings"] = &settings_;
    // lua["s"] = &settings_;

    // lua.new_usertype<UI>("ui",
    //                      "loadUiFile", &UI::loadUiFile2,
    //                      "createWindow", &UI::createWindow2
    //                      );

    // lua["ui"] = &ui_;
    // lua["u"] = &ui_;
}
