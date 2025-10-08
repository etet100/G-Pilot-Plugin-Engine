
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

LuaImpl::LuaImpl(QWidget *mainWindow, Lua *lua) : lua(lua) {
    init();
}

bool LuaImpl::execute(const QString &script)
{
    try {
        luaState.script(script.toStdString());
    } catch (const sol::error& e) {
        lua->console_.error("LUA error: " + QString(e.what()));
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
    luaState.open_libraries(sol::lib::base, sol::lib::string, sol::lib::math, sol::lib::table);

    luaState.new_usertype<MsgBox>("MsgBox",
                              "info", &MsgBox::info2,
                              "warn", &MsgBox::warn2,
                              "error", &MsgBox::error2,
                              "confirm", &MsgBox::confirm2,
                              "select", &MsgBox::select2
                              );
    luaState["msgBox"] = &lua->msgBox_;
    luaState["m"] = &lua->msgBox_;

    luaState.new_usertype<Console>("Console",
                              "log", &Console::log2,
                              "warn", &Console::warn2,
                              "error", &Console::error2
                              );
    luaState["c"] = &lua->console_;
    luaState["console"] = &lua->console_;

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
